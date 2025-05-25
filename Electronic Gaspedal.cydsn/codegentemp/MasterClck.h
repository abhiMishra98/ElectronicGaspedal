/*******************************************************************************
* File Name: MasterClck.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_MasterClck_H)
#define CY_CLOCK_MasterClck_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void MasterClck_Start(void) ;
void MasterClck_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void MasterClck_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void MasterClck_StandbyPower(uint8 state) ;
void MasterClck_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 MasterClck_GetDividerRegister(void) ;
void MasterClck_SetModeRegister(uint8 modeBitMask) ;
void MasterClck_ClearModeRegister(uint8 modeBitMask) ;
uint8 MasterClck_GetModeRegister(void) ;
void MasterClck_SetSourceRegister(uint8 clkSource) ;
uint8 MasterClck_GetSourceRegister(void) ;
#if defined(MasterClck__CFG3)
void MasterClck_SetPhaseRegister(uint8 clkPhase) ;
uint8 MasterClck_GetPhaseRegister(void) ;
#endif /* defined(MasterClck__CFG3) */

#define MasterClck_Enable()                       MasterClck_Start()
#define MasterClck_Disable()                      MasterClck_Stop()
#define MasterClck_SetDivider(clkDivider)         MasterClck_SetDividerRegister(clkDivider, 1u)
#define MasterClck_SetDividerValue(clkDivider)    MasterClck_SetDividerRegister((clkDivider) - 1u, 1u)
#define MasterClck_SetMode(clkMode)               MasterClck_SetModeRegister(clkMode)
#define MasterClck_SetSource(clkSource)           MasterClck_SetSourceRegister(clkSource)
#if defined(MasterClck__CFG3)
#define MasterClck_SetPhase(clkPhase)             MasterClck_SetPhaseRegister(clkPhase)
#define MasterClck_SetPhaseValue(clkPhase)        MasterClck_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(MasterClck__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define MasterClck_CLKEN              (* (reg8 *) MasterClck__PM_ACT_CFG)
#define MasterClck_CLKEN_PTR          ((reg8 *) MasterClck__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define MasterClck_CLKSTBY            (* (reg8 *) MasterClck__PM_STBY_CFG)
#define MasterClck_CLKSTBY_PTR        ((reg8 *) MasterClck__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define MasterClck_DIV_LSB            (* (reg8 *) MasterClck__CFG0)
#define MasterClck_DIV_LSB_PTR        ((reg8 *) MasterClck__CFG0)
#define MasterClck_DIV_PTR            ((reg16 *) MasterClck__CFG0)

/* Clock MSB divider configuration register. */
#define MasterClck_DIV_MSB            (* (reg8 *) MasterClck__CFG1)
#define MasterClck_DIV_MSB_PTR        ((reg8 *) MasterClck__CFG1)

/* Mode and source configuration register */
#define MasterClck_MOD_SRC            (* (reg8 *) MasterClck__CFG2)
#define MasterClck_MOD_SRC_PTR        ((reg8 *) MasterClck__CFG2)

#if defined(MasterClck__CFG3)
/* Analog clock phase configuration register */
#define MasterClck_PHASE              (* (reg8 *) MasterClck__CFG3)
#define MasterClck_PHASE_PTR          ((reg8 *) MasterClck__CFG3)
#endif /* defined(MasterClck__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define MasterClck_CLKEN_MASK         MasterClck__PM_ACT_MSK
#define MasterClck_CLKSTBY_MASK       MasterClck__PM_STBY_MSK

/* CFG2 field masks */
#define MasterClck_SRC_SEL_MSK        MasterClck__CFG2_SRC_SEL_MASK
#define MasterClck_MODE_MASK          (~(MasterClck_SRC_SEL_MSK))

#if defined(MasterClck__CFG3)
/* CFG3 phase mask */
#define MasterClck_PHASE_MASK         MasterClck__CFG3_PHASE_DLY_MASK
#endif /* defined(MasterClck__CFG3) */

#endif /* CY_CLOCK_MasterClck_H */


/* [] END OF FILE */
