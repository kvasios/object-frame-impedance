/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c29_ODE_Hand_Model_v08_IPC_v03.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c29_st);
static void finalize_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber);
static void c29_info_helper(c29_ResolvedFunctionInfo c29_info[46]);
static void c29_emlrt_marshallIn(SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c29_x, const char_T *c29_name, real_T c29_y[12]);
static uint8_T c29_b_emlrt_marshallIn
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c29_b_is_active_c29_ODE_Hand_Model_v08_IPC_v03, const char_T *c29_name);
static void init_dsm_address_info(SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c29_is_active_c29_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c29_st;
  const mxArray *c29_y = NULL;
  int32_T c29_i0;
  real_T c29_u[12];
  const mxArray *c29_b_y = NULL;
  uint8_T c29_b_u;
  const mxArray *c29_c_y = NULL;
  real_T (*c29_x)[12];
  c29_x = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  c29_st = NULL;
  c29_st = NULL;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_createcellarray(2));
  for (c29_i0 = 0; c29_i0 < 12; c29_i0 = c29_i0 + 1) {
    c29_u[c29_i0] = (*c29_x)[c29_i0];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", &c29_u, 0, 0U, 1U, 0U, 2, 4, 3));
  sf_mex_setcell(c29_y, 0, c29_b_y);
  c29_b_u = chartInstance->c29_is_active_c29_ODE_Hand_Model_v08_IPC_v03;
  c29_c_y = NULL;
  sf_mex_assign(&c29_c_y, sf_mex_create("y", &c29_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c29_y, 1, c29_c_y);
  sf_mex_assign(&c29_st, c29_y);
  return c29_st;
}

static void set_sim_state_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance,
   const mxArray *c29_st)
{
  const mxArray *c29_u;
  real_T c29_dv0[12];
  int32_T c29_i1;
  real_T (*c29_x)[12];
  c29_x = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  c29_u = sf_mex_dup(c29_st);
  c29_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c29_u, 0)), "x",
                       c29_dv0);
  for (c29_i1 = 0; c29_i1 < 12; c29_i1 = c29_i1 + 1) {
    (*c29_x)[c29_i1] = c29_dv0[c29_i1];
  }

  chartInstance->c29_is_active_c29_ODE_Hand_Model_v08_IPC_v03 =
    c29_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c29_u
    , 1)), "is_active_c29_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c29_u);
  sf_mex_destroy(&c29_st);
}

static void finalize_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c29_ODE_Hand_Model_v08_IPC_v03
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c29_previousEvent;
  int32_T c29_c;
  real_T c29_q[16];
  real_T c29_x_[12];
  int32_T c29_b_c;
  int32_T c29_i;
  real_T c29_q1;
  real_T c29_q2;
  real_T c29_q3;
  real_T c29_q4;
  int32_T c29_c_c;
  int32_T c29_d_c;
  int32_T c29_i2;
  int32_T c29_i3;
  static int8_T c29_iv0[9] = { 0, 0, 1, 0, 1, 0, -1, 0, 0 };

  static real_T c29_dv1[12] = { -0.7, 0.6, 0.7, 0.6, 0.0, 0.4, 0.0, -0.4, 0.1,
    0.1, 0.1, 0.1 };

  real_T c29_dv2[3];
  real_T (*c29_x)[12];
  real_T (*c29_b_q)[16];
  c29_x = (real_T (*)[12])ssGetOutputPortSignal(chartInstance->S, 1);
  c29_b_q = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c29_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  for (c29_c = 0; c29_c < 16; c29_c = c29_c + 1) {
    c29_q[c29_c] = (*c29_b_q)[c29_c];
  }

  for (c29_c = 0; c29_c < 12; c29_c = c29_c + 1) {
    c29_x_[c29_c] = 0.0;
  }

  c29_b_c = 1;
  for (c29_i = 0; c29_i < 16; c29_i = c29_i + 4) {
    c29_q1 = c29_q[c29_i];
    c29_q2 = c29_q[sf_mex_lw_bounds_check(c29_i + 2, 1, 16) - 1];
    c29_q3 = c29_q[sf_mex_lw_bounds_check(c29_i + 3, 1, 16) - 1];
    c29_q4 = c29_q[sf_mex_lw_bounds_check(c29_i + 4, 1, 16) - 1];
    c29_x_[sf_mex_lw_bounds_check(c29_b_c, 1, 4) - 1] = muDoubleScalarCos(c29_q1)
      * ((1.1 * muDoubleScalarCos(c29_q2) + 0.6 *
          muDoubleScalarCos(c29_q2 + c29_q3)) + 0.55 * muDoubleScalarCos((c29_q2
           + c29_q3) + c29_q4));
    c29_x_[c29_b_c + 3] = ((1.1 * muDoubleScalarCos(c29_q2) + 0.6 *
      muDoubleScalarCos(c29_q2 + c29_q3)) + 0.55 * muDoubleScalarCos((
      c29_q2 + c29_q3) + c29_q4)) * muDoubleScalarSin(c29_q1);
    c29_x_[c29_b_c + 7] = (1.1 * muDoubleScalarSin(c29_q2) + 0.6 *
      muDoubleScalarSin(c29_q2 + c29_q3)) + 0.55 * muDoubleScalarSin((
      c29_q2 + c29_q3) + c29_q4);
    c29_c_c = c29_b_c - 1;
    c29_c = c29_b_c - 1;
    c29_d_c = c29_b_c - 1;
    for (c29_i2 = 0; c29_i2 < 3; c29_i2 = c29_i2 + 1) {
      c29_q1 = 0.0;
      for (c29_i3 = 0; c29_i3 < 3; c29_i3 = c29_i3 + 1) {
        c29_q1 = c29_q1 + (real_T)c29_iv0[c29_i2 + 3 * c29_i3] * c29_x_[c29_c +
          (c29_i3 << 2)];
      }

      c29_dv2[c29_i2] = c29_q1 + c29_dv1[c29_d_c + (c29_i2 << 2)];
    }

    for (c29_c = 0; c29_c < 3; c29_c = c29_c + 1) {
      c29_x_[c29_c_c + (c29_c << 2)] = c29_dv2[c29_c];
    }

    c29_b_c = c29_b_c + 1;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  for (c29_c = 0; c29_c < 12; c29_c = c29_c + 1) {
    (*c29_x)[c29_c] = c29_x_[c29_c];
  }

  _sfEvent_ = c29_previousEvent;
}

static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber)
{
}

const mxArray *sf_c29_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c29_nameCaptureInfo;
  c29_ResolvedFunctionInfo c29_info[46];
  const mxArray *c29_m0 = NULL;
  int32_T c29_i4;
  c29_ResolvedFunctionInfo *c29_r0;
  c29_nameCaptureInfo = NULL;
  c29_nameCaptureInfo = NULL;
  c29_info_helper(c29_info);
  sf_mex_assign(&c29_m0, sf_mex_createstruct("nameCaptureInfo", 1, 46));
  for (c29_i4 = 0; c29_i4 < 46; c29_i4 = c29_i4 + 1) {
    c29_r0 = &c29_info[c29_i4];
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c29_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c29_r0->context)), "context", "nameCaptureInfo", c29_i4);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c29_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c29_r0->name)), "name", "nameCaptureInfo", c29_i4);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c29_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const
      char *)c29_r0->dominantType)), "dominantType", "nameCaptureInfo", c29_i4);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c29_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c29_r0->resolved)), "resolved", "nameCaptureInfo", c29_i4);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", &c29_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c29_i4);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", &c29_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c29_i4);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", &c29_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c29_i4);
  }

  sf_mex_assign(&c29_nameCaptureInfo, c29_m0);
  return c29_nameCaptureInfo;
}

static void c29_info_helper(c29_ResolvedFunctionInfo c29_info[46])
{
  c29_info[0].context = "";
  c29_info[0].name = "zeros";
  c29_info[0].dominantType = "double";
  c29_info[0].resolved = "[B]zeros";
  c29_info[0].fileLength = 0U;
  c29_info[0].fileTime1 = 0U;
  c29_info[0].fileTime2 = 0U;
  c29_info[1].context = "";
  c29_info[1].name = "uminus";
  c29_info[1].dominantType = "double";
  c29_info[1].resolved = "[B]uminus";
  c29_info[1].fileLength = 0U;
  c29_info[1].fileTime1 = 0U;
  c29_info[1].fileTime2 = 0U;
  c29_info[2].context = "";
  c29_info[2].name = "plus";
  c29_info[2].dominantType = "double";
  c29_info[2].resolved = "[B]plus";
  c29_info[2].fileLength = 0U;
  c29_info[2].fileTime1 = 0U;
  c29_info[2].fileTime2 = 0U;
  c29_info[3].context = "";
  c29_info[3].name = "cos";
  c29_info[3].dominantType = "double";
  c29_info[3].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c29_info[3].fileLength = 324U;
  c29_info[3].fileTime1 = 1203444350U;
  c29_info[3].fileTime2 = 0U;
  c29_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c29_info[4].name = "nargin";
  c29_info[4].dominantType = "";
  c29_info[4].resolved = "[B]nargin";
  c29_info[4].fileLength = 0U;
  c29_info[4].fileTime1 = 0U;
  c29_info[4].fileTime2 = 0U;
  c29_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c29_info[5].name = "gt";
  c29_info[5].dominantType = "double";
  c29_info[5].resolved = "[B]gt";
  c29_info[5].fileLength = 0U;
  c29_info[5].fileTime1 = 0U;
  c29_info[5].fileTime2 = 0U;
  c29_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c29_info[6].name = "isa";
  c29_info[6].dominantType = "double";
  c29_info[6].resolved = "[B]isa";
  c29_info[6].fileLength = 0U;
  c29_info[6].fileTime1 = 0U;
  c29_info[6].fileTime2 = 0U;
  c29_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c29_info[7].name = "eml_scalar_cos";
  c29_info[7].dominantType = "double";
  c29_info[7].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c29_info[7].fileLength = 602U;
  c29_info[7].fileTime1 = 1209327186U;
  c29_info[7].fileTime2 = 0U;
  c29_info[8].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c29_info[8].name = "isreal";
  c29_info[8].dominantType = "double";
  c29_info[8].resolved = "[B]isreal";
  c29_info[8].fileLength = 0U;
  c29_info[8].fileTime1 = 0U;
  c29_info[8].fileTime2 = 0U;
  c29_info[9].context = "";
  c29_info[9].name = "times";
  c29_info[9].dominantType = "double";
  c29_info[9].resolved = "[B]times";
  c29_info[9].fileLength = 0U;
  c29_info[9].fileTime1 = 0U;
  c29_info[9].fileTime2 = 0U;
  c29_info[10].context = "";
  c29_info[10].name = "sin";
  c29_info[10].dominantType = "double";
  c29_info[10].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c29_info[10].fileLength = 324U;
  c29_info[10].fileTime1 = 1203444442U;
  c29_info[10].fileTime2 = 0U;
  c29_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c29_info[11].name = "eml_scalar_sin";
  c29_info[11].dominantType = "double";
  c29_info[11].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c29_info[11].fileLength = 601U;
  c29_info[11].fileTime1 = 1209327190U;
  c29_info[11].fileTime2 = 0U;
  c29_info[12].context = "";
  c29_info[12].name = "ctranspose";
  c29_info[12].dominantType = "double";
  c29_info[12].resolved = "[B]ctranspose";
  c29_info[12].fileLength = 0U;
  c29_info[12].fileTime1 = 0U;
  c29_info[12].fileTime2 = 0U;
  c29_info[13].context = "";
  c29_info[13].name = "mtimes";
  c29_info[13].dominantType = "double";
  c29_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[13].fileLength = 3425U;
  c29_info[13].fileTime1 = 1250669166U;
  c29_info[13].fileTime2 = 0U;
  c29_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[14].name = "isinteger";
  c29_info[14].dominantType = "double";
  c29_info[14].resolved = "[B]isinteger";
  c29_info[14].fileLength = 0U;
  c29_info[14].fileTime1 = 0U;
  c29_info[14].fileTime2 = 0U;
  c29_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[15].name = "isscalar";
  c29_info[15].dominantType = "double";
  c29_info[15].resolved = "[B]isscalar";
  c29_info[15].fileLength = 0U;
  c29_info[15].fileTime1 = 0U;
  c29_info[15].fileTime2 = 0U;
  c29_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[16].name = "ndims";
  c29_info[16].dominantType = "double";
  c29_info[16].resolved = "[B]ndims";
  c29_info[16].fileLength = 0U;
  c29_info[16].fileTime1 = 0U;
  c29_info[16].fileTime2 = 0U;
  c29_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[17].name = "le";
  c29_info[17].dominantType = "double";
  c29_info[17].resolved = "[B]le";
  c29_info[17].fileLength = 0U;
  c29_info[17].fileTime1 = 0U;
  c29_info[17].fileTime2 = 0U;
  c29_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[18].name = "size";
  c29_info[18].dominantType = "double";
  c29_info[18].resolved = "[B]size";
  c29_info[18].fileLength = 0U;
  c29_info[18].fileTime1 = 0U;
  c29_info[18].fileTime2 = 0U;
  c29_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[19].name = "eq";
  c29_info[19].dominantType = "double";
  c29_info[19].resolved = "[B]eq";
  c29_info[19].fileLength = 0U;
  c29_info[19].fileTime1 = 0U;
  c29_info[19].fileTime2 = 0U;
  c29_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[20].name = "not";
  c29_info[20].dominantType = "logical";
  c29_info[20].resolved = "[B]not";
  c29_info[20].fileLength = 0U;
  c29_info[20].fileTime1 = 0U;
  c29_info[20].fileTime2 = 0U;
  c29_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[21].name = "strcmp";
  c29_info[21].dominantType = "char";
  c29_info[21].resolved = "[B]strcmp";
  c29_info[21].fileLength = 0U;
  c29_info[21].fileTime1 = 0U;
  c29_info[21].fileTime2 = 0U;
  c29_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[22].name = "class";
  c29_info[22].dominantType = "double";
  c29_info[22].resolved = "[B]class";
  c29_info[22].fileLength = 0U;
  c29_info[22].fileTime1 = 0U;
  c29_info[22].fileTime2 = 0U;
  c29_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[23].name = "ne";
  c29_info[23].dominantType = "logical";
  c29_info[23].resolved = "[B]ne";
  c29_info[23].fileLength = 0U;
  c29_info[23].fileTime1 = 0U;
  c29_info[23].fileTime2 = 0U;
  c29_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[24].name = "eml_index_class";
  c29_info[24].dominantType = "";
  c29_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c29_info[24].fileLength = 909U;
  c29_info[24].fileTime1 = 1192463182U;
  c29_info[24].fileTime2 = 0U;
  c29_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[25].name = "ones";
  c29_info[25].dominantType = "char";
  c29_info[25].resolved = "[B]ones";
  c29_info[25].fileLength = 0U;
  c29_info[25].fileTime1 = 0U;
  c29_info[25].fileTime2 = 0U;
  c29_info[26].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[26].name = "cast";
  c29_info[26].dominantType = "double";
  c29_info[26].resolved = "[B]cast";
  c29_info[26].fileLength = 0U;
  c29_info[26].fileTime1 = 0U;
  c29_info[26].fileTime2 = 0U;
  c29_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[27].name = "eml_scalar_eg";
  c29_info[27].dominantType = "double";
  c29_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c29_info[27].fileLength = 3068U;
  c29_info[27].fileTime1 = 1240258410U;
  c29_info[27].fileTime2 = 0U;
  c29_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c29_info[28].name = "false";
  c29_info[28].dominantType = "";
  c29_info[28].resolved = "[B]false";
  c29_info[28].fileLength = 0U;
  c29_info[28].fileTime1 = 0U;
  c29_info[28].fileTime2 = 0U;
  c29_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c29_info[29].name = "isstruct";
  c29_info[29].dominantType = "double";
  c29_info[29].resolved = "[B]isstruct";
  c29_info[29].fileLength = 0U;
  c29_info[29].fileTime1 = 0U;
  c29_info[29].fileTime2 = 0U;
  c29_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[30].name = "isempty";
  c29_info[30].dominantType = "double";
  c29_info[30].resolved = "[B]isempty";
  c29_info[30].fileLength = 0U;
  c29_info[30].fileTime1 = 0U;
  c29_info[30].fileTime2 = 0U;
  c29_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[31].name = "eml_xgemm";
  c29_info[31].dominantType = "int32";
  c29_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c29_info[31].fileLength = 3184U;
  c29_info[31].fileTime1 = 1209327252U;
  c29_info[31].fileTime2 = 0U;
  c29_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c29_info[32].name = "lt";
  c29_info[32].dominantType = "int32";
  c29_info[32].resolved = "[B]lt";
  c29_info[32].fileLength = 0U;
  c29_info[32].fileTime1 = 0U;
  c29_info[32].fileTime2 = 0U;
  c29_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c29_info[33].name = "length";
  c29_info[33].dominantType = "double";
  c29_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c29_info[33].fileLength = 326U;
  c29_info[33].fileTime1 = 1226573674U;
  c29_info[33].fileTime2 = 0U;
  c29_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c29_info[34].name = "min";
  c29_info[34].dominantType = "double";
  c29_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c29_info[34].fileLength = 362U;
  c29_info[34].fileTime1 = 1244731952U;
  c29_info[34].fileTime2 = 0U;
  c29_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c29_info[35].name = "nargout";
  c29_info[35].dominantType = "";
  c29_info[35].resolved = "[B]nargout";
  c29_info[35].fileLength = 0U;
  c29_info[35].fileTime1 = 0U;
  c29_info[35].fileTime2 = 0U;
  c29_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c29_info[36].name = "eml_min_or_max";
  c29_info[36].dominantType = "char";
  c29_info[36].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c29_info[36].fileLength = 9969U;
  c29_info[36].fileTime1 = 1240258406U;
  c29_info[36].fileTime2 = 0U;
  c29_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c29_info[37].name = "ischar";
  c29_info[37].dominantType = "char";
  c29_info[37].resolved = "[B]ischar";
  c29_info[37].fileLength = 0U;
  c29_info[37].fileTime1 = 0U;
  c29_info[37].fileTime2 = 0U;
  c29_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c29_info[38].name = "isnumeric";
  c29_info[38].dominantType = "double";
  c29_info[38].resolved = "[B]isnumeric";
  c29_info[38].fileLength = 0U;
  c29_info[38].fileTime1 = 0U;
  c29_info[38].fileTime2 = 0U;
  c29_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c29_info[39].name = "islogical";
  c29_info[39].dominantType = "double";
  c29_info[39].resolved = "[B]islogical";
  c29_info[39].fileLength = 0U;
  c29_info[39].fileTime1 = 0U;
  c29_info[39].fileTime2 = 0U;
  c29_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c29_info[40].name = "eml_scalexp_alloc";
  c29_info[40].dominantType = "double";
  c29_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c29_info[40].fileLength = 808U;
  c29_info[40].fileTime1 = 1230491098U;
  c29_info[40].fileTime2 = 0U;
  c29_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c29_info[41].name = "minus";
  c29_info[41].dominantType = "double";
  c29_info[41].resolved = "[B]minus";
  c29_info[41].fileLength = 0U;
  c29_info[41].fileTime1 = 0U;
  c29_info[41].fileTime2 = 0U;
  c29_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c29_info[42].name = "eml_refblas_xgemm";
  c29_info[42].dominantType = "int32";
  c29_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c29_info[42].fileLength = 5748U;
  c29_info[42].fileTime1 = 1228090272U;
  c29_info[42].fileTime2 = 0U;
  c29_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c29_info[43].name = "eml_index_minus";
  c29_info[43].dominantType = "int32";
  c29_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c29_info[43].fileLength = 277U;
  c29_info[43].fileTime1 = 1192463184U;
  c29_info[43].fileTime2 = 0U;
  c29_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c29_info[44].name = "eml_index_times";
  c29_info[44].dominantType = "int32";
  c29_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c29_info[44].fileLength = 280U;
  c29_info[44].fileTime1 = 1192463186U;
  c29_info[44].fileTime2 = 0U;
  c29_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c29_info[45].name = "eml_index_plus";
  c29_info[45].dominantType = "int32";
  c29_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c29_info[45].fileLength = 272U;
  c29_info[45].fileTime1 = 1192463184U;
  c29_info[45].fileTime2 = 0U;
}

static void c29_emlrt_marshallIn(SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c29_x, const char_T *
  c29_name, real_T c29_y[12])
{
  real_T c29_dv3[12];
  int32_T c29_i5;
  sf_mex_import(c29_name, sf_mex_dup(c29_x), &c29_dv3, 1, 0, 0U, 1, 0U, 2, 4, 3);
  for (c29_i5 = 0; c29_i5 < 12; c29_i5 = c29_i5 + 1) {
    c29_y[c29_i5] = c29_dv3[c29_i5];
  }

  sf_mex_destroy(&c29_x);
}

static uint8_T c29_b_emlrt_marshallIn
  (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c29_b_is_active_c29_ODE_Hand_Model_v08_IPC_v03, const char_T *c29_name)
{
  uint8_T c29_y;
  uint8_T c29_u0;
  sf_mex_import(c29_name, sf_mex_dup
                (c29_b_is_active_c29_ODE_Hand_Model_v08_IPC_v03), &c29_u0, 1, 3,
                0U, 0, 0U, 0);
  c29_y = c29_u0;
  sf_mex_destroy(&c29_b_is_active_c29_ODE_Hand_Model_v08_IPC_v03);
  return c29_y;
}

static void init_dsm_address_info(SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c29_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3104505318U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3450944153U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3660491716U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1871535327U);
}

mxArray *sf_c29_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3355766652U);
    pr[1] = (double)(553839046U);
    pr[2] = (double)(591062596U);
    pr[3] = (double)(1066058994U);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c29_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"x\",},{M[8],M[0],T\"is_active_c29_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c29_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c29_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c29_ODE_Hand_Model_v08_IPC_v03
    ((SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c29_ODE_Hand_Model_v08_IPC_v03
    ((SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c29_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c29_ODE_Hand_Model_v08_IPC_v03
    ((SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c29_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c29_ODE_Hand_Model_v08_IPC_v03
    ((SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c29_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c29_ODE_Hand_Model_v08_IPC_v03
    ((SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c29_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c29_ODE_Hand_Model_v08_IPC_v03
    ((SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c29_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c29_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c29_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c29_ODE_Hand_Model_v08_IPC_v03
    ((SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c29_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c29_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c29_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c29_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c29_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c29_ODE_Hand_Model_v08_IPC_v03
      ((SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c29_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c29_ODE_Hand_Model_v08_IPC_v03
      ((SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c29_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",29);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",29,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",29,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",29,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",29,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",29);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2091456661U));
  ssSetChecksum1(S,(4285885652U));
  ssSetChecksum2(S,(755027153U));
  ssSetChecksum3(S,(1225979617U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c29_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",29);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c29_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc
    (sizeof(SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc29_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c29_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c29_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c29_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c29_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c29_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c29_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c29_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c29_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c29_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c29_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c29_ODE_Hand_Model_v08_IPC_v03;
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

void c29_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c29_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c29_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c29_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c29_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
