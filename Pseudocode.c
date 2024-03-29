#include<stdint.h>

//caluclations to find STACK_START

#define STACK_START SRAM_END

int main(void);

//function prototypes of STM32407x system exceptions and IRQ Handlers

void Reset_handler(void);
void NMI_Handler				(void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler				(void) __attribute__ ((weak, alias("Default_Handler")));
.
.
.
/*implement all prototypes*/

//vector table creation

uint32_t vectors[] __attribute__((section(".isr_vector"))) = {
STACK_START,
(uint32_t)&Reset_handler,
(uint32_t)&NMI_Handler,

/*implement total (15exceptions,82IRQs,1MSP) 98 word addressable memeory*/



}

void Default_Handler(void)
{
	/* imlementation of default handler */
}	

void Reset_handler(void)
{
	/*implementation of reset handler*/

	//copy .data section to SRAM
		
	//Init the .bss section to zero in SRAM
	
	//call init function of std. libray(like printf, scanf)
		
	//call main	
	
}	
 
 
 * System Clock Configuration External */
 
void SystemClock_Config_Exe(void) {
	
    // Enable HSE (external oscillator)
    

    // Wait until HSE is ready
    

    // Configure PLL
    

    // Enable PLL
    

    // Wait until PLL is ready
    

    // Select PLL as system clock source
    

    // Wait until PLL is used as the system clock source
    
}

/* System Clock Configuration Internal */

void SystemClock_Config_In(void) {
    // Enable HSI (internal oscillator)
    

    // Wait until HSI is ready
    

    // Configure PLL
    

    // Enable PLL
    

    // Wait until PLL is ready
    

    // Select PLL as system clock source
    

    // Wait until HSI is used as the system clock source
    
}