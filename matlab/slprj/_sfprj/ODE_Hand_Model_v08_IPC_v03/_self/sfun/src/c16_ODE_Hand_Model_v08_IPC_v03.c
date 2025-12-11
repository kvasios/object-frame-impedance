/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c16_ODE_Hand_Model_v08_IPC_v03.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c16_st);
static void finalize_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber);
static real_T c16_norm(SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c16_x[3]);
static real_T c16_ceval_xnrm2(SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c16_n, real_T c16_x[3], int32_T c16_ix0, int32_T
  c16_incx);
static void c16_info_helper(c16_ResolvedFunctionInfo c16_info[62]);
static void c16_emlrt_marshallIn(SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c16_Jc, const char_T *c16_name, real_T c16_y[48]);
static uint8_T c16_b_emlrt_marshallIn
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c16_b_is_active_c16_ODE_Hand_Model_v08_IPC_v03, const char_T *c16_name);
static void init_dsm_address_info(SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c16_is_active_c16_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  int32_T c16_i0;
  real_T c16_u[48];
  const mxArray *c16_b_y = NULL;
  uint8_T c16_b_u;
  const mxArray *c16_c_y = NULL;
  real_T (*c16_Jc)[48];
  c16_Jc = (real_T (*)[48])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellarray(2));
  for (c16_i0 = 0; c16_i0 < 48; c16_i0 = c16_i0 + 1) {
    c16_u[c16_i0] = (*c16_Jc)[c16_i0];
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_u, 0, 0U, 1U, 0U, 2, 12, 4));
  sf_mex_setcell(c16_y, 0, c16_b_y);
  c16_b_u = chartInstance->c16_is_active_c16_ODE_Hand_Model_v08_IPC_v03;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c16_y, 1, c16_c_y);
  sf_mex_assign(&c16_st, c16_y);
  return c16_st;
}

static void set_sim_state_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance,
   const mxArray *c16_st)
{
  const mxArray *c16_u;
  real_T c16_dv0[48];
  int32_T c16_i1;
  real_T (*c16_Jc)[48];
  c16_Jc = (real_T (*)[48])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_u = sf_mex_dup(c16_st);
  c16_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 0)), "Jc",
                       c16_dv0);
  for (c16_i1 = 0; c16_i1 < 48; c16_i1 = c16_i1 + 1) {
    (*c16_Jc)[c16_i1] = c16_dv0[c16_i1];
  }

  chartInstance->c16_is_active_c16_ODE_Hand_Model_v08_IPC_v03 =
    c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u
    , 1)), "is_active_c16_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c16_u);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c16_ODE_Hand_Model_v08_IPC_v03
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c16_previousEvent;
  int32_T c16_i2;
  real_T c16_dx[12];
  int32_T c16_i3;
  real_T c16_B;
  real_T c16_b_B;
  real_T c16_c_B;
  real_T c16_d_B;
  real_T c16_xO;
  real_T c16_b_dx[3];
  real_T c16_norm_dx[4];
  real_T c16_dv1[12];
  int32_T c16_i4;
  static real_T c16_dv2[36] = { 0.75, 0.0, 0.0, -0.25, -0.0, -0.0, -0.25, -0.0,
    -0.0, -0.25, -0.0, -0.0, 0.0, 0.75, 0.0, -0.0, -0.25,
    -0.0, -0.0, -0.25, -0.0, -0.0, -0.25, -0.0, 0.0, 0.0, 0.75, -0.0, -0.0,
    -0.25, -0.0, -0.0, -0.25, -0.0
    , -0.0, -0.25 };

  real_T c16_dv3[12];
  static real_T c16_dv4[36] = { -0.25, -0.0, -0.0, 0.75, 0.0, 0.0, -0.25, -0.0,
    -0.0, -0.25, -0.0, -0.0, -0.0, -0.25, -0.0, 0.0, 0.75
    , 0.0, -0.0, -0.25, -0.0, -0.0, -0.25, -0.0, -0.0, -0.0, -0.25, 0.0, 0.0,
    0.75, -0.0, -0.0, -0.25,
    -0.0, -0.0, -0.25 };

  real_T c16_dv5[12];
  static real_T c16_dv6[36] = { -0.25, -0.0, -0.0, -0.25, -0.0, -0.0, 0.75, 0.0,
    0.0, -0.25, -0.0, -0.0, -0.0, -0.25, -0.0, -0.0,
    -0.25, -0.0, 0.0, 0.75, 0.0, -0.0, -0.25, -0.0, -0.0, -0.0, -0.25, -0.0,
    -0.0, -0.25, 0.0, 0.0, 0.75,
    -0.0, -0.0, -0.25 };

  static real_T c16_dv7[36] = { -0.25, -0.0, -0.0, -0.25, -0.0, -0.0, -0.25,
    -0.0, -0.0, 0.75, 0.0, 0.0, -0.0, -0.25, -0.0, -0.0,
    -0.25, -0.0, -0.0, -0.25, -0.0, 0.0, 0.75, 0.0, -0.0, -0.0, -0.25, -0.0,
    -0.0, -0.25, -0.0, -0.0,
    -0.25, 0.0, 0.0, 0.75 };

  real_T (*c16_Jc)[48];
  real_T (*c16_xi)[12];
  c16_Jc = (real_T (*)[48])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_xi = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c16_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  for (c16_i2 = 0; c16_i2 < 12; c16_i2 = c16_i2 + 1) {
    c16_dx[c16_i2] = 0.0;
  }

  /*  a=0; */
  c16_i2 = 0;
  for (c16_i3 = 0; c16_i3 < 3; c16_i3 = c16_i3 + 1) {
    c16_B = (*c16_xi)[c16_i2];
    c16_b_B = (*c16_xi)[c16_i2 + 1];
    c16_c_B = (*c16_xi)[c16_i2 + 2];
    c16_d_B = (*c16_xi)[c16_i2 + 3];
    c16_xO = 0.25 * (((c16_B + c16_b_B) + c16_c_B) + c16_d_B);

    /*  xO = [0.2000         0    2.09]; */
    /*   */
    c16_dx[c16_i2] = c16_B - c16_xO;
    c16_dx[c16_i2 + 1] = c16_b_B - c16_xO;
    c16_dx[c16_i2 + 2] = c16_c_B - c16_xO;
    c16_dx[c16_i2 + 3] = c16_d_B - c16_xO;
    c16_b_dx[c16_i3] = c16_dx[c16_i2];
    c16_i2 = c16_i2 + 4;
  }

  c16_norm_dx[0] = c16_norm(chartInstance, c16_b_dx);
  c16_i2 = 0;
  for (c16_i3 = 0; c16_i3 < 3; c16_i3 = c16_i3 + 1) {
    c16_b_dx[c16_i3] = c16_dx[c16_i2 + 1];
    c16_i2 = c16_i2 + 4;
  }

  c16_norm_dx[1] = c16_norm(chartInstance, c16_b_dx);
  c16_i2 = 0;
  for (c16_i3 = 0; c16_i3 < 3; c16_i3 = c16_i3 + 1) {
    c16_b_dx[c16_i3] = c16_dx[c16_i2 + 2];
    c16_i2 = c16_i2 + 4;
  }

  c16_norm_dx[2] = c16_norm(chartInstance, c16_b_dx);
  c16_i2 = 0;
  for (c16_i3 = 0; c16_i3 < 3; c16_i3 = c16_i3 + 1) {
    c16_b_dx[c16_i3] = c16_dx[c16_i2 + 3];
    c16_i2 = c16_i2 + 4;
  }

  c16_norm_dx[3] = c16_norm(chartInstance, c16_b_dx);

  /*  size(partial_delta_x1) */
  /*  size(dx(1,:)) */
  /*  size(norm_dx(1)) */
  c16_B = c16_norm_dx[0];
  c16_b_B = c16_norm_dx[1];
  c16_c_B = c16_norm_dx[2];
  c16_d_B = c16_norm_dx[3];
  c16_i2 = 0;
  for (c16_i3 = 0; c16_i3 < 3; c16_i3 = c16_i3 + 1) {
    c16_b_dx[c16_i3] = c16_dx[c16_i2] / c16_B;
    c16_i2 = c16_i2 + 4;
  }

  for (c16_i2 = 0; c16_i2 < 12; c16_i2 = c16_i2 + 1) {
    c16_dv1[c16_i2] = 0.0;
    c16_i3 = 0;
    for (c16_i4 = 0; c16_i4 < 3; c16_i4 = c16_i4 + 1) {
      c16_dv1[c16_i2] = c16_dv1[c16_i2] + c16_dv2[c16_i3 + c16_i2] *
        c16_b_dx[c16_i4];
      c16_i3 = c16_i3 + 12;
    }
  }

  c16_i2 = 0;
  for (c16_i3 = 0; c16_i3 < 3; c16_i3 = c16_i3 + 1) {
    c16_b_dx[c16_i3] = c16_dx[c16_i2 + 1] / c16_b_B;
    c16_i2 = c16_i2 + 4;
  }

  for (c16_i2 = 0; c16_i2 < 12; c16_i2 = c16_i2 + 1) {
    c16_dv3[c16_i2] = 0.0;
    c16_i3 = 0;
    for (c16_i4 = 0; c16_i4 < 3; c16_i4 = c16_i4 + 1) {
      c16_dv3[c16_i2] = c16_dv3[c16_i2] + c16_dv4[c16_i3 + c16_i2] *
        c16_b_dx[c16_i4];
      c16_i3 = c16_i3 + 12;
    }
  }

  c16_i2 = 0;
  for (c16_i3 = 0; c16_i3 < 3; c16_i3 = c16_i3 + 1) {
    c16_b_dx[c16_i3] = c16_dx[c16_i2 + 2] / c16_c_B;
    c16_i2 = c16_i2 + 4;
  }

  for (c16_i2 = 0; c16_i2 < 12; c16_i2 = c16_i2 + 1) {
    c16_dv5[c16_i2] = 0.0;
    c16_i3 = 0;
    for (c16_i4 = 0; c16_i4 < 3; c16_i4 = c16_i4 + 1) {
      c16_dv5[c16_i2] = c16_dv5[c16_i2] + c16_dv6[c16_i3 + c16_i2] *
        c16_b_dx[c16_i4];
      c16_i3 = c16_i3 + 12;
    }
  }

  c16_i2 = 0;
  for (c16_i3 = 0; c16_i3 < 3; c16_i3 = c16_i3 + 1) {
    c16_b_dx[c16_i3] = c16_dx[c16_i2 + 3] / c16_d_B;
    c16_i2 = c16_i2 + 4;
  }

  for (c16_i2 = 0; c16_i2 < 12; c16_i2 = c16_i2 + 1) {
    c16_dx[c16_i2] = 0.0;
    c16_i3 = 0;
    for (c16_i4 = 0; c16_i4 < 3; c16_i4 = c16_i4 + 1) {
      c16_dx[c16_i2] = c16_dx[c16_i2] + c16_dv7[c16_i3 + c16_i2] *
        c16_b_dx[c16_i4];
      c16_i3 = c16_i3 + 12;
    }

    (*c16_Jc)[c16_i2] = c16_dv1[c16_i2];
    (*c16_Jc)[c16_i2 + 12] = c16_dv3[c16_i2];
    (*c16_Jc)[c16_i2 + 24] = c16_dv5[c16_i2];
    (*c16_Jc)[c16_i2 + 36] = c16_dx[c16_i2];
  }

  _sfEvent_ = c16_previousEvent;
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber)
{
}

static real_T c16_norm(SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c16_x[3])
{
  return c16_ceval_xnrm2(chartInstance, 3, c16_x, 1, 1);
}

static real_T c16_ceval_xnrm2(SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c16_n, real_T c16_x[3], int32_T
  c16_ix0, int32_T c16_incx)
{
  return dnrm232(&c16_n, &c16_x[sf_mex_lw_bounds_check(c16_ix0, 1, 3) - 1],
                 &c16_incx);
}

const mxArray *sf_c16_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c16_nameCaptureInfo;
  c16_ResolvedFunctionInfo c16_info[62];
  const mxArray *c16_m0 = NULL;
  int32_T c16_i5;
  c16_ResolvedFunctionInfo *c16_r0;
  c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  c16_info_helper(c16_info);
  sf_mex_assign(&c16_m0, sf_mex_createstruct("nameCaptureInfo", 1, 62));
  for (c16_i5 = 0; c16_i5 < 62; c16_i5 = c16_i5 + 1) {
    c16_r0 = &c16_info[c16_i5];
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c16_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c16_r0->context)), "context", "nameCaptureInfo", c16_i5);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c16_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c16_r0->name)), "name", "nameCaptureInfo", c16_i5);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c16_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const
      char *)c16_r0->dominantType)), "dominantType", "nameCaptureInfo", c16_i5);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c16_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c16_r0->resolved)), "resolved", "nameCaptureInfo", c16_i5);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c16_i5);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c16_i5);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c16_i5);
  }

  sf_mex_assign(&c16_nameCaptureInfo, c16_m0);
  return c16_nameCaptureInfo;
}

static void c16_info_helper(c16_ResolvedFunctionInfo c16_info[62])
{
  c16_info[0].context = "";
  c16_info[0].name = "zeros";
  c16_info[0].dominantType = "double";
  c16_info[0].resolved = "[B]zeros";
  c16_info[0].fileLength = 0U;
  c16_info[0].fileTime1 = 0U;
  c16_info[0].fileTime2 = 0U;
  c16_info[1].context = "";
  c16_info[1].name = "mrdivide";
  c16_info[1].dominantType = "double";
  c16_info[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c16_info[1].fileLength = 800U;
  c16_info[1].fileTime1 = 1238430690U;
  c16_info[1].fileTime2 = 0U;
  c16_info[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c16_info[2].name = "nargin";
  c16_info[2].dominantType = "";
  c16_info[2].resolved = "[B]nargin";
  c16_info[2].fileLength = 0U;
  c16_info[2].fileTime1 = 0U;
  c16_info[2].fileTime2 = 0U;
  c16_info[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c16_info[3].name = "ge";
  c16_info[3].dominantType = "double";
  c16_info[3].resolved = "[B]ge";
  c16_info[3].fileLength = 0U;
  c16_info[3].fileTime1 = 0U;
  c16_info[3].fileTime2 = 0U;
  c16_info[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c16_info[4].name = "isscalar";
  c16_info[4].dominantType = "double";
  c16_info[4].resolved = "[B]isscalar";
  c16_info[4].fileLength = 0U;
  c16_info[4].fileTime1 = 0U;
  c16_info[4].fileTime2 = 0U;
  c16_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c16_info[5].name = "rdivide";
  c16_info[5].dominantType = "double";
  c16_info[5].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c16_info[5].fileLength = 403U;
  c16_info[5].fileTime1 = 1244731952U;
  c16_info[5].fileTime2 = 0U;
  c16_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c16_info[6].name = "gt";
  c16_info[6].dominantType = "double";
  c16_info[6].resolved = "[B]gt";
  c16_info[6].fileLength = 0U;
  c16_info[6].fileTime1 = 0U;
  c16_info[6].fileTime2 = 0U;
  c16_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c16_info[7].name = "isa";
  c16_info[7].dominantType = "double";
  c16_info[7].resolved = "[B]isa";
  c16_info[7].fileLength = 0U;
  c16_info[7].fileTime1 = 0U;
  c16_info[7].fileTime2 = 0U;
  c16_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c16_info[8].name = "eml_div";
  c16_info[8].dominantType = "double";
  c16_info[8].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c16_info[8].fileLength = 4269U;
  c16_info[8].fileTime1 = 1228090226U;
  c16_info[8].fileTime2 = 0U;
  c16_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c16_info[9].name = "isinteger";
  c16_info[9].dominantType = "double";
  c16_info[9].resolved = "[B]isinteger";
  c16_info[9].fileLength = 0U;
  c16_info[9].fileTime1 = 0U;
  c16_info[9].fileTime2 = 0U;
  c16_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c16_info[10].name = "isreal";
  c16_info[10].dominantType = "double";
  c16_info[10].resolved = "[B]isreal";
  c16_info[10].fileLength = 0U;
  c16_info[10].fileTime1 = 0U;
  c16_info[10].fileTime2 = 0U;
  c16_info[11].context = "";
  c16_info[11].name = "minus";
  c16_info[11].dominantType = "double";
  c16_info[11].resolved = "[B]minus";
  c16_info[11].fileLength = 0U;
  c16_info[11].fileTime1 = 0U;
  c16_info[11].fileTime2 = 0U;
  c16_info[12].context = "";
  c16_info[12].name = "uminus";
  c16_info[12].dominantType = "double";
  c16_info[12].resolved = "[B]uminus";
  c16_info[12].fileLength = 0U;
  c16_info[12].fileTime1 = 0U;
  c16_info[12].fileTime2 = 0U;
  c16_info[13].context = "";
  c16_info[13].name = "plus";
  c16_info[13].dominantType = "double";
  c16_info[13].resolved = "[B]plus";
  c16_info[13].fileLength = 0U;
  c16_info[13].fileTime1 = 0U;
  c16_info[13].fileTime2 = 0U;
  c16_info[14].context = "";
  c16_info[14].name = "mtimes";
  c16_info[14].dominantType = "double";
  c16_info[14].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[14].fileLength = 3425U;
  c16_info[14].fileTime1 = 1250669166U;
  c16_info[14].fileTime2 = 0U;
  c16_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[15].name = "strcmp";
  c16_info[15].dominantType = "char";
  c16_info[15].resolved = "[B]strcmp";
  c16_info[15].fileLength = 0U;
  c16_info[15].fileTime1 = 0U;
  c16_info[15].fileTime2 = 0U;
  c16_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[16].name = "size";
  c16_info[16].dominantType = "double";
  c16_info[16].resolved = "[B]size";
  c16_info[16].fileLength = 0U;
  c16_info[16].fileTime1 = 0U;
  c16_info[16].fileTime2 = 0U;
  c16_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[17].name = "eq";
  c16_info[17].dominantType = "double";
  c16_info[17].resolved = "[B]eq";
  c16_info[17].fileLength = 0U;
  c16_info[17].fileTime1 = 0U;
  c16_info[17].fileTime2 = 0U;
  c16_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[18].name = "class";
  c16_info[18].dominantType = "double";
  c16_info[18].resolved = "[B]class";
  c16_info[18].fileLength = 0U;
  c16_info[18].fileTime1 = 0U;
  c16_info[18].fileTime2 = 0U;
  c16_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[19].name = "not";
  c16_info[19].dominantType = "logical";
  c16_info[19].resolved = "[B]not";
  c16_info[19].fileLength = 0U;
  c16_info[19].fileTime1 = 0U;
  c16_info[19].fileTime2 = 0U;
  c16_info[20].context = "";
  c16_info[20].name = "norm";
  c16_info[20].dominantType = "double";
  c16_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c16_info[20].fileLength = 5312U;
  c16_info[20].fileTime1 = 1262616676U;
  c16_info[20].fileTime2 = 0U;
  c16_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c16_info[21].name = "ndims";
  c16_info[21].dominantType = "double";
  c16_info[21].resolved = "[B]ndims";
  c16_info[21].fileLength = 0U;
  c16_info[21].fileTime1 = 0U;
  c16_info[21].fileTime2 = 0U;
  c16_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c16_info[22].name = "le";
  c16_info[22].dominantType = "double";
  c16_info[22].resolved = "[B]le";
  c16_info[22].fileLength = 0U;
  c16_info[22].fileTime1 = 0U;
  c16_info[22].fileTime2 = 0U;
  c16_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c16_info[23].name = "lt";
  c16_info[23].dominantType = "double";
  c16_info[23].resolved = "[B]lt";
  c16_info[23].fileLength = 0U;
  c16_info[23].fileTime1 = 0U;
  c16_info[23].fileTime2 = 0U;
  c16_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c16_info[24].name = "isempty";
  c16_info[24].dominantType = "double";
  c16_info[24].resolved = "[B]isempty";
  c16_info[24].fileLength = 0U;
  c16_info[24].fileTime1 = 0U;
  c16_info[24].fileTime2 = 0U;
  c16_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c16_info[25].name = "isvector";
  c16_info[25].dominantType = "double";
  c16_info[25].resolved = "[B]isvector";
  c16_info[25].fileLength = 0U;
  c16_info[25].fileTime1 = 0U;
  c16_info[25].fileTime2 = 0U;
  c16_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c16_info[26].name = "eml_index_class";
  c16_info[26].dominantType = "";
  c16_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c16_info[26].fileLength = 909U;
  c16_info[26].fileTime1 = 1192463182U;
  c16_info[26].fileTime2 = 0U;
  c16_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c16_info[27].name = "ones";
  c16_info[27].dominantType = "char";
  c16_info[27].resolved = "[B]ones";
  c16_info[27].fileLength = 0U;
  c16_info[27].fileTime1 = 0U;
  c16_info[27].fileTime2 = 0U;
  c16_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c16_info[28].name = "ischar";
  c16_info[28].dominantType = "double";
  c16_info[28].resolved = "[B]ischar";
  c16_info[28].fileLength = 0U;
  c16_info[28].fileTime1 = 0U;
  c16_info[28].fileTime2 = 0U;
  c16_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c16_info[29].name = "eml_xnrm2";
  c16_info[29].dominantType = "int32";
  c16_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c16_info[29].fileLength = 718U;
  c16_info[29].fileTime1 = 1209327256U;
  c16_info[29].fileTime2 = 0U;
  c16_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c16_info[30].name = "cast";
  c16_info[30].dominantType = "double";
  c16_info[30].resolved = "[B]cast";
  c16_info[30].fileLength = 0U;
  c16_info[30].fileTime1 = 0U;
  c16_info[30].fileTime2 = 0U;
  c16_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c16_info[31].name = "eml_refblas_xnrm2";
  c16_info[31].dominantType = "int32";
  c16_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c16_info[31].fileLength = 1433U;
  c16_info[31].fileTime1 = 1240258442U;
  c16_info[31].fileTime2 = 0U;
  c16_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c16_info[32].name = "true";
  c16_info[32].dominantType = "";
  c16_info[32].resolved = "[B]true";
  c16_info[32].fileLength = 0U;
  c16_info[32].fileTime1 = 0U;
  c16_info[32].fileTime2 = 0U;
  c16_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c16_info[33].name = "eml_index_minus";
  c16_info[33].dominantType = "int32";
  c16_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c16_info[33].fileLength = 277U;
  c16_info[33].fileTime1 = 1192463184U;
  c16_info[33].fileTime2 = 0U;
  c16_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c16_info[34].name = "eml_index_times";
  c16_info[34].dominantType = "int32";
  c16_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c16_info[34].fileLength = 280U;
  c16_info[34].fileTime1 = 1192463186U;
  c16_info[34].fileTime2 = 0U;
  c16_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c16_info[35].name = "eml_index_plus";
  c16_info[35].dominantType = "int32";
  c16_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c16_info[35].fileLength = 272U;
  c16_info[35].fileTime1 = 1192463184U;
  c16_info[35].fileTime2 = 0U;
  c16_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c16_info[36].name = "real";
  c16_info[36].dominantType = "double";
  c16_info[36].resolved = "[B]real";
  c16_info[36].fileLength = 0U;
  c16_info[36].fileTime1 = 0U;
  c16_info[36].fileTime2 = 0U;
  c16_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c16_info[37].name = "ne";
  c16_info[37].dominantType = "double";
  c16_info[37].resolved = "[B]ne";
  c16_info[37].fileLength = 0U;
  c16_info[37].fileTime1 = 0U;
  c16_info[37].fileTime2 = 0U;
  c16_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c16_info[38].name = "abs";
  c16_info[38].dominantType = "double";
  c16_info[38].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c16_info[38].fileLength = 566U;
  c16_info[38].fileTime1 = 1221263532U;
  c16_info[38].fileTime2 = 0U;
  c16_info[39].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c16_info[39].name = "islogical";
  c16_info[39].dominantType = "double";
  c16_info[39].resolved = "[B]islogical";
  c16_info[39].fileLength = 0U;
  c16_info[39].fileTime1 = 0U;
  c16_info[39].fileTime2 = 0U;
  c16_info[40].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c16_info[40].name = "eml_scalar_abs";
  c16_info[40].dominantType = "double";
  c16_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c16_info[40].fileLength = 461U;
  c16_info[40].fileTime1 = 1203444360U;
  c16_info[40].fileTime2 = 0U;
  c16_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c16_info[41].name = "false";
  c16_info[41].dominantType = "";
  c16_info[41].resolved = "[B]false";
  c16_info[41].fileLength = 0U;
  c16_info[41].fileTime1 = 0U;
  c16_info[41].fileTime2 = 0U;
  c16_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c16_info[42].name = "times";
  c16_info[42].dominantType = "double";
  c16_info[42].resolved = "[B]times";
  c16_info[42].fileLength = 0U;
  c16_info[42].fileTime1 = 0U;
  c16_info[42].fileTime2 = 0U;
  c16_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c16_info[43].name = "imag";
  c16_info[43].dominantType = "double";
  c16_info[43].resolved = "[B]imag";
  c16_info[43].fileLength = 0U;
  c16_info[43].fileTime1 = 0U;
  c16_info[43].fileTime2 = 0U;
  c16_info[44].context = "";
  c16_info[44].name = "eye";
  c16_info[44].dominantType = "double";
  c16_info[44].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c16_info[44].fileLength = 1765U;
  c16_info[44].fileTime1 = 1219749288U;
  c16_info[44].fileTime2 = 0U;
  c16_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c16_info[45].name = "eml_assert_valid_size_arg";
  c16_info[45].dominantType = "double";
  c16_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c16_info[45].fileLength = 3315U;
  c16_info[45].fileTime1 = 1256041632U;
  c16_info[45].fileTime2 = 0U;
  c16_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c16_info[46].name = "isinf";
  c16_info[46].dominantType = "double";
  c16_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c16_info[46].fileLength = 506U;
  c16_info[46].fileTime1 = 1228090208U;
  c16_info[46].fileTime2 = 0U;
  c16_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c16_info[47].name = "double";
  c16_info[47].dominantType = "double";
  c16_info[47].resolved = "[B]double";
  c16_info[47].fileLength = 0U;
  c16_info[47].fileTime1 = 0U;
  c16_info[47].fileTime2 = 0U;
  c16_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c16_info[48].name = "intmax";
  c16_info[48].dominantType = "char";
  c16_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c16_info[48].fileLength = 1535U;
  c16_info[48].fileTime1 = 1192463128U;
  c16_info[48].fileTime2 = 0U;
  c16_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c16_info[49].name = "int32";
  c16_info[49].dominantType = "double";
  c16_info[49].resolved = "[B]int32";
  c16_info[49].fileLength = 0U;
  c16_info[49].fileTime1 = 0U;
  c16_info[49].fileTime2 = 0U;
  c16_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c16_info[50].name = "eml_is_float_class";
  c16_info[50].dominantType = "char";
  c16_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c16_info[50].fileLength = 226U;
  c16_info[50].fileTime1 = 1197846840U;
  c16_info[50].fileTime2 = 0U;
  c16_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c16_info[51].name = "min";
  c16_info[51].dominantType = "double";
  c16_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c16_info[51].fileLength = 362U;
  c16_info[51].fileTime1 = 1244731952U;
  c16_info[51].fileTime2 = 0U;
  c16_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c16_info[52].name = "nargout";
  c16_info[52].dominantType = "";
  c16_info[52].resolved = "[B]nargout";
  c16_info[52].fileLength = 0U;
  c16_info[52].fileTime1 = 0U;
  c16_info[52].fileTime2 = 0U;
  c16_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c16_info[53].name = "eml_min_or_max";
  c16_info[53].dominantType = "char";
  c16_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c16_info[53].fileLength = 9969U;
  c16_info[53].fileTime1 = 1240258406U;
  c16_info[53].fileTime2 = 0U;
  c16_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c16_info[54].name = "isnumeric";
  c16_info[54].dominantType = "double";
  c16_info[54].resolved = "[B]isnumeric";
  c16_info[54].fileLength = 0U;
  c16_info[54].fileTime1 = 0U;
  c16_info[54].fileTime2 = 0U;
  c16_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c16_info[55].name = "eml_scalar_eg";
  c16_info[55].dominantType = "double";
  c16_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c16_info[55].fileLength = 3068U;
  c16_info[55].fileTime1 = 1240258410U;
  c16_info[55].fileTime2 = 0U;
  c16_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c16_info[56].name = "isstruct";
  c16_info[56].dominantType = "double";
  c16_info[56].resolved = "[B]isstruct";
  c16_info[56].fileLength = 0U;
  c16_info[56].fileTime1 = 0U;
  c16_info[56].fileTime2 = 0U;
  c16_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c16_info[57].name = "eml_scalexp_alloc";
  c16_info[57].dominantType = "double";
  c16_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c16_info[57].fileLength = 808U;
  c16_info[57].fileTime1 = 1230491098U;
  c16_info[57].fileTime2 = 0U;
  c16_info[58].context = "";
  c16_info[58].name = "ctranspose";
  c16_info[58].dominantType = "double";
  c16_info[58].resolved = "[B]ctranspose";
  c16_info[58].fileLength = 0U;
  c16_info[58].fileTime1 = 0U;
  c16_info[58].fileTime2 = 0U;
  c16_info[59].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[59].name = "eml_xgemm";
  c16_info[59].dominantType = "int32";
  c16_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c16_info[59].fileLength = 3184U;
  c16_info[59].fileTime1 = 1209327252U;
  c16_info[59].fileTime2 = 0U;
  c16_info[60].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c16_info[60].name = "length";
  c16_info[60].dominantType = "double";
  c16_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c16_info[60].fileLength = 326U;
  c16_info[60].fileTime1 = 1226573674U;
  c16_info[60].fileTime2 = 0U;
  c16_info[61].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c16_info[61].name = "eml_refblas_xgemm";
  c16_info[61].dominantType = "int32";
  c16_info[61].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c16_info[61].fileLength = 5748U;
  c16_info[61].fileTime1 = 1228090272U;
  c16_info[61].fileTime2 = 0U;
}

static void c16_emlrt_marshallIn(SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c16_Jc, const char_T
  *c16_name, real_T c16_y[48])
{
  real_T c16_dv8[48];
  int32_T c16_i6;
  sf_mex_import(c16_name, sf_mex_dup(c16_Jc), &c16_dv8, 1, 0, 0U, 1, 0U, 2, 12,
                4);
  for (c16_i6 = 0; c16_i6 < 48; c16_i6 = c16_i6 + 1) {
    c16_y[c16_i6] = c16_dv8[c16_i6];
  }

  sf_mex_destroy(&c16_Jc);
}

static uint8_T c16_b_emlrt_marshallIn
  (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c16_b_is_active_c16_ODE_Hand_Model_v08_IPC_v03, const char_T *c16_name)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  sf_mex_import(c16_name, sf_mex_dup
                (c16_b_is_active_c16_ODE_Hand_Model_v08_IPC_v03), &c16_u0, 1, 3,
                0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_b_is_active_c16_ODE_Hand_Model_v08_IPC_v03);
  return c16_y;
}

static void init_dsm_address_info(SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c16_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3122827594U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(597793299U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2859837724U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2847988879U);
}

mxArray *sf_c16_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2321250901U);
    pr[1] = (double)(983217149U);
    pr[2] = (double)(119676868U);
    pr[3] = (double)(489723157U);
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
      pr[0] = (double)(12);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c16_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Jc\",},{M[8],M[0],T\"is_active_c16_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c16_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c16_ODE_Hand_Model_v08_IPC_v03
    ((SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c16_ODE_Hand_Model_v08_IPC_v03
    ((SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c16_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c16_ODE_Hand_Model_v08_IPC_v03
    ((SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c16_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c16_ODE_Hand_Model_v08_IPC_v03
    ((SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c16_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c16_ODE_Hand_Model_v08_IPC_v03
    ((SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c16_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c16_ODE_Hand_Model_v08_IPC_v03
    ((SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c16_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c16_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c16_ODE_Hand_Model_v08_IPC_v03
    ((SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c16_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c16_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c16_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c16_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c16_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c16_ODE_Hand_Model_v08_IPC_v03
      ((SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c16_ODE_Hand_Model_v08_IPC_v03
      ((SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",16,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",16,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",16,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",16);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(4262640647U));
  ssSetChecksum1(S,(3348844408U));
  ssSetChecksum2(S,(538830199U));
  ssSetChecksum3(S,(3806318422U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c16_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",16);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc
    (sizeof(SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc16_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c16_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c16_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c16_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c16_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c16_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c16_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c16_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c16_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c16_ODE_Hand_Model_v08_IPC_v03;
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

void c16_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
