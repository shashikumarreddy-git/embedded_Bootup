#include <stdint.h>

/* Peripheral base addresses */
#define RCC_BASE            0x40023800UL
#define GPIOA_BASE          0x40020000UL
#define GPIOB_BASE          0x40020400UL
// Define base addresses for other GPIO ports if needed

/* RCC registers */
#define RCC_CR              (*(volatile uint32_t *)(RCC_BASE + 0x00))
#define RCC_PLLCFGR         (*(volatile uint32_t *)(RCC_BASE + 0x04))
#define RCC_CFGR            (*(volatile uint32_t *)(RCC_BASE + 0x08))
#define RCC_AHB1ENR         (*(volatile uint32_t *)(RCC_BASE + 0x30))

/* GPIO registers */
#define GPIOA_MODER         (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_OSPEEDR       (*(volatile uint32_t *)(GPIOA_BASE + 0x08))
#define GPIOA_OTYPER        (*(volatile uint32_t *)(GPIOA_BASE + 0x14))
#define GPIOA_PUPDR         (*(volatile uint32_t *)(GPIOA_BASE + 0x0C))

/* Function prototypes */
void SystemClock_Config(void);
void GPIO_Init(void);

/* Main function */
int main(void) {
    // Initialize system
    SystemClock_Config();

    // Initialize GPIOs
    GPIO_Init();

    // Main application loop
    while (1) {
        // Your application code here
    }
}

/* System Clock Configuration */
void SystemClock_Config_Exe(void) {
    // Enable HSE (external oscillator)
    RCC_CR |= (1UL << 16); // HSEON bit

    // Wait until HSE is ready
    while (!(RCC_CR & (1UL << 17))); // HSERDY bit

    // Configure PLL
    RCC_PLLCFGR = (8UL << 0) | (336UL << 6) | (2UL << 16) | (7UL << 24);

    // Enable PLL
    RCC_CR |= (1UL << 24); // PLLON bit

    // Wait until PLL is ready
    while (!(RCC_CR & (1UL << 25))); // PLLRDY bit

    // Select PLL as system clock source
    RCC_CFGR = (0x2UL << 0);

    // Wait until PLL is used as the system clock source
    while ((RCC_CFGR & (0x3UL << 2)) != (0x2UL << 2));
}

/* System Clock Configuration */
void SystemClock_Config_In(void) {
    // Enable HSI (internal oscillator)
    RCC_CR |= (1UL << 0); // HSION bit

    // Wait until HSI is ready
    while (!(RCC_CR & (1UL << 1))); // HSIRDY bit

    // Configure PLL
    RCC_PLLCFGR = (16UL << 0) | (192UL << 6) | (2UL << 16) | (7UL << 24); // Example values for PLL configuration

    // Enable PLL
    RCC_CR |= (1UL << 24); // PLLON bit

    // Wait until PLL is ready
    while (!(RCC_CR & (1UL << 25))); // PLLRDY bit

    // Select PLL as system clock source
    RCC_CFGR = (0x0UL << 0); // Select HSI as system clock source

    // Wait until HSI is used as the system clock source
    while ((RCC_CFGR & (0x3UL << 2)) != (0x0UL << 2));
}


/* GPIO initialization */
void GPIO_Init(void) {
    // Enable GPIOA clock
    RCC_AHB1ENR |= (1UL << 0); // GPIOAEN bit

    // Configure GPIO pin
    GPIOX_MODER |= (0x1UL << 10); // Set pin PX5 as output
    GPIOX_OTYPER &= ~(0x1UL << 5); // Set pin PX5 as push-pull
    GPIOX_OSPEEDR |= (0x3UL << 10); // Set pin PX5 as high-speed
    GPIOX_PUPDR &= ~(0x3UL << 10); // No pull-up, no pull-down
}
