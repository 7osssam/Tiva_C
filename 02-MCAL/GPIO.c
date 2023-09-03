

#include "GPIO.h"
#include "../01-LIB/BIT_MACROS.h"

static void GPIO_unlock(GPIO_Ports_t port)
{
	// Unlock the GPIO_CR register
	*GPIOLOCK[port] = LOCK_KEY;
	// Allow changes on GPIO_CR register
	SET_BIT(*GPIOCR[port], 0);
}

void GPIO_init(const GPIO_Configuration_t *const config_struct)
{
	//**************************** Clock Enable ********************************
	SET_BIT_S(RCGCGPIO, BIT(config_struct->port));
	// delay to make sure that the clock is enabled
	volatile uint32 delay;
	delay = RCGCGPIO;

	//**************************** Unlock GPIO_CR *******************************
	if (config_struct->port == PORTF && config_struct->pin == PIN0) // to avoid unlocking JTAG pins
		GPIO_unlock(config_struct->port);

	//**************************** Analog Mode ********************************
	if (config_struct->analogMode == GPIO_analogEnable)
		SET_BIT(*GPIOAMSEL[config_struct->port], config_struct->pin);
	else
		CLEAR_BIT(*GPIOAMSEL[config_struct->port], config_struct->pin);

	//**************************** Digital Enable *******************************
	if (config_struct->digitalEnable == GPIO_digitalEnable)
		SET_BIT(*GPIODEN[config_struct->port], config_struct->pin);
	else
		CLEAR_BIT(*GPIODEN[config_struct->port], config_struct->pin);

	//**************************** Alternate Function **************************
	if (config_struct->alternateFunction == GPIO_alternateEnable) //!!!!!!!!!!!!!
		SET_BIT(*GPIOAFSEL[config_struct->port], config_struct->pin);
	else
		CLEAR_BIT(*GPIOAFSEL[config_struct->port], config_struct->pin);

	//**************************** Port Control ********************************
	// clear PMCx bits for the selected pin to use it as GPIO pin
	*GPIOPCTL[config_struct->port] &= ~(0xF << (config_struct->pin * 4));

	//**************************** Direction ***********************************
	if (config_struct->direction == GPIO_output)
		SET_BIT(*GPIODIR[config_struct->port], config_struct->pin);
	else
		CLEAR_BIT(*GPIODIR[config_struct->port], config_struct->pin);

	//**************************** Pull Up Resistor ****************************
	if (config_struct->resistor == GPIO_pullupenable)
		SET_BIT(*GPIOPUR[config_struct->port], config_struct->pin);
	else
		CLEAR_BIT(*GPIOPUR[config_struct->port], config_struct->pin);
}

void GPIO_setDirection(GPIO_Ports_t port, GPIO_Pins_t pin, GPIO_PinDirection_t direction)
{
	if (direction == GPIO_output)
		SET_BIT(*GPIODIR[port], pin);
	else
		CLEAR_BIT(*GPIODIR[port], pin);
}

void GPIO_WritePin(GPIO_Ports_t port, GPIO_Pins_t pin, GPIO_PinState_t state)
{
	if (state == GPIO_high)
		SET_BIT(*GPIODATA[port], pin);
	else
		CLEAR_BIT(*GPIODATA[port], pin);
}

GPIO_PinState_t GPIO_ReadPin(GPIO_Ports_t port, GPIO_Pins_t pin)
{
	return READ_BIT(*GPIODATA[port], pin);
}

void GPIO_TogglePin(GPIO_Ports_t port, GPIO_Pins_t pin)
{
	TOGGLE_BIT(*GPIODATA[port], pin);
}

void GPIO_IntEnable(GPIO_Ports_t port, GPIO_Pins_t pin)
{
	SET_BIT(*GPIOIM[port], pin);
}
void GPIO_IntDisable(GPIO_Ports_t port, GPIO_Pins_t pin)
{
	CLEAR_BIT(*GPIOIM[port], pin);
}

void GPIO_IntClear(GPIO_Ports_t port, GPIO_Pins_t pin)
{
	SET_BIT(*GPIOICR[port], pin);
}
void GPIO_IntSense(GPIO_Ports_t port, GPIO_Pins_t pin, GPIO_InterruptSense_t sense)
{
	if (sense == GPIO_edgeSensetive)
		SET_BIT(*GPIOIS[port], pin);
	else
		CLEAR_BIT(*GPIOIS[port], pin);
}
void GPIO_IntEdgeSelection(GPIO_Ports_t port, GPIO_Pins_t pin, GPIO_InterruptLevel_t edge)
{
	if (edge == GPIO_bothEdges)
	{
		SET_BIT(*GPIOIBE[port], pin);
	}
	else
	{
		CLEAR_BIT(*GPIOIBE[port], pin);

		if (edge == GPIO_fallingEdge)
			CLEAR_BIT(*GPIOIEV[port], pin);
		else
			SET_BIT(*GPIOIEV[port], pin);
	}
}
void GPIO_IntMask(GPIO_Ports_t port, GPIO_Pins_t pin, GPIO_InterruptMask_t mask)
{
	if (mask == GPIO_maskInterrupt)
		SET_BIT(*GPIOIM[port], pin);
	else
		CLEAR_BIT(*GPIOIM[port], pin);
}
GPIO_InterruptStatus_t GPIO_INTRIS(GPIO_Ports_t port, GPIO_Pins_t pin)
{
	return READ_BIT(*GPIORIS[port], pin);
}
GPIO_InterruptStatus_t GPIO_INTMIS(GPIO_Ports_t port, GPIO_Pins_t pin)
{
	return READ_BIT(*GPIOMIS[port], pin);
}