/*
 * LED_Config.h
 *
 *  Created on: Sep 23, 2022
 *      Author: wwwmo
 */

#ifndef HAL_LED_HEADER_LED_CONFIG_H_
#define HAL_LED_HEADER_LED_CONFIG_H_

#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../../../MCAL/DIO/Header/DIO_Register.h"

#define Led_DirD    DIO_GroupD
#define Led_PortD   DIO_PORTD

#define Led_DirC    DIO_GroupC
#define Led_PortC   DIO_PORTC

#define Led_Delay	1000

#endif /* HAL_LED_HEADER_LED_CONFIG_H_ */
