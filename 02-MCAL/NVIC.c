
#include "NVIC.h"
#include "NVIC_map.h"
#include "../01-LIB/BIT_MACROS.h"
/********************************************************************************************************************
 *                                    LOCAL MACROS CONSTANT\FUNCTION                                                 *
 *********************************************************************************************************************/

/*Preprocessor Macro To Enable interrupts and show which interrupts Through ENn Reg*/
//#define IRQ_SET_ENABLE(ENn, IRQ_BIT) (*(ENABLE_REG_BASE + ENn) |= (1 << IRQ_BIT))
#define ENABLE_REG(ENn) (*(ENABLE_REG_BASE + ENn))
#define IRQ_SET_ENABLE(ENn, IRQ_BIT)  ( SET_BIT(ENABLE_REG(ENn), IRQ_BIT) )


/*Preprocessor Macro To Disable interrupts and show which interrupts Through DISn Reg*/
//#define IRQ_SET_DISABLE(DISn, IRQ_BIT) (*(DISABLE_REG_BASE + DISn) |= (1 << IRQ_BIT))
#define DISABLE_REG(DISn) (*(DISABLE_REG_BASE + DISn))
#define IRQ_SET_DISABLE(DISn, IRQ_BIT)  ( SET_BIT(DISABLE_REG(DISn), IRQ_BIT) )


/*Preprocessor Macro To force interrupts into the pending state Through PENDn Reg*/
//#define IRQ_SET_PENDING(PENDn, IRQ_BIT) (*(PEND_REG_BASE + PENDn) |= (1 << IRQ_BIT))
#define PEND_REG(PENDn) (*(PEND_REG_BASE + PENDn))
#define IRQ_SET_PENDING(PENDn, IRQ_BIT)  ( SET_BIT(PEND_REG(PENDn), IRQ_BIT) )

/*Preprocessor Macro remove the pending state from interrupts through UNPENDn reg*/
//#define IRQ_CLEAR_PENDING(UNPENDn, IRQ_BIT) (*(UNPEND_REG_BASE + UNPENDn) |= (1 << IRQ_BIT))
#define UNPEND_REG(UNPENDn) (*(UNPEND_REG_BASE + UNPENDn))
#define IRQ_CLEAR_PENDING(UNPENDn, IRQ_BIT)  ( SET_BIT(UNPEND_REG(UNPENDn), IRQ_BIT) )

/*Preprocessor Macro To Trigger interrupts By Software*/
#define IRQ_TRIGGER(IRQ_ID) (SWTRIG = IRQ_ID)

/*Preprocessor Macro  To Acess PRIn Reg*/
#define PRI_REG(PRIn) (PRIORITY_REG_BASE + PRIn)

/**********************************************************************************************************************
 *                                                  LOCAL DATA                                                        *
 *********************************************************************************************************************/
/*global Arr To Hold Intx (INTA-INTB-INTC-INTD) Mask Values in PRI Register*/
static const uint32 g_IntXPriorityMask[4] = {INTA_MASK, INTB_MASK, INTC_MASK, INTD_MASK};

/*global Arr To Hold Intx (INTA-INTB-INTC-INTD) shift Values in PRI Register*/
static const uint8 g_IntXPriorityShift[4] = {INTA_SHIFT, INTB_SHIFT, INTC_SHIFT, INTD_SHIFT};

/******************************************************************************
 * \Syntax          : void NVIC_Init(const NVIC_ConfigType * configPtr)
 * \Description     : Function To Init NVIC Module
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void NVIC_Init(const NVIC_ConfigType *configPtr)
{
	uint32 ENn;
	uint32 irqEnOffset;
	uint32 PRIn;
	uint32 irqPriOffset;
	uint32 totalPriority;

	/*Get Offset Of ENn Register Which Irq resident in */
	ENn = configPtr->irqNum / 32;

	/*Get Offset Of irqNum in ENn Register */
	irqEnOffset = configPtr->irqNum % 32;

	/*Enable Interrupt*/
	IRQ_SET_ENABLE(ENn, irqEnOffset);

	/*Get Offset Of PRIn Register Which Irq resident in */
	PRIn = configPtr->irqNum / NVIC_PRIORITY_FIELDS_PER_REG;

	/*Get Offset Of irqNum in PRIn Register (INTA/INTB/INTC/INTD) */
	irqPriOffset = configPtr->irqNum % NVIC_PRIORITY_FIELDS_PER_REG;

	/*Caclulate Total Priority For Irq*/
	// totalPriority = g_NVICConfiguration[itr].groupPriority | g_NVICConfiguration[itr].subGroupPriority;
	totalPriority = configPtr->groupPriority | configPtr->subGroupPriority;

	/*Make Sure That Total Priority Doesnot Exceed 3 Bits*/
	totalPriority &= 0x00000007;

	/*Set Irq Priority According TO PRiority Grouping System In APINT Reg*/
	*PRI_REG(PRIn) = ((*PRI_REG(PRIn)) & ~g_IntXPriorityMask[irqPriOffset]) | (totalPriority << g_IntXPriorityShift[irqPriOffset]);
}

/******************************************************************************
 * \Syntax          : void NVIC_IrqSetPending(NVIC_IrqNumberType irqNum)
 * \Description     : Force interrupts into the pending state
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): irqNum : Interrupt Request ID
 * \Return value:   : None
 *******************************************************************************/
void NVIC_IrqSetPending(NVIC_IrqNumberType irqNum)
{
	uint32 PENDn;
	uint32 irqPendOffset;

	/*Get Offset Of PENDn Register Which Irq resident in */
	PENDn = irqNum / 32;

	/*Get Offset Of irqNum in PENDn Register */
	irqPendOffset = irqNum % 32;

	/*Force interrupts into the pending state*/
	IRQ_SET_PENDING(PENDn, irqPendOffset);
}

/******************************************************************************
 * \Syntax          : void NVIC_IrqClearPending(NVIC_IrqNumberType irqNum)
 * \Description     : remove the pending state from interrupts
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): irqNum : Interrupt Request ID
 * \Return value:   : None
 *******************************************************************************/
void NVIC_IrqClearPending(NVIC_IrqNumberType irqNum)
{
	uint32 UNPENDn;
	uint32 irqUnPendOffset;

	/*Get Offset Of UNPENDn Register Which Irq resident in */
	UNPENDn = irqNum / 32;

	/*Get Offset Of irqNum in UNPENDn Register */
	irqUnPendOffset = irqNum % 32;

	/* remove the pending state from interrupts through UNPENDn reg*/
	IRQ_CLEAR_PENDING(UNPENDn, irqUnPendOffset);
}
/******************************************************************************
 * \Syntax          : void NVIC_IrqSetEnable(NVIC_IrqNumberType irqNum)
 * \Description     : Enable Interrupt Request
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): irqNum : Interrupt Request ID
 * \Return value:   : None
 *******************************************************************************/
void NVIC_IrqSetEnable(NVIC_IrqNumberType irqNum)
{
	uint32 ENn;
	uint32 irqEnOffset;
	/*Get Offset Of ENn Register Which Irq resident in */
	ENn = irqNum / 32;

	/*Get Offset Of irqNum in ENn Register */
	irqEnOffset = irqNum % 32;

	/*Enable Interrupt*/
	IRQ_SET_ENABLE(ENn, irqEnOffset);
}
/******************************************************************************
 * \Syntax          : void NVIC_IrqSetDisable(NVIC_IrqNumberType irqNum)
 * \Description     : Disable Interrupt Request
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): irqNum : Interrupt Request ID
 * \Return value:   : None
 *******************************************************************************/
void NVIC_IrqSetDisable(NVIC_IrqNumberType irqNum)
{
	uint32 DISn;
	uint32 irqDisOffset;

	DISn = irqNum / 32;
	irqDisOffset = irqNum % 32;
	IRQ_SET_PENDING(DISn, irqDisOffset);
}