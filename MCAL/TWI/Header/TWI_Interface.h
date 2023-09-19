/*
 * TWI_Interface.h
 *
 *  Created on: Oct 30, 2022
 *      Author: hisha
 */

#include "../../../Common/STD_types.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/Macro.h"
#include "TWI_Register.h"
#include "TWI_Private.h"
#include "TWI_Configruation.h"



#ifndef MCAL_TWI_HEADER_TWI_INTERFACE_H_
#define MCAL_TWI_HEADER_TWI_INTERFACE_H_

void TWI_VoidMasterInit(void);
TWI_ErrList TWI_VoidStartCondition(void);
TWI_ErrList TWI_VoidReStartCondition(void);

/*Send the SlaveAdd Write*/
/*this Slave Address You want Connect it */
TWI_ErrList TWI_VoidSendSlaveAddressWithWriteACK(u8 Local_SlaveAddress);
TWI_ErrList TWI_VoidSendSlaveAddressWithWriteNACK(u8 Local_SlaveAddress);

/*Send the SlaveAdd Read*/
TWI_ErrList TWI_VoidSendSlaveAddressWithReadACK(u8 Local_SlaveAddress);
TWI_ErrList TWI_VoidSendSlaveAddressWithReadNACK(u8 Local_SlaveAddress);

/* Master Send the Data*/
TWI_ErrList TWI_VoidMasterWriteDataACK(u8 Local_Data);
TWI_ErrList TWI_VoidMasterWriteDataNACK(u8 Local_Data);

/*Master Rx the Data*/
TWI_ErrList  TWI_u8MasterReadDataACK(u8 *Recive_Data);
TWI_ErrList  TWI_u8MasterReadDataNACK(u8 *Recive_Data);

/*Stop*/
void TWI_VoidStopCondition(void);

/*Slave*/
void TWI_VoidSlaveInit(u8 Local_SlaveAddress);
void TWI_VoidSlaveSendData(u8 Local_Data);
u8   TWI_u8SlaveReciveData(void);
#endif /* MCAL_TWI_HEADER_TWI_INTERFACE_H_ */
