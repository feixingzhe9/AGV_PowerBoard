/*
 *  Author: Kaka Xie
 *  brief: communication with serials led
 */
#include "serial_leds.h"
#include "app_platform.h"
#include "mico.h"
#include "voltage_detect.h"
#include "serial_uart.h"
#include "protocol.h"
#include "fifo.h"

#define LIGHTS_DEBUG

#define LEDS_MODES_N                    LIGHTS_MODE_MAX
#define LED_EFFECT_N                    10

#define serial_leds_log(M, ...) custom_log("SerialLeds", M, ##__VA_ARGS__)
#define serial_leds_log_trace() custom_log_trace("SerialLeds")


extern UART_HandleTypeDef huart2;
#if 0
void LedsUartInit(void)
{

    GPIO_InitTypeDef GPIO_InitStruct;

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /*Configure GPIO pin : PA2 */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pin : PA3 */
    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    /*Configure GPIO pin : PA2 */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pin : PA3 */
    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* Private variables ---------------------------------------------------------*/

    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        printf("led uart init err");
    }

}
#endif

/* USART2 init function */
static void serial_leds_com_uart_init(void)
{

    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        //_Error_Handler(__FILE__, __LINE__);
    }

    HAL_NVIC_SetPriority(USART2_IRQn, 6, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
}

/** Configure pins as
 * Analog
 * Input
 * Output
 * EVENT_OUT
 * EXTI
 */
static void uart_2_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /*Configure GPIO pin : PA2 */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pin : PA3 */
    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

uint8_t rcv_buf[50];
void serial_leds_uart_init(void)
{
    uart_2_gpio_init();
    serial_leds_com_uart_init();

    if(HAL_UART_Receive_IT(&huart2,rcv_buf,1)!=HAL_OK)
    {
        //Error_Handler();
    }
}

static uint8_t leds_send_buf[0x0f] = {0};

static uint8_t cal_check_sum(uint8_t *data, uint8_t len)
{
    uint8_t sum = 0;
    for(uint8_t i = 0; i < len; i++)
    {
        sum += data[i];
    }
    return sum;
}

/*
   static void LedsSendFrame(rcv_serial_leds_frame_t *leds_frame)
   {
   leds_send_buf[0] = FRAME_HEADER;
   leds_send_buf[1] = 0x0a;
   leds_send_buf[2] = FRAME_TYPE_LEDS_CONTROL;
   memcpy(&leds_send_buf[3], (uint8_t*)leds_frame, sizeof(rcv_serial_leds_frame_t));
   leds_send_buf[8] = cal_check_sum(leds_send_buf, 8);
   leds_send_buf[9] = FRAME_FOOTER;

   HAL_StatusTypeDef uart_err = HAL_UART_Transmit(&huart2, leds_send_buf, sizeof(leds_send_buf), 10);
   }
 */

static HAL_StatusTypeDef serials_leds_uart_send(uint8_t *data, uint8_t len)
{
    return HAL_UART_Transmit(&huart2, data, len, 10);
}

void get_serials_leds_version(void)
{
    memset(leds_send_buf, 0, sizeof(leds_send_buf));

    leds_send_buf[0] = FRAME_HEADER;
    leds_send_buf[1] = 0x05;
    leds_send_buf[2] = SERIALS_LEDS_FRAME_VERSION;
    leds_send_buf[3] = cal_check_sum(leds_send_buf, 3);
    leds_send_buf[4] = FRAME_FOOTER;
    serials_leds_uart_send(leds_send_buf, 5);
}

void set_serial_leds_effect(light_mode_t light_mode, color_t *cur_color, uint8_t period)
{
    memset(leds_send_buf, 0, sizeof(leds_send_buf));

    leds_send_buf[0] = FRAME_HEADER;
    leds_send_buf[1] = 0x0d;
    leds_send_buf[2] = SERIALS_LEDS_FRAME_LED_CTRL;
    leds_send_buf[3] = light_mode;
    leds_send_buf[4] = cur_color[0].r;
    leds_send_buf[5] = cur_color[0].g;
    leds_send_buf[6] = cur_color[0].b;

    leds_send_buf[7] = cur_color[1].r;
    leds_send_buf[8] = cur_color[1].g;
    leds_send_buf[9] = cur_color[1].b;
    leds_send_buf[10] = period;
    leds_send_buf[11] = cal_check_sum(leds_send_buf, 11);
    leds_send_buf[12] = FRAME_FOOTER;
    serials_leds_uart_send(leds_send_buf, 13);

    /*
       rcv_serial_leds_frame_t leds_frame;
       leds_frame.color.r = cur_color->r;
       leds_frame.color.g = cur_color->g;
       leds_frame.color.b = cur_color->b;
       leds_frame.cur_light_mode = light_mode;
       leds_frame.period = period;

       LedsSendFrame(&leds_frame);
     */
#if 0
    switch(light_mode)
    {
        case LIGHTS_MODE_NOMAL:

            break;
        case LIGHTS_MODE_ERROR:

            break;
        case LIGHTS_MODE_COM_ERROR:

            break;

        case LIGHTS_MODE_LOW_POWER:

            break;
        case LIGHTS_MODE_CHARGING:

            break;
        case LIGHTS_MODE_TURN_LEFT:

            break;
        case LIGHTS_MODE_TURN_RIGHT:

            break;
        case LIGHTS_MODE_EMERGENCY_STOP:
            ;
            break;
        case LIGHTS_MODE_SETTING:

            break;
        default :
            break;
    }
#endif
}
bool check_frame_sum(uint8_t *data, uint8_t data_len)
{
    uint8_t sum = 0;
    uint8_t i = 0;
    for(i = 0; i < data_len - 1; i++)
    {
        sum += data[i];
    }
    if(sum == data[data_len - 1])
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    //return (sum == data[i]);

}


extern void ack_leds_effect(light_mode_t light_mode, color_t *cur_color, uint8_t period);
extern void ack_serials_leds_version(uint8_t *data, uint8_t len);

void proc_serial_leds_protocol(light_mode_t light_mode, color_t *cur_color, uint8_t period)
{
    ack_leds_effect(light_mode, cur_color, period);
}

led_com_opt_t led_com_opt = {0};
char serials_leds_version[20] = {0};

void leds_protocol_period(void)
{
    uint8_t data_tmp;
    while(is_fifo_empty(fifo) == FALSE)
    {
        get_data_from_fifo(fifo, &data_tmp);
        led_com_opt.rcv_buf[led_com_opt.rcv_cnt] = data_tmp;
        if(led_com_opt.start_flag == TRUE)
        {
            if(led_com_opt.rcv_cnt == 1)
            {
                led_com_opt.data_len = data_tmp;
            }
            if(led_com_opt.rcv_cnt == led_com_opt.data_len - 1)
            {
                if(led_com_opt.rcv_buf[led_com_opt.rcv_cnt] == FRAME_FOOTER)
                {
                    uint8_t ctype = led_com_opt.rcv_buf[2];
                    led_com_opt.end_flag = TRUE;
                    led_com_opt.start_flag = FALSE;
                    led_com_opt.rcv_cnt = 0;
                    if(check_frame_sum(led_com_opt.rcv_buf,led_com_opt.data_len - 1) == TRUE)
                    {
                        switch(ctype)
                        {
                            case SERIALS_LEDS_FRAME_LED_CTRL:
                                proc_serial_leds_protocol((light_mode_t)led_com_opt.rcv_buf[3], (color_t*)&led_com_opt.rcv_buf[4], led_com_opt.rcv_buf[7]);
                                break;

                            case SERIALS_LEDS_FRAME_VERSION:
                                //if(led_com_opt.data_len == 8)
                                {
                                    for(uint8_t i = 0; i < led_com_opt.data_len - 5; i++)
                                    {
                                        serials_leds_version[i] = led_com_opt.rcv_buf[3 + i];
                                    }
                                    ack_serials_leds_version(&led_com_opt.rcv_buf[3], led_com_opt.data_len - 5);
                                }
                                break;

                            default :
                                break;
                        }
                    }

                    break;
                }
                else
                {
                    led_com_opt.end_flag = FALSE;
                    led_com_opt.start_flag = FALSE;
                    led_com_opt.rcv_cnt = 0;
                }
            }
        }
        else
        {
            if(data_tmp == FRAME_HEADER)
            {
                led_com_opt.start_flag = TRUE;
                led_com_opt.end_flag = FALSE;
            }
            led_com_opt.rcv_cnt = 0;
        }

        if(led_com_opt.rcv_cnt++ >= sizeof(led_com_opt.rcv_buf) - 1)
        {
            led_com_opt.start_flag = FALSE;
            led_com_opt.end_flag = FALSE;
            led_com_opt.rcv_cnt = 0;
        }
    }
}


/*********************END OF FILE**************/
