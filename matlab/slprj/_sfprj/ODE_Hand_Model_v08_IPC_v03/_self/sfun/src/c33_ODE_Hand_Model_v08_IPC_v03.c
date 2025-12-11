/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c33_ODE_Hand_Model_v08_IPC_v03.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c33_st);
static void finalize_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c33_machineNumber, uint32_T
  c33_chartNumber);
static void c33_info_helper(c33_ResolvedFunctionInfo c33_info[24]);
static void c33_emlrt_marshallIn(SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c33_gravity_dynamic_term, const char_T *c33_name,
  real_T c33_y[16]);
static uint8_T c33_b_emlrt_marshallIn
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c33_b_is_active_c33_ODE_Hand_Model_v08_IPC_v03, const char_T *c33_name);
static void init_dsm_address_info(SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c33_is_active_c33_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c33_st;
  const mxArray *c33_y = NULL;
  int32_T c33_i0;
  real_T c33_u[16];
  const mxArray *c33_b_y = NULL;
  uint8_T c33_b_u;
  const mxArray *c33_c_y = NULL;
  real_T (*c33_gravity_dynamic_term)[16];
  c33_gravity_dynamic_term = (real_T (*)[16])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c33_st = NULL;
  c33_st = NULL;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_createcellarray(2));
  for (c33_i0 = 0; c33_i0 < 16; c33_i0 = c33_i0 + 1) {
    c33_u[c33_i0] = (*c33_gravity_dynamic_term)[c33_i0];
  }

  c33_b_y = NULL;
  sf_mex_assign(&c33_b_y, sf_mex_create("y", &c33_u, 0, 0U, 1U, 0U, 2, 1, 16));
  sf_mex_setcell(c33_y, 0, c33_b_y);
  c33_b_u = chartInstance->c33_is_active_c33_ODE_Hand_Model_v08_IPC_v03;
  c33_c_y = NULL;
  sf_mex_assign(&c33_c_y, sf_mex_create("y", &c33_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c33_y, 1, c33_c_y);
  sf_mex_assign(&c33_st, c33_y);
  return c33_st;
}

static void set_sim_state_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance,
   const mxArray *c33_st)
{
  const mxArray *c33_u;
  real_T c33_dv0[16];
  int32_T c33_i1;
  real_T (*c33_gravity_dynamic_term)[16];
  c33_gravity_dynamic_term = (real_T (*)[16])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c33_u = sf_mex_dup(c33_st);
  c33_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 0)),
                       "gravity_dynamic_term", c33_dv0);
  for (c33_i1 = 0; c33_i1 < 16; c33_i1 = c33_i1 + 1) {
    (*c33_gravity_dynamic_term)[c33_i1] = c33_dv0[c33_i1];
  }

  chartInstance->c33_is_active_c33_ODE_Hand_Model_v08_IPC_v03 =
    c33_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u
    , 1)), "is_active_c33_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c33_u);
  sf_mex_destroy(&c33_st);
}

static void finalize_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c33_ODE_Hand_Model_v08_IPC_v03
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c33_previousEvent;
  int32_T c33_i;
  real_T c33_theta_in[16];
  real_T c33_c[16];
  real_T c33_q1;
  real_T c33_q2;
  real_T c33_q3;
  real_T c33_q4;
  int32_T c33_b_i;
  real_T c33_dv1[4];
  int32_T c33_i2;
  real_T (*c33_gravity_dynamic_term)[16];
  real_T (*c33_b_theta_in)[16];
  c33_gravity_dynamic_term = (real_T (*)[16])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c33_b_theta_in = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c33_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  for (c33_i = 0; c33_i < 16; c33_i = c33_i + 1) {
    c33_theta_in[c33_i] = (*c33_b_theta_in)[c33_i];
    c33_c[c33_i] = 0.0;
  }

  for (c33_i = 0; c33_i < 16; c33_i = c33_i + 4) {
    c33_q1 = c33_theta_in[c33_i];
    c33_q2 = c33_theta_in[sf_mex_lw_bounds_check(c33_i + 2, 1, 16) - 1];
    c33_q3 = c33_theta_in[sf_mex_lw_bounds_check(c33_i + 3, 1, 16) - 1];
    c33_q4 = c33_theta_in[sf_mex_lw_bounds_check(c33_i + 4, 1, 16) - 1];
    c33_b_i = c33_i + 1;
    c33_dv1[0] = -4.905 * ((6.6000000000000005E+000 * muDoubleScalarCos(c33_q2)
      + 1.7999999999999998E+000 * muDoubleScalarCos(c33_q2 +
      c33_q3)) + 0.55 * muDoubleScalarCos((c33_q2 + c33_q3) + c33_q4)) *
      muDoubleScalarSin(c33_q1);
    c33_dv1[1] = -4.905 * muDoubleScalarCos(c33_q1) * ((6.6000000000000005E+000 *
      muDoubleScalarSin(c33_q2) + 1.7999999999999998E+000 *
      muDoubleScalarSin(c33_q2 + c33_q3)) + 0.55 * muDoubleScalarSin((c33_q2 +
      c33_q3) + c33_q4));
    c33_dv1[2] = -4.905 * muDoubleScalarCos(c33_q1) * (1.7999999999999998E+000 *
      muDoubleScalarSin(c33_q2 + c33_q3) + 0.55 *
      muDoubleScalarSin((c33_q2 + c33_q3) + c33_q4));
    c33_dv1[3] = -2.6977500000000005E+000 * muDoubleScalarCos(c33_q1) *
      muDoubleScalarSin((c33_q2 + c33_q3) + c33_q4);
    for (c33_i2 = 0; c33_i2 < 4; c33_i2 = c33_i2 + 1) {
      c33_c[sf_mex_lw_bounds_check(c33_b_i + c33_i2, 1, 16) - 1] = 1.1 *
        c33_dv1[c33_i2];
    }

    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  for (c33_i = 0; c33_i < 16; c33_i = c33_i + 1) {
    (*c33_gravity_dynamic_term)[c33_i] = c33_c[c33_i];
  }

  _sfEvent_ = c33_previousEvent;
}

static void init_script_number_translation(uint32_T c33_machineNumber, uint32_T
  c33_chartNumber)
{
}

const mxArray *sf_c33_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c33_nameCaptureInfo;
  c33_ResolvedFunctionInfo c33_info[24];
  const mxArray *c33_m0 = NULL;
  int32_T c33_i3;
  c33_ResolvedFunctionInfo *c33_r0;
  c33_nameCaptureInfo = NULL;
  c33_nameCaptureInfo = NULL;
  c33_info_helper(c33_info);
  sf_mex_assign(&c33_m0, sf_mex_createstruct("nameCaptureInfo", 1, 24));
  for (c33_i3 = 0; c33_i3 < 24; c33_i3 = c33_i3 + 1) {
    c33_r0 = &c33_info[c33_i3];
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c33_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c33_r0->context)), "context", "nameCaptureInfo", c33_i3);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c33_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c33_r0->name)), "name", "nameCaptureInfo", c33_i3);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c33_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const
      char *)c33_r0->dominantType)), "dominantType", "nameCaptureInfo", c33_i3);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c33_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c33_r0->resolved)), "resolved", "nameCaptureInfo", c33_i3);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", &c33_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c33_i3);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", &c33_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c33_i3);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", &c33_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c33_i3);
  }

  sf_mex_assign(&c33_nameCaptureInfo, c33_m0);
  return c33_nameCaptureInfo;
}

static void c33_info_helper(c33_ResolvedFunctionInfo c33_info[24])
{
  c33_info[0].context = "";
  c33_info[0].name = "zeros";
  c33_info[0].dominantType = "double";
  c33_info[0].resolved = "[B]zeros";
  c33_info[0].fileLength = 0U;
  c33_info[0].fileTime1 = 0U;
  c33_info[0].fileTime2 = 0U;
  c33_info[1].context = "";
  c33_info[1].name = "plus";
  c33_info[1].dominantType = "double";
  c33_info[1].resolved = "[B]plus";
  c33_info[1].fileLength = 0U;
  c33_info[1].fileTime1 = 0U;
  c33_info[1].fileTime2 = 0U;
  c33_info[2].context = "";
  c33_info[2].name = "uminus";
  c33_info[2].dominantType = "double";
  c33_info[2].resolved = "[B]uminus";
  c33_info[2].fileLength = 0U;
  c33_info[2].fileTime1 = 0U;
  c33_info[2].fileTime2 = 0U;
  c33_info[3].context = "";
  c33_info[3].name = "mrdivide";
  c33_info[3].dominantType = "double";
  c33_info[3].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c33_info[3].fileLength = 800U;
  c33_info[3].fileTime1 = 1238430690U;
  c33_info[3].fileTime2 = 0U;
  c33_info[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c33_info[4].name = "nargin";
  c33_info[4].dominantType = "";
  c33_info[4].resolved = "[B]nargin";
  c33_info[4].fileLength = 0U;
  c33_info[4].fileTime1 = 0U;
  c33_info[4].fileTime2 = 0U;
  c33_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c33_info[5].name = "ge";
  c33_info[5].dominantType = "double";
  c33_info[5].resolved = "[B]ge";
  c33_info[5].fileLength = 0U;
  c33_info[5].fileTime1 = 0U;
  c33_info[5].fileTime2 = 0U;
  c33_info[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c33_info[6].name = "isscalar";
  c33_info[6].dominantType = "double";
  c33_info[6].resolved = "[B]isscalar";
  c33_info[6].fileLength = 0U;
  c33_info[6].fileTime1 = 0U;
  c33_info[6].fileTime2 = 0U;
  c33_info[7].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c33_info[7].name = "rdivide";
  c33_info[7].dominantType = "double";
  c33_info[7].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c33_info[7].fileLength = 403U;
  c33_info[7].fileTime1 = 1244731952U;
  c33_info[7].fileTime2 = 0U;
  c33_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c33_info[8].name = "gt";
  c33_info[8].dominantType = "double";
  c33_info[8].resolved = "[B]gt";
  c33_info[8].fileLength = 0U;
  c33_info[8].fileTime1 = 0U;
  c33_info[8].fileTime2 = 0U;
  c33_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c33_info[9].name = "isa";
  c33_info[9].dominantType = "double";
  c33_info[9].resolved = "[B]isa";
  c33_info[9].fileLength = 0U;
  c33_info[9].fileTime1 = 0U;
  c33_info[9].fileTime2 = 0U;
  c33_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c33_info[10].name = "eml_div";
  c33_info[10].dominantType = "double";
  c33_info[10].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c33_info[10].fileLength = 4269U;
  c33_info[10].fileTime1 = 1228090226U;
  c33_info[10].fileTime2 = 0U;
  c33_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c33_info[11].name = "isinteger";
  c33_info[11].dominantType = "double";
  c33_info[11].resolved = "[B]isinteger";
  c33_info[11].fileLength = 0U;
  c33_info[11].fileTime1 = 0U;
  c33_info[11].fileTime2 = 0U;
  c33_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c33_info[12].name = "isreal";
  c33_info[12].dominantType = "double";
  c33_info[12].resolved = "[B]isreal";
  c33_info[12].fileLength = 0U;
  c33_info[12].fileTime1 = 0U;
  c33_info[12].fileTime2 = 0U;
  c33_info[13].context = "";
  c33_info[13].name = "times";
  c33_info[13].dominantType = "double";
  c33_info[13].resolved = "[B]times";
  c33_info[13].fileLength = 0U;
  c33_info[13].fileTime1 = 0U;
  c33_info[13].fileTime2 = 0U;
  c33_info[14].context = "";
  c33_info[14].name = "cos";
  c33_info[14].dominantType = "double";
  c33_info[14].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c33_info[14].fileLength = 324U;
  c33_info[14].fileTime1 = 1203444350U;
  c33_info[14].fileTime2 = 0U;
  c33_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c33_info[15].name = "eml_scalar_cos";
  c33_info[15].dominantType = "double";
  c33_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c33_info[15].fileLength = 602U;
  c33_info[15].fileTime1 = 1209327186U;
  c33_info[15].fileTime2 = 0U;
  c33_info[16].context = "";
  c33_info[16].name = "sin";
  c33_info[16].dominantType = "double";
  c33_info[16].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c33_info[16].fileLength = 324U;
  c33_info[16].fileTime1 = 1203444442U;
  c33_info[16].fileTime2 = 0U;
  c33_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c33_info[17].name = "eml_scalar_sin";
  c33_info[17].dominantType = "double";
  c33_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c33_info[17].fileLength = 601U;
  c33_info[17].fileTime1 = 1209327190U;
  c33_info[17].fileTime2 = 0U;
  c33_info[18].context = "";
  c33_info[18].name = "mtimes";
  c33_info[18].dominantType = "double";
  c33_info[18].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c33_info[18].fileLength = 3425U;
  c33_info[18].fileTime1 = 1250669166U;
  c33_info[18].fileTime2 = 0U;
  c33_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c33_info[19].name = "strcmp";
  c33_info[19].dominantType = "char";
  c33_info[19].resolved = "[B]strcmp";
  c33_info[19].fileLength = 0U;
  c33_info[19].fileTime1 = 0U;
  c33_info[19].fileTime2 = 0U;
  c33_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c33_info[20].name = "size";
  c33_info[20].dominantType = "double";
  c33_info[20].resolved = "[B]size";
  c33_info[20].fileLength = 0U;
  c33_info[20].fileTime1 = 0U;
  c33_info[20].fileTime2 = 0U;
  c33_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c33_info[21].name = "eq";
  c33_info[21].dominantType = "double";
  c33_info[21].resolved = "[B]eq";
  c33_info[21].fileLength = 0U;
  c33_info[21].fileTime1 = 0U;
  c33_info[21].fileTime2 = 0U;
  c33_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c33_info[22].name = "class";
  c33_info[22].dominantType = "double";
  c33_info[22].resolved = "[B]class";
  c33_info[22].fileLength = 0U;
  c33_info[22].fileTime1 = 0U;
  c33_info[22].fileTime2 = 0U;
  c33_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c33_info[23].name = "not";
  c33_info[23].dominantType = "logical";
  c33_info[23].resolved = "[B]not";
  c33_info[23].fileLength = 0U;
  c33_info[23].fileTime1 = 0U;
  c33_info[23].fileTime2 = 0U;
}

static void c33_emlrt_marshallIn(SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *
  c33_gravity_dynamic_term, const char_T *c33_name, real_T c33_y[16])
{
  real_T c33_dv2[16];
  int32_T c33_i4;
  sf_mex_import(c33_name, sf_mex_dup(c33_gravity_dynamic_term), &c33_dv2, 1, 0,
                0U, 1, 0U, 2, 1, 16);
  for (c33_i4 = 0; c33_i4 < 16; c33_i4 = c33_i4 + 1) {
    c33_y[c33_i4] = c33_dv2[c33_i4];
  }

  sf_mex_destroy(&c33_gravity_dynamic_term);
}

static uint8_T c33_b_emlrt_marshallIn
  (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c33_b_is_active_c33_ODE_Hand_Model_v08_IPC_v03, const char_T *c33_name)
{
  uint8_T c33_y;
  uint8_T c33_u0;
  sf_mex_import(c33_name, sf_mex_dup
                (c33_b_is_active_c33_ODE_Hand_Model_v08_IPC_v03), &c33_u0, 1, 3,
                0U, 0, 0U, 0);
  c33_y = c33_u0;
  sf_mex_destroy(&c33_b_is_active_c33_ODE_Hand_Model_v08_IPC_v03);
  return c33_y;
}

static void init_dsm_address_info(SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c33_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(855269356U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(315039964U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(213142797U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(485429654U);
}

mxArray *sf_c33_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4173724779U);
    pr[1] = (double)(406778799U);
    pr[2] = (double)(1679760182U);
    pr[3] = (double)(3827771181U);
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

static mxArray *sf_get_sim_state_info_c33_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"gravity_dynamic_term\",},{M[8],M[0],T\"is_active_c33_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c33_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c33_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c33_ODE_Hand_Model_v08_IPC_v03
    ((SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c33_ODE_Hand_Model_v08_IPC_v03
    ((SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c33_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c33_ODE_Hand_Model_v08_IPC_v03
    ((SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c33_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c33_ODE_Hand_Model_v08_IPC_v03
    ((SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c33_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c33_ODE_Hand_Model_v08_IPC_v03
    ((SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c33_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c33_ODE_Hand_Model_v08_IPC_v03
    ((SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c33_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c33_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c33_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c33_ODE_Hand_Model_v08_IPC_v03
    ((SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c33_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c33_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c33_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c33_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c33_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c33_ODE_Hand_Model_v08_IPC_v03
      ((SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c33_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c33_ODE_Hand_Model_v08_IPC_v03
      ((SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c33_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",33);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",33,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",33,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",33,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",33,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",33);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3955759099U));
  ssSetChecksum1(S,(689658145U));
  ssSetChecksum2(S,(1460986385U));
  ssSetChecksum3(S,(1125612565U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c33_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",33);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c33_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc
    (sizeof(SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc33_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c33_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c33_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c33_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c33_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c33_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c33_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c33_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c33_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c33_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c33_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c33_ODE_Hand_Model_v08_IPC_v03;
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

void c33_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c33_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c33_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c33_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c33_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
