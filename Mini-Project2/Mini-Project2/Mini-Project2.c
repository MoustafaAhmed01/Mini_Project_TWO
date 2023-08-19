/*
 * Main
 *
 * Mini-Project2.c
 *
 *  Created on: Sep 15, 2022
 *      Author: Moustafa Ahmed
 */

/*-------------------------Libraries Section------------------------*/
#include "Libraries.h"
#include "Macros_def.h"
#include "Interrupts_Init.h"
#include "Seven_Seg.h"
/*-------------------------Define Section--------------------------*/

#define F_CPU 1000000UL

/*-------------------------Defining Functions---------------------------*/

/* Intializing Function */
void Call_ALL_Initializers(void)
{
	SREG|=(1<<PIN7); 	 	// Enabling Global Interrupt
	Timer_ONE_Init();	    // Initializing Timer 1
	INT_ZERO_Init(); 		// Activating INT 0
	INT_ONE_Init();	   	    // Activating INT 1
	INT_TWO_Init(); 		// Activating INT 2
	Seven_Segm_Init();	    // Intializing OUTPUT PINS for 7 Segm
	Reset_Button_Init(); 	// Activating Reset Button
	Pause_Button_Init();	// Activating Pause Button
	Resume_Button_Init();	// Acitvating Resume Button

	/* Intializing Struct Variables to Zero */
	Struct_Display_Init();
}

/* Update Seven Segment Screen */
void Display_Seven_Segm()
{
	PORTA = (1<<En_Segm_ONE);   /* Enabling the First Segment only to change it's value */
	PORTC = Display.Second_ONE; /* Displaying the new value */

	_delay_ms(2);				/* Delay between each Segment as they are connected to the same Decoder */

	PORTA = (1<<En_Segm_TWO);	/* Enabling the Second Segment only to change it's value */
	PORTC = Display.Second_TWO;	/* Displaying the new value */

	_delay_ms(2);				/* Delay between each Segment as they are connected to the same Decoder */

	PORTA = (1<<En_Segm_THREE);	/* Enabling the Third Segment only to change it's value */
	PORTC = Display.Minute_ONE;	/* Displaying the new value */

	_delay_ms(2);				/* Delay between each Segment as they are connected to the same Decoder */

	PORTA = (1<<En_Segm_FOUR);	/* Enabling the Fourth Segment only to change it's value */
	PORTC = Display.Minute_TWO;	/* Displaying the new value */

	_delay_ms(2);				/* Delay between each Segment as they are connected to the same Decoder */

	PORTA = (1<<En_Segm_FIVE);	/* Enabling the Fifth Segment only to change it's value */
	PORTC = Display.Hour_ONE;	/* Displaying the new value */

	_delay_ms(2);				/* Delay between each Segment as they are connected to the same Decoder */

	PORTA = (1<<En_Segm_SIX);	/* Enabling the Sixth Segment only to change it's value */
	PORTC = Display.Hour_TWO;	/* Displaying the new value */

	_delay_ms(2);				/* Delay between each Segment as they are connected to the same Decoder */

}

/*-------------------------ISR Section--------------------------*/

/* Timer ONE Interrupt ( Will be called every 1 second ) */
ISR(TIMER1_COMPA_vect)
{
	/** The main thing that will change everything is Seconds, So, we have to check it at first **/
	if(Display.Second_ONE == 9 && Display.Second_TWO == 5) /* If the first and Second digits were at max no. 59 */
	{
		/*  Then we will Inc the next but let's make sure the next not at it's max digits */
		if(Display.Minute_ONE == 9) /* If the first Digit in Minute was 9 So, it's as it's max no. */
		{
			/* Then we will inc. the next which is Minute Two but let's make sure it's not at it's max no. */
			if(Display.Minute_TWO == 5) /* If second digit in Minute was 5 then it's at it's max no. */
			{
				/* Then we will inc the next which is the Hours but, let's make sure again */
				if(Display.Hour_ONE == 9)  /* If the FIRST digit in hours was at it's max */
				{
					if(Display.Hour_TWO == 9) /* If the SECOND digit in hours was at it's max */
					{
						/* Reset */
						Struct_Display_Init();
						Timer_ONE_Init();	    /* Initializing Timer 1 */
					}
					else  /* Means Hour_TWO not at it's max != 5 So, Inc. it */
					{
						Display.Hour_TWO++;
						Display.Second_ONE = 0;
						Display.Second_TWO = 0;
						Display.Minute_ONE = 0;
						Display.Minute_TWO = 0;
						Display.Hour_ONE = 0;
					}
				}
				else /* Means Hour_ONE not at it's max != 9 So, Inc. it */
				{
					Display.Hour_ONE++	;
					Display.Second_ONE = 0;
					Display.Second_TWO = 0;
					Display.Minute_ONE = 0;
					Display.Minute_TWO = 0;
				}
			}
			else /* Means Minute_TWO not at it's max != 5 So, Inc. it */
			{
				Display.Second_ONE = 0;
				Display.Second_TWO = 0;
				Display.Minute_ONE = 0;
				Display.Minute_TWO++;
			}
		}
		else /* Means Minute_ONE not at it's max != 9 So, Inc. it */
		{
			Display.Second_ONE = 0;
			Display.Second_TWO = 0;
			Display.Minute_ONE++;
		}
	}
	else if(Display.Second_ONE == 9) /* Means the Second_TWO not at it's max no.!= 5 So, Inc it */
	{
			Display.Second_ONE = 0;
			Display.Second_TWO++;
	}
	else /* Means the Second_ONE not at it's max no.!= 9 So, Inc it */
	{
		Display.Second_ONE++;
	}
}

 /* Interrupt ZERO */
ISR(INT0_vect)
{
	/* Setting back to Zero */
	Struct_Display_Init();
	Timer_ONE_Init();	    /* Initializing Timer 1 */
}

/* Interrupt ONE */
ISR(INT1_vect)
{
	/* Disconnecting the clock of TIMER_ONE
	 *
	 * TCCR1B
	 * 		   ICNC1 | ICES1 | - | WGM13 | WGM12 | CS12* = 0 | CS11* = 0 | CS10* = 0
	 */
	TCCR1B&= ~(1<<CS12);
	TCCR1B&= ~(1<<CS11);
	TCCR1B&= ~(1<<CS10);
}

/* Interrupt TWO */
ISR(INT2_vect)
{
	/* Connecting back F_CPU/1024 the clock of TIMER_ONE
	 *
	 * TCCR1B
	 * 		   ICNC1 | ICES1 | - | WGM13 | WGM12* = 1 | CS12* = 1  | CS11 | CS10* = 1
	 */
	TCCR1B = (1<<WGM12) | (1<<CS12) | (1<<CS10);
}

/*-------------------------Main Section--------------------------*/
int main()
{
	Call_ALL_Initializers(); /* Intializing Everything */

	while(1)
	{
		Display_Seven_Segm(); /* Always ON Display */
	}

}
