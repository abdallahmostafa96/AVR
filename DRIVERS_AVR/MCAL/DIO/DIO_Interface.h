/*
 * DIO_Interface.h
 *
 *  Created on: 23 Feb 2023
 *      Author: abdallah
 */
#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
#include "../../SERVES/std_macros.h"
#include "DIO_Private.h"


ErrState  DIO_ErrStateSetPinDirection(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,DIO_DirectionState Copy_DirectionState);
ErrState  DIO_ErrStateSetPinValue(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,DIO_ValueState Copy_ValueState);
ErrState  DIO_ErrStateReadPinValue(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,u8 *Result);


ErrState  DIO_ErrStateSetGroupDirection(DIO_GroupNumber Copy_GroupNumber ,DIO_DirectionState Copy_DirectionState);
ErrState  DIO_ErrStateSetGroupValue(DIO_GroupNumber Copy_GroupNumber ,DIO_ValueState Copy_ValueState);
ErrState  DIO_ErrStateReadGroupValue(DIO_GroupNumber Copy_GroupNumber ,u8 *Result);

u8  DIO_ErrStateReadPinValuekey(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber );





#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
