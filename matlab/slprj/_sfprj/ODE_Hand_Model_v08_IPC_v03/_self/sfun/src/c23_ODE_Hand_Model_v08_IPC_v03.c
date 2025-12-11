/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c23_ODE_Hand_Model_v08_IPC_v03.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c23_st);
static void finalize_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber);
static void c23_emlrt_marshallIn(SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c23_r_f, const char_T *c23_name, real_T c23_y[3]);
static uint8_T c23_b_emlrt_marshallIn
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c23_b_is_active_c23_ODE_Hand_Model_v08_IPC_v03, const char_T *c23_name);
static void init_dsm_address_info(SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c23_is_active_c23_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  int32_T c23_i0;
  real_T c23_u[3];
  const mxArray *c23_b_y = NULL;
  real_T c23_b_u[3];
  const mxArray *c23_c_y = NULL;
  uint8_T c23_c_u;
  const mxArray *c23_d_y = NULL;
  real_T (*c23_x_f)[3];
  real_T (*c23_r_f)[3];
  c23_r_f = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c23_x_f = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellarray(3));
  for (c23_i0 = 0; c23_i0 < 3; c23_i0 = c23_i0 + 1) {
    c23_u[c23_i0] = (*c23_r_f)[c23_i0];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_setcell(c23_y, 0, c23_b_y);
  for (c23_i0 = 0; c23_i0 < 3; c23_i0 = c23_i0 + 1) {
    c23_b_u[c23_i0] = (*c23_x_f)[c23_i0];
  }

  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_setcell(c23_y, 1, c23_c_y);
  c23_c_u = chartInstance->c23_is_active_c23_ODE_Hand_Model_v08_IPC_v03;
  c23_d_y = NULL;
  sf_mex_assign(&c23_d_y, sf_mex_create("y", &c23_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c23_y, 2, c23_d_y);
  sf_mex_assign(&c23_st, c23_y);
  return c23_st;
}

static void set_sim_state_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance,
   const mxArray *c23_st)
{
  const mxArray *c23_u;
  real_T c23_dv0[3];
  int32_T c23_i1;
  real_T (*c23_x_f)[3];
  real_T (*c23_r_f)[3];
  c23_r_f = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c23_x_f = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c23_u = sf_mex_dup(c23_st);
  c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 0)),
                       "r_f", c23_dv0);
  for (c23_i1 = 0; c23_i1 < 3; c23_i1 = c23_i1 + 1) {
    (*c23_r_f)[c23_i1] = c23_dv0[c23_i1];
  }

  c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 1)),
                       "x_f", c23_dv0);
  for (c23_i1 = 0; c23_i1 < 3; c23_i1 = c23_i1 + 1) {
    (*c23_x_f)[c23_i1] = c23_dv0[c23_i1];
  }

  chartInstance->c23_is_active_c23_ODE_Hand_Model_v08_IPC_v03 =
    c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u
    , 2)), "is_active_c23_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c23_u);
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c23_ODE_Hand_Model_v08_IPC_v03
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c23_previousEvent;
  int32_T c23_i2;
  real_T *c23_key;
  real_T (*c23_x_f)[3];
  real_T (*c23_r_f)[3];
  c23_r_f = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c23_x_f = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c23_key = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c23_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;

  /*  torque_signal_out=zeros(1,16); */
  for (c23_i2 = 0; c23_i2 < 3; c23_i2 = c23_i2 + 1) {
    (*c23_x_f)[c23_i2] = 0.0;
    (*c23_r_f)[c23_i2] = 0.0;
  }

  /*  q_incr = pi/8; */
  switch ((int32_T)*c23_key) {
   case 30:
    (*c23_x_f)[0] = 0.01;
    break;

   case 31:
    (*c23_x_f)[0] = -0.01;
    break;

   case 28:
    (*c23_x_f)[1] = 0.01;
    break;

   case 29:
    (*c23_x_f)[1] = -0.01;
    break;

   case 56:
    (*c23_x_f)[2] = 0.01;
    break;

   case 50:
    (*c23_x_f)[2] = -0.01;
    break;

   case 119:
    (*c23_r_f)[0] = 0.01;
    break;

   case 120:
    (*c23_r_f)[0] = -0.01;
    break;

   case 97:
    (*c23_r_f)[1] = 0.01;
    break;

   case 100:
    (*c23_r_f)[1] = -0.01;
    break;

   case 113:
    (*c23_r_f)[2] = 0.01;
    break;

   case 99:
    (*c23_r_f)[2] = -0.01;
    break;
  }

  _sfEvent_ = c23_previousEvent;
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber)
{
}

const mxArray *sf_c23_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c23_nameCaptureInfo;
  c23_ResolvedFunctionInfo c23_info[3];
  c23_ResolvedFunctionInfo (*c23_b_info)[3];
  const mxArray *c23_m0 = NULL;
  int32_T c23_i3;
  c23_ResolvedFunctionInfo *c23_r0;
  c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
  c23_b_info = (c23_ResolvedFunctionInfo (*)[3])c23_info;
  (*c23_b_info)[0].context = "";
  (*c23_b_info)[0].name = "zeros";
  (*c23_b_info)[0].dominantType = "double";
  (*c23_b_info)[0].resolved = "[B]zeros";
  (*c23_b_info)[0].fileLength = 0U;
  (*c23_b_info)[0].fileTime1 = 0U;
  (*c23_b_info)[0].fileTime2 = 0U;
  (*c23_b_info)[1].context = "";
  (*c23_b_info)[1].name = "uint8";
  (*c23_b_info)[1].dominantType = "char";
  (*c23_b_info)[1].resolved = "[B]uint8";
  (*c23_b_info)[1].fileLength = 0U;
  (*c23_b_info)[1].fileTime1 = 0U;
  (*c23_b_info)[1].fileTime2 = 0U;
  (*c23_b_info)[2].context = "";
  (*c23_b_info)[2].name = "uminus";
  (*c23_b_info)[2].dominantType = "double";
  (*c23_b_info)[2].resolved = "[B]uminus";
  (*c23_b_info)[2].fileLength = 0U;
  (*c23_b_info)[2].fileTime1 = 0U;
  (*c23_b_info)[2].fileTime2 = 0U;
  sf_mex_assign(&c23_m0, sf_mex_createstruct("nameCaptureInfo", 1, 3));
  for (c23_i3 = 0; c23_i3 < 3; c23_i3 = c23_i3 + 1) {
    c23_r0 = &c23_info[c23_i3];
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c23_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c23_r0->context)), "context", "nameCaptureInfo", c23_i3);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c23_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c23_r0->name)), "name", "nameCaptureInfo", c23_i3);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c23_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const
      char *)c23_r0->dominantType)), "dominantType", "nameCaptureInfo", c23_i3);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c23_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c23_r0->resolved)), "resolved", "nameCaptureInfo", c23_i3);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c23_i3);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c23_i3);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c23_i3);
  }

  sf_mex_assign(&c23_nameCaptureInfo, c23_m0);
  return c23_nameCaptureInfo;
}

static void c23_emlrt_marshallIn(SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c23_r_f, const char_T
  *c23_name, real_T c23_y[3])
{
  real_T c23_dv1[3];
  int32_T c23_i4;
  sf_mex_import(c23_name, sf_mex_dup(c23_r_f), &c23_dv1, 1, 0, 0U, 1, 0U, 2, 1,
                3);
  for (c23_i4 = 0; c23_i4 < 3; c23_i4 = c23_i4 + 1) {
    c23_y[c23_i4] = c23_dv1[c23_i4];
  }

  sf_mex_destroy(&c23_r_f);
}

static uint8_T c23_b_emlrt_marshallIn
  (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c23_b_is_active_c23_ODE_Hand_Model_v08_IPC_v03, const char_T *c23_name)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  sf_mex_import(c23_name, sf_mex_dup
                (c23_b_is_active_c23_ODE_Hand_Model_v08_IPC_v03), &c23_u0, 1, 3,
                0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_b_is_active_c23_ODE_Hand_Model_v08_IPC_v03);
  return c23_y;
}

static void init_dsm_address_info(SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c23_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2561017062U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3650183672U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1061477258U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3366806714U);
}

mxArray *sf_c23_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(110964822U);
    pr[1] = (double)(3981257191U);
    pr[2] = (double)(1333852933U);
    pr[3] = (double)(4082644161U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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
      pr[1] = (double)(3);
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
      pr[1] = (double)(3);
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

static mxArray *sf_get_sim_state_info_c23_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[6],T\"r_f\",},{M[1],M[5],T\"x_f\",},{M[8],M[0],T\"is_active_c23_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c23_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c23_ODE_Hand_Model_v08_IPC_v03
    ((SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c23_ODE_Hand_Model_v08_IPC_v03
    ((SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c23_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c23_ODE_Hand_Model_v08_IPC_v03
    ((SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c23_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c23_ODE_Hand_Model_v08_IPC_v03
    ((SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c23_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c23_ODE_Hand_Model_v08_IPC_v03
    ((SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c23_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c23_ODE_Hand_Model_v08_IPC_v03
    ((SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c23_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c23_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c23_ODE_Hand_Model_v08_IPC_v03
    ((SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c23_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c23_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c23_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c23_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c23_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c23_ODE_Hand_Model_v08_IPC_v03
      ((SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c23_ODE_Hand_Model_v08_IPC_v03
      ((SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c23_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",23,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",23,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",23,2);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3377885894U));
  ssSetChecksum1(S,(4153128426U));
  ssSetChecksum2(S,(1380315233U));
  ssSetChecksum3(S,(1280808567U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c23_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",23);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc
    (sizeof(SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc23_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c23_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c23_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c23_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c23_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c23_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c23_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c23_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c23_ODE_Hand_Model_v08_IPC_v03;
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

void c23_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
