/*
 * UART_program.c
 *
 *  Created on: Oct 28, 2022
 *      Author: hisha
 */
#include "../../../Common/Bit_Math.h"
#include "../../../Common/Macro.h"
#include "../../../Common/STD_types.h"

#include "../Header/UART_Register.h"
#include "../Header/UART_Interface.h"


void UART_VoidInit(u16 Baudrate)
{
	/*Select the PD0 as INPUT */
	/*Select the PD1 as OUPUT*/
	u16 UBRR  ;
	/*Calc the Baud rate */
#if UART_OperationMode == UART_NormalMode
	/*baud rate & U2X Must Be Zero*/
	UBRR = (((FOC)/(16UL*Baudrate))-1) ;
	Clear_Bit(UART_UCSRA,UART_U2X);
#elif UART_OperationMode == UART_DoubleSpeedMode
	/*baud rate divi 8 & U2X Must Be One*/
	UBRR = (((FOC)/(8*Baudrate))-1) ;
	Set_Bit(UART_UCSRA,UART_U2X);
#endif
	UART_UBRRL = (u8)UBRR ;
	UART_UBRRH = (u8)(UBRR>>8);

	UART_UCSRB = (1<<UART_RXEN)|(1<<UART_TXEN);

	UART_UCSRC = (1<<UART_URSEL)|(1<<UART_USBS)| (1<<UART_UCSZ0) |(1<<UART_UCSZ1);
}

void UART_VoidTx(u8 local_data)
{
/*Polling*/
/*Wait Until the Tx Buffer Must be Empty*/
	while(Get_Bit(UART_UCSRA,UART_UDRE)==0);
	UART_UDR = local_data ;


}

u8  UART_voidRX(void)
{
	/*Wait until the Rx flag == 1*/
	while(Get_Bit(UART_UCSRA ,UART_RXC)==0);
	return UART_UDR ;

}
