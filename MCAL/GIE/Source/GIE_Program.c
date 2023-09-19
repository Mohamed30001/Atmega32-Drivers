/*
 * GIE_Program.c
 *
 *  Created on: Oct 7, 2022
 *      Author: wwwmo
 */


#include "../../../common/STD_types.h"
#include "../../../common/Bit_Math.h"
#include "../../../common/Macro.h"
#include "../Header/GIE_All.h"

void GIE_VoidEn()
{
	Set_Bit(GIE_SREG, GIE_I);
}

void GIE_VoidDis()
{
	Clear_Bit(GIE_SREG, GIE_I);
}
