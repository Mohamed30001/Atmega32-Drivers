/*
 * Lcd_Interface.h
 *
 *  Created on: Sep 23, 2022
 *      Author: hisha
 */

#ifndef HAL_LCD_HEADER_LCD_INTERFACE_H_
#define HAL_LCD_HEADER_LCD_INTERFACE_H_

#include "Lcd_Config.h"
#include "Lcd_Private.h"
void LCD_VoidInit(void);
void LCD_VoidSendCommand(u8 Local_Command);
void LCD_VoidSendChar(u8 Local_Char);
void LCD_VoidSendString(u8 *Address_String);
void LCD_VoidGoToXY(u8 Local_XPosition,u8 Local_YPosition);
void LCD_VoidSendNumber(u32 local_U32Number);
void LCD_VoidStoreSpecialChar(u8* Local_U8PatternArray , u8 Local_U8PatternNum);
void LCD_VoidDisplaySpecialChar(u8 Local_U8PatternNum);


#endif /* HAL_LCD_HEADER_LCD_INTERFACE_H_ */
