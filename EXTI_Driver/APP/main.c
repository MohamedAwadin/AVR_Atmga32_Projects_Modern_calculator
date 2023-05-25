


#include "../Servicse/std_Types.h"
#include "../Servicse/BIT_Math.h"



//#include "../HAL/01-CLCD/CLCD_Interface.h"



#include "../MCAL/01-DIO/DIO_Interface.h"
#include "../MCAL/02-GIE/GIE_Interface.h"
#include "../MCAL/03-EXTI/EXTI_Interface.h"


#include "util/delay.h"




void CHANGE_LEDs_PATTERN_ISR(void);

u8 arr3[]={0b10000001,0b11000011,0b11100111,0b11111111};
#define MID_PORT      DIO_u8_PORTA
volatile int flag =0 ;
int main(void){

	DIO_voidSetPortDirection(DIO_u8_PORTA,DIO_u8_PORT_OUTPUT);
	DIO_voidSetPinDiraection(DIO_u8_PIN_D2,DIO_u8_INPUT);

	DIO_voidActivePullUp(DIO_u8_PIN_D2);


    EXTI_voidInit();
	EXTI_voidCallBack(CHANGE_LEDs_PATTERN_ISR , EXTI_u8_LINE0);



	GIE_voidEnable();
    EXTI_voidEnable(EXTI_u8_LINE0 , EXTI_u8_ON_CHANGE);



	while(1){

		}

}

void CHANGE_LEDs_PATTERN_ISR(void){

}

