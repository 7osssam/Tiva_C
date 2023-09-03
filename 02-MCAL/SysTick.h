#ifndef SYS_TICK_H_
#define SYS_TICK_H_

#include "../01-LIB/BIT_MACROS.h"
#include "../01-LIB/STD_TYPES.h"

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
	SysTick_INT Int;
	uint32 ReloadValue;
} SysTick_ConfigType;

void SysTick_init(SysTick_ConfigType *Config_Ptr);

#endif /* SYS_TICK_H_ */