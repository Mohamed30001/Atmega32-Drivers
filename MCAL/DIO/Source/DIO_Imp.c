/*
 * DIO_Imp.c
 *
 *  Created on: Sep 16, 2022
 *      Author: wwwmo
 */


#include "../../../common/STD_types.h"
#include "../../../common/Bit_Math.h"
#include "../../../common/Macro.h"

#include "../Header/DIO_Register.h"
#include "../Header/DIO_Private.h"
#include "../Header/DIO_Config.h"
#include "../Header/DIO_Interface.h"


u8 DIO_u8SetPinDir(u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PinState)
{
	RequestState Request;
	if ((Local_GroupName <= DIO_GroupD) && (Local_GroupName >= DIO_GroupA))
	{
		if((Local_PinNumber <= DIO_PIN7 ) && (Local_PinNumber >= DIO_PIN0))
		{
			if ((Local_PinState == DIO_Output))
			{
				switch(Local_GroupName)
				{
				case DIO_GroupA : DIO_DDRA |=(1<<Local_PinNumber);
				Request = RequestHandled;
				break;

				case DIO_GroupB : DIO_DDRB |=(1<<Local_PinNumber);
				Request = RequestHandled;
				break;

				case DIO_GroupC : DIO_DDRC |=(1<<Local_PinNumber);
				Request = RequestHandled;
				break;

				case DIO_GroupD : DIO_DDRD |=(1<<Local_PinNumber);
				Request = RequestHandled;
				break;
				}

			}
			else
			{
				Request= RequestErrorNotValidState;
			}
		}
		else
		{
			Request = RequestErrorPinOutOfRange;
		}
	}
	else
	{
		Request = RequestErrorGroupOutOfRange;
	}
	return Request;
}

u8 DIO_u8SetPinValue(u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PinValue)
{
	u8 Request;
	if(Local_GroupName <= DIO_GroupD && Local_GroupName >= DIO_GroupA){

		if(Local_PinNumber <= DIO_PIN7 && Local_PinNumber >= DIO_PIN0){

			if(Local_PinValue == High){
				Request = RequestHandled;
				switch(Local_GroupName){
				case DIO_GroupA:
					Set_Bit(DIO_PORTA,Local_PinNumber);
					break;
				case DIO_GroupB:
					Set_Bit(DIO_PORTB,Local_PinNumber);
					break;
				case DIO_GroupC:
					Set_Bit(DIO_PORTC,Local_PinNumber);
					break;
				case DIO_GroupD:
					Set_Bit(DIO_PORTD,Local_PinNumber);
					break;
				}
			}
			else if(Local_PinValue == Low){
				Request = RequestHandled;
				switch(Local_GroupName){
				case DIO_GroupA:
					Clear_Bit(DIO_PORTA,Local_PinNumber);
					break;
				case DIO_GroupB:
					Clear_Bit(DIO_PORTB,Local_PinNumber);
					break;
				case DIO_GroupC:
					Clear_Bit(DIO_PORTC,Local_PinNumber);
					break;
				case DIO_GroupD:
					Clear_Bit(DIO_PORTD,Local_PinNumber);
					break;
				}

			}
			else{
				Request = RequestErrorNotValidValue;
			}


		}
		else{
			Request = RequestErrorPinOutOfRange;
		}

	}
	else{
		Request = RequestErrorGroupOutOfRange;
	}
	return Request;
}


u8 DIO_u8GetBitValue(u8 Local_GroupName, u8 Local_PinNumber, u8 *Reference_Value)
{
	u8 Request;
		if(Local_GroupName <= DIO_GroupD && Local_GroupName >= DIO_GroupA){

			if(Local_PinNumber <= DIO_PIN7 && Local_PinNumber >= DIO_PIN0){
				Request = RequestHandled;
				switch(Local_GroupName){
				case DIO_GroupA:
					*Reference_Value = Get_Bit(DIO_PINA,Local_PinNumber);
					break;
				case DIO_GroupB:
					*Reference_Value = Get_Bit(DIO_PINB,Local_PinNumber);
					break;
				case DIO_GroupC:
					*Reference_Value = Get_Bit(DIO_PINC,Local_PinNumber);
					break;
				case DIO_GroupD:
					*Reference_Value = Get_Bit(DIO_PIND,Local_PinNumber);
					break;
				}
			}
			else{
				Request = RequestErrorPinOutOfRange;
			}

		}
		else{
			Request = RequestErrorGroupOutOfRange;
		}
		return Request;
	}


u8 DIO_u8SetPortDir(u8 Local_GroupName,u8 Local_PortState){
	u8 Request;
	if(Local_GroupName <= DIO_GroupD && Local_GroupName >= DIO_GroupA){
		if(Local_PortState <= DIO_GroupOut)
		{
			Request = RequestHandled;
			switch(Local_GroupName)
			{
			case DIO_GroupA:
				 DIO_DDRA = Local_PortState;
				break;
			case DIO_GroupB:
				DIO_DDRB = Local_PortState;
				break;
			case DIO_GroupC:
				DIO_DDRC = Local_PortState;
				break;
			case DIO_GroupD:
				DIO_DDRD = Local_PortState;
				break;
			}
		}
		else{
			Request = RequestErrorNotValidState;
		}
	}
	else{
		Request = RequestErrorGroupOutOfRange;
	}
	return Request;
}


u8 DIO_u8SetPortValue(u8 Local_GroupName, u8 Local_PortValue)
{
	RequestState Request;
	if ((Local_GroupName <= DIO_GroupD) && (Local_GroupName >= DIO_GroupA))
	{
		if ((Local_PortValue <= DIO_GroupHigh))
		{
			switch(Local_GroupName)
			{
			case DIO_GroupA : DIO_PORTA = Local_PortValue;
			Request = RequestHandled;
			break;

			case DIO_GroupB : DIO_PORTB = Local_PortValue;
			Request = RequestHandled;
			break;

			case DIO_GroupC : DIO_PORTC = Local_PortValue;
			Request = RequestHandled;
			break;

			case DIO_GroupD : DIO_PORTD = Local_PortValue;
			Request = RequestHandled;
			break;
			}

		}
		else
		{
			Request= RequestErrorNotValidValue;
		}

	}
	else
	{
		Request = RequestErrorGroupOutOfRange;
	}
	return Request;
}


u8 DIO_u8GetPortRead(u8 Local_GroupName, u8 *Reference_value)
{
	RequestState Request;
	if ((Local_GroupName <= DIO_GroupD) && (Local_GroupName >= DIO_GroupA))
	{
		switch(Local_GroupName)
		{
		case DIO_GroupA : *Reference_value = DIO_PORTA;
		Request = RequestHandled;
		break;

		case DIO_GroupB : *Reference_value = DIO_PORTB;
		Request = RequestHandled;
		break;

		case DIO_GroupC : *Reference_value = DIO_PORTC;
		Request = RequestHandled;
		break;

		case DIO_GroupD : *Reference_value = DIO_PORTD;
		Request = RequestHandled;
		break;
		}

	}
	else
	{
		Request = RequestErrorGroupOutOfRange;
	}
	return Request;

}



u8 DIO_u8ControlPullUp(u8 Local_ConnectionType, u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PullUpState)
{
	RequestState Request;
	if ((Local_GroupName <= DIO_GroupD) && (Local_GroupName >= DIO_GroupA))
	{
		if(Local_ConnectionType == DIO_PortConnection)
		{
			if(Local_PullUpState == DIO_PullUpEn)
			{
				switch(Local_GroupName)
				{
				case DIO_GroupA : DIO_PORTA = DIO_GroupHigh;
				Request = RequestHandled;
				break;

				case DIO_GroupB : DIO_PORTB = DIO_GroupHigh;
				Request = RequestHandled;
				break;

				case DIO_GroupC : DIO_PORTC = DIO_GroupHigh;
				Request = RequestHandled;
				break;

				case DIO_GroupD : DIO_PORTD = DIO_GroupHigh;
				Request = RequestHandled;
				break;
				}
			}
			else if(Local_PullUpState == DIO_PullUpDis)
			{
				switch(Local_GroupName)
				{
				case DIO_GroupA : DIO_PORTA = DIO_GroupLow;
				Request = RequestHandled;
				break;

				case DIO_GroupB : DIO_PORTB = DIO_GroupLow;
				Request = RequestHandled;
				break;

				case DIO_GroupC : DIO_PORTC = DIO_GroupLow;
				Request = RequestHandled;
				break;

				case DIO_GroupD : DIO_PORTD = DIO_GroupLow;
				Request = RequestHandled;
				break;
				}
			}
			else
			{
				Request= RequestErrorNotValidState;
			}
		}

		else if(Local_ConnectionType == DIO_PinConnection)
		{
			if((Local_PinNumber <= DIO_PIN7 ) && (Local_PinNumber >= DIO_PIN0))
			{
				if ((Local_PullUpState == DIO_PullUpEn))
				{
					switch(Local_GroupName)
					{
					case DIO_GroupA : DIO_PORTA |=(1<<Local_PinNumber);
					Request = RequestHandled;
					break;

					case DIO_GroupB : DIO_PORTB |=(1<<Local_PinNumber);
					Request = RequestHandled;
					break;

					case DIO_GroupC : DIO_PORTC |=(1<<Local_PinNumber);
					Request = RequestHandled;
					break;

					case DIO_GroupD : DIO_PORTD |=(1<<Local_PinNumber);
					Request = RequestHandled;
					break;
					}
				}
				else if(Local_PullUpState == DIO_PullUpDis)
				{
					switch(Local_GroupName)
					{
					case DIO_GroupA :Clear_Bit(DIO_PORTA,Local_PinNumber);
					Request = RequestHandled;
					break;

					case DIO_GroupB : Clear_Bit(DIO_PORTB,Local_PinNumber);
					Request = RequestHandled;
					break;

					case DIO_GroupC : Clear_Bit(DIO_PORTC,Local_PinNumber);
					Request = RequestHandled;
					break;

					case DIO_GroupD : Clear_Bit(DIO_PORTD,Local_PinNumber);
					Request = RequestHandled;
					break;
					}
				}
				else
				{
					Request= RequestErrorNotValidState;
				}
			}
			else
			{
				Request = RequestErrorPinOutOfRange;
			}
		}
		else
		{
			Request= RequestErrorNotValidState;
		}
	}
	else
	{
		Request = RequestErrorGroupOutOfRange;
	}
	return Request;
}








