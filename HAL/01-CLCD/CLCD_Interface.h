/*
 * CLCD_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: A4 Center
 */

#ifndef HAL_01_CLCD_CLCD_INTERFACE_H_
#define HAL_01_CLCD_CLCD_INTERFACE_H_

#include "../../Servicse/std_Types.h"
#include "../../Servicse/BIT_Math.h"

void CLCD_voidInit(void);
void CLCD_voidSendData(u8 Copy_u8data);
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendString(s8 * Copy_u8PtrString);

#endif /* HAL_01_CLCD_CLCD_INTERFACE_H_ */
