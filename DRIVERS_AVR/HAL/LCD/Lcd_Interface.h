/*
 * Lcd_Interface.h
 *
 *  Created on: 6 Mar 2023
 *      Author: abdallah
 */
#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#include "LCD_Register.h"
#include "Lcd_Privet.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../SERVES/std_macros.h"
void Lcd_VoidSendChar(u8 Copy_Char, Lcd_Info * Lcd);
void Lcd_VoidSendCommand(u8 Copy_Command, Lcd_Info * Lcd);
void Lcd_VoidInit(Lcd_Info * Lcd);

void Lcd_VoidSendString(u8 *Address_String ,Lcd_Info * Lcd);

void Lcd_VoidGoXY(Lcd_Info * Lcd ,u8 Copy_XLocation ,u8 Copy_YLocation );

void LCD_voidSendNumber(Lcd_Info * Lcd, s32 Copy_u32Num);



#endif /* HAL_LCD_LCD_INTERFACE_H_ */
