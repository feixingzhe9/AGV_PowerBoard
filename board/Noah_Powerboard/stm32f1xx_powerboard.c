/*
 *  Author: Adam Huang
 *  Date:2016/6/4
 */

#include "stm32f1xx_powerboard.h"
#include "Mico.h"

uint32_t get_switch_state(switch_type_def Switch)
{
    (void)Switch;
    return MicoGpioInputGet(MICO_GPIO_PWRKEY);
}

void power_ctrl(uint32_t power_en, power_on_off_type_def OnOff)
{
    if(POWER_ON == OnOff)
    {
        if(power_en & POWER_5V_MOTOR)
        {
            MicoGpioOutputLow(MICO_GPIO_5V_MOTOR_EN);
        }
        if(power_en & POWER_5V_RECHARGE)
        {
            MicoGpioOutputLow(MICO_GPIO_5V_RECHARGE_EN);
        }
        if(power_en & POWER_5V_SENSOR_BOARD)
        {
            MicoGpioOutputLow(MICO_GPIO_5V_SENSOR_BOARD_EN);
        }
        //if(power_en & POWER_5V_SWITCH)
        {
            //MicoGpioOutputLow(MICO_GPIO_5V_SWITCH_EN);
        }
        if(power_en & POWER_5V_ROUTER)
        {
            MicoGpioOutputLow(MICO_GPIO_5V_ROUTER_EN);
        }
        if(power_en & POWER_5V_EN)
        {
            MicoGpioOutputLow(MICO_GPIO_5V_EN);
        }
        if(power_en & POWER_12V_PAD)
        {
            MicoGpioOutputLow(MICO_GPIO_12V_PAD_EN);
        }
        if(power_en & POWER_12V_2_1_PA)
        {
            MicoGpioOutputLow(MICO_GPIO_12V_2_1_PA_EN);
        }
        if(power_en & POWER_12V_EXTEND)
        {
            MicoGpioOutputLow(MICO_GPIO_12V_EXTEND_EN);
        }
        if(power_en & POWER_12V_X86)
        {
            MicoGpioOutputLow(MICO_GPIO_12V_X86_EN);
        }
        if(power_en & POWER_12V_NV)
        {
            MicoGpioOutputLow(MICO_GPIO_12V_NV_EN);
        }
        if(power_en & POWER_12V_EN)
        {
            MicoGpioOutputLow(MICO_GPIO_12V_EN);
        }
        if(power_en & POWER_24V_EN)
        {
            MicoGpioOutputLow(MICO_GPIO_24V_EN);
        }
        if(power_en & POWER_24V_PRINTER)
        {
            MicoGpioOutputLow(MICO_GPIO_24V_PRINTER_EN);
        }
        if(power_en & POWER_24V_EXTEND)
        {
            MicoGpioOutputLow(MICO_GPIO_24V_EXTEND_EN);
        }
        if(power_en & POWER_VSYS_24V_NV)
        {
            MicoGpioOutputLow(MICO_GPIO_VSYS_24V_NV_EN);
        }
        if(power_en & POWER_485)
        {
            MicoGpioOutputLow(MICO_GPIO_485_EN);
        }
        if(power_en & POWER_RECHARGE_LED)
        {
            MicoGpioOutputLow(MICO_GPIO_RECHARGE_LED);
        }
        if(power_en & POWER_SLAM)
        {
            MicoGpioOutputLow(MICO_GPIO_SLAM_EN);
        }

        if(power_en & POWER_LED_MCU)
        {
            MicoGpioOutputLow(MICO_GPIO_LED_MCU_POWER_EN);
        }





        /*
           if(power_en & POWER_CHARGE_FAN)
           {
           MicoGpioOutputHigh(MICO_GPIO_CHARGE_FAN_CTRL);
           }
         */


        //if(power_en & POWER_POLE_MOTOR)
        {
            //MicoGpioOutputLow(MICO_GPIO_5V_POLE_MOTOR_EN);
        }
        //if(power_en & POWER_5V_KEYPAD)
        {
            //MicoGpioOutputLow(MICO_GPIO_5V_KEYPAD_EN);
        }

        if(power_en & POWER_CAMERA_FRONT_LED)
        {
            MicoGpioOutputHigh(MICO_GPIO_CAMERA_FRONT_LED_EN);
        }
        if(power_en & POWER_CAMERA_BACK_LED)
        {
            MicoGpioOutputHigh(MICO_GPIO_CAMERA_BACK_LED_EN);
        }

        if(power_en & POWER_CTRL_OUT)
        {
            MicoGpioOutputHigh(MICO_GPIO_PWR_CTRL_OUT);
        }

        if(power_en & POWER_DOOR_CTRL)
        {
            MicoGpioOutputHigh(MICO_GPIO_3_3V_DOOR_CTRL);
        }

        if(power_en & POWER_3V3_CARD_EN_1)
        {
            MicoGpioOutputHigh(MICO_GPIO_3V3_CARD_EN_1);
        }

        if(power_en & POWER_3V3_CARD_EN_2)
        {
            MicoGpioOutputHigh(MICO_GPIO_3V3_CARD_EN_2);
        }

        if(power_en & POWER_3V3_CARD_EN_3)
        {
            MicoGpioOutputHigh(MICO_GPIO_3V3_CARD_EN_3);
        }

        if(power_en & POWER_3V3_CARD_EN_4)
        {
            MicoGpioOutputHigh(MICO_GPIO_3V3_CARD_EN_4);
        }

    }
    else if(POWER_OFF == OnOff)
    {
        if(power_en & POWER_5V_MOTOR)
        {
            MicoGpioOutputHigh(MICO_GPIO_5V_MOTOR_EN);
        }
        if(power_en & POWER_5V_RECHARGE)
        {
            MicoGpioOutputHigh(MICO_GPIO_5V_RECHARGE_EN);
        }
        if(power_en & POWER_5V_SENSOR_BOARD)
        {
            MicoGpioOutputHigh(MICO_GPIO_5V_SENSOR_BOARD_EN);
        }
        //if(power_en & POWER_5V_SWITCH)
        {
            //MicoGpioOutputHigh(MICO_GPIO_5V_SWITCH_EN);
        }
        if(power_en & POWER_5V_ROUTER)
        {
            MicoGpioOutputHigh(MICO_GPIO_5V_ROUTER_EN);
        }
        if(power_en & POWER_5V_EN)
        {
            MicoGpioOutputHigh(MICO_GPIO_5V_EN);
        }
        if(power_en & POWER_12V_PAD)
        {
            MicoGpioOutputHigh(MICO_GPIO_12V_PAD_EN);
        }
        if(power_en & POWER_12V_2_1_PA)
        {
            MicoGpioOutputHigh(MICO_GPIO_12V_2_1_PA_EN);
        }
        if(power_en & POWER_12V_EXTEND)
        {
            MicoGpioOutputHigh(MICO_GPIO_12V_EXTEND_EN);
        }
        if(power_en & POWER_12V_X86)
        {
            MicoGpioOutputHigh(MICO_GPIO_12V_X86_EN);
        }
        if(power_en & POWER_12V_NV)
        {
            MicoGpioOutputHigh(MICO_GPIO_12V_NV_EN);
        }
        if(power_en & POWER_12V_EN)
        {
            MicoGpioOutputHigh(MICO_GPIO_12V_EN);
        }
        if(power_en & POWER_24V_EN)
        {
            MicoGpioOutputHigh(MICO_GPIO_24V_EN);
        }
        if(power_en & POWER_24V_PRINTER)
        {
            MicoGpioOutputHigh(MICO_GPIO_24V_PRINTER_EN);
        }
        if(power_en & POWER_24V_EXTEND)
        {
            MicoGpioOutputHigh(MICO_GPIO_24V_EXTEND_EN);
        }
        if(power_en & POWER_VSYS_24V_NV)
        {
            MicoGpioOutputHigh(MICO_GPIO_VSYS_24V_NV_EN);
        }
        if(power_en & POWER_485)
        {
            MicoGpioOutputHigh(MICO_GPIO_485_EN);
        }
        if(power_en & POWER_RECHARGE_LED)
        {
            MicoGpioOutputHigh(MICO_GPIO_RECHARGE_LED);
        }
        if(power_en & POWER_SLAM)
        {
            MicoGpioOutputHigh(MICO_GPIO_SLAM_EN);
        }

        if(power_en & POWER_LED_MCU)
        {
            MicoGpioOutputHigh(MICO_GPIO_LED_MCU_POWER_EN);
        }



        /*
           if(power_en & POWER_CHARGE_FAN)
           {
           MicoGpioOutputLow(MICO_GPIO_CHARGE_FAN_CTRL);
           }
         */

        //if(power_en & POWER_POLE_MOTOR)
        {
            //MicoGpioOutputHigh(MICO_GPIO_5V_POLE_MOTOR_EN);
        }
        //if(power_en & POWER_5V_KEYPAD)
        {
            //MicoGpioOutputHigh(MICO_GPIO_5V_KEYPAD_EN);
        }

        if(power_en & POWER_CTRL_OUT)
        {
            MicoGpioOutputLow(MICO_GPIO_PWR_CTRL_OUT);
        }

        if(power_en & POWER_CAMERA_FRONT_LED)
        {
            MicoGpioOutputLow(MICO_GPIO_CAMERA_FRONT_LED_EN);
        }
        if(power_en & POWER_CAMERA_BACK_LED)
        {
            MicoGpioOutputLow(MICO_GPIO_CAMERA_BACK_LED_EN);
        }
        if(power_en & POWER_DOOR_CTRL)
        {
            MicoGpioOutputLow(MICO_GPIO_3_3V_DOOR_CTRL);
        }

        if(power_en & POWER_3V3_CARD_EN_1)
        {
            MicoGpioOutputLow(MICO_GPIO_3V3_CARD_EN_1);
        }

        if(power_en & POWER_3V3_CARD_EN_2)
        {
            MicoGpioOutputLow(MICO_GPIO_3V3_CARD_EN_2);
        }

        if(power_en & POWER_3V3_CARD_EN_3)
        {
            MicoGpioOutputLow(MICO_GPIO_3V3_CARD_EN_3);
        }

        if(power_en & POWER_3V3_CARD_EN_4)
        {
            MicoGpioOutputLow(MICO_GPIO_3V3_CARD_EN_4);
        }

    }
}

uint32_t get_module_power_state(power_enable_type_def power_en)
{
    volatile uint32_t pinState;

    pinState = (uint32_t)0;

    if(power_en & POWER_5V_MOTOR)
    {
        if(!MicoGpioInputGet(MICO_GPIO_5V_MOTOR_EN))
        {
            pinState |= POWER_5V_MOTOR;
        }
    }
    if(power_en & POWER_5V_RECHARGE)
    {
        if(!MicoGpioInputGet(MICO_GPIO_5V_RECHARGE_EN))
        {
            pinState |= POWER_5V_RECHARGE;
        }
    }
    if(power_en & POWER_5V_SENSOR_BOARD)
    {
        if(!MicoGpioInputGet(MICO_GPIO_5V_SENSOR_BOARD_EN))
        {
            pinState |= POWER_5V_SENSOR_BOARD     ;
        }
    }
    //if(power_en & POWER_5V_SWITCH)
    {
        //if(!MicoGpioInputGet(MICO_GPIO_5V_SWITCH_EN))
        {
            //pinState |= POWER_5V_SWITCH;
        }
    }
    if(power_en & POWER_5V_ROUTER)
    {
        if(!MicoGpioInputGet(MICO_GPIO_5V_ROUTER_EN))
        {
            pinState |= POWER_5V_ROUTER ;
        }
    }
    if(power_en & POWER_5V_EN)
    {
        if(!MicoGpioInputGet(MICO_GPIO_5V_EN))
        {
            pinState |= POWER_5V_EN;
        }
    }
    if(power_en & POWER_12V_PAD)
    {
        if(!MicoGpioInputGet(MICO_GPIO_12V_2_1_PA_EN))
        {
            pinState |= POWER_12V_PAD;
        }
    }
    if(power_en & POWER_12V_2_1_PA)
    {
        if(!MicoGpioInputGet(MICO_GPIO_12V_PAD_EN))
        {
            pinState |= POWER_12V_2_1_PA;
        }
    }
    if(power_en & POWER_12V_EXTEND)
    {
        if(!MicoGpioInputGet(MICO_GPIO_12V_EXTEND_EN))
        {
            pinState |= POWER_12V_EXTEND;
        }
    }
    if(power_en & POWER_12V_X86)
    {
        if(!MicoGpioInputGet(MICO_GPIO_12V_X86_EN))
        {
            pinState |= POWER_12V_X86;
        }
    }
    if(power_en & POWER_12V_NV)
    {
        if(!MicoGpioInputGet(MICO_GPIO_12V_NV_EN))
        {
            pinState |= POWER_12V_NV;
        }
    }
    if(power_en & POWER_12V_EN)
    {
        if(!MicoGpioInputGet(MICO_GPIO_12V_EN))
        {
            pinState |= POWER_12V_EN;
        }
    }
    if(power_en & POWER_24V_EN)
    {
        if(!MicoGpioInputGet(MICO_GPIO_24V_EN))
        {
            pinState |= POWER_24V_EN;
        }
    }
    if(power_en & POWER_24V_PRINTER)
    {
        if(!MicoGpioInputGet(MICO_GPIO_24V_PRINTER_EN))
        {
            pinState |= POWER_24V_PRINTER;
        }
    }

    if(power_en & POWER_24V_EXTEND)
    {
        if(!MicoGpioInputGet(MICO_GPIO_24V_EXTEND_EN))
        {
            pinState |= POWER_24V_EXTEND;
        }
    }
    if(power_en & POWER_VSYS_24V_NV)
    {
        if(!MicoGpioInputGet(MICO_GPIO_VSYS_24V_NV_EN))
        {
            pinState |= POWER_VSYS_24V_NV;
        }
    }
    if(power_en & POWER_485)
    {
        if(!MicoGpioInputGet(MICO_GPIO_485_EN))
        {
            pinState |= POWER_485;
        }
    }
    if(power_en & POWER_SYS_LED)
    {
        if(!MicoGpioInputGet(MICO_GPIO_SYS_LED))
        {
            pinState |= POWER_SYS_LED;
        }
    }
    if(power_en & POWER_RECHARGE_LED)
    {
        if(!MicoGpioInputGet(MICO_GPIO_RECHARGE_LED))
        {
            pinState |= POWER_RECHARGE_LED;
        }
    }
    if(power_en & POWER_SLAM)
    {
        if(!MicoGpioInputGet(MICO_GPIO_SLAM_EN))
        {
            pinState |= POWER_SLAM;
        }
    }


    if(power_en & POWER_LED_MCU)
    {
        if(!MicoGpioInputGet(MICO_GPIO_LED_MCU_POWER_EN))
        {
            pinState |= POWER_LED_MCU;
        }
    }
    if(power_en & POWER_CHARGE_FAN)
    {
        if(!MicoGpioInputGet(MICO_GPIO_CHARGE_FAN_CTRL))
        {
            pinState |= POWER_CHARGE_FAN;
        }
    }
    //if(power_en & POWER_POLE_MOTOR)
    {
        //if(!MicoGpioInputGet(MICO_GPIO_5V_POLE_MOTOR_EN))
        {
            //pinState |= POWER_POLE_MOTOR;
        }
    }

    //if(power_en & POWER_5V_KEYPAD)
    {
        //if(!MicoGpioInputGet(MICO_GPIO_5V_KEYPAD_EN))
        {
            //pinState |= POWER_5V_KEYPAD;
        }
    }
    if(power_en & POWER_CAMERA_FRONT_LED)
    {
        if(MicoGpioInputGet(MICO_GPIO_CAMERA_FRONT_LED_EN))
        {
            pinState |= POWER_CAMERA_FRONT_LED;
        }
    }
    if(power_en & POWER_CAMERA_BACK_LED)
    {
        if(MicoGpioInputGet(MICO_GPIO_CAMERA_BACK_LED_EN))
        {
            pinState |= POWER_CAMERA_BACK_LED;
        }
    }

    if(power_en & POWER_CTRL_OUT)
    {
        if(MicoGpioInputGet(MICO_GPIO_PWR_CTRL_OUT))
        {
            pinState |= POWER_CTRL_OUT;
        }
    }

    if(power_en & POWER_DOOR_CTRL)
    {
        if(MicoGpioInputGet(MICO_GPIO_3_3V_DOOR_CTRL))
        {
            pinState |= POWER_DOOR_CTRL;
        }
    }

    if(power_en & POWER_3V3_CARD_EN_1)
    {
        if(MicoGpioInputGet(MICO_GPIO_3V3_CARD_EN_1))
        {
            pinState |= POWER_3V3_CARD_EN_1;
        }
    }

    if(power_en & POWER_3V3_CARD_EN_2)
    {
        if(MicoGpioInputGet(MICO_GPIO_3V3_CARD_EN_2))
        {
            pinState |= POWER_3V3_CARD_EN_2;
        }
    }

    if(power_en & POWER_3V3_CARD_EN_3)
    {
        if(MicoGpioInputGet(MICO_GPIO_3V3_CARD_EN_3))
        {
            pinState |= POWER_3V3_CARD_EN_3;
        }
    }

    if(power_en & POWER_3V3_CARD_EN_4)
    {
        if(MicoGpioInputGet(MICO_GPIO_3V3_CARD_EN_4))
        {
            pinState |= POWER_3V3_CARD_EN_4;
        }
    }


    return pinState;
}

void module_signal_ctrl(power_control_type_def PowerCon, control_signal_type_def is_hold)
{
    if(CONTROL_RELEASE == is_hold)
    {
#if 1
        switch(PowerCon)
        {
            case POWER_CON_NV:
                MicoGpioOutputLow(MICO_GPIO_PWR_NV);
                break;
                //    case POWER_CON_DLP:
                //      MicoGpioOutputLow(MICO_GPIO_PWR_DLP);
                //      break;
            case POWER_CON_PAD:
                MicoGpioOutputLow(MICO_GPIO_PWR_PAD);
                break;
            case POWER_CON_X86:
                MicoGpioOutputLow(MICO_GPIO_PWR_X86);
                break;
            case POWER_CON_RES:
                MicoGpioOutputLow(MICO_GPIO_PWR_RESERVE);
                break;
            default:
                break;
        }
#else
        if(PowerCon & POWER_CON_NV)
        {
            MicoGpioOutputLow(MICO_GPIO_PWR_NV);
        }
        if(PowerCon & POWER_CON_DLP)
        {
            MicoGpioOutputLow(MICO_GPIO_PWR_DLP);
        }
        if(PowerCon & POWER_CON_PAD)
        {
            MicoGpioOutputLow(MICO_GPIO_PWR_PAD);
        }
        if(PowerCon & POWER_CON_X86)
        {
            MicoGpioOutputLow(MICO_GPIO_PWR_X86);
        }
        if(PowerCon & POWER_CON_RES)
        {
            MicoGpioOutputLow(MICO_GPIO_PWR_RES);
        }
#endif
    }
    else if(CONTROL_HOLD == is_hold)
    {
#if 1
        switch(PowerCon)
        {
            case POWER_CON_NV:
                MicoGpioOutputHigh(MICO_GPIO_PWR_NV);
                break;
                //    case POWER_CON_DLP:
                //      MicoGpioOutputHigh(MICO_GPIO_PWR_DLP);
                //      break;
            case POWER_CON_PAD:
                MicoGpioOutputHigh(MICO_GPIO_PWR_PAD);
                break;
            case POWER_CON_X86:
                MicoGpioOutputHigh(MICO_GPIO_PWR_X86);
                break;
            case POWER_CON_RES:
                MicoGpioOutputHigh(MICO_GPIO_PWR_RESERVE);
                break;
            default:
                break;
        }
#else
        if(PowerCon & POWER_CON_NV)
        {
            MicoGpioOutputHigh(MICO_GPIO_PWR_NV);
        }
        if(PowerCon & POWER_CON_DLP)
        {
            MicoGpioOutputHigh(MICO_GPIO_PWR_DLP);
        }
        if(PowerCon & POWER_CON_PAD)
        {
            MicoGpioOutputHigh(MICO_GPIO_PWR_PAD);
        }
        if(PowerCon & POWER_CON_X86)
        {
            MicoGpioOutputHigh(MICO_GPIO_PWR_X86);
        }
        if(PowerCon & POWER_CON_RES)
        {
            MicoGpioOutputHigh(MICO_GPIO_PWR_RES);
        }
#endif
    }
}


void en_led_mcu(void)
{
    platform_pin_config_t pin_config;

    pin_config.gpio_speed = GPIO_SPEED_MEDIUM;
    pin_config.gpio_mode = GPIO_MODE_OUTPUT_PP;
    pin_config.gpio_pull = GPIO_PULLUP;
    MicoGpioInitialize((mico_gpio_t)MICO_GPIO_LED_MCU_POWER_EN, &pin_config);
    MicoGpioOutputLow((mico_gpio_t)MICO_GPIO_LED_MCU_POWER_EN);
}
#ifndef BOOTLOADER
void enter_sleep_mode(void)
{
    //  BSP_LED_Off(LED_SYS);
    //  HAL_PWR_EnterSTANDBYMode();
}

void wake_up_from_sleep_mode(void)
{
    //  init_clocks();
}
#endif

