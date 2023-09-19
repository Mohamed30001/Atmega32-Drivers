/*
 * EXTI_private.h
 *
 *  Created on: Oct 7, 2022
 *      Author: wwwmo
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#include "../../../MCAL/DIO/Header/DIO_Interface.h"

#define EXTI_LowLevel   1
#define EXTI_AnyChange  2
#define EXTI_Falling    3
#define EXTI_Rising     4

#define EXTI_GROUP1     DIO_GroupD
#define EXTI_GROUP2     DIO_GroupB

#define EXTI_PinINT0   DIO_PIN2
#define EXTI_PinINT1   DIO_PIN3

#define EXTI_PinINT2   DIO_PIN2


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
