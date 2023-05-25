/*
 * EXTI_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: A4 Center
 */

#include "../../Servicse/BIT_Math.h"
#include "../../Servicse/std_Types.h"

#include "EXTI_Interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


void EXTI_voidInit(){


	/*INTERRUPT LINE 0*/
#ifdef EXTI_LINE_0_ENABLE

	/*INTERRUPT LINE 0 - FALLING EDGE*/
#if  EXTI_LINE_0_CONFIG == 	EXTI_u8_FALLING_EDGE
	SET_BIT(MCUCR,ISC01);
	CLEAR_BIT(MCUCR,ISC00);
#endif

	/*INTERRUPT LINE 0 - RISING EDGE*/
#if  EXTI_LINE_0_CONFIG == 	EXTI_u8_RISING_EDGE
	SET_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC00);
#endif

	/*INTERRUPT LINE 0 - LOW LEVEL EDGE*/
#if  EXTI_LINE_0_CONFIG == 	EXTI_u8_LOW_LEVEL
	CLEAR_BIT(MCUCR,ISC01);
	CLEAR_BIT(MCUCR,ISC00);
#endif

	/*INTERRUPT LINE 0 - ON CHANGE EDGE*/
#if  EXTI_LINE_0_CONFIG == 	EXTI_u8_ON_CHANGE
	CLEAR_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC00);
#endif

	/*SET PIE OF INTERRUPT 0*/
	SET_BIT(GICR,INT0);
#endif




	/*INTERRUPT LINE 1*/
#ifdef EXTI_LINE_1_ENABLE


	/*INTERRUPT LINE 1 - FALLING EDGE*/
#if  EXTI_LINE_1_CONFIG == 	EXTI_u8_FALLING_EDGE
	SET_BIT(MCUCR,ISC11);
	CLEAR_BIT(MCUCR,ISC10);
#endif

	/*INTERRUPT LINE 1 - RISING EDGE*/
#if  EXTI_LINE_1_CONFIG == 	EXTI_u8_RISING_EDGE
	SET_BIT(MCUCR,ISC11);
	SET_BIT(MCUCR,ISC10);
#endif

	/*INTERRUPT LINE 1 - LOW LEVEL EDGE*/
#if  EXTI_LINE_1_CONFIG == 	EXTI_u8_LOW_LEVEL
	CLEAR_BIT(MCUCR,ISC11);
	CLEAR_BIT(MCUCR,ISC10);
#endif

	/*INTERRUPT LINE 1 - ON CHANGE EDGE*/
#if  EXTI_LINE_1_CONFIG == 	EXTI_u8_ON_CHANGE
	CLEAR_BIT(MCUCR,ISC11);
	SET_BIT(MCUCR,ISC10);
#endif
	/*SET PIE OF INTERRUPT 1*/
	SET_BIT(GICR,INT1);
#endif



	/*INTERRUPT LINE 2*/
#ifdef EXTI_LINE_2_ENABLE

	/*INTERRUPT LINE 0 - FALLING EDGE*/
#if  EXTI_LINE_0_CONFIG == 	EXTI_u8_FALLING_EDGE

	CLEAR_BIT(MCUCSR,ISC2);
#endif

	/*INTERRUPT LINE 0 - RISING EDGE*/
#if  EXTI_LINE_0_CONFIG == 	EXTI_u8_RISING_EDGE
	SET_BIT(MCUCSR,ISC2);

#endif

	/*SET PIE OF INTERRUPT 2*/
	SET_BIT(GICR,INT2);
#endif
}
void EXTI_voidEnable(u8 Copy_u8Line , u8 Copy_u8SenseMode){
	switch(Copy_u8Line){

	case EXTI_u8_LINE0:
		SET_BIT(GICR,INT0);
		switch(Copy_u8SenseMode){
		case EXTI_u8_LOW_LEVEL:
			CLEAR_BIT(MCUCR, ISC00);
			CLEAR_BIT(MCUCR, ISC01);
			break;
		case EXTI_u8_RISING_EDGE:
			CLEAR_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
		case EXTI_u8_FALLING_EDGE:
			CLEAR_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
		case EXTI_u8_ON_CHANGE:
			SET_BIT(MCUCR, ISC00);
			CLEAR_BIT(MCUCR, ISC01);
			break;
		}
		break;
		case EXTI_u8_LINE1:
			SET_BIT(GICR,INT1);
			switch(Copy_u8SenseMode){
			case EXTI_u8_LOW_LEVEL:
				CLEAR_BIT(MCUCR, ISC10);
				CLEAR_BIT(MCUCR, ISC11);
				break;
			case EXTI_u8_RISING_EDGE:
				CLEAR_BIT(MCUCR, ISC10);
				SET_BIT(MCUCR, ISC11);
				break;
			case EXTI_u8_FALLING_EDGE:
				CLEAR_BIT(MCUCR, ISC10);
				SET_BIT(MCUCR, ISC11);
				break;
			case EXTI_u8_ON_CHANGE:
				SET_BIT(MCUCR, ISC10);
				CLEAR_BIT(MCUCR, ISC11);
				break;
			}
			break;
			case EXTI_u8_LINE2:
				SET_BIT(GICR,INT1);
				switch(Copy_u8SenseMode){
				case EXTI_u8_RISING_EDGE:
					SET_BIT(MCUCR, ISC2);
					break;
				case EXTI_u8_FALLING_EDGE:
					CLEAR_BIT(MCUCR, ISC2);

					break;

				}
				break;
	}
}
void EXTI_voidDisable(u8 Copy_u8Line ){
	switch (Copy_u8Line) {
	case EXTI_u8_LINE0:
		CLEAR_BIT(GICR, INT0);
		break;
	case EXTI_u8_LINE1:
		CLEAR_BIT(GICR, INT1);
		break;
	case EXTI_u8_LINE2:
		CLEAR_BIT(GICR, INT2);
		break;
	}
}
void EXTI_voidClearflag(u8 Copy_u8Line ){
	switch (Copy_u8Line) {
	case EXTI_u8_LINE0:
		SET_BIT(GIFR, INT0);
		break;
	case EXTI_u8_LINE1:
		SET_BIT(GIFR, INT1);
		break;
	case EXTI_u8_LINE2:
		SET_BIT(GICR, INT2);
		break;
	}
}


void EXTI_voidCallBack(void (*Copy_PvoidCallBack) (void), u8 Copy_u8Line){

	if (Copy_PvoidCallBack != NULL) {
			EXTI_CallBack[Copy_u8Line] = Copy_PvoidCallBack;
		}


}

/*INTERRUPt LINE 0 ISR */
void __vector_1(void){
	if(EXTI_CallBack[EXTI_u8_LINE0] != NULL){
		EXTI_CallBack[EXTI_u8_LINE0]();
	}

}
/*INTERRUPt LINE 1 ISR */
void __vector_2(void){
	if(EXTI_CallBack[EXTI_u8_LINE1] != NULL){
		EXTI_CallBack[EXTI_u8_LINE1]();
	}
}
/*INTERRUPt LINE 2 ISR */
void __vector_3(void){
	if(EXTI_CallBack[EXTI_u8_LINE2] != NULL){
		EXTI_CallBack[EXTI_u8_LINE2]();
	}
}
