/*
 * Filename: swc_joystick.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Software component
 * name: swc_joystick
 * shortname: joystick
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "swc_joystick.h"


/* USER CODE START SWC_JOYSTICK_INCLUDE */

/* USER CODE END SWC_JOYSTICK_INCLUDE */


#include "sp_signalpool.h"

/* USER CODE START SWC_JOYSTICK_USERDEFINITIONS */

/* USER CODE END SWC_JOYSTICK_USERDEFINITIONS */



/*
 * component: swc_joystick
 * cycletime: 10
 * description: Runnable
 * events: 
 * name: JOYSTICK_Joystick_readJoystick_run
 * shortname: Joystick_readJoystick
 * signalIN: 
 * signalOUT: so_joystick
 * task: tsk_IO
 */
void JOYSTICK_Joystick_readJoystick_run(RTE_event ev){
	
	/* USER CODE START JOYSTICK_Joystick_readJoystick_run */
     RC_t result = RTE_SC_JOYSTICK_pullPort(&SO_JOYSTICK_signal);    
    if(result != RC_SUCCESS){
        UART_LOG_PutString("Issue with Joystick Driver\r\n");
    }
    WD_Alive(WD_joystick);

    /* USER CODE END JOYSTICK_Joystick_readJoystick_run */
}

/* USER CODE START SWC_JOYSTICK_FUNCTIONS */

/* USER CODE END SWC_JOYSTICK_FUNCTIONS */

