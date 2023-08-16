/*
 * ADC.c
 *
 *  Created on: 1 Mar 2023
 *      Author: abdallah
 */
#include "ADC.h"

void ADC_init(void){
	//SETBIT(ADMUX,REFS0); // AVCC will be the ref.
	SETBIT(ADCSRA,ADEN); // enable ADC
	SETBIT(ADCSRA,ADPS0);
	SETBIT(ADCSRA,ADPS1);
	SETBIT(ADCSRA,ADPS2);
}

u16 ADC_read(void){
	SETBIT(ADCSRA,ADSC); // start single conversion
	while(READBIT(ADCSRA,ADSC) == 1); // conversion not completed
	return ADC;
}