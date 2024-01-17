#include "stm32f4xx.h"
void Delayms(unsigned int ms);

int main() {
	
	//Loop variabe Initialization
	  //uint32_t i;
	
	//configure LEDs
	  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; //enable the clock of port D of the GPIO
	
	  GPIOD->MODER |= GPIO_MODER_MODE12_0; //Green LED, set pin 12 as Output
	  GPIOD->MODER |= GPIO_MODER_MODE13_0; //Orange LED, set pin 13 as Output
	  GPIOD->MODER |= GPIO_MODER_MODE14_0; //Red LED, set pin 14 as Output
	  GPIOD->MODER |= GPIO_MODER_MODE15_0; //Blue LED, set pin 15 as Output
	
	while(1){
		//Turn on LEDs
	  GPIOD->BSRR = 1<<12; //Set the BSRR bit 12 to 1 to turn respective LED on
    GPIOD->BSRR = 1<<13; //Set the BSRR bit 13 to 1 to turn respective LED on
	  GPIOD->BSRR = 1<<14; //Set the BSRR bit 14 to 1 to turn respective LED on
		GPIOD->BSRR = 0<<15; //Set the BSRR bit 15 to 1 to turn respective LED on
		
		//Delay
		//for(i = 0; i < 20000000; i++){};
		//Delayms(10000);
		
    //Turn off LEDs
    //GPIOD->BSRR = 0<<12; // Set the BSRR bit 12 + 16 to 1 to turn off respectice LED
    //GPIOD->BSRR = 0<<13; // Set the BSRR bit 13 + 16 to 1 to turn off respectice LED
    //GPIOD->BSRR = 0<<14; // Set the BSRR bit 14 + 16 to 1 to turn off respectice LED
    //GPIOD->BSRR = 0<<15; // Set the BSRR bit 15 + 16 to 1 to turn off respectice LED		
			
		//GPIOD->ODR =0;
		
		//Delay
		//for(i = 0; i < 20000000; i++){};
		//Delayms(10000);
	}
}
void Delayms(unsigned int ms)
{
	while(ms--) //ms x 1ms =ms?
	{
		for(int x=0;x<11111;x++);//1ms
	}
}
