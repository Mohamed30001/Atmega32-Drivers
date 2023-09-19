/*
 * TI1_Program.c
 *
 *  Created on: Oct 21, 2022
 *      Author: MoMenBak
 *	   Lecture: Interfacing_Lec
 */

#include "../../../Common/STD_Types.h"
#include "../../../Common/Bit_Math.h"
#include "../../../common/Macro.h"

#include "../../TI1/Header/TI1_Interface.h"

u16 Time1=0;
u16 Time2=0;
u16 Time3=0 ;
u16 ONtime=0;
u16 PerodicTime=0;

//void PWM1_VoidSevInit()
/*non inverting
 * perodic time = Over Flow time = tick time * OverFlow value
 * on time  = Compare time => compare Value *tick time  */
void PWM1_VoidInitM14(u16 Local_MaxValue,u16 Local_CompareValue, u8 Local_Prescaller)
{

	//	 *Select the Mode -> mode 14:
	//	 *  			    	WGM10 -> LOW ->TCCR1A
	Clear_Bit(TI1_TCCR1A,TI1_WGM10);
	//	 * 						WGM11 -> High->TCCR1A
	Set_Bit(TI1_TCCR1A,TI1_WGM11);
	//	 * 						WGM12 -> High->TCCR1B
	Set_Bit(TI1_TCCR1B,TI1_WGM12);
	//	 * 						WGM13 -> High->TCCR1B
	Set_Bit(TI1_TCCR1B,TI1_WGM13);
	//	 *Select The Action pwm mode-> Nin inverting & unit A (COM1A0->low)/(COM1A1->Set)
	Clear_Bit(TI1_TCCR1A,TI1_COM1A0);
	Set_Bit(TI1_TCCR1A,TI1_COM1A1);
	//	 * Assign the Max value in Register (ICR1 = Local_MaxValue)
	TI1_ICR1 = Local_MaxValue ;
	//	 * PWM1_VoidSetCompareValue(Local_CompareValue);
	TI1_OCR1A= Local_CompareValue ;
	//	 * select the Prescaller

	switch (Local_Prescaller)
	{
	case TI1_NoPrescale:
		Set_Bit(TI1_TCCR1B,TI1_CS10);
		Clear_Bit(TI1_TCCR1B,TI1_CS11);
		Clear_Bit(TI1_TCCR1B,TI1_CS12);
		break;
	default:
	case TI1_Prescaler8:
		Clear_Bit(TI1_TCCR1B,TI1_CS10);
		Set_Bit(TI1_TCCR1B,TI1_CS11);
		Clear_Bit(TI1_TCCR1B,TI1_CS12);
		break;
	case TI1_Prescaler64:
		Set_Bit(TI1_TCCR1B,TI1_CS10);
		Set_Bit(TI1_TCCR1B,TI1_CS11);
		Clear_Bit(TI1_TCCR1B,TI1_CS12);
		break;
	case TI1_Prescaler256:
		Clear_Bit(TI1_TCCR1B,TI1_CS10);
		Clear_Bit(TI1_TCCR1B,TI1_CS11);
		Set_Bit(TI1_TCCR1B,TI1_CS12);
		break;
	case TI1_Prescaler1024:
	case TI1_ExternalClkFalling:
	case TI1_ExternalClkRising:
		break;
	}


}

void PWM1_VoidSetCompareValue(u16 Local_CompareValue)
{
	TI1_OCR1A = Local_CompareValue ;
}


void ICU_VoidInit()
{	//TCCR1A TCCR1A TCCR1B  TCCR1B
	//WGM10  WGM11  WGM12   WGM13   Normal Mode
	// 0     0      0       0
	Clear_Bit(TI1_TCCR1A,TI1_WGM10);
	Clear_Bit(TI1_TCCR1A,TI1_WGM11);
	Clear_Bit(TI1_TCCR1B,TI1_WGM12);
	Clear_Bit(TI1_TCCR1B,TI1_WGM13);
	/*------------------------------------------------*/
	//Enable the Interrupt
	Set_Bit(TI1_TIMSK,TI1_TICIE1);
	//Select the Edge Rising
	ICU_VoidSelectEdge(Rising);
	//prescaller 8
	Clear_Bit(TI1_TCCR1B,TI1_CS10);
	Set_Bit(TI1_TCCR1B,TI1_CS11);
	Clear_Bit(TI1_TCCR1B,TI1_CS12);


}
void ICU_VoidSelectEdge(u8 Local_TypeOfEdge)
{
	switch(Local_TypeOfEdge)
	{
	case Falling : Clear_Bit(TI1_TCCR1B,TI1_ICES1); break ;
	default      :
	case Rising  : Set_Bit(TI1_TCCR1B,TI1_ICES1);   break ;

	}
}

void __vector_6(void)
{

	u8 static Local_Counter = 0 ;
	Local_Counter++;
	if(Local_Counter==1)
	{
		Time1 = TI1_ICR1 ;
		ICU_VoidSelectEdge(Falling);
	}
	else if (Local_Counter==2)
	{
		Time2= TI1_ICR1  ;
		ONtime=Time2 - Time1;
		ICU_VoidSelectEdge(Rising);
	}
	else if (Local_Counter==3)
	{
		Time3 = TI1_ICR1 ;
		PerodicTime=Time3 - Time1 ;

	}
	else
	{
		/*Disable Interrupt */
		/*Disable Timer*/

		Clear_Bit(TI1_TCCR1B,TI1_CS10);
		Clear_Bit(TI1_TCCR1B,TI1_CS11);
		Clear_Bit(TI1_TCCR1B,TI1_CS12);
	}

}









