/*
 * SevSeg_program.c
 *
 *  Created on: 28 Feb 2023
 *      Author: abdallah
 */
#include "../../SERVES/std_macros.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SevSeg_Interface.h"
#include"SevSeg_Private.h"



SevErrState    SevSeg_SevErrStateSetNumber(u8 Copy_Number , SevSeg_info * SevenSegment1)
{
	DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_EnablePort,0xff);
	DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_Low);
	if(SevenSegment1->SevSeg_Type == Cathod)
	{
		DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group,SevSeg_Arr[Copy_Number]);
		return NOERROR;
	}
	else if(SevenSegment1->SevSeg_Type == Anode)
	{
		DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_EnablePort,0xff);
		DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_Low);
		DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group,SevSeg_Arr[Copy_Number]);
		return NOERROR;
	}
	return ERROR;
}

SevErrState    SevSeg_SevErrStateDisplayRange(SevSeg_info * SevenSegment1 , u8 Copy_start , u8 Copy_End )
{
	while(Copy_start<=Copy_End)
	{
		DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_EnablePort,0xff);
		DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_Low);
		DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group,SevSeg_Arr[Copy_start++]);
		_delay_ms(1000);
	}
	return NOERROR;

}

SevErrState    SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1)
{
	DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_EnablePort,0xff);
	DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_Low);
	u8 count;
	for(count = 0 ;count<10;count++)
	{
		DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group,SevSeg_Arr[count]);
		_delay_ms(1000);
	}
	return NOERROR;
}
