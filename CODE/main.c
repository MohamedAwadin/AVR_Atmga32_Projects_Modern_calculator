
#include "DIO_Driver/DIO_interface.h"
#include "std_Types.h"
#include "BIT_Math.h"
#include "util/delay.h"




const u8 segNumbers[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
const u8 segNumbers2[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
#define RED_LED    0
#define YELLOW_LED 1
#define GREEN_LED  2


#define EN1        7
#define EN2        6


#define Seg_port    2

#define MONO_PORT   3
#define TENS_PORT   1
void _2segment_display(u8 n,u8 ENABLE1,u8 ENABLE2,u8 SEGMENT_PORT);
void SIGNAL_2segment_display(u8 n,u8 MONO_SEGMENT_PORT,u8 TENS_SEGMENT_PORT);
int main(void)
{
	DIO_voidSetPinDiraection(RED_LED    , 1);
	DIO_voidSetPinDiraection(YELLOW_LED , 1);
	DIO_voidSetPinDiraection(GREEN_LED  , 1);

	DIO_voidSetPinDiraection(EN1 , 1);
	DIO_voidSetPinDiraection(EN2 , 1);

	DIO_voidSetPortDirection(MONO_PORT,DIO_u8_PORT_OUTPUT );
	DIO_voidSetPortDirection(TENS_PORT,DIO_u8_PORT_OUTPUT );
	DIO_voidSetPortDirection(Seg_port,DIO_u8_PORT_OUTPUT );

	while(1)
	{
		DIO_voidSetPinValue(RED_LED    , 1);
		DIO_voidSetPinValue(YELLOW_LED , 0);
		DIO_voidSetPinValue(GREEN_LED  , 0);
		for(u8 i =0 ; i<=35;i++)
		{

		SIGNAL_2segment_display( i, MONO_PORT, TENS_PORT);
		 _delay_ms(250);
		}
		DIO_voidSetPinValue(RED_LED    , 0);
		DIO_voidSetPinValue(YELLOW_LED , 1);
		DIO_voidSetPinValue(GREEN_LED  , 0);
		for(u8 i =0 ; i<=5;i++)
		{

		SIGNAL_2segment_display( i, MONO_PORT, TENS_PORT);
		 _delay_ms(250);

		}
		DIO_voidSetPinValue(RED_LED    , 0);
		DIO_voidSetPinValue(YELLOW_LED , 0);
		DIO_voidSetPinValue(GREEN_LED  , 1);
		for(u8 i =0 ; i<=30;i++)
		{

		  SIGNAL_2segment_display( i, MONO_PORT, TENS_PORT);
		  _delay_ms(250);


		}
	}
}
void _2segment_display(u8 n,u8 ENABLE1,u8 ENABLE2,u8 SEGMENT_PORT)
{
	u8 temp , unit_num,tens_num;
	temp=n;
	unit_num = segNumbers[temp/10];
	temp=n;
	tens_num = segNumbers[temp%10];
	DIO_voidSetPinValue(ENABLE1,DIO_u8_HIGH); //(port,pin,value)
	DIO_voidSetPinValue(ENABLE2,DIO_u8_LOW);
	DIO_voidSetPortValue(SEGMENT_PORT ,unit_num );
	_delay_ms(5);

    DIO_voidSetPinValue(ENABLE2,DIO_u8_HIGH);
	DIO_voidSetPinValue(ENABLE1,DIO_u8_LOW);
	DIO_voidSetPortValue(SEGMENT_PORT ,tens_num );
	_delay_ms(5);


}
void SIGNAL_2segment_display(u8 n,u8 MONO_SEGMENT_PORT,u8 TENS_SEGMENT_PORT)
{
	u8 temp,UNIT_NUM,TENS_NUM;
	temp=n;
	UNIT_NUM = segNumbers[temp/10];
	temp =n;
	TENS_NUM = segNumbers[temp%10];


	DIO_voidSetPortValue(MONO_SEGMENT_PORT,UNIT_NUM);

	DIO_voidSetPortValue(TENS_SEGMENT_PORT,TENS_NUM);

}
