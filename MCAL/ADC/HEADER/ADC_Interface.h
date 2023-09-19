/*
 * ADC_Interface.h
 *
 *  Created on: Oct 14, 2022
 *      Author: wwwmo
 */

#ifndef MCAL_ADC_HEADER_ADC_INTERFACE_H_
#define MCAL_ADC_HEADER_ADC_INTERFACE_H_

#include "ADC_Interface.h"
#include "ADC_Register.h"
#include "ADC_private.h"




void ADC_voidInit();
u16 ADC_u16StartConversion(u8 Channel);
u16 ADC_u16StartConversion2(u8 Channel);

#endif /* MCAL_ADC_HEADER_ADC_INTERFACE_H_ */
