/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c19_ODE_Hand_Model_v08_IPC_v03.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c19_st);
static void finalize_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber);
static void c19_emlrt_marshallIn(SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c19_y, const char_T *c19_name, real_T c19_b_y[3]);
static uint8_T c19_b_emlrt_marshallIn
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c19_b_is_active_c19_ODE_Hand_Model_v08_IPC_v03, const char_T *c19_name);
static void init_dsm_address_info(SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c19_is_active_c19_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  int32_T c19_i0;
  real_T c19_u[3];
  const mxArray *c19_b_y = NULL;
  uint8_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  real_T (*c19_d_y)[3];
  c19_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellarray(2));
  for (c19_i0 = 0; c19_i0 < 3; c19_i0 = c19_i0 + 1) {
    c19_u[c19_i0] = (*c19_d_y)[c19_i0];
  }

  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_b_u = chartInstance->c19_is_active_c19_ODE_Hand_Model_v08_IPC_v03;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 1, c19_c_y);
  sf_mex_assign(&c19_st, c19_y);
  return c19_st;
}

static void set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance,
   const mxArray *c19_st)
{
  const mxArray *c19_u;
  real_T c19_dv0[3];
  int32_T c19_i1;
  real_T (*c19_y)[3];
  c19_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c19_u = sf_mex_dup(c19_st);
  c19_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 0)), "y",
                       c19_dv0);
  for (c19_i1 = 0; c19_i1 < 3; c19_i1 = c19_i1 + 1) {
    (*c19_y)[c19_i1] = c19_dv0[c19_i1];
  }

  chartInstance->c19_is_active_c19_ODE_Hand_Model_v08_IPC_v03 =
    c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u
    , 1)), "is_active_c19_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c19_u);
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c19_i2;
  real_T (*c19_y)[3];
  real_T (*c19_u)[4];
  c19_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c19_u = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  for (c19_i2 = 0; c19_i2 < 3; c19_i2 = c19_i2 + 1) {
    (*c19_y)[c19_i2] = (*c19_u)[c19_i2 + 1];
  }
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber)
{
}

const mxArray *sf_c19_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  sf_mex_assign(&c19_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c19_nameCaptureInfo;
}

static void c19_emlrt_marshallIn(SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c19_y, const char_T *
  c19_name, real_T c19_b_y[3])
{
  real_T c19_dv1[3];
  int32_T c19_i3;
  sf_mex_import(c19_name, sf_mex_dup(c19_y), &c19_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c19_i3 = 0; c19_i3 < 3; c19_i3 = c19_i3 + 1) {
    c19_b_y[c19_i3] = c19_dv1[c19_i3];
  }

  sf_mex_destroy(&c19_y);
}

static uint8_T c19_b_emlrt_marshallIn
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c19_b_is_active_c19_ODE_Hand_Model_v08_IPC_v03, const char_T *c19_name)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  sf_mex_import(c19_name, sf_mex_dup
                (c19_b_is_active_c19_ODE_Hand_Model_v08_IPC_v03), &c19_u0, 1, 3,
                0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_b_is_active_c19_ODE_Hand_Model_v08_IPC_v03);
  return c19_y;
}

static void init_dsm_address_info(SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c19_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(544981954U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2477708764U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4263718701U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1907141687U);
}

mxArray *sf_c19_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(492932172U);
    pr[1] = (double)(2764478348U);
    pr[2] = (double)(4062781912U);
    pr[3] = (double)(3761809077U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c19_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c19_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c19_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c19_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c19_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c19_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c19_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

static void sf_internal_set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c19_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c19_ODE_Hand_Model_v08_IPC_v03
      ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c19_ODE_Hand_Model_v08_IPC_v03
      ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",19,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",19,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",19,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3947339199U));
  ssSetChecksum1(S,(2357617671U));
  ssSetChecksum2(S,(4218539048U));
  ssSetChecksum3(S,(1947644901U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",19);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc
    (sizeof(SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info(chartInstance);
  }
}

void c19_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
