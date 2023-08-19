/*
 * Interrupt_Init.c
 *
 *  Created on: Sep 15, 2022
 *      Author: Moustafa Ahmed
 */
/*-------------------------Including Libraries---------------------------*/
#include "Interrupts_Init.h"
#include "Libraries.h"
/*-------------------------Defining each Function------------------------*/

/* Initializing Timer_1 */
void Timer_ONE_Init(void)
{
	TCNT1 = 0; 				/* Starts counting from zero 							*/
	OCR1A = 977; 			/* Calling ISR every 1 second ( Every compare) 			*/
	TIMSK|= (1<<OCIE1A); 	/* Enabling compare A interrupt 						*/
	TCCR1A = (1<<FOC1A);	/* Force OUTPUT comapare to channel A 					*/
	TCCR1B = (1<<WGM12) | (1<<CS12) | (1<<CS10); /* Setting on CTC mode - FCPU/1024 */
}

/* Initializing INT_ZERO */
void INT_ZERO_Init(void)
{
	MCUCR|=(1<<ISC01);	/* Generates request with Falling Edge */
	GICR|=(1<<INT0);	/* Enable external interrupt pin INT0  */
}

/* Initializing INT_ONE */
void INT_ONE_Init(void)
{
	GIFR&= ~(1<<INTF1); 			/* Setting INT ONE flag reg to ZERO    */
	MCUCR|= (1<<ISC11) | (1<<ISC10);/* Generates request with Raising Edge */
	GICR|=(1<<INT1);				/* Enable external interrupt pin INT1  */
}

/* Initializing INT_TWO */
void INT_TWO_Init(void)
{
	MCUCSR&= ~(1<<ISC2);	/* Generates request with Falling Edge */
	GICR|= (1<<INT2);		/* Enable external interrupt pin INT2 */
}

/*-----------------------------------END--------------------------------------*/
