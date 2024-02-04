#include "stm32f4xx.h"

void GPIO_Config(void);
void EXTI0_IRQHandler(void);
void SysTick_Handler(void);


int main (void)
{
	
	HAL_Init();
	GPIO_Config();
	
	
	
	while(1)
		{
			HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);
			HAL_Delay(500);
		}
}

void GPIO_Config(void)
{
	GPIO_InitTypeDef mypinInit;
	
  __HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	mypinInit.Pin = GPIO_PIN_0;
	mypinInit.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOA, &mypinInit);
	
	mypinInit.Pin = GPIO_PIN_12 | GPIO_PIN_13;
	mypinInit.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOD, &mypinInit);
	
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0,0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
	
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);
  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Callback could be implemented in the user file
   */
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	for(uint32_t i = 0; i <10000 ; i++);
}

void EXTI0_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
