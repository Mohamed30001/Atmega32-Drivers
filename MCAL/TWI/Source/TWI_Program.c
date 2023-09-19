/*
 * TWI_Program.c
 *
 *  Created on: Oct 30, 2022
 *      Author: hisha
 */

#include "../Header/TWI_Interface.h"





void TWI_VoidMasterInit(void)
{
	/*Set Prescaler Values*//*TWSR->TWPS0 TWPS1*/
	Clear_Bit(TWI_TWSR,TWI_TWPS0);
	Clear_Bit(TWI_TWSR,TWI_TWPS1);

	/*Set TWBR with the Value =>200KHZ*/
	TWI_TWBR = 12 ;

	/*Enable  ACK*/
	Set_Bit(TWI_TWCR,TWI_TWEA);

	/*Enable  I2C*/
	Set_Bit(TWI_TWCR,TWI_TWEN);

}
TWI_ErrList TWI_VoidStartCondition(void)
{
	TWI_ErrList State = NOERROR;

	/*Clear Flag + Start Condition*/
	Set_Bit(TWI_TWCR,TWI_TWINT);
	Set_Bit(TWI_TWCR,TWI_TWSTA);

	/*wait the flag */
	while (Get_Bit(TWI_TWCR,TWI_TWINT)==0);

	/* chack on ack */
	if ((TWI_TWSR & 0xf8) != TWI_MTXCheckStart)
	{
		/*Error */
		State = ErrorStartCondition;
	}
	/*Clear the Start Condition*/
	Clear_Bit(TWI_TWCR,TWI_TWSTA);

	return State ;
}


TWI_ErrList TWI_VoidReStartCondition(void)
{
	TWI_ErrList State = NOERROR;

		/*Clear Flag + Start Condition*/
		Set_Bit(TWI_TWCR,TWI_TWINT);
		Set_Bit(TWI_TWCR,TWI_TWSTA);

		/*wait the flag */
		while (Get_Bit(TWI_TWCR,TWI_TWINT)==0);

		/*chack on ack -> Restart */
		if ((TWI_TWSR & 0xf8) != TWI_MTXCheckReStart)
		{
			/*Error */
			State = ErrorReStartCondition;
		}

		/*Clear the Start Condition*/
		Clear_Bit(TWI_TWCR,TWI_TWSTA);

		return State ;
}

/*Send the SlaveAdd Write*/
/*this Slave Address You want Connect it */

TWI_ErrList TWI_VoidSendSlaveAddressWithWriteACK(u8 Local_SlaveAddress)
{
	TWI_ErrList State = NOERROR ;

	/*Send the Slave Address */
	TWI_TWDR = (Local_SlaveAddress<< 1);

	/*Select the Write Mode*/
	Clear_Bit(TWI_TWDR , 0 );

	/*Clear Flag*/
	Set_Bit(TWI_TWCR,TWI_TWINT);

	/*wait the flag*/
	while(Get_Bit(TWI_TWCR,TWI_TWINT)==0);

	/*Check ACK*/
	if ((TWI_TWSR & 0xf8 ) != TWI_MTXCheckSLA_W_WithAck)
	{
		State = ErrorSLAWACK ;
	}

	return State ;
}


TWI_ErrList TWI_VoidSendSlaveAddressWithWriteNACK(u8 Local_SlaveAddress)
{
	TWI_ErrList State =NOERROR ;

		/*Send the Slave Address */
		TWI_TWDR = (Local_SlaveAddress<< 1);

		/*Select the Write Mode*/
		Clear_Bit(TWI_TWDR , 0 );

		/*Clear Flag*/
		Set_Bit(TWI_TWCR,TWI_TWINT);

		/*wait the flag*/
		while(Get_Bit(TWI_TWCR,TWI_TWINT)==0);

		/*Check ACK*/
		if ((TWI_TWSR & 0xf8 ) != TWI_MTXCheckSLA_W_WithOutAck)
		{
			State = ErrorSLAWNotACK ;
		}

	return State ;

}


/*Send the SlaveAdd Read*/
TWI_ErrList TWI_VoidSendSlaveAddressWithReadACK(u8 Local_SlaveAddress)
{
	TWI_ErrList State = NOERROR;

	TWI_TWDR = (Local_SlaveAddress<< 1);

	/*Read */
	Set_Bit(TWI_TWDR, 0 );

	/**/
	Set_Bit(TWI_TWCR,TWI_TWINT);

	/**/
	while(Get_Bit(TWI_TWCR,TWI_TWINT)==0);

	/**/
	if ((TWI_TWSR & 0xf8) != TWI_MRXCheckSLA_R_WithAck)
	{
		State = ErrorSLARACK ;
	}

	return State ;
}


TWI_ErrList TWI_VoidSendSlaveAddressWithReadNACK(u8 Local_SlaveAddress)
{
	TWI_ErrList State = NOERROR;

		TWI_TWDR = (Local_SlaveAddress<< 1);

		/*Read */
		Set_Bit(TWI_TWDR, 0 );

		/**/
		Set_Bit(TWI_TWCR,TWI_TWINT);

		/**/
		while(Get_Bit(TWI_TWCR,TWI_TWINT)==0);

		/**/
		if ((TWI_TWSR & 0xf8) != TWI_MRXCheckSLA_R_WithOutAck)
		{
			State = ErrorSLArNotACK ;
		}

	return State ;
}


/* Master Send the Data*/
TWI_ErrList TWI_VoidMasterWriteDataACK(u8 Local_Data)
{
	TWI_ErrList State = NOERROR;

	/*Write Data*/
	TWI_TWDR = Local_Data ;

	/*Clear Flag*/
	Set_Bit(TWI_TWCR,TWI_TWINT);

	/*wait flag*/
	while(Get_Bit(TWI_TWCR,TWI_TWINT)==0);

	/*Check Ack => */
	if ((TWI_TWSR & 0xf8) != TWI_MRXCheckData_WithAck)
		{
			State = ErrorWriteDataWithAck ;
		}

	return State ;
}


TWI_ErrList TWI_VoidMasterWriteDataNACK(u8 Local_Data)
{
	TWI_ErrList State = NOERROR;

	/*Write Data*/
	TWI_TWDR = Local_Data ;

	/*Clear Flag*/
	Set_Bit(TWI_TWCR,TWI_TWINT);

	/*wait flag*/
	while(Get_Bit(TWI_TWCR,TWI_TWINT)==0);

	/*Check Ack => */
	if ((TWI_TWSR & 0xf8) != TWI_MRXCheckData_WithOutAck)
		{
			State = ErrorWriteDataWithNotAck ;
		}

	return State ;
}


/*Master Rx the Data*/
TWI_ErrList  TWI_u8MasterReadDataACK(u8 *Recive_Data)
{
	/*Check About Pointer*/
	if (Recive_Data != NULL)
	{
		/*State var*/
		TWI_ErrList State = NOERROR ;

		/*clear flag*/
		Set_Bit(TWI_TWCR,TWI_TWINT);

		/*wait flag*/
		while(Get_Bit(TWI_TWCR,TWI_TWINT)==0);

		/*check ack*/
		if ((TWI_TWSR & 0xf8) != TWI_MRXCheckData_WithAck)
		{
			State = ErrorReadDataWithAck;
		}
		else
		{
			*Recive_Data = TWI_TWDR ;
		}
	return State ;
	}

}


TWI_ErrList TWI_u8MasterReadDataNACK(u8 *Recive_Data)
{
	/*Check About Pointer*/
		if (Recive_Data != NULL)
		{
			/*State var*/
			TWI_ErrList State = NOERROR;

			/*clear flag*/
			Set_Bit(TWI_TWCR,TWI_TWINT);

			/*wait flag*/
			while(Get_Bit(TWI_TWCR,TWI_TWINT)==0);

			/*check ack*/
			if ((TWI_TWSR & 0xf8) != TWI_MRXCheckData_WithOutAck)
			{
				State = ErrorReadDataWithNotAck;
			}
			else
			{
				*Recive_Data = TWI_TWDR ;
			}
		return State ;
		}
}


/*Stop*/
void TWI_VoidStopCondition(void)
{
//	clear flag
	Set_Bit(TWI_TWCR,TWI_TWINT);

//	Set the Stop Condition
	Set_Bit(TWI_TWCR , TWI_TWSTO);

}


/*Slave*/
void TWI_VoidSlaveInit(u8 Local_SlaveAddress)
{
 	/*Set Slave Address iN TWAR*/
	TWI_TWAR = (Local_SlaveAddress <<1);

	/*Enable ACK*/
	Set_Bit(TWI_TWCR , TWI_TWEA);

	/*Enable I2C*/
	Set_Bit(TWI_TWCR , TWI_TWEN);
}


void TWI_VoidSlaveSendData(u8 Local_Data)
{

}


u8   TWI_u8SlaveReciveData(void)
{

}
