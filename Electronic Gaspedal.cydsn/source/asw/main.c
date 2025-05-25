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
#include "project.h"
#include "global.h"

#include "led.h"
#include "tsk_io.h"
#include "tsk_control.h"

//ISR which will increment the systick counter every ms
ISR(systick_handler)
{
    CounterTick(cnt_systick);
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_LOG_Start();
    //Set systick period to 1 ms. Enable the INT and start it.
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, BCLK__BUS_CLK__HZ));
	EE_systick_enable_int();
   
    // Start Operating System
    for(;;)	    
    	StartOS(OSDEFAULTAPPMODE);
}

void unhandledException()
{
    //Ooops, something terrible happened....check the call stack to see how we got here...
    __asm("bkpt");
}

/********************************************************************************
 * Task Definitions
 ********************************************************************************/

TASK(tsk_init)
{
    
    //Init MCAL Drivers
//    LED_Init();
//    SEVEN_Init();
    
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();  
	RGB_PWM_green_Start();
    //Start the alarm with 100ms cycle time
    SetRelAlarm(alrm_1ms,1,1);
    ActivateTask(tsk_Control);
    ActivateTask(tsk_background);
    ActivateTask(tsk_Brakelight);
    TerminateTask();
    
}

TASK(tsk_background)
{
    while(1)
    {
        //do something with low prioroty
        __asm("nop");
    }
}


/********************************************************************************
 * ISR Definitions
 ********************************************************************************/


/* [] END OF FILE */
