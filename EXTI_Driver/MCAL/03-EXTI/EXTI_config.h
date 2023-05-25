/*
 * EXTI_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: A4 Center
 */

#ifndef MCAL_03_EXTI_EXTI_CONFIG_H_
#define MCAL_03_EXTI_EXTI_CONFIG_H_

/*
 * OPTIONS
 * OMMENT UN-NEEDED LINES
 *
 */


#define EXTI_LINE_0_ENABLE
//#define EXTI_LINE_1_ENABLE
//#define EXTI_LINE_2_ENABLE

/*
 * OPTIONS -> EXTI_LINE_0_CONFIG
 * EXTI_u8_FALLING_EDGE
 *  EXTI_u8_RISING_EDGE
 *  EXTI_u8_LOW_LEVEL
 *  EXTI_u8_ON_CHANGE
 */

#define EXTI_LINE_0_CONFIG     EXTI_u8_ON_CHANGE
#define EXTI_LINE_1_CONFIG     EXTI_u8_ON_CHANGE
#define EXTI_LINE_2_CONFIG     EXTI_u8_LOW_LEVEL

#endif /* MCAL_03_EXTI_EXTI_CONFIG_H_ */
