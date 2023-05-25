

#ifndef BIT_MATH
#define BIT_MATH

	#define SET_BIT(BYTE,BIT_NO) (BYTE |= (0x01 << (BIT_NO) ))
	#define CLEAR_BIT(BYTE,BIT_NO) (BYTE=BYTE&(~(1<<BIT_NO)))
	#define TOGLLE_BIT(BYTE,BIT_NO) (BYTE ^= (0x01 << (BIT_NO) ))
	#define READ_BIT(BYTE,BIT_NO) (( BYTE >> (BIT_NO)) & 0x01)
	//#define Read_BIT(BYTE,BIT_NO) (BYTE & (1 << BIT_NO) != 0)
	//#define Read_BIT(BYTE,BIT_NO) !!(BYTE & (1 << BIT_NO))
    #define WRITE_BIT(BYTE,BIT_NO,value)  (BYTE = BYTE & (~(1<<BIT_NO)|(value<<BIT_NO)))


#endif
