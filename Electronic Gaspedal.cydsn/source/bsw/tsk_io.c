/*
 * Filename: tsk_io.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Task having runnables which either receives input from the user or provide output to the actuators. Running runnables in 10ms and 100ms.
 * events: 
 * mode: Cyclic
 * name: tsk_IO
 * shortname: IO
 * signalpoolsRO: sp_signalPool
 * signalpoolsRW: sp_signalPool
 * tickEvent: 0
 * timertickperiod: 1
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "tsk_io.h"



/* USER CODE START TSK_IO_INCLUDE */

/* USER CODE END TSK_IO_INCLUDE */

#include "swc_joystick.h"
#include "swc_engine_control.h"



/* USER CODE START TSK_IO_USERDEFINITIONS */

/* USER CODE END TSK_IO_USERDEFINITIONS */

/*******************************************************************************
 * Runnable Tables from Activation Engine
 *******************************************************************************/

/* Cyclic Table */

const RTE_cyclicTable_t RTE_cyclicActivationTable_tsk_io[] = {
	{ JOYSTICK_Joystick_readJoystick_run, 10 },	//Runnable
	{ ENGINE_CONTROL_Engine_Control_setEngine_run, 100 },	//Runnable
};
const uint16_t RTE_cyclicActivation_tsk_io_size = sizeof (RTE_cyclicActivationTable_tsk_io) / sizeof(RTE_cyclicTable_t); 


/*******************************************************************************
 * Task Body
 *******************************************************************************/


/*
 * description: Task having runnables which either receives input from the user or provide output to the actuators. Running runnables in 10ms and 100ms.
 * events: 
 * mode: Cyclic
 * name: tsk_IO
 * shortname: IO
 * signalpoolsRO: sp_signalPool
 * signalpoolsRW: sp_signalPool
 * tickEvent: 0
 * timertickperiod: 1
 */
TASK(tsk_IO)
{
	/* ticktime of the task */
	static uint32_t ticktime = 0;

	/* USER CODE START TSK_IO_TASKBODY_PRE */

	/* USER CODE END TSK_IO_TASKBODY_PRE */
    
    //Process all cyclic runnables which are due
    RTE_ProcessCyclicTable(RTE_cyclicActivationTable_tsk_io, RTE_cyclicActivation_tsk_io_size, ticktime);
	
	/* USER CODE START TSK_IO_TASKBODY_POST */

	/* USER CODE END TSK_IO_TASKBODY_POST */

	ticktime += 1;
	if (ticktime > 0xFFFFFF00) ticktime = 0;
	
	TerminateTask();
    
}


/*******************************************************************************
 * Interrupt Service Routines
 *******************************************************************************/

/* USER CODE START TSK_IO_ISR */

/* USER CODE END TSK_IO_ISR */

