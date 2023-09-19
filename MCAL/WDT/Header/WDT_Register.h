/*
 * WDT_Register.h
 *
 *  Created on: Oct 22, 2022
 *      Author: wwwmo
 */

#ifndef MCAL_WDT_HEADER_WDT_REGISTER_H_
#define MCAL_WDT_HEADER_WDT_REGISTER_H_


#define WDT_WDTCR       (*(volatile u8 *)0x41)
#define WDT_WDTOE       4 // Trun off
#define WDT_WDE     	3 // Enable WDT


#endif /* MCAL_WDT_HEADER_WDT_REGISTER_H_ */
