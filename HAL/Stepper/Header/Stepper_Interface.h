/*
 * Stepper_Interface.h
 *
 *  Created on: Oct 7, 2022
 *      Author: wwwmo
 */

#ifndef HAL_STEPPER_HEADER_STEPPER_INTERFACE_H_
#define HAL_STEPPER_HEADER_STEPPER_INTERFACE_H_

#include "../../../common/Bit_Math.h"
#include "../../../common/STD_types.h"
#include "../../../common/Macro.h"
#include "Stepper_Private.h"
#include "Stepper_Config.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"

void Stepper_VoidInit(void);
void Stepper_VoidOnCW(u16 Local_anagle);
void Stepper_VoidStop(void);

#endif /* HAL_STEPPER_HEADER_STEPPER_INTERFACE_H_ */
