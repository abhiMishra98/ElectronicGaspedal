/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/* [] END OF FILE */
#include "watchdog.h"


RC_t WD_Start(WDT_TimeOut_t timeout){
    /* Set WDT interval */
    PM_WDT_CFG_REG = (PM_WDT_CFG_REG & ((uint8)(~WDT_CFG_INTRVL_MASK))) | (timeout & WDT_CFG_INTRVL_MASK);

    /* Reset CTW to ensure that first watchdog period is full */
    PM_WDT_CFG_REG |= WDT_CFG_CTW_RESET;
    PM_WDT_CFG_REG &= ((uint8)(~WDT_CFG_CTW_RESET));   
    
    /* Enables watchdog reset */
    PM_WDT_CFG_REG |= WDT_CFG_WDR_EN;
    return RC_SUCCESS;
}

RC_t WD_trigger(){
    RC_t ret = RC_SUCCESS;
    if(WD_alive_Globalbitfield == 0x0fu){ //If the 4 runnables set the corresponding bit fields.
        PM_WDT_CR_REG = WDT_CR_FEED; //Feeding the watchdog
    }
    return ret;
}

RC_t WD_Alive(uint8_t rnbl_bitPosn){
    WD_alive_Globalbitfield |= (1u)<<rnbl_bitPosn;
    return RC_SUCCESS;
}

boolean_t WD_CheckResetBit(){
    if(CyResetStatus & RESET_WD){
        return true;
    }
    else{
        return false;
    }
}