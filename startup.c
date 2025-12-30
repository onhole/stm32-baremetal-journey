#include <stdint.h>

#define SRAM_START (0x20000000U)
#define SRAM_SIZE (112U * 1024U)
#define SRAM_END (SRAM_START + SRAM_SIZE)
#define STACK_POINTER_INIT_ADDRESS (SRAM_END)

/* ============================================================================================================= */
/* Cortex-M4 Processor Exception Handlers                                                                                   */
/* ============================================================================================================= */

void default_handler(void);
void reset_handler(void);

void NMI_handler(void)                 __attribute__((weak, alias("default_handler")));
void hard_fault_handler(void)          __attribute__((weak, alias("default_handler")));
void mem_manage_handler(void)          __attribute__((weak, alias("default_handler")));
void bus_fault_handler(void)           __attribute__((weak, alias("default_handler")));
void usage_fault_handler(void)         __attribute__((weak, alias("default_handler")));
void SVC_handler(void)                 __attribute__((weak, alias("default_handler")));
void debug_monitor_handler(void)       __attribute__((weak, alias("default_handler")));
void pend_SV_handler(void)             __attribute__((weak, alias("default_handler")));
void sys_tick_handler(void)            __attribute__((weak, alias("default_handler")));

/* ============================================================================================================= */
/* External Interrupt Handlers                                                                                   */
/* ============================================================================================================= */
void WWDG_handler(void)                __attribute__((weak, alias("default_handler")));
void PVD_handler(void)                 __attribute__((weak, alias("default_handler")));
void TAMP_STAMP_handler(void)          __attribute__((weak, alias("default_handler")));
void RTC_WKUP_handler(void)            __attribute__((weak, alias("default_handler")));
void FLASH_handler(void)               __attribute__((weak, alias("default_handler")));
void RCC_handler(void)                 __attribute__((weak, alias("default_handler")));
void EXTI0_handler(void)               __attribute__((weak, alias("default_handler")));
void EXTI1_handler(void)               __attribute__((weak, alias("default_handler")));
void EXTI2_handler(void)               __attribute__((weak, alias("default_handler")));
void EXTI3_handler(void)               __attribute__((weak, alias("default_handler")));
void EXTI4_handler(void)               __attribute__((weak, alias("default_handler")));
void DMA1_Stream0_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA1_Stream1_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA1_Stream2_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA1_Stream3_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA1_Stream4_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA1_Stream5_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA1_Stream6_handler(void)        __attribute__((weak, alias("default_handler")));
void ADC_handler(void)                 __attribute__((weak, alias("default_handler")));
void CAN1_TX_handler(void)             __attribute__((weak, alias("default_handler")));
void CAN1_RX0_handler(void)            __attribute__((weak, alias("default_handler")));
void CAN1_RX1_handler(void)            __attribute__((weak, alias("default_handler")));
void CAN1_SCE_handler(void)            __attribute__((weak, alias("default_handler")));
void EXTI9_5_handler(void)             __attribute__((weak, alias("default_handler")));
void TMI1_BRK_TIM9_handler(void)       __attribute__((weak, alias("default_handler")));
void TIM1_UP_TIM10_handler(void)       __attribute__((weak, alias("default_handler")));
void TIM1_TRG_COM_TIM11_handler(void)  __attribute__((weak, alias("default_handler")));
void TIM1_CC_handler(void)             __attribute__((weak, alias("default_handler")));
void TIM2_handler(void)                __attribute__((weak, alias("default_handler")));
void TIM3_handler(void)                __attribute__((weak, alias("default_handler")));
void TIM4_handler(void)                __attribute__((weak, alias("default_handler")));
void I2C1_EV_handler(void)             __attribute__((weak, alias("default_handler")));
void I2C1_ER_handler(void)             __attribute__((weak, alias("default_handler")));
void I2C2_EV_handler(void)             __attribute__((weak, alias("default_handler")));
void I2C2_ER_handler(void)             __attribute__((weak, alias("default_handler")));
void SPI1_handler(void)                __attribute__((weak, alias("default_handler")));
void SPI2_handler(void)                __attribute__((weak, alias("default_handler")));
void USART1_handler(void)              __attribute__((weak, alias("default_handler")));
void USART2_handler(void)              __attribute__((weak, alias("default_handler")));
void USART3_handler(void)              __attribute__((weak, alias("default_handler")));
void EXTI15_10_handler(void)           __attribute__((weak, alias("default_handler")));
void RTC_alarm_handler(void)           __attribute__((weak, alias("default_handler")));
void OTG_FS_WKUP_handler(void)         __attribute__((weak, alias("default_handler")));
void TIM8_BRK_TIM12_handler(void)      __attribute__((weak, alias("default_handler")));
void TIM8_UP_TIM13_handler(void)       __attribute__((weak, alias("default_handler")));
void TIM8_TRG_COM_TIM14_handler(void)  __attribute__((weak, alias("default_handler")));
void TIM8_CC_handler(void)             __attribute__((weak, alias("default_handler")));
void DMA1_Stream7_handler(void)        __attribute__((weak, alias("default_handler")));
void FMC_handler(void)                 __attribute__((weak, alias("default_handler")));
void SDIO_handler(void)                __attribute__((weak, alias("default_handler")));
void TIM5_handler(void)                __attribute__((weak, alias("default_handler")));
void SPI3_handler(void)                __attribute__((weak, alias("default_handler")));
void UART4_handler(void)               __attribute__((weak, alias("default_handler")));
void UART5_handler(void)               __attribute__((weak, alias("default_handler")));
void TIM6_DAC_handler(void)            __attribute__((weak, alias("default_handler")));
void TIM7_handler(void)                __attribute__((weak, alias("default_handler")));
void DMA2_Stream0_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA2_Stream1_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA2_Stream2_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA2_Stream3_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA2_Stream4_handler(void)        __attribute__((weak, alias("default_handler")));
void CAN2_TX_handler(void)             __attribute__((weak, alias("default_handler")));
void CAN2_RX0_handler(void)            __attribute__((weak, alias("default_handler")));
void CAN2_RX1_handler(void)            __attribute__((weak, alias("default_handler")));
void CAN2_SCE_handler(void)            __attribute__((weak, alias("default_handler")));
void OTG_FS_handler(void)              __attribute__((weak, alias("default_handler")));
void DMA2_Stream5_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA2_Stream6_handler(void)        __attribute__((weak, alias("default_handler")));
void DMA2_Stream7_handler(void)        __attribute__((weak, alias("default_handler")));
void USART6_handler(void)              __attribute__((weak, alias("default_handler")));
void I2C3_EV_handler(void)             __attribute__((weak, alias("default_handler")));
void I2C3_ER_handler(void)             __attribute__((weak, alias("default_handler")));
void OTG_HS_EP1_OUT_handler(void)      __attribute__((weak, alias("default_handler")));
void OTG_HS_EP1_IN_handler(void)       __attribute__((weak, alias("default_handler")));
void OTG_HS_WKUP_handler(void)         __attribute__((weak, alias("default_handler")));
void OTG_HS_handler(void)              __attribute__((weak, alias("default_handler")));
void DCMI_handler(void)                __attribute__((weak, alias("default_handler")));
void FPU_handler(void)                 __attribute__((weak, alias("default_handler")));
void SPI4_handler(void)                __attribute__((weak, alias("default_handler")));
void SAI1_handler(void)                __attribute__((weak, alias("default_handler")));
void SAI2_handler(void)                __attribute__((weak, alias("default_handler")));
void QuadSPI_handler(void)             __attribute__((weak, alias("default_handler")));
void HDMI_CEC_handler(void)            __attribute__((weak, alias("default_handler")));
void SPDIF_RX_handler(void)            __attribute__((weak, alias("default_handler")));
void FMPI2C1_handler(void)             __attribute__((weak, alias("default_handler")));
void FMPI2C1_error_handler(void)       __attribute__((weak, alias("default_handler")));

__attribute__((section(".vector_table"))) uint32_t __vector_table[] = {
    /* Processor Exceptions */
    STACK_POINTER_INIT_ADDRESS,        /* Initial Stack Pointer */
    (uint32_t)reset_handler,       /* Reset Handler */
    (uint32_t)NMI_handler,         /* Non-maskable Interrupt Handler */
    (uint32_t)hard_fault_handler,  /* Hard Fault Handler */
    (uint32_t)mem_manage_handler,  /* Memory Protection Unit Error Handler */
    (uint32_t)bus_fault_handler,   /* Bus Fault Handler */
    (uint32_t)usage_fault_handler, /* Usage Fault Handler */
    (uint32_t)0,                   /* Reserved */
    (uint32_t)0,                   /* Reserved */
    (uint32_t)0,                   /* Reserved */
    (uint32_t)0,                   /* Reserved */
    (uint32_t)SVC_handler,         /* Supervisor Call Handler */
    (uint32_t)debug_monitor_handler, /* Debug Monitor Handler */
    (uint32_t)0,                   /* Reserved */
    (uint32_t)pend_SV_handler,     /* PendSV Handler */
    (uint32_t)sys_tick_handler,    /* SysTick Handler */

    /* External Interrupts */
    (uint32_t)WWDG_handler,           
    (uint32_t)PVD_handler,            
    (uint32_t)TAMP_STAMP_handler,     
    (uint32_t)RTC_WKUP_handler,       
    (uint32_t)FLASH_handler,          
    (uint32_t)RCC_handler,            
    (uint32_t)EXTI0_handler,          
    (uint32_t)EXTI1_handler,          
    (uint32_t)EXTI2_handler,          
    (uint32_t)EXTI3_handler,          
    (uint32_t)EXTI4_handler,          
    (uint32_t)DMA1_Stream0_handler,   
    (uint32_t)DMA1_Stream1_handler,   
    (uint32_t)DMA1_Stream2_handler,   
    (uint32_t)DMA1_Stream3_handler,   
    (uint32_t)DMA1_Stream4_handler,   
    (uint32_t)DMA1_Stream5_handler,   
    (uint32_t)DMA1_Stream6_handler,   
    (uint32_t)ADC_handler,            
    (uint32_t)CAN1_TX_handler,        
    (uint32_t)CAN1_RX0_handler,       
    (uint32_t)CAN1_RX1_handler,       
    (uint32_t)CAN1_SCE_handler,       
    (uint32_t)EXTI9_5_handler,        
    (uint32_t)TMI1_BRK_TIM9_handler,  
    (uint32_t)TIM1_UP_TIM10_handler,  
    (uint32_t)TIM1_TRG_COM_TIM11_handler,
    (uint32_t)TIM1_CC_handler,        
    (uint32_t)TIM2_handler,           
    (uint32_t)TIM3_handler,           
    (uint32_t)TIM4_handler,           
    (uint32_t)I2C1_EV_handler,        
    (uint32_t)I2C1_ER_handler,        
    (uint32_t)I2C2_EV_handler,        
    (uint32_t)I2C2_ER_handler,        
    (uint32_t)SPI1_handler,           
    (uint32_t)SPI2_handler,           
    (uint32_t)USART1_handler,         
    (uint32_t)USART2_handler,         
    (uint32_t)USART3_handler,         
    (uint32_t)EXTI15_10_handler,      
    (uint32_t)RTC_alarm_handler,      
    (uint32_t)OTG_FS_WKUP_handler,    
    (uint32_t)TIM8_BRK_TIM12_handler, 
    (uint32_t)TIM8_UP_TIM13_handler,  
    (uint32_t)TIM8_TRG_COM_TIM14_handler,
    (uint32_t)TIM8_CC_handler,        
    (uint32_t)DMA1_Stream7_handler,   
    (uint32_t)FMC_handler,            
    (uint32_t)SDIO_handler,           
    (uint32_t)TIM5_handler,           
    (uint32_t)SPI3_handler,           
    (uint32_t)UART4_handler,          
    (uint32_t)UART5_handler,          
    (uint32_t)TIM6_DAC_handler,       
    (uint32_t)TIM7_handler,           
    (uint32_t)DMA2_Stream0_handler,   
    (uint32_t)DMA2_Stream1_handler,   
    (uint32_t)DMA2_Stream2_handler,   
    (uint32_t)DMA2_Stream3_handler,   
    (uint32_t)DMA2_Stream4_handler,   
    (uint32_t)0,                      
    (uint32_t)0,                      
    (uint32_t)CAN2_TX_handler,        
    (uint32_t)CAN2_RX0_handler,       
    (uint32_t)CAN2_RX1_handler,       
    (uint32_t)CAN2_SCE_handler,       
    (uint32_t)OTG_FS_handler,         
    (uint32_t)DMA2_Stream5_handler,   
    (uint32_t)DMA2_Stream6_handler,   
    (uint32_t)DMA2_Stream7_handler,   
    (uint32_t)USART6_handler,         
    (uint32_t)I2C3_EV_handler,        
    (uint32_t)I2C3_ER_handler,        
    (uint32_t)OTG_HS_EP1_OUT_handler, 
    (uint32_t)OTG_HS_EP1_IN_handler,  
    (uint32_t)OTG_HS_WKUP_handler,    
    (uint32_t)OTG_HS_handler,         
    (uint32_t)DCMI_handler,           
    (uint32_t)0,                      
    (uint32_t)0,                      
    (uint32_t)FPU_handler,            
    (uint32_t)0,                      
    (uint32_t)0,                      
    (uint32_t)SPI4_handler,           
    (uint32_t)0,                      
    (uint32_t)0,                      
    (uint32_t)SAI1_handler,           
    (uint32_t)0,                      
    (uint32_t)0,                      
    (uint32_t)0,                      
    (uint32_t)SAI2_handler,           
    (uint32_t)QuadSPI_handler,        
    (uint32_t)HDMI_CEC_handler,       
    (uint32_t)SPDIF_RX_handler,       
    (uint32_t)FMPI2C1_handler,        
    (uint32_t)FMPI2C1_error_handler   
};

extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss;
void main (void);

void reset_handler (void) {
    // copy data from ROM to RAM
    uint8_t *flashDataStart = (uint8_t *)&_sdata; // first line of data so we need to get the address
    uint8_t *sramDataStart = (uint8_t *)&_sidata; // uint8_t because each address is byte-addressable.

    uint32_t dataSize = (uint32_t)&_edata - (uint32_t)&_sdata; // need to cast in case compiler complains.
    
    for (uint32_t i = 0; i < dataSize; i++) {
        sramDataStart[i] = flashDataStart[i];
    }

    // initialize bss section with 0s.
    uint8_t *bssStart = (uint8_t *)&_sbss;
    uint32_t bssSize = (uint32_t)&_ebss - (uint32_t)&_sbss;

    for (uint32_t i = 0; i < bssSize; i++) {
        bssStart[i] = 0;
    }

    // call main
    main();
}

void default_handler(void) {
    while (1);
}
