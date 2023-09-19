/*
 * Servo_Interface.h
 *
 *  Created on: Oct 22, 2022
 *      Author: wwwmo
 */

#ifndef HAL_SERVO_HEADER_SERVO_INTERFACE_H_
#define HAL_SERVO_HEADER_SERVO_INTERFACE_H_

#include "Servo_Private.h"


//Select the OC1A As Output
//Select Servo motor angle Zero  -> compare value
//call function to calc the angel -> return value
//Call the PWM1_voidInitM14(Servo_Perdioc ,value);


void Servo_VoidInit(void);
u16  Servo_U16CalcAnagle(u8 Local_Anagl);
void Servo_VoidMove(u8 Local_Anagl);


#endif /* HAL_SERVO_HEADER_SERVO_INTERFACE_H_ */
