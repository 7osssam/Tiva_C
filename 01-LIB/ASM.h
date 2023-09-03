/**********************************************************************************************
 * File name        : ASM.h
 * Description      : This file provides declarations of the ASM functions.
 * Notes            : for ARM Cortex-M4 microcontrollers using IAR tools
 * Creator          : Hossam Mohamed
 **********************************************************************************************/

#ifndef ASM_H
#define ASM_H

/* Enable Exceptions ... This Macro enables IRQ interrupts, Programmable Systems Exceptions, and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions() __asm("CPSIE I")

/* Disable Exceptions ... This Macro disables IRQ interrupts, Programmable Systems Exceptions, and Faults by setting the I-bit in the PRIMASK. */
#define Disable_Exceptions() __asm("CPSID I")

/* Enable Faults ... This Macro enables Faults by clearing the F-bit in the FAULTMASK. */
#define Enable_Faults() __asm("CPSIE F")

/* Disable Faults ... This Macro disables Faults by setting the F-bit in the FAULTMASK. */
#define Disable_Faults() __asm("CPSID F")

/* Go to low-power mode while waiting for the next interrupt. */
#define Wait_For_Interrupt() __asm("WFI")

#endif /* ASM_H */
