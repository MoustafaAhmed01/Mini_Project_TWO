/*
 * Macros_def.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Moustafa Ahmed
 */

#ifndef MACROS_DEF_H_
#define MACROS_DEF_H_

/*-------------------------Type Define Section------------------------*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

/*-------------------------Define Section-----------------------------*/

#define SET_BIT(REG,BIT_NUM) (REG=REG|(1<<BIT_NUM))   	 /* Add ONE to this bit */
#define CLEAR_BIT(REG,BIT_NUM) (REG=REG&(~(1<<BIT_NUM))) /* Add ZERO to this bit */
#define OUTPUT(REG,BIT_NUM) (REG=REG|(1<<BIT_NUM))		 /* Add ONE to this bit */
#define INPUT(REG,BIT_NUM) (REG=REG&(~(1<<BIT_NUM)))	 /* Add ZERO to this bit */
#define PIN_7 7
#define Reset_Button PD2
#define Pause_Button PD3
#define Resume_Button PB2
#define En_Segm_ONE PA5
#define En_Segm_TWO PA4
#define En_Segm_THREE PA3
#define En_Segm_FOUR PA2
#define En_Segm_FIVE PA1
#define En_Segm_SIX PA0


/*-----------------------------END-----------------------------------*/
#endif /* MACROS_DEF_H_ */
