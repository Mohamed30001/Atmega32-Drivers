/*
 * Lcd_Private.h
 *
 *  Created on: Sep 23, 2022
 *      Author: hisha
 */

#ifndef HAL_LCD_HEADER_LCD_PRIVATE_H_
#define HAL_LCD_HEADER_LCD_PRIVATE_H_


/*------------------------------------------------------------------------------------------*/
/*Clear Display*/
#define LCD_ClearDisplay     0x01

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Return Home*/
#define LCD_ReturnHome       0x02
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Entry Mode Set*/
#define LCD_EntryMode2       0x06 //  S = 0 (no screen shifting) & I/D = 1 (Increment cursor position)   /*Increment cursor (shift cursor to right)*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

/*Display OFF*/
#define LCD_DisplayOFF   0x08  // D = 0    C = 0    B = 0    The Display is Off so Will Cursor is off  And Blinking is OFF
#define LCD_DisplayON    0x0C  // D = 1    C = 0    B = 0    The Display is On But the Cursor is OFF so the Blinking is OFF
#define LCD_CursorON     0x0E
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Function Set
RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
=== === === === === === === === === ===
 0   0   0   0   1   DL  N   F   *   *
*/

#define  LCD_Set4Bit1Line5x8         0x20     // the Data Will Send by 4 bit and the Number of line is 1 and the Font is 5x8
#define  LCD_Set4Bit1Line5x11        0x24     // the Data Will Send by 4 bit and the Number of line is 1 and the Font is 5x11
#define  LCD_Set4Bit2Line5x8	     0x28     // the Data Will Send by 4 bit and the Number of line is 2 and the Font is 5x8
#define  LCD_Set4Bit2Line5x11        0x2C     // the Data Will Send by 4 bit and the Number of line is 2 and the Font is 5x11
#define  LCD_Reset		             0x30     // the Data Will Send by 8 bit and the Number of line is 1 and the Font is 5x8
#define  LCD_Set8Bit1Line5x11    	 0x34     // the Data Will Send by 8 bit and the Number of line is 1 and the Font is 5x11
#define  LCD_Set8Bit2Line5x8     	 0x38     // the Data Will Send by 8 bit and the Number of line is 2 and the Font is 5x8
#define  LCD_Set8Bit2Line5x11    	 0x3C     // the Data Will Send by 8 bit and the Number of line is 2 and the Font is 5x11
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Set CG RAM Address*/
#define  LCD_SetAddressCGRAM      0x40
/*---------------------------------------------------------------------------------------------------*/

/*Set DDRAM Address*/
#define  LCD_SetAddressDDRAM      0x80
/*---------------------------------------------------------------------------------------------------*/


/*************************************************************************************
 *                                Declaring Options                                  *
 *************************************************************************************/

/*
 * Options for the Pin Direction/Value of the LCD
 */

#define LCD_PinLOW          	LOW
#define LCD_PinHIGH         	HIGH
#define LCD_PinINPUT        	INPUT
#define LCD_PinOUTPUT       	OUTPUT
#define LCD_PORTMAXVALUE    	0xFF
#define LCD_CGRAMPatternSize    8

/**********************************************/
#define LCD_FirstLine     0x00
#define LCD_SecondLine    0x40


#endif /* HAL_LCD_HEADER_LCD_PRIVATE_H_ */
