/*
 * DIO_Private.h
 *
 *  Created on: Sep 16, 2022
 *      Author: wwwmo
 */

#ifndef MCAL_DIO_HEADER_DIO_PRIVATE_H_
#define MCAL_DIO_HEADER_DIO_PRIVATE_H_


#define DIO_GroupA   1
#define DIO_GroupB   2
#define DIO_GroupC   3
#define DIO_GroupD   4

#define DIO_PIN0     0
#define DIO_PIN1     1
#define DIO_PIN2     2
#define DIO_PIN3     3
#define DIO_PIN4     4
#define DIO_PIN5     5
#define DIO_PIN6     6
#define DIO_PIN7     7

#define DIO_Low      0
#define DIO_High     1

#define DIO_GroupOut     0xff
#define DIO_GroupHigh    0xff
#define DIO_GroupLow    0x00

#define DIO_Input    0
#define DIO_Output   1

#define DIO_PullUpEn  1
#define DIO_PullUpDis 2

#define DIO_PortConnection  0
#define DIO_PinConnection   1



typedef enum
{
	RequestHandled,
	RequestErrorGroupOutOfRange,
	RequestErrorPinOutOfRange,
	RequestErrorNotValidState,
	RequestErrorNotValidValue,


}RequestState;


#endif /* MCAL_DIO_HEADER_DIO_PRIVATE_H_ */
