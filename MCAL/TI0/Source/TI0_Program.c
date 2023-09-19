/*
 * TI0_Program.c
 *
 *  Created on: Oct 15, 2022
 *      Author: wwwmo
 */


#include "../Header/TI0_Interface.h"

void TI0_VoidInitNormal (u8 Local_Preload , u8 Local_Prescaller)
{

	//  select the type (GWM01 -> 0 /GWM00 -> 0 ) Normal mode
	Clear_Bit(TI0_TCCR0,TI0_WGM00);
	Clear_Bit(TI0_TCCR0,TI0_WGM01);

	//  Set The Preload Value In the Register :
	TI0_TCNT0= Local_Preload;

	//  Set the preScaller
	switch(Local_Prescaller)
	{
	case TI0_NoPrescale:
		Set_Bit(TI0_TCCR0,TI0_CS00);
		Clear_Bit(TI0_TCCR0,TI0_CS01);
		Clear_Bit(TI0_TCCR0,TI0_CS02);
		break;
	default:
	case TI0_Prescaler8:
		Clear_Bit(TI0_TCCR0,TI0_CS00);
		Set_Bit(TI0_TCCR0,TI0_CS01);
		Clear_Bit(TI0_TCCR0,TI0_CS02);
		break;
	case TI0_Prescaler64:
		Set_Bit(TI0_TCCR0,TI0_CS00);
		Set_Bit(TI0_TCCR0,TI0_CS01);
		Clear_Bit(TI0_TCCR0,TI0_CS02);
		break;
	case TI0_Prescaler256:
		Clear_Bit(TI0_TCCR0,TI0_CS01);
		Clear_Bit(TI0_TCCR0,TI0_CS00);
		Set_Bit(TI0_TCCR0,TI0_CS02);
		break;
	case TI0_Prescaler1024:
	case TI0_ExternalClkFalling:
	case TI0_ExternalClkRising:
		break;

	}
	// Enable the Interrupt
	Set_Bit(TI0_TIMSK,TI0_TOIE0);
}


void TI0_VoidInitCTC (u8 Local_CompareValue, u8 Local_ActionState , u8 Local_Prescaller )
{
	//
	// * select the type (GWM01 -> 1 /GWM00 -> 0 ) CTC mode
	Set_Bit(TI0_TCCR0,TI0_WGM01);
	Clear_Bit(TI0_TCCR0,TI0_WGM00);

	// * Set The Compare value Value In the Register :
	TI0_OCR0= Local_CompareValue;

	// * Select for the action on the OC pin :
	switch(Local_ActionState)
	{
	default:
	case TI0_OCdisconnect:
		Clear_Bit(TI0_TCCR0,TI0_COM00);
		Clear_Bit(TI0_TCCR0,TI0_COM01);
		break;
	case TI0_OCToggle:
		Clear_Bit(TI0_TCCR0,TI0_COM01);
		Set_Bit(TI0_TCCR0,TI0_COM00);
		break;
	case TI0_OCclear:
		Clear_Bit(TI0_TCCR0,TI0_COM00);
		Set_Bit(TI0_TCCR0,TI0_COM01);
		break;
	case TI0_OCset:
		Set_Bit(TI0_TCCR0,TI0_COM00);
		Set_Bit(TI0_TCCR0,TI0_COM01);
		break;
	}

	// * Set the preScaller
	switch (Local_Prescaller)
	{
	case TI0_NoPrescale:
		Set_Bit(TI0_TCCR0,TI0_CS00);
		Clear_Bit(TI0_TCCR0,TI0_CS01);
		Clear_Bit(TI0_TCCR0,TI0_CS02);
		break;
	default:
	case TI0_Prescaler8:
		Clear_Bit(TI0_TCCR0,TI0_CS00);
		Set_Bit(TI0_TCCR0,TI0_CS01);
		Clear_Bit(TI0_TCCR0,TI0_CS02);
		break;
	case TI0_Prescaler64:
		Set_Bit(TI0_TCCR0,TI0_CS00);
		Set_Bit(TI0_TCCR0,TI0_CS01);
		Clear_Bit(TI0_TCCR0,TI0_CS02);
		break;
	case TI0_Prescaler256:
		Clear_Bit(TI0_TCCR0,TI0_CS01);
		Clear_Bit(TI0_TCCR0,TI0_CS00);
		Set_Bit(TI0_TCCR0,TI0_CS02);
		break;
	case TI0_Prescaler1024:
	case TI0_ExternalClkFalling:
	case TI0_ExternalClkRising:
		break;
	}

	// * Enable the Interrupt
	Set_Bit(TI0_TIMSK,TI0_OCIE0);
}



void TI0_VoidSetPreload(u8 Local_Preload)
{
	TI0_TCCR0 = Local_Preload;
}



void PWM_VoidInit(u8 Dutycycle)
{
	Set_Bit(TI0_TCCR0, TI0_WGM00);
	Set_Bit(TI0_TCCR0, TI0_WGM01);

	Clear_Bit(TI0_TCCR0, TI0_COM00);
	Set_Bit(TI0_TCCR0, TI0_COM01);

	Clear_Bit(TI0_TCCR0,TI0_CS00);
	Set_Bit(TI0_TCCR0,TI0_CS01);
	Clear_Bit(TI0_TCCR0,TI0_CS02);

	DIO_u8SetPinDir(DIO_GroupB, DIO_PIN3, Output);

	PWM_VoidDutycycle(Dutycycle);

}

void PWM_VoidDutycycle(u8 Dutycycle)
{

	TI0_OCR0 = ((float) Dutycycle/100)*256;
}

void PWM_VoidStop()
{
	Clear_Bit(TI0_TCCR0,TI0_CS00);
	Clear_Bit(TI0_TCCR0,TI0_CS01);
	Clear_Bit(TI0_TCCR0,TI0_CS02);
}






































/*This part for the CallBackfunction Concept so please wait untill you understand this concept ^_^*/
//static void (*GPTF_Normal) (void) = NULL;
//static void (*GPTF_CTC) (void) = NULL;
//void TI0_CallBackFunctionNormal(void (*PTF)(void))
//{
//	if (PTF!=NULL)
//	{
//		GPTF_Normal = PTF ;
//	}
//}
//
//
////Normal Mode Interrupt
//void __vector_11(void)
//{
//	GPTF_Normal();
//}
//
//
//
//void TI0_CallBackFunctionCTC(void (*PTF)(void))
//{
//	if (PTF!=NULL)
//		{
//			GPTF_CTC = PTF ;
//		}
//}
//
////CTC Mode Interrput
//void __vector_10(void)
//{
//	GPTF_CTC();
//}
