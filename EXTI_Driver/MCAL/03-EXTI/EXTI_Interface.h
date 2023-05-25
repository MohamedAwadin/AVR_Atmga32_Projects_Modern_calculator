/*
 * EXTI_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: A4 Center
 */

#ifndef MCAL_03_EXTI_EXTI_INTERFACE_H_
#define MCAL_03_EXTI_EXTI_INTERFACE_H_

#define EXTI_u8_LINE0     0
#define EXTI_u8_LINE1     1
#define EXTI_u8_LINE2     2

#define EXTI_u8_FALLING_EDGE     0
#define EXTI_u8_RISING_EDGE      1
#define EXTI_u8_LOW_LEVEL        2
#define EXTI_u8_ON_CHANGE        3




void EXTI_voidInit();
void EXTI_voidEnable(u8 Copy_u8Line , u8 Copy_u8SenseMode);
void EXTI_voidDisable(u8 Copy_u8Line );
void EXTI_voidClearflag(u8 Copy_u8Line );

void EXTI_voidCallBack(void (*Copy_PvoidCallBack) (void), u8 Copy_u8Line);

#endif /* MCAL_03_EXTI_EXTI_INTERFACE_H_ */
