/**
 * @author  Sharath N
 * @file    Keypad_Driver.h
 * @brief   Source file for interfacing 4*4 Matrix Keypad with STM32F407 Discovery Kit
**/

#include "Keypad_Driver.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"


/* Coloumn pin configuration, Coloumn is output */
#define KEYPAD_COLUMN_1_HIGH		HAL_GPIO_WritePin(KEYPAD_COLUMN_1_PORT, KEYPAD_COLUMN_1_PIN, GPIO_PIN_SET)
#define KEYPAD_COLUMN_1_LOW			HAL_GPIO_WritePin(KEYPAD_COLUMN_1_PORT, KEYPAD_COLUMN_1_PIN, GPIO_PIN_RESET)
#define KEYPAD_COLUMN_2_HIGH		HAL_GPIO_WritePin(KEYPAD_COLUMN_2_PORT, KEYPAD_COLUMN_2_PIN, GPIO_PIN_SET)
#define KEYPAD_COLUMN_2_LOW			HAL_GPIO_WritePin(KEYPAD_COLUMN_2_PORT, KEYPAD_COLUMN_2_PIN, GPIO_PIN_RESET)
#define KEYPAD_COLUMN_3_HIGH		HAL_GPIO_WritePin(KEYPAD_COLUMN_3_PORT, KEYPAD_COLUMN_3_PIN, GPIO_PIN_SET)
#define KEYPAD_COLUMN_3_LOW			HAL_GPIO_WritePin(KEYPAD_COLUMN_3_PORT, KEYPAD_COLUMN_3_PIN, GPIO_PIN_RESET)
#define KEYPAD_COLUMN_4_HIGH		HAL_GPIO_WritePin(KEYPAD_COLUMN_4_PORT, KEYPAD_COLUMN_4_PIN, GPIO_PIN_SET)
#define KEYPAD_COLUMN_4_LOW			HAL_GPIO_WritePin(KEYPAD_COLUMN_4_PORT, KEYPAD_COLUMN_4_PIN, GPIO_PIN_RESET)

/* Read input pins - Rows */
#define KEYPAD_ROW_1_CHECK			!(HAL_GPIO_ReadPin(KEYPAD_ROW_1_PORT, KEYPAD_ROW_1_PIN))
#define KEYPAD_ROW_2_CHECK			!(HAL_GPIO_ReadPin(KEYPAD_ROW_2_PORT, KEYPAD_ROW_2_PIN))
#define KEYPAD_ROW_3_CHECK			!(HAL_GPIO_ReadPin(KEYPAD_ROW_3_PORT, KEYPAD_ROW_3_PIN))
#define KEYPAD_ROW_4_CHECK			!(HAL_GPIO_ReadPin(KEYPAD_ROW_4_PORT, KEYPAD_ROW_4_PIN))


uint8_t KEYPAD_Button_Values[4][4] = {  {0x01, 0x02, 0x03, 0x0C},
	                                      {0x04, 0x05, 0x06, 0x0D},
	                                      {0x07, 0x08, 0x09, 0x0E},
	                                      {0x0A, 0x00, 0x0B, 0x0F},
                                     };

/* Private, Set Column */
static void KEYPAD_SetColumn(uint8_t column)
{
	/* Set all column high */
	KEYPAD_COLUMN_1_HIGH;
	KEYPAD_COLUMN_2_HIGH;
	KEYPAD_COLUMN_3_HIGH;
	KEYPAD_COLUMN_4_HIGH;

	
	/* Set column low */
	if (column == 1)
		KEYPAD_COLUMN_1_LOW;
	
	if (column == 2)
		KEYPAD_COLUMN_2_LOW;

	if (column == 3)
		KEYPAD_COLUMN_3_LOW;

	if (column == 4)
		KEYPAD_COLUMN_4_LOW;
	
}


/*Private,  Read rows */
static uint8_t KEYPAD_CheckRow(uint8_t column) 
{

	/* Scan row 1 */
	if (KEYPAD_ROW_1_CHECK) 
		return KEYPAD_Button_Values[0][column - 1];	
	
	/* Scan row 2 */
	if (KEYPAD_ROW_2_CHECK) 
		return KEYPAD_Button_Values[1][column - 1];
	
	/* Scan row 3 */
	if (KEYPAD_ROW_3_CHECK) 
		return KEYPAD_Button_Values[2][column - 1];
	
	/* Scan row 4 */
	if (KEYPAD_ROW_4_CHECK) 
		return KEYPAD_Button_Values[3][column - 1];
	
	
	/* Not pressed */
	return KEYPAD_NOT_PRESSED;
}																		 


/* Initialize the keypad */
void KEYPAD_Init(void)
{
	
	/* Columns are output */
	
	/*Enable GPIOD Clock*/
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	/* Column 1 */
	GPIO_InitTypeDef Column1;
	Column1.Pin = KEYPAD_COLUMN_1_PIN;
	Column1.Mode = GPIO_MODE_OUTPUT_PP;
	Column1.Pull = GPIO_PULLUP;
	Column1.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(KEYPAD_COLUMN_1_PORT, &Column1);
	
	/* Column 2 */
	GPIO_InitTypeDef Column2;
	Column1.Pin = KEYPAD_COLUMN_2_PIN;
	Column1.Mode = GPIO_MODE_OUTPUT_PP;
	Column1.Pull = GPIO_PULLUP;
	Column1.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(KEYPAD_COLUMN_2_PORT, &Column2);
	
	/* Column 3 */
	GPIO_InitTypeDef Column3;
	Column1.Pin = KEYPAD_COLUMN_3_PIN;
	Column1.Mode = GPIO_MODE_OUTPUT_PP;
	Column1.Pull = GPIO_PULLUP;
	Column1.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(KEYPAD_COLUMN_3_PORT, &Column3);	

	/* Column 4 */
	GPIO_InitTypeDef Column4;
	Column1.Pin = KEYPAD_COLUMN_4_PIN;
	Column1.Mode = GPIO_MODE_OUTPUT_PP;
	Column1.Pull = GPIO_PULLUP;
	Column1.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(KEYPAD_COLUMN_4_PORT, &Column4);
	
	
  /* Rows are inputs */
	
	/*Enable GPIOC Clock*/
	__HAL_RCC_GPIOC_CLK_ENABLE();
	/* Row 1 */
	GPIO_InitTypeDef Row1;
	Column1.Pin = KEYPAD_ROW_1_PIN;
	Column1.Mode = GPIO_MODE_INPUT;
	Column1.Pull = GPIO_PULLUP;
	Column1.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(KEYPAD_ROW_1_PORT, &Row1);
	
	/* Row 2 */
	GPIO_InitTypeDef Row2;
	Column1.Pin = KEYPAD_ROW_2_PIN;
	Column1.Mode = GPIO_MODE_INPUT;
	Column1.Pull = GPIO_PULLUP;
	Column1.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(KEYPAD_ROW_2_PORT, &Row2);
	
	/* Row 3 */
	GPIO_InitTypeDef Row3;
	Column1.Pin = KEYPAD_ROW_3_PIN;
	Column1.Mode = GPIO_MODE_INPUT;
	Column1.Pull = GPIO_PULLUP;
	Column1.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(KEYPAD_ROW_3_PORT, &Row3);	
	
	/* Row 4 */
	GPIO_InitTypeDef Row4;
	Column1.Pin = KEYPAD_ROW_4_PIN;
	Column1.Mode = GPIO_MODE_INPUT;
	Column1.Pull = GPIO_PULLUP;
	Column1.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(KEYPAD_ROW_4_PORT, &Row4);
 
  /* Set all columns to High */
  KEYPAD_SetColumn(0);
	
}


/* Read the keypad */
uint8_t KEYPAD_Read(void)
{
	uint8_t check;
	
	/* Set Column 1 to LOW */
	//KEYPAD_SetColumn(1);
	/* Check rows */
	check = KEYPAD_CheckRow(1);
	if (check != KEYPAD_NOT_PRESSED) 
		return check;
	
	
	/* Set row 2 to LOW */
	//KEYPAD_SetColumn(2);
	/* Check columns */
	check = KEYPAD_CheckRow(2);
	if (check != KEYPAD_NOT_PRESSED) 
		return check;
	
	
	/* Set row 3 to LOW */
	//KEYPAD_SetColumn(3);
	/* Check columns */
	check = KEYPAD_CheckRow(3);
	if (check != KEYPAD_NOT_PRESSED) 
		return check;
	

	/* Set column 4 to LOW */
	//KEYPAD_SetColumn(4);
	/* Check rows */
	check = KEYPAD_CheckRow(4);
	if (check != KEYPAD_NOT_PRESSED) 
		return check;
	
	/* Not pressed */
	return KEYPAD_NOT_PRESSED;
		
}
	
	

																		 





