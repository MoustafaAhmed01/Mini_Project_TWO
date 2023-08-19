/*
 * Seven_Seg.c
 *
 *  Created on: Sep 15, 2022
 *      Author: Moustafa Ahmed
 */

/*-------------------------Including Libraries Section------------------------*/

#include "Seven_Seg.h"
#include "Libraries.h"
#include "Macros_def.h"

/*-------------------------Defining each Function------------------------*/

/* Setting up Seven-Seg */
void Seven_Segm_Init(void)
{
	DDRC|=0x0F;  // Setting PINcS number 0 > 3 as OUTPUT pins
	DDRA|=0x3F;  // Setting PINaS number 0 > 5 as OUTPUT pins
	PORTA&=0xC0; // Disabling all PORTA pin (OUTPUT PINS ONLY) (Screen OFF)
}

/* Setting up Reset Button */
void Reset_Button_Init(void)
{
	INPUT(DDRD,Reset_Button); 	 /*Setting PIND2 as input pin 				  */
	SET_BIT(PORTD,Reset_Button); /*Setting PIND2 as Internal PULL UP resistor */
}

/* Setting up Pause Button */
void Pause_Button_Init(void)
{
	INPUT(DDRD,Pause_Button); 	   /*Setting PIND3 as input pin				 	  */
	CLEAR_BIT(PORTD,Pause_Button); /*Setting PIND3 as External PULL down resistor */
}

/* Setting up Resume Button */
void Resume_Button_Init(void)
{
	INPUT(DDRB,Resume_Button);	  /* Setting PINB2 as input pin 				*/
	SET_BIT(PORTB,Resume_Button); /* Setting PINB2 as Internal PULL UP resistor */
}

/* Intializing Display Struct member varibales*/
void Struct_Display_Init(void)
{
	Display.Second_ONE = 0;
	Display.Second_TWO = 0;
	Display.Minute_ONE = 0;
	Display.Minute_TWO = 0;
	Display.Hour_ONE = 0;
	Display.Hour_TWO = 0;
}

/*-------------------------END------------------------*/
