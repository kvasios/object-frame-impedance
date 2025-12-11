/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v02_sfun.h"
#include "c1_ODE_Hand_Model_v08_IPC_v02.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ODE_Hand_Model_v08_IPC_v02_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance);
static void initialize_params_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance);
static void enable_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance);
static void disable_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance);
static void set_sim_state_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance, const mxArray
   *c1_st);
static void c1_set_sim_state_side_effects_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance);
static void finalize_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance);
static void sf_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static uint8_T c1_emlrt_marshallIn(SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_ODE_Hand_Model_v08_IPC_v02,
  const char_T *c1_name);
static const mxArray *c1_b_emlrt_marshallIn
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance, const mxArray
   *c1_b_setSimStateSideEffectsInfo, const char_T *c1_name);
static void init_dsm_address_info(SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_is_active_c1_ODE_Hand_Model_v08_IPC_v02 = 0U;
}

static void initialize_params_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance)
{
}

static void enable_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance)
{
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_u;
  const mxArray *c1_b_y = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(1));
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_ODE_Hand_Model_v08_IPC_v02;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  chartInstance->c1_is_active_c1_ODE_Hand_Model_v08_IPC_v02 =
    c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                        "is_active_c1_ODE_Hand_Model_v08_IPC_v02");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)
    ), "setSimStateSideEffectsInfo"));
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_ODE_Hand_Model_v08_IPC_v02(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance
   )
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_ODE_Hand_Model_v08_IPC_v02
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance)
{
  int32_T c1_previousEvent;
  c1_set_sim_state_side_effects_c1_ODE_Hand_Model_v08_IPC_v02(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_ODE_Hand_Model_v08_IPC_v02MachineNumber_, chartInstance->chartNumber,
     chartInstance->
     instanceNumber);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray *sf_c1_ODE_Hand_Model_v08_IPC_v02_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c1_nameCaptureInfo;
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  boolean_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance;
  chartInstance = (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *)
    chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((boolean_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static uint8_T c1_emlrt_marshallIn(SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct
  *chartInstance, const mxArray *
  c1_b_is_active_c1_ODE_Hand_Model_v08_IPC_v02, const char_T *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_is_active_c1_ODE_Hand_Model_v08_IPC_v02),
                &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_b_is_active_c1_ODE_Hand_Model_v08_IPC_v02);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallIn
  (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance, const mxArray *
   c1_b_setSimStateSideEffectsInfo, const char_T *c1_name)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe
                (&c1_b_setSimStateSideEffectsInfo));
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static void init_dsm_address_info(SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *
  chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_ODE_Hand_Model_v08_IPC_v02_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2802920234U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678648956U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3206369403U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2370315360U);
}

mxArray *sf_c1_ODE_Hand_Model_v08_IPC_v02_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2858324061U);
    pr[1] = (double)(1721477666U);
    pr[2] = (double)(3011819823U);
    pr[3] = (double)(318792175U);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_ODE_Hand_Model_v08_IPC_v02(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c1_ODE_Hand_Model_v08_IPC_v02\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_ODE_Hand_Model_v08_IPC_v02_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance;
    chartInstance = (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_ODE_Hand_Model_v08_IPC_v02MachineNumber_,
           1,
           0,
           0,
           0,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_ODE_Hand_Model_v08_IPC_v02MachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_ODE_Hand_Model_v08_IPC_v02MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_ODE_Hand_Model_v08_IPC_v02MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_ODE_Hand_Model_v08_IPC_v02MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_ODE_Hand_Model_v08_IPC_v02(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_ODE_Hand_Model_v08_IPC_v02
    ((SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct*) chartInstanceVar);
  initialize_c1_ODE_Hand_Model_v08_IPC_v02
    ((SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_ODE_Hand_Model_v08_IPC_v02(void
  *chartInstanceVar)
{
  enable_c1_ODE_Hand_Model_v08_IPC_v02
    ((SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_ODE_Hand_Model_v08_IPC_v02(void
  *chartInstanceVar)
{
  disable_c1_ODE_Hand_Model_v08_IPC_v02
    ((SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_ODE_Hand_Model_v08_IPC_v02(void
  *chartInstanceVar)
{
  sf_c1_ODE_Hand_Model_v08_IPC_v02
    ((SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c1_ODE_Hand_Model_v08_IPC_v02
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_ODE_Hand_Model_v08_IPC_v02
    ((SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c1_ODE_Hand_Model_v08_IPC_v02();/* state var info */
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

static void sf_internal_set_sim_state_c1_ODE_Hand_Model_v08_IPC_v02(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_ODE_Hand_Model_v08_IPC_v02();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_ODE_Hand_Model_v08_IPC_v02
    ((SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c1_ODE_Hand_Model_v08_IPC_v02(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c1_ODE_Hand_Model_v08_IPC_v02(S);
}

static void sf_opaque_set_sim_state_c1_ODE_Hand_Model_v08_IPC_v02(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_ODE_Hand_Model_v08_IPC_v02(S, st);
}

static void sf_opaque_terminate_c1_ODE_Hand_Model_v08_IPC_v02(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_ODE_Hand_Model_v08_IPC_v02
      ((SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_ODE_Hand_Model_v08_IPC_v02(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_ODE_Hand_Model_v08_IPC_v02
      ((SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_ODE_Hand_Model_v08_IPC_v02(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v02",
      "ODE_Hand_Model_v08_IPC_v02",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v02",
                "ODE_Hand_Model_v08_IPC_v02",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v02","ODE_Hand_Model_v08_IPC_v02",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v02",
                          "ODE_Hand_Model_v08_IPC_v02",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(682437473U));
  ssSetChecksum1(S,(3095780968U));
  ssSetChecksum2(S,(2785961191U));
  ssSetChecksum3(S,(4143957716U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_ODE_Hand_Model_v08_IPC_v02(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v02",
      "ODE_Hand_Model_v08_IPC_v02",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_ODE_Hand_Model_v08_IPC_v02(SimStruct *S)
{
  SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *chartInstance;
  chartInstance = (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct *)malloc(sizeof
    (SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_ODE_Hand_Model_v08_IPC_v02InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_ODE_Hand_Model_v08_IPC_v02;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_ODE_Hand_Model_v08_IPC_v02;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_ODE_Hand_Model_v08_IPC_v02;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_ODE_Hand_Model_v08_IPC_v02;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_ODE_Hand_Model_v08_IPC_v02;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_ODE_Hand_Model_v08_IPC_v02;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_ODE_Hand_Model_v08_IPC_v02;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_ODE_Hand_Model_v08_IPC_v02;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_ODE_Hand_Model_v08_IPC_v02;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_ODE_Hand_Model_v08_IPC_v02;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_ODE_Hand_Model_v08_IPC_v02;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info(chartInstance);
  }

  chart_debug_initialization(S,1);
}

void c1_ODE_Hand_Model_v08_IPC_v02_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_ODE_Hand_Model_v08_IPC_v02(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_ODE_Hand_Model_v08_IPC_v02(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_ODE_Hand_Model_v08_IPC_v02(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_ODE_Hand_Model_v08_IPC_v02_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
