
#include "DIO_Driver/DIO_interface.h"
#include "std_Types.h"
#include "BIT_Math.h"
#include "util/delay.h"


#define LEFT_PORT      0
#define MID_PORT       1
#define RIGHT_PORT     2

#define Button_1      DIO_u8_PIN_D0
#define Button_2      DIO_u8_PIN_D1
#define Button_3      DIO_u8_PIN_D2
#define Button_4      DIO_u8_PIN_D3

u8 arr1[]={0b00000000,0b10000000,0b11000000,0b11100000,0b11110000,0b11111000,0b11111100,0b11111110,0b11111111};
u8 arr2[]={0b00000000,0b00000001,0b00000011,0b00000111,0b00001111,0b00011111,0b00111111,0b01111111,0b11111111};
u8 arr3[]={0b10000001,0b11000011,0b11100111,0b11111111};
int main(void)
{
	DIO_voidSetPortDirection(LEFT_PORT,DIO_u8_OUTPUT);
	DIO_voidSetPortDirection(MID_PORT,DIO_u8_OUTPUT);
	DIO_voidSetPortDirection(RIGHT_PORT,DIO_u8_OUTPUT);

	DIO_voidSetPinDiraection(Button_1,DIO_u8_INPUT);
	DIO_voidSetPinDiraection(Button_2,DIO_u8_INPUT);
	DIO_voidSetPinDiraection(Button_3,DIO_u8_INPUT);
	DIO_voidSetPinDiraection(Button_4,DIO_u8_INPUT);

	DIO_voidActivePullUp(Button_1);
	DIO_voidActivePullUp(Button_2);
	DIO_voidActivePullUp(Button_3);
	DIO_voidActivePullUp(Button_4);


	while(1)
	{
		if(DIO_u8ReadPinValue(Button_1)){
			DIO_voidSetPortValue(MID_PORT,DIO_u8_PORT_HIGH);
			DIO_voidSetPortValue(LEFT_PORT,DIO_u8_PORT_HIGH);
			DIO_voidSetPortValue(RIGHT_PORT,DIO_u8_PORT_HIGH);
			_delay_ms(50);
			DIO_voidSetPortValue(MID_PORT,DIO_u8_PORT_LOW);
			DIO_voidSetPortValue(LEFT_PORT,DIO_u8_PORT_LOW);
			DIO_voidSetPortValue(RIGHT_PORT,DIO_u8_PORT_LOW);
			_delay_ms(50);
		}
		if(DIO_u8ReadPinValue(Button_2)){
			for(u8 i = 0 ; i<24 ; i++)
			{
				DIO_voidSetPinValue(i,DIO_u8_HIGH);
				_delay_ms(50);
			}
			DIO_voidSetPortValue(MID_PORT,DIO_u8_PORT_LOW);
			DIO_voidSetPortValue(LEFT_PORT,DIO_u8_PORT_LOW);
			DIO_voidSetPortValue(RIGHT_PORT,DIO_u8_PORT_LOW);

		}
		if(DIO_u8ReadPinValue(Button_3)){
			for(u8 i = 0 ; i<=8 ; i++)
			{
				DIO_voidSetPortValue (LEFT_PORT,arr1[i]);
				_delay_ms(50);
			}
			for(u8 i = 0 ; i<=8 ; i++)
			{
				DIO_voidSetPortValue (LEFT_PORT,arr2[i]);
				_delay_ms(50);
			}
			for(u8 i = 0 ; i<4 ; i++)
			{
				DIO_voidSetPortValue (MID_PORT,arr3[i]);
				_delay_ms(50);
			}
			DIO_voidSetPortValue (MID_PORT,DIO_u8_PORT_LOW);
			DIO_voidSetPortValue (LEFT_PORT,DIO_u8_PORT_LOW);
			DIO_voidSetPortValue (RIGHT_PORT,DIO_u8_PORT_LOW);
		}
		if(DIO_u8ReadPinValue(Button_4)){
			for(u8 i = 4 ; i<0 ; i--)
			{
				DIO_voidSetPortValue (LEFT_PORT,arr1[i]);
				_delay_ms(50);
			}
			for(u8 i = 4 ; i<0 ; i--)
			{
				DIO_voidSetPortValue (LEFT_PORT,arr2[i]);
				_delay_ms(50);
			}
			for(u8 i = 0 ; i<4 ; i++)
			{
				DIO_voidSetPortValue (MID_PORT,arr3[i]);
				_delay_ms(50);
			}
			DIO_voidSetPortValue (MID_PORT,DIO_u8_PORT_LOW);
			DIO_voidSetPortValue (LEFT_PORT,DIO_u8_PORT_LOW);
			DIO_voidSetPortValue (RIGHT_PORT,DIO_u8_PORT_LOW);
		}




	}
}
