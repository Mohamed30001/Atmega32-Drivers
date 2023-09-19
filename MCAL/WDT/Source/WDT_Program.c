/*
 * WDT_Program.c
 *
 *  Created on: Oct 22, 2022
 *      Author: wwwmo
 */


#include "../Header/WDT_Interface.h"


void WDT_VoidEnable(void)
{
	Set_Bit(WDT_WDTCR , WDT_WDE);
}
void WDT_VoidDisable(void)
{
	/*Bit Masking */
	WDT_WDTCR = (1<<WDT_WDE)|(1<<WDT_WDTOE);
	WDT_WDTCR = 0x00 ;
}

void WDT_u8Wait(u8 Local_SleepTime)
{
	if (Local_SleepTime < 8 )
	{
		WDT_WDTCR &= 0b11111000;
		WDT_WDTCR |= Local_SleepTime ;
	}
}
