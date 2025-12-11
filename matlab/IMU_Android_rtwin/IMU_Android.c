/*
 * IMU_Android.c
 *
 * Real-Time Workshop code generation for Simulink model "IMU_Android.mdl".
 *
 * Model version              : 1.18
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Mon Jan 21 19:03:22 2013
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IMU_Android.h"
#include "IMU_Android_private.h"
#include <stdio.h>
#include "IMU_Android_dt.h"

/* Block states (auto storage) */
D_Work_IMU_Android IMU_Android_DWork;

/* Real-time model */
RT_MODEL_IMU_Android IMU_Android_M_;
RT_MODEL_IMU_Android *IMU_Android_M = &IMU_Android_M_;

/* Model output function */
void IMU_Android_output(int_T tid)
{
  /* (no output code required) */

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void IMU_Android_update(int_T tid)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++IMU_Android_M->Timing.clockTick0)) {
    ++IMU_Android_M->Timing.clockTickH0;
  }

  IMU_Android_M->Timing.t[0] = IMU_Android_M->Timing.clockTick0 *
    IMU_Android_M->Timing.stepSize0 + IMU_Android_M->Timing.clockTickH0 *
    IMU_Android_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void IMU_Android_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)IMU_Android_M, 0,
                sizeof(RT_MODEL_IMU_Android));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = IMU_Android_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    IMU_Android_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    IMU_Android_M->Timing.sampleTimes = (&IMU_Android_M->
      Timing.sampleTimesArray[0]);
    IMU_Android_M->Timing.offsetTimes = (&IMU_Android_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    IMU_Android_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    IMU_Android_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(IMU_Android_M, &IMU_Android_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = IMU_Android_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    IMU_Android_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(IMU_Android_M, -1);
  IMU_Android_M->Timing.stepSize0 = 0.01;

  /* external mode info */
  IMU_Android_M->Sizes.checksums[0] = (4074957687U);
  IMU_Android_M->Sizes.checksums[1] = (2032700770U);
  IMU_Android_M->Sizes.checksums[2] = (1264137906U);
  IMU_Android_M->Sizes.checksums[3] = (2558086071U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    IMU_Android_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(IMU_Android_M->extModeInfo,
      &IMU_Android_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(IMU_Android_M->extModeInfo,
                        IMU_Android_M->Sizes.checksums);
    rteiSetTPtr(IMU_Android_M->extModeInfo, rtmGetTPtr(IMU_Android_M));
  }

  IMU_Android_M->solverInfoPtr = (&IMU_Android_M->solverInfo);
  IMU_Android_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&IMU_Android_M->solverInfo, 0.01);
  rtsiSetSolverMode(&IMU_Android_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* states (dwork) */
  IMU_Android_M->Work.dwork = ((void *) &IMU_Android_DWork);
  (void) memset((void *)&IMU_Android_DWork, 0,
                sizeof(D_Work_IMU_Android));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    IMU_Android_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;
  }
}

/* Model terminate function */
void IMU_Android_terminate(void)
{
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  IMU_Android_output(tid);
}

void MdlUpdate(int_T tid)
{
  IMU_Android_update(tid);
}

void MdlInitializeSizes(void)
{
  IMU_Android_M->Sizes.numContStates = (0);/* Number of continuous states */
  IMU_Android_M->Sizes.numY = (0);     /* Number of model outputs */
  IMU_Android_M->Sizes.numU = (0);     /* Number of model inputs */
  IMU_Android_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  IMU_Android_M->Sizes.numSampTimes = (1);/* Number of sample times */
  IMU_Android_M->Sizes.numBlocks = (2);/* Number of blocks */
  IMU_Android_M->Sizes.numBlockIO = (1);/* Number of block outputs */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  MdlInitialize();
}

void MdlTerminate(void)
{
  IMU_Android_terminate();
}

RT_MODEL_IMU_Android *IMU_Android(void)
{
  IMU_Android_initialize(1);
  return IMU_Android_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
