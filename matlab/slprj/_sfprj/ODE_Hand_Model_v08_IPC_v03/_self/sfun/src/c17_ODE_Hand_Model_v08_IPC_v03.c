/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c17_ODE_Hand_Model_v08_IPC_v03.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c17_st);
static void finalize_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber);
static void c17_info_helper(c17_ResolvedFunctionInfo c17_info[15]);
static void c17_emlrt_marshallIn(SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c17_t, const char_T *c17_name, real_T c17_y[16]);
static uint8_T c17_b_emlrt_marshallIn
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c17_b_is_active_c17_ODE_Hand_Model_v08_IPC_v03, const char_T *c17_name);
static void init_dsm_address_info(SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c17_is_active_c17_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c17_st;
  const mxArray *c17_y = NULL;
  int32_T c17_i0;
  real_T c17_u[16];
  const mxArray *c17_b_y = NULL;
  uint8_T c17_b_u;
  const mxArray *c17_c_y = NULL;
  real_T (*c17_t)[16];
  c17_t = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c17_st = NULL;
  c17_st = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createcellarray(2));
  for (c17_i0 = 0; c17_i0 < 16; c17_i0 = c17_i0 + 1) {
    c17_u[c17_i0] = (*c17_t)[c17_i0];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", &c17_u, 0, 0U, 1U, 0U, 2, 1, 16));
  sf_mex_setcell(c17_y, 0, c17_b_y);
  c17_b_u = chartInstance->c17_is_active_c17_ODE_Hand_Model_v08_IPC_v03;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c17_y, 1, c17_c_y);
  sf_mex_assign(&c17_st, c17_y);
  return c17_st;
}

static void set_sim_state_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance,
   const mxArray *c17_st)
{
  const mxArray *c17_u;
  real_T c17_dv0[16];
  int32_T c17_i1;
  real_T (*c17_t)[16];
  c17_t = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c17_u = sf_mex_dup(c17_st);
  c17_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 0)), "t",
                       c17_dv0);
  for (c17_i1 = 0; c17_i1 < 16; c17_i1 = c17_i1 + 1) {
    (*c17_t)[c17_i1] = c17_dv0[c17_i1];
  }

  chartInstance->c17_is_active_c17_ODE_Hand_Model_v08_IPC_v03 =
    c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u
    , 1)), "is_active_c17_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c17_u);
  sf_mex_destroy(&c17_st);
}

static void finalize_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c17_ODE_Hand_Model_v08_IPC_v03
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c17_previousEvent;
  int32_T c17_i;
  real_T c17_q[16];
  real_T c17_tau[16];
  real_T c17_y;
  int32_T c17_b_i;
  int32_T c17_i2;
  static int8_T c17_iv0[4] = { 0, 0, 1, -1 };

  real_T (*c17_t)[16];
  real_T (*c17_b_q)[16];
  c17_t = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c17_b_q = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c17_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  for (c17_i = 0; c17_i < 16; c17_i = c17_i + 1) {
    c17_q[c17_i] = (*c17_b_q)[c17_i];
    c17_tau[c17_i] = 0.0;
  }

  for (c17_i = 0; c17_i < 16; c17_i = c17_i + 4) {
    sf_mex_lw_bounds_check(c17_i + 4, 1, 16);
    sf_mex_lw_bounds_check(c17_i + 3, 1, 16);
    c17_y = 50.0 * (c17_q[sf_mex_lw_bounds_check(c17_i + 3, 1, 16) - 1] -
                    c17_q[sf_mex_lw_bounds_check(c17_i + 4, 1, 16) - 1]);
    c17_b_i = c17_i + 1;
    for (c17_i2 = 0; c17_i2 < 4; c17_i2 = c17_i2 + 1) {
      c17_tau[sf_mex_lw_bounds_check(c17_b_i + c17_i2, 1, 16) - 1] = c17_y *
        (real_T)c17_iv0[c17_i2];
    }

    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  /*  t=(eye(16)-JH'*JH)*tau'; */
  /*  size(JH') */
  /*  size(pinv(JH')*JH') */
  /*  size(tau') */
  for (c17_i = 0; c17_i < 16; c17_i = c17_i + 1) {
    (*c17_t)[c17_i] = c17_tau[c17_i];
  }

  _sfEvent_ = c17_previousEvent;
}

static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber)
{
}

const mxArray *sf_c17_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c17_nameCaptureInfo;
  c17_ResolvedFunctionInfo c17_info[15];
  const mxArray *c17_m0 = NULL;
  int32_T c17_i3;
  c17_ResolvedFunctionInfo *c17_r0;
  c17_nameCaptureInfo = NULL;
  c17_nameCaptureInfo = NULL;
  c17_info_helper(c17_info);
  sf_mex_assign(&c17_m0, sf_mex_createstruct("nameCaptureInfo", 1, 15));
  for (c17_i3 = 0; c17_i3 < 15; c17_i3 = c17_i3 + 1) {
    c17_r0 = &c17_info[c17_i3];
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c17_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c17_r0->context)), "context", "nameCaptureInfo", c17_i3);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c17_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c17_r0->name)), "name", "nameCaptureInfo", c17_i3);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c17_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const
      char *)c17_r0->dominantType)), "dominantType", "nameCaptureInfo", c17_i3);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c17_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c17_r0->resolved)), "resolved", "nameCaptureInfo", c17_i3);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", &c17_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c17_i3);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", &c17_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c17_i3);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", &c17_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c17_i3);
  }

  sf_mex_assign(&c17_nameCaptureInfo, c17_m0);
  return c17_nameCaptureInfo;
}

static void c17_info_helper(c17_ResolvedFunctionInfo c17_info[15])
{
  c17_info[0].context = "";
  c17_info[0].name = "zeros";
  c17_info[0].dominantType = "double";
  c17_info[0].resolved = "[B]zeros";
  c17_info[0].fileLength = 0U;
  c17_info[0].fileTime1 = 0U;
  c17_info[0].fileTime2 = 0U;
  c17_info[1].context = "";
  c17_info[1].name = "plus";
  c17_info[1].dominantType = "double";
  c17_info[1].resolved = "[B]plus";
  c17_info[1].fileLength = 0U;
  c17_info[1].fileTime1 = 0U;
  c17_info[1].fileTime2 = 0U;
  c17_info[2].context = "";
  c17_info[2].name = "mtimes";
  c17_info[2].dominantType = "double";
  c17_info[2].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[2].fileLength = 3425U;
  c17_info[2].fileTime1 = 1250669166U;
  c17_info[2].fileTime2 = 0U;
  c17_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[3].name = "nargin";
  c17_info[3].dominantType = "";
  c17_info[3].resolved = "[B]nargin";
  c17_info[3].fileLength = 0U;
  c17_info[3].fileTime1 = 0U;
  c17_info[3].fileTime2 = 0U;
  c17_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[4].name = "gt";
  c17_info[4].dominantType = "double";
  c17_info[4].resolved = "[B]gt";
  c17_info[4].fileLength = 0U;
  c17_info[4].fileTime1 = 0U;
  c17_info[4].fileTime2 = 0U;
  c17_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[5].name = "isa";
  c17_info[5].dominantType = "double";
  c17_info[5].resolved = "[B]isa";
  c17_info[5].fileLength = 0U;
  c17_info[5].fileTime1 = 0U;
  c17_info[5].fileTime2 = 0U;
  c17_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[6].name = "isinteger";
  c17_info[6].dominantType = "double";
  c17_info[6].resolved = "[B]isinteger";
  c17_info[6].fileLength = 0U;
  c17_info[6].fileTime1 = 0U;
  c17_info[6].fileTime2 = 0U;
  c17_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[7].name = "isscalar";
  c17_info[7].dominantType = "double";
  c17_info[7].resolved = "[B]isscalar";
  c17_info[7].fileLength = 0U;
  c17_info[7].fileTime1 = 0U;
  c17_info[7].fileTime2 = 0U;
  c17_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[8].name = "strcmp";
  c17_info[8].dominantType = "char";
  c17_info[8].resolved = "[B]strcmp";
  c17_info[8].fileLength = 0U;
  c17_info[8].fileTime1 = 0U;
  c17_info[8].fileTime2 = 0U;
  c17_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[9].name = "size";
  c17_info[9].dominantType = "double";
  c17_info[9].resolved = "[B]size";
  c17_info[9].fileLength = 0U;
  c17_info[9].fileTime1 = 0U;
  c17_info[9].fileTime2 = 0U;
  c17_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[10].name = "eq";
  c17_info[10].dominantType = "double";
  c17_info[10].resolved = "[B]eq";
  c17_info[10].fileLength = 0U;
  c17_info[10].fileTime1 = 0U;
  c17_info[10].fileTime2 = 0U;
  c17_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[11].name = "class";
  c17_info[11].dominantType = "double";
  c17_info[11].resolved = "[B]class";
  c17_info[11].fileLength = 0U;
  c17_info[11].fileTime1 = 0U;
  c17_info[11].fileTime2 = 0U;
  c17_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[12].name = "not";
  c17_info[12].dominantType = "logical";
  c17_info[12].resolved = "[B]not";
  c17_info[12].fileLength = 0U;
  c17_info[12].fileTime1 = 0U;
  c17_info[12].fileTime2 = 0U;
  c17_info[13].context = "";
  c17_info[13].name = "minus";
  c17_info[13].dominantType = "double";
  c17_info[13].resolved = "[B]minus";
  c17_info[13].fileLength = 0U;
  c17_info[13].fileTime1 = 0U;
  c17_info[13].fileTime2 = 0U;
  c17_info[14].context = "";
  c17_info[14].name = "uminus";
  c17_info[14].dominantType = "double";
  c17_info[14].resolved = "[B]uminus";
  c17_info[14].fileLength = 0U;
  c17_info[14].fileTime1 = 0U;
  c17_info[14].fileTime2 = 0U;
}

static void c17_emlrt_marshallIn(SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c17_t, const char_T *
  c17_name, real_T c17_y[16])
{
  real_T c17_dv1[16];
  int32_T c17_i4;
  sf_mex_import(c17_name, sf_mex_dup(c17_t), &c17_dv1, 1, 0, 0U, 1, 0U, 2, 1, 16);
  for (c17_i4 = 0; c17_i4 < 16; c17_i4 = c17_i4 + 1) {
    c17_y[c17_i4] = c17_dv1[c17_i4];
  }

  sf_mex_destroy(&c17_t);
}

static uint8_T c17_b_emlrt_marshallIn
  (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c17_b_is_active_c17_ODE_Hand_Model_v08_IPC_v03, const char_T *c17_name)
{
  uint8_T c17_y;
  uint8_T c17_u0;
  sf_mex_import(c17_name, sf_mex_dup
                (c17_b_is_active_c17_ODE_Hand_Model_v08_IPC_v03), &c17_u0, 1, 3,
                0U, 0, 0U, 0);
  c17_y = c17_u0;
  sf_mex_destroy(&c17_b_is_active_c17_ODE_Hand_Model_v08_IPC_v03);
  return c17_y;
}

static void init_dsm_address_info(SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c17_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2007377930U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(595302850U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1022396320U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2545872655U);
}

mxArray *sf_c17_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1320520036U);
    pr[1] = (double)(895840811U);
    pr[2] = (double)(2643016647U);
    pr[3] = (double)(3282566802U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(16);
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
      pr[0] = (double)(1);
      pr[1] = (double)(16);
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

static mxArray *sf_get_sim_state_info_c17_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"t\",},{M[8],M[0],T\"is_active_c17_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c17_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c17_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c17_ODE_Hand_Model_v08_IPC_v03
    ((SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c17_ODE_Hand_Model_v08_IPC_v03
    ((SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c17_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c17_ODE_Hand_Model_v08_IPC_v03
    ((SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c17_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c17_ODE_Hand_Model_v08_IPC_v03
    ((SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c17_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c17_ODE_Hand_Model_v08_IPC_v03
    ((SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c17_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c17_ODE_Hand_Model_v08_IPC_v03
    ((SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c17_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c17_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c17_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c17_ODE_Hand_Model_v08_IPC_v03
    ((SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c17_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c17_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c17_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c17_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c17_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c17_ODE_Hand_Model_v08_IPC_v03
      ((SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c17_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c17_ODE_Hand_Model_v08_IPC_v03
      ((SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c17_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",17);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",17,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",17,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",17,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",17,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",17);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2498252000U));
  ssSetChecksum1(S,(4019680016U));
  ssSetChecksum2(S,(4252381865U));
  ssSetChecksum3(S,(527322520U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c17_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",17);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c17_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc
    (sizeof(SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc17_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c17_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c17_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c17_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c17_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c17_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c17_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c17_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c17_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c17_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c17_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c17_ODE_Hand_Model_v08_IPC_v03;
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

void c17_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c17_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c17_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c17_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c17_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
