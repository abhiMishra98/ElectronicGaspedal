/*******************************************************************************
* File Name: redLED.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_redLED_H) /* Pins redLED_H */
#define CY_PINS_redLED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "redLED_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 redLED__PORT == 15 && ((redLED__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    redLED_Write(uint8 value);
void    redLED_SetDriveMode(uint8 mode);
uint8   redLED_ReadDataReg(void);
uint8   redLED_Read(void);
void    redLED_SetInterruptMode(uint16 position, uint16 mode);
uint8   redLED_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the redLED_SetDriveMode() function.
     *  @{
     */
        #define redLED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define redLED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define redLED_DM_RES_UP          PIN_DM_RES_UP
        #define redLED_DM_RES_DWN         PIN_DM_RES_DWN
        #define redLED_DM_OD_LO           PIN_DM_OD_LO
        #define redLED_DM_OD_HI           PIN_DM_OD_HI
        #define redLED_DM_STRONG          PIN_DM_STRONG
        #define redLED_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define redLED_MASK               redLED__MASK
#define redLED_SHIFT              redLED__SHIFT
#define redLED_WIDTH              1u

/* Interrupt constants */
#if defined(redLED__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in redLED_SetInterruptMode() function.
     *  @{
     */
        #define redLED_INTR_NONE      (uint16)(0x0000u)
        #define redLED_INTR_RISING    (uint16)(0x0001u)
        #define redLED_INTR_FALLING   (uint16)(0x0002u)
        #define redLED_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define redLED_INTR_MASK      (0x01u) 
#endif /* (redLED__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define redLED_PS                     (* (reg8 *) redLED__PS)
/* Data Register */
#define redLED_DR                     (* (reg8 *) redLED__DR)
/* Port Number */
#define redLED_PRT_NUM                (* (reg8 *) redLED__PRT) 
/* Connect to Analog Globals */                                                  
#define redLED_AG                     (* (reg8 *) redLED__AG)                       
/* Analog MUX bux enable */
#define redLED_AMUX                   (* (reg8 *) redLED__AMUX) 
/* Bidirectional Enable */                                                        
#define redLED_BIE                    (* (reg8 *) redLED__BIE)
/* Bit-mask for Aliased Register Access */
#define redLED_BIT_MASK               (* (reg8 *) redLED__BIT_MASK)
/* Bypass Enable */
#define redLED_BYP                    (* (reg8 *) redLED__BYP)
/* Port wide control signals */                                                   
#define redLED_CTL                    (* (reg8 *) redLED__CTL)
/* Drive Modes */
#define redLED_DM0                    (* (reg8 *) redLED__DM0) 
#define redLED_DM1                    (* (reg8 *) redLED__DM1)
#define redLED_DM2                    (* (reg8 *) redLED__DM2) 
/* Input Buffer Disable Override */
#define redLED_INP_DIS                (* (reg8 *) redLED__INP_DIS)
/* LCD Common or Segment Drive */
#define redLED_LCD_COM_SEG            (* (reg8 *) redLED__LCD_COM_SEG)
/* Enable Segment LCD */
#define redLED_LCD_EN                 (* (reg8 *) redLED__LCD_EN)
/* Slew Rate Control */
#define redLED_SLW                    (* (reg8 *) redLED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define redLED_PRTDSI__CAPS_SEL       (* (reg8 *) redLED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define redLED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) redLED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define redLED_PRTDSI__OE_SEL0        (* (reg8 *) redLED__PRTDSI__OE_SEL0) 
#define redLED_PRTDSI__OE_SEL1        (* (reg8 *) redLED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define redLED_PRTDSI__OUT_SEL0       (* (reg8 *) redLED__PRTDSI__OUT_SEL0) 
#define redLED_PRTDSI__OUT_SEL1       (* (reg8 *) redLED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define redLED_PRTDSI__SYNC_OUT       (* (reg8 *) redLED__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(redLED__SIO_CFG)
    #define redLED_SIO_HYST_EN        (* (reg8 *) redLED__SIO_HYST_EN)
    #define redLED_SIO_REG_HIFREQ     (* (reg8 *) redLED__SIO_REG_HIFREQ)
    #define redLED_SIO_CFG            (* (reg8 *) redLED__SIO_CFG)
    #define redLED_SIO_DIFF           (* (reg8 *) redLED__SIO_DIFF)
#endif /* (redLED__SIO_CFG) */

/* Interrupt Registers */
#if defined(redLED__INTSTAT)
    #define redLED_INTSTAT            (* (reg8 *) redLED__INTSTAT)
    #define redLED_SNAP               (* (reg8 *) redLED__SNAP)
    
	#define redLED_0_INTTYPE_REG 		(* (reg8 *) redLED__0__INTTYPE)
#endif /* (redLED__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_redLED_H */


/* [] END OF FILE */
