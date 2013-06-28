/*
 * File: floribot_task3.h
 *
 * Code generated for Simulink model 'floribot_task3'.
 *
 * Model version                  : 1.111
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Fri Jun 28 14:07:49 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_floribot_task3_h_
#define RTW_HEADER_floribot_task3_h_
#ifndef floribot_task3_COMMON_INCLUDES_
# define floribot_task3_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* floribot_task3_COMMON_INCLUDES_ */

#include "floribot_task3_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T dir;                          /* '<Root>/Chart' */
  int32_T count;                       /* '<Root>/Chart' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint32_T presentTicks;               /* '<Root>/Chart' */
  uint32_T elapsedTicks;               /* '<Root>/Chart' */
  uint32_T previousTicks;              /* '<Root>/Chart' */
  uint8_T is_active_c1_floribot_task3; /* '<Root>/Chart' */
  uint8_T is_c1_floribot_task3;        /* '<Root>/Chart' */
  uint8_T is_no_danger;                /* '<Root>/Chart' */
} DW_floribot_task3_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T left_row_y;                   /* '<Root>/left_row_y' */
  real_T left_row_prob;                /* '<Root>/left_row_prob' */
  real_T right_row_y;                  /* '<Root>/right_row_y' */
  real_T right_row_prob;               /* '<Root>/right_row_prob' */
  real_T front_row_x;                  /* '<Root>/front_row_x' */
  real_T front_row_prob;               /* '<Root>/front_row_prob' */
  real_T row_width;                    /* '<Root>/row_width' */
  real_T prob_threshold;               /* '<Root>/prob_threshold' */
  real_T direction;                    /* '<Root>/direction' */
  real_T leav_vel_x;                   /* '<Root>/leav_vel_x' */
  real_T turn_vel_x;                   /* '<Root>/turn_vel_x' */
  real_T turn_vel_yaw;                 /* '<Root>/turn_vel_yaw' */
  real_T leav_time;                    /* '<Root>/leav_time' */
  real_T turn_time;                    /* '<Root>/turn_time' */
} ExtU_floribot_task3_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T cmd_vel_x;                    /* '<Root>/cmd_vel_x' */
  real_T cmd_vel_yaw;                  /* '<Root>/cmd_vel_yaw' */
} ExtY_floribot_task3_T;

/* Real-time Model Data Structure */
struct tag_RTM_floribot_task3_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
  } Timing;
};

/* Block states (auto storage) */
extern DW_floribot_task3_T floribot_task3_DW;

/* External inputs (root inport signals with auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern ExtU_floribot_task3_T floribot_task3_U;

#ifdef __cplusplus

}
#endif

/* External outputs (root outports fed by signals with auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern ExtY_floribot_task3_T floribot_task3_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void floribot_task3_initialize(void);
  extern void floribot_task3_step(void);
  extern void floribot_task3_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_floribot_task3_T *const floribot_task3_M;

#ifdef __cplusplus

}
#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'floribot_task3'
 * '<S1>'   : 'floribot_task3/Chart'
 */
#endif                                 /* RTW_HEADER_floribot_task3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
