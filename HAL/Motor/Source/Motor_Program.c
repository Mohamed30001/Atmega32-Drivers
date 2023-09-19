/*
 * Motor_Program.c
 *
 *  Created on: Oct 1, 2022
 *      Author: wwwmo
 */

#include "util/delay.h"
#include "../../../common/STD_types.h"
#include "../../../common/Bit_Math.h"
#include "../../../common/Macro.h"
#include "../Header/Motor_Config.h"
#include "../Header/Motor_Interface.h"

u8 Motor_Direction = 3;

void Motor_voidInit()
{
	DIO_u8SetPinDir(Motor_Dir, Motor_RightPin, Output);
	DIO_u8SetPinDir(Motor_Dir, Motor_LeftPin, Output);
}


void Motor_voidOn(u8 direction)
{
	if(direction == Motor_Right)
	{
		Motor_Direction = Motor_Right;

		DIO_u8SetPinValue(Motor_Dir, Motor_RightPin,High);
		DIO_u8SetPinValue(Motor_Dir, Motor_LeftPin,Low);
	}
	else if(direction == Motor_Left)
	{
		Motor_Direction = Motor_Left;

		DIO_u8SetPinValue(Motor_Dir, Motor_RightPin,Low);
		DIO_u8SetPinValue(Motor_Dir, Motor_LeftPin,High);
	}
}


void Motor_voidOff()
{
	DIO_u8SetPinValue(Motor_Dir, Motor_RightPin,Low);
	DIO_u8SetPinValue(Motor_Dir, Motor_LeftPin,Low);
	Motor_Direction = 4;
}

void Motor_voidChangeDirection()
{

	if(Motor_Direction == Motor_Right)
	{
		DIO_u8SetPinValue(Motor_Dir, Motor_RightPin,Low);
		DIO_u8SetPinValue(Motor_Dir, Motor_LeftPin,High);
	}
	else if(Motor_Direction == Motor_Left)
	{
		DIO_u8SetPinValue(Motor_Dir, Motor_RightPin,High);
		DIO_u8SetPinValue(Motor_Dir, Motor_LeftPin,Low);
	}
}
