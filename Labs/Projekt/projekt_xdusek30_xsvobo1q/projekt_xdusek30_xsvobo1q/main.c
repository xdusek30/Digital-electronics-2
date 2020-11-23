/*
 * projekt_xdusek30_xsvobo1q.c
 *
 * Created: 23.11.2020 11:41:41
 * Author : Dušek, Svoboda
 */ 

#ifndef F_CPU
#define F_CPU 16000000
#endif


#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "timer.h"
#include  "serial_controller_for_diodes.h"
#include "lcd.h"
#include "lcd_definitions.h"

uint8_t turn_on_row1;
uint8_t turn_on_row2;

int main(void)
{
	// Initialize LCD display
    lcd_init(LCD_DISP_ON);
    lcd_gotoxy(1, 0);
    lcd_puts("Distance");
    lcd_gotoxy(13, 0);
    lcd_puts("cm");

    DIODE_init();
	
    /* Configure 8-bit Timer/Counter1
     * Set prescaler and enable overflow interrupt */
	TIM0_overflow_4ms();
	TIM0_overflow_interrupt_enable();
    // Enables interrupts by setting the global interrupt mask

    /* Configure 16-bit Timer/Counter1
     * Set prescaler and enable overflow interrupt */
	TIM1_overflow_262ms();
	TIM1_overflow_interrupt_enable();
    // Enables interrupts by setting the global interrupt mask
	sei();
	

	
    /* Replace with your application code */
    while (1) 
    {
    }
	return 0;
}
	
 	ISR(TIMER0_OVF_vect)
 	{
 		static uint8_t row = 0;
	    uint8_t line = 0;
 		if (row == 0)
 		{ 
 			DIODE_update_shift_regs_FRONT(turn_on_row1);
 			row = 0;
			line =1;
 		}
 		if (line == 1)
 		{
 			DIODE_update_shift_regs_REAR(turn_on_row2);
 			line = 1;			
 		}

	}
	
	ISR(TIMER1_OVF_vect)
	{
		turn_on_row1++;
		if (turn_on_row1 > 7)
		{
			turn_on_row1 = 0;
			turn_on_row2++;
			if (turn_on_row2 > 5)
			{
				turn_on_row2 = 0;
			}
		}
	}

