/*
 * Seven_Seg.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Moustafa Ahmed
 */

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_
/*-------------------------LIBRARIES------------------------*/
#include "Macros_def.h"
/*-------------------------STRUCTURES------------------------*/

/* Numbers will be saved right here */
struct DISPLAY_STRUCT
{
	uint8 Second_ONE,Second_TWO,Minute_ONE,Minute_TWO,Hour_ONE,Hour_TWO;
}Display;


/*-------------------------Declaring Functions------------------------*/

void Seven_Segm_Init(void);
void Reset_Button_Init(void);
void Pause_Button_Init(void);
void Resume_Button_Init(void);
void Struct_Display_Init(void);


#endif /* SEVEN_SEG_H_ */

/*-------------------------END------------------------*/
