/*
 * File: floribot_task3.cpp
 *
 * Code generated for Simulink model 'floribot_task3'.
 *
 * Model version                  : 1.58
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Tue Jun 18 15:33:42 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "floribot_task3.h"
#include "floribot_task3_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define floribot_tas_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define floribot_task3_IN_inside_row   ((uint8_T)1U)
#define floribot_task3_IN_leaving_row  ((uint8_T)2U)
#define floribot_task3_IN_turning      ((uint8_T)3U)

/* Block states (auto storage) */
DW_floribot_task3_T floribot_task3_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_floribot_task3_T floribot_task3_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_floribot_task3_T floribot_task3_Y;

/* Real-time model */
RT_MODEL_floribot_task3_T floribot_task3_M_;
RT_MODEL_floribot_task3_T *const floribot_task3_M = &floribot_task3_M_;

/* Model step function */
void floribot_task3_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/direction'
   *  Inport: '<Root>/front_row_x'
   *  Inport: '<Root>/left_row_prob'
   *  Inport: '<Root>/left_row_y'
   *  Inport: '<Root>/prob_threshold'
   *  Inport: '<Root>/right_row_prob'
   *  Inport: '<Root>/right_row_y'
   *  Inport: '<Root>/row_width'
   */
  floribot_task3_DW.presentTicks = floribot_task3_M->Timing.clockTick0;
  floribot_task3_DW.elapsedTicks = floribot_task3_DW.presentTicks -
    floribot_task3_DW.previousTicks;
  floribot_task3_DW.previousTicks = floribot_task3_DW.presentTicks;
  if (floribot_task3_DW.temporalCounter_i1 + floribot_task3_DW.elapsedTicks <=
      63U) {
    floribot_task3_DW.temporalCounter_i1 += floribot_task3_DW.elapsedTicks;
  } else {
    floribot_task3_DW.temporalCounter_i1 = 63U;
  }

  /* Gateway: Chart */
  /* During: Chart */
  if (floribot_task3_DW.is_active_c1_floribot_task3 == 0U) {
    /* Entry: Chart */
    floribot_task3_DW.is_active_c1_floribot_task3 = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:11' */
    floribot_task3_DW.dir = floribot_task3_U.direction;
    floribot_task3_DW.is_c1_floribot_task3 = floribot_task3_IN_inside_row;
  } else {
    switch (floribot_task3_DW.is_c1_floribot_task3) {
     case floribot_task3_IN_inside_row:
      /* During 'inside_row': '<S1>:10' */
      if ((floribot_task3_U.right_row_prob < floribot_task3_U.prob_threshold) &&
          (floribot_task3_U.left_row_prob < floribot_task3_U.prob_threshold) &&
          ((floribot_task3_U.row_width - floribot_task3_U.left_row_y) +
           floribot_task3_U.right_row_y < 0.2)) {
        /* Outport: '<Root>/cmd_vel_x' */
        /* Transition: '<S1>:37' */
        floribot_task3_Y.cmd_vel_x = 0.1;

        /* Outport: '<Root>/cmd_vel_yaw' */
        floribot_task3_Y.cmd_vel_yaw = (floribot_task3_U.left_row_y +
          floribot_task3_U.right_row_y) / 2.0;
        floribot_task3_DW.is_c1_floribot_task3 = floribot_task3_IN_inside_row;
      } else if ((floribot_task3_U.right_row_prob <
                  floribot_task3_U.prob_threshold) &&
                 (floribot_task3_U.left_row_prob >
                  floribot_task3_U.prob_threshold)) {
        /* Outport: '<Root>/cmd_vel_x' incorporates:
         *  Inport: '<Root>/front_row_x'
         */
        /* Transition: '<S1>:15' */
        floribot_task3_Y.cmd_vel_x = floribot_task3_U.front_row_x / 2.0;

        /* Outport: '<Root>/cmd_vel_yaw' */
        floribot_task3_Y.cmd_vel_yaw = (floribot_task3_U.left_row_y -
          floribot_task3_U.row_width / 2.0) * 1.5;
        floribot_task3_DW.is_c1_floribot_task3 = floribot_task3_IN_inside_row;
      } else if ((floribot_task3_U.left_row_prob >
                  floribot_task3_U.prob_threshold) &&
                 (floribot_task3_U.right_row_prob >
                  floribot_task3_U.prob_threshold) &&
                 ((floribot_task3_U.row_width - floribot_task3_U.left_row_y) +
                  floribot_task3_U.right_row_y < 0.2)) {
        /* Outport: '<Root>/cmd_vel_x' incorporates:
         *  Inport: '<Root>/front_row_x'
         */
        /* Transition: '<S1>:42' */
        floribot_task3_Y.cmd_vel_x = floribot_task3_U.front_row_x;

        /* Outport: '<Root>/cmd_vel_yaw' */
        floribot_task3_Y.cmd_vel_yaw = (floribot_task3_U.left_row_y +
          floribot_task3_U.right_row_y) / 2.0 * 1.5;
        floribot_task3_DW.is_c1_floribot_task3 = floribot_task3_IN_inside_row;
      } else if (floribot_task3_U.front_row_x == 0.0) {
        /* Transition: '<S1>:17' */
        floribot_task3_DW.is_c1_floribot_task3 = floribot_task3_IN_leaving_row;
        floribot_task3_DW.temporalCounter_i1 = 0U;
      } else if ((floribot_task3_U.right_row_prob >
                  floribot_task3_U.prob_threshold) &&
                 (floribot_task3_U.left_row_prob <
                  floribot_task3_U.prob_threshold)) {
        /* Outport: '<Root>/cmd_vel_x' incorporates:
         *  Inport: '<Root>/front_row_x'
         */
        /* Transition: '<S1>:43' */
        floribot_task3_Y.cmd_vel_x = floribot_task3_U.front_row_x / 2.0;

        /* Outport: '<Root>/cmd_vel_yaw' */
        floribot_task3_Y.cmd_vel_yaw = (floribot_task3_U.row_width / 2.0 +
          floribot_task3_U.right_row_y) * 1.5;
        floribot_task3_DW.is_c1_floribot_task3 = floribot_task3_IN_inside_row;
      } else {
        if ((floribot_task3_U.left_row_prob > floribot_task3_U.prob_threshold) &&
            (floribot_task3_U.right_row_prob > floribot_task3_U.prob_threshold) &&
            ((floribot_task3_U.row_width - floribot_task3_U.left_row_y) +
             floribot_task3_U.right_row_y > 0.2)) {
          /* Outport: '<Root>/cmd_vel_x' */
          /* Transition: '<S1>:44' */
          floribot_task3_Y.cmd_vel_x = floribot_task3_U.row_width / 2.0 -
            ((floribot_task3_U.row_width - floribot_task3_U.left_row_y) +
             floribot_task3_U.right_row_y);

          /* Outport: '<Root>/cmd_vel_yaw' */
          floribot_task3_Y.cmd_vel_yaw = (floribot_task3_U.left_row_y +
            floribot_task3_U.right_row_y) / 2.0 * 1.5;
          floribot_task3_DW.is_c1_floribot_task3 = floribot_task3_IN_inside_row;
        }
      }
      break;

     case floribot_task3_IN_leaving_row:
      /* During 'leaving_row': '<S1>:14' */
      if (floribot_task3_DW.temporalCounter_i1 >= 50U) {
        /* Transition: '<S1>:29' */
        floribot_task3_DW.is_c1_floribot_task3 = floribot_task3_IN_turning;
        floribot_task3_DW.temporalCounter_i1 = 0U;
      } else {
        /* Outport: '<Root>/cmd_vel_x' */
        floribot_task3_Y.cmd_vel_x = 0.6;

        /* Outport: '<Root>/cmd_vel_yaw' */
        floribot_task3_Y.cmd_vel_yaw = 0.3 * floribot_task3_DW.dir;
      }
      break;

     default:
      /* During 'turning': '<S1>:28' */
      if ((floribot_task3_DW.temporalCounter_i1 >= 60U) &&
          ((floribot_task3_U.left_row_prob > floribot_task3_U.prob_threshold) ||
           (floribot_task3_U.right_row_prob > floribot_task3_U.prob_threshold)))
      {
        /* Transition: '<S1>:20' */
        floribot_task3_DW.dir = -floribot_task3_DW.dir;
        floribot_task3_DW.is_c1_floribot_task3 = floribot_task3_IN_inside_row;
      } else {
        /* Outport: '<Root>/cmd_vel_x' */
        floribot_task3_Y.cmd_vel_x = 0.0;

        /* Outport: '<Root>/cmd_vel_yaw' */
        floribot_task3_Y.cmd_vel_yaw = 0.5 * floribot_task3_DW.dir;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  floribot_task3_M->Timing.clockTick0++;
  if (!floribot_task3_M->Timing.clockTick0) {
    floribot_task3_M->Timing.clockTickH0++;
  }
}

/* Model initialize function */
void floribot_task3_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)floribot_task3_M, 0,
                sizeof(RT_MODEL_floribot_task3_T));

  /* states (dwork) */
  (void) memset((void *)&floribot_task3_DW, 0,
                sizeof(DW_floribot_task3_T));

  /* external inputs */
  (void) memset((void *)&floribot_task3_U, 0,
                sizeof(ExtU_floribot_task3_T));

  /* external outputs */
  (void) memset((void *)&floribot_task3_Y, 0,
                sizeof(ExtY_floribot_task3_T));

  /* InitializeConditions for Chart: '<Root>/Chart' */
  floribot_task3_DW.temporalCounter_i1 = 0U;
  floribot_task3_DW.is_active_c1_floribot_task3 = 0U;
  floribot_task3_DW.is_c1_floribot_task3 = floribot_tas_IN_NO_ACTIVE_CHILD;
  floribot_task3_DW.dir = 0.0;

  /* InitializeConditions for Outport: '<Root>/cmd_vel_x' incorporates:
   *  InitializeConditions for Chart: '<Root>/Chart'
   */
  floribot_task3_Y.cmd_vel_x = 0.0;

  /* InitializeConditions for Outport: '<Root>/cmd_vel_yaw' incorporates:
   *  InitializeConditions for Chart: '<Root>/Chart'
   */
  floribot_task3_Y.cmd_vel_yaw = 0.0;

  /* InitializeConditions for Chart: '<Root>/Chart' */
  floribot_task3_DW.presentTicks = 0U;
  floribot_task3_DW.elapsedTicks = 0U;
  floribot_task3_DW.previousTicks = 0U;

  /* Enable for Chart: '<Root>/Chart' */
  floribot_task3_DW.presentTicks = floribot_task3_M->Timing.clockTick0;
  floribot_task3_DW.previousTicks = floribot_task3_DW.presentTicks;
}

/* Model terminate function */
void floribot_task3_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
