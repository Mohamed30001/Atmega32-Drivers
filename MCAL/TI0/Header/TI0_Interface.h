/*
 * TI0_Interface.h
 *
 *  Created on: Oct 15, 2022
 *      Author: wwwmo
 */

#ifndef MCAL_TI0_HEADER_TI0_INTERFACE_H_
#define MCAL_TI0_HEADER_TI0_INTERFACE_H_

#include "../../../common/STD_types.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../../../common/Macro.h"
#include "../../../common/Bit_Math.h"
#include "TI0_Register.h"
#include "TI0_Private.h"
#include "TI0_Config.h"

void TI0_VoidInitNormal (u8 Local_Preload , u8 Local_Prescaller);
/*
 * select the type (GWM01 -> 0 /GWM00 -> 0 ) Normal mode
 * Set The Preload Value In the Register :
 * 			TCNT0= Local_preload;
 * Set the preScaller
 *	Switch (Local_Prescaller)
 *	{
 *	}
 * Enable the Interrupt
 * */
void TI0_VoidInitCTC (u8 Local_CompareValue, u8 Local_ActionState , u8 Local_Prescaller );
/*
 * select the type (GWM01 -> 0 /GWM00 -> 0 ) CTC mode
 * Set The Compare value Value In the Register :
 * 			OCR0= Local_CompareValue;
 * Select for the action on the OC pin :
 * 			COM00/COM01
 * Set the preScaller
 *	Switch (Local_Prescaller)
 *	{
 *	}
 * Enable the Interrupt
 * */

void TI0_VoidSetPreload(u8 Local_Preload);

void TI0_CallBackFunctionNormal(void (*PTF)(void));

void TI0_CallBackFunctionCTC(void (*PTF)(void));


void PWM_VoidInit(u8 Dutycycle);

void PWM_VoidDutycycle(u8 Dutycycle);

void PWM_VoidStop();






void __vector_11(void)		__attribute__((signal));
void __vector_10(void)		__attribute__((signal));

#endif /* MCAL_TI0_HEADER_TI0_INTERFACE_H_ */
