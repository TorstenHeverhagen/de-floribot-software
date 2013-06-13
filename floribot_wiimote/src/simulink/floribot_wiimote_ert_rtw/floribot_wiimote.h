/*
 * File: floribot_wiimote.h
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

#ifndef RTW_HEADER_floribot_wiimote_h_
#define RTW_HEADER_floribot_wiimote_h_
#ifndef floribot_wiimote_COMMON_INCLUDES_
# define floribot_wiimote_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* floribot_wiimote_COMMON_INCLUDES_ */

#include "floribot_wiimote_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c1_floribot_wiimote;/* '<Root>/Chart' */
  uint8_T is_c1_floribot_wiimote;      /* '<Root>/Chart' */
  uint8_T is_manual;                   /* '<Root>/Chart' */
} DW_floribot_wiimote_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  boolean_T A;                         /* '<Root>/A' */
  boolean_T B;                         /* '<Root>/B' */
  boolean_T Button1;                   /* '<Root>/Button1' */
  boolean_T Button2;                   /* '<Root>/Button2' */
  real_T joy_pitch;                    /* '<Root>/joy_pitch' */
  real_T joy_roll;                     /* '<Root>/joy_roll' */
  real_T joy_yaw;                      /* '<Root>/joy_yaw' */
  real_T task_x;                       /* '<Root>/task_x' */
  real_T task_yaw;                     /* '<Root>/task_yaw' */
  boolean_T Up;                        /* '<Root>/Up' */
  boolean_T Down;                      /* '<Root>/Down' */
  boolean_T Right;                     /* '<Root>/Right' */
  boolean_T Left;                      /* '<Root>/Left' */
} ExtU_floribot_wiimote_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T cmd_vel_x;                    /* '<Root>/cmd_vel_x' */
  real_T cmd_vel_yaw;                  /* '<Root>/cmd_vel_yaw' */
  real_T joy_rumble;                   /* '<Root>/joy_rumble' */
  boolean_T joy_led1;                  /* '<Root>/joy_led1' */
  boolean_T joy_led2;                  /* '<Root>/joy_led2' */
  boolean_T joy_led3;                  /* '<Root>/joy_led3' */
  boolean_T joy_led4;                  /* '<Root>/joy_led4' */
} ExtY_floribot_wiimote_T;

/* Real-time Model Data Structure */
struct tag_RTM_floribot_wiimote_T {
  const char_T * volatile errorStatus;
};

/* Block states (auto storage) */
extern DW_floribot_wiimote_T floribot_wiimote_DW;

/* External inputs (root inport signals with auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern ExtU_floribot_wiimote_T floribot_wiimote_U;

#ifdef __cplusplus

}
#endif

/* External outputs (root outports fed by signals with auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern ExtY_floribot_wiimote_T floribot_wiimote_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void floribot_wiimote_initialize(void);
  extern void floribot_wiimote_step(void);
  extern void floribot_wiimote_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_floribot_wiimote_T *const floribot_wiimote_M;

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
 * '<Root>' : 'floribot_wiimote'
 * '<S1>'   : 'floribot_wiimote/Chart'
 */
#endif                                 /* RTW_HEADER_floribot_wiimote_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
