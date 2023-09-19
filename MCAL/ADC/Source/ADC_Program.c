/*
 * ADC_Program.c
 *
 *  Created on: Oct 8, 2022
 *      Author: wwwmo
 */


#include "../../../common/STD_types.h"
#include "../../../common/Bit_Math.h"
#include "../../../common/Macro.h"
#include "../Header/ADC_Interface.h"
#include "../Header/ADC_Register.h"
#include "../Header/ADC_private.h"
#include "../../GIE/Header/GIE_All.h"


void ADC_voidInit()
{
	Set_Bit(ADC_ADMUX,ADC_REFS0);
	Clear_Bit(ADC_ADMUX,ADC_REFS1);

	Clear_Bit(ADC_ADMUX,ADC_ADLAR);

	Set_Bit(ADC_ADCSRA,ADC_ADEN);
	Clear_Bit(ADC_ADCSRA,ADC_ADIE);

	Set_Bit(ADC_ADCSRA,ADC_ADPS0);
	Set_Bit(ADC_ADCSRA,ADC_ADPS1);
	Clear_Bit(ADC_ADCSRA,ADC_ADPS2);

}
u16 ADC_u16StartConversion(u8 Channel)
{

	Channel   &= 0x07;
	ADC_ADMUX &= 0xE0;
	ADC_ADMUX |= Channel;

	Set_Bit(ADC_ADCSRA,ADC_ADSC);

	while(Get_Bit(ADC_ADCSRA,ADC_ADIF) == 0);
	Set_Bit(ADC_ADCSRA,ADC_ADIF);

	return ADC_DATA;
}

/*
u16 ADC_u16StartConversion2(u8 Channel)
{




}
*/







