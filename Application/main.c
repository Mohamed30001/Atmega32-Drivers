/*
 * main.c
 *
 *  Created on: Sep 16, 2022
 *      Author: wwwmo
 */

#include "util/delay.h"
#include "../common/STD_types.h"
#include "../common/Bit_Math.h"
#include "../common/Macro.h"
#include "../MCAL/DIO/Header/DIO_Interface.h"
#include "../MCAL/DIO/Header/DIO_Config.h"
#include "../MCAL/DIO/Header/DIO_Private.h"





int main()
{

	DIO_u8SetPinDir(DIO_GroupD,DIO_PIN6,Input);
	DIO_u8SetPinDir(DIO_GroupC,DIO_PIN7,Output);

	DIO_u8SetPortValue(DIO_GroupC,0x00);

	DIO_u8SetPortDir(DIO_GroupA,0xff);
	DIO_u8SetPortDir(DIO_GroupB,0xff);
	//DIO_u8SetPinValue(DIO_GroupB,DIO_PIN7,High);

	//DIO_u8SetPortValue(DIO_GroupA,0xff);
	//DIO_u8SetPortValue(DIO_GroupB,0xff);

	s16 i=0;

	while(1)

	{
		for(i=7; i>=0; i-- )
		{
			DIO_u8SetPinValue(DIO_GroupB,i,High);
			_delay_ms(10);
			DIO_u8SetPinValue(DIO_GroupB,i,Low);
			_delay_ms(10);

		}

		for(i=0; i<8; i++)
		{
			DIO_u8SetPinValue(DIO_GroupA,i,High);
			_delay_ms(10);
			DIO_u8SetPinValue(DIO_GroupA,i,Low);
			_delay_ms(10);
		}

		for(i=6; i>=0; i--)
		{
			DIO_u8SetPinValue(DIO_GroupA,i,High);
			_delay_ms(10);
			DIO_u8SetPinValue(DIO_GroupA,i,Low);
			_delay_ms(10);
		}

		for(i=0; i<8; i++ )
		{
			DIO_u8SetPinValue(DIO_GroupB,i,High);
			_delay_ms(10);
			DIO_u8SetPinValue(DIO_GroupB,i,Low);
			_delay_ms(10);

		}
	}
}





































	/*
int main()
{
	DIO_u8SetPinDir(DIO_GroupA, DIO_PIN0,Output);
	DIO_u8SetPinDir(DIO_GroupA, DIO_PIN1,Output);

	Motor_voidInit();
	SevSeg_voidSingleInit();

	EXTI_VoidInit0(EXTI_Falling);
	DIO_u8SetPinValue(EXTI_GROUP1, EXTI_PinINT0, High);

	EXTI_VoidInit1(EXTI_Falling);
	DIO_u8SetPinValue(EXTI_GROUP1, EXTI_PinINT1, High);

	EXTI_VoidInit2(EXTI_Falling);
	DIO_u8SetPinValue(EXTI_GROUP2, EXTI_PinINT2, High);


	while(1)
	{

		DIO_u8SetPinValue(DIO_GroupA, DIO_PIN0,High);
		_delay_ms(1000);
		DIO_u8SetPinValue(DIO_GroupA, DIO_PIN0,Low);
		_delay_ms(1000);
	}
}


void __vector_1(void)  __attribute__((signal));

void __vector_1(void)
{
	static u8 Local_State = Low;

	if(Local_State == Low)
	{
		DIO_u8SetPinValue(DIO_GroupA, DIO_PIN1, High);
		Local_State = High;
	}
	else
	{
		DIO_u8SetPinValue(DIO_GroupA, DIO_PIN1, Low);
		Local_State = Low;
	}
}


void __vector_2(void)  __attribute__((signal));

void __vector_2(void)
{

	static u8 Local_State = 0;

	if (Local_State <10)
	{
	SevSeg_voidDisplayNumber(Local_State);
	Local_State++;
	}
	else
	{
		Local_State = 0;
	}
}
	 */
