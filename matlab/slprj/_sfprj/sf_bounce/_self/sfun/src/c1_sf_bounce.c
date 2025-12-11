/* Include files */

#include "blascompat32.h"
#include "sf_bounce_sfun.h"
#include "c1_sf_bounce.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0U)
#define c1_IN_Falling                  (1U)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_sf_bounceInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_sf_bounce(void);
static void initialize_params_c1_sf_bounce(void);
static void enable_c1_sf_bounce(void);
static void disable_c1_sf_bounce(void);
static const mxArray *get_sim_state_c1_sf_bounce(void);
static void set_sim_state_c1_sf_bounce(const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_sf_bounce(void);
static void finalize_c1_sf_bounce(void);
static void sf_c1_sf_bounce(void);
static void zeroCrossings_c1_sf_bounce(void);
static void derivatives_c1_sf_bounce(void);
static void outputs_c1_sf_bounce(void);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_emlrt_marshallOut(void);
static const mxArray *c1_b_emlrt_marshallOut(real_T c1_u);
static const mxArray *c1_c_emlrt_marshallOut(uint8_T c1_u);
static void c1_emlrt_marshallIn(const mxArray *c1_u);
static real_T c1_b_emlrt_marshallIn(const mxArray *c1_p_out, const char_T
  *c1_name);
static uint8_T c1_c_emlrt_marshallIn(const mxArray *c1_b_is_active_c1_sf_bounce,
  const char_T *c1_name);
static const mxArray *c1_d_emlrt_marshallIn(const mxArray
  *c1_b_setSimStateSideEffectsInfo, const char_T *c1_name);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c1_sf_bounce(void)
{
  real_T *c1_p;
  real_T *c1_v;
  real_T *c1_p_out;
  real_T *c1_v_out;
  c1_v_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c1_v = (real_T *)(ssGetContStates(chartInstance.S) + 1);
  c1_p = (real_T *)(ssGetContStates(chartInstance.S) + 0);
  c1_p_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c1_doSetSimStateSideEffects = 0U;
  chartInstance.c1_setSimStateSideEffectsInfo = NULL;
  chartInstance.c1_is_active_c1_sf_bounce = 0U;
  chartInstance.c1_is_c1_sf_bounce = 0U;
  *c1_p = 3.0;
  *c1_v = 0.0;
  if (!(cdrGetOutputPortReusable(chartInstance.S, 1) != 0)) {
    *c1_p_out = 0.0;
  }

  if (!(cdrGetOutputPortReusable(chartInstance.S, 2) != 0)) {
    *c1_v_out = 0.0;
  }

  chartInstance.c1_is_active_c1_sf_bounce = 1U;
  *c1_p = 10.0;
  *c1_v = 15.0;
  chartInstance.c1_is_c1_sf_bounce = c1_IN_Falling;
}

static void initialize_params_c1_sf_bounce(void)
{
}

static void enable_c1_sf_bounce(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c1_sf_bounce(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static const mxArray *get_sim_state_c1_sf_bounce(void)
{
  const mxArray *c1_st = NULL;
  c1_st = NULL;
  sf_mex_assign(&c1_st, c1_emlrt_marshallOut());
  return c1_st;
}

static void set_sim_state_c1_sf_bounce(const mxArray *c1_st)
{
  c1_emlrt_marshallIn(sf_mex_dup(c1_st));
  chartInstance.c1_doSetSimStateSideEffects = 1U;
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_sf_bounce(void)
{
  if (chartInstance.c1_doSetSimStateSideEffects != 0) {
    chartInstance.c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_sf_bounce(void)
{
  sf_mex_destroy(&chartInstance.c1_setSimStateSideEffectsInfo);
}

static void sf_c1_sf_bounce(void)
{
  boolean_T c1_stateChanged;
  int32_T c1_previousEvent;
  real_T *c1_p;
  real_T *c1_v;
  real_T *c1_p_out;
  real_T *c1_v_out;
  c1_v_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c1_v = (real_T *)(ssGetContStates(chartInstance.S) + 1);
  c1_p = (real_T *)(ssGetContStates(chartInstance.S) + 0);
  c1_p_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_set_sim_state_side_effects_c1_sf_bounce();
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c1_lastMajorTime = _sfTime_;
  c1_stateChanged = (boolean_T)0;
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  *c1_p_out = 0.0;
  *c1_v_out = 0.0;
  if ((*c1_p <= 0.0) && (*c1_v < 0.0)) {
    *c1_p = 0.0;
    *c1_v = -0.8 * *c1_v;
    c1_stateChanged = TRUE;
    chartInstance.c1_is_c1_sf_bounce = c1_IN_Falling;
  }

  _sfEvent_ = c1_previousEvent;
  if (c1_stateChanged) {
    ssSetSolverNeedsReset(chartInstance.S);
  }
}

static void zeroCrossings_c1_sf_bounce(void)
{
  boolean_T c1_stateChanged;
  real_T *c1_zcVar;
  real_T *c1_p;
  real_T *c1_v;
  c1_v = (real_T *)(ssGetContStates(chartInstance.S) + 1);
  c1_p = (real_T *)(ssGetContStates(chartInstance.S) + 0);
  c1_zcVar = (real_T *)(ssGetNonsampledZCs(chartInstance.S) + 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  if (chartInstance.c1_lastMajorTime == _sfTime_) {
    *c1_zcVar = -1.0;
  } else {
    c1_stateChanged = (boolean_T)0;
    if ((*c1_p <= 0.0) && (*c1_v < 0.0)) {
      c1_stateChanged = TRUE;
    }

    if (c1_stateChanged) {
      *c1_zcVar = 1.0;
    } else {
      *c1_zcVar = -1.0;
    }
  }
}

static void derivatives_c1_sf_bounce(void)
{
  real_T *c1_v;
  real_T *c1_p_dot;
  real_T *c1_v_dot;
  c1_v_dot = (real_T *)(ssGetdX(chartInstance.S) + 1);
  c1_v = (real_T *)(ssGetContStates(chartInstance.S) + 1);
  c1_p_dot = (real_T *)(ssGetdX(chartInstance.S) + 0);
  *c1_p_dot = 0.0;
  *c1_v_dot = 0.0;
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c1_p_dot = *c1_v;
  *c1_v_dot = -9.81;
}

static void outputs_c1_sf_bounce(void)
{
  real_T *c1_p;
  real_T *c1_p_out;
  real_T *c1_v;
  real_T *c1_v_out;
  c1_v_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c1_v = (real_T *)(ssGetContStates(chartInstance.S) + 1);
  c1_p = (real_T *)(ssGetContStates(chartInstance.S) + 0);
  c1_p_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c1_p_out = *c1_p;
  *c1_v_out = *c1_v;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray *sf_c1_sf_bounce_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c1_nameCaptureInfo;
}

static const mxArray *c1_emlrt_marshallOut(void)
{
  const mxArray *c1_y;
  real_T *c1_p_out;
  real_T *c1_v_out;
  real_T *c1_p;
  real_T *c1_v;
  c1_v_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c1_v = (real_T *)(ssGetContStates(chartInstance.S) + 1);
  c1_p = (real_T *)(ssGetContStates(chartInstance.S) + 0);
  c1_p_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(6));
  sf_mex_setcell(c1_y, 0, c1_b_emlrt_marshallOut(*c1_p_out));
  sf_mex_setcell(c1_y, 1, c1_b_emlrt_marshallOut(*c1_v_out));
  sf_mex_setcell(c1_y, 2, c1_b_emlrt_marshallOut(*c1_p));
  sf_mex_setcell(c1_y, 3, c1_b_emlrt_marshallOut(*c1_v));
  sf_mex_setcell(c1_y, 4, c1_c_emlrt_marshallOut
                 (chartInstance.c1_is_active_c1_sf_bounce));
  sf_mex_setcell(c1_y, 5, c1_c_emlrt_marshallOut
                 (chartInstance.c1_is_c1_sf_bounce));
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(real_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  return c1_y;
}

static const mxArray *c1_c_emlrt_marshallOut(uint8_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0));
  return c1_y;
}

static void c1_emlrt_marshallIn(const mxArray *c1_u)
{
  real_T *c1_p_out;
  real_T *c1_v_out;
  real_T *c1_p;
  real_T *c1_v;
  c1_v_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c1_v = (real_T *)(ssGetContStates(chartInstance.S) + 1);
  c1_p = (real_T *)(ssGetContStates(chartInstance.S) + 0);
  c1_p_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  *c1_p_out = c1_b_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 0)), "p_out");
  *c1_v_out = c1_b_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 1)), "v_out");
  *c1_p = c1_b_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 2)), "p");
  *c1_v = c1_b_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 3)), "v");
  chartInstance.c1_is_active_c1_sf_bounce = c1_c_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c1_u, 4)), "is_active_c1_sf_bounce");
  chartInstance.c1_is_c1_sf_bounce = c1_c_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c1_u, 5)), "is_c1_sf_bounce");
  sf_mex_assign(&chartInstance.c1_setSimStateSideEffectsInfo,
                c1_d_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c1_u, 6)),
    "setSimStateSideEffectsInfo"));
  sf_mex_destroy(&c1_u);
}

static real_T c1_b_emlrt_marshallIn(const mxArray *c1_p_out, const char_T
  *c1_name)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_name, sf_mex_dup(c1_p_out), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_p_out);
  return c1_y;
}

static uint8_T c1_c_emlrt_marshallIn(const mxArray *c1_b_is_active_c1_sf_bounce,
  const char_T *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_is_active_c1_sf_bounce), &c1_u0, 1, 3,
                0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_b_is_active_c1_sf_bounce);
  return c1_y;
}

static const mxArray *c1_d_emlrt_marshallIn(const mxArray
  *c1_b_setSimStateSideEffectsInfo, const char_T *c1_name)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe
                (&c1_b_setSimStateSideEffectsInfo));
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c1_sf_bounce_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4275988984U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1011765098U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2738341276U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1986075523U);
}

mxArray *sf_c1_sf_bounce_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2434034508U);
    pr[1] = (double)(2783370984U);
    pr[2] = (double)(2315019118U);
    pr[3] = (double)(2838460565U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_sf_bounce(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[4],T\"p_out\",},{M[1],M[8],T\"v_out\",},{M[5],M[6],T\"p\",},{M[5],M[7],T\"v\",},{M[8],M[0],T\"is_active_c1_sf_bounce\",},{M[9],M[0],T\"is_c1_sf_bounce\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_sf_bounce_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c1_sf_bounce(void *chartInstanceVar)
{
  initialize_params_c1_sf_bounce();
  initialize_c1_sf_bounce();
}

static void sf_opaque_enable_c1_sf_bounce(void *chartInstanceVar)
{
  enable_c1_sf_bounce();
}

static void sf_opaque_disable_c1_sf_bounce(void *chartInstanceVar)
{
  disable_c1_sf_bounce();
}

static void sf_opaque_zeroCrossings_c1_sf_bounce(void *chartInstanceVar)
{
  zeroCrossings_c1_sf_bounce();
}

static void sf_opaque_outputs_c1_sf_bounce(void *chartInstanceVar)
{
  outputs_c1_sf_bounce();
}

static void sf_opaque_derivatives_c1_sf_bounce(void *chartInstanceVar)
{
  derivatives_c1_sf_bounce();
}

static void sf_opaque_gateway_c1_sf_bounce(void *chartInstanceVar)
{
  sf_c1_sf_bounce();
}

static mxArray* sf_internal_get_sim_state_c1_sf_bounce(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_sf_bounce();/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c1_sf_bounce();/* state var info */
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

static void sf_internal_set_sim_state_c1_sf_bounce(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_sf_bounce();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_sf_bounce(mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c1_sf_bounce(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_sf_bounce(S);
}

static void sf_opaque_set_sim_state_c1_sf_bounce(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_sf_bounce(S, st);
}

static void sf_opaque_terminate_c1_sf_bounce(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c1_sf_bounce();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_sf_bounce(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_sf_bounce();
  }
}

static void mdlSetWorkWidths_c1_sf_bounce(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("sf_bounce","sf_bounce",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("sf_bounce","sf_bounce",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("sf_bounce","sf_bounce",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,"sf_bounce","sf_bounce",1,2);
    }

    sf_set_rtw_dwork_info(S,"sf_bounce","sf_bounce",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
    ssSetCallsOutputInInitFcn(S,1);
  }

  ssSetChecksum0(S,(3947157759U));
  ssSetChecksum1(S,(2182980953U));
  ssSetChecksum2(S,(3621922550U));
  ssSetChecksum3(S,(3888787765U));
  ssSetNumContStates(S,2);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_sf_bounce(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "sf_bounce", "sf_bounce",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_sf_bounce(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 0;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c1_sf_bounce;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c1_sf_bounce;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c1_sf_bounce;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c1_sf_bounce;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c1_sf_bounce;
  chartInstance.chartInfo.getSimState = sf_opaque_get_sim_state_c1_sf_bounce;
  chartInstance.chartInfo.setSimState = sf_opaque_set_sim_state_c1_sf_bounce;
  chartInstance.chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_sf_bounce;
  chartInstance.chartInfo.zeroCrossings = sf_opaque_zeroCrossings_c1_sf_bounce;
  chartInstance.chartInfo.outputs = sf_opaque_outputs_c1_sf_bounce;
  chartInstance.chartInfo.derivatives = sf_opaque_derivatives_c1_sf_bounce;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_sf_bounce;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_sf_bounce;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_sf_bounce;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c1_sf_bounce_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_sf_bounce(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_sf_bounce(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_sf_bounce(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_sf_bounce_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
