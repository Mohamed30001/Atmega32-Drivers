/*
 * lcd_program.c
 *
 *  Created on: Sep 23, 2022
 *      Author: hisha
 */


#include "../../../Common/Macro.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/STD_Types.h"
#include <util/delay.h>

#include "../../../MCAL/DIO/Header/DIO_Interface.h"

#include "../Header/Lcd_Private.h"
#include "../Header/Lcd_Config.h"
#include "../Header/Lcd_Interface.h"

void LCD_VoidSendCommand(u8 Local_Command)
{
	/*Select the Rs As Command Low*/
	DIO_u8SetPinValue(Lcd_ControlGroup,Lcd_ControlRS,Low);
	/*Select the Rw as Write (LOW)*/
	DIO_u8SetPinValue(Lcd_ControlGroup,Lcd_ControlRW,Low);
	/*Write the Command On the Group for Data*/
	DIO_u8SetPortValue(Lcd_DataGroup,Local_Command);
	/*Select the E Running (High)*/
	DIO_u8SetPinValue(Lcd_ControlGroup,Lcd_ControlE,High);
	/*Waiting For 1ms*/
	_delay_ms(1);
	/*Select the E Spoted (Low)*/
	DIO_u8SetPinValue(Lcd_ControlGroup,Lcd_ControlE,Low);
}

void LCD_VoidSendChar(u8 Local_Char)
{
	/*Select the Rs As Data Low*/
	DIO_u8SetPinValue(Lcd_ControlGroup,Lcd_ControlRS,High);
	/*Select the Rw as Write (LOW)*/
	DIO_u8SetPinValue(Lcd_ControlGroup,Lcd_ControlRW,Low);
	/*Write the Command On the Group for Data*/
	DIO_u8SetPortValue(Lcd_DataGroup,Local_Char);
	/*Select the E Running (High)*/
	DIO_u8SetPinValue(Lcd_ControlGroup,Lcd_ControlE,High);
	/*Waiting For 1ms*/
	_delay_ms(1);
	/*Select the E Stoped (Low)*/
	DIO_u8SetPinValue(Lcd_ControlGroup,Lcd_ControlE,Low);
}

void LCD_VoidInit(void)
{
	DIO_u8SetPinDir(Lcd_ControlGroup,Lcd_ControlE,DIO_Output);
	DIO_u8SetPinDir(Lcd_ControlGroup,Lcd_ControlRS,DIO_Output);
	DIO_u8SetPinDir(Lcd_ControlGroup,Lcd_ControlRW,DIO_Output);
	DIO_u8SetPortDir(Lcd_DataGroup, DIO_GroupOut);
/*wait the delay */
_delay_ms(35);
/*send the function set */
LCD_VoidSendCommand(0x38);
/*Wait for 39us*/
_delay_ms(1);
/*Send the Display on */
LCD_VoidSendCommand(0x0C);
/*wait for 39us*/
_delay_ms(1);
/*send the clear*/
LCD_VoidSendCommand(0x01);
/*wait for 1.53ms*/
_delay_ms(2);
}



void LCD_VoidSendString(u8 *Address_String)
{
	u8 Counter = 0;


	while (Address_String[Counter] != '\0')
	{
	LCD_VoidSendChar( Address_String[Counter]);
	Counter++;
	}
}


void LCD_VoidGoToXY(u8 Local_XPosition,u8 Local_YPosition)
{
	 u8 position = 0 ;

	 if (Local_XPosition == LCD_FirstLine)
	 {
		 position = LCD_FirstLine + Local_YPosition;
	 }
	 else
	 {
		 position = LCD_SecondLine + Local_YPosition;
	 }
	 Set_Bit(position, 7);
	 LCD_VoidSendCommand(position);
}


void LCD_VoidSendNumber(u32 local_U32Number)
{
	u32 Reminder =0;
	u16 arr [sizeof(u32)] = {0};
	u32 i = 0;
	while (local_U32Number != 0)
	{
		Reminder = local_U32Number % 10;
		local_U32Number /=10;
		arr[i] = Reminder;
		i++;
	}

	for(int count = i-1; count >=0; count--)
	{
		LCD_VoidSendChar(arr[count] + '0');
	}
}













