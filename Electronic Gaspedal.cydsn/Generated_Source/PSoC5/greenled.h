/*******************************************************************************
* File Name: greenled.h  
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

#if !defined(CY_PINS_greenled_H) /* Pins greenled_H */
#define CY_PINS_greenled_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "greenled_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 greenled__PORT == 15 && ((greenled__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    greenled_Write(uint8 value);
void    greenled_SetDriveMode(uint8 mode);
uint8   greenled_ReadDataReg(void);
uint8   greenled_Read(void);
void    greenled_SetInterruptMode(uint16 position, uint16 mode);
uint8   greenled_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the greenled_SetDriveMode() function.
     *  @{
     */
        #define greenled_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define greenled_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define greenled_DM_RES_UP          PIN_DM_RES_UP
        #define greenled_DM_RES_DWN         PIN_DM_RES_DWN
        #define greenled_DM_OD_LO           PIN_DM_OD_LO
        #define greenled_DM_OD_HI           PIN_DM_OD_HI
        #define greenled_DM_STRONG          PIN_DM_STRONG
        #define greenled_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define greenled_MASK               greenled__MASK
#define greenled_SHIFT              greenled__SHIFT
#define greenled_WIDTH              1u

/* Interrupt constants */
#if defined(greenled__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in greenled_SetInterruptMode() function.
     *  @{
     */
        #define greenled_INTR_NONE      (uint16)(0x0000u)
        #define greenled_INTR_RISING    (uint16)(0x0001u)
        #define greenled_INTR_FALLING   (uint16)(0x0002u)
        #define greenled_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define greenled_INTR_MASK      (0x01u) 
#endif /* (greenled__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define greenled_PS                     (* (reg8 *) greenled__PS)
/* Data Register */
#define greenled_DR                     (* (reg8 *) greenled__DR)
/* Port Number */
#define greenled_PRT_NUM                (* (reg8 *) greenled__PRT) 
/* Connect to Analog Globals */                                                  
#define greenled_AG                     (* (reg8 *) greenled__AG)                       
/* Analog MUX bux enable */
#define greenled_AMUX                   (* (reg8 *) greenled__AMUX) 
/* Bidirectional Enable */                                                        
#define greenled_BIE                    (* (reg8 *) greenled__BIE)
/* Bit-mask for Aliased Register Access */
#define greenled_BIT_MASK               (* (reg8 *) greenled__BIT_MASK)
/* Bypass Enable */
#define greenled_BYP                    (* (reg8 *) greenled__BYP)
/* Port wide control signals */                                                   
#define greenled_CTL                    (* (reg8 *) greenled__CTL)
/* Drive Modes */
#define greenled_DM0                    (* (reg8 *) greenled__DM0) 
#define greenled_DM1                    (* (reg8 *) greenled__DM1)
#define greenled_DM2                    (* (reg8 *) greenled__DM2) 
/* Input Buffer Disable Override */
#define greenled_INP_DIS                (* (reg8 *) greenled__INP_DIS)
/* LCD Common or Segment Drive */
#define greenled_LCD_COM_SEG            (* (reg8 *) greenled__LCD_COM_SEG)
/* Enable Segment LCD */
#define greenled_LCD_EN                 (* (reg8 *) greenled__LCD_EN)
/* Slew Rate Control */
#define greenled_SLW                    (* (reg8 *) greenled__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define greenled_PRTDSI__CAPS_SEL       (* (reg8 *) greenled__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define greenled_PRTDSI__DBL_SYNC_IN    (* (reg8 *) greenled__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define greenled_PRTDSI__OE_SEL0        (* (reg8 *) greenled__PRTDSI__OE_SEL0) 
#define greenled_PRTDSI__OE_SEL1        (* (reg8 *) greenled__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define greenled_PRTDSI__OUT_SEL0       (* (reg8 *) greenled__PRTDSI__OUT_SEL0) 
#define greenled_PRTDSI__OUT_SEL1       (* (reg8 *) greenled__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define greenled_PRTDSI__SYNC_OUT       (* (reg8 *) greenled__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(greenled__SIO_CFG)
    #define greenled_SIO_HYST_EN        (* (reg8 *) greenled__SIO_HYST_EN)
    #define greenled_SIO_REG_HIFREQ     (* (reg8 *) greenled__SIO_REG_HIFREQ)
    #define greenled_SIO_CFG            (* (reg8 *) greenled__SIO_CFG)
    #define greenled_SIO_DIFF           (* (reg8 *) greenled__SIO_DIFF)
#endif /* (greenled__SIO_CFG) */

/* Interrupt Registers */
#if defined(greenled__INTSTAT)
    #define greenled_INTSTAT            (* (reg8 *) greenled__INTSTAT)
    #define greenled_SNAP               (* (reg8 *) greenled__SNAP)
    
	#define greenled_0_INTTYPE_REG 		(* (reg8 *) greenled__0__INTTYPE)
#endif /* (greenled__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_greenled_H */


/* [] END OF FILE */
