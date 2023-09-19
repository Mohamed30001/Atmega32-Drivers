/*
 * WDT_Interface.h
 *
 *  Created on: Oct 22, 2022
 *      Author: wwwmo
 */

#ifndef MCAL_WDT_HEADER_WDT_INTERFACE_H_
#define MCAL_WDT_HEADER_WDT_INTERFACE_H_

#include "WDT_Register.h"
#include "../../../common/STD_types.h"
#include "../../../common/Bit_Math.h"

void WDT_VoidEnable(void);

void WDT_VoidDisable(void);

void WDT_u8Wait(u8 Local_SleepTime);

#endif /* MCAL_WDT_HEADER_WDT_INTERFACE_H_ */
