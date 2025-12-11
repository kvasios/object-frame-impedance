/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c30_ODE_Hand_Model_v08_IPC_v03.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c30_st);
static void finalize_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber);
static void c30_emlrt_marshallIn(SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c30_y, const char_T *c30_name, real_T c30_b_y[3]);
static uint8_T c30_b_emlrt_marshallIn
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c30_b_is_active_c30_ODE_Hand_Model_v08_IPC_v03, const char_T *c30_name);
static void init_dsm_address_info(SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c30_is_active_c30_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c30_st;
  const mxArray *c30_y = NULL;
  int32_T c30_i0;
  real_T c30_u[3];
  const mxArray *c30_b_y = NULL;
  uint8_T c30_b_u;
  const mxArray *c30_c_y = NULL;
  real_T (*c30_d_y)[3];
  c30_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c30_st = NULL;
  c30_st = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_createcellarray(2));
  for (c30_i0 = 0; c30_i0 < 3; c30_i0 = c30_i0 + 1) {
    c30_u[c30_i0] = (*c30_d_y)[c30_i0];
  }

  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", &c30_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c30_y, 0, c30_b_y);
  c30_b_u = chartInstance->c30_is_active_c30_ODE_Hand_Model_v08_IPC_v03;
  c30_c_y = NULL;
  sf_mex_assign(&c30_c_y, sf_mex_create("y", &c30_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c30_y, 1, c30_c_y);
  sf_mex_assign(&c30_st, c30_y);
  return c30_st;
}

static void set_sim_state_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance,
   const mxArray *c30_st)
{
  const mxArray *c30_u;
  real_T c30_dv0[3];
  int32_T c30_i1;
  real_T (*c30_y)[3];
  c30_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c30_u = sf_mex_dup(c30_st);
  c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u, 0)), "y",
                       c30_dv0);
  for (c30_i1 = 0; c30_i1 < 3; c30_i1 = c30_i1 + 1) {
    (*c30_y)[c30_i1] = c30_dv0[c30_i1];
  }

  chartInstance->c30_is_active_c30_ODE_Hand_Model_v08_IPC_v03 =
    c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c30_u
    , 1)), "is_active_c30_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c30_u);
  sf_mex_destroy(&c30_st);
}

static void finalize_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c30_ODE_Hand_Model_v08_IPC_v03
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c30_i2;
  int32_T c30_i3;
  real_T (*c30_y)[3];
  real_T (*c30_u)[12];
  c30_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c30_u = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c30_i2 = 0;
  for (c30_i3 = 0; c30_i3 < 3; c30_i3 = c30_i3 + 1) {
    (*c30_y)[c30_i3] = ((((*c30_u)[c30_i2] + (*c30_u)[c30_i2 + 1]) + (*c30_u)
                         [c30_i2 + 2]) + (*c30_u)[c30_i2 + 3]) / 4.0;
    c30_i2 = c30_i2 + 4;
  }
}

static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber)
{
}

const mxArray *sf_c30_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c30_nameCaptureInfo;
  c30_ResolvedFunctionInfo c30_info[12];
  c30_ResolvedFunctionInfo (*c30_b_info)[12];
  const mxArray *c30_m0 = NULL;
  int32_T c30_i4;
  c30_ResolvedFunctionInfo *c30_r0;
  c30_nameCaptureInfo = NULL;
  c30_nameCaptureInfo = NULL;
  c30_b_info = (c30_ResolvedFunctionInfo (*)[12])c30_info;
  (*c30_b_info)[0].context = "";
  (*c30_b_info)[0].name = "plus";
  (*c30_b_info)[0].dominantType = "double";
  (*c30_b_info)[0].resolved = "[B]plus";
  (*c30_b_info)[0].fileLength = 0U;
  (*c30_b_info)[0].fileTime1 = 0U;
  (*c30_b_info)[0].fileTime2 = 0U;
  (*c30_b_info)[1].context = "";
  (*c30_b_info)[1].name = "mrdivide";
  (*c30_b_info)[1].dominantType = "double";
  (*c30_b_info)[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  (*c30_b_info)[1].fileLength = 800U;
  (*c30_b_info)[1].fileTime1 = 1238430690U;
  (*c30_b_info)[1].fileTime2 = 0U;
  (*c30_b_info)[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  (*c30_b_info)[2].name = "nargin";
  (*c30_b_info)[2].dominantType = "";
  (*c30_b_info)[2].resolved = "[B]nargin";
  (*c30_b_info)[2].fileLength = 0U;
  (*c30_b_info)[2].fileTime1 = 0U;
  (*c30_b_info)[2].fileTime2 = 0U;
  (*c30_b_info)[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  (*c30_b_info)[3].name = "ge";
  (*c30_b_info)[3].dominantType = "double";
  (*c30_b_info)[3].resolved = "[B]ge";
  (*c30_b_info)[3].fileLength = 0U;
  (*c30_b_info)[3].fileTime1 = 0U;
  (*c30_b_info)[3].fileTime2 = 0U;
  (*c30_b_info)[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  (*c30_b_info)[4].name = "isscalar";
  (*c30_b_info)[4].dominantType = "double";
  (*c30_b_info)[4].resolved = "[B]isscalar";
  (*c30_b_info)[4].fileLength = 0U;
  (*c30_b_info)[4].fileTime1 = 0U;
  (*c30_b_info)[4].fileTime2 = 0U;
  (*c30_b_info)[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  (*c30_b_info)[5].name = "rdivide";
  (*c30_b_info)[5].dominantType = "double";
  (*c30_b_info)[5].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c30_b_info)[5].fileLength = 403U;
  (*c30_b_info)[5].fileTime1 = 1244731952U;
  (*c30_b_info)[5].fileTime2 = 0U;
  (*c30_b_info)[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c30_b_info)[6].name = "gt";
  (*c30_b_info)[6].dominantType = "double";
  (*c30_b_info)[6].resolved = "[B]gt";
  (*c30_b_info)[6].fileLength = 0U;
  (*c30_b_info)[6].fileTime1 = 0U;
  (*c30_b_info)[6].fileTime2 = 0U;
  (*c30_b_info)[7].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c30_b_info)[7].name = "isa";
  (*c30_b_info)[7].dominantType = "double";
  (*c30_b_info)[7].resolved = "[B]isa";
  (*c30_b_info)[7].fileLength = 0U;
  (*c30_b_info)[7].fileTime1 = 0U;
  (*c30_b_info)[7].fileTime2 = 0U;
  (*c30_b_info)[8].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c30_b_info)[8].name = "eml_div";
  (*c30_b_info)[8].dominantType = "double";
  (*c30_b_info)[8].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c30_b_info)[8].fileLength = 4269U;
  (*c30_b_info)[8].fileTime1 = 1228090226U;
  (*c30_b_info)[8].fileTime2 = 0U;
  (*c30_b_info)[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c30_b_info)[9].name = "isinteger";
  (*c30_b_info)[9].dominantType = "double";
  (*c30_b_info)[9].resolved = "[B]isinteger";
  (*c30_b_info)[9].fileLength = 0U;
  (*c30_b_info)[9].fileTime1 = 0U;
  (*c30_b_info)[9].fileTime2 = 0U;
  (*c30_b_info)[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  (*c30_b_info)[10].name = "isreal";
  (*c30_b_info)[10].dominantType = "double";
  (*c30_b_info)[10].resolved = "[B]isreal";
  (*c30_b_info)[10].fileLength = 0U;
  (*c30_b_info)[10].fileTime1 = 0U;
  (*c30_b_info)[10].fileTime2 = 0U;
  (*c30_b_info)[11].context = "";
  (*c30_b_info)[11].name = "ctranspose";
  (*c30_b_info)[11].dominantType = "double";
  (*c30_b_info)[11].resolved = "[B]ctranspose";
  (*c30_b_info)[11].fileLength = 0U;
  (*c30_b_info)[11].fileTime1 = 0U;
  (*c30_b_info)[11].fileTime2 = 0U;
  sf_mex_assign(&c30_m0, sf_mex_createstruct("nameCaptureInfo", 1, 12));
  for (c30_i4 = 0; c30_i4 < 12; c30_i4 = c30_i4 + 1) {
    c30_r0 = &c30_info[c30_i4];
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c30_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c30_r0->context)), "context", "nameCaptureInfo", c30_i4);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c30_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c30_r0->name)), "name", "nameCaptureInfo", c30_i4);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c30_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const
      char *)c30_r0->dominantType)), "dominantType", "nameCaptureInfo", c30_i4);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c30_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c30_r0->resolved)), "resolved", "nameCaptureInfo", c30_i4);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", &c30_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c30_i4);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", &c30_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c30_i4);
    sf_mex_addfield(c30_m0, sf_mex_create("nameCaptureInfo", &c30_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c30_i4);
  }

  sf_mex_assign(&c30_nameCaptureInfo, c30_m0);
  return c30_nameCaptureInfo;
}

static void c30_emlrt_marshallIn(SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c30_y, const char_T *
  c30_name, real_T c30_b_y[3])
{
  real_T c30_dv1[3];
  int32_T c30_i5;
  sf_mex_import(c30_name, sf_mex_dup(c30_y), &c30_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c30_i5 = 0; c30_i5 < 3; c30_i5 = c30_i5 + 1) {
    c30_b_y[c30_i5] = c30_dv1[c30_i5];
  }

  sf_mex_destroy(&c30_y);
}

static uint8_T c30_b_emlrt_marshallIn
  (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c30_b_is_active_c30_ODE_Hand_Model_v08_IPC_v03, const char_T *c30_name)
{
  uint8_T c30_y;
  uint8_T c30_u0;
  sf_mex_import(c30_name, sf_mex_dup
                (c30_b_is_active_c30_ODE_Hand_Model_v08_IPC_v03), &c30_u0, 1, 3,
                0U, 0, 0U, 0);
  c30_y = c30_u0;
  sf_mex_destroy(&c30_b_is_active_c30_ODE_Hand_Model_v08_IPC_v03);
  return c30_y;
}

static void init_dsm_address_info(SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c30_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1637393473U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4276478550U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2860590585U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2150083868U);
}

mxArray *sf_c30_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2149695350U);
    pr[1] = (double)(1870409921U);
    pr[2] = (double)(2246289703U);
    pr[3] = (double)(2971683491U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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

static mxArray *sf_get_sim_state_info_c30_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c30_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c30_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c30_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c30_ODE_Hand_Model_v08_IPC_v03
    ((SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c30_ODE_Hand_Model_v08_IPC_v03
    ((SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c30_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c30_ODE_Hand_Model_v08_IPC_v03
    ((SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c30_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c30_ODE_Hand_Model_v08_IPC_v03
    ((SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c30_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c30_ODE_Hand_Model_v08_IPC_v03
    ((SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c30_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c30_ODE_Hand_Model_v08_IPC_v03
    ((SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c30_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c30_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c30_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c30_ODE_Hand_Model_v08_IPC_v03
    ((SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c30_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c30_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c30_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c30_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c30_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c30_ODE_Hand_Model_v08_IPC_v03
      ((SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c30_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c30_ODE_Hand_Model_v08_IPC_v03
      ((SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c30_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",30);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",30,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",30,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",30,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",30,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",30);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2112554915U));
  ssSetChecksum1(S,(1964773493U));
  ssSetChecksum2(S,(1780643136U));
  ssSetChecksum3(S,(2563094422U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c30_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",30);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c30_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc
    (sizeof(SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc30_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c30_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c30_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c30_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c30_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c30_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c30_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c30_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c30_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c30_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c30_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c30_ODE_Hand_Model_v08_IPC_v03;
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

void c30_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c30_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c30_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c30_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c30_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
