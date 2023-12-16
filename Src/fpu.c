#include "stm32f439xx.h"

void fpu_enable(void)
{
	/*Enable floating point unit: Enable CP10 & CP11 full access*/
	SCB->CPACR |=(1<<20);
	SCB->CPACR |=(1<<21);
	SCB->CPACR |=(1<<22);
	SCB->CPACR |=(1<<23);

}
