/******************************************************************
 * @Title : General Purpose Input Output (GPIO) Driver
 * @Filename : GPIO.h
 * @Author : Hossam Mohamed
 * @Compiler : IAR
 * @Target : Tiva-C (Tm4c123gh6pm)
 * @Notes : this file contains prototypes for gpio module functions
 ********************************************************************/
#ifndef GPIO_H_
#define GPIO_H_

#include "GPIO_map.h"

#include "../01-LIB/STD_TYPES.h"

#define LOCK_KEY 0x4C4F434B

/****************************************************************************************
 *   						   User Defined Data Types								    *
 ****************************************************************************************/
typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF
} GPIO_Ports_t;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
} GPIO_Pins_t;

typedef enum
{
	GPIO_low,
	GPIO_high
} GPIO_PinState_t;

typedef enum
{
	GPIO_input,
	GPIO_output
} GPIO_PinDirection_t;

typedef enum
{
	GPIO_pullupdisable,
	GPIO_pullupenable
} GPIO_PullupResistors_t;

typedef enum
{
	GPIO_digitalDisable,
	GPIO_digitalEnable
} GPIO_DigitalEnable_t;

typedef enum
{
	GPIO_analogDisable,
	GPIO_analogEnable
} GPIO_AnalogMode_t;

typedef enum
{
	GPIO_alternateDisable,
	GPIO_alternateEnable
} GPIO_AlternateFunction_t;

//*********************************************************************************
//                                  GPIO Interrupts
//********************************************************************************

/**
 *Defining Interrupt status of a GPIO pin
 */
typedef enum
{
	GPIO_noInterrupt,		/**<No interrupt is active corresponding to that GPIO pin*/
	GPIO_triggeredInterrupt /**<An interrupt is active corresponding to that GPIO pin*/
} GPIO_InterruptStatus_t;

/**
 * Defining Type of signal to fire an interrupt on a GPIO pin
 */
typedef enum
{
	GPIO_edgeSensetive, /**<set GPIO to detect edge  of any signal on it's pin to generate an interrupt*/
	GPIO_levelSensetive /**<set GPIO to detect Level of any signal on it's pin to generate an interrupt*/
} GPIO_InterruptSense_t;

/**
 * Defining which signal edge to cause an interrupt if GPIO pin configured as an edge triggered
 */
typedef enum
{
	GPIO_fallingEdge, /**< interrupt is triggred on falling edge of signal*/
	GPIO_risingEdge,  /**<interrupt is triggered on rising edge of signal*/
	GPIO_bothEdges	  /**<Interrupt occur on any edge change*/
} GPIO_InterruptLevel_t;

/**
 * Defining Interrupt Mask
 */
typedef enum
{
	GPIO_maskInterrupt,	 /**<mask the Activated interrupt*/
	GPIO_trggerInterrupt /**<send the interrupt signal to the NVIC*/
} GPIO_InterruptMask_t;

//*********************************************************************************
//                             Configuration Table structure
//*********************************************************************************

/**
 * This is the configuration table structure that will be used
 * to set the configuration parameter of every GPIO pin by defining
 * evey entry in this structure to a specific pin and pass this table to initializing function
 */
typedef struct
{
	GPIO_Ports_t port;
	GPIO_Pins_t pin;
	GPIO_PinDirection_t direction;
	GPIO_PullupResistors_t resistor;
	GPIO_DigitalEnable_t digitalEnable;
	GPIO_AnalogMode_t analogMode;
	GPIO_AlternateFunction_t alternateFunction;
} GPIO_Configuration_t;

void GPIO_init(const GPIO_Configuration_t *const cnfg_table);
void GPIO_setDirection(GPIO_Ports_t port, GPIO_Pins_t pin, GPIO_PinDirection_t direction);

void GPIO_WritePin(GPIO_Ports_t port, GPIO_Pins_t pin, GPIO_PinState_t state);
GPIO_PinState_t GPIO_ReadPin(GPIO_Ports_t port, GPIO_Pins_t pin);
void GPIO_TogglePin(GPIO_Ports_t port, GPIO_Pins_t pin);

void GPIO_IntEnable(GPIO_Ports_t port, GPIO_Pins_t pin);
void GPIO_IntDisable(GPIO_Ports_t port, GPIO_Pins_t pin);

void GPIO_IntClear(GPIO_Ports_t port, GPIO_Pins_t pin);

void GPIO_IntSense(GPIO_Ports_t port, GPIO_Pins_t pin, GPIO_InterruptSense_t sense);
void GPIO_IntEdgeSelection(GPIO_Ports_t port, GPIO_Pins_t pin, GPIO_InterruptLevel_t edge);
void GPIO_IntMask(GPIO_Ports_t port, GPIO_Pins_t pin, GPIO_InterruptMask_t mask);

GPIO_InterruptStatus_t GPIO_INTRIS(GPIO_Ports_t port, GPIO_Pins_t pin);
GPIO_InterruptStatus_t GPIO_INTMIS(GPIO_Ports_t port, GPIO_Pins_t pin);
#endif /* GPIO_H_ */