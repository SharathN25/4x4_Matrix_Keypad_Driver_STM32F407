/**
  ********************************************************************************************
	*@file     main.c
	*@author   Sharath N
	*@brief    An example project to interface 4x4 keypad on STM32F407 Discovery Kit
	           ->Without using STM32CubeMX
	********************************************************************************************
*/

#include "stdio.h"
#include "stdint.h"
#include "STM32F407_KeypadDriver.h"

void Systick_Interrupt_Enable(void);

int main(void)
{

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
	
  /*Enable Systick interrupt for delay*/
	Systick_Interrupt_Enable();
	
	/* Initialize Keypad */
	KEYPAD_Init();
	
	/*Charcter variable to hold the key value*/
	char Key = KEYPAD_NOT_PRESSED;

  while (1)
  {
	 /*Read the Keypad */
	 Key = KEYPAD_Read();
   
   if(Key != KEYPAD_NOT_PRESSED)
   {
    printf("Key pressed = %c \n", Key);
	 }
	 
	 /* Read Keypad Every 100ms */
	 HAL_Delay(100);
 }
	
}



void Systick_Interrupt_Enable(void)
{
	//Systick interrupt enable for HAL_Delay function
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}



/*Systick Handler*/
void SysTick_Handler(void)
{
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
}

