/*
 * SPI_Program.c
 *
 *  Created on: Oct 29, 2022
 *      Author: wwwmo
 */


#include "../../../Common/Bit_Math.h"
#include "../../../Common/Macro.h"
#include "../../../Common/STD_types.h"
#include "../Header/SPI_Interface.h"


void SPI_VoidInitMaster(u8 Local_Prescaller)
{
	Clear_Bit(SPI_SPCR, SPI_SPIE);

#if SPI_DataOrder == SPI_MSP
	Clear_Bit(SPI_SPCR,SPI_DORD);

#elif SPI_DataOrder == SPI_LSB
	Set_Bit(SPCR,SPCR_DORD);
#endif

	Set_Bit(SPI_SPCR, SPI_MSTR);

#if SPI_CLKPol == SPI_HighLevel
	Clear_Bit(SPI_SPCR,SPI_CPOL);

#elif SPI_CLKPol == SPI_LowLevel
	Set_Bit(SPCR,SPCR_CPOL);

#endif

#if SPI_CLKPhase == SPI_RxFirst
	Clear_Bit(SPI_SPCR,SPI_CPHA);

#elif SPI_CLKPhase == SPI_TxFirst
	Set_Bit(SPCR,SPCR_CPHA);

#endif



	switch (Local_Prescaller)
	{
	case SPI_Prescaler2:
		Clear_Bit(SPI_SPCR,SPI_SPR0);
		Clear_Bit(SPI_SPCR,SPI_SPR1);
		Set_Bit(SPI_SPCR,SPI_SPI2X);
		break;
	case SPI_Prescaler4:
		Clear_Bit(SPI_SPCR,SPI_SPR0);
		Clear_Bit(SPI_SPCR,SPI_SPR1);
		Clear_Bit(SPI_SPCR,SPI_SPI2X);
		break;
	default:
	case SPI_Prescaler8:
		Set_Bit(SPI_SPCR,SPI_SPR0);
		Clear_Bit(SPI_SPCR,SPI_SPR1);
		Set_Bit(SPI_SPCR,SPI_SPI2X);
		break;
	case SPI_Prescaler16:
		Set_Bit(SPI_SPCR,SPI_SPR0);
		Clear_Bit(SPI_SPCR,SPI_SPR1);
		Clear_Bit(SPI_SPCR,SPI_SPI2X);
		break;
	case SPI_Prescaler32:
		Clear_Bit(SPI_SPCR,SPI_SPR0);
		Set_Bit(SPI_SPCR,SPI_SPR1);
		Set_Bit(SPI_SPCR,SPI_SPI2X);
		break;
	case SPI_Prescaler64:
		Clear_Bit(SPI_SPCR,SPI_SPR0);
		Set_Bit(SPI_SPCR,SPI_SPR1);
		Clear_Bit(SPI_SPCR,SPI_SPI2X);
		break;
	case SPI_Prescaler128:
		Set_Bit(SPI_SPCR,SPI_SPR0);
		Set_Bit(SPI_SPCR,SPI_SPR1);
		Clear_Bit(SPI_SPCR,SPI_SPI2X);
		break;
	case SPI_Prescaler64DS:
		Set_Bit(SPI_SPCR,SPI_SPR0);
		Set_Bit(SPI_SPCR,SPI_SPR1);
		Set_Bit(SPI_SPCR,SPI_SPI2X);
		break;
	}

	Set_Bit(SPI_SPCR, SPI_SPE);
}


void SPI_VoidInitSlave()
{
	Clear_Bit(SPI_SPCR,SPI_SPIE);

#if SPI_DataOrder == SPI_LSB
	Set_Bit(SPI_SPCR,SPI_DORD);

#elif SPI_DataOrder == SPI_MSB
	Clear_Bit(SPI_SPCR,SPI_DORD);

#endif

	Clear_Bit(SPI_SPCR,SPI_MSTR);

#if SPI_CLKPol == SPI_HighLevel
	Clear_Bit(SPI_SPCR,SPI_CPOL);

#elif SPI_CLKPol == SPI_LowLevel
	Clear_Bit(SPI_SPCR,SPI_CPOL);

#endif

#if SPI_CLKPhase == SPI_RxFirst
	Clear_Bit(SPI_SPCR,SPI_CPHA);

#elif SPI_CLKPhase == SPI_TxFirst
	Clear_Bit(SPI_SPCR,SPI_CPHA);

#endif

	Set_Bit(SPI_SPCR,SPI_SPE);
}


u8 SPI_u8MasterTransiver(u8 Local_Data)
{
	/* Start transmission */
	SPI_SPDR = Local_Data;

	/* Wait for transmission to complete */
	while(!Get_Bit(SPI_SPSR,SPI_SPIF));

	return SPI_SPDR;
}

void SPI_VoidSlaveSend(u8 Local_Data)
{
	SPI_SPDR = Local_Data;
}


u8 SPI_u8SlaveReceive()
{
	/* Wait for transmission complete */

	while(!Get_Bit(SPI_SPSR,SPI_SPIF));

	return SPI_SPDR;
}








