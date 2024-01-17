#include "stm32f4xx.h"
void delay_ms(uint32_t ms);

void delay_ms(uint32_t ms) {
    // Simple delay function
    for (uint32_t i = 0; i < ms; i++)
        for (uint32_t j = 0; j < 2000; j++) {}
}

int main(void) {
    // Enable the GPIO D clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    // Configure GPIO D pin 13 as output
    GPIOD->MODER |= GPIO_MODER_MODER13_0;  // General purpose output mode
    GPIOD->OTYPER &= ~GPIO_OTYPER_OT_13;   // Output push-pull
    GPIOD->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR13;  // High speed
    GPIOD->PUPDR &= ~GPIO_PUPDR_PUPDR13;  // No pull-up, no pull-down

    while (1) {
        // Turn LED on (set pin high)
        GPIOD->BSRR |= GPIO_BSRR_BS13;

        // Delay for 2 seconds
        delay_ms(2000000);

        // Turn LED off (set pin low)
        GPIOD->BSRR |= GPIO_BSRR_BR13;

        // Delay for 2 seconds
        delay_ms(2000000);
    }
}
