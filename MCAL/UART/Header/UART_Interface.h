/*
 * UART_Interface.h
 *
 *  Created on: Oct 28, 2022
 *      Author: hisha
 */

#ifndef DEBUG_MCAL_UART_HEADER_UART_INTERFACE_H_
#define DEBUG_MCAL_UART_HEADER_UART_INTERFACE_H_


#include "../../../Common/STD_types.h"
#include "UART_Register.h"
#include "UART_Private.h"
#include "UART_Config.h"


void UART_VoidInit(u16 Baudrate);
void UART_VoidTx(u8 local_data);
u8  UART_voidRX(void);


#endif /* DEBUG_MCAL_UART_HEADER_UART_INTERFACE_H_ */
