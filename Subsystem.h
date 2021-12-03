/*
 * Subsystem.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Subsystem".
 *
 * Model version              : 1.18
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sun Nov 28 16:52:05 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Subsystem_h_
#define RTW_HEADER_Subsystem_h_
#include <stddef.h>
#include <string.h>
#ifndef Subsystem_COMMON_INCLUDES_
#define Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Subsystem_COMMON_INCLUDES_ */

#include "Subsystem_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S2>/UD' */
} DW_Subsystem_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T SpeedKmh;                     /* '<Root>/Speed Km//h' */
} ExtU_Subsystem_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T ForceCorrection;              /* '<Root>/Force Correction' */
} ExtY_Subsystem_T;

/* Real-time Model Data Structure */
struct tag_RTM_Subsystem_T {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_Subsystem_T Subsystem_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Subsystem_T Subsystem_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Subsystem_T Subsystem_Y;

/* Model entry point functions */
extern void Subsystem_initialize(void);
extern void Subsystem_step(void);
extern void Subsystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Subsystem_T *const Subsystem_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Duplicate' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('CC/Subsystem Reference')    - opens subsystem CC/Subsystem Reference
 * hilite_system('CC/Subsystem Reference/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CC'
 * '<S1>'   : 'CC/Subsystem Reference'
 * '<S2>'   : 'CC/Subsystem Reference/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_Subsystem_h_ */
