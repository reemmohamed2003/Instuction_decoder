/*
 * decoder.c
 *
 * Created: 8/8/2024 1:13:11 AM
 * Author : Al-Arab
 */ 

#include <avr/io.h>
#include "STD_Macros.h"
#define F_CPU  8000000UL
#include <util/delay.h>


int main(void)
{
	// seg1 >>PORTA   seg2>>  PORTB    dip_switch>> PORTC
	 unsigned char segmentcathod[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F},decimal,ones;
	DDRA = 0xFF;
	DDRB = 0xFF;
	//PORTA=0x00; 
	//PORTB=0x00;
	DDRC=0x00;  // sw is input
	PORTC=0xff;  // switch is pull up
	
	while (1) {
		
		unsigned char dip_switch =~PINC;

		
		unsigned char op_code = (dip_switch >> 6); // op_code bit 6,7

		// Extract operand 2 (BIT 4:3)
		//unsigned char operand2 = ((dip_switch >> 3)& 0x03);
		unsigned char operand2 = ((dip_switch >> 3)& 0x07);  //operand2 (BIT 5:4:3)
		unsigned char operand1 = (dip_switch & 0x07);  // operand1 (BIT 2:1:0)
		unsigned char result = 0;
		if (op_code == 0x00)
		   {
			result = operand1 + operand2;
			}
			else if (op_code == 0x01) 
			{
			result = operand1 - operand2;
			} 
			else if (op_code == 0x02) 
			{
			result = operand1 * operand2;
			} 
			else if (op_code == 0x03)
			 {
			if (operand2 != 0) {
				result = operand1 / operand2;
				} else {
				result = 0; 
			}
		}
		decimal = result/ 10;
		ones = result % 10;
		PORTA =segmentcathod[decimal]; 
		PORTB =segmentcathod[ones]; 
		_delay_ms(250);
	}
}
	
	
	/*unsigned char switch_state=0b00;
    unsigned char segmentcathod[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
		 DDRA = 0xFF;  // Segment 1 (Tens)
		 DDRB = 0xFF;  // Segment 2 (Units)
		 PORTA=0x00;
		 PORTB=0x00;
		 DDRC=0x00;
		 PORTC=0xff;
		 switch_state=~PINC;
	unsigned char op_code=(switch_state>>6);	 
	unsigned char operand1 = (switch_state >> 3) & 0x07; 
	unsigned char operand2 = (switch_state <<5); 
	unsigned char result=0;
	
	switch(op_code) {
		case 0b00: 
		result = operand1 + operand2;
		break;
		case 0b01: 
		result = operand1 - operand2;
		break;
		case 0b10: 
		result = operand1 * operand2;
		break;
		case 0b11: 
		if (operand2 != 0) {
			result = operand1 / operand2;
			} else {
			result = 0; 
		}
		break;
	}

	
	unsigned char decimal= result / 10;
	unsigned char ones = result % 10;

	
    while (1) 
    {
		 PORTA = segmentcathod[decimal];
		 
		 PORTB = segmentcathod[ones];

		 _delay_ms(250); 
		
    }*/


