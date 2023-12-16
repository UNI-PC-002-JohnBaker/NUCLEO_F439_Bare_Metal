# STM32BareMetal-Projects:

## Nucleo-F439ZI 



example 

<!--

#include <stdio.h>
int main(void)
{
    /* Loop forever */
	printf("Hello World\n");
	for(;;);
}
-->


place after "#include <sys/times.h>"   in   "syscalls.c"

<!--
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//					Implementation of printf like feature using ARM Cortex M3/M4/ ITM functionality
//					This function will not work for ARM Cortex M0/M0+
//					If you are using Cortex M0, then you can use semihosting feature of openOCD
/////////////////////////////////////////////////////////////////////////////////////////////////////////


//Debug Exception and Monitor Control Register base address
#define DEMCR        			*((volatile uint32_t*) 0xE000EDFCU )

/* ITM register addresses */
#define ITM_STIMULUS_PORT0   	*((volatile uint32_t*) 0xE0000000 )
#define ITM_TRACE_EN          	*((volatile uint32_t*) 0xE0000E00 )

void ITM_SendChar(uint8_t ch)
{

	//Enable TRCENA
	DEMCR |= ( 1 << 24);

	//enable stimulus port 0
	ITM_TRACE_EN |= ( 1 << 0);

	// read FIFO status in bit [0]:
	while(!(ITM_STIMULUS_PORT0 & 1));

	//Write to ITM stimulus port0
	ITM_STIMULUS_PORT0 = ch;
}
-->



modify 

<!--
__attribute__((weak)) int _write(int file, char *ptr, int len)
{
  (void)file;
  int DataIdx;

  for (DataIdx = 0; DataIdx < len; DataIdx++)
  {
   // __io_putchar(*ptr++);
	  ITM_SendChar(*ptr++);  // send to ITM fifo
  }
  return len;
}
-->

printf works over SWO pin of SWD (2 wire protocol)  interface

It uses ITM unit (Instrumentation Trace Macrocell Unit
Go to window, Show view, SWV, SWV ITM Data Console

click on configure trace and choose port 0
Start Trace


# Enable FPU (cortex m4 generic guide) Chapter 4




