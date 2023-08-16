/*
 * KEYPAD_config.h
 *
 *  Created on: 4 Mar 2023
 *      Author: abdallah
 */
#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_PORT	DIO_GroupB

#define KEYPAD_COLUMN0_PIN		Pin0
#define KEYPAD_COLUMN1_PIN		Pin1
#define KEYPAD_COLUMN2_PIN		Pin2
#define KEYPAD_COLUMN3_PIN		Pin3

#define KEYPAD_ROW0_PIN			Pin4
#define KEYPAD_ROW1_PIN			Pin5
#define KEYPAD_ROW2_PIN			Pin6
#define KEYPAD_ROW3_PIN			Pin7

#define KEYPAD_DEFAULT_KEY		0xFF

#define KEYPAD_ARR_VAL	{{'1', '2', '3', ' '}\
					,{'4', '5', '6', ' '}\
					,{'7', '8', '9', 'E'}\
					,{'L', '0', 'R', 'S'}}
//#define KEYPAD_ARR_VAL			{{'1','2','3','+'},{'4','5','6','-'},{'7','8','9','*'},{'0','/','%','.'}}
#endif /* KEYPAD_CONFIG_H_ */
