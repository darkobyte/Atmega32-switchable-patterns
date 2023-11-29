#define F_CPU 80000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    uint8_t pattern[3][20] = {
	    {0b00000010, 0b00000101, 0b00001010, 0b00010100, 0b00101000, 0b01010000, 0b10100000, 0b01000000, 0b10000000, 0b01000000, 0b10100000, 0b01010000, 0b00101000, 0b01010100, 0b00001010, 0b00000101, 0b00000010, 0b00000001},
	    {0b10000001, 0b11000011, 0b01100110, 0b00111100, 0b00011000, 0b00100100, 0b01000010, 0b10000001, 0b01000010, 0b00100100, 0b00011000, 0b00011000, 0b00111100, 0b01111110, 0b11111111, 0b01111110, 0b00111100, 0b00011000, 0b00000000},
	    {0b10000001, 0b11000011, 0b01100110, 0b00111100, 0b00011000, 0b00100100, 0b01000010, 0b10000001, 0b01000010, 0b00100100, 0b00011000, 0b00011000, 0b00111100, 0b01111110, 0b11111111, 0b01111110, 0b00111100, 0b00011000, 0b00000000}
	    
    };
	
	int patternline = 0;
	int i = 0;
	int num_pattern = sizeof(muster) / sizeof(muster[0]);
	int array_size = sizeof(muster[0]) / sizeof(muster[0][0]);
	int speed = 10;	
	
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRA &= ~((1 << PA0) | (1 << PA1) | (1 << PA2));

	
    while (1) 
    {
		
		PORTB = pattern[patternline][i];
		for (int g = 0; g <= patternline; g++)
		{
			_delay_ms(5);
		}

		
		i = i + 1;
		if (i >= array_size) {
			i = 0;
		}
		
		
		if (PINA & (1 << PA0))
		{
			patternline = (patternline + 1) % num_pattern;
			_delay_ms(30);
		}
		
		if (PINA&(1<<PA1)){
			speed  += 2;
			_delay_ms(30);
		}
		if (PINA&(1<<PA2)){
			speed -= 2;
			_delay_ms(30);
			
		}

		
		
		PORTC = num_pattern;
    }
}

