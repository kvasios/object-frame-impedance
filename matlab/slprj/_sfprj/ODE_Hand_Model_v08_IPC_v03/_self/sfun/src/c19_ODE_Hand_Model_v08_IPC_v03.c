/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c19_ODE_Hand_Model_v08_IPC_v03.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c19_st);
static void finalize_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber);
static void c19_info_helper(c19_ResolvedFunctionInfo c19_info[58]);
static void c19_emlrt_marshallIn(SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c19_tau_N, const char_T *c19_name, real_T c19_y
  [16]);
static uint8_T c19_b_emlrt_marshallIn
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c19_b_is_active_c19_ODE_Hand_Model_v08_IPC_v03, const char_T *c19_name);
static void c19_refp12_ceval_xgemm
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, int32_T c19_m,
   int32_T c19_n, int32_T c19_k, real_T c19_alpha1, real_T c19_A[384], int32_T
   c19_ia0, int32_T c19_lda, real_T c19_B[384], int32_T c19_ib0, int32_T c19_ldb,
   real_T c19_beta1, real_T c19_C[256], int32_T c19_ic0, int32_T c19_ldc);
static void c19_b_refp12_ceval_xgemm
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, int32_T c19_m,
   int32_T c19_n, int32_T c19_k, real_T c19_alpha1, real_T c19_A[256], int32_T
   c19_ia0, int32_T c19_lda, real_T c19_B[16], int32_T c19_ib0, int32_T c19_ldb,
   real_T c19_beta1, real_T c19_C[16], int32_T c19_ic0, int32_T c19_ldc);
static void init_dsm_address_info(SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c19_is_active_c19_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  int32_T c19_i0;
  real_T c19_u[16];
  const mxArray *c19_b_y = NULL;
  uint8_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  real_T (*c19_tau_N)[16];
  c19_tau_N = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellarray(2));
  for (c19_i0 = 0; c19_i0 < 16; c19_i0 = c19_i0 + 1) {
    c19_u[c19_i0] = (*c19_tau_N)[c19_i0];
  }

  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_u, 0, 0U, 1U, 0U, 1, 16));
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_b_u = chartInstance->c19_is_active_c19_ODE_Hand_Model_v08_IPC_v03;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 1, c19_c_y);
  sf_mex_assign(&c19_st, c19_y);
  return c19_st;
}

static void set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance,
   const mxArray *c19_st)
{
  const mxArray *c19_u;
  real_T c19_dv0[16];
  int32_T c19_i1;
  real_T (*c19_tau_N)[16];
  c19_tau_N = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c19_u = sf_mex_dup(c19_st);
  c19_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 0)),
                       "tau_N", c19_dv0);
  for (c19_i1 = 0; c19_i1 < 16; c19_i1 = c19_i1 + 1) {
    (*c19_tau_N)[c19_i1] = c19_dv0[c19_i1];
  }

  chartInstance->c19_is_active_c19_ODE_Hand_Model_v08_IPC_v03 =
    c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u
    , 1)), "is_active_c19_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c19_u);
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c19_ODE_Hand_Model_v08_IPC_v03
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c19_previousEvent;
  int32_T c19_i;
  real_T c19_q_in[16];
  real_T c19_dq[16];
  real_T c19_J[384];
  real_T c19_c;
  int32_T c19_b_i;
  real_T c19_q1;
  real_T c19_q2;
  real_T c19_q3;
  real_T c19_q4;
  int32_T c19_c_i;
  real_T c19_dv1[24];
  int32_T c19_d_i;
  static int8_T c19_iv0[4] = { 1, 0, 0, 0 };

  int32_T c19_i2;
  static int8_T c19_iv1[36] = { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1
    , 0, 0 };

  real_T c19_tau[16];
  static int8_T c19_iv2[4] = { 0, 0, 1, -1 };

  int8_T c19_I[256];
  real_T c19_y[256];
  real_T c19_b_J[384];
  real_T c19_b_I[256];
  real_T (*c19_tau_N)[16];
  real_T (*c19_b_q_in)[16];
  real_T (*c19_dq_in)[16];
  c19_dq_in = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 1);
  c19_tau_N = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c19_b_q_in = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c19_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  for (c19_i = 0; c19_i < 16; c19_i = c19_i + 1) {
    c19_q_in[c19_i] = (*c19_b_q_in)[c19_i];
    c19_dq[c19_i] = (*c19_dq_in)[c19_i];
  }

  for (c19_i = 0; c19_i < 384; c19_i = c19_i + 1) {
    c19_J[c19_i] = 0.0;
  }

  c19_c = 1.0;
  for (c19_b_i = 0; c19_b_i < 16; c19_b_i = c19_b_i + 4) {
    c19_q1 = c19_q_in[c19_b_i];
    c19_q2 = c19_q_in[sf_mex_lw_bounds_check(c19_b_i + 2, 1, 16) - 1];
    c19_q3 = c19_q_in[sf_mex_lw_bounds_check(c19_b_i + 3, 1, 16) - 1];
    c19_q4 = c19_q_in[sf_mex_lw_bounds_check(c19_b_i + 4, 1, 16) - 1];
    c19_c_i = c19_b_i + 1;
    c19_dv1[0] = -1.0 * ((1.1 * muDoubleScalarCos(c19_q2) + 0.6 *
                          muDoubleScalarCos(c19_q2 + c19_q3)) + 0.55 *
                         muDoubleScalarCos((c19_q2
      + c19_q3) + c19_q4)) * muDoubleScalarSin(c19_q1);
    c19_dv1[6] = -1.0 * muDoubleScalarCos(c19_q1) * ((1.1 * muDoubleScalarSin
      (c19_q2) + 0.6 * muDoubleScalarSin(c19_q2 + c19_q3)) + 0.55
      * muDoubleScalarSin((c19_q2 + c19_q3) + c19_q4));
    c19_dv1[12] = -1.0 * muDoubleScalarCos(c19_q1) * (0.6 * muDoubleScalarSin
      (c19_q2 + c19_q3) + 0.55 * muDoubleScalarSin((c19_q2 +
      c19_q3) + c19_q4));
    c19_dv1[18] = -0.55 * muDoubleScalarCos(c19_q1) * muDoubleScalarSin((c19_q2
      + c19_q3) + c19_q4);
    c19_dv1[1] = muDoubleScalarCos(c19_q1) * ((1.1 * muDoubleScalarCos(c19_q2) +
      0.6 * muDoubleScalarCos(c19_q2 + c19_q3)) + 0.55 *
      muDoubleScalarCos((c19_q2 + c19_q3) + c19_q4));
    c19_dv1[7] = -1.0 * muDoubleScalarSin(c19_q1) * ((1.1 * muDoubleScalarSin
      (c19_q2) + 0.6 * muDoubleScalarSin(c19_q2 + c19_q3)) + 0.55
      * muDoubleScalarSin((c19_q2 + c19_q3) + c19_q4));
    c19_dv1[13] = -1.0 * muDoubleScalarSin(c19_q1) * (0.6 * muDoubleScalarSin
      (c19_q2 + c19_q3) + 0.55 * muDoubleScalarSin((c19_q2 +
      c19_q3) + c19_q4));
    c19_dv1[19] = -0.55 * muDoubleScalarSin(c19_q1) * muDoubleScalarSin((c19_q2
      + c19_q3) + c19_q4);
    c19_dv1[2] = 0.0;
    c19_dv1[8] = muDoubleScalarPower(muDoubleScalarCos(c19_q1), 2.0) * ((1.1 *
      muDoubleScalarCos(c19_q2) + 0.6 * muDoubleScalarCos(
      c19_q2 + c19_q3)) + 0.55 * muDoubleScalarCos((c19_q2 + c19_q3) + c19_q4))
      + ((1.1 * muDoubleScalarCos(c19_q2) + 0.6 *
          muDoubleScalarCos(c19_q2 + c19_q3)) + 0.55 * muDoubleScalarCos((c19_q2
           + c19_q3) + c19_q4)) * muDoubleScalarPower(muDoubleScalarSin(
      c19_q1), 2.0);
    c19_dv1[14] = muDoubleScalarCos(c19_q1) * (-1.1 * muDoubleScalarCos(c19_q1) *
      muDoubleScalarCos(c19_q2) + muDoubleScalarCos(c19_q1)
      * ((1.1 * muDoubleScalarCos(c19_q2) + 0.6 * muDoubleScalarCos(c19_q2 +
      c19_q3)) + 0.55 * muDoubleScalarCos((c19_q2 + c19_q3) +
      c19_q4))) + muDoubleScalarSin(c19_q1) * (-1.1 * muDoubleScalarCos(c19_q2) *
      muDoubleScalarSin(c19_q1) + ((1.1 * muDoubleScalarCos(
      c19_q2) + 0.6 * muDoubleScalarCos(c19_q2 + c19_q3)) + 0.55 *
      muDoubleScalarCos((c19_q2 + c19_q3) + c19_q4)) * muDoubleScalarSin(
      c19_q1));
    c19_dv1[20] = muDoubleScalarCos(c19_q1) * (-1.0 * muDoubleScalarCos(c19_q1) *
      (1.1 * muDoubleScalarCos(c19_q2) + 0.6 *
       muDoubleScalarCos(c19_q2 + c19_q3)) + muDoubleScalarCos(c19_q1) * ((1.1 *
      muDoubleScalarCos(c19_q2) + 0.6 * muDoubleScalarCos(c19_q2
      + c19_q3)) + 0.55 * muDoubleScalarCos((c19_q2 + c19_q3) + c19_q4))) +
      muDoubleScalarSin(c19_q1) * (-1.0 * (1.1 * muDoubleScalarCos(
      c19_q2) + 0.6 * muDoubleScalarCos(c19_q2 + c19_q3)) * muDoubleScalarSin
      (c19_q1) + ((1.1 * muDoubleScalarCos(c19_q2) + 0.6 *
                   muDoubleScalarCos(c19_q2 + c19_q3)) + 0.55 *
                  muDoubleScalarCos((c19_q2 + c19_q3) + c19_q4)) *
      muDoubleScalarSin(c19_q1));
    c19_dv1[3] = 0.0;
    c19_dv1[9] = muDoubleScalarSin(c19_q1);
    c19_dv1[15] = muDoubleScalarSin(c19_q1);
    c19_dv1[21] = muDoubleScalarSin(c19_q1);
    c19_dv1[4] = 0.0;
    c19_dv1[10] = -1.0 * muDoubleScalarCos(c19_q1);
    c19_dv1[16] = -1.0 * muDoubleScalarCos(c19_q1);
    c19_dv1[22] = -1.0 * muDoubleScalarCos(c19_q1);
    c19_i = 0;
    for (c19_d_i = 0; c19_d_i < 4; c19_d_i = c19_d_i + 1) {
      c19_dv1[c19_i + 5] = (real_T)c19_iv0[c19_d_i];
      c19_i = c19_i + 6;
    }

    for (c19_i = 0; c19_i < 6; c19_i = c19_i + 1) {
      for (c19_d_i = 0; c19_d_i < 4; c19_d_i = c19_d_i + 1) {
        c19_J[(sf_mex_lw_bounds_check((int32_T)(c19_c + (real_T)c19_i), 1, 24) -
               1) + 24 * (sf_mex_lw_bounds_check(c19_c_i + c19_d_i, 1, 16)
                          - 1)] = 0.0;
        for (c19_i2 = 0; c19_i2 < 6; c19_i2 = c19_i2 + 1) {
          c19_J[(sf_mex_lw_bounds_check((int32_T)(c19_c + (real_T)c19_i), 1, 24)
                 - 1) + 24 * (sf_mex_lw_bounds_check(c19_c_i + c19_d_i, 1, 16)
                              - 1)] = c19_J[(sf_mex_lw_bounds_check((int32_T)
            (c19_c + (real_T)c19_i), 1, 24) - 1) + 24 * (sf_mex_lw_bounds_check
            (c19_c_i +
             c19_d_i, 1, 16) - 1)] + (real_T)c19_iv1[c19_i + 6 * c19_i2] *
            c19_dv1[c19_i2 + 6 * c19_d_i];
        }
      }
    }

    c19_c = c19_c + 6.0;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  /*  size(JH) */
  /*   K=0; */
  for (c19_i = 0; c19_i < 16; c19_i = c19_i + 1) {
    c19_tau[c19_i] = 0.0;
  }

  for (c19_b_i = 0; c19_b_i < 16; c19_b_i = c19_b_i + 4) {
    sf_mex_lw_bounds_check(c19_b_i + 4, 1, 16);
    sf_mex_lw_bounds_check(c19_b_i + 3, 1, 16);
    c19_c = 50.0 * (c19_q_in[sf_mex_lw_bounds_check(c19_b_i + 3, 1, 16) - 1] -
                    c19_q_in[sf_mex_lw_bounds_check(c19_b_i + 4, 1, 16) - 1]);
    c19_i = c19_b_i + 1;
    for (c19_d_i = 0; c19_d_i < 4; c19_d_i = c19_d_i + 1) {
      sf_mex_lw_bounds_check(c19_i + c19_d_i, 1, 16);
    }

    c19_i = c19_b_i + 1;
    for (c19_d_i = 0; c19_d_i < 4; c19_d_i = c19_d_i + 1) {
      sf_mex_lw_bounds_check(c19_i + c19_d_i, 1, 16);
    }

    c19_i = c19_b_i + 1;
    c19_d_i = c19_b_i + 1;
    for (c19_i2 = 0; c19_i2 < 4; c19_i2 = c19_i2 + 1) {
      c19_tau[sf_mex_lw_bounds_check(c19_i + c19_i2, 1, 16) - 1] = c19_c *
        (real_T)c19_iv2[c19_i2] + 0.9 * c19_dq[sf_mex_lw_bounds_check(
        c19_d_i + c19_i2, 1, 16) - 1];
    }

    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  for (c19_i = 0; c19_i < 256; c19_i = c19_i + 1) {
    c19_I[c19_i] = 0;
  }

  c19_i = 0;
  for (c19_d_i = 0; c19_d_i < 16; c19_d_i = c19_d_i + 1) {
    c19_I[c19_i] = 1;
    c19_i = c19_i + 17;
  }

  for (c19_i = 0; c19_i < 256; c19_i = c19_i + 1) {
    c19_y[c19_i] = 0.0;
  }

  c19_i = 0;
  for (c19_d_i = 0; c19_d_i < 24; c19_d_i = c19_d_i + 1) {
    c19_i2 = 0;
    for (c19_b_i = 0; c19_b_i < 16; c19_b_i = c19_b_i + 1) {
      c19_b_J[c19_b_i + c19_i] = c19_J[c19_i2 + c19_d_i];
      c19_i2 = c19_i2 + 24;
    }

    c19_i = c19_i + 16;
  }

  c19_refp12_ceval_xgemm(chartInstance, 16, 16, 24, 1.0, c19_b_J, 1, 16, c19_J,
    1, 24, 0.0, c19_y, 1, 16);
  for (c19_i = 0; c19_i < 16; c19_i = c19_i + 1) {
    (*c19_tau_N)[c19_i] = 0.0;
  }

  for (c19_i = 0; c19_i < 256; c19_i = c19_i + 1) {
    c19_b_I[c19_i] = (real_T)c19_I[c19_i] - c19_y[c19_i];
  }

  c19_b_refp12_ceval_xgemm(chartInstance, 16, 1, 16, 1.0, c19_b_I, 1, 16,
    c19_tau, 1, 16, 0.0, *c19_tau_N, 1, 16);
  _sfEvent_ = c19_previousEvent;
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber)
{
}

const mxArray *sf_c19_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c19_nameCaptureInfo;
  c19_ResolvedFunctionInfo c19_info[58];
  const mxArray *c19_m0 = NULL;
  int32_T c19_i3;
  c19_ResolvedFunctionInfo *c19_r0;
  c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  c19_info_helper(c19_info);
  sf_mex_assign(&c19_m0, sf_mex_createstruct("nameCaptureInfo", 1, 58));
  for (c19_i3 = 0; c19_i3 < 58; c19_i3 = c19_i3 + 1) {
    c19_r0 = &c19_info[c19_i3];
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c19_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c19_r0->context)), "context", "nameCaptureInfo", c19_i3);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c19_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c19_r0->name)), "name", "nameCaptureInfo", c19_i3);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c19_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const
      char *)c19_r0->dominantType)), "dominantType", "nameCaptureInfo", c19_i3);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c19_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c19_r0->resolved)), "resolved", "nameCaptureInfo", c19_i3);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c19_i3);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c19_i3);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c19_i3);
  }

  sf_mex_assign(&c19_nameCaptureInfo, c19_m0);
  return c19_nameCaptureInfo;
}

static void c19_info_helper(c19_ResolvedFunctionInfo c19_info[58])
{
  c19_info[0].context = "";
  c19_info[0].name = "ctranspose";
  c19_info[0].dominantType = "double";
  c19_info[0].resolved = "[B]ctranspose";
  c19_info[0].fileLength = 0U;
  c19_info[0].fileTime1 = 0U;
  c19_info[0].fileTime2 = 0U;
  c19_info[1].context = "";
  c19_info[1].name = "zeros";
  c19_info[1].dominantType = "double";
  c19_info[1].resolved = "[B]zeros";
  c19_info[1].fileLength = 0U;
  c19_info[1].fileTime1 = 0U;
  c19_info[1].fileTime2 = 0U;
  c19_info[2].context = "";
  c19_info[2].name = "uminus";
  c19_info[2].dominantType = "double";
  c19_info[2].resolved = "[B]uminus";
  c19_info[2].fileLength = 0U;
  c19_info[2].fileTime1 = 0U;
  c19_info[2].fileTime2 = 0U;
  c19_info[3].context = "";
  c19_info[3].name = "plus";
  c19_info[3].dominantType = "double";
  c19_info[3].resolved = "[B]plus";
  c19_info[3].fileLength = 0U;
  c19_info[3].fileTime1 = 0U;
  c19_info[3].fileTime2 = 0U;
  c19_info[4].context = "";
  c19_info[4].name = "cos";
  c19_info[4].dominantType = "double";
  c19_info[4].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c19_info[4].fileLength = 324U;
  c19_info[4].fileTime1 = 1203444350U;
  c19_info[4].fileTime2 = 0U;
  c19_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c19_info[5].name = "nargin";
  c19_info[5].dominantType = "";
  c19_info[5].resolved = "[B]nargin";
  c19_info[5].fileLength = 0U;
  c19_info[5].fileTime1 = 0U;
  c19_info[5].fileTime2 = 0U;
  c19_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c19_info[6].name = "gt";
  c19_info[6].dominantType = "double";
  c19_info[6].resolved = "[B]gt";
  c19_info[6].fileLength = 0U;
  c19_info[6].fileTime1 = 0U;
  c19_info[6].fileTime2 = 0U;
  c19_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c19_info[7].name = "isa";
  c19_info[7].dominantType = "double";
  c19_info[7].resolved = "[B]isa";
  c19_info[7].fileLength = 0U;
  c19_info[7].fileTime1 = 0U;
  c19_info[7].fileTime2 = 0U;
  c19_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c19_info[8].name = "eml_scalar_cos";
  c19_info[8].dominantType = "double";
  c19_info[8].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c19_info[8].fileLength = 602U;
  c19_info[8].fileTime1 = 1209327186U;
  c19_info[8].fileTime2 = 0U;
  c19_info[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c19_info[9].name = "isreal";
  c19_info[9].dominantType = "double";
  c19_info[9].resolved = "[B]isreal";
  c19_info[9].fileLength = 0U;
  c19_info[9].fileTime1 = 0U;
  c19_info[9].fileTime2 = 0U;
  c19_info[10].context = "";
  c19_info[10].name = "times";
  c19_info[10].dominantType = "double";
  c19_info[10].resolved = "[B]times";
  c19_info[10].fileLength = 0U;
  c19_info[10].fileTime1 = 0U;
  c19_info[10].fileTime2 = 0U;
  c19_info[11].context = "";
  c19_info[11].name = "sin";
  c19_info[11].dominantType = "double";
  c19_info[11].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c19_info[11].fileLength = 324U;
  c19_info[11].fileTime1 = 1203444442U;
  c19_info[11].fileTime2 = 0U;
  c19_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c19_info[12].name = "eml_scalar_sin";
  c19_info[12].dominantType = "double";
  c19_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c19_info[12].fileLength = 601U;
  c19_info[12].fileTime1 = 1209327190U;
  c19_info[12].fileTime2 = 0U;
  c19_info[13].context = "";
  c19_info[13].name = "power";
  c19_info[13].dominantType = "double";
  c19_info[13].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[13].fileLength = 5380U;
  c19_info[13].fileTime1 = 1228090298U;
  c19_info[13].fileTime2 = 0U;
  c19_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[14].name = "isinteger";
  c19_info[14].dominantType = "double";
  c19_info[14].resolved = "[B]isinteger";
  c19_info[14].fileLength = 0U;
  c19_info[14].fileTime1 = 0U;
  c19_info[14].fileTime2 = 0U;
  c19_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[15].name = "eml_scalar_eg";
  c19_info[15].dominantType = "double";
  c19_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c19_info[15].fileLength = 3068U;
  c19_info[15].fileTime1 = 1240258410U;
  c19_info[15].fileTime2 = 0U;
  c19_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c19_info[16].name = "false";
  c19_info[16].dominantType = "";
  c19_info[16].resolved = "[B]false";
  c19_info[16].fileLength = 0U;
  c19_info[16].fileTime1 = 0U;
  c19_info[16].fileTime2 = 0U;
  c19_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c19_info[17].name = "isstruct";
  c19_info[17].dominantType = "double";
  c19_info[17].resolved = "[B]isstruct";
  c19_info[17].fileLength = 0U;
  c19_info[17].fileTime1 = 0U;
  c19_info[17].fileTime2 = 0U;
  c19_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c19_info[18].name = "eq";
  c19_info[18].dominantType = "double";
  c19_info[18].resolved = "[B]eq";
  c19_info[18].fileLength = 0U;
  c19_info[18].fileTime1 = 0U;
  c19_info[18].fileTime2 = 0U;
  c19_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c19_info[19].name = "class";
  c19_info[19].dominantType = "double";
  c19_info[19].resolved = "[B]class";
  c19_info[19].fileLength = 0U;
  c19_info[19].fileTime1 = 0U;
  c19_info[19].fileTime2 = 0U;
  c19_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c19_info[20].name = "cast";
  c19_info[20].dominantType = "double";
  c19_info[20].resolved = "[B]cast";
  c19_info[20].fileLength = 0U;
  c19_info[20].fileTime1 = 0U;
  c19_info[20].fileTime2 = 0U;
  c19_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[21].name = "eml_scalexp_alloc";
  c19_info[21].dominantType = "double";
  c19_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c19_info[21].fileLength = 808U;
  c19_info[21].fileTime1 = 1230491098U;
  c19_info[21].fileTime2 = 0U;
  c19_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c19_info[22].name = "minus";
  c19_info[22].dominantType = "double";
  c19_info[22].resolved = "[B]minus";
  c19_info[22].fileLength = 0U;
  c19_info[22].fileTime1 = 0U;
  c19_info[22].fileTime2 = 0U;
  c19_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c19_info[23].name = "isscalar";
  c19_info[23].dominantType = "double";
  c19_info[23].resolved = "[B]isscalar";
  c19_info[23].fileLength = 0U;
  c19_info[23].fileTime1 = 0U;
  c19_info[23].fileTime2 = 0U;
  c19_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c19_info[24].name = "not";
  c19_info[24].dominantType = "logical";
  c19_info[24].resolved = "[B]not";
  c19_info[24].fileLength = 0U;
  c19_info[24].fileTime1 = 0U;
  c19_info[24].fileTime2 = 0U;
  c19_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[25].name = "lt";
  c19_info[25].dominantType = "double";
  c19_info[25].resolved = "[B]lt";
  c19_info[25].fileLength = 0U;
  c19_info[25].fileTime1 = 0U;
  c19_info[25].fileTime2 = 0U;
  c19_info[26].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[26].name = "eml_scalar_floor";
  c19_info[26].dominantType = "double";
  c19_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c19_info[26].fileLength = 260U;
  c19_info[26].fileTime1 = 1209327190U;
  c19_info[26].fileTime2 = 0U;
  c19_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[27].name = "ne";
  c19_info[27].dominantType = "double";
  c19_info[27].resolved = "[B]ne";
  c19_info[27].fileLength = 0U;
  c19_info[27].fileTime1 = 0U;
  c19_info[27].fileTime2 = 0U;
  c19_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[28].name = "eml_error";
  c19_info[28].dominantType = "char";
  c19_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c19_info[28].fileLength = 315U;
  c19_info[28].fileTime1 = 1213923144U;
  c19_info[28].fileTime2 = 0U;
  c19_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c19_info[29].name = "strcmp";
  c19_info[29].dominantType = "char";
  c19_info[29].resolved = "[B]strcmp";
  c19_info[29].fileLength = 0U;
  c19_info[29].fileTime1 = 0U;
  c19_info[29].fileTime2 = 0U;
  c19_info[30].context = "";
  c19_info[30].name = "mtimes";
  c19_info[30].dominantType = "double";
  c19_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c19_info[30].fileLength = 3425U;
  c19_info[30].fileTime1 = 1250669166U;
  c19_info[30].fileTime2 = 0U;
  c19_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c19_info[31].name = "ndims";
  c19_info[31].dominantType = "double";
  c19_info[31].resolved = "[B]ndims";
  c19_info[31].fileLength = 0U;
  c19_info[31].fileTime1 = 0U;
  c19_info[31].fileTime2 = 0U;
  c19_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c19_info[32].name = "le";
  c19_info[32].dominantType = "double";
  c19_info[32].resolved = "[B]le";
  c19_info[32].fileLength = 0U;
  c19_info[32].fileTime1 = 0U;
  c19_info[32].fileTime2 = 0U;
  c19_info[33].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c19_info[33].name = "size";
  c19_info[33].dominantType = "double";
  c19_info[33].resolved = "[B]size";
  c19_info[33].fileLength = 0U;
  c19_info[33].fileTime1 = 0U;
  c19_info[33].fileTime2 = 0U;
  c19_info[34].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c19_info[34].name = "eml_index_class";
  c19_info[34].dominantType = "";
  c19_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c19_info[34].fileLength = 909U;
  c19_info[34].fileTime1 = 1192463182U;
  c19_info[34].fileTime2 = 0U;
  c19_info[35].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c19_info[35].name = "ones";
  c19_info[35].dominantType = "char";
  c19_info[35].resolved = "[B]ones";
  c19_info[35].fileLength = 0U;
  c19_info[35].fileTime1 = 0U;
  c19_info[35].fileTime2 = 0U;
  c19_info[36].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c19_info[36].name = "isempty";
  c19_info[36].dominantType = "double";
  c19_info[36].resolved = "[B]isempty";
  c19_info[36].fileLength = 0U;
  c19_info[36].fileTime1 = 0U;
  c19_info[36].fileTime2 = 0U;
  c19_info[37].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c19_info[37].name = "eml_xgemm";
  c19_info[37].dominantType = "int32";
  c19_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c19_info[37].fileLength = 3184U;
  c19_info[37].fileTime1 = 1209327252U;
  c19_info[37].fileTime2 = 0U;
  c19_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c19_info[38].name = "length";
  c19_info[38].dominantType = "double";
  c19_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c19_info[38].fileLength = 326U;
  c19_info[38].fileTime1 = 1226573674U;
  c19_info[38].fileTime2 = 0U;
  c19_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c19_info[39].name = "min";
  c19_info[39].dominantType = "double";
  c19_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c19_info[39].fileLength = 362U;
  c19_info[39].fileTime1 = 1244731952U;
  c19_info[39].fileTime2 = 0U;
  c19_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c19_info[40].name = "nargout";
  c19_info[40].dominantType = "";
  c19_info[40].resolved = "[B]nargout";
  c19_info[40].fileLength = 0U;
  c19_info[40].fileTime1 = 0U;
  c19_info[40].fileTime2 = 0U;
  c19_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c19_info[41].name = "eml_min_or_max";
  c19_info[41].dominantType = "char";
  c19_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c19_info[41].fileLength = 9969U;
  c19_info[41].fileTime1 = 1240258406U;
  c19_info[41].fileTime2 = 0U;
  c19_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c19_info[42].name = "ischar";
  c19_info[42].dominantType = "char";
  c19_info[42].resolved = "[B]ischar";
  c19_info[42].fileLength = 0U;
  c19_info[42].fileTime1 = 0U;
  c19_info[42].fileTime2 = 0U;
  c19_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c19_info[43].name = "isnumeric";
  c19_info[43].dominantType = "double";
  c19_info[43].resolved = "[B]isnumeric";
  c19_info[43].fileLength = 0U;
  c19_info[43].fileTime1 = 0U;
  c19_info[43].fileTime2 = 0U;
  c19_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c19_info[44].name = "islogical";
  c19_info[44].dominantType = "double";
  c19_info[44].resolved = "[B]islogical";
  c19_info[44].fileLength = 0U;
  c19_info[44].fileTime1 = 0U;
  c19_info[44].fileTime2 = 0U;
  c19_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c19_info[45].name = "eml_refblas_xgemm";
  c19_info[45].dominantType = "int32";
  c19_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c19_info[45].fileLength = 5748U;
  c19_info[45].fileTime1 = 1228090272U;
  c19_info[45].fileTime2 = 0U;
  c19_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c19_info[46].name = "eml_index_minus";
  c19_info[46].dominantType = "int32";
  c19_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c19_info[46].fileLength = 277U;
  c19_info[46].fileTime1 = 1192463184U;
  c19_info[46].fileTime2 = 0U;
  c19_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c19_info[47].name = "eml_index_times";
  c19_info[47].dominantType = "int32";
  c19_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c19_info[47].fileLength = 280U;
  c19_info[47].fileTime1 = 1192463186U;
  c19_info[47].fileTime2 = 0U;
  c19_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c19_info[48].name = "eml_index_plus";
  c19_info[48].dominantType = "int32";
  c19_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c19_info[48].fileLength = 272U;
  c19_info[48].fileTime1 = 1192463184U;
  c19_info[48].fileTime2 = 0U;
  c19_info[49].context = "";
  c19_info[49].name = "eye";
  c19_info[49].dominantType = "double";
  c19_info[49].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c19_info[49].fileLength = 1765U;
  c19_info[49].fileTime1 = 1219749288U;
  c19_info[49].fileTime2 = 0U;
  c19_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c19_info[50].name = "eml_assert_valid_size_arg";
  c19_info[50].dominantType = "double";
  c19_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c19_info[50].fileLength = 3315U;
  c19_info[50].fileTime1 = 1256041632U;
  c19_info[50].fileTime2 = 0U;
  c19_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c19_info[51].name = "isinf";
  c19_info[51].dominantType = "double";
  c19_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c19_info[51].fileLength = 506U;
  c19_info[51].fileTime1 = 1228090208U;
  c19_info[51].fileTime2 = 0U;
  c19_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c19_info[52].name = "true";
  c19_info[52].dominantType = "";
  c19_info[52].resolved = "[B]true";
  c19_info[52].fileLength = 0U;
  c19_info[52].fileTime1 = 0U;
  c19_info[52].fileTime2 = 0U;
  c19_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c19_info[53].name = "double";
  c19_info[53].dominantType = "double";
  c19_info[53].resolved = "[B]double";
  c19_info[53].fileLength = 0U;
  c19_info[53].fileTime1 = 0U;
  c19_info[53].fileTime2 = 0U;
  c19_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c19_info[54].name = "intmax";
  c19_info[54].dominantType = "char";
  c19_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c19_info[54].fileLength = 1535U;
  c19_info[54].fileTime1 = 1192463128U;
  c19_info[54].fileTime2 = 0U;
  c19_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c19_info[55].name = "int32";
  c19_info[55].dominantType = "double";
  c19_info[55].resolved = "[B]int32";
  c19_info[55].fileLength = 0U;
  c19_info[55].fileTime1 = 0U;
  c19_info[55].fileTime2 = 0U;
  c19_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c19_info[56].name = "eml_is_float_class";
  c19_info[56].dominantType = "char";
  c19_info[56].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c19_info[56].fileLength = 226U;
  c19_info[56].fileTime1 = 1197846840U;
  c19_info[56].fileTime2 = 0U;
  c19_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c19_info[57].name = "real";
  c19_info[57].dominantType = "double";
  c19_info[57].resolved = "[B]real";
  c19_info[57].fileLength = 0U;
  c19_info[57].fileTime1 = 0U;
  c19_info[57].fileTime2 = 0U;
}

static void c19_emlrt_marshallIn(SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c19_tau_N, const
  char_T *c19_name, real_T c19_y[16])
{
  real_T c19_dv2[16];
  int32_T c19_i4;
  sf_mex_import(c19_name, sf_mex_dup(c19_tau_N), &c19_dv2, 1, 0, 0U, 1, 0U, 1,
                16);
  for (c19_i4 = 0; c19_i4 < 16; c19_i4 = c19_i4 + 1) {
    c19_y[c19_i4] = c19_dv2[c19_i4];
  }

  sf_mex_destroy(&c19_tau_N);
}

static uint8_T c19_b_emlrt_marshallIn
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c19_b_is_active_c19_ODE_Hand_Model_v08_IPC_v03, const char_T *c19_name)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  sf_mex_import(c19_name, sf_mex_dup
                (c19_b_is_active_c19_ODE_Hand_Model_v08_IPC_v03), &c19_u0, 1, 3,
                0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_b_is_active_c19_ODE_Hand_Model_v08_IPC_v03);
  return c19_y;
}

static void c19_refp12_ceval_xgemm
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, int32_T c19_m,
   int32_T c19_n,
   int32_T c19_k, real_T c19_alpha1, real_T c19_A[384], int32_T c19_ia0, int32_T
   c19_lda, real_T c19_B[384], int32_T c19_ib0, int32_T
   c19_ldb, real_T c19_beta1, real_T c19_C[256], int32_T c19_ic0, int32_T
   c19_ldc)
{
  char_T c19_TRANSA;
  char_T c19_TRANSB;
  c19_TRANSA = 'N';
  c19_TRANSB = 'N';
  dgemm32(&c19_TRANSA, &c19_TRANSB, &c19_m, &c19_n, &c19_k, &c19_alpha1,
          &c19_A[sf_mex_lw_bounds_check(c19_ia0, 1, 384) - 1], &c19_lda
          , &c19_B[sf_mex_lw_bounds_check(c19_ib0, 1, 384) - 1], &c19_ldb,
          &c19_beta1, &c19_C[sf_mex_lw_bounds_check(c19_ic0, 1, 256) - 1], &
          c19_ldc);
}

static void c19_b_refp12_ceval_xgemm
  (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, int32_T c19_m,
   int32_T c19_n,
   int32_T c19_k, real_T c19_alpha1, real_T c19_A[256], int32_T c19_ia0, int32_T
   c19_lda, real_T c19_B[16], int32_T c19_ib0, int32_T
   c19_ldb, real_T c19_beta1, real_T c19_C[16], int32_T c19_ic0, int32_T c19_ldc)
{
  char_T c19_TRANSA;
  char_T c19_TRANSB;
  c19_TRANSA = 'N';
  c19_TRANSB = 'N';
  dgemm32(&c19_TRANSA, &c19_TRANSB, &c19_m, &c19_n, &c19_k, &c19_alpha1,
          &c19_A[sf_mex_lw_bounds_check(c19_ia0, 1, 256) - 1], &c19_lda
          , &c19_B[sf_mex_lw_bounds_check(c19_ib0, 1, 16) - 1], &c19_ldb,
          &c19_beta1, &c19_C[sf_mex_lw_bounds_check(c19_ic0, 1, 16) - 1], &
          c19_ldc);
}

static void init_dsm_address_info(SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c19_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(204639078U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3034735114U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2480707437U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(816138356U);
}

mxArray *sf_c19_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(305719543U);
    pr[1] = (double)(1294787692U);
    pr[2] = (double)(643239876U);
    pr[3] = (double)(4174770233U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(16);
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
      pr[0] = (double)(16);
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

static mxArray *sf_get_sim_state_info_c19_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"tau_N\",},{M[8],M[0],T\"is_active_c19_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c19_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c19_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c19_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c19_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c19_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03
    ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c19_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c19_ODE_Hand_Model_v08_IPC_v03
      ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c19_ODE_Hand_Model_v08_IPC_v03
      ((SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",19,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",19,2);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",19,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(119843984U));
  ssSetChecksum1(S,(813056115U));
  ssSetChecksum2(S,(2261218608U));
  ssSetChecksum3(S,(2711971136U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",19);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc
    (sizeof(SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc19_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c19_ODE_Hand_Model_v08_IPC_v03;
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

void c19_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
