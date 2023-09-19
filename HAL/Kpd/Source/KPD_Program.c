/*
 * KPD_Program.c
 *
 *  Created on: Sep 17, 2022
 *      Author: wwwmo
 */

#include "../../../common/STD_types.h"
#include "../../../common/Bit_Math.h"
#include "../../../common/Macro.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../Header/Kpd_Private.h"
#include "../Header/Kpd_Config.h"
#include "../Header/Kpd_Interface.h"



void Kpd_voidInit()
{
	DIO_u8SetPinDir(Kpd_ColomGroup,Kpd_Colom0,Output);
	DIO_u8SetPinDir(Kpd_ColomGroup,Kpd_Colom1,Output);
	DIO_u8SetPinDir(Kpd_ColomGroup,Kpd_Colom2,Output);
	DIO_u8SetPinDir(Kpd_ColomGroup,Kpd_Colom3,Output);

	DIO_u8SetPinValue(Kpd_ColomGroup,Kpd_Colom0,High);
	DIO_u8SetPinValue(Kpd_ColomGroup,Kpd_Colom1,High);
	DIO_u8SetPinValue(Kpd_ColomGroup,Kpd_Colom2,High);
	DIO_u8SetPinValue(Kpd_ColomGroup,Kpd_Colom3,High);

	DIO_u8SetPinDir(Kpd_RowGroup,Kpd_Row0,Input);
	DIO_u8SetPinDir(Kpd_RowGroup,Kpd_Row1,Input);
	DIO_u8SetPinDir(Kpd_RowGroup,Kpd_Row2,Input);
	DIO_u8SetPinDir(Kpd_RowGroup,Kpd_Row3,Input);


	DIO_u8SetPinValue(Kpd_RowGroup,Kpd_Row0,High);
	DIO_u8SetPinValue(Kpd_RowGroup,Kpd_Row1,High);
	DIO_u8SetPinValue(Kpd_RowGroup,Kpd_Row2,High);
	DIO_u8SetPinValue(Kpd_RowGroup,Kpd_Row3,High);

}


u8 Kpd_u8CheckPressed()
{
	u8 ColomCounter = 0;
	u8 RowCounter   = 0;
	u8 Local_Value =NotPressed;
	u8 Value = Kpd_NotPressed;
	u8 Colom_Arr[Coloms_numbers] = {Kpd_Colom0, Kpd_Colom1, Kpd_Colom2, Kpd_Colom3};
	u8 Row_Arr[Rows_numbers]     = {Kpd_Row0, Kpd_Row1, Kpd_Row2, Kpd_Row3};

	for (ColomCounter=Kpd_Colom0; ColomCounter<= Kpd_Colom3; ColomCounter++)
	{
		DIO_u8SetPinValue(Kpd_ColomGroup, Colom_Arr[ColomCounter], Low);
		for (RowCounter=Kpd_Row0; RowCounter <= Kpd_Row3; RowCounter++)
		{
			DIO_u8GetBitValue(Kpd_RowGroup, Row_Arr[RowCounter - Kpd_Row0], &Local_Value);

			if(Local_Value == Low)
			{
				Value = Kpd_values[RowCounter - Kpd_Row0][ColomCounter];
				while (Local_Value == Low)
				{
					DIO_u8GetBitValue(Kpd_RowGroup, Row_Arr[RowCounter - Kpd_Row0], &Local_Value);
				}
				DIO_u8SetPinValue(Kpd_ColomGroup, Colom_Arr[ColomCounter], High);
				return Value;
			}
		}
		DIO_u8SetPinValue(Kpd_ColomGroup, Colom_Arr[ColomCounter], High);
	}
	return Value;
}
