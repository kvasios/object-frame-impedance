/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c20_ODE_Hand_Model_v08_IPC_v03.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c20_st);
static void finalize_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber);
static void c20_info_helper(c20_ResolvedFunctionInfo c20_info[17]);
static void c20_emlrt_marshallIn(SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c20_J, const char_T *c20_name, real_T c20_y[9]);
static uint8_T c20_b_emlrt_marshallIn
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c20_b_is_active_c20_ODE_Hand_Model_v08_IPC_v03, const char_T *c20_name);
static void init_dsm_address_info(SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c20_is_active_c20_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  int32_T c20_i0;
  real_T c20_u[9];
  const mxArray *c20_b_y = NULL;
  uint8_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  real_T (*c20_J)[9];
  c20_J = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellarray(2));
  for (c20_i0 = 0; c20_i0 < 9; c20_i0 = c20_i0 + 1) {
    c20_u[c20_i0] = (*c20_J)[c20_i0];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_b_u = chartInstance->c20_is_active_c20_ODE_Hand_Model_v08_IPC_v03;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c20_y, 1, c20_c_y);
  sf_mex_assign(&c20_st, c20_y);
  return c20_st;
}

static void set_sim_state_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance,
   const mxArray *c20_st)
{
  const mxArray *c20_u;
  real_T c20_dv0[9];
  int32_T c20_i1;
  real_T (*c20_J)[9];
  c20_J = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_u = sf_mex_dup(c20_st);
  c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 0)), "J",
                       c20_dv0);
  for (c20_i1 = 0; c20_i1 < 9; c20_i1 = c20_i1 + 1) {
    (*c20_J)[c20_i1] = c20_dv0[c20_i1];
  }

  chartInstance->c20_is_active_c20_ODE_Hand_Model_v08_IPC_v03 =
    c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u
    , 1)), "is_active_c20_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c20_u);
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c20_ODE_Hand_Model_v08_IPC_v03
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  real_T c20_q0;
  real_T c20_q1;
  real_T c20_q2;
  real_T c20_q3;
  real_T c20_b_q0[9];
  int32_T c20_i2;
  int32_T c20_i3;
  int32_T c20_i4;
  real_T (*c20_J)[9];
  real_T (*c20_e)[4];
  c20_J = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_e = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c20_q0 = (*c20_e)[0];
  c20_q1 = (*c20_e)[1];
  c20_q2 = (*c20_e)[2];
  c20_q3 = (*c20_e)[3];

  /*  R_O_Desired=[-0.7071    0.7071         0; ... */
  /*      0.7071    0.7071         0; ... */
  /*           0         0   -1.0000]; */
  c20_b_q0[0] = c20_q0;
  c20_b_q0[3] = -c20_q3;
  c20_b_q0[6] = c20_q2;
  c20_b_q0[1] = c20_q3;
  c20_b_q0[4] = c20_q0;
  c20_b_q0[7] = -c20_q1;
  c20_b_q0[2] = -c20_q2;
  c20_b_q0[5] = c20_q1;
  c20_b_q0[8] = c20_q0;
  c20_i2 = 0;
  for (c20_i3 = 0; c20_i3 < 3; c20_i3 = c20_i3 + 1) {
    for (c20_i4 = 0; c20_i4 < 3; c20_i4 = c20_i4 + 1) {
      (*c20_J)[c20_i4 + c20_i2] = -2.0 * c20_b_q0[c20_i4 + c20_i2];
    }

    c20_i2 = c20_i2 + 3;
  }
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber)
{
}

const mxArray *sf_c20_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c20_nameCaptureInfo;
  c20_ResolvedFunctionInfo c20_info[17];
  const mxArray *c20_m0 = NULL;
  int32_T c20_i5;
  c20_ResolvedFunctionInfo *c20_r0;
  c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  c20_info_helper(c20_info);
  sf_mex_assign(&c20_m0, sf_mex_createstruct("nameCaptureInfo", 1, 17));
  for (c20_i5 = 0; c20_i5 < 17; c20_i5 = c20_i5 + 1) {
    c20_r0 = &c20_info[c20_i5];
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c20_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c20_r0->context)), "context", "nameCaptureInfo", c20_i5);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c20_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c20_r0->name)), "name", "nameCaptureInfo", c20_i5);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c20_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const
      char *)c20_r0->dominantType)), "dominantType", "nameCaptureInfo", c20_i5);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c20_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c20_r0->resolved)), "resolved", "nameCaptureInfo", c20_i5);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c20_i5);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c20_i5);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c20_i5);
  }

  sf_mex_assign(&c20_nameCaptureInfo, c20_m0);
  return c20_nameCaptureInfo;
}

static void c20_info_helper(c20_ResolvedFunctionInfo c20_info[17])
{
  c20_info[0].context = "";
  c20_info[0].name = "uminus";
  c20_info[0].dominantType = "double";
  c20_info[0].resolved = "[B]uminus";
  c20_info[0].fileLength = 0U;
  c20_info[0].fileTime1 = 0U;
  c20_info[0].fileTime2 = 0U;
  c20_info[1].context = "";
  c20_info[1].name = "mrdivide";
  c20_info[1].dominantType = "double";
  c20_info[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c20_info[1].fileLength = 800U;
  c20_info[1].fileTime1 = 1238430690U;
  c20_info[1].fileTime2 = 0U;
  c20_info[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c20_info[2].name = "nargin";
  c20_info[2].dominantType = "";
  c20_info[2].resolved = "[B]nargin";
  c20_info[2].fileLength = 0U;
  c20_info[2].fileTime1 = 0U;
  c20_info[2].fileTime2 = 0U;
  c20_info[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c20_info[3].name = "ge";
  c20_info[3].dominantType = "double";
  c20_info[3].resolved = "[B]ge";
  c20_info[3].fileLength = 0U;
  c20_info[3].fileTime1 = 0U;
  c20_info[3].fileTime2 = 0U;
  c20_info[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c20_info[4].name = "isscalar";
  c20_info[4].dominantType = "double";
  c20_info[4].resolved = "[B]isscalar";
  c20_info[4].fileLength = 0U;
  c20_info[4].fileTime1 = 0U;
  c20_info[4].fileTime2 = 0U;
  c20_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c20_info[5].name = "rdivide";
  c20_info[5].dominantType = "double";
  c20_info[5].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c20_info[5].fileLength = 403U;
  c20_info[5].fileTime1 = 1244731952U;
  c20_info[5].fileTime2 = 0U;
  c20_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c20_info[6].name = "gt";
  c20_info[6].dominantType = "double";
  c20_info[6].resolved = "[B]gt";
  c20_info[6].fileLength = 0U;
  c20_info[6].fileTime1 = 0U;
  c20_info[6].fileTime2 = 0U;
  c20_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c20_info[7].name = "isa";
  c20_info[7].dominantType = "double";
  c20_info[7].resolved = "[B]isa";
  c20_info[7].fileLength = 0U;
  c20_info[7].fileTime1 = 0U;
  c20_info[7].fileTime2 = 0U;
  c20_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c20_info[8].name = "eml_div";
  c20_info[8].dominantType = "double";
  c20_info[8].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c20_info[8].fileLength = 4269U;
  c20_info[8].fileTime1 = 1228090226U;
  c20_info[8].fileTime2 = 0U;
  c20_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c20_info[9].name = "isinteger";
  c20_info[9].dominantType = "double";
  c20_info[9].resolved = "[B]isinteger";
  c20_info[9].fileLength = 0U;
  c20_info[9].fileTime1 = 0U;
  c20_info[9].fileTime2 = 0U;
  c20_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c20_info[10].name = "isreal";
  c20_info[10].dominantType = "double";
  c20_info[10].resolved = "[B]isreal";
  c20_info[10].fileLength = 0U;
  c20_info[10].fileTime1 = 0U;
  c20_info[10].fileTime2 = 0U;
  c20_info[11].context = "";
  c20_info[11].name = "mtimes";
  c20_info[11].dominantType = "double";
  c20_info[11].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[11].fileLength = 3425U;
  c20_info[11].fileTime1 = 1250669166U;
  c20_info[11].fileTime2 = 0U;
  c20_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[12].name = "strcmp";
  c20_info[12].dominantType = "char";
  c20_info[12].resolved = "[B]strcmp";
  c20_info[12].fileLength = 0U;
  c20_info[12].fileTime1 = 0U;
  c20_info[12].fileTime2 = 0U;
  c20_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[13].name = "size";
  c20_info[13].dominantType = "double";
  c20_info[13].resolved = "[B]size";
  c20_info[13].fileLength = 0U;
  c20_info[13].fileTime1 = 0U;
  c20_info[13].fileTime2 = 0U;
  c20_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[14].name = "eq";
  c20_info[14].dominantType = "double";
  c20_info[14].resolved = "[B]eq";
  c20_info[14].fileLength = 0U;
  c20_info[14].fileTime1 = 0U;
  c20_info[14].fileTime2 = 0U;
  c20_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[15].name = "class";
  c20_info[15].dominantType = "double";
  c20_info[15].resolved = "[B]class";
  c20_info[15].fileLength = 0U;
  c20_info[15].fileTime1 = 0U;
  c20_info[15].fileTime2 = 0U;
  c20_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[16].name = "not";
  c20_info[16].dominantType = "logical";
  c20_info[16].resolved = "[B]not";
  c20_info[16].fileLength = 0U;
  c20_info[16].fileTime1 = 0U;
  c20_info[16].fileTime2 = 0U;
}

static void c20_emlrt_marshallIn(SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c20_J, const char_T *
  c20_name, real_T c20_y[9])
{
  real_T c20_dv1[9];
  int32_T c20_i6;
  sf_mex_import(c20_name, sf_mex_dup(c20_J), &c20_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c20_i6 = 0; c20_i6 < 9; c20_i6 = c20_i6 + 1) {
    c20_y[c20_i6] = c20_dv1[c20_i6];
  }

  sf_mex_destroy(&c20_J);
}

static uint8_T c20_b_emlrt_marshallIn
  (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c20_b_is_active_c20_ODE_Hand_Model_v08_IPC_v03, const char_T *c20_name)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  sf_mex_import(c20_name, sf_mex_dup
                (c20_b_is_active_c20_ODE_Hand_Model_v08_IPC_v03), &c20_u0, 1, 3,
                0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_b_is_active_c20_ODE_Hand_Model_v08_IPC_v03);
  return c20_y;
}

static void init_dsm_address_info(SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c20_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2533056973U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1178495732U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1888177343U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2326042293U);
}

mxArray *sf_c20_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3874214580U);
    pr[1] = (double)(3499220884U);
    pr[2] = (double)(2128486199U);
    pr[3] = (double)(3956992826U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c20_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"J\",},{M[8],M[0],T\"is_active_c20_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c20_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c20_ODE_Hand_Model_v08_IPC_v03
    ((SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c20_ODE_Hand_Model_v08_IPC_v03
    ((SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c20_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c20_ODE_Hand_Model_v08_IPC_v03
    ((SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c20_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c20_ODE_Hand_Model_v08_IPC_v03
    ((SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c20_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c20_ODE_Hand_Model_v08_IPC_v03
    ((SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c20_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c20_ODE_Hand_Model_v08_IPC_v03
    ((SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c20_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c20_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c20_ODE_Hand_Model_v08_IPC_v03
    ((SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c20_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c20_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c20_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c20_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c20_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c20_ODE_Hand_Model_v08_IPC_v03
      ((SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c20_ODE_Hand_Model_v08_IPC_v03
      ((SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",20,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",20,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",20,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2748550007U));
  ssSetChecksum1(S,(851784173U));
  ssSetChecksum2(S,(1299662218U));
  ssSetChecksum3(S,(671016307U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c20_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",20);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc
    (sizeof(SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c20_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c20_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c20_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c20_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c20_ODE_Hand_Model_v08_IPC_v03;
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

void c20_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
