
#include "SysTick_map.h"

#include "sysTick.h"

// using SET_BIT and CLEAR_BIT macros
void SysTick_init(SysTick_ConfigType *Config_Ptr)
{
	//// disable systick
	// CLEAR_BIT(STCTRL, STCTRL_ENABLE_BIT);

	///* Set clock source
	// * 0: PIOSC/4
	// * 1: System Clock */
	// STCTRL |= (Config_Ptr->ClkSrc << STCTRL_CLK_SRC_BIT);

	///* Set reload value */
	// STRELOAD = Config_Ptr->ReloadValue - 1;

	///* Set interrupt enable
	// * 0: Disable
	// * 1: Enable */
	// STCTRL |= (Config_Ptr->Int << STCTRL_INTEN_BIT);

	//// enable systick
	// SET_BIT(STCTRL, STCTRL_ENABLE_BIT);

	// disable systick
	STCTRL.bits.ENABLE = 0;

	/* Set clock source
	 * 0: PIOSC/4
	 * 1: System Clock */
	STCTRL.bits.CLK_SRC = Config_Ptr->ClkSrc;

	/* Set reload value */
	STRELOAD.bits.RELOAD = Config_Ptr->ReloadValue - 1;

	/* Set interrupt enable
	 * 0: Disable
	 * 1: Enable */
	STCTRL.bits.INTEN = Config_Ptr->Int;

	// enable systick
	STCTRL.bits.ENABLE = 1;
}
