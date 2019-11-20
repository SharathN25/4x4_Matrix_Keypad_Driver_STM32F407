/**
 * @author  Sharath N
 * @file    Keypad_Driver.h
 * @brief   Header file for interfacing 4*4 Matrix Keypad with STM32F407 Discovery Kit
**/ 


#ifndef KEYPAD_DRIVER_H
#define KEYPAD_DRIVER_H

#include <stdint.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

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


/* Number of milliseconds between 2 reads */
#define KEYPAD_READ_INTERVAL    100


/* Keypad no pressed */
#define KEYPAD_NOT_PRESSED			  (uint8_t)0xFF

/**
 * @brief  Keypad button enumeration
 */
typedef enum {
	KEYPAD_Button_0 = 0x00,                     /*!< Button 0 code */
	KEYPAD_Button_1 = 0x01,                     /*!< Button 1 code */
	KEYPAD_Button_2 = 0x02,                     /*!< Button 2 code */
	KEYPAD_Button_3 = 0x03,                     /*!< Button 3 code */
	KEYPAD_Button_4 = 0x04,                     /*!< Button 4 code */
	KEYPAD_Button_5 = 0x05,                     /*!< Button 5 code */
	KEYPAD_Button_6 = 0x06,                     /*!< Button 6 code */
	KEYPAD_Button_7 = 0x07,                     /*!< Button 7 code */
	KEYPAD_Button_8 = 0x08,                     /*!< Button 8 code */
	KEYPAD_Button_9 = 0x09,                     /*!< Button 9 code */
	KEYPAD_Button_STAR = 0x0A,                  /*!< Button START code */
	KEYPAD_Button_HASH = 0x0B,                  /*!< Button HASH code */
	KEYPAD_Button_A = 0x0C,	                   /*!< Button A code. Only on large size */
	KEYPAD_Button_B = 0x0D,	                   /*!< Button B code. Only on large size */
	KEYPAD_Button_C = 0x0E,	                   /*!< Button C code. Only on large size */
	KEYPAD_Button_D = 0x0F,	                   /*!< Button D code. Only on large size */
	KEYPAD_Button_NOTPRESSED = KEYPAD_NOT_PRESSED /*!< No button pressed */
} KEYPAD_Button_t;



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
uint8_t KEYPAD_Read(void);

/**
 * @brief  Updates keypad
 * @note   This function must be called from interrupt routine every 1ms
 * @param  None
 * @retval None
 */
void KEYPAD_Update(void);
		 

#endif


