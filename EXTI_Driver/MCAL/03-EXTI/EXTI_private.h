/*
 * EXTI_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: A4 Center
 */

#ifndef MCAL_03_EXTI_EXTI_PRIVATE_H_
#define MCAL_03_EXTI_EXTI_PRIVATE_H_

#define MCUCR    *((volatile u8 *)0x55)
#define MCUCSR   *((volatile u8 *)0x54)
#define GICR     *((volatile u8 *)0x5B)
#define GIFR     *((volatile u8 *)0x5A)


#define ISC11    3
#define ISC10    2
#define ISC01    1
#define ISC00    0


#define ISC2     6


#define INT1     7
#define INT0     6
#define INT2     5







/*INTERRUPt LINE 0 ISR */
void __vector_1(void) __attribute__ ((signal));
/*INTERRUPt LINE 1 ISR */
void __vector_2(void) __attribute__ ((signal));
/*INTERRUPt LINE 2 ISR */
void __vector_3(void) __attribute__ ((signal));


 void  (*EXTI_CallBack[3])(void) = {NULL};


#endif /* MCAL_03_EXTI_EXTI_PRIVATE_H_ */
