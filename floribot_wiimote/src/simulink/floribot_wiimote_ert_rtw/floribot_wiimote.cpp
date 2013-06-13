/*
 * File: floribot_wiimote.cpp
 *
 * Code generated for Simulink model 'floribot_wiimote'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Fri Jun 14 00:02:09 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "floribot_wiimote.h"
#include "floribot_wiimote_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define floribot__DIRECT_PITCH_AXIS_DIV (10.0)
#define floribot_w_DIRECT_ROLL_AXIS_DIV (30.0)
#define floribot_w_IN_control_x_and_yaw ((uint8_T)5U)
#define floribot_wii_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define floribot_wiimote_IN_Down       ((uint8_T)1U)
#define floribot_wiimote_IN_Left       ((uint8_T)2U)
#define floribot_wiimote_IN_Right      ((uint8_T)3U)
#define floribot_wiimote_IN_Up         ((uint8_T)4U)
#define floribot_wiimote_IN_automatic  ((uint8_T)1U)
#define floribot_wiimote_IN_manual     ((uint8_T)2U)
#define floribot_wiimote_IN_stand_still ((uint8_T)6U)

/* Block states (auto storage) */
DW_floribot_wiimote_T floribot_wiimote_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_floribot_wiimote_T floribot_wiimote_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_floribot_wiimote_T floribot_wiimote_Y;

/* Real-time model */
RT_MODEL_floribot_wiimote_T floribot_wiimote_M_;
RT_MODEL_floribot_wiimote_T *const floribot_wiimote_M = &floribot_wiimote_M_;

/* Model step function */
void floribot_wiimote_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/B'
   *  Inport: '<Root>/Button1'
   *  Inport: '<Root>/Button2'
   *  Inport: '<Root>/Down'
   *  Inport: '<Root>/Left'
   *  Inport: '<Root>/Right'
   *  Inport: '<Root>/Up'
   *  Inport: '<Root>/joy_pitch'
   *  Inport: '<Root>/joy_roll'
   */
  /* Gateway: Chart */
  /* During: Chart */
  if (floribot_wiimote_DW.is_active_c1_floribot_wiimote == 0U) {
    /* Entry: Chart */
    floribot_wiimote_DW.is_active_c1_floribot_wiimote = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:19' */
    floribot_wiimote_DW.is_c1_floribot_wiimote = floribot_wiimote_IN_manual;

    /* Outport: '<Root>/joy_led1' */
    /* Entry 'manual': '<S1>:17' */
    floribot_wiimote_Y.joy_led1 = TRUE;

    /* Outport: '<Root>/joy_led2' */
    floribot_wiimote_Y.joy_led2 = FALSE;

    /* Outport: '<Root>/joy_led3' */
    floribot_wiimote_Y.joy_led3 = FALSE;

    /* Outport: '<Root>/joy_led4' */
    floribot_wiimote_Y.joy_led4 = FALSE;

    /* Entry Internal 'manual': '<S1>:17' */
    /* Transition: '<S1>:23' */
    floribot_wiimote_DW.is_manual = floribot_wiimote_IN_stand_still;

    /* Outport: '<Root>/cmd_vel_x' */
    /* Entry 'stand_still': '<S1>:22' */
    floribot_wiimote_Y.cmd_vel_x = 0.0;

    /* Outport: '<Root>/cmd_vel_yaw' */
    floribot_wiimote_Y.cmd_vel_yaw = 0.0;
  } else if (floribot_wiimote_DW.is_c1_floribot_wiimote ==
             floribot_wiimote_IN_automatic) {
    /* During 'automatic': '<S1>:18' */
    if (floribot_wiimote_U.Button1) {
      /* Transition: '<S1>:21' */
      floribot_wiimote_DW.is_c1_floribot_wiimote = floribot_wiimote_IN_manual;

      /* Outport: '<Root>/joy_led1' */
      /* Entry 'manual': '<S1>:17' */
      floribot_wiimote_Y.joy_led1 = TRUE;

      /* Outport: '<Root>/joy_led2' */
      floribot_wiimote_Y.joy_led2 = FALSE;

      /* Outport: '<Root>/joy_led3' */
      floribot_wiimote_Y.joy_led3 = FALSE;

      /* Outport: '<Root>/joy_led4' */
      floribot_wiimote_Y.joy_led4 = FALSE;

      /* Entry Internal 'manual': '<S1>:17' */
      /* Transition: '<S1>:23' */
      floribot_wiimote_DW.is_manual = floribot_wiimote_IN_stand_still;

      /* Outport: '<Root>/cmd_vel_x' */
      /* Entry 'stand_still': '<S1>:22' */
      floribot_wiimote_Y.cmd_vel_x = 0.0;

      /* Outport: '<Root>/cmd_vel_yaw' */
      floribot_wiimote_Y.cmd_vel_yaw = 0.0;
    } else {
      /* Outport: '<Root>/cmd_vel_x' incorporates:
       *  Inport: '<Root>/task_x'
       */
      floribot_wiimote_Y.cmd_vel_x = floribot_wiimote_U.task_x;

      /* Outport: '<Root>/cmd_vel_yaw' incorporates:
       *  Inport: '<Root>/task_yaw'
       */
      floribot_wiimote_Y.cmd_vel_yaw = floribot_wiimote_U.task_yaw;

      /* Outport: '<Root>/joy_led1' */
      floribot_wiimote_Y.joy_led1 = FALSE;

      /* Outport: '<Root>/joy_led2' */
      floribot_wiimote_Y.joy_led2 = TRUE;

      /* Outport: '<Root>/joy_led3' */
      floribot_wiimote_Y.joy_led3 = FALSE;

      /* Outport: '<Root>/joy_led4' */
      floribot_wiimote_Y.joy_led4 = FALSE;
    }
  } else {
    /* During 'manual': '<S1>:17' */
    if (floribot_wiimote_U.Button2 && (!floribot_wiimote_U.Button1)) {
      /* Transition: '<S1>:20' */
      /* Exit Internal 'manual': '<S1>:17' */
      floribot_wiimote_DW.is_manual = floribot_wii_IN_NO_ACTIVE_CHILD;
      floribot_wiimote_DW.is_c1_floribot_wiimote = floribot_wiimote_IN_automatic;
    } else {
      switch (floribot_wiimote_DW.is_manual) {
       case floribot_wiimote_IN_Down:
        /* During 'Down': '<S1>:36' */
        if (!floribot_wiimote_U.Down) {
          /* Transition: '<S1>:38' */
          floribot_wiimote_DW.is_manual = floribot_wiimote_IN_stand_still;

          /* Outport: '<Root>/cmd_vel_x' */
          /* Entry 'stand_still': '<S1>:22' */
          floribot_wiimote_Y.cmd_vel_x = 0.0;

          /* Outport: '<Root>/cmd_vel_yaw' */
          floribot_wiimote_Y.cmd_vel_yaw = 0.0;
        } else {
          if (floribot_wiimote_U.joy_pitch < 0.0) {
            /* Outport: '<Root>/cmd_vel_x' incorporates:
             *  Inport: '<Root>/joy_pitch'
             */
            /* Transition: '<S1>:46' */
            floribot_wiimote_Y.cmd_vel_x = floribot_wiimote_U.joy_pitch /
              floribot__DIRECT_PITCH_AXIS_DIV;
            floribot_wiimote_DW.is_manual = floribot_wiimote_IN_Down;
          }
        }
        break;

       case floribot_wiimote_IN_Left:
        /* During 'Left': '<S1>:40' */
        if (!floribot_wiimote_U.Left) {
          /* Transition: '<S1>:44' */
          floribot_wiimote_DW.is_manual = floribot_wiimote_IN_stand_still;

          /* Outport: '<Root>/cmd_vel_x' */
          /* Entry 'stand_still': '<S1>:22' */
          floribot_wiimote_Y.cmd_vel_x = 0.0;

          /* Outport: '<Root>/cmd_vel_yaw' */
          floribot_wiimote_Y.cmd_vel_yaw = 0.0;
        } else {
          if (floribot_wiimote_U.joy_roll < 0.0) {
            /* Outport: '<Root>/cmd_vel_yaw' incorporates:
             *  Inport: '<Root>/joy_roll'
             */
            /* Transition: '<S1>:48' */
            floribot_wiimote_Y.cmd_vel_yaw = floribot_wiimote_U.joy_roll /
              floribot_w_DIRECT_ROLL_AXIS_DIV;
            floribot_wiimote_DW.is_manual = floribot_wiimote_IN_Left;
          }
        }
        break;

       case floribot_wiimote_IN_Right:
        /* During 'Right': '<S1>:39' */
        if (!floribot_wiimote_U.Right) {
          /* Transition: '<S1>:42' */
          floribot_wiimote_DW.is_manual = floribot_wiimote_IN_stand_still;

          /* Outport: '<Root>/cmd_vel_x' */
          /* Entry 'stand_still': '<S1>:22' */
          floribot_wiimote_Y.cmd_vel_x = 0.0;

          /* Outport: '<Root>/cmd_vel_yaw' */
          floribot_wiimote_Y.cmd_vel_yaw = 0.0;
        } else {
          if (floribot_wiimote_U.joy_roll > 0.0) {
            /* Outport: '<Root>/cmd_vel_yaw' incorporates:
             *  Inport: '<Root>/joy_roll'
             */
            /* Transition: '<S1>:47' */
            floribot_wiimote_Y.cmd_vel_yaw = floribot_wiimote_U.joy_roll /
              floribot_w_DIRECT_ROLL_AXIS_DIV;
            floribot_wiimote_DW.is_manual = floribot_wiimote_IN_Right;
          }
        }
        break;

       case floribot_wiimote_IN_Up:
        /* During 'Up': '<S1>:33' */
        if (!floribot_wiimote_U.Up) {
          /* Transition: '<S1>:35' */
          floribot_wiimote_DW.is_manual = floribot_wiimote_IN_stand_still;

          /* Outport: '<Root>/cmd_vel_x' */
          /* Entry 'stand_still': '<S1>:22' */
          floribot_wiimote_Y.cmd_vel_x = 0.0;

          /* Outport: '<Root>/cmd_vel_yaw' */
          floribot_wiimote_Y.cmd_vel_yaw = 0.0;
        } else {
          if (floribot_wiimote_U.joy_pitch > 0.0) {
            /* Outport: '<Root>/cmd_vel_x' incorporates:
             *  Inport: '<Root>/joy_pitch'
             */
            /* Transition: '<S1>:45' */
            floribot_wiimote_Y.cmd_vel_x = floribot_wiimote_U.joy_pitch /
              floribot__DIRECT_PITCH_AXIS_DIV;
            floribot_wiimote_DW.is_manual = floribot_wiimote_IN_Up;
          }
        }
        break;

       case floribot_w_IN_control_x_and_yaw:
        /* During 'control_x_and_yaw': '<S1>:24' */
        if (!floribot_wiimote_U.B) {
          /* Transition: '<S1>:26' */
          floribot_wiimote_DW.is_manual = floribot_wiimote_IN_stand_still;

          /* Outport: '<Root>/cmd_vel_x' */
          /* Entry 'stand_still': '<S1>:22' */
          floribot_wiimote_Y.cmd_vel_x = 0.0;

          /* Outport: '<Root>/cmd_vel_yaw' */
          floribot_wiimote_Y.cmd_vel_yaw = 0.0;
        } else {
          /* Outport: '<Root>/cmd_vel_x' incorporates:
           *  Inport: '<Root>/joy_pitch'
           */
          floribot_wiimote_Y.cmd_vel_x = floribot_wiimote_U.joy_pitch /
            floribot__DIRECT_PITCH_AXIS_DIV;

          /* Outport: '<Root>/cmd_vel_yaw' incorporates:
           *  Inport: '<Root>/joy_roll'
           */
          floribot_wiimote_Y.cmd_vel_yaw = floribot_wiimote_U.joy_roll /
            floribot_w_DIRECT_ROLL_AXIS_DIV;
        }
        break;

       default:
        /* During 'stand_still': '<S1>:22' */
        if (floribot_wiimote_U.B) {
          /* Transition: '<S1>:25' */
          floribot_wiimote_DW.is_manual = floribot_w_IN_control_x_and_yaw;
        } else if (floribot_wiimote_U.Up) {
          /* Transition: '<S1>:34' */
          floribot_wiimote_DW.is_manual = floribot_wiimote_IN_Up;
        } else if (floribot_wiimote_U.Down) {
          /* Transition: '<S1>:37' */
          floribot_wiimote_DW.is_manual = floribot_wiimote_IN_Down;
        } else if (floribot_wiimote_U.Right) {
          /* Transition: '<S1>:41' */
          floribot_wiimote_DW.is_manual = floribot_wiimote_IN_Right;
        } else {
          if (floribot_wiimote_U.Left) {
            /* Transition: '<S1>:43' */
            floribot_wiimote_DW.is_manual = floribot_wiimote_IN_Left;
          }
        }
        break;
      }
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void floribot_wiimote_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(floribot_wiimote_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&floribot_wiimote_DW, 0,
                sizeof(DW_floribot_wiimote_T));

  /* external inputs */
  (void) memset((void *)&floribot_wiimote_U, 0,
                sizeof(ExtU_floribot_wiimote_T));

  /* external outputs */
  (void) memset((void *)&floribot_wiimote_Y, 0,
                sizeof(ExtY_floribot_wiimote_T));

  /* InitializeConditions for Chart: '<Root>/Chart' */
  floribot_wiimote_DW.is_manual = floribot_wii_IN_NO_ACTIVE_CHILD;
  floribot_wiimote_DW.is_active_c1_floribot_wiimote = 0U;
  floribot_wiimote_DW.is_c1_floribot_wiimote = floribot_wii_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for Outport: '<Root>/cmd_vel_x' incorporates:
   *  InitializeConditions for Chart: '<Root>/Chart'
   */
  floribot_wiimote_Y.cmd_vel_x = 0.0;

  /* InitializeConditions for Outport: '<Root>/cmd_vel_yaw' incorporates:
   *  InitializeConditions for Chart: '<Root>/Chart'
   */
  floribot_wiimote_Y.cmd_vel_yaw = 0.0;

  /* InitializeConditions for Outport: '<Root>/joy_rumble' incorporates:
   *  InitializeConditions for Chart: '<Root>/Chart'
   */
  floribot_wiimote_Y.joy_rumble = 0.0;

  /* InitializeConditions for Outport: '<Root>/joy_led1' incorporates:
   *  InitializeConditions for Chart: '<Root>/Chart'
   */
  floribot_wiimote_Y.joy_led1 = FALSE;

  /* InitializeConditions for Outport: '<Root>/joy_led2' incorporates:
   *  InitializeConditions for Chart: '<Root>/Chart'
   */
  floribot_wiimote_Y.joy_led2 = FALSE;

  /* InitializeConditions for Outport: '<Root>/joy_led3' incorporates:
   *  InitializeConditions for Chart: '<Root>/Chart'
   */
  floribot_wiimote_Y.joy_led3 = FALSE;

  /* InitializeConditions for Outport: '<Root>/joy_led4' incorporates:
   *  InitializeConditions for Chart: '<Root>/Chart'
   */
  floribot_wiimote_Y.joy_led4 = FALSE;
}

/* Model terminate function */
void floribot_wiimote_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
