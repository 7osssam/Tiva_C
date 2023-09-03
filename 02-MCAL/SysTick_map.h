#ifndef SYSTICK_MAP_H
#define SYSTICK_MAP_H

#include "../01-LIB/STD_TYPES.h"

#define SYSTICK_BASE 					0xE000E000
#define SYSTICK_CTRL_OFFSET  			0x010
#define SYSTICK_LOAD_OFFSET  			0x014
#define SYSTICK_VAL_OFFSET   			0x018

typedef union
{
	uint32 REG;
	struct
	{
		uint32 ENABLE 	  : 1;
		uint32 INTEN  	  : 1;
		uint32 CLK_SRC    : 1;
		uint32 			  : 13;
		uint32 COUNT_FLAG : 1; // Read only
		uint32  		  : 15;
	} bits;
} SYSTICK_CTRL_REG_t;

typedef union
{
	uint32 REG;
	struct
	{
		uint32 RELOAD : 24;
		uint32 		  : 8;
	} bits;
} SYSTICK_LOAD_REG_t;

typedef union
{
	uint32 REG;
	struct
	{
		uint32 CURRENT : 24;
		uint32 		   : 8;
	} bits;
} SYSTICK_CURRENT_REG_t;

#define STCTRL 							(*((volatile SYSTICK_CTRL_REG_t *)(SYSTICK_BASE + SYSTICK_CTRL_OFFSET)))
#define STRELOAD 						(*((volatile SYSTICK_LOAD_REG_t *)(SYSTICK_BASE + SYSTICK_LOAD_OFFSET)))
#define STCURRENT 						(*((volatile SYSTICK_CURRENT_REG_t *)(SYSTICK_BASE + SYSTICK_VAL_OFFSET)))

// #define STCTRL 						(*((volatile uint32 *)(SYSTICK_BASE + SYSTICK_CTRL_OFFSET)))
// #define STRELOAD 					(*((volatile uint32 *)(SYSTICK_BASE + SYSTICK_LOAD_OFFSET)))
// #define STCURRENT 					(*((volatile uint32 *)(SYSTICK_BASE + SYSTICK_VAL_OFFSET)))

// #define STCTRL_ENABLE_BIT 			0
// #define STCTRL_INTEN_BIT 			1
// #define STCTRL_CLK_SRC_BIT 			2
// #define STCTRL_COUNT_FLAG_BIT 		16
// #define STRELOAD_RELOAD_MASK 		0x00FFFFFF
// #define STCURRENT_CURRENT_MASK 		0x00FFFFFF

#endif /* SYSTICK_MAP_H */