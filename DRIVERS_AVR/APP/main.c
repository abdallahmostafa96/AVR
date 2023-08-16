#include "../SERVES/std_macros.h"
#include "../HAL/LCD/Lcd_Interface.h"
static u8 sec=0;
static u8 min=0;
static u8 h=0;
static u8 x=0;
static u16 counter;
Lcd_Info Lcd1={DIO_GroupA,DIO_GroupA,DIO_GroupA,Pin2,Pin1,Pin0,DIO_GroupC};
int main(void)
{

	Set_Bit(TCCR0,CS00); // NO PRESCALER
	Set_Bit(TCCR0,FOC0);

	Set_Bit(TIMSK,TOIE0); // enable timer ov interrupt
	Set_Bit(SREG, 7); // enable global interrupt

	Lcd_VoidInit(&Lcd1);
	Lcd_VoidGoXY(&Lcd1,0,1);
	Lcd_VoidSendString("welcome",&Lcd1);

//sei();
	while(1)
	{

	}

}

ISR(TIMER0_OVF_vect)
{

		if(sec<59)
		{
			sec++;
			if(sec<10){
				Lcd_VoidGoXY(&Lcd1,0,6);
				Lcd_VoidGoXY(&Lcd1,0,7);
				LCD_voidSendNumber(&Lcd1,x);
			}
			else if(sec>10 && sec<60)
			{
				Lcd_VoidGoXY(&Lcd1,0,6);
				LCD_voidSendNumber(&Lcd1,x);
			}
		}
		else if(min<59 && sec==59)
		{
			sec=0;
			Lcd_VoidGoXY(&Lcd1,0,6);
			Lcd_VoidGoXY(&Lcd1,0,7);
			LCD_voidSendNumber(&Lcd1,sec);
			min++;
			if(min<10){
				Lcd_VoidGoXY(&Lcd1,0,6);
				Lcd_VoidGoXY(&Lcd1,0,7);
				LCD_voidSendNumber(&Lcd1,x);
			}
			else if(min>10 && min<60)
			{
				Lcd_VoidGoXY(&Lcd1,0,6);
				LCD_voidSendNumber(&Lcd1,x);
			}

		}
		else if(h<23 && min==59 && sec ==59)
		{
			min=0;
			sec=0;
			h++;
		}
		else if(h==23 && min==59 &&sec==59)
		{
			h=0;
			min=0;
			sec=0;
		}
		counter=0;

	}

