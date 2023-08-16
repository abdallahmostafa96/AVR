/*
 * Led_Program.c
 *
 *  Created on: 25 Feb 2023
 *      Author: abdallah
 */
 #include "../../SERVES/std_macros.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Led_Interface.h"

LedErrState	Led_LedErrStateTurnOn(Led_info *Led)
{
	DIO_ErrStateSetPinDirection(Led->Led_Group,Led->Led_Pin,DIO_Output);
	if(Led->ConnectionType==Source_Connection)
	{		DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_High);
			return on;
	}
	else if (Led->ConnectionType==Sink_Connection)
	{	DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_Low);
		return off;
	}

	else{
		return Errorcon;
	}
}
LedErrState	Led_LedErrStateTurnOff(Led_info *Led)
{
	DIO_ErrStateSetPinDirection(Led->Led_Group,Led->Led_Pin,DIO_Output);
		if(Led->ConnectionType==Source_Connection)
		{		DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_High);
				return on;
		}
		else if (Led->ConnectionType==Sink_Connection)
		{	DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_Low);
			return off;
		}

		else{
			return Errorcon;
		}
}
