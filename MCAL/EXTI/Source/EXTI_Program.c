/*
 * EXTI_Program.c
 *
 *  Created on: Oct 7, 2022
 *      Author: wwwmo
 */


#include "../../../common/STD_types.h"
#include "../../../common/Bit_Math.h"
#include "../../../common/Macro.h"
#include "../Header/EXTI_Interface.h"
#include "../Header/EXTI_Register.h"
#include "../Header/EXTI_private.h"
#include "../../GIE/Header/GIE_All.h"


void EXTI_VoidInit0 (u8 Local_Sens)
{
	DIO_u8SetPinDir(EXTI_GROUP1, EXTI_PinINT0, Input);
	switch (Local_Sens)
	{
	case EXTI_LowLevel:
		Clear_Bit(EXTI_MCUCR, EXTI_ISC00);
		Clear_Bit(EXTI_MCUCR, EXTI_ISC01);
		break;
	case EXTI_AnyChange:
		Set_Bit(EXTI_MCUCR, EXTI_ISC00);
		clear_Bit(EXTI_MCUCR, EXTI_ISC01);
		break;

	case EXTI_Falling:
		clear_Bit(EXTI_MCUCR, EXTI_ISC00);
		Set_Bit(EXTI_MCUCR, EXTI_ISC01);
		break;
	case EXTI_Rising:
		Set_Bit(EXTI_MCUCR, EXTI_ISC00);
		Set_Bit(EXTI_MCUCR, EXTI_ISC01);
		break;
	}

	GIE_VoidEn();
	Set_Bit(EXTI_GICR, EXTI_INT0);
}




void EXTI_VoidInit1 (u8 Local_Sens)
{
	DIO_u8SetPinDir(EXTI_GROUP1, EXTI_PinINT1, Input);
	switch (Local_Sens)
	{
	case EXTI_LowLevel:
		Clear_Bit(EXTI_MCUCR, EXTI_ISC10);
		Clear_Bit(EXTI_MCUCR, EXTI_ISC11);
		break;

	case EXTI_AnyChange:
		Set_Bit(EXTI_MCUCR, EXTI_ISC10);
		clear_Bit(EXTI_MCUCR, EXTI_ISC11);
		break;

	case EXTI_Falling:
		clear_Bit(EXTI_MCUCR, EXTI_ISC10);
		set_Bit(EXTI_MCUCR, EXTI_ISC11);
		break;
	case EXTI_Rising:
		Set_Bit(EXTI_MCUCR, EXTI_ISC10);
		Set_Bit(EXTI_MCUCR, EXTI_ISC11);
		break;
	}

	GIE_VoidEn();
	Set_Bit(EXTI_GICR, EXTI_INT1);
}





void EXTI_VoidInit2 (u8 Local_Sens)
{
	DIO_u8SetPinDir(EXTI_GROUP2, EXTI_PinINT2, Input);
	switch (Local_Sens)
	{
	case EXTI_Falling:
		clear_Bit(EXTI_MCUCSR, EXTI_ISC2);
		break;
	case EXTI_Rising:
		Set_Bit(EXTI_MCUCSR, EXTI_ISC2);
		break;
	}

	GIE_VoidEn();
	Set_Bit(EXTI_GICR, EXTI_INT2);
}














