/*
 * Kpd_Config.h
 *
 *  Created on: Sep 17, 2022
 *      Author: wwwmo
 */

#ifndef HAL_KPD_HEADER_KPD_CONFIG_H_
#define HAL_KPD_HEADER_KPD_CONFIG_H_

#include "../../../MCAL/DIO/Header/DIO_Interface.h"

#define Kpd_ColomGroup  DIO_GroupA

#define Kpd_Colom0  DIO_PIN0
#define Kpd_Colom1  DIO_PIN1
#define Kpd_Colom2  DIO_PIN2
#define Kpd_Colom3  DIO_PIN3

#define Kpd_RowGroup  DIO_GroupA

#define Kpd_Row0  DIO_PIN4
#define Kpd_Row1  DIO_PIN5
#define Kpd_Row2  DIO_PIN6
#define Kpd_Row3  DIO_PIN7

#define Rows_numbers    4
#define Coloms_numbers  4

const static u8 Kpd_values[Rows_numbers][Coloms_numbers] ={
		{7,8,9,'/'},
		{4,5,6,'*'},
		{1,2,3,'-'},
		{'=',0,'c','+'}
};



#endif /* HAL_KPD_HEADER_KPD_CONFIG_H_ */
