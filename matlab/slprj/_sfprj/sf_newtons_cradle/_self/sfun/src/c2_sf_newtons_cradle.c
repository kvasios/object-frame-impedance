/* Include files */

#include "blascompat32.h"
#include "sf_newtons_cradle_sfun.h"
#include "c2_sf_newtons_cradle.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0U)
#define c2_IN_A                        (1U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c2_sf_newtons_cradle(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance);
static void initialize_params_c2_sf_newtons_cradle
  (SFc2_sf_newtons_cradleInstanceStruct *chartInstance);
static void enable_c2_sf_newtons_cradle(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance);
static void disable_c2_sf_newtons_cradle(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_sf_newtons_cradle
  (SFc2_sf_newtons_cradleInstanceStruct *chartInstance);
static void set_sim_state_c2_sf_newtons_cradle
  (SFc2_sf_newtons_cradleInstanceStruct *chartInstance, const mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_sf_newtons_cradle
  (SFc2_sf_newtons_cradleInstanceStruct *chartInstance);
static void finalize_c2_sf_newtons_cradle(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance);
static void sf_c2_sf_newtons_cradle(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static uint8_T c2_emlrt_marshallIn(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_sf_newtons_cradle, const
  char_T *c2_name);
static const mxArray *c2_b_emlrt_marshallIn(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_name);
static void init_dsm_address_info(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_sf_newtons_cradle(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_is_active_c2_sf_newtons_cradle = 0U;
  chartInstance->c2_is_c2_sf_newtons_cradle = 0U;
}

static void initialize_params_c2_sf_newtons_cradle
  (SFc2_sf_newtons_cradleInstanceStruct *chartInstance)
{
}

static void enable_c2_sf_newtons_cradle(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_sf_newtons_cradle(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c2_sf_newtons_cradle
  (SFc2_sf_newtons_cradleInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  uint8_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  c2_u = chartInstance->c2_is_active_c2_sf_newtons_cradle;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_u = chartInstance->c2_is_c2_sf_newtons_cradle;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_sf_newtons_cradle
  (SFc2_sf_newtons_cradleInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  c2_u = sf_mex_dup(c2_st);
  chartInstance->c2_is_active_c2_sf_newtons_cradle = c2_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
     "is_active_c2_sf_newtons_cradle");
  chartInstance->c2_is_c2_sf_newtons_cradle = c2_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "is_c2_sf_newtons_cradle");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 2)
    ), "setSimStateSideEffectsInfo"));
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_sf_newtons_cradle
  (SFc2_sf_newtons_cradleInstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_sf_newtons_cradle(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_c2_sf_newtons_cradle(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance)
{
  int32_T c2_previousEvent;
  int32_T c2_i0;
  real_T c2_dv0[7];
  real_T (*c2_p)[7];
  c2_p = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 0);
  c2_set_sim_state_side_effects_c2_sf_newtons_cradle(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  if (chartInstance->c2_is_active_c2_sf_newtons_cradle == 0) {
    chartInstance->c2_is_active_c2_sf_newtons_cradle = 1U;
    chartInstance->c2_is_c2_sf_newtons_cradle = c2_IN_A;
  } else {
    for (c2_i0 = 0; c2_i0 < 7; c2_i0 = c2_i0 + 1) {
      c2_dv0[c2_i0] = (*c2_p)[c2_i0];
    }

    sf_mex_call("sf_newtons_cradle_plotter", 0U, 1U, 14, sf_mex_create(
      "sf_newtons_cradle_plotter", &c2_dv0, 0, 0U, 1U, 0U, 1, 7));
  }

  _sfEvent_ = c2_previousEvent;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

const mxArray *sf_c2_sf_newtons_cradle_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c2_nameCaptureInfo;
}

static uint8_T c2_emlrt_marshallIn(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance, const mxArray *
  c2_b_is_active_c2_sf_newtons_cradle, const char_T *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_sf_newtons_cradle), &c2_u0,
                1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_sf_newtons_cradle);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallIn(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance, const mxArray *
  c2_b_setSimStateSideEffectsInfo, const char_T *c2_name)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe
                (&c2_b_setSimStateSideEffectsInfo));
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static void init_dsm_address_info(SFc2_sf_newtons_cradleInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_sf_newtons_cradle_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1856005712U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3376153583U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2893826222U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(240927225U);
}

mxArray *sf_c2_sf_newtons_cradle_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3139711464U);
    pr[1] = (double)(1376065895U);
    pr[2] = (double)(2085175330U);
    pr[3] = (double)(18754940U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_sf_newtons_cradle(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c2_sf_newtons_cradle\",},{M[9],M[0],T\"is_c2_sf_newtons_cradle\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_sf_newtons_cradle_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c2_sf_newtons_cradle(void *chartInstanceVar)
{
  initialize_params_c2_sf_newtons_cradle((SFc2_sf_newtons_cradleInstanceStruct*)
    chartInstanceVar);
  initialize_c2_sf_newtons_cradle((SFc2_sf_newtons_cradleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_sf_newtons_cradle(void *chartInstanceVar)
{
  enable_c2_sf_newtons_cradle((SFc2_sf_newtons_cradleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_sf_newtons_cradle(void *chartInstanceVar)
{
  disable_c2_sf_newtons_cradle((SFc2_sf_newtons_cradleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_sf_newtons_cradle(void *chartInstanceVar)
{
  sf_c2_sf_newtons_cradle((SFc2_sf_newtons_cradleInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c2_sf_newtons_cradle(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_sf_newtons_cradle
    ((SFc2_sf_newtons_cradleInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_sf_newtons_cradle();/* state var info */
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

static void sf_internal_set_sim_state_c2_sf_newtons_cradle(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_sf_newtons_cradle();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_sf_newtons_cradle((SFc2_sf_newtons_cradleInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_sf_newtons_cradle(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_sf_newtons_cradle(S);
}

static void sf_opaque_set_sim_state_c2_sf_newtons_cradle(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_sf_newtons_cradle(S, st);
}

static void sf_opaque_terminate_c2_sf_newtons_cradle(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_sf_newtons_cradleInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_sf_newtons_cradle((SFc2_sf_newtons_cradleInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_sf_newtons_cradle(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_sf_newtons_cradle((SFc2_sf_newtons_cradleInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_sf_newtons_cradle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("sf_newtons_cradle","sf_newtons_cradle",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("sf_newtons_cradle","sf_newtons_cradle",2,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("sf_newtons_cradle",
      "sf_newtons_cradle",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"sf_newtons_cradle",
        "sf_newtons_cradle",2,1);
    }

    sf_set_rtw_dwork_info(S,"sf_newtons_cradle","sf_newtons_cradle",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3208568600U));
  ssSetChecksum1(S,(3802033068U));
  ssSetChecksum2(S,(2101612914U));
  ssSetChecksum3(S,(521019949U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_sf_newtons_cradle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "sf_newtons_cradle", "sf_newtons_cradle",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_sf_newtons_cradle(SimStruct *S)
{
  SFc2_sf_newtons_cradleInstanceStruct *chartInstance;
  chartInstance = (SFc2_sf_newtons_cradleInstanceStruct *)malloc(sizeof
    (SFc2_sf_newtons_cradleInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_sf_newtons_cradleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_sf_newtons_cradle;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_sf_newtons_cradle;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_sf_newtons_cradle;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_sf_newtons_cradle;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_sf_newtons_cradle;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_sf_newtons_cradle;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_sf_newtons_cradle;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_sf_newtons_cradle;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_sf_newtons_cradle;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_sf_newtons_cradle;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_sf_newtons_cradle;
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

void c2_sf_newtons_cradle_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_sf_newtons_cradle(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_sf_newtons_cradle(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_sf_newtons_cradle(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_sf_newtons_cradle_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
