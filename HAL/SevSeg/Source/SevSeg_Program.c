/*
 * SevSeg_Program.c
 *
 *  Created on: Sep 23, 2022
 *      Author: wwwmo
 */


#include "util/delay.h"
#include "../../../common/STD_types.h"
#include "../../../common/Bit_Math.h"
#include "../../../common/Macro.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../Header/SevSeg_Private.h"
#include "../Header/SevSeg_Config.h"
#include "../Header/Sevseg_Interface.h"


void SevSeg_voidSingleInit()
{
	DIO_u8SetPortDir(Sev_DirC, DIO_GroupOut);
}


void SevSeg_voidDoubleInit()
{
	DIO_u8SetPortDir(Sev_DirC, DIO_GroupOut);
	DIO_u8SetPortDir(Sev_DirD, DIO_GroupOut);
}

void SevSeg_voidDisplayNumber(u8 number)
{
	u8 Sev_arr[] = Sev_Array;

	DIO_u8SetPortValue(Sev_DirC,Sev_arr[number]);
}


void SevSeg_voidSingleCounter()
{
	u8 Sev_arr[] = Sev_Array;
	u16 i;

	for(i=0; i<10; i++)
	{
		DIO_u8SetPortValue(Sev_DirC,Sev_arr[i]);
		_delay_ms(Sev_Delay);
	}
}



void SevSeg_voidDisplayAll()
{
	u8 Sev_arr[] = Sev_Array;
	u16 i;
	u16 j;

	for(i=0; i<10; i++)
	{
		DIO_u8SetPortValue(Sev_DirD,Sev_arr[i]);

		for(j=0; j<10; j++)
		{
			DIO_u8SetPortValue(Sev_DirC,Sev_arr[j]);
			_delay_ms(Sev_Delay);
		}
	}

}


void SevSeg_voidDisplayRange(u8 start,u8 end)
{
	u8 Sev_arr[] = Sev_Array;
	u16 i;
	u16 j;
	u16 count1 = 0;
	u16 count2 = 0;
	u16 start0,start1,end0,end1;

	if (start <100 && end <100)
	{

		for (i=0; i<10;i++)
		{
			if (start >= count1)
			{
				count1 = count1 + 10;
			}
			else
			{
				count1 = count1 - 10;
				start0 = i-1;
				break;
			}
		}

		for (i=0; i<10;i++)
		{
			if (start >= count1 )
			{
				count1++;
			}
			else
			{
				start1 = i-1;
				break;
			}
		}

		for (i=0; i<10;i++)
		{
			if (end >= count2 )
			{
				count2 = count2 + 10;
			}
			else
			{
				count2 = count2 - 10;
				end0 = i-1;
				break;
			}
		}


		for (i=0; i<10;i++)
		{
			if (end >= count2 )
			{
				count2++;
			}
			else
			{
				end1 = i-1;
				break;
			}
		}



		for(i=start0; i<10; i++)
		{

			DIO_u8SetPortValue(Sev_DirD,Sev_arr[i]);

			for(j=start1; j<10 ; j++)
			{
				DIO_u8SetPortValue(Sev_DirC,Sev_arr[j]);
				_delay_ms(Sev_Delay);

				if(i == end0 && j == end1)
				{
					return;
				}
			}
			start1=0;
		}

	}

}










