/*
 * Subsystem.c
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

#include "Subsystem.h"
#include "Subsystem_private.h"

/* Block states (default storage) */
DW_Subsystem_T Subsystem_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Subsystem_T Subsystem_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Subsystem_T Subsystem_Y;

/* Real-time model */
static RT_MODEL_Subsystem_T Subsystem_M_;
RT_MODEL_Subsystem_T *const Subsystem_M = &Subsystem_M_;

/* Model step function */
void Subsystem_step(void)
{
  real_T rtb_TSamp;

  /* SampleTimeMath: '<S2>/TSamp' incorporates:
   *  Constant: '<S1>/Set Spd'
   *  Inport: '<Root>/Speed Km//h'
   *  Sum: '<S1>/Sum'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = (50.0 - Subsystem_U.SpeedKmh) * 700.0;

  /* Outport: '<Root>/Force Correction' incorporates:
   *  Constant: '<S1>/Set Spd'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Gain: '<S1>/Gain'
   *  Inport: '<Root>/Speed Km//h'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S2>/Diff'
   *  UnitDelay: '<S2>/UD'
   */
  Subsystem_Y.ForceCorrection = ((50.0 - Subsystem_U.SpeedKmh) * 450.0 +
    Subsystem_DW.DiscreteTimeIntegrator_DSTATE) + (rtb_TSamp -
    Subsystem_DW.UD_DSTATE);

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Set Spd'
   *  Inport: '<Root>/Speed Km//h'
   *  Sum: '<S1>/Sum'
   */
  Subsystem_DW.DiscreteTimeIntegrator_DSTATE += (50.0 - Subsystem_U.SpeedKmh) *
    0.70000000000000007;

  /* Update for UnitDelay: '<S2>/UD' */
  Subsystem_DW.UD_DSTATE = rtb_TSamp;
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Subsystem_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Subsystem_DW, 0,
                sizeof(DW_Subsystem_T));

  /* external inputs */
  Subsystem_U.SpeedKmh = 0.0;

  /* external outputs */
  Subsystem_Y.ForceCorrection = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  Subsystem_DW.DiscreteTimeIntegrator_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S2>/UD' */
  Subsystem_DW.UD_DSTATE = 0.0;
}

/* Model terminate function */
void Subsystem_terminate(void)
{
  /* (no terminate code required) */
}
