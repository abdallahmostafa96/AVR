/*
 * SPI.c
 *
 *  Created on: 10 Mar 2023
 *      Author: abdallah
 */
#include "SPI.h"
//#include "LCD"
void SPI_init_master(void)
{
	SETBIT(DDRB,MOSI);
	//SETBIT(DDRB,SS);
	SETBIT(DDRB,SCK);

	SPCR = 1<<MSTR | 1<<SPE;

	CLRBIT(SPCR,SPR0);//presceler 64
	SETBIT(SPCR,SPR1);


	CLRBIT(SPDR,CPHA);
	CLRBIT(SPDR,CPOL);

	SETBIT(SPCR,CPHA); /*Clock Phase*/
	SETBIT(SPCR,CPOL); /*Clock Polarity*/
}

void SPI_master_output(u8 data)
{
	SPDR = data;
	while(READBIT(SPSR,SPIF) == 0);
}


int main(void)
{
	u8 data;
	SPI_init_master();
	SPI_master_output('A');
	_delay_ms(2000);
}

