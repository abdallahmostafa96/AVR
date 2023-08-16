/*
 * Switch_program.c
 *
 *  Created on: 27 Feb 2023
 *      Author: abdallah
 */
#include "Switch_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Switch_Configuration.h"
SwitchErrState  SW_ErrStateSetState(Switch_Info * Switch)
{
	DIO_ErrStateSetPinDirection(Switch->SW_Group,Switch->SW_Pin,DIO_Input);
	if(Switch->ConnectionType == InternalPullUp)
	{
		DIO_ErrStateSetPinValue(Switch->SW_Group,Switch->SW_Pin,DIO_High);
		return NOSWITCHERRPR;
	}
	return ERRORSWITCH;
}
SwitchErrState SW_SwitchErrStateGetState(Switch_Info * Switch ,RS_info * Result)
{
	u8 SwitchRead;
	DIO_ErrStateReadPinValue(Switch->SW_Group,Switch->SW_Pin,&SwitchRead);
	if(SwitchRead == PressedPullUp)
	{
		DIO_ErrStateSetPinValue(Result->RS_Group,Result->RS_Pin,DIO_High);
		return NOSWITCHERRPR;
	}
	else if(SwitchRead == NotPressedPullUp)
	{
		DIO_ErrStateSetPinValue(Result->RS_Group,Result->RS_Pin,DIO_Low);
		return NOSWITCHERRPR;
	}
}
