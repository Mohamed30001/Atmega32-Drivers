/*
 * TWI_Private.h
 *
 *  Created on: Oct 30, 2022
 *      Author: hisha
 */

#ifndef MCAL_TWI_HEADER_TWI_PRIVATE_H_
#define MCAL_TWI_HEADER_TWI_PRIVATE_H_
/*TWI_Master Trasmit  Check */
#define TWI_MTXCheckStart         				0x08
#define TWI_MTXCheckReStart       				0x10

#define TWI_MTXCheckSLA_W_WithAck       		0x18
#define TWI_MTXCheckSLA_W_WithOutAck    	   	0x20

#define TWI_MTXCheckData_WithAck       			0x28
#define TWI_MTXCheckData_WithOutAck       		0x30

#define TWI_MRXCheckSLA_R_WithAck       		0x40
#define TWI_MRXCheckSLA_R_WithOutAck       		0x48

#define TWI_MRXCheckData_WithAck       			0x50
#define TWI_MRXCheckData_WithOutAck       		0x58

#define TWI_MTXCheckLostArbitration   			0x38


/*I will Create the List From Errot*/

typedef enum
{
NOERROR,
ErrorStartCondition,
ErrorReStartCondition,
ErrorSLAWACK,      /*Wrong when Send the Slave Address And Write*/
ErrorSLAWNotACK,
ErrorSLARACK,
ErrorSLArNotACK,
ErrorWriteDataWithAck,
ErrorWriteDataWithNotAck,
ErrorReadDataWithAck,
ErrorReadDataWithNotAck,
}TWI_ErrList;



#endif /* MCAL_TWI_HEADER_TWI_PRIVATE_H_ */
