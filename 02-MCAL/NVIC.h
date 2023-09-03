

#ifndef NVIC_H_
#define NVIC_H_

#include "../01-LIB/STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*TODO: Set Configured IRQ IN NVIC_Cfg File*/
#define NVIC_CONFIGURED_IRQS 3

#define NVIC_PRIORITY_FIELDS_PER_REG 4

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*Typedef For IRQ signals From TM4C123GH6PM peripherals To Cortex-M4F Core*/
typedef enum
{
	NVIC_GPIO_PORT_A_IRQ = 0,						  /* IRQ 0 - Vector 16  */
	NVIC_GPIO_PORT_B_IRQ,							  /* IRQ 1 - Vector 17  */
	NVIC_GPIO_PORT_C_IRQ,							  /* IRQ 2 - Vector 18  */
	NVIC_GPIO_PORT_D_IRQ,							  /* IRQ 3 - Vector 19  */
	NVIC_GPIO_PORT_E_IRQ,							  /* IRQ 4 - Vector 20  */
	NVIC_UART0_IRQ,									  /* IRQ 5 - Vector 21  */
	NVIC_UART1_IRQ,									  /* IRQ 6 - Vector 22  */
	NVIC_SSI0_IRQ,									  /* IRQ 7 - Vector 23  */
	NVIC_I2C0_IRQ,									  /* IRQ 8 - Vector 24  */
	NVIC_PWM0_FAULT_IRQ,							  /* IRQ 9 - Vector 25  */
	NVIC_PWM0_GENERATOR_0_IRQ,						  /* IRQ 10 - Vector 26 */
	NVIC_PWM0_GENERATOR_1_IRQ,						  /* IRQ 11 - Vector 27 */
	NVIC_PWM0_GENERATOR_2_IRQ,						  /* IRQ 12 - Vector 28 */
	NVIC_QEI0_IRQ,									  /* IRQ 13 - Vector 29 */
	NVIC_ADC0_SEQUENCE0_IRQ,						  /* IRQ 14 - Vector 30 */
	NVIC_ADC0_SEQUENCE1_IRQ,						  /* IRQ 15 - Vector 31 */
	NVIC_ADC0_SEQUENCE2_IRQ,						  /* IRQ 16 - Vector 32 */
	NVIC_ADC0_SEQUENCE3_IRQ,						  /* IRQ 17 - Vector 33 */
	NVIC_WATCHDOG_TIMERS_0_AND_1,					  /* IRQ 18 - Vector 34 */
	NVIC_16_32_TIMER_0A_IRQ,						  /* IRQ 19 - Vector 35 */
	NVIC_16_32_TIMER_0B_IRQ,						  /* IRQ 20 - Vector 36 */
	NVIC_16_32_TIMER_1A_IRQ,						  /* IRQ 21 - Vector 37 */
	NVIC_16_32_TIMER_1B_IRQ,						  /* IRQ 22 - Vector 38 */
	NVIC_16_32_TIMER_2A_IRQ,						  /* IRQ 23 - Vector 39 */
	NVIC_16_32_TIMER_2B_IRQ,						  /* IRQ 24 - Vector 40 */
	NVIC_ANALOG_COMPARATOR0_IRQ,					  /* IRQ 25 - Vector 41 */
	NVIC_ANALOG_COMPARATOR1_IRQ,					  /* IRQ 26 - Vector 42 */
	/*Reserved*/									  /*  --- Reserved ---  */
	NVIC_SYSTEM_CONTROL_IRQ = 28,					  /* IRQ 28 - Vector 44 */
	NVIC_FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL_IRQ, /* IRQ 29 - Vector 45 */
	NVIC_GPIO_PORT_F_IRQ,							  /* IRQ 30 - Vector 46 */
	/*Reserved*/									  /*  --- Reserved ---  */
	NVIC_UART2_IRQ = 33,							  /* IRQ 33 - Vector 49 */
	NVIC_SSI1_IRQ,									  /* IRQ 34 - Vector 50 */
	NVIC_TIMER_3A_IRQ,								  /* IRQ 35 - Vector 51 */
	NVIC_TIMER_3B_IRQ,								  /* IRQ 36 - Vector 52 */
	NVIC_I2C1_IRQ,									  /* IRQ 37 - Vector 53 */
	NVIC_QEI1_IRQ,									  /* IRQ 38 - Vector 54 */
	NVIC_CAN0_IRQ,									  /* IRQ 39 - Vector 55 */
	NVIC_CAN1_IRQ,									  /* IRQ 40 - Vector 56 */
	/*Reserved*/									  /*  --- Reserved ---  */
	NVIC_HIBERNATION_MODULE_IRQ = 43,				  /* IRQ 43 - Vector 59 */
	NVIC_USB_IRQ,									  /* IRQ 44 - Vector 60 */
	NVIC_PWM_GENERATOR3_IRQ,						  /* IRQ 45 - Vector 61 */
	NVIC_MDMA_SOFTWARE_IRQ,							  /* IRQ 46 - Vector 62 */
	NVIC_MDMA_ERROR_IRQ,							  /* IRQ 47 - Vector 63 */
	NVIC_ADC1_SEQUENCE0_IRQ,						  /* IRQ 48 - Vector 64 */
	NVIC_ADC1_SEQUENCE1_IRQ,						  /* IRQ 49 - Vector 65 */
	NVIC_ADC1_SEQUENCE2_IRQ,						  /* IRQ 50 - Vector 66 */
	NVIC_ADC1_SEQUENCE3_IRQ,						  /* IRQ 51 - Vector 67 */
	/*Reserved*/									  /*  --- Reserved ---  */
	NVIC_SSI2_IRQ = 57,								  /* IRQ 57 - Vector 73 */
	NVIC_SSI3_IRQ,									  /* IRQ 58 - Vector 74 */
	NVIC_UART3_IRQ,									  /* IRQ 59 - Vector 75 */
	NVIC_UART4_IRQ,									  /* IRQ 60 - Vector 76 */
	NVIC_UART5_IRQ,									  /* IRQ 61 - Vector 77 */
	NVIC_UART6_IRQ,									  /* IRQ 62 - Vector 78 */
	NVIC_UART7_IRQ,									  /* IRQ 63 - Vector 79 */
	/*Reserved*/									  /*  --- Reserved ---  */
	NVIC_I2C2_IRQ = 68,								  /* IRQ 68 - Vector 84 */
	NVIC_I2C3_IRQ,									  /* IRQ 69 - Vector 85 */
	NVIC_16_32_TIMER_4A_IRQ,						  /* IRQ 70 - Vector 86 */
	NVIC_16_32_TIMER_4B_IRQ,						  /* IRQ 71 - Vector 87 */
	/*Reserved*/									  /* ---- Reserved ---- */
	NVIC_16_32_TIMER_5A_IRQ = 92,					  /*IRQ 92 - Vector 108	*/
	NVIC_16_32_TIMER_5B_IRQ,						  /*IRQ 93 - Vector 109	*/
	NVIC_32_64_TIMER_0A_IRQ,						  /*IRQ 94 - Vector 110	*/
	NVIC_32_64_TIMER_0B_IRQ,						  /*IRQ 95 - Vector 111	*/
	NVIC_32_64_TIMER_1A_IRQ,						  /*IRQ 96 - Vector 112	*/
	NVIC_32_64_TIMER_1B_IRQ,						  /*IRQ 97 - Vector 113	*/
	NVIC_32_64_TIMER_2A_IRQ,						  /*IRQ 98 - Vector 114	*/
	NVIC_32_64_TIMER_2B_IRQ,						  /*IRQ 99 - Vector 115	*/
	NVIC_32_64_TIMER_3A_IRQ,						  /*IRQ 100 - Vector 116*/
	NVIC_32_64_TIMER_3B_IRQ,						  /*IRQ 101 - Vector 117*/
	NVIC_32_64_TIMER_4A_IRQ,						  /*IRQ 102 - Vector 118*/
	NVIC_32_64_TIMER_4B_IRQ,						  /*IRQ 103 - Vector 119*/
	NVIC_32_64_TIMER_5A_IRQ,						  /*IRQ 104 - Vector 120*/
	NVIC_32_64_TIMER_5B_IRQ,						  /*IRQ 105 - Vector 121*/
	NVIC_32_64_SYSTEM_EXCEPTION_IRQ,				  /*IRQ 106 - Vector 122*/
	/*reserved*/									  /* ---- Reserved ---- */
	NVIC_PWM1_GENERATOR0_IRQ = 134,					  /*IRQ 134 - Vector 150*/
	NVIC_PWM1_GENERATOR1_IRQ,						  /*IRQ 135 - Vector 151*/
	NVIC_PWM1_GENERATOR2_IRQ,						  /*IRQ 136 - Vector 152*/
	NVIC_PWM1_GENERATOR3_IRQ,						  /*IRQ 137 - Vector 153*/
	NVIC_PWM1_FAULT_IRQ,							  /*IRQ 138 - Vector 154*/
} NVIC_IrqNumberType;

/*Typdef For IRQ Group Priority According To Sys_Grouping_select in APIN Reg */
typedef uint8 NVIC_GroupPriorityType;

/*Typdef For IRQ subGroup Priority According To Sys_Grouping_select in APIN Reg */
typedef uint8 NVIC_SubGroupPriorityType;

/*Typdef For Configuring an IRQ*/
typedef struct
{
	NVIC_IrqNumberType irqNum;
	NVIC_GroupPriorityType groupPriority;
	NVIC_SubGroupPriorityType subGroupPriority;
} NVIC_ConfigType;

/**********************************************************************************************************************
 *                                        GLOBAL FUNCTION PROTOTYPES                                                *
 *********************************************************************************************************************/
void NVIC_Init(const NVIC_ConfigType *configPtr);
void NVIC_IrqSetPending(NVIC_IrqNumberType irqNum);
void NVIC_IrqClearPending(NVIC_IrqNumberType irqNum);
void NVIC_IrqSetEnable(NVIC_IrqNumberType irqNum);
void NVIC_IrqSetDisable(NVIC_IrqNumberType irqNum);
#endif /* NVIC_H_ */