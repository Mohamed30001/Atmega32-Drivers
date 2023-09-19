/*
 * Stepper_Program.c
 *
 *  Created on: Oct 7, 2022
 *      Author: wwwmo
 */

#include "../Header/Stepper_Interface.h"
#include <util/delay.h>

void Stepper_VoidInit(void)
{
DIO_u8SetPinDir(Stepper_Group,Stepper_Blue,Output);
DIO_u8SetPinDir(Stepper_Group,Stepper_Pink,Output);
DIO_u8SetPinDir(Stepper_Group,Stepper_Yellow,Output);
DIO_u8SetPinDir(Stepper_Group,Stepper_Orange,Output);
}

void Stepper_VoidOnCW(u16 Local_anagle)
{
	u16 Local_NoOfSteps = Local_anagle / FullStridAnagle ;
	u16 Local_NoOfIetration = Local_NoOfSteps / 4 ;
	u16 Local_counter ;

	for (Local_counter = 0 ; Local_counter < Local_NoOfIetration; Local_counter++)
	{
		/*Step-1*/
		DIO_u8SetPinValue(Stepper_Group,Stepper_Blue,Low);
		DIO_u8SetPinValue(Stepper_Group,Stepper_Pink,High);
		DIO_u8SetPinValue(Stepper_Group,Stepper_Yellow,High);
		DIO_u8SetPinValue(Stepper_Group,Stepper_Orange,High);
		_delay_ms(Stepper_Delay);
		/*Step-2*/
		DIO_u8SetPinValue(Stepper_Group,Stepper_Blue,High);
		DIO_u8SetPinValue(Stepper_Group,Stepper_Pink,Low);
		DIO_u8SetPinValue(Stepper_Group,Stepper_Yellow,High);
		DIO_u8SetPinValue(Stepper_Group,Stepper_Orange,High);
		_delay_ms(Stepper_Delay);
		/*Step-3*/
		DIO_u8SetPinValue(Stepper_Group,Stepper_Blue,High);
		DIO_u8SetPinValue(Stepper_Group,Stepper_Pink,High);
		DIO_u8SetPinValue(Stepper_Group,Stepper_Yellow,Low);
		DIO_u8SetPinValue(Stepper_Group,Stepper_Orange,High);
		_delay_ms(Stepper_Delay);
		/*Step-4*/
		DIO_u8SetPinValue(Stepper_Group,Stepper_Blue,High);
		DIO_u8SetPinValue(Stepper_Group,Stepper_Pink,High);
		DIO_u8SetPinValue(Stepper_Group,Stepper_Yellow,High);
		DIO_u8SetPinValue(Stepper_Group,Stepper_Orange,Low);
		_delay_ms(Stepper_Delay);
	}
}
void Stepper_VoidStop(void)
{

}

//
///*Step-1*/
//		DIO_u8SetPinValue(Stepper_Group,STPM_Blue,Low);
//		DIO_u8SetPinValue(Stepper_Group,STPM_Orange,High);
//		DIO_u8SetPinValue(Stepper_Group,STPM_Yellow,High);
//		DIO_u8SetPinValue(Stepper_Group,STPM_Pink,High);
//		_delay_ms(STPM_Delay);
