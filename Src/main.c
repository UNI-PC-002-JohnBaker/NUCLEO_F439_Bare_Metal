
#include "stm32f439xx.h"
#include "fpu.h"

#include <stdint.h>
#include <stdio.h>




#define GPIOBEN 		(1U<<1)
#define PIN0			(1U<<0)
#define LED1_PIN		PIN0




int main(void)
{
	    //enable FPU
		//fpu_enable();



		/*Enable clock access to GPIOB*/
		RCC->AHB1ENR  |= GPIOBEN;                   //enable clock access to GPIOB

		/* Set output = PB0 for board green LED1*/
		GPIOB->MODER |= (1U<<00);
		GPIOB->MODER &= ~(1U<<01);



		printf("Hello World\n");                    //write to SWO console

	while(1)
	{
		GPIOB->ODR ^= LED1_PIN;
		for(int i=0; i<100000; i++){};

	}
}


