/*
 * GIE_All.h
 *
 *  Created on: Oct 7, 2022
 *      Author: wwwmo
 */

#ifndef MCAL_GIE_HEADER_GIE_ALL_H_
#define MCAL_GIE_HEADER_GIE_ALL_H_

#define GIE_SREG   (*(volatile u8*)0x5F)
#define GIE_I  7

void GIE_VoidEn();
void GIE_VoidDis();


#endif /* MCAL_GIE_HEADER_GIE_ALL_H_ */
