typedef volatile struct{
    unsigned int rMEMRMP;
    unsigned int rPMC;
    unsigned int rEXTICR1;
    unsigned int rEXTICR2;
    unsigned int rEXTICR3;
    unsigned int rEXTICR4;
    unsigned int rCMPCR;
}REG_SYSCFG;

typedef volatile struct{
    unsigned int rIMR;
    unsigned int rEMR;
    unsigned int rRTSR;
    unsigned int rFTSR;
    unsigned int rSWIER;
    unsigned int rPR;
}REG_EXIT;


typedef volatile struct{
     unsigned int rRCC_CR;
     unsigned int rRCC_PLLCFGR;
     unsigned int rRCC_CFGR;
     unsigned int rRCC_CIR;
     unsigned int rRCC_AHB1RSTR;
     unsigned int reserved1;
     unsigned int reserved2;
     unsigned int reserved3;
     unsigned int reserved4;
     unsigned int reserved5;
     unsigned int reserved6;
     unsigned int reserved7;
     unsigned int rRCC_AHB1ENR;
     unsigned int reserved8;
     unsigned int reserved9;
     unsigned int reserved10;
     unsigned int rRCC_APB1ENR;
}tREG_RCC;

typedef volatile struct{
	unsigned int rMODER;
	unsigned int rOTYPER;
	unsigned int rOSPEEDR;
	unsigned int rPUPDR;
	unsigned int rIDR;
	unsigned int rODR;
	unsigned int reserved1;
	unsigned int reserved2;
	unsigned int rAFRL;
	unsigned int rAFRH;
}REG_GPIO;

typedef volatile struct{
	unsigned int rSR;
	unsigned int rDR;
	unsigned int rBRR;
	unsigned int rCR1;
	unsigned int rCR2;
	unsigned int rCR3;
	unsigned int reserved;
}REG_USART;

typedef volatile struct{
	unsigned int rCR1;
	unsigned int rCR2;
	unsigned int reserved1;
	unsigned int rDIER;
	unsigned int rSR;
	unsigned int rEGR;
	unsigned int rCCMR1;
	unsigned int rCCMR2;
	unsigned int rCCER;
	unsigned int rCNT;
	unsigned int rPSC;
	unsigned int rARR;
	unsigned int reserved2;
	unsigned int rCCR1;
	unsigned int rCCR2;
	unsigned int rCCR3;
	unsigned int rCCR4;
	unsigned int reserved3;
	unsigned int rDCR;
	unsigned int rDMAR;
}TIM2to5;

// RCC register //
#define RCC_BASE 0x40023800
#define RCC ((tREG_RCC*)RCC_BASE)

#define RCC_CR          (RCC->rRCC_CR)
#define RCC_PLLCFGR     (RCC->rRCC_PLLCFGR)
#define RCC_CFGR        (RCC->rRCC_CFGR)
#define RCC_CIR         (RCC->rRCC_CIR)
#define RCC_AHB1RSTR    (RCC->rRCC_AHB1RSTR)
#define RCC_AHB1ENR     (RCC->rRCC_AHB1ENR)
#define RCC_APB1ENR     (RCC->rRCC_APB1ENR)


// GPIO A //
#define GPIOA_BASE 0x40020000
#define GPIOA ((REG_GPIO*)GPIOA_BASE)

#define GPIOA_MODER		(GPIOA->rMODER) 
#define GPIOA_OTYPER  	(GPIOA->rOTYPER)
#define GPIOA_OSPEEDR 	(GPIOA->rOSPEEDR) 
#define GPIOA_PUPDR  	(GPIOA->rPUPDR)
#define GPIOA_IDR    	(GPIOA->rIDR)  
#define GPIOA_ODR		(GPIOA->rODR) 
#define GPIOA_AFRL		(GPIOA->rAFRL) 
#define GPIOA_AFRH		(GPIOA->rAFRH)  

// GPIO D //
#define GPIOD_BASE 0x40020C00
#define GPIOD ((REG_GPIO*)GPIOD_BASE)

#define GPIOD_MODER		(GPIOD->rMODER) 
#define GPIOD_OTYPER  	(GPIOD->rOTYPER)
#define GPIOD_OSPEEDR 	(GPIOD->rOSPEEDR) 
#define GPIOD_PUPDR  	(GPIOD->rPUPDR)
#define GPIOD_ODR		(GPIOD->rODR) 
#define GPIOD_AFRL		(GPIOD->rAFRL) 
#define GPIOD_AFRH		(GPIOD->rAFRH)  

// USART 2 //
#define USART2_BASE 0x40004400
#define USART2 ((REG_USART*)USART2_BASE)

#define USART2_SR		(USART2->rSR)
#define USART2_DR		(USART2->rDR)
#define USART2_BRR		(USART2->rBRR)
#define USART2_CR1		(USART2->rCR1)
#define USART2_CR2		(USART2->rCR2)
#define USART2_CR3		(USART2->rCR3)


// Timer 2 //
#define TIM2_BASE 0x40000000
#define TIM2 ((TIM2to5*)TIM2_BASE)

#define TIM2_CR1		(TIM2->rCR1)
#define TIM2_DIER		(TIM2->rDIER)
#define TIM2_SR			(TIM2->rSR)
#define TIM2_EGR		(TIM2->rEGR)
#define TIM2_CNT		(TIM2->rCNT)
#define TIM2_PSC		(TIM2->rPSC)
#define TIM2_ARR		(TIM2->rARR)

// SYSCFG Register //
#define SYSCFG_BASE 0x40013800
#define SYSCFG ((REG_SYSCFG*)SYSCFG_BASE)

#define SYSCFG_MEMRMP   (SYSCFG->rMEMRMP)
#define SYSCFG_PMC      (SYSCFG->rPMC   )
#define SYSCFG_EXTICR1  (SYSCFG->rEXTICR1)
#define SYSCFG_EXTICR2  (SYSCFG->rEXTICR2)
#define SYSCFG_EXTICR3  (SYSCFG->rEXTICR3)
#define SYSCFG_EXTICR4  (SYSCFG->rEXTICR4)
#define SYSCFG_CMPCR    (SYSCFG->rCMPCR  )

// EXTI Register //
#define EXTI_BASE 0x40013c00
#define EXTI ((REG_EXIT*)EXTI_BASE)

#define EXTI_IMR    (EXTI->rIMR)
#define EXTI_EMR    (EXTI->rEMR)
#define EXTI_RTSR   (EXTI->rRTSR)
#define EXTI_FTSR   (EXTI->rFTSR)
#define EXTI_SWIER  (EXTI->rSWIER)
#define EXTI_PR     (EXTI->rPR)

#define FLASH_ACR *(volatile unsigned *)0x40023C00
#define NVIC_ISER0 *(volatile unsigned *)0xE000E100
#define NVIC_ISER1 *(volatile unsigned *)0xE000E104
