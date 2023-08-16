/*
 * KEYPAD_Program.c
 *
 *  Created on: 4 Mar 2023
 *      Author: abdallah
 */
#include "../../SERVES/std_macros.h"
#include  "../../MCAL/DIO/DIO_Interface.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

void KEYPAD_init(void)
{
	/*Set keypad columns pins as OUTPUT*/
	DIO_ErrStateSetPinDirection(KEYPAD_PORT, KEYPAD_COLUMN0_PIN, DIO_Output);
	DIO_ErrStateSetPinDirection(KEYPAD_PORT, KEYPAD_COLUMN1_PIN, DIO_Output);
	DIO_ErrStateSetPinDirection(KEYPAD_PORT, KEYPAD_COLUMN2_PIN, DIO_Output);
	DIO_ErrStateSetPinDirection(KEYPAD_PORT, KEYPAD_COLUMN3_PIN, DIO_Output);

	/*Set keypad rows pins as INPUT*/
	DIO_ErrStateSetPinDirection(KEYPAD_PORT, KEYPAD_ROW0_PIN, DIO_Input);
	DIO_ErrStateSetPinDirection(KEYPAD_PORT, KEYPAD_ROW1_PIN, DIO_Input);
	DIO_ErrStateSetPinDirection(KEYPAD_PORT, KEYPAD_ROW2_PIN, DIO_Input);
	DIO_ErrStateSetPinDirection(KEYPAD_PORT, KEYPAD_ROW3_PIN, DIO_Input);


	/*Set the keypad port value to HIGH(to enable pull-up in rows pins, and out high signal on columns pins)*/
	DIO_ErrStateSetGroupValue(KEYPAD_PORT, 0xff);
}

u8 KEYPAD_read(void)
{
	u8 Local_u8PressedKey = KEYPAD_DEFAULT_KEY;
	u8 Local_u8ColCounter, Local_u8RowCounter, Local_u8KeyFlag;

	u8 KeypadArray[KEYPAD_ROWS_NUM][KEYPAD_COLS_NUM] = KEYPAD_ARR_VAL;
	u8 ColumnsArr[KEYPAD_COLS_NUM] = {KEYPAD_COLUMN0_PIN, KEYPAD_COLUMN1_PIN, KEYPAD_COLUMN2_PIN, KEYPAD_COLUMN3_PIN};
	u8 RowsArr[KEYPAD_ROWS_NUM]    = {KEYPAD_ROW0_PIN, KEYPAD_ROW1_PIN, KEYPAD_ROW2_PIN, KEYPAD_ROW3_PIN};

	for(Local_u8ColCounter = 0; Local_u8ColCounter < KEYPAD_COLS_NUM; Local_u8ColCounter++)
	{
		/*Activate the current column by setting its value to low*/
		DIO_ErrStateSetPinValue(KEYPAD_PORT, ColumnsArr[Local_u8ColCounter], DIO_Low);

		/*Loop for the rows to get if any key is pressed*/
		for(Local_u8RowCounter = 0; Local_u8RowCounter < KEYPAD_ROWS_NUM; Local_u8RowCounter++)
		{
			Local_u8KeyFlag = DIO_ErrStateReadPinValuekey(KEYPAD_PORT, RowsArr[Local_u8RowCounter]);
			if(DIO_Low == Local_u8KeyFlag)
			{
				Local_u8PressedKey = KeypadArray[Local_u8RowCounter][Local_u8ColCounter];
				/*Polling till switch released*/
				while(DIO_Low == DIO_ErrStateReadPinValuekey(KEYPAD_PORT, RowsArr[Local_u8RowCounter]))
				{
					Local_u8PressedKey = KeypadArray[Local_u8RowCounter][Local_u8ColCounter];
				}
				return Local_u8PressedKey;
			}
			else{
				/*Do Nothing*/
			}
		}
		/*Deactivate the current column*/
		DIO_ErrStateSetPinValue(KEYPAD_PORT, ColumnsArr[Local_u8ColCounter], DIO_High);
	}
	return Local_u8PressedKey;
}

