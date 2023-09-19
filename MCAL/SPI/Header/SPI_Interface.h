/*
 * SPI_Interface.h
 *
 *  Created on: Oct 29, 2022
 *      Author: wwwmo
 */

#ifndef MCAL_SPI_HEADER_SPI_INTERFACE_H_
#define MCAL_SPI_HEADER_SPI_INTERFACE_H_


#include "../../../Common/STD_types.h"
#include "SPI_Register.h"
#include "SPI_Config.h"
#include "SPI_Private.h"


void SPI_VoidInitMaster(u8 Local_Prescaller);

void SPI_VoidInitSlave();

u8 SPI_u8MasterTransiver(u8 Local_Data);

void SPI_VoidSlaveSend(u8 Local_Data);

u8 SPI_u8SlaveReceive();

#endif /* MCAL_SPI_HEADER_SPI_INTERFACE_H_ */
