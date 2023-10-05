/******************************************************************
 * @Title    : System Tick Driver Header
 * @Filename : SysTick.h
 * @Author   : Hossam Mohamed
 * @Compiler : IAR
 * @Target   : Tiva-C (Tm4c123gh6pm)
 ********************************************************************/
#ifndef SYS_TICK_H_
#define SYS_TICK_H_

#include "BIT_MACROS.h"
#include "STD_TYPES.h"

typedef enum
{
	PIOSC_4 = 0,
	SYS_CLK = 1
} SysTick_CLK_SRC;

typedef enum
{
	INT_DISABLE = 0,
	INT_ENABLE = 1
} SysTick_INT;

// configuration type
typedef struct
{
	SysTick_CLK_SRC ClkSrc;
	SysTick_INT		Int;
	uint32			ReloadValue;
} SysTick_ConfigType;

void SysTick_init(SysTick_ConfigType* Config_Ptr);
void SysTick_SetPriority(uint8 ExceptionPriority);
void SysTick_enableException(void);
void SysTick_disableException(void);

#endif /* SYS_TICK_H_ */