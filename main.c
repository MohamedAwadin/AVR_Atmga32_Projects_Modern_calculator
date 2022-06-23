
#define  F_CPU    8000000UL
#include <util/delay.h>


#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "KeyPad.h"
#include "Stepeer_Interface.h"



int main(void)
{
	DIO_Init();
	LCD_Init();
	u32 num =0 ;
	u8 x,op;
	u32 op1=0,op2=0,op3=0,op4=0;
	LCD_GoTo(1,0);
	LCD_WriteString("Ans=");
	LCD_GoTo(0,0);
	while(1)
	{
		x = KEYPAD_GetEntry();
		if (x!=DEFULT_KEY)
		{
			if ((x>='0')&&(x<='9'))
			{
				num = (num*10)+(x-'0');
				LCD_WriteChar(x);
			}
			else if ((x=='+')||(x=='-')||(x=='*')||(x=='/')||(x=='='))
			{
				op = x;
				switch(op){
					case '=':
					if ((op1 == 0)&&(op2 == 0)&&(op3 == 0)&&(op4 == 0))
					{
						LCD_GoTo(1,6);
						LCD_WriteString("     ");
						LCD_GoTo(1,6);
						LCD_WriteNumber(num);
					}
					else if (op1 != 0)
					{
						num = op1 + num;
						LCD_GoTo(1,6);
						LCD_WriteString("     ");
						LCD_GoTo(1,6);
						LCD_WriteNumber(num);
						op1 = 0;
					}
					else if (op2 != 0)
					{
						num = op2 - num;
						LCD_GoTo(1,6);
						LCD_WriteString("     ");
						LCD_GoTo(1,6);
						LCD_WriteNumber(num);
						op2=0;
					}
					else if (op3 != 0)
					{
						num = op3 * num;
						LCD_GoTo(1,6);
						LCD_WriteString("     ");
						LCD_GoTo(1,6);
						LCD_WriteNumber(num);
						op3=0;
					}
					else if (op4 != 0)
					{
						num = op4 / num;
						LCD_GoTo(1,6);
						LCD_WriteNumber(num);
						op4=0;
					}
					
					break;
					case '+' :
					
					op1 =num ;
					LCD_GoTo(0,0);
					LCD_WriteString("              ");
					LCD_GoTo(0,0);
					LCD_WriteNumber(op1);
					LCD_WriteChar('+');
					
					num =0 ;
					break;
					case '-' :
					op2 =num ;
					LCD_GoTo(0,0);
					LCD_WriteString("              ");
					LCD_GoTo(0,0);
					LCD_WriteNumber(op2);
					LCD_WriteChar('-');
					
					num =0 ;
					break;
					case '*' :
					op3 =num ;
					LCD_GoTo(0,0);
					LCD_WriteString("              ");
					LCD_GoTo(0,0);
					LCD_WriteNumber(op3);
					LCD_WriteChar('*');
					
					num =0 ;
					break;
					case '/' :
					op4 =num ;
					LCD_GoTo(0,0);
					LCD_WriteString("              ");
					LCD_GoTo(0,0);
					LCD_WriteNumber(op4);
					LCD_WriteChar('/');
					
					num =0 ;
					break;
					
				}
			}
		}
	}
}