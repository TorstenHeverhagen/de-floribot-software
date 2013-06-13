/*
 * File: floribot_accu_watchdog.h
 *
 * Code generated for Simulink model 'floribot_accu_watchdog'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Thu Jun 13 11:54:35 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_floribot_accu_watchdog_h_
#define RTW_HEADER_floribot_accu_watchdog_h_
#ifndef floribot_accu_watchdog_COMMON_INCLUDES_
# define floribot_accu_watchdog_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* floribot_accu_watchdog_COMMON_INCLUDES_ */

#include "floribot_accu_watchdog_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c1_floribot_accu_watc;/* '<Root>/Chart' */
  uint8_T is_c1_floribot_accu_watchdog;/* '<Root>/Chart' */
} DW_floribot_accu_watchdog_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T voltage;                      /* '<Root>/voltage' */
} ExtU_floribot_accu_watchdog_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T accu_low;                  /* '<Root>/accu_low' */
} ExtY_floribot_accu_watchdog_T;

/* Real-time Model Data Structure */
struct tag_RTM_floribot_accu_watchdo_T {
  const char_T * volatile errorStatus;
};

/* Block states (auto storage) */
extern DW_floribot_accu_watchdog_T floribot_accu_watchdog_DW;

/* External inputs (root inport signals with auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern ExtU_floribot_accu_watchdog_T floribot_accu_watchdog_U;

#ifdef __cplusplus

}
#endif

/* External outputs (root outports fed by signals with auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern ExtY_floribot_accu_watchdog_T floribot_accu_watchdog_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void floribot_accu_watchdog_initialize(void);
  extern void floribot_accu_watchdog_step(void);
  extern void floribot_accu_watchdog_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_floribot_accu_watchd_T *const floribot_accu_watchdog_M;

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
 * '<Root>' : 'floribot_accu_watchdog'
 * '<S1>'   : 'floribot_accu_watchdog/Chart'
 */
#endif                                 /* RTW_HEADER_floribot_accu_watchdog_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
