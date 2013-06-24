/*
 * File: floribot_accu_watchdog.cpp
 *
 * Code generated for Simulink model 'floribot_accu_watchdog'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Fri Jun 21 00:24:15 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "floribot_accu_watchdog.h"
#include "floribot_accu_watchdog_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define floribot_acc_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define floribot_accu_watch_IN_Accu_low ((uint8_T)1U)
#define floribot_accu_watchd_IN_Accu_ok ((uint8_T)2U)

/* Block states (auto storage) */
DW_floribot_accu_watchdog_T floribot_accu_watchdog_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_floribot_accu_watchdog_T floribot_accu_watchdog_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_floribot_accu_watchdog_T floribot_accu_watchdog_Y;

/* Real-time model */
RT_MODEL_floribot_accu_watchd_T floribot_accu_watchdog_M_;
RT_MODEL_floribot_accu_watchd_T *const floribot_accu_watchdog_M =
  &floribot_accu_watchdog_M_;

/* Model step function */
void floribot_accu_watchdog_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/voltage'
   *  Inport: '<Root>/voltage_threshold'
   */
  /* Gateway: Chart */
  /* During: Chart */
  if (floribot_accu_watchdog_DW.is_active_c1_floribot_accu_watc == 0U) {
    /* Entry: Chart */
    floribot_accu_watchdog_DW.is_active_c1_floribot_accu_watc = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:7' */
    floribot_accu_watchdog_DW.is_c1_floribot_accu_watchdog =
      floribot_accu_watchd_IN_Accu_ok;

    /* Outport: '<Root>/accu_low' */
    /* Entry 'Accu_ok': '<S1>:3' */
    floribot_accu_watchdog_Y.accu_low = FALSE;
  } else if (floribot_accu_watchdog_DW.is_c1_floribot_accu_watchdog ==
             floribot_accu_watch_IN_Accu_low) {
    /* During 'Accu_low': '<S1>:4' */
    if (floribot_accu_watchdog_U.voltage >
        floribot_accu_watchdog_U.voltage_threshold) {
      /* Transition: '<S1>:6' */
      floribot_accu_watchdog_DW.is_c1_floribot_accu_watchdog =
        floribot_accu_watchd_IN_Accu_ok;

      /* Outport: '<Root>/accu_low' */
      /* Entry 'Accu_ok': '<S1>:3' */
      floribot_accu_watchdog_Y.accu_low = FALSE;
    }
  } else {
    /* During 'Accu_ok': '<S1>:3' */
    if (floribot_accu_watchdog_U.voltage <
        floribot_accu_watchdog_U.voltage_threshold) {
      /* Transition: '<S1>:5' */
      floribot_accu_watchdog_DW.is_c1_floribot_accu_watchdog =
        floribot_accu_watch_IN_Accu_low;

      /* Outport: '<Root>/accu_low' */
      /* Entry 'Accu_low': '<S1>:4' */
      floribot_accu_watchdog_Y.accu_low = TRUE;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void floribot_accu_watchdog_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(floribot_accu_watchdog_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&floribot_accu_watchdog_DW, 0,
                sizeof(DW_floribot_accu_watchdog_T));

  /* external inputs */
  (void) memset((void *)&floribot_accu_watchdog_U, 0,
                sizeof(ExtU_floribot_accu_watchdog_T));

  /* external outputs */
  floribot_accu_watchdog_Y.accu_low = FALSE;

  /* InitializeConditions for Chart: '<Root>/Chart' */
  floribot_accu_watchdog_DW.is_active_c1_floribot_accu_watc = 0U;
  floribot_accu_watchdog_DW.is_c1_floribot_accu_watchdog =
    floribot_acc_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for Outport: '<Root>/accu_low' incorporates:
   *  InitializeConditions for Chart: '<Root>/Chart'
   */
  floribot_accu_watchdog_Y.accu_low = FALSE;
}

/* Model terminate function */
void floribot_accu_watchdog_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
