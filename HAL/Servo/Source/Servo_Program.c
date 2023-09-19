/*
 * Servo_Program.c
 *
 *  Created on: Oct 22, 2022
 *      Author: hisha
 */


#include "../../../Common/Macro.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../../../MCAL/TI1/Header/TI1_Interface.h"
#include "../Header/Servo_Interface.h"


void Servo_VoidInit(void)
{
	//Select the OC1A As Output
	DIO_u8SetPinDir(DIO_GroupD,DIO_PIN5,Output);

	//Select Servo motor angle Zero  -> compare value
	//call function to calc the angel -> return value

	u16 Local_CompareValue = Servo_U16CalcAnagle(0);

	//Call the PWM1_voidInitM14(Servo_Perdioc ,value);
	PWM1_VoidInitM14(Servo_Perdioc,Local_CompareValue,TI1_Prescaler8);

}
u16  Servo_U16CalcAnagle(u8 Local_Anagl)
{
	u16 local_return = (Local_Anagl *2000)/180 ;
	return local_return ;

	//return ((Local_Anagl *2000)/180) ;

}
void Servo_VoidMove(u8 Local_Anagl)
{
	u16 local_return  = Servo_U16CalcAnagle(Local_Anagl);
	PWM1_VoidSetCompareValue(local_return);
}
