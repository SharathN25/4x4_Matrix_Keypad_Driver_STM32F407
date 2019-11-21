/**
 * @author  Sharath N
 * @file    STM32F407_KeypadDriver.h
 * @brief   Header file for interfacing 4*4 Matrix Keypad with STM32F407 Discovery Kit
**/ 


#ifndef STM32F407_KEYPADDRIVER_H
#define STM32F407_KEYPADDRIVER_H

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

/*------------------------Define your GPIO pins here----------------------------*/
/** 
  Keypad	STM32F4xx	 Description

     C1			PD0				Column 1
     C2			PD1				Column 2
     C3			PD2				Column 3
     C4			PD3				Column 4
     R1			PC1				Row 1
     R2			PC2				Row 2
     R3			PC3				Row 3
     R4			PC4				Row 4
**/	

/* Rows */
/* Row 1 default */
#define KEYPAD_ROW_1_PORT			  GPIOC
#define KEYPAD_ROW_1_PIN			  GPIO_PIN_1

/* Row 2 default */
#define KEYPAD_ROW_2_PORT			  GPIOC
#define KEYPAD_ROW_2_PIN			  GPIO_PIN_2

/* Row 3 default */
#define KEYPAD_ROW_3_PORT			  GPIOC
#define KEYPAD_ROW_3_PIN			  GPIO_PIN_3

/* Row 4 default */
#define KEYPAD_ROW_4_PORT			  GPIOC
#define KEYPAD_ROW_4_PIN			  GPIO_PIN_4


/* Columns */
/* Column 1 default */
#define KEYPAD_COLUMN_1_PORT		GPIOD
#define KEYPAD_COLUMN_1_PIN			GPIO_PIN_0

/* Column 2 default */
#define KEYPAD_COLUMN_2_PORT		GPIOD
#define KEYPAD_COLUMN_2_PIN			GPIO_PIN_1

/* Column 3 default */
#define KEYPAD_COLUMN_3_PORT		GPIOD
#define KEYPAD_COLUMN_3_PIN			GPIO_PIN_2

/* Column 4 default */
#define KEYPAD_COLUMN_4_PORT		GPIOD
#define KEYPAD_COLUMN_4_PIN			GPIO_PIN_3

/* Keypad NOT pressed */
#define NULL_CHARACTER              '\0'
#define KEYPAD_NOT_PRESSED			NULL_CHARACTER 

/**
 * @brief  Initializes keypad functionality
 * @param  none
 * @retval None
 */
void KEYPAD_Init(void);

/**
 * @brief  Reads keypad data
 * @param  None
 * @retval Button status. This parameter will be a value of KEYPAD_Button_t enumeration
 */
char KEYPAD_Read(void);

#endif


