/*
 * Led_Program.c
 *
 *  Created on: Sep 23, 2022
 *      Author: wwwmo
 */


#include "util/delay.h"
#include "../../../common/STD_types.h"
#include "../../../common/Bit_Math.h"
#include "../../../common/Macro.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../Header/Led_Config.h"
#include "../Header/Led_Interface.h"
#include "../Header/Led_Private.h"


void Led_voidInit()
{
	DIO_u8SetPortDir(Led_DirC, DIO_GroupOut);
}


void Led_voidSingleON()
{

	DIO_u8SetPinValue(Led_DirC, DIO_PIN0, DIO_High);
}

void Led_voidSingleOff()
{
	DIO_u8SetPinValue(Led_DirC, DIO_PIN0, DIO_Low);
}

void Led_voidAllOn()
{

	DIO_u8SetPortValue(Led_DirC, DIO_GroupHigh);
}

void Led_voidAllOff()
{
	DIO_u8SetPortValue(Led_DirC, DIO_GroupLow);

}








