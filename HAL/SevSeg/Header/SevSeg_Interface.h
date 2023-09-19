/*
 * SevSeg_Interface.h
 *
 *  Created on: Sep 23, 2022
 *      Author: wwwmo
 */

#ifndef HAL_SEVSEG_HEADER_SEVSEG_INTERFACE_H_
#define HAL_SEVSEG_HEADER_SEVSEG_INTERFACE_H_

void SevSeg_voidSingleInit();

void SevSeg_voidDoubleInit();

void SevSeg_voidDisplayNumber(u8 number);

void SevSeg_voidSingleCounter();

void SevSeg_voidDisplayAll();

void SevSeg_voidDisplayRange(u8 start,u8 end);


#endif /* HAL_SEVSEG_HEADER_SEVSEG_INTERFACE_H_ */
