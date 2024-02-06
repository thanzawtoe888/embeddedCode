#include "stm32f4xx.h"

void delay(uint32_t count);
int main (void)
{
	//RCC clock enable
	RCC->AHB1ENR |= 1<<3; 
	
	//GPIOD enable
	GPIOD->MODER |= 1<<24;
	
	
	while (1)
	{
		
		GPIOD->ODR |= 1u<<12;
		//delay(1000000000);
		for(int i =0; i < 1000000000 ; i++);
		GPIOD->ODR &= ~(1u<<12);
		for(int i =0; i < 1000000000 ; i++);
		//delay(1000000000);

		
		//GPIOD->ODR ^= GPIO_ODR_ODR_12;
		//delay(1000000000);
	}
}

void delay(uint32_t count) {
    for(uint32_t i = 0; i < count; i++);
}
