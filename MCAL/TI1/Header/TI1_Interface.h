/*
 * TI1_Interface.h
 *
 *  Created on: Oct 21, 2022
 *      Author: MoMenBak
 *	   Lecture: Interfacing_Lec
 */

#ifndef MCAL_TI1_HEADER_TI1_INTERFACE_H_
#define MCAL_TI1_HEADER_TI1_INTERFACE_H_

#include "../../../Common/STD_Types.h"

#include "../../TI1/Header/TI1_Configuration.h"
#include "../../TI1/Header/TI1_Private.h"
#include "../../TI1/Header/TI1_Register.h"

//void PWM1_VoidSevInit()
/*non inverting
 * perodic time = Over Flow time = tick time * OverFlow value
 * on time  = Compare time => compare Value *tick time  */
void PWM1_VoidInitM14(u16 Local_MaxValue,u16 Local_CompareValue,u8 Local_Prescaller);
/*
 *Select the Mode -> mode 14:
 *  			    	WGM10 -> LOW ->TCCR1A
 * 						WGM11 -> High->TCCR1A
 * 						WGM12 -> High->TCCR1B
 * 						WGM13 -> High->TCCR1B
 *Select The Action pwm mode-> Nin inverting & unit A (COM1A0->low)/(COM1A1->Set)
 *
 * Assign the Max value in Register (ICR1 = Local_MaxValue)
 * PWM1_VoidSetCompareValue(Local_CompareValue);
 * select the Prescaller
 * */
void PWM1_VoidSetCompareValue(u16 Local_CompareValue);




void ICU_VoidInit ();
void ICU_VoidSelectEdge (u8 Local_TypeOfEdge);

void __vector_6()__attribute__((signal));

#endif /* MCAL_TI1_HEADER_TI1_INTERFACE_H_ */
