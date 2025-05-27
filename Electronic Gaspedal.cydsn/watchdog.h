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
#ifndef WATCHDOG_H
#define WATCHDOG_H
    
#include "global.h"
#include "stdbool.h"
#include <stdint.h>
#include "project.h"

#define PM_WDT_CFG_REG           (*(volatile uint8_t *)0x40004383u)
#define PM_WDT_CR_REG            (*(volatile uint8_t *)0x40004384u)
#define WDT_CFG_INTRVL_MASK      (0x03u)
#define WDT_CFG_CTW_RESET        (0x80u)
#define WDT_CFG_WDR_EN           (0x10u)
#define WDT_CR_FEED              (0x01u)
#define RESET_WD                 (0x08u)



#define WD_joystick               0u
#define WD_calcControl            1u
#define WD_setEngine              2u
#define WD_setBrakeLight          3u


static uint8_t WD_alive_Globalbitfield = 0x0u;

typedef enum{
  timeOut4_6ms       = CYWDT_2_TICKS,    //Timeout after 4-6ms
  timeOut32_48ms     = CYWDT_16_TICKS,   //Timeout after 32- 48ms
  timeOut256_384ms   = CYWDT_128_TICKS,  //Timeout after 256 - 384ms
  timeOut2_3s        = CYWDT_1024_TICKS  //Timeout after 2-3 seconds
}WDT_TimeOut_t;

/**
 * Starts the watchdog
 * @param timeout [IN]          -           Timeout period
 * @return RC_SUCCESS if function was executed as exepected, other error code in case of error
 */
RC_t WD_Start(WDT_TimeOut_t timeout);

/**
* Service the Watchdog Trigger
* @return RC_SUCCESS
*/
RC_t WD_trigger();

/**
* Set the corresponding bit field in the globalBitField given by myBitPosition
* @return RC_SUCCESS
*/

RC_t WD_Alive(uint8_t rnbl_bitPosn);

/**
* Checks the watchdog bit
* @return TRUE if watchdog reset bit was set
*/
boolean_t WD_CheckResetBit();

#endif /* Together */