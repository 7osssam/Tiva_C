#ifndef CORE_MAP_H_
#define CORE_MAP_H_

#include "../01-LIB/BIT_MACROS.h"
#include "../01-LIB/STD_TYPES.h"


// TM4C123GH6PM Datasheet : Page 134:137 (Table 3-8)
/*****************************************************************************************************
 *                                     Core Peripheral Registers                                     *
 *****************************************************************************************************
 * offset           Name                    Description                                              *
 ********************************** System Timer (SysTick) Registers *********************************
 * 0x010           STCTRL                  SysTick Control and Status                       		 *
 * 0x014           STRELOAD                SysTick Reload Value                             		 *
 * 0x018           STCURRENT               SysTick Current Value                            		 *
 ************************** Nested Vectored Interrupt Controller (NVIC) Registers ********************
 * 0x100           EN0                     Interrupt 0-31 Set Enable                        		 *
 * 0x104           EN1                     Interrupt 32-63 Set Enable                       		 *
 * 0x108           EN2                     Interrupt 64-95 Set Enable                       		 *
 * 0x10C           EN3                     Interrupt 96-127 Set Enable                      		 *
 * 0x110           EN4                     Interrupt 128-138 Set Enable                     		 *
 * 0x180           DIS0                    Interrupt 0-31 Clear Enable                      		 *
 * 0x184           DIS1                    Interrupt 32-63 Clear Enable                     		 *
 * 0x188           DIS2                    Interrupt 64-95 Clear Enable                     		 *
 * 0x18C           DIS3                    Interrupt 96-127 Clear Enable                    		 *
 * 0x190           DIS4                    Interrupt 128-138 Clear Enable                   		 *
 * 0x200           PEND0                   Interrupt 0-31 Set Pending                       		 *
 * 0x204           PEND1                   Interrupt 32-63 Set Pending                      		 *
 * 0x208           PEND2                   Interrupt 64-95 Set Pending                      		 *
 * 0x20C           PEND3                   Interrupt 96-127 Set Pending                     		 *
 * 0x210           PEND4                   Interrupt 128-138 Set Pending                    		 *
 * 0x280           UNPEND0                 Interrupt 0-31 Clear Pending                     		 *
 * 0x284           UNPEND1                 Interrupt 32-63 Clear Pending                    		 *
 * 0x288           UNPEND2                 Interrupt 64-95 Clear Pending                    		 *
 * 0x28C           UNPEND3                 Interrupt 96-127 Clear Pending                   		 *
 * 0x290           UNPEND4                 Interrupt 128-138 Clear Pending                  		 *
 * 0x300           ACTIVE0                 Interrupt 0-31 Active Bit                        		 *
 * 0x304           ACTIVE1                 Interrupt 32-63 Active Bit                       		 *
 * 0x308           ACTIVE2                 Interrupt 64-95 Active Bit                       		 *
 * 0x30C           ACTIVE3                 Interrupt 96-127 Active Bit                      		 *
 * 0x310           ACTIVE4                 Interrupt 128-138 Active Bit                     		 *
 * 0x400           PRI0                    Interrupt 0-3 Priority                          		 	 *
 * 0x404           PRI1                    Interrupt 4-7 Priority                          		 	 *
 * 0x408           PRI2                    Interrupt 8-11 Priority                         		 	 *
 * 0x40C           PRI3                    Interrupt 12-15 Priority                        		 	 *
 * 0x410           PRI4                    Interrupt 16-19 Priority                        		 	 *
 * 0x414           PRI5                    Interrupt 20-23 Priority                        		 	 *
 * 0x418           PRI6                    Interrupt 24-27 Priority                        		 	 *
 * 0x41C           PRI7                    Interrupt 28-31 Priority                        		 	 *
 * 0x420           PRI8                    Interrupt 32-35 Priority                        		 	 *
 * 0x424           PRI9                    Interrupt 36-39 Priority                        		 	 *
 * 0x428           PRI10                   Interrupt 40-43 Priority                        		 	 *
 * 0x42C           PRI11                   Interrupt 44-47 Priority                        		 	 *
 * 0x430           PRI12                   Interrupt 48-51 Priority                        		 	 *
 * 0x434           PRI13                   Interrupt 52-55 Priority                        		 	 *
 * 0x438           PRI14                   Interrupt 56-59 Priority                        		 	 *
 * 0x43C           PRI15                   Interrupt 60-63 Priority                        		 	 *
 * 0x440           PRI16                   Interrupt 64-67 Priority                        		 	 *
 * 0x444           PRI17                   Interrupt 68-71 Priority                        		 	 *
 * 0x448           PRI18                   Interrupt 72-75 Priority                        		 	 *
 * 0x44C           PRI19                   Interrupt 76-79 Priority                        		 	 *
 * 0x450           PRI20                   Interrupt 80-83 Priority                        		 	 *
 * 0x454           PRI21                   Interrupt 84-87 Priority                        		 	 *
 * 0x458           PRI22                   Interrupt 88-91 Priority                        		 	 *
 * 0x45C           PRI23                   Interrupt 92-95 Priority                        		 	 *
 * 0x460           PRI24                   Interrupt 96-99 Priority                        		 	 *
 * 0x464           PRI25                   Interrupt 100-103 Priority                      		 	 *
 * 0x468           PRI26                   Interrupt 104-107 Priority                      		 	 *
 * 0x46C           PRI27                   Interrupt 108-111 Priority                      		 	 *
 * 0x470           PRI28                   Interrupt 112-115 Priority                      		 	 *
 * 0x474           PRI29                   Interrupt 116-119 Priority                      		 	 *
 * 0x478           PRI30                   Interrupt 120-123 Priority                      		 	 *
 * 0x47C           PRI31                   Interrupt 124-127 Priority                      		 	 *
 * 0x480           PRI32                   Interrupt 128-131 Priority                      		 	 *
 * 0x484           PRI33                   Interrupt 132-135 Priority                      		 	 *
 * 0x488           PRI34                   Interrupt 136-138 Priority                      		 	 *
 * 0xF00           SWTRIG                  Software Trigger Interrupt              		 	 		 *
 ************************** System Control (SCB) Registers *******************************************
 * 0x008           ACTLR                   Auxiliary Control                        		 		 *
 * 0xD00           CPUID                   CPUID Base                               		 		 *
 * 0xD04           INTCTRL                 Interrupt Control and State              		 		 *
 * 0xD08           VTABLE                  Vector Table Offset                      		 		 *
 * 0xD0C           APINT                   Application Interrupt and Reset Control  		 		 *
 * 0xD10           SYSCTRL                 System Control                           		 		 *
 * 0xD14           CFGCTRL                 Configuration Control                    		 		 *
 * 0xD18           SYSPRI1                 System Handler Priority  1               		 		 *
 * 0xD1C           SYSPRI2                 System Handler Priority  2               		 		 *
 * 0xD20           SYSPRI3                 System Handler Priority  3               		 		 *
 * 0xD24           SYSHNDCTRL              System Handler Control and State         		 		 *
 * 0xD28           FAULTSTAT               Configurable Fault Status                		 		 *
 * 0xD2C           HFAULTSTAT              Hard Fault Status                        		 		 *
 * 0xD34		   MMADDR                  MemManage Fault Address                  		 		 *
 * 0xD38           FAULTADDR               Bus Fault Address                        		 		 *
 ************************** Memory Protection Unit (MPU) Registers ***********************************
 * 0xD90           MPUTYPE                 MPU Type                                 		 		 *
 * 0xD94           MPUCTRL                 MPU Control                              		 		 *
 * 0xD98           MPUNUMBER               MPU Region Number                        		 		 *
 * 0xD9C           MPUBASE                 MPU Region Base Address                  		 		 *
 * 0xDA0           MPUATTR                 MPU Region Attribute and Size            		 		 *
 * 0xDA4           MPUBASE1                MPU Region Base Address  1               		 		 *
 * 0xDA8           MPUATTR1                MPU Region Attribute and Size  1         		 		 *
 * 0xDAC           MPUBASE2                MPU Region Base Address  2               		 		 *
 * 0xDB0           MPUATTR2                MPU Region Attribute and Size  2         		 		 *
 * 0xDB4           MPUBASE3                MPU Region Base Address  3               		 		 *
 * 0xDB8           MPUATTR3                MPU Region Attribute and Size  3         		 		 *
 * 0xDBC           MPUBASE4                MPU Region Base Address  4               		 		 *
 ************************** Floating Point Unit (FPU) Registers **************************************
 * 0xD88           CPAC                    Coprocessor Access Control               		 		 *
 * 0xF34           FPCCR                   Floating-Point Context Control           		 		 *
 * 0xF38           FPCAR                   Floating-Point Context Address           		 		 *
 * 0xF3C           FPDSCR                  Floating-Point Default Status Control    		 		 *
 * 0xF40           MVFR0                   Media and FP Feature  0                  		 		 *
 *****************************************************************************************************/

/* Core Peripheral Base Address */
#define CORE_PERI_BASE_ADDRESS  0xE000E000

/* System Timer (SysTick) Registers offset */
#define STCTRL_OFFSET 			0x010
#define STRELOAD_OFFSET 		0x014
#define STCURRENT_OFFSET 		0x018

/* Nested Vectored Interrupt Controller (NVIC) Registers offset */
#define EN0_OFFSET 				0x100
#define EN1_OFFSET 				0x104
#define EN2_OFFSET 				0x108
#define EN3_OFFSET 				0x10C
#define EN4_OFFSET 				0x110
#define DIS0_OFFSET 			0x180
#define DIS1_OFFSET 			0x184
#define DIS2_OFFSET 			0x188
#define DIS3_OFFSET 			0x18C
#define DIS4_OFFSET 			0x190
#define PEND0_OFFSET 			0x200
#define PEND1_OFFSET 			0x204
#define PEND2_OFFSET 			0x208
#define PEND3_OFFSET 			0x20C
#define PEND4_OFFSET 			0x210
#define UNPEND0_OFFSET 			0x280
#define UNPEND1_OFFSET 			0x284
#define UNPEND2_OFFSET 			0x288
#define UNPEND3_OFFSET 			0x28C
#define UNPEND4_OFFSET 			0x290
#define ACTIVE0_OFFSET 			0x300
#define ACTIVE1_OFFSET 			0x304
#define ACTIVE2_OFFSET 			0x308
#define ACTIVE3_OFFSET 			0x30C
#define ACTIVE4_OFFSET 			0x310
#define PRI0_OFFSET 			0x400
#define PRI1_OFFSET 			0x404
#define PRI2_OFFSET 			0x408
#define PRI3_OFFSET 			0x40C
#define PRI4_OFFSET 			0x410
#define PRI5_OFFSET 			0x414
#define PRI6_OFFSET 			0x418
#define PRI7_OFFSET 			0x41C
#define PRI8_OFFSET 			0x420
#define PRI9_OFFSET 			0x424
#define PRI10_OFFSET 			0x428
#define PRI11_OFFSET 			0x42C
#define PRI12_OFFSET 			0x430
#define PRI13_OFFSET 			0x434
#define PRI14_OFFSET 			0x438
#define PRI15_OFFSET 			0x43C
#define PRI16_OFFSET 			0x440
#define PRI17_OFFSET 			0x444
#define PRI18_OFFSET 			0x448
#define PRI19_OFFSET 			0x44C
#define PRI20_OFFSET 			0x450
#define PRI21_OFFSET 			0x454
#define PRI22_OFFSET 			0x458
#define PRI23_OFFSET 			0x45C
#define PRI24_OFFSET 			0x460
#define PRI25_OFFSET 			0x464
#define PRI26_OFFSET 			0x468
#define PRI27_OFFSET 			0x46C
#define PRI28_OFFSET 			0x470
#define PRI29_OFFSET 			0x474
#define PRI30_OFFSET 			0x478
#define PRI31_OFFSET 			0x47C
#define PRI32_OFFSET 			0x480
#define PRI33_OFFSET 			0x484
#define PRI34_OFFSET 			0x488
#define SWTRIG_OFFSET 			0xF00

/* System Control (SCB) Registers offset */
#define ACTLR_OFFSET 			0x008
#define CPUID_OFFSET 			0xD00
#define INTCTRL_OFFSET 			0xD04
#define VTABLE_OFFSET 			0xD08
#define APINT_OFFSET 			0xD0C
#define SYSCTRL_OFFSET 			0xD10
#define CFGCTRL_OFFSET 			0xD14
#define SYSPRI1_OFFSET 			0xD18
#define SYSPRI2_OFFSET 			0xD1C
#define SYSPRI3_OFFSET 			0xD20
#define SYSHNDCTRL_OFFSET 		0xD24
#define FAULTSTAT_OFFSET 		0xD28
#define HFAULTSTAT_OFFSET 		0xD2C
#define MMADDR_OFFSET 			0xD34
#define FAULTADDR_OFFSET 		0xD38

/* Memory Protection Unit (MPU) Registers offset */
#define MPUTYPE_OFFSET 			0xD90
#define MPUCTRL_OFFSET 			0xD94
#define MPUNUMBER_OFFSET 		0xD98
#define MPUBASE_OFFSET 			0xD9C
#define MPUATTR_OFFSET 			0xDA0
#define MPUBASE1_OFFSET 		0xDA4
#define MPUATTR1_OFFSET 		0xDA8
#define MPUBASE2_OFFSET 		0xDAC
#define MPUATTR2_OFFSET 		0xDB0
#define MPUBASE3_OFFSET 		0xDB4
#define MPUATTR3_OFFSET 		0xDB8
#define MPUBASE4_OFFSET 		0xDBC


/* Floating Point Unit (FPU) Registers offset */
#define CPAC_OFFSET 			0xD88
#define FPCCR_OFFSET 			0xF34
#define FPCAR_OFFSET 			0xF38
#define FPDSCR_OFFSET 			0xF3C
#define MVFR0_OFFSET 			0xF40


/* System Timer (SysTick) Registers Structure */

/************************************************************************************************
 * 						 SysTick Control and Status Register (STCTRL) 							*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:17           Reserved           RO                    Reserved
 * 16              COUNT 		      RO                    Count Flag
 * 15:3 		   Reserved           RO                    Reserved
 * 2 			   CLK_SRC 		      RW                    Clock Source
 * 1 			   INTEN 			  RW                    Interrupt Enable
 * 0 			   ENABLE 			  RW                    Counter Enable
 * ==============================================================================================*/
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


/************************************************************************************************
 * 						 SysTick Reload Value Register (STRELOAD) 								*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:24           Reserved           RO                    Reserved
 * 23:0            RELOAD 		      RW                    RELOAD Value
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 RELOAD : 24;
		uint32 		  : 8;
	} bits;
} SYSTICK_LOAD_REG_t;


/************************************************************************************************
 * 						 SysTick Current Value Register (STCURRENT) 							*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:24           Reserved           RO                    Reserved
 * 23:0            CURRENT 		      RWC                   CURRENT Value
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 CURRENT : 24;
		uint32 		   : 8;
	} bits;
} SYSTICK_CURRENT_REG_t;


#define STCTRL 					(*((volatile SYSTICK_CTRL_REG_t *)(CORE_PERI_BASE_ADDRESS + SYSTICK_CTRL_OFFSET)))
#define STRELOAD 				(*((volatile SYSTICK_LOAD_REG_t *)(CORE_PERI_BASE_ADDRESS + SYSTICK_LOAD_OFFSET)))
#define STCURRENT 				(*((volatile SYSTICK_CURRENT_REG_t *)(CORE_PERI_BASE_ADDRESS + SYSTICK_VAL_OFFSET)))


/* Nested Vectored Interrupt Controller (NVIC) Registers Structure */

/*Preprocessor Macro To Enable interrupts and show which interrupts Through ENn Reg*/
//#define IRQ_SET_ENABLE(ENn, IRQ_BIT) (*(ENABLE_REG_BASE + ENn) |= (1 << IRQ_BIT))
#define ENABLE_REG(ENn) (*( CORE_PERI_BASE_ADDRESS + EN0_OFFSET) + ENn)
#define IRQ_SET_ENABLE(ENn, IRQ_BIT)  ( SET_BIT(ENABLE_REG(ENn), IRQ_BIT) )

/*Preprocessor Macro To Disable interrupts and show which interrupts Through DISn Reg*/
//#define IRQ_SET_DISABLE(DISn, IRQ_BIT) (*(DISABLE_REG_BASE + DISn) |= (1 << IRQ_BIT))
#define DISABLE_REG(DISn) (*( CORE_PERI_BASE_ADDRESS + DIS0_OFFSET) + DISn)
#define IRQ_SET_DISABLE(DISn, IRQ_BIT)  ( SET_BIT(DISABLE_REG(DISn), IRQ_BIT) )

/*Preprocessor Macro To force interrupts into the pending state Through PENDn Reg*/
//#define IRQ_SET_PENDING(PENDn, IRQ_BIT) (*(PEND_REG_BASE + PENDn) |= (1 << IRQ_BIT))
#define PEND_REG(PENDn) (*( CORE_PERI_BASE_ADDRESS + PEND0_OFFSET) + PENDn)
#define IRQ_SET_PENDING(PENDn, IRQ_BIT)  ( SET_BIT(PEND_REG(PENDn), IRQ_BIT) )

/*Preprocessor Macro remove the pending state from interrupts through UNPENDn reg*/
//#define IRQ_CLEAR_PENDING(UNPENDn, IRQ_BIT) (*(UNPEND_REG_BASE + UNPENDn) |= (1 << IRQ_BIT))
#define UNPEND_REG(UNPENDn) (*(UNPEND_REG_BASE + UNPENDn))
#define IRQ_CLEAR_PENDING(UNPENDn, IRQ_BIT)  ( SET_BIT(UNPEND_REG(UNPENDn), IRQ_BIT) )

/*Preprocessor Macro To Trigger interrupts By Software*/
//#define IRQ_TRIGGER(IRQ_ID) (SWTRIG = IRQ_ID)
#define SWTRIG_REG  (*( CORE_PERI_BASE_ADDRESS + SWTRIG_OFFSET))
#define IRQ_TRIGGER(IRQ_ID)  ( SWTRIG_REG = IRQ_ID )

/*Preprocessor Macro  To Acess PRIn Reg*/
//#define PRI_REG(PRIn) (PRIORITY_REG_BASE + PRIn)
#define PRI_REG(PRIn) (*( CORE_PERI_BASE_ADDRESS + PRI0_OFFSET) + PRIn)




/* System Control (SCB) Registers Structure */

/************************************************************************************************
 * 						 Auxiliary Control Register (ACTLR) 									*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:10		   Reserved           RO                    Reserved
 * 9               DISOOFP 		  	  RW                    Disable Out-of-Order Floating-Point
 * 8               DISFPCA 		      RW                    Disable CONTROL Register Write to Fault
 * 7:3 		   	   Reserved           RO                    Reserved
 * 2			   DISFOLD 		      RW                    Disable Folding of IT Instructions
 * 1			   DISWBUF 		      RW                    Disable Write Buffer
 * 0			   DISMCYC 		      RW                    Disable Interrupts as NMI Sources
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 DISMCYC: 1;
		uint32 DISWBUF: 1;
		uint32 DISFOLD: 1;
		uint32 		  : 5;
		uint32 DISFPCA: 1;
		uint32 DISOOFP: 1;
		uint32 		  : 22;
	} bits;
} ACTLR_REG_t;


/************************************************************************************************
 * 						 CPU ID Base Register (CPUID) 											*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:24		   IMP 			      RO                    Implementer Code
 * 23:20		   VAR 			      RO                    Variant Number
 * 19:16		   CON 			      RO                    Constant
 * 15:4 		   PARTNO 		      RO                    Part Number of the Processor
 * 3:0 			   REV 			      RO                    Revision Number
 * 
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 REV 	 : 4;
		uint32 PARTNO: 12;
		uint32 CON 	 : 4;
		uint32 VAR 	 : 4;
		uint32 IMP 	 : 8;
	} bits;
} CPUID_REG_t;

/************************************************************************************************
 * 						 Interrupt Control and State Register (INTCTRL) 						*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31			   NMISET 			  RW                    NMI Set Pending
 * 30:29 		   Reserved           RO                    Reserved
 * 28			   PENDSV 			  RW                    PendSV Set Pending
 * 27			   UNPENDSV 		  WO                    PendSV Clear Pending 
 * 26			   PENDSTSET 		  RW                    SysTick Set Pending
 * 25			   PENDSTCLR 		  WO                    SysTick Clear Pending
 * 24 			   reserved 		  RO                    Reserved
 * 23			   ISRPRE 			  RW                    Debug Interrupt Handling
 * 22			   ISRPEND 			  RO                    Interrupt Pending Flag
 * 21:20 		   Reserved           RO                    Reserved
 * 19:12 		   VECPEND 			  RO                    Interrupt Pending Vector Number
 * 11 			   RETBASE 			  RO                    Return to Base Level
 * 10:8 		   Reserved           RO                    Reserved
 * 7:0 			   VECACT 			  RO                    Active Vector Number (look Page 162)
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 VECACT 	: 8;
		uint32 			: 3;
		uint32 RETBASE 	: 1;
		uint32 VECPEND 	: 8;
		uint32 			: 2;
		uint32 ISRPEND 	: 1;
		uint32 ISRPRE 	: 1;
		uint32 			: 1;
		uint32 PENDSTCLR: 1;
		uint32 PENDSTSET: 1;
		uint32 UNPENDSV : 1;
		uint32 PENDSV 	: 1;
		uint32 			: 2;
		uint32 NMISET 	: 1;
	} bits;
} INTCTRL_REG_t;


/************************************************************************************************
 * 						 Vector Table Offset Register (VTABLE) 									*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:10		   OFFSET 		      RW                    Vector Table Offset
 * 9:0 			   Reserved           RO                    Reserved
 * ==============================================================================================*/

typedef union
{
	uint32 REG;
	struct
	{
		uint32 OFFSET: 22;
		uint32 		 : 10;
	} bits;
} VTABLE_REG_t;


/************************************************************************************************
 * 						 Application Interrupt and Reset Control Register (APINT) 				*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:16		   VECTKEY 		      RW                    Register Key
 * 15 			   ENDIANESS 		  RW                    Data Endianness
 * 14:11 		   Reserved           RO                    Reserved
 * 10:8 		   PRIGROUP 		  RW                    Interrupt Priority Grouping
 * 7:3 			   Reserved           RO                    Reserved
 * 2 			   SYSRESREQ 		  RW                    System Reset Request
 * 1 			   VECTCLRACT 		  RW                    Clear Active NMI / Fault
 * 0 			   VECTRESET 		  RW                    System Reset Request
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 VECTRESET : 1;
		uint32 VECTCLRACT: 1;
		uint32 SYSRESREQ : 1;
		uint32 			 : 5;
		uint32 PRIGROUP  : 3;
		uint32 			 : 4;
		uint32 ENDIANESS : 1;
		uint32 VECTKEY 	 : 16;
	} bits;
} APINT_REG_t;


/************************************************************************************************
 * 						 System Control Register (SYSCTRL) 										*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31-5 		   Reserved           RO                    Reserved
 * 4 			   SEVONPEND 		  RW                    Wake Up on Pending
 * 3 			   Reserved 		  RO                    Reserved
 * 2 			   SLEEPDEEP 		  RW                    Deep Sleep Enable
 * 1 			   SLEEPEXIT 		  RW                    Sleep on ISR Exit
 * 0 			   Reserved 		  RO                    Reserved
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 			: 1;
		uint32 SLEEPEXIT: 1;
		uint32 SLEEPDEEP: 1;
		uint32 			: 1;
		uint32 SEVONPEND: 1;
		uint32 			: 27;
	} bits;
} SYSCTRL_REG_t;


/************************************************************************************************
 * 						 Configuration and Control Register (CFGCTRL) 							*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:10		   Reserved           RO                    Reserved
 * 9 		       STKALIGN 		  RW                    Stack Alignment on Exception Entry
 * 8 			   BFHFNMIGN 		  RW                    Ignore Bus Fault in NMI and Hard Fault
 * 7:5 			   Reserved           RO                    Reserved
 * 4 			   DIV0 		      RW                    Trap on Divide by 0
 * 3 			   UNALIGNED 		  RW                    Trap on Unaligned Access
 * 2 			   Reserved 		  RO                    Reserved
 * 1 			   MAINPEND 		  RW                    Allow Main interrupt trigger
 * 0 			   BASETHR 		      RW                    Thread State Control
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 BASETHR 	: 1;
		uint32 MAINPEND : 1;
		uint32 			: 1;
		uint32 UNALIGNED: 1;
		uint32 DIV0 	: 1;
		uint32 			: 3;
		uint32 BFHFNMIGN: 1;
		uint32 STKALIGN : 1;
		uint32 			: 22;
	} bits;
} CFGCTRL_REG_t;


/************************************************************************************************
 * 						 System Handler Priority 1 Register (SYSPRI1) 							*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:24		   Reserved           RO                    Reserved
 * 23:21 		   USAGE 		      RW                    Usage Fault Priority
 * 20:16 		   Reserved           RO                    Reserved
 * 15:13 		   BUS 			      RW                    Bus Fault Priority
 * 12:8 		   Reserved           RO                    Reserved
 * 7:5 			   MEM 			      RW                    Memory Management Fault Priority
 * 4:0 			   Reserved           RO                    Reserved
 * ==============================================================================================*/

typedef union
{
	uint32 REG;
	struct
	{
		uint32 		: 5;
		uint32 MEM 	: 3;
		uint32 		: 5;
		uint32 BUS 	: 3;
		uint32 		: 5;
		uint32 USAGE: 3;
		uint32 		: 8;
	} bits;
} SYSPRI1_REG_t;


/************************************************************************************************
 * 						 System Handler Priority 2 Register (SYSPRI2) 							*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:29		   SVC 			      RW                    SVCall Priority
 * 28:0 		   Reserved           RO                    Reserved
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 		: 29;
		uint32 SVC 	: 3;
	} bits;
} SYSPRI2_REG_t;


/************************************************************************************************
 * 						 System Handler Priority 3 Register (SYSPRI3) 							*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:29		   TICK 		      RW                    SysTick Exception Priority
 * 28:24 		   Reserved           RO                    Reserved
 * 23:21 		   PENDSV 		      RW                    PendSV Priority
 * 20:8 		   Reserved           RO                    Reserved
 * 7:5 			   DEBUG 		      RW                    Debug Monitor Priority
 * 4:0 			   Reserved           RO                    Reserved
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 		 : 5;
		uint32 DEBUG : 3;
		uint32 		 : 13;
		uint32 PENDSV: 3;
		uint32 		 : 5;
		uint32 TICK  : 3;
	} bits;
} SYSPRI3_REG_t;


/************************************************************************************************
 * 						 System Handler Control and State Register (SYSHNDCTRL) 				*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:19 		   Reserved           RO                    Reserved
 * 18 			   USAGE 		      RW                    Usage Fault Enable
 * 17 			   BUS 			      RW                    Bus Fault Enable
 * 16 			   MEM 			      RW                    Memory Management Fault Enable
 * 15 			   SVC 			      RW                    SVCall Pending
 * 14 			   BUSP 		      RW                    Bus Fault Pending
 * 13 			   MEMP 		      RW                    Memory Management Fault Pending
 * 12 			   USAGEP 		      RW                    Usage Fault Pending
 * 11 			   TICK 		      RW                    SysTick Exception Active
 * 10 			   PNDSV 		      RW                    PendSV Exception Active
 * 9 			   Reserved           RO                    Reserved
 * 8 			   MON 			      RW                    Debug Monitor Active
 * 7 			   SVCA 		      RW                    SVCall Active
 * 6:4 			   Reserved           RO                    Reserved
 * 3 			   USGA 		      RW                    Usage Fault Active
 * 2 			   Reserved           RO                    Reserved
 * 1 			   BUSA 		      RW                    Bus Fault Active
 * 0 			   MEMA 		      RW                    Memory Management Fault Active
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 MEMA  : 1;
		uint32 BUSA  : 1;
		uint32 		 : 1;
		uint32 USGA  : 1;
		uint32 		 : 3;
		uint32 SVCA  : 1;
		uint32 MON 	 : 1;
		uint32 		 : 1;
		uint32 PNDSV : 1;
		uint32 TICK  : 1;
		uint32 USAGEP: 1;
		uint32 MEMP  : 1;
		uint32 BUSP  : 1;
		uint32 SVC 	 : 1;
		uint32 MEM 	 : 1;
		uint32 BUS 	 : 1;
		uint32 USAGE : 1;
		uint32 		 : 13;
	} bits;
} SYSHNDCTRL_REG_t;


/************************************************************************************************
 * 						 Configurable Fault Status Register (FAULTSTAT) 						*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:26 		   Reserved           RO                    Reserved
 * 25 			   DIV0 		      RW1C                  Divide by 0 Fault Active
 * 24 			   UNALIGN 		      RW1C                  Unaligned Access Fault Active
 * 23:20 		   Reserved           RO                    Reserved
 * 19 			   NOCP 		      RW1C                  No Coprocessor Fault Active
 * 18 			   INVPC 		      RW1C                  Invalid PC Load Usage Fault Active
 * 17 			   INVSTAT 		      RW1C                  Invalid State Usage Fault Active
 * 16 			   UNDEF 		      RW1C                  Undefined Instruction Usage Fault Active
 * 15 			   BFARV 		      RW1C                  Bus Fault Address Register (BFAR) Valid
 * 14 			   Reserved           RO                    Reserved
 * 13 			   BLSPERR 		      RW1C                  Bus Fault on Floating-Point Lazy State Preservation
 * 12 			   BSTKE 		      RW1C                  Bus Fault on Stack Extension
 * 11 			   BUSTKE 		      RW1C                  Bus Fault on Floating-Point Stack Extension
 * 10 			   IMPRE 		      RW1C                  Implementation-Defined Fault
 * 9 			   PRECISE 		      RW1C                  Precise Data Access Violation
 * 8 			   IBUS 		      RW1C                  Instruction Bus Error
 * 7 			   MMARV 		      RW1C                  Memory Management Fault Address Register (MMAR) Valid
 * 6 			   Reserved           RO                    Reserved
 * 5 			   MLSPERR 		      RW1C                  Memory Management Fault on Floating-Point Lazy State Preservation
 * 4 			   MSTKE 		      RW1C                  Stack Access Violation
 * 3 			   MUSTKE 		      RW1C                  Unstack Access Violation
 * 2 			   Reserved           RO                    Reserved
 * 1 			   DERR 		      RW1C                  Data Access Violation
 * 0 			   IERR 		      RW1C                  Instruction Access Violation
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 IERR 	: 1;
		uint32 DERR 	: 1;
		uint32 		 	: 1;
		uint32 MUSTKE 	: 1;
		uint32 MSTKE 	: 1;
		uint32 MLSPERR 	: 1;
		uint32 		 	: 1;
		uint32 MMARV 	: 1;
		uint32 IBUS 	: 1;
		uint32 PRECISE 	: 1;
		uint32 IMPRE 	: 1;
		uint32 BUSTKE 	: 1;
		uint32 BSTKE 	: 1;
		uint32 BLSPERR 	: 1;
		uint32 		 	: 1;
		uint32 BFARV 	: 1;
		uint32 UNDEF 	: 1;
		uint32 INVSTAT 	: 1;
		uint32 INVPC 	: 1;
		uint32 NOCP 	: 1;
		uint32 		 	: 4;
		uint32 UNALIGN 	: 1;
		uint32 DIV0 	: 1;
		uint32 		 	: 6;
	} bits;
} FAULTSTAT_REG_t;


/************************************************************************************************
 * 						 Hard Fault Status Register (HFAULTSTAT) 								*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31 			   DBG 			      RW                    Debug Event
 * 30 			   FORCED 		      RW                    Forced Hard Fault
 * 29:2 		   Reserved           RO                    Reserved
 * 1 			   VECT 		      RW                    Vector Table Read Fault
 * 0 			   Reserved           RO                    Reserved
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 		 : 1;
		uint32 VECT  : 1;
		uint32 		 : 28;
		uint32 FORCED: 1;
		uint32 DBG 	 : 1;
	} bits;	
} HFAULTSTAT_REG_t;


/************************************************************************************************
 * 						 Memory Management Fault Address  (MMADDR) 								*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:0 		   ADDR 		      RW                    MemManage Fault Address
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 ADDR: 32;
	} bits;
} MMADDR_REG_t;

/************************************************************************************************
 * 						 Bus Fault Address  (FAULTADDR) 										*
 * =============================================================================================*
 * Bit/Field       Name               Type                  Description
 * ==============================================================================================
 * 31:0 		   ADDR 		      RW                    Bus Fault Address
 * ==============================================================================================*/
typedef union
{
	uint32 REG;
	struct
	{
		uint32 ADDR: 32;
	} bits;
} FAULTADDR_REG_t;

#define ACTLR 					(*((volatile ACTLR_REG_t *)(CORE_PERI_BASE_ADDRESS + ACTLR_OFFSET)))
#define CPUID 					(*((volatile CPUID_REG_t *)(CORE_PERI_BASE_ADDRESS + CPUID_OFFSET)))
#define INTCTRL 				(*((volatile INTCTRL_REG_t *)(CORE_PERI_BASE_ADDRESS + INTCTRL_OFFSET)))
#define VTABLE 					(*((volatile VTABLE_REG_t *)(CORE_PERI_BASE_ADDRESS + VTABLE_OFFSET)))
#define APINT 					(*((volatile APINT_REG_t *)(CORE_PERI_BASE_ADDRESS + APINT_OFFSET)))
#define SYSCTRL 				(*((volatile SYSCTRL_REG_t *)(CORE_PERI_BASE_ADDRESS + SYSCTRL_OFFSET)))
#define CFGCTRL 				(*((volatile CFGCTRL_REG_t *)(CORE_PERI_BASE_ADDRESS + CFGCTRL_OFFSET)))
#define SYSPRI1 				(*((volatile SYSPRI1_REG_t *)(CORE_PERI_BASE_ADDRESS + SYSPRI1_OFFSET)))
#define SYSPRI2 				(*((volatile SYSPRI2_REG_t *)(CORE_PERI_BASE_ADDRESS + SYSPRI2_OFFSET)))
#define SYSPRI3 				(*((volatile SYSPRI3_REG_t *)(CORE_PERI_BASE_ADDRESS + SYSPRI3_OFFSET)))
#define SYSHNDCTRL 				(*((volatile SYSHNDCTRL_REG_t *)(CORE_PERI_BASE_ADDRESS + SYSHNDCTRL_OFFSET)))
#define FAULTSTAT 				(*((volatile FAULTSTAT_REG_t *)(CORE_PERI_BASE_ADDRESS + FAULTSTAT_OFFSET)))
#define HFAULTSTAT 				(*((volatile HFAULTSTAT_REG_t *)(CORE_PERI_BASE_ADDRESS + HFAULTSTAT_OFFSET)))
#define MMADDR 					(*((volatile MMADDR_REG_t *)(CORE_PERI_BASE_ADDRESS + MMADDR_OFFSET)))
#define FAULTADDR 				(*((volatile FAULTADDR_REG_t *)(CORE_PERI_BASE_ADDRESS + FAULTADDR_OFFSET)))


#endif /* CORE_MAP_H_ */