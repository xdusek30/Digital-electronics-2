/***********************************************************************
 * 
 * Alternately toggle two LEDs when a push button is pressed.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-2020 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#define LED_RED0     PC0
#define LED_RED1     PC1
#define LED_RED2     PC2
#define LED_RED3     PC3
#define LED_RED4     PC4
#define BTN			 PD0
#define BLINK_DELAY  250
#ifndef F_CPU
#define F_CPU 16000000      // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions

/* Functions ---------------------------------------------------------*/
/**
 * Main function where the program execution begins. Toggle two LEDs 
 * when a push button is pressed.
 */
int main(void)
{
	
	//initialization new variables
	int Start_number;


    /* first LED */
    DDRC = DDRC | (1<<LED_RED0);
	PORTC = PORTC & ~(1<<LED_RED0);
	
	/* second LED */
	DDRC = DDRC | (1<<LED_RED1);
	PORTC = PORTC & ~(1<<LED_RED1);
	
	/* third LED */
	DDRC = DDRC | (1<<LED_RED2);
	PORTC = PORTC & ~(1<<LED_RED2);
		
	/* fourth LED */
	DDRC = DDRC | (1<<LED_RED3);
	PORTC = PORTC & ~(1<<LED_RED3);
	
	/* fifth LED */    
	DDRC = DDRC | (1<<LED_RED4);
	PORTC = PORTC & ~(1<<LED_RED4);
	
	/*Button*/
	DDRD=DDRD & ~ (1<<BTN);
	PORTD = PORTD | (1<<BTN);
	
	// Infinite loop
	while(1){

		if (bit_is_clear(PIND,BTN)) // HOLD the button and cycle will start.  
		{
			for (Start_number = 0; Start_number <=5; Start_number= Start_number + 1)
			{
				if (Start_number==0)
				{
					PORTC = PORTC ^ (1<<LED_RED0); // turn on LED0
					_delay_ms(BLINK_DELAY);

				}
				else if (Start_number==1)
				{				
					PORTC = PORTC ^ (1<<LED_RED1); //turn on LED1
					PORTC = PORTC ^ (1<<LED_RED0); // turn off LED0
					_delay_ms(BLINK_DELAY);	
				}
				else if (Start_number==2)
				{
					PORTC = PORTC ^ (1<<LED_RED2); // turn on LED2
					PORTC = PORTC ^ (1<<LED_RED1);	// turn off LED1				
					_delay_ms(BLINK_DELAY);						
				}
				else if (Start_number==3)
				{
					PORTC = PORTC ^ (1<<LED_RED3); // turn on LED3
					PORTC = PORTC ^ (1<<LED_RED2); // turn off LED2
					_delay_ms(BLINK_DELAY);						
				}
				else if (Start_number==4)
				{
					PORTC = PORTC ^ (1<<LED_RED4); // turn on LED4
					PORTC = PORTC ^ (1<<LED_RED3); // turn off LED3
					_delay_ms(BLINK_DELAY);						
				}
				else if (Start_number == 5)
				{
				
					PORTC = PORTC ^ (1<<LED_RED4); // turn off LED4
					_delay_ms(BLINK_DELAY);
					PORTC = PORTC ^ (1<<LED_RED3); // turn on LED3
					_delay_ms(BLINK_DELAY);
					PORTC = PORTC ^ (1<<LED_RED2); // turn on LED2
					PORTC = PORTC ^ (1<<LED_RED3); // turn off LED3
					_delay_ms(BLINK_DELAY);
					PORTC = PORTC ^ (1<<LED_RED2); //turn off LED2
					PORTC = PORTC ^ (1<<LED_RED1); //turn on LED1
					_delay_ms(BLINK_DELAY);
					PORTC = PORTC ^ (1<<LED_RED1); //turn off LED1

				}	
																				
			}

		}

	}

    return 0;
}
