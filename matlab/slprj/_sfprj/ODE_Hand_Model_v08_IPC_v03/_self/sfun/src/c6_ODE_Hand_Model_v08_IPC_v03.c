/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c6_ODE_Hand_Model_v08_IPC_v03.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray
   *c6_st);
static void finalize_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void c6_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static real_T c6_power(SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c6_a, real_T c6_b);
static void c6_eml_error(SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[28]);
static void c6_emlrt_marshallIn(SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, const mxArray *c6_J, const char_T *c6_name, real_T c6_y[36]);
static uint8_T c6_b_emlrt_marshallIn
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray
   *c6_b_is_active_c6_ODE_Hand_Model_v08_IPC_v03, const char_T *c6_name);
static void init_dsm_address_info(SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_u[36];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T (*c6_J)[36];
  c6_J = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2));
  for (c6_i0 = 0; c6_i0 < 36; c6_i0 = c6_i0 + 1) {
    c6_u[c6_i0] = (*c6_J)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 1U, 0U, 2, 3, 12));
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_u = chartInstance->c6_is_active_c6_ODE_Hand_Model_v08_IPC_v03;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y);
  return c6_st;
}

static void set_sim_state_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray
   *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[36];
  int32_T c6_i1;
  real_T (*c6_J)[36];
  c6_J = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)), "J",
                      c6_dv0);
  for (c6_i1 = 0; c6_i1 < 36; c6_i1 = c6_i1 + 1) {
    (*c6_J)[c6_i1] = c6_dv0[c6_i1];
  }

  chartInstance->c6_is_active_c6_ODE_Hand_Model_v08_IPC_v03 =
    c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1))
    , "is_active_c6_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c6_u);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c6_previousEvent;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c6_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c6_c6_ODE_Hand_Model_v08_IPC_v03(chartInstance);
  _sfEvent_ = c6_previousEvent;
}

static void c6_c6_ODE_Hand_Model_v08_IPC_v03
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  real_T c6_x1x;
  real_T c6_x1y;
  real_T c6_x1z;
  real_T c6_x2x;
  real_T c6_x2y;
  real_T c6_x2z;
  real_T c6_x3x;
  real_T c6_x3y;
  real_T c6_x3z;
  real_T c6_x4x;
  real_T c6_x4y;
  real_T c6_x4z;
  real_T c6_a;
  real_T c6_b_a;
  real_T c6_c_a;
  real_T c6_d_a;
  real_T c6_e_a;
  real_T c6_f_a;
  real_T c6_g_a;
  real_T c6_h_a;
  real_T c6_i_a;
  real_T c6_d0;
  real_T c6_d1;
  real_T c6_d2;
  real_T c6_d3;
  real_T c6_d4;
  real_T c6_d5;
  real_T c6_d6;
  real_T c6_d7;
  real_T c6_d8;
  real_T c6_d9;
  real_T c6_d10;
  real_T c6_d11;
  real_T c6_d12;
  real_T c6_d13;
  real_T c6_d14;
  real_T c6_b_x1x;
  real_T c6_c_x1x;
  real_T c6_d15;
  real_T c6_d16;
  real_T c6_d17;
  real_T c6_d18;
  real_T c6_d_x1x;
  real_T c6_d19;
  real_T c6_d20;
  real_T c6_d21;
  real_T c6_d22;
  real_T c6_d23;
  real_T c6_d24;
  real_T c6_d25;
  real_T c6_d26;
  real_T c6_b_x1z;
  real_T c6_J[36];
  int32_T c6_i2;
  real_T (*c6_b_J)[36];
  real_T (*c6_xi)[12];
  c6_b_J = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_xi = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  c6_x1x = (*c6_xi)[0];
  c6_x1y = (*c6_xi)[4];
  c6_x1z = (*c6_xi)[8];
  c6_x2x = (*c6_xi)[1];
  c6_x2y = (*c6_xi)[5];
  c6_x2z = (*c6_xi)[9];
  c6_x3x = (*c6_xi)[2];
  c6_x3y = (*c6_xi)[6];
  c6_x3z = (*c6_xi)[10];
  c6_x4x = (*c6_xi)[3];
  c6_x4y = (*c6_xi)[7];
  c6_x4z = (*c6_xi)[11];
  c6_a = (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
          (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    muDoubleScalarPower(c6_x2z + -1.0 * c6_x4z, 2.0);
  if (c6_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_a = (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * muDoubleScalarPower(c6_a, -0.5);
  c6_b_a = (muDoubleScalarPower(c6_x1x + -1.0 * c6_x3x, 2.0) +
            muDoubleScalarPower(c6_x1y + -1.0 * c6_x3y, 2.0)) +
    muDoubleScalarPower
    (c6_x1z + -1.0 * c6_x3z, 2.0);
  if (c6_b_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_c_a = (muDoubleScalarPower(c6_x2x + -1.0 * c6_x4x, 2.0) +
            muDoubleScalarPower(c6_x2y + -1.0 * c6_x4y, 2.0)) +
    muDoubleScalarPower
    (c6_x2z + -1.0 * c6_x4z, 2.0);
  if (c6_c_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_d_a = (muDoubleScalarPower(c6_x1x + -1.0 * c6_x3x, 2.0) +
            muDoubleScalarPower(c6_x1y + -1.0 * c6_x3y, 2.0)) +
    muDoubleScalarPower
    (c6_x1z + -1.0 * c6_x3z, 2.0);
  if (c6_d_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_e_a = (muDoubleScalarPower(c6_x2x + -1.0 * c6_x4x, 2.0) +
            muDoubleScalarPower(c6_x2y + -1.0 * c6_x4y, 2.0)) +
    muDoubleScalarPower
    (c6_x2z + -1.0 * c6_x4z, 2.0);
  if (c6_e_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_f_a = (muDoubleScalarPower(c6_a, 2.0) + muDoubleScalarPower((c6_x1y + -1.0 *
              c6_x3y) * muDoubleScalarPower(c6_b_a, -0.5) + (
              c6_x2y + -1.0 * c6_x4y) * muDoubleScalarPower(c6_c_a, -0.5), 2.0))
    + muDoubleScalarPower(muDoubleScalarPower(c6_d_a, -0.5) * (c6_x1z
    + -1.0 * c6_x3z) + muDoubleScalarPower(c6_e_a, -0.5) * (c6_x2z + -1.0 *
    c6_x4z), 2.0);
  if (c6_f_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_g_a = (muDoubleScalarPower(c6_x2x + -1.0 * c6_x4x, 2.0) +
            muDoubleScalarPower(c6_x2y + -1.0 * c6_x4y, 2.0)) +
    muDoubleScalarPower
    (c6_x2z + -1.0 * c6_x4z, 2.0);
  if (c6_g_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_h_a = (muDoubleScalarPower((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
              c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
              c6_x4y), 2.0) + muDoubleScalarPower((c6_x1z + -1.0 * c6_x3z) *
             (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
             (c6_x2z
              + -1.0 * c6_x4z), 2.0)) + muDoubleScalarPower((-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0);
  if (c6_h_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_a = (muDoubleScalarPower(c6_x1x + -1.0 * c6_x3x, 2.0) + muDoubleScalarPower
          (c6_x1y + -1.0 * c6_x3y, 2.0)) + muDoubleScalarPower(
    c6_x1z + -1.0 * c6_x3z, 2.0);
  if (c6_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_b_a = (muDoubleScalarPower(c6_x2x + -1.0 * c6_x4x, 2.0) +
            muDoubleScalarPower(c6_x2y + -1.0 * c6_x4y, 2.0)) +
    muDoubleScalarPower
    (c6_x2z + -1.0 * c6_x4z, 2.0);
  if (c6_b_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_c_a = (muDoubleScalarPower(c6_x1x + -1.0 * c6_x3x, 2.0) +
            muDoubleScalarPower(c6_x1y + -1.0 * c6_x3y, 2.0)) +
    muDoubleScalarPower
    (c6_x1z + -1.0 * c6_x3z, 2.0);
  if (c6_c_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_d_a = (muDoubleScalarPower(c6_x2x + -1.0 * c6_x4x, 2.0) +
            muDoubleScalarPower(c6_x2y + -1.0 * c6_x4y, 2.0)) +
    muDoubleScalarPower
    (c6_x2z + -1.0 * c6_x4z, 2.0);
  if (c6_d_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_e_a = (muDoubleScalarPower(c6_x1x + -1.0 * c6_x3x, 2.0) +
            muDoubleScalarPower(c6_x1y + -1.0 * c6_x3y, 2.0)) +
    muDoubleScalarPower
    (c6_x1z + -1.0 * c6_x3z, 2.0);
  if (c6_e_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_i_a = (muDoubleScalarPower(c6_x2x + -1.0 * c6_x4x, 2.0) +
            muDoubleScalarPower(c6_x2y + -1.0 * c6_x4y, 2.0)) +
    muDoubleScalarPower
    (c6_x2z + -1.0 * c6_x4z, 2.0);
  if (c6_i_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_a = (muDoubleScalarPower((c6_x1x + -1.0 * c6_x3x) * muDoubleScalarPower
           (c6_a, -0.5) + (c6_x2x + -1.0 * c6_x4x) *
           muDoubleScalarPower(c6_b_a, -0.5), 2.0) + muDoubleScalarPower((c6_x1y
            + -1.0 * c6_x3y) * muDoubleScalarPower(c6_c_a, -0.5) + (c6_x2y
            + -1.0 * c6_x4y) * muDoubleScalarPower(c6_d_a, -0.5), 2.0)) +
    muDoubleScalarPower(muDoubleScalarPower(c6_e_a, -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + muDoubleScalarPower(c6_i_a, -0.5) * (c6_x2z + -1.0 * c6_x4z),
                        2.0);
  if (c6_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_b_a = (muDoubleScalarPower(c6_x2x + -1.0 * c6_x4x, 2.0) +
            muDoubleScalarPower(c6_x2y + -1.0 * c6_x4y, 2.0)) +
    muDoubleScalarPower
    (c6_x2z + -1.0 * c6_x4z, 2.0);
  if (c6_b_a < 0.0) {
    c6_eml_error(chartInstance);
  }

  c6_c_a = (((((((c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 * c6_x3y) * c6_power
                 (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                  c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5
                  ) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                       (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) *
                 c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) + 0.5 * ((-1.0 * c6_x1y + c6_x3y
    ) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y)) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (-1.0 * c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) + c6_power(chartInstance,
                     (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                      + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) * ((c6_x1x
    + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + -2.0 *
    (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 * c6_x3y) * c6_power
                   (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) *
                   ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
                      (
                       chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
                    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
                     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) +
    -2.0
    * (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * (c6_power
                   (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
                   (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
                 (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                     + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + -1.0 *
                (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power
               (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5
                ) * (c6_x1z + -1.0 * c6_x3z) * c6_power(chartInstance, (c6_power
                 (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x)
                  + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 *
              c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (-1.0 *
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) + c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5))
    * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + -2.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 *
    c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + -2.0
    * (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * (c6_power
                (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                 c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
    (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
              (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                 (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                  + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + c6_power
             (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
                (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
    chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
              ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
               (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                 (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                  c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                (
                 c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * (c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
               c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
              * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (-1.0 *
              c6_x2z + c6_x4z)) + 0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
              -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
              c6_x4y)
             ) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (
    c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power
            (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
               * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
               (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((
              c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
              chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
              c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) *
            (2.0 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                    (c6_x1x
                     + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (c6_x2y +
              -1.0 * c6_x4y) + 2.0 * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x
    ) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (-1.0 *
              c6_x2z + c6_x4z))) + -0.5 * c6_power(chartInstance, (
    c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
             + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
             2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
    -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
                (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
                 (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z)) * (2.0 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y)) * (c6_x2y + -1.0 * c6_x4y) + 2.0 * ((c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z)) * (-1.0 * c6_x2z + c6_x4z));
  c6_d_a = (((((-1.0 * (-1.0 * c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
    2.0) * c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5)) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0
    * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power
                (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z
    + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
    chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                 ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                  (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                   (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                   (
                    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(
             chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) + 0.5 * ((-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power(chartInstance,
    (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0)
     + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z
    + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((-2.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 * (-1.0 * c6_power
                   (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) + c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5))
    * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5))) + -2.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power
    (chartInstance, (
                     c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(
              chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z +
    -1.0 * c6_x3z) * (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) +
    c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0)) + c6_power(chartInstance, c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) *
                ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
                 * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5))) + -1.0 * (-1.0 * c6_x2x + c6_x4x) * c6_power
               (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5))) + -1.0 * (c6_x1y + -1.0 * c6_x3y) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z +
    -1.0 * c6_x3z) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z))) + 0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) *
             c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (
    c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
    chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
                      ) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
               (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                 (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                  c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                (
                 c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * (2.0
              * (-1.0 * c6_x2x + c6_x4x) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y)) + 2.0 * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) +
                      (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * (
    c6_x2z + -1.0 * c6_x4z))) + -0.5 * c6_power(chartInstance, (c6_power
              (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
              c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
    -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z),
                       2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z
    ) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z), 2.0), -0.5) * ((-2.0 * (c6_x1x + -1.0 * c6_x3x)
              * (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
               (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
    (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 * (-1.0 * c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) + c6_power(chartInstance,
                (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                 + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) * ((c6_x1y
    + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + -2.0 *
             (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * (c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
               (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (
    c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power(
             chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
             c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
             c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
                      (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
                       (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) *
                      (c6_x2z
                       + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1z + -1.0 * c6_x3z)
             * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
             (c6_x2z +
              -1.0 * c6_x4z)) * (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y +
    -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
              -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
              chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
              c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) *
             (c6_x2z + -1.0 * c6_x4z))) + -0.5 * c6_power(chartInstance,
    (c6_power(
              chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
              + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
     c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
              + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) * (2.0 * (-1.0 * c6_x2x + c6_x4x) * ((-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2y + -1.0 * c6_x4y)) + 2.0 * ((-1.0 * c6_x1z + c6_x3z)
    * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z)) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z));
  c6_e_a = ((((((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z
    ) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) + 0.5 * ((-1.0 * c6_x1y + c6_x3y
    ) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y)) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((-2.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
    * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x
    + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) + -2.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0
    * c6_x3z) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0 * (c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + -1.0 * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
                (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 0.5 * ((-1.0
    * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (2.0 * (c6_x2x + -1.0 *
    c6_x4x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) + 2.0 *
                (-1.0 * c6_x2y + c6_x4y) * ((-1.0 * c6_x1z + c6_x3z)
    * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + (c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + -1.0 * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0)) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z))) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
              chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) *
                (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
              (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
                        c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
              c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
              + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * c6_power
            (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
              * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((-2.0 * (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y +
    -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + -2.0 *
              (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0
             * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
    2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + -1.0 *
                c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0))
    + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0
               ), -1.5) * c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0)) *
             (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                       c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
                       -0.5
                       ) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z
    ))) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (
                  chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 *
    c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
               (
                c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
              + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1z +
              -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x
              + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power
             (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) +
    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
              (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
              -1.0
              * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)
             * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * (2.0 * (c6_x2x
    + -1.0 * c6_x4x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
                        -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z
    )) + 2.0 * (-1.0 * c6_x2y + c6_x4y) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y +
    -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
    (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
    (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) *
    c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
               c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
              * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
             ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
                  (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) *
    (c6_power(
              chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
        2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
     (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
        chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
        c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
       + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z));
  c6_i_a = ((((((0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                        (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (
    2.0 * (-1.0 * c6_x1y + c6_x3y) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y)) + 2.0 * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
     + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + -1.0 * (-1.0 * c6_x1y + c6_x3y) * c6_power
                 (chartInstance, (
    c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
             + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
             2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
    -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + 0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y)) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
    (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
    (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
                c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                  (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
    ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * ((2.0 * (-1.0 * c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))
    + -2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0
    * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0))
    + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -1.5)) + -2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
     (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 *
    c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) *
                  (c6_x2z + -1.0 * c6_x4z)) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)))
               + (c6_x1z + -1.0 * c6_x3z) * c6_power(chartInstance
    , (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)
                , 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * (2.0 * (-1.0 *
    c6_x1y + c6_x3y) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 *
               (c6_x1z + -1.0 * c6_x3z) * ((c6_x1z + -1.0 * c6_x3z)
    * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
                (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
                 (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z))) + -0.5 * c6_power(chartInstance, (c6_power(chartInstance,
                (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
              + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
    2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
              ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
                   (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 *
               (
                -1.0 * c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) *
                c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)
                + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0
    * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) *
    ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
                  (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
     (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
      c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))
    + -2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
    + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
    ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + -2.0 *
              (c6_x2x + -1.0 * c6_x4x) * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0
    * c6_x4z)) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0
    * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
                  * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
               (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
                (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)))
            + (c6_x2x + -1.0 * c6_x4x) * ((-1.0 * c6_x1y +
              c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
             (c6_x2y + -1.0 * c6_x4y)) * (c6_x2y + -1.0 * c6_x4y) * c6_power(
             chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) *
               (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
             (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
                       c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
             c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
              c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
              (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
              chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + -1.0 *
    (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z);
  c6_d0 = (((((-1.0 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                       (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) *
               c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power
               (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
                    2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
                 -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(
              chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
     (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
                c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (-1.0 * c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + c6_power(chartInstance
    , (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
       (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 0.5 * ((-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (2.0 * (c6_x1x + -1.0 * c6_x3x) *
    ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 * (-1.0 * c6_x1z +
    c6_x3z) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
               (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
                  (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
    chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
                ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                 (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                  (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                  (
                   c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                   c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(
             chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + -1.0
              * (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
     + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5))) + 0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x)
              + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power
             (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
              chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
             c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
              c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
                       (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
                        (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) *
                       (c6_x2z
                        + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1y + -1.0 * c6_x3y)
              * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((2.0 * (-1.0 * c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + -2.0
    * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + -2.0 *
              (c6_x2y + -1.0 * c6_x4y) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z)) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x
    + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -1.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * (2.0 * (
              c6_x1x + -1.0 * c6_x3x) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)
              ) + 2.0 * (-1.0 * c6_x1z + c6_x3z) * ((-1.0 * c6_x1z + c6_x3z) *
              (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
    (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
             (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) *
            c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
               c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
              * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                     ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
             -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) *
            (c6_power(
                      chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                      c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
             * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * c6_power
           (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z
    + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
              * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
             chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y)
             + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
            ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
             (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
               (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
              (
               c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
               (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
             + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1z +
             -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x
             + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 * (-1.0 *
              c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
               c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))
             * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + -2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 *
              c6_x4y) *
             ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
              c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5))
            + -2.0 * (c6_x2y + -1.0 * c6_x4y) * (c6_power(chartInstance,
              (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z
              ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0
    * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) *
             (c6_x2z + -1.0 * c6_x4z)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
              + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) *
           (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (
             c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
              (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
              (chartInstance,
               c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z +
              -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -1.0 * (
    c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, (
    -1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x +
          -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0
    * c6_x4z);
  c6_d1 = (((((0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                      (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (
    2.0 * (-1.0 * c6_x1x + c6_x3x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z)) + 2.0 * (c6_x1y + -1.0 * c6_x3y) * ((-1.0 * c6_x1z + c6_x3z)
    * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
     + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + 0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) +
                (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power
               (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (
       c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((2.0 * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) + -1.0 *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
    + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
    ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0)) + -2.0 * (
    c6_x2x + -1.0 * c6_x4x) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) + -2.0 * (c6_x2y +
    -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z
    ))) + (-1.0 * c6_x1x + c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x
    ) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y
                    , 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z,
    2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
                 (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 *
             (2.0 * (-1.0 * c6_x1x + c6_x3x) * ((c6_x1z + -1.0 * c6_x3z
    ) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z)) + 2.0 * (c6_x1y + -1.0 * c6_x3y) * ((-1.0
    * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) *
    (c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (
    c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
             + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
             2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
    -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
              c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
                (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
                 (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z))) + -0.5 * c6_power(chartInstance, (c6_power(chartInstance,
               (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
               (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
              c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
             + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
                        2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
               c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
              * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
             ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
                  (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 *
              (
               c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x
    , 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) + -1.0
    * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
               -1.5) * c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0)) +
              -2.0
              * (c6_x2x + -1.0 * c6_x4x) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x
    + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) + -2.0 * (c6_x2y +
              -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z
              )) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y
    , 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
                    (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
               (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + c6_power
           (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z
    + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
              * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
             chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y)
             + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
            ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
             (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
               (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
              (
               c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
               (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
             + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1z +
             -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x
             + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power
            (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
              +
              c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
             (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) + -1.0 *
            c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
              ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) *
            c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0))) + ((-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2y + -1.0 * c6_x4y)) * (c6_x2y + -1.0 * c6_x4y) *
    c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) *
               (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power
    (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x
        ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
          c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
          2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
       (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
          chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
          c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
         + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y +
        -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
          chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
          c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
         + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
       (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
          2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
        c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
     c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
         c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
         c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
        c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
       chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                       c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
       c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z +
       -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z);
  c6_d2 = ((((((-1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 * c6_x3y) *
                c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0))
    + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0
               ), -1.5) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                 (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power
                (
                 chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) + 0.5 * ((-1.0 * c6_x1y + c6_x3y
    ) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y)) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) + -1.0 * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) * ((c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0
    * (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * (c6_power
                  (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                   c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
                  (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
                (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + -1.0 * (-1.0
    * c6_x2y + c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + (c6_x1x + -1.0 * c6_x3x) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
               (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (
    c6_x1z + -1.0 * c6_x3z) * c6_power(chartInstance, (c6_power(chartInstance, (
    -1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * ((
    -1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x)
              * (c6_x2y + -1.0 * c6_x4y)) * c6_power(chartInstance,
              (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0
    * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
                        2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
                (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z +
     -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
               (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
              c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * (2.0 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y)) * (-1.0 * c6_x2y + c6_x4y) + 2.0 * ((c6_x1z + -1.0 * c6_x3z)
    * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 *
            c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (
    c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
              chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y)
              + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                     ) * ((2.0 * (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5
                    ) + -1.0 * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5))
              * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
                 * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) + 2.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)))
             + 2.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power(
              chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) *
             (c6_x1z + -1.0 * c6_x3z) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) +
              c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                       (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) +
    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                        (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
                       (c6_x2y + -1.0
                        * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
                       2.0)) + c6_power(chartInstance, c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) *
            ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
             * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power
             (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
              (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z
              + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
              -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * c6_power
           (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) *
              (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
              (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
              * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
              c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
              c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power
           (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
            c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
              chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
              c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) *
                     (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 *
             c6_x3z) * (
                        c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
            * (c6_x2z + -1.0 * c6_x4z)) * (2.0 * ((-1.0 * c6_x1y + c6_x3y) *
             (c6_x2x
              + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
              c6_x4y)) * (-1.0 * c6_x2y + c6_x4y) + 2.0 * ((c6_x1z + -1.0 *
              c6_x3z
              ) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
             (c6_x2z + -1.0 * c6_x4z)) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
             chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
              + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
             c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
            (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
              + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) +
    c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
               (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
              chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y)
              + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
             ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0
    * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                           (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                     c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                            (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * (c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (c6_x2z
    + -1.0 * c6_x4z);
  c6_d3 = (((((-1.0 * (c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0) *
                       c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0))
    + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0
               ), -1.5) + -1.0 * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y +
    -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5)) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power
               (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
                  (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
    chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                 (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                  (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                  (
                   c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                   c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(
             chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) + 0.5 * ((-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power(chartInstance,
    (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0)
     + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z
    + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 * (c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) + -1.0 *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
             c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5
             )) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5))) + 2.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power
    (chartInstance, (
                     c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(
              chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z +
    -1.0 * c6_x3z) * (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) +
    c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0)) + c6_power(chartInstance, c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) *
               ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
                * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5))) + -1.0 * (c6_x2x + -1.0 * c6_x4x) * c6_power
              (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5))) + (c6_x1y + -1.0 * c6_x3y) * c6_power(
              chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) *
             (c6_x1z + -1.0 * c6_x3z) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
              c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z))) + -0.5 * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
              c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) + 2.0 * (c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) + -1.0 * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) * ((c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0 * (
              c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
            (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
               * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
               (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
              c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
             (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
              chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
             (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * ((-1.0 *
             c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
             -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power(chartInstance,
            (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
             c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z
              + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) *
             (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (
             c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
                      (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) +
    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                       (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
                      (c6_x2x + -1.0
                       * c6_x4x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
                      2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
              + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
            (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
              (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
               c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z +
              -1.0
              * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power
            (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
              + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
             (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
             -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
             -0.5)) * (2.0 * (c6_x2x + -1.0 * c6_x4x) * ((-1.0 *
              c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 *
              c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 * ((-1.0 * c6_x1z +
              c6_x3z)
             * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
              -1.0 * c6_x4z)) * (-1.0 * c6_x2z + c6_x4z))) + -0.5 * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
                (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
                 (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z)) * (2.0 * (c6_x2x + -1.0 * c6_x4x) * ((-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 * ((-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z)) * (-1.0 * c6_x2z + c6_x4z));
  c6_d4 = (((((-1.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0
    * c6_x3z) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) + 0.5 * ((-1.0 * c6_x1y + c6_x3y
    ) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y)) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
    * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x
    + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) + 2.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0
    * c6_x3z) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0 * (-1.0 * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
               (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                  (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                   + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 0.5 * ((-1.0
    * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (2.0 * (-1.0 * c6_x2x +
    c6_x4x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) + 2.0 *
               (c6_x2y + -1.0 * c6_x4y) * ((-1.0 * c6_x1z + c6_x3z)
    * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + (-1.0 * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0)) * c6_power(chartInstance
              , (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)
    , 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
              c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z))) + (-1.0 * c6_x2x + c6_x4x) * c6_power(
             chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) *
               (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
             (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
                       c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
             c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
             + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * c6_power
           (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
              * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
              (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
              -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y +
              -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (
              c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y +
    -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 * (c6_x1y
              + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0
            * (-1.0 * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
               + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0)) *
            (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
              (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
               c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z +
              -1.0
              * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance,
              (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) +
             c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                      (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) +
    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                       (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
                      (c6_x2y + -1.0
                       * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
                      2.0)) + c6_power(chartInstance, c6_power(
              chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
             (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) *
           ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
            * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power
            (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
             (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z
             + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
             -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * (2.0 * (
    -1.0 * c6_x2x + c6_x4x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) + 2.0 * (c6_x2y + -1.0 * c6_x4y) * ((-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance,
    (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x +
          -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z));
  c6_d5 = ((((((0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                       (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (
    2.0 * (c6_x1y + -1.0 * c6_x3y) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y)) + 2.0 * (-1.0 * c6_x1z + c6_x3z) * ((c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
     + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + -1.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power
                (chartInstance, (
    c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
             + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
             2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
    -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + 0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y)) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
    (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
    (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
               c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                 (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
                        ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                 (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                  c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * ((2.0 * (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0)
    * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
               -1.5) + -1.0 * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x
    + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0))
    + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0
               ), -0.5)) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + 2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 *
    c6_x4y) * (
               (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5))
    + 2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z
    ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5) * (c6_x2z + -1.0 * c6_x4z)) * c6_power(chartInstance,
    (c6_power(
              chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
     (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z))) + (-1.0 * c6_x1z +
    c6_x3z) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * (2.0 * (c6_x1y +
    -1.0 * c6_x3y) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 *
              (-1.0 * c6_x1z + c6_x3z) * ((c6_x1z + -1.0 * c6_x3z)
    * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
              c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
                (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
                 (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z))) + -0.5 * c6_power(chartInstance, (c6_power(chartInstance,
               (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
               (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
              c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
             + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
                        2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
               c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
              * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
             ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
                  (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 *
              (
               c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) * c6_power
               (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0)
    + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
                (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + -1.0 *
               c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
    ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1x
    + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 *
              (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + 2.0 * (c6_x2x
              + -1.0 * c6_x4x) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z)) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x
    + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
              -1.5) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
              chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
             (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -1.0 * (c6_x2x +
            -1.0 * c6_x4x) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x
             + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
             c6_x4y)) * (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
             c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
                      2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
              (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
              (c6_x2z +
               -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
              c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
              c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
            (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
            c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
              chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
              c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) *
                     (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power
           (chartInstance, (
             c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
             (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
             chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, (
    -1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(
    chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
                                (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0
    )) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
                                        (chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance,
     c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
    2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
                    (c6_x2y
                     + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5), 2.0)) + c6_power(chartInstance, c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
    ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
     * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
       2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z
    + -1.0 * c6_x4z);
  c6_d6 = (((((-1.0 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                       (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) *
               c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power
               (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
                    2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
                 -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(
              chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
     (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
                c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + -1.0 * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 0.5 * ((-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (2.0 * (-1.0 * c6_x1x +
    c6_x3x) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 *
    (c6_x1z + -1.0 * c6_x3z) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)))
               * c6_power(chartInstance, (c6_power(chartInstance, (
    -1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(
    chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
                  (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0
    )) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
                    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
    2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
                    (c6_x2y
                     + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5), 2.0)) + c6_power(chartInstance, c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
               ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
                * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5))) + -1.0 * (-1.0 * c6_x1x + c6_x3x) * c6_power
              (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5))) + 0.5 * ((-1.0 * c6_x1y + c6_x3y) * (
    c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y))
             * c6_power(chartInstance, (c6_power(chartInstance, (
    -1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(
    chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
                (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0
    )) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
                  (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
    2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
                    (c6_x2y
                     + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5), 2.0)) + c6_power(chartInstance, c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) *
             ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
              * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((2.0 * (c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) + -1.0 * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 * (c6_x2x + -1.0 *
    c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance,
                (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
                 + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + 2.0 * (
    c6_x2y + -1.0 * c6_x4y) * (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * (2.0 *
             (-1.0 * c6_x1x + c6_x3x) * ((-1.0 * c6_x1y + c6_x3y) * (
    c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y))
             + 2.0 * (c6_x1z + -1.0 * c6_x3z) * ((-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
              c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
              (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                (
                 c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
               * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
             c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
              c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
             (c6_x2z + -1.0 * c6_x4z)) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
              + -1.0 * c6_x4z))) + -0.5 * c6_power(chartInstance, (c6_power
             (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
              +
              (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
             c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
            + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
              c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
              -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power(
              chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
               (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
             (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
             * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
            ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
                 (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 *
             (
              c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0)
    + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + -1.0 *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
    ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1y
    + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 *
             (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(
              chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
              c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + 2.0
            * (c6_x2y + -1.0 * c6_x4y) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
              + -1.0 * c6_x4z)) * c6_power(chartInstance, (c6_power
              (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
              (chartInstance, c6_x2y
               + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
              c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
             chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
              + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
             c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
            (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
              + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) +
    (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z);
  c6_d7 = (((((0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                      (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (
    2.0 * (c6_x1x + -1.0 * c6_x3x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z)) + 2.0 * (-1.0 * c6_x1y + c6_x3y) * ((-1.0 * c6_x1z + c6_x3z)
    * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
     + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + 0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) +
                (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power
               (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (
       c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((2.0 * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (-1.0 * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) +
    c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
    + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
    ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0)) + 2.0 * (
    c6_x2x + -1.0 * c6_x4x) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) + 2.0 * (c6_x2y +
    -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z
    ))) + (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x
    ) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y
                    , 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z,
    2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
                 (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 *
             (2.0 * (c6_x1x + -1.0 * c6_x3x) * ((c6_x1z + -1.0 * c6_x3z
    ) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z)) + 2.0 * (-1.0 * c6_x1y + c6_x3y) * ((-1.0
    * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) *
    (c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (
    c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
             + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
             2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
    -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
              c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
                (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
                 (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z))) + -0.5 * c6_power(chartInstance, (c6_power(chartInstance,
               (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
               (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
              c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
             + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
                        2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
               c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
              * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
             ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
                  (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 *
              (
               c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (-1.0 * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0
    * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5
     ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                  -1.5) * c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0))
              + 2.0 *
              (c6_x2x + -1.0 * c6_x4x) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                     + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) + 2.0 * (c6_x2y +
              -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z
              )) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y
    , 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
                    (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
               (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + c6_power
           (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z
    + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
              * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
             chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y)
             + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
            ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
             (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
               (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
              (
               c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
               (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
             + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1z +
             -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x
             + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (-1.0 * c6_power
            (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0
    ) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
             (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) + c6_power(
             chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
              + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
             c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) *
            c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0))) + -1.0 *
    ((-1.0
      * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
     (c6_x2y + -1.0 * c6_x4y)) * (c6_x2y + -1.0 * c6_x4y) *
    c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) *
               (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power
    (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x
        ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
          c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
          2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
       (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
          chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
          c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
         + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y +
        -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
          chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
          c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
         + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
       (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
          2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
        c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
     c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
         c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
         c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
        c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
       chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                       c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
       c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z +
       -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z);
  c6_d8 = ((((((-1.0 * c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) *
                c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0))
    + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0
               ), -1.5) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5))
               * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
                  + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) *
               c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -0.5) + -0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y)) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
    (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
    (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
               ((2.0 * (-1.0 * c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y +
    -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -1.5) + c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5)) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))
                 + -2.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0
    * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0
    * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
                 * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
                    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5))) + -2.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power
                (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                 (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z
    + -1.0 * c6_x3z) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
    ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5))) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power
     (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
      (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
     c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
              + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + (c6_x1x + -1.0 * c6_x3x) * c6_power
             (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
              (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (
              c6_x1z + -1.0 * c6_x3z) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
              + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
    2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
              ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * c6_power(
             chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) *
               (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (-1.0 * c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) + c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5))
              * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + -2.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 *
    c6_x3y) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + -2.0
             * (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * (c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
               c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
              (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
            (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
               * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
               (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((-1.0
              * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
              c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
             + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * ((-1.0 * c6_x1y +
             c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 *
             c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power(chartInstance,
            (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
             c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
    -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z),
                      2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z
              ) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z
              + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power(
              chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
               (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
             (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
             * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
            ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
              (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
              c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
             ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * (2.0 *
            ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
             + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (c6_x2y +
             -1.0 * c6_x4y) + 2.0 * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
              -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
              c6_x4z)) * (-1.0 * c6_x2z + c6_x4z))) + 0.5 * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))
    * (c6_power(chartInstance, (c6_power(chartInstance,
          c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
          c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
         c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
        (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
         c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
        (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
        * c6_x4z)) * (2.0 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
    + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (
    c6_x2y + -1.0 * c6_x4y) + 2.0 * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z)) * (-1.0 * c6_x2z + c6_x4z));
  c6_d9 = ((((((-1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 * c6_x3y) *
                c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0))
    + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0
               ), -1.5) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                 (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power
                (
                 chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) + -0.5 * ((-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y)) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((-2.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) + 2.0 * (-1.0 * c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) + c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) * ((c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + -2.0 * (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
                (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + (-1.0 *
    c6_x2x + c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + (c6_x1y + -1.0 * c6_x3y) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
               (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (
    c6_x1z + -1.0 * c6_x3z) * c6_power(chartInstance, (c6_power(chartInstance, (
    -1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * ((-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
              (c6_x2y + -1.0 * c6_x4y)) * c6_power(chartInstance, (
    c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
             + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
             2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
    -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
              c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * (2.0 * (-1.0 * c6_x2x + c6_x4x) * ((-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 * ((-1.0 * c6_x1z + c6_x3z)
    * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z)) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * c6_power
            (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
               (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
              chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y)
              + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
             ) * ((-2.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 * c6_x3y) *
                   c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
                   * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + 2.0 * (-1.0 * c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y
    , 2.0) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5)) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)))
                  + -2.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power(
              chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) *
                  (c6_x1z + -1.0 * c6_x3z) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) +
              c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                       (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) +
    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                        (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
                       (c6_x2y + -1.0
                        * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
                       2.0)) + c6_power(chartInstance, c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) *
            ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (
              c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power
             (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
              (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
              -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
              -0.5) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * c6_power(
            chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) *
              (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
              (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
              * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
              c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
              c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power
           (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
            c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
              chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
              c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) *
                     (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z +
             c6_x3z) * (
                        c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) *
            (c6_x2z + -1.0 * c6_x4z)) * (2.0 * (-1.0 * c6_x2x + c6_x4x) * ((-1.0
              * c6_x1y
              + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
             (c6_x2y + -1.0 * c6_x4y)) + 2.0 * ((-1.0 * c6_x1z + c6_x3z) * (
              c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
              -1.0 * c6_x4z)) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power
            (chartInstance
             , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
              chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
             -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
              c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -1.0 * c6_power
    (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
       * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
        c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
        c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
       (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
       -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
       c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z
    ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (c6_x2z + -1.0 * c6_x4z);
  c6_d10 = (((((-1.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0
    * c6_x3z) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) + -0.5 * ((-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y)) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((-2.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
    * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x
    + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) + -2.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0
    * c6_x3z) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0 * (c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + -1.0 * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
                (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + -0.5 *
               ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (2.0 * (c6_x2x + -1.0 *
    c6_x4x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0
    * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) +
    2.0 * (-1.0 * c6_x2y + c6_x4y) * ((-1.0 * c6_x1z + c6_x3z
    ) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + -1.0 * (c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + -1.0 * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0)) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)))
             + -1.0 * (-1.0 * c6_x2y + c6_x4y) * c6_power(
              chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) *
                (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
              (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
                        c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
              c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
              + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * c6_power
            (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
              * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((-2.0 * (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y +
    -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + -2.0 *
              (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0
             * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
    2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + -1.0 *
                c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0))
    + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0
               ), -1.5) * c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0)) *
             (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                       c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
                       -0.5
                       ) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z
    ))) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (
                  chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 *
    c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
               (
                c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
              + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((-1.0 *
              c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0
              * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(chartInstance,
              (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z
              ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0
    * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) *
             (c6_x2z + -1.0 * c6_x4z))) + 0.5 * (2.0 * (c6_x2x + -1.0 *
    c6_x4x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
               (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) + 2.0
    * (-1.0 * c6_x2y + c6_x4y) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
    (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) *
    c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
               c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
              * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
             ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z));
  c6_d11 = (((((((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power
                (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (-1.0 * c6_power(chartInstance
    , c6_x2x + -1.0 * c6_x4x, 2.0) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + c6_power(chartInstance
    , (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
       (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + -0.5 * ((-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0
    * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (2.0 * (-1.0 * c6_x1y + c6_x3y) * ((
    -1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 * (c6_x1z + -1.0 *
    c6_x3z) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) *
                c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (
    c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
    chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
    ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                  (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                   (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                   (
                    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(
             chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + (-1.0
    * c6_x1y + c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
                  (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
    -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
                (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y +
    -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0),
    -0.5) * c6_power(chartInstance, (c6_power(chartInstance
    , (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                 (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                     ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5))) + -0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x)
    + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power
              (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((2.0 * (-1.0 * c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + -2.0
    * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + -2.0 *
    (c6_x2x + -1.0 * c6_x4x) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z)) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x
    + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -1.5) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * (2.0 * (
    -1.0 * c6_x1y + c6_x3y) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)
    ) + 2.0 * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
    -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance,
                (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
              + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
    2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
              ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * c6_power
            (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z
    + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
              chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y)
              + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
             ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0
    * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (
                  chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 *
    c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
               (
                c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
              + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((-1.0 *
              c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0
              * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 * (-1.0 * c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))
              * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + -2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 *
    c6_x4y) *
              ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
               c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5))
             + -2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z
    ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5) * (c6_x2z + -1.0 * c6_x4z)) * c6_power(chartInstance,
              (c6_power(
                        chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
               (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z
               + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) *
            (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                      (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (
              c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + (c6_x2x
    + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
                                  (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) +
    -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
                                (chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y +
     -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0),
    -0.5) * c6_power(chartInstance, (c6_power(chartInstance
    , (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                      (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                     ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) +
                          (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) *
    c6_power(
             chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
              + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
             c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) *
    (c6_x2z + -1.0 * c6_x4z);
  c6_d12 = ((((((-0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
    (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) *
                 (2.0 * (c6_x1x + -1.0 * c6_x3x) * ((-1.0 * c6_x1y + c6_x3y) *
    (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0
    * c6_x4y)) + 2.0 * (-1.0 * c6_x1z + c6_x3z) * ((-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance,
                    (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(
              chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
              + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
     c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
              + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + -0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y
    + -1.0 * c6_x4y)) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
                   (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
    -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
                 (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y +
    -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0),
    -0.5) * c6_power(chartInstance, (c6_power(chartInstance
    , (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                  (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
                     ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * ((2.0 * (-1.0 * c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))
    + -2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0
    * c6_x4y) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0))
    + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -1.5)) + -2.0 * (c6_x2y + -1.0 * c6_x4y) * (c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
     (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 *
    c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) *
                  (c6_x2z + -1.0 * c6_x4z)) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)))
               + -1.0 * (-1.0 * c6_x1z + c6_x3z) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * (2.0 * (c6_x1x +
    -1.0 * c6_x3x) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 *
               (-1.0 * c6_x1z + c6_x3z) * ((-1.0 * c6_x1z + c6_x3z)
    * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))
              * (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) + 0.5 * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
                (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
    -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
              (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y +
    -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0),
              -0.5) * c6_power(chartInstance, (c6_power(chartInstance
    , (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
               (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
              ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 * (-1.0 *
    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
                     + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + -2.0
    * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + -2.0 *
              (c6_x2y + -1.0 * c6_x4y) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z)) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x
    + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -1.5) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -1.0 * (c6_x2x +
             -1.0 * c6_x4x) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x
              + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
              c6_x4y)) * (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
              c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
                       2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
               (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z +
     -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
              (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
              (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
             c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
              c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
              (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
              chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, (
    -1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(
    chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
                                (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0
    )) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
                                        (chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance,
     c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
    2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
                    (c6_x2y
                     + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5), 2.0)) + c6_power(chartInstance, c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
    ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (
      c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
                     + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z +
    -1.0 * c6_x4z);
  c6_d13 = (((((-0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                        (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (
    2.0 * (-1.0 * c6_x1x + c6_x3x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z)) + 2.0 * (c6_x1y + -1.0 * c6_x3y) * ((-1.0 * c6_x1z + c6_x3z)
    * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
     + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + -0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x)
    + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power
                (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((2.0 * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) + -1.0 *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
    + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
    ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0)) + -2.0 * (
    c6_x2x + -1.0 * c6_x4x) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                     + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) + -2.0 * (c6_x2y +
    -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z
    ))) + -1.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0
    * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x
    + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z),
             2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) + 0.5 * (2.0 * (-1.0 * c6_x1x + c6_x3x) * (
                (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
    (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) + 2.0 * (c6_x1y +
    -1.0 * c6_x3y) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) +
                      (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) *
              c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power
              (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
                    2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
                 -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(
              chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
     (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
               c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))
              * (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) + 0.5 * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
                (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
    -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
              (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y +
    -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0),
              -0.5) * c6_power(chartInstance, (c6_power(chartInstance
    , (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
               (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
              ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x
    , 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) + -1.0
    * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
               -1.5) * c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0)) +
    -2.0
    * (c6_x2x + -1.0 * c6_x4x) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x
    + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) + -2.0 * (c6_x2y +
    -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z
    )) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y
    , 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
          (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
                (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -1.0 *
            c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (
    c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
              chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y)
              + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                     ) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (
                  chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 *
    c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
               (
                c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
              + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((-1.0 *
              c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0
              * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(chartInstance,
              (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) + -1.0 * c6_power(
              chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
              c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) *
             c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0))) + -1.0 * (
    c6_x2x + -1.0 * c6_x4x) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)
    ) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (
    c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power
    (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
        c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
          * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
          c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
        -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
         c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
         (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
         chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                     (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                      (chartInstance
                       , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
         c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
         chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 *
        c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance,
          c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
          c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
         c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
      (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                       + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
       c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
       -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x
         + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
         -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z,
        2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
              + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
              ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) *
    (c6_x2z + -1.0 * c6_x4z);
  c6_d14 = ((((((c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) * c6_power
                 (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                  c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5
                  ) + -1.0 * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5))
                * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
                   + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) *
                c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y
    + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -0.5) + -0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y)) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
    (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
    (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
                ((2.0 * (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
    + -1.0 * c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5)) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))
                  + 2.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) *
                  ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
                   * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5))) + 2.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power
                 (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                  (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z
    + -1.0 * c6_x3z) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
    ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5))) + (-1.0 * c6_x2y + c6_x4y) * c6_power(chartInstance,
    (c6_power
     (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
      (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
     c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
              + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
               c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5
               ) * (c6_x1z + -1.0 * c6_x3z) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
     + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * ((-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
              (c6_x2y + -1.0 * c6_x4y)) * c6_power(chartInstance, (
    c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
             + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
             2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
    -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
              c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * (2.0 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y)) * (-1.0 * c6_x2y + c6_x4y) + 2.0 * ((c6_x1z + -1.0 * c6_x3z)
    * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 *
            c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (
    c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
              chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y)
              + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                     ) * ((2.0 * (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5
                    ) + -1.0 * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5))
              * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
                 * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) + 2.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)))
             + 2.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power(
              chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) *
             (c6_x1z + -1.0 * c6_x3z) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) +
              c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                       (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) +
    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                        (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
                       (c6_x2y + -1.0
                        * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
                       2.0)) + c6_power(chartInstance, c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) *
            ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (
              c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power
             (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
              (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
              -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
              -0.5) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))
    * (2.0 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0
         * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) *
       (-1.0 * c6_x2y + c6_x4y) + 2.0 * ((c6_x1z + -1.0 * c6_x3z) * (
         c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
         -1.0 * c6_x4z)) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z));
  c6_b_x1x = (((((((c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 * c6_x3y) *
                   c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0))
    + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -1.5) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) + -0.5 * ((-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y)) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) + 2.0 * (c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) + -1.0 * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) * ((c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0 * (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
                   (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                      (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                       + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + -1.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power
                 (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                  c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5
                  ) * (c6_x1z + -1.0 * c6_x3z) * c6_power(chartInstance,
    (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
              + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
     c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 *
                  (c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0) *
                   c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0
    ) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) + -1.0 *
                   c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) * ((c6_x1y
    + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0
    * (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * (c6_power
                  (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                   c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
                  (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
                (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((-1.0
    * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) *
    (c6_x2z + -1.0 * c6_x4z)) * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -1.0 * c6_power
               (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z
    ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (-1.0 * c6_x2z + c6_x4z)) +
              -0.5
              * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * (2.0 * (c6_x2x + -1.0 * c6_x4x) * ((-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 * ((-1.0 * c6_x1z + c6_x3z)
    * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z)) * (-1.0 * c6_x2z + c6_x4z))) + 0.5 * c6_power
    (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
        c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y
        + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z +
        -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
        c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
      chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) +
      (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
     ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                   (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                    (
                     c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(
             chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0
    * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z
    ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (2.0 * (c6_x2x + -1.0 *
    c6_x4x) *
    ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 * ((-1.0 * c6_x1z
    + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z)) * (-1.0 * c6_x2z + c6_x4z));
  c6_c_x1x = ((((((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z
    ) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) + -0.5 * ((-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y)) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
    * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x
    + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) + 2.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0
    * c6_x3z) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0 * (-1.0 * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
                  (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                     (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                      + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + -0.5 *
                 ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (2.0 * (-1.0 * c6_x2x
    + c6_x4x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0
    * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) +
    2.0 * (c6_x2y + -1.0 * c6_x4y) * ((-1.0 * c6_x1z + c6_x3z
    ) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + -1.0 * (-1.0 * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0)) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)))
               + -1.0 * (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * c6_power
              (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y +
    -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 * (c6_x1y
    + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0
    * (-1.0 * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
       + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0)) *
               (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) +
    c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0)) + c6_power(chartInstance, c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) *
              ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (
    c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                     + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * (2.0 * (-1.0
    * c6_x2x + c6_x4x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
    -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) + 2.0 * (c6_x2y + -1.0 * c6_x4y) * ((-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance,
    (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
          c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z));
  c6_d15 = (((((((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power
                (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + -1.0 * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + -0.5 * ((-1.0
    * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (2.0 * (c6_x1y + -1.0 *
    c6_x3y) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 * (-1.0
    * c6_x1z + c6_x3z) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + (c6_x1y + -1.0 * c6_x3y) * c6_power
               (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
                  (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
    chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                 (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                  (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                  (
                   c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                   c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(
             chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + -0.5
              * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -1.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((2.0 * (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) + -1.0 * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 * (c6_x2x + -1.0 *
    c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance,
                 (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
                  + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + 2.0 * (
    c6_x2x + -1.0 * c6_x4x) * (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * (2.0 *
              (c6_x1y + -1.0 * c6_x3y) * ((-1.0 * c6_x1y + c6_x3y) * (
    c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y))
              + 2.0 * (-1.0 * c6_x1z + c6_x3z) * ((c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (
    c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
             + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
             2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
    -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
              c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))
             * (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) + 0.5 * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
               (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
    -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
             (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y +
    -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0),
             -0.5) * c6_power(chartInstance, (c6_power(chartInstance
    , (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
               c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
              * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
             ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
              + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 * (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + -1.0 *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
    + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
    ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1x
    + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 *
              (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + 2.0 * (c6_x2x
              + -1.0 * c6_x4x) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z)) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x
    + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
              -1.5) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
              chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
             (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -1.0 * (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z);
  c6_d16 = ((((((-0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
    (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) *
                 (2.0 * (-1.0 * c6_x1x + c6_x3x) * ((-1.0 * c6_x1y + c6_x3y) *
    (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0
    * c6_x4y)) + 2.0 * (c6_x1z + -1.0 * c6_x3z) * ((-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance,
                    (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + (-1.0 * c6_x1x + c6_x3x) * c6_power(chartInstance,
    (c6_power(
              chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
              + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
     c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
              + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + -0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y
    + -1.0 * c6_x4y)) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
                   (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
    -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
                 (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y +
    -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0),
    -0.5) * c6_power(chartInstance, (c6_power(chartInstance
    , (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                  (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
                     ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * ((2.0 * (c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)
    * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
               -1.5) + -1.0 * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x
    + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0))
    + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0
               ), -0.5)) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + 2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 *
    c6_x4y) * (
               (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5))
    + 2.0 * (c6_x2y + -1.0 * c6_x4y) * (c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z
    ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5) * (c6_x2z + -1.0 * c6_x4z)) * c6_power(chartInstance,
    (c6_power(
              chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
     (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z))) + -1.0 * (c6_x1z +
    -1.0 * c6_x3z) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * (2.0 * (-1.0 *
    c6_x1x + c6_x3x) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 *
               (c6_x1z + -1.0 * c6_x3z) * ((-1.0 * c6_x1z + c6_x3z)
    * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))
              * (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) + 0.5 * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
                (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
    -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
              (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y +
    -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0),
              -0.5) * c6_power(chartInstance, (c6_power(chartInstance
    , (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
               (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
              ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 * (c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + -1.0 *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
    + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
    ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1y
    + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 *
               (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + 2.0 * (c6_x2y
    + -1.0 * c6_x4y) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
                        (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z)) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x
    + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -1.5) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + (c6_x2x + -1.0 *
             c6_x4x) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0
              * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) *
            (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
              c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
              (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                (
                 c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
               * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
             c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
              c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
              (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
              chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + -1.0 *
    (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z);
  c6_d17 = (((((-0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                        (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (
    2.0 * (c6_x1x + -1.0 * c6_x3x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z)) + 2.0 * (-1.0 * c6_x1y + c6_x3y) * ((-1.0 * c6_x1z + c6_x3z)
    * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
     + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + -0.5 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x)
    + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * c6_power
                (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((2.0 * (c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (-1.0 * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) +
    c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
    + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
    ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0)) + 2.0 * (
    c6_x2x + -1.0 * c6_x4x) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                     + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) + 2.0 * (c6_x2y +
    -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z
    ))) + -1.0 * (-1.0 * c6_x1y + c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0
    * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x
    + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z),
             2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) + 0.5 * (2.0 * (c6_x1x + -1.0 * c6_x3x) * (
                (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
    (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) + 2.0 * (-1.0 *
    c6_x1y + c6_x3y) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) +
                        (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) *
              c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power
              (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
                    2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
                 -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(
              chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
     (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
               c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))
              * (c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) + 0.5 * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
                (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
    -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
              (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y +
    -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0),
              -0.5) * c6_power(chartInstance, (c6_power(chartInstance
    , (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
               (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
              ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (-1.0 * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0
    * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5
     ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                  -1.5) * c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0))
    + 2.0 *
               (c6_x2x + -1.0 * c6_x4x) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                     + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) + 2.0 * (c6_x2y +
    -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z
    )) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y
    , 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
          (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
                (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) + -1.0 *
            c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (
    c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
              chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y)
              + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                     ) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (
                  chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 *
    c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
               (
                c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
              + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((-1.0 *
              c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0
              * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * (-1.0 * c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) +
    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) + c6_power(
              chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
              c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) *
             c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0))) + (c6_x2x +
    -1.0 * c6_x4x) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                      (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) *
    c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) *
               (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power
    (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x
        ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
          c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
          2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
       (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
          chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
          c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
         + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y +
        -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
          chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
          c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
         + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
       (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
          2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
        c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
     c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
         c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
         c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
        c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
       chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                       c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
       c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z +
       -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z);
  c6_d18 = (((((-1.0 * (-1.0 * c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) * c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) + 0.5 * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (-1.0 * c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) + c6_power(chartInstance,
                    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                     + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) * ((c6_x1x
    + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + -2.0 *
    (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 * c6_x3y) * c6_power
                  (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                   c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) *
                  ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
                   (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
                    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + -2.0
    * (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * (c6_power
                  (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                   c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
                  (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
                (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * c6_power(chartInstance,
                (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (
    c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
    2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
                    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) + -0.5 * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
    (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
    (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
              ((2.0 * (-1.0 * c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y +
    -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -1.5) + c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5)) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))
                + -2.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0
    * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0
    * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
                * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
                   * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5))) + -2.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power
               (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z
    + -1.0 * c6_x3z) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
    ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) +
               (
                c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + -1.0 *
             c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
                (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
    chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                      ) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
               (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                 (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                  c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                (
                 c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * (-1.0
              * c6_x2z + c6_x4z)) + 0.5 * c6_power(chartInstance, (c6_power
              (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
               +
               (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
              c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
             + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
                        2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
               c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
              * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
             ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
              ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0
    * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) *
            ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
             * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (2.0 *
             ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (c6_x2y + -1.0 * c6_x4y) + 2.0 *
             ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
              + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) *
             (-1.0 * c6_x2z + c6_x4z))) + -0.5 * c6_power(chartInstance, (
    c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
             + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
             2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
    -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z)) * (2.0 * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) +
                       (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (
    c6_x2y + -1.0 * c6_x4y) + 2.0 * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z)) * (-1.0 * c6_x2z + c6_x4z));
  c6_d_x1x = ((((((c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 * c6_x3y) * c6_power
                  (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                   c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5
                   ) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (
    c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power
                  (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                     (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                      + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((
    c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) + 0.5 * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((-2.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 *
                    (-1.0 * c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
                     * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
                     + c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
    2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) *
    ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
                       (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
     (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
      c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)))
    + -2.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z
    ) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y
                    , 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z,
    2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
                      (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
                  (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0
    * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0
    * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
                      (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                       c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(
             chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                     (chartInstance
                      , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
                     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                     (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                      + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + (-1.0 * c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) + c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5))
                 * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (
    c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power
                 (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                     + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((-1.0
    * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) *
    (c6_x2z + -1.0 * c6_x4z))) + -0.5 * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((-2.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 *
                  (-1.0 * c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0) *
                   c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
                   + c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
    2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) *
    ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
                     (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
     (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
      c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)))
    + -2.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z
    ) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y
                    , 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z,
    2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
                    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
                (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0
    * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0
    * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
                    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(
             chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                  (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                   (chartInstance
                    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                       c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                    c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
                   * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0
    * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * c6_power(chartInstance,
    (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0)
     + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z
    + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                 (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                  + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (2.0
    * (-1.0 * c6_x2x + c6_x4x) * ((-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y)) + 2.0 * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y +
    -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) *
    (c6_x2z + -1.0 * c6_x4z))) + -0.5 * c6_power(chartInstance,
               (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
    2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z)) * (2.0 * (-1.0 * c6_x2x + c6_x4x) * ((-1.0 * c6_x1y + c6_x3y) *
    (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2y + -1.0 * c6_x4y)) + 2.0 * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z)) * (c6_x2z + -1.0 * c6_x4z))) + c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0
    * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x
    + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z),
             2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                               (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * (c6_x2z + -1.0 * c6_x4z);
  c6_d19 = ((((((-1.0 * (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0)
     + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z
    + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) + (-1.0 * c6_x2y + c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + (c6_x1x + -1.0 * c6_x3x) * c6_power
                (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                 (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (
    c6_x1z + -1.0 * c6_x3z) * c6_power(chartInstance, (c6_power(chartInstance, (
    -1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 *
               c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((-2.0 * (c6_x1x
    + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + -2.0
    * (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1y
    + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0 *
    (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0))
              + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
              -0.5) + -1.0 * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0
    * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
     * c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0
                )) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y
    , 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
                      (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power
     (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
               (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0
    * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0
    * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(
             chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                 (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                  (chartInstance
                   , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                      c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                   c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
                  * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                  (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                   + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * (2.0 * (c6_x2x + -1.0 *
    c6_x4x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0
    * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) +
    2.0 * (-1.0 * c6_x2y + c6_x4y) * ((-1.0 * c6_x1z + c6_x3z
    ) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z))) + -1.0 * (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
              (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
               + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) *
             (c6_x1z +
              -1.0 * c6_x3z) * c6_power(chartInstance, (c6_power(chartInstance,
                (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
    (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
              (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
             c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
               (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                      ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) +
              (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 *
            c6_power(
                     chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((-2.0 * (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + -2.0
              * (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1y
    + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0 *
             (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0))
                       + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
                       -0.5) + -1.0 * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0
    * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
              * c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0
    )) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y
    , 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
          (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
                (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
            (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0
    * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0
    * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
                (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
                 (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
               * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
               (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
              c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
              chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
              c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) *
            ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y +
              -1.0
              * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * (2.0 * (c6_x2x +
    -1.0 * c6_x4x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) + 2.0 *
    (-1.0 * c6_x2y + c6_x4y) * ((-1.0 * c6_x1z + c6_x3z)
    * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z));
  c6_d20 = (((((-1.0 * (c6_x1z + -1.0 * c6_x3z) * c6_power(chartInstance,
    (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0)
     + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z
    + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                  (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                   + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) + -1.0 * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (-1.0 * c6_power(chartInstance
    , c6_x2x + -1.0 * c6_x4x, 2.0) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + c6_power(chartInstance
    , (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
       (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * (2.0 * (-1.0 * c6_x1y +
    c6_x3y) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 *
    c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 *
    (c6_x1z + -1.0 * c6_x3z) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z))) + -0.5 * (2.0 * (-1.0 * c6_x1y + c6_x3y) * ((-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 * (c6_x1z + -1.0 * c6_x3z) *
    ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
     * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
              (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) +
             0.5 * c6_power(chartInstance, (c6_power(chartInstance, (
    -1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(
    chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
                (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0
    )) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
                  (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
    2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
                    (c6_x2y
                     + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5), 2.0)) + c6_power(chartInstance, c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) *
             ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
              * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
              + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) * ((2.0 * (-1.0 * c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -1.5) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) + -2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y +
    -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + -2.0 * (c6_x2x + -1.0
    * c6_x4x) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0
    * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
                 * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
                (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
                 (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))
                * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * c6_power
            (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
              * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
             chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
             c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
             c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
                      (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
                       (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) *
                      (c6_x2z
                       + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1y + -1.0 * c6_x3y)
             * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                        (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
              c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y
              + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
              c6_x4z)) * ((2.0 * (-1.0 * c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))
              + -2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0
    * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0))
    + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -1.5)) + -2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
     (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 *
    c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) *
              (c6_x2z + -1.0 * c6_x4z)) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)))
    + -1.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0
    * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z
    + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
    (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
    c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
               c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
              * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
             ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5);
  c6_d21 = ((((((-1.0 * c6_x1z + c6_x3z) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0
    * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x
    + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z),
             2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                  (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                   + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) + 0.5 * (2.0 * (c6_x1x + -1.0 * c6_x3x) * ((-1.0
    * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2y + -1.0 * c6_x4y)) + 2.0 * (-1.0 * c6_x1z +
    c6_x3z) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y +
    -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z))) + c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
    (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
    (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
               c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                 (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                        ) * (-1.0 * c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)
    + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
               -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (
    c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * (2.0 * (c6_x1x
    + -1.0 * c6_x3x) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) +
    2.0 * (-1.0 * c6_x1z + c6_x3z) * ((-1.0 * c6_x1z + c6_x3z
    ) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) + 0.5 * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
    (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
              (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
             c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
               (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
                      ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
              -1.0
              * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 * (
    -1.0 * c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
    + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
    ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))
    * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + -2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 *
    c6_x4y) *
               ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5))
              + -2.0 * (c6_x2y + -1.0 * c6_x4y) * (c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z
    ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5) * (c6_x2z + -1.0 * c6_x4z)) * c6_power(chartInstance,
    (c6_power(
              chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
     (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * c6_power
            (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z
    + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
              chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y)
              + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
             ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0
    * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (
                  chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 *
    c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
               (
                c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
              + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1y +
              -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((-1.0
              * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
              c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 * (-1.0 * c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + -2.0
              * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + -2.0 *
             (c6_x2y + -1.0 * c6_x4y) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z)) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x
    + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
              -1.5) * (c6_x2z + -1.0 * c6_x4z))) + (c6_x2x + -1.0
    * c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0
    * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x
    + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z),
             2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
    + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5);
  c6_d22 = ((((((-1.0 * (-1.0 * c6_x1x + c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0)
     + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z
    + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) + (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + 0.5 * (2.0 * (-1.0 * c6_x1x + c6_x3x) *
    ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
     -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) + 2.0 * (c6_x1y
    + -1.0 * c6_x3y) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) *
                c6_power(chartInstance, (c6_power(chartInstance, (-1.0
    * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance
    , (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
                 (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0),
    -1.5) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                  (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                   (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                   (
                    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(
             chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((
    c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * (2.0 * (
    -1.0 * c6_x1x + c6_x3x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) + 2.0 * (c6_x1y + -1.0 * c6_x3y) * ((-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance,
                  (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) +
                (
                 c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 *
              c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
                 (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
    chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                       ) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                 (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(
                    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                  (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y
    + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                 (
                  c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                  c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(
             chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((
    c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 * (c6_power
                 (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                  c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
                 (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x
    , 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) + -1.0
    * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
               -1.5) * c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0)) +
    -2.0
    * (c6_x2x + -1.0 * c6_x4x) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x
    + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) + -2.0 * (c6_x2y +
    -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z
    ))) + -0.5 * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0
    * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z
    + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
              (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
             c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
               (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
                      ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) +
              (
               c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 *
    (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
     * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (
    c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
    + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
    ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) + -1.0 *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0))
             + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
             -1.5) * c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0)) +
    -2.0 * (c6_x2x + -1.0 * c6_x4x) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z
    )) + -2.0 * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z))) + (c6_x2x + -1.0 *
             c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
              c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
              (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                (
                 c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
               * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
             c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
              c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
             (c6_x2z + -1.0 * c6_x4z)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
              + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) + -1.0 *
    (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z);
  c6_d23 = (((((-1.0 * (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) *
                        c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0))
    + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0
               ), -1.5) + -1.0 * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y +
    -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) + 0.5 * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) + -1.0 * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) * ((c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0
    * (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * (c6_power
                  (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                   c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
                  (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
                (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + (c6_x1x + -1.0 * c6_x3x) *
               (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * c6_power(chartInstance,
                (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (
    c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
    2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
                    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) + -0.5 * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
    (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
    (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
              ((2.0 * (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
                       + -1.0 * c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5)) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))
                + 2.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) *
                ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
                 * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5))) + 2.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power
               (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z
    + -1.0 * c6_x3z) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
    ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) +
               (
                c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 *
             c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
                (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
    chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
                      ) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
               (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                 (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                  c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                (
                 c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
    + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
               (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((
    c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (2.0 * ((-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2y + -1.0 * c6_x4y)) * (-1.0 * c6_x2y + c6_x4y) + 2.0
              * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
                 (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * (c6_x2z
    +
    -1.0 * c6_x4z))) + -0.5 * c6_power(chartInstance, (c6_power(chartInstance, (
    -1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
              (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
             + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
                        2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
              (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
               c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
              * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
             ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
              ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0
    * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) *
            ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (
              c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * (2.0 *
             ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0
    * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) * (-1.0 * c6_x2y + c6_x4y) + 2.0 *
             ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
              -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) *
             (c6_x2z + -1.0 * c6_x4z))) + -1.0 * c6_power(chartInstance,
    (c6_power(
              chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
              + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
     c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
              + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * (c6_x2z + -1.0 * c6_x4z);
  c6_d24 = (((((-1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y + -1.0 * c6_x3y) *
                c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0))
    + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0
               ), -1.5) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0
    * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
    (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
                c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                  (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) + 0.5 *
                c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (c6_x1x +
    -1.0 * c6_x3x) * (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 *
                  (c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0) *
                   c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0
    ) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) + -1.0 *
                   c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) * ((c6_x1y
    + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0
    * (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance
    , c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * (c6_power
                  (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                   c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
                  (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
                (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + (c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) + -1.0 * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) *
               c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power
               (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
                    2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
                 -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(
              chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
     (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
                c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)))
              + -0.5 * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) + 2.0 * (c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) + -1.0 * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)) * ((c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0 * (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
              (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
    (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                 (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                  + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0
    * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0
    * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x
    + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z),
             2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
              (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
               (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * (-1.0 * c6_x2z + c6_x4z)) + 0.5 * c6_power(
             chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) *
               (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance,
             (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
                       c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
             c6_power(chartInstance, c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
             c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
              -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
              c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
              -1.0 * c6_x4z)) * (2.0 * (c6_x2x + -1.0 * c6_x4x) * ((-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x)
              * (c6_x2y + -1.0 * c6_x4y)) + 2.0 * ((-1.0 * c6_x1z + c6_x3z) *
              (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z)) * (-1.0 * c6_x2z + c6_x4z))) + -0.5 * c6_power(chartInstance,
    (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (
    c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
              2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) *
    (2.0 * (c6_x2x + -1.0 * c6_x4x) * ((-1.0 * c6_x1y +
       c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
       -1.0 * c6_x4y)) + 2.0 * ((-1.0 * c6_x1z + c6_x3z) * (
       c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
       c6_x4z)) * (-1.0 * c6_x2z + c6_x4z));
  c6_d25 = ((((((-1.0 * (-1.0 * c6_x2x + c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0)
     + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z
    + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                   (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power
                (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0
    * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                 c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5
                 ) * (c6_x1z + -1.0 * c6_x3z) * c6_power(chartInstance,
    (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
              + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
     c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
    + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
               2.0), -0.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 *
               c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (
    c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0
    * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 *
                 (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x +
    -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y +
    -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0 * (-1.0 *
    c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -1.5) * c6_power(chartInstance, c6_x1z + -1.0 *
                     c6_x3z, 2.0)) * (c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y +
    -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
    -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
    ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
    -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * (2.0 * (-1.0
    * c6_x2x + c6_x4x) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) + 2.0 * (c6_x2y + -1.0 * c6_x4y) * ((-1.0 *
    c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) *
    (c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (
    c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
             + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y),
             2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x +
    -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z))) + (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
              (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
               c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
              (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * (c6_x1z +
              -1.0
              * c6_x3z) * c6_power(chartInstance, (c6_power(chartInstance, (-1.0
    * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0
    * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z
    + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
              (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
             c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
               (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                      ) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) +
              (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 *
            c6_power(
                     chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((2.0 * (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -1.5) * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x
    + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0))
             + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0
                        ), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                     c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 * (c6_x1y + -1.0
    * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0
    * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5)
              * (c6_x1z + -1.0 * c6_x3z) * ((c6_x1y + -1.0 * c6_x3y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y,
                    2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
                 -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(
              chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
     (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + 2.0 * (-1.0 * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -1.5) * c6_power
              (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0)) * (c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
            (chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 *
    c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance
    , (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
       (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y)
               * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
               (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z +
    -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((
              c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
              chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
              c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) *
            ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y +
              -1.0
              * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * (2.0 * (-1.0 *
    c6_x2x + c6_x4x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) + 2.0 *
    (c6_x2y + -1.0 * c6_x4y) * ((-1.0 * c6_x1z + c6_x3z)
    * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z));
  c6_d26 = (((((-1.0 * (-1.0 * c6_x1z + c6_x3z) * c6_power(chartInstance,
    (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0)
     + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z
    + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                  (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                   + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) + -1.0 * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + -1.0 * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 * (2.0 * (c6_x1y + -1.0 *
    c6_x3y) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0
    * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 *
    (-1.0 * c6_x1z + c6_x3z) * ((c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z))) + -0.5 * (2.0 * (c6_x1y + -1.0 * c6_x3y) * ((-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) + 2.0 * (-1.0 * c6_x1z + c6_x3z) *
    ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
     * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) * c6_power
              (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
    * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(
    chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
    c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) +
             0.5 * c6_power(chartInstance, (c6_power(chartInstance, (
    -1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(
    chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
                (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0
    )) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
                  (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
    2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                     (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) +
                    (c6_x2y
                     + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5), 2.0)) + c6_power(chartInstance, c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) *
             ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
              * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
              + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) * ((2.0 * (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) *
                        c6_power(chartInstance, (c6_power(chartInstance, c6_x2x
    + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0))
    + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0
               ), -1.5) + -1.0 * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y +
    -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + 2.0 * (c6_x2x + -1.0
    * c6_x4x) * (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0
    * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
                 * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
                (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
                 (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z))
                * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * c6_power
            (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y)
    * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 *
    c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 *
    c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (
    -1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y)
              * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(
             chartInstance, (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
             c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (
    c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
             c6_power(chartInstance, c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
                      (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
                       (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) *
                      (c6_x2z
                       + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1y + -1.0 * c6_x3y)
             * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x
    , 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                        (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (
              c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance,
    c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y
              + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
              c6_x4z)) * ((2.0 * (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)
    + -1.0 * c6_power(chartInstance, (c6_power(chartInstance
    , c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5))
              + 2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 *
    c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0))
    + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -1.5)) + 2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_power(chartInstance, (c6_power
                (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z
    ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5) * (c6_x2z + -1.0 * c6_x4z)) * c6_power(chartInstance,
              (c6_power(
                        chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
               (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z
               + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z))) +
    (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -1.5);
  c6_b_x1z = ((((((c6_x1z + -1.0 * c6_x3z) * c6_power(chartInstance, (c6_power
    (chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z
    + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                     + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) + 0.5 * (2.0 * (-1.0 * c6_x1x + c6_x3x) * ((-1.0
    * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2y + -1.0 * c6_x4y)) + 2.0 * (c6_x1z + -1.0 *
    c6_x3z) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y +
    -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z +
    -1.0 * c6_x4z))) + c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
    (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
    (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
                 c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                   (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
    ) * (c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0) * c6_power
         (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x
    , 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
          (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + -1.0
         * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) *
                 ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (
    c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * (2.0 * (-1.0 *
    c6_x1x + c6_x3x) * ((-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y)) +
    2.0 * (c6_x1z + -1.0 * c6_x3z) * ((-1.0 * c6_x1z + c6_x3z
    ) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) * c6_power(chartInstance, (c6_power(
    chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x
    + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
    c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
             + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -1.5) * c6_power(chartInstance, (c6_power
    (chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
    (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x)
     * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y)
    * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 *
    c6_x4z))) + 0.5 * c6_power(chartInstance, (c6_power(chartInstance, (-1.0 *
    c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance,
    (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
    (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
    c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) *
               c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                 (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
                        ) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                 (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                  c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
    -1.0
    * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 * (c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + -1.0 *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0
    * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
             c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5
             )) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) + 2.0 * (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 *
    c6_x4y) * (
               (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5))
    + 2.0 * (c6_x2y + -1.0 * c6_x4y) * (c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z
    ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5) * (c6_x2z + -1.0 * c6_x4z)) * c6_power(chartInstance,
    (c6_power(
              chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
     (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * c6_power
              (chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y
    + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z
    + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
    chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y
    + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
               ) * c6_power(chartInstance, (c6_power(chartInstance, (c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                 (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(
                    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                  (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y
    + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                 (
                  c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                  c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(
             chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1y +
    -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((-1.0
    * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) *
    (c6_x2z + -1.0 * c6_x4z)) * ((2.0 * (c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) + -1.0 *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0)
    + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
    ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((c6_x1y
    + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) + 2.0 *
                (c6_x2x + -1.0 * c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)) + 2.0 * (c6_x2y
    + -1.0 * c6_x4y) * (c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power
                        (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z
    + -1.0 * c6_x4z)) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x
    + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -1.5) * (c6_x2z + -1.0 * c6_x4z))) + -1.0 * (c6_x2x
    + -1.0 * c6_x4x) * (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance,
    (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0)
     + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z
    + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x)
    + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5);
  c6_a = ((((((-1.0 * (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x
    + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0)
     + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (
    c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z
    + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
    -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance, (
    c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
     c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0
    * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5),
             2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (
    c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power
    (chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(
    chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power
    (chartInstance, c6_power(chartInstance, (c6_power(chartInstance
    , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance,
                 (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                  + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) + (-1.0 * c6_x1y + c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x +
    -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) *
    (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x)
    * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z +
    c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 *
    c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * c6_power(chartInstance,
    (c6_power(chartInstance, (c6_x1x + -1.0 * c6_x3x) *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 *
    c6_x3y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) +
    c6_power(chartInstance, c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z) + c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0
    * c6_x4z), 2.0), -0.5) * ((c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5))) + 0.5 * (2.0 * (c6_x1x + -1.0 * c6_x3x) *
    ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) +
     -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) + 2.0 * (-1.0 *
    c6_x1y + c6_x3y) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y
    + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) *
              c6_power(chartInstance, (c6_power(chartInstance, (-1.0
    * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) *
    (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance
    , (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x +
    -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
                       (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0
    * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0),
                       -1.5) * c6_power(chartInstance, (c6_power(chartInstance,
                 (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance
     , c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
                (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power
                 (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(
                    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
                  (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y
    + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
                 (
                  c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                  c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(
             chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0
    * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5) * ((c6_x1x +
    -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
     (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((
    c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 *
    c6_x3x) * (c6_x2z + -1.0 * c6_x4z))) + -0.5 * (2.0 * (
    c6_x1x + -1.0 * c6_x3x) * ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
    c6_x4z)) + 2.0 * (-1.0 * c6_x1y + c6_x3y) * ((-1.0 * c6_x1z + c6_x3z) *
    (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (
    c6_x2z + -1.0 * c6_x4z))) * c6_power(chartInstance, (c6_power(chartInstance,
                (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power
    (chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
    c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0))
              + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) * (
    c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z),
    2.0), -1.5) * c6_power(chartInstance, (c6_power(
    chartInstance, (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0) + c6_power(chartInstance, (c6_x1y + -1.0 * c6_x3y) *
    c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
    + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)
    ) + c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y +
    -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
    * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
              ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
    c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5)) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) +
              (
               c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z))) + 0.5 *
            c6_power(chartInstance, (c6_power(chartInstance, (-1.0 * c6_x1y +
    c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y +
    -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z +
    -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) *
               (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power(
              chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y)
              + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0), -0.5
                     ) * c6_power(chartInstance, (c6_power(chartInstance,
    (c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 *
    c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance,
    (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
     c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
    (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
              (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance,
                (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                 (
                  chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power
    (chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 *
    c6_x4y
    ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                 -0.5), 2.0)) + c6_power(chartInstance, c6_power(chartInstance,
               (
                c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power
                (chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(
    chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) * (c6_x1z + -1.0 * c6_x3z)
              + c6_power(chartInstance, (c6_power(chartInstance,
    c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 *
    c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5) * ((c6_x1x +
              -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y
    + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z
    + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power
             (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power
              (chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) * ((
              c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 *
             (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 *
              (c6_power
               (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x,
    2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) *
               (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (-1.0 * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0
    * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
     c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5
     ) + c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x,
    2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
                    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
                  -1.5) * c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0))
              + 2.0 *
              (c6_x2x + -1.0 * c6_x4x) * ((c6_x1x + -1.0 * c6_x3x) * c6_power
    (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0)
                     + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
     c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x +
    -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x +
    -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y +
    -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0),
    -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z)) + 2.0 * (c6_x2y +
              -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z
              ))) + -0.5 * c6_power(chartInstance, (c6_power(chartInstance,
              (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x) + (c6_x1x +
    -1.0
    * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) + c6_power(chartInstance, (c6_x1z
    + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (
    c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z), 2.0)) + c6_power
            (chartInstance, (-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
              c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z), 2.0),
            -0.5) * c6_power(chartInstance, (c6_power(chartInstance, (
    c6_x1x + -1.0 * c6_x3x) * c6_power(chartInstance, (c6_power(chartInstance,
    c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(chartInstance,
    c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance, c6_x1z + -1.0 *
    c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0 * c6_x4x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) +
                    c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
    c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5), 2.0) + c6_power
             (chartInstance, (c6_x1y + -1.0 * c6_x3y) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0
    * c6_x4y) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5), 2.0)) + c6_power(chartInstance, c6_power
             (chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
              c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
             * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z), 2.0), -1.5
            ) * ((c6_x1y + -1.0 * c6_x3y) * c6_power(chartInstance, (c6_power
              (chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) + c6_power(
    chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) + c6_power(chartInstance,
              c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2y + -1.0 * c6_x4y
             ) * c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y,
    2.0)) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5)) *
           ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 * c6_x4y) + (
             c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) * ((2.0 *
             (c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                       c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0),
                       -0.5)
              * (c6_x1z + -1.0 * c6_x3z) + c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5) * (c6_x2z + -1.0 * c6_x4z)) * (-1.0 *
              c6_power(chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)
    ) + c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -0.5) + c6_power
              (chartInstance, (c6_power(chartInstance, c6_x2x + -1.0 *
    c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) +
               c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0), -1.5)
              * c6_power(chartInstance, c6_x2z + -1.0 * c6_x4z, 2.0)) + 2.0 *
             (c6_x2x + -1.0 * c6_x4x) * ((c6_x1x + -1.0 * c6_x3x) * c6_power(
    chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 * c6_x3x, 2.0) +
                    c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
    c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5) + (c6_x2x + -1.0
    * c6_x4x) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
    + -1.0 * c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(
    chartInstance, c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance,
    c6_x2z + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z
              )) + 2.0 * (c6_x2y + -1.0 * c6_x4y) * ((c6_x1y + -1.0 * c6_x3y) *
             c6_power(chartInstance, (c6_power(chartInstance, c6_x1x + -1.0 *
    c6_x3x, 2.0) + c6_power(chartInstance, c6_x1y + -1.0 * c6_x3y, 2.0)) +
                      c6_power(chartInstance, c6_x1z + -1.0 * c6_x3z, 2.0), -0.5)
             + (c6_x2y + -1.0 * c6_x4y) * c6_power(chartInstance, (c6_power
    (chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance
    , c6_x2y + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z + -1.0 *
    c6_x4z, 2.0), -0.5)) * c6_power(chartInstance, (c6_power(
    chartInstance, c6_x2x + -1.0 * c6_x4x, 2.0) + c6_power(chartInstance, c6_x2y
    + -1.0 * c6_x4y, 2.0)) + c6_power(chartInstance, c6_x2z
              + -1.0 * c6_x4z, 2.0), -1.5) * (c6_x2z + -1.0 * c6_x4z))) + -1.0 *
          (c6_x2x + -1.0 * c6_x4x) * c6_power(chartInstance, (c6_power(
             chartInstance, (-1.0 * c6_x1y + c6_x3y) * (c6_x2x + -1.0 * c6_x4x)
             + (c6_x1x + -1.0 * c6_x3x) * (c6_x2y + -1.0 * c6_x4y), 2.0) +
            c6_power(chartInstance, (c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 *
              c6_x4x) + -1.0 * (c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 *
              c6_x4z), 2.0)) + c6_power(chartInstance, (-1.0 * c6_x1z + c6_x3z) *
            (c6_x2y + -1.0 * c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z +
             -1.0 * c6_x4z), 2.0), -0.5) * muDoubleScalarPower(c6_f_a, -0.5) *
          ((c6_x1z + -1.0 * c6_x3z) * (c6_x2x + -1.0 * c6_x4x) + -1.0 * (
            c6_x1x + -1.0 * c6_x3x) * (c6_x2z + -1.0 * c6_x4z)) *
          muDoubleScalarPower(c6_g_a, -1.5) * (c6_x2z + -1.0 * c6_x4z)) +
    (c6_x2y + -1.0
     * c6_x4y) * muDoubleScalarPower(c6_h_a, -0.5) * muDoubleScalarPower(c6_a,
    -0.5) * ((-1.0 * c6_x1z + c6_x3z) * (c6_x2y + -1.0 *
              c6_x4y) + (c6_x1y + -1.0 * c6_x3y) * (c6_x2z + -1.0 * c6_x4z)) *
    muDoubleScalarPower(c6_b_a, -1.5) * (c6_x2z + -1.0 * c6_x4z);
  c6_J[0] = c6_c_a;
  c6_J[3] = c6_d_a;
  c6_J[6] = c6_e_a;
  c6_J[9] = c6_i_a;
  c6_J[12] = c6_d0;
  c6_J[15] = c6_d1;
  c6_J[18] = c6_d2;
  c6_J[21] = c6_d3;
  c6_J[24] = c6_d4;
  c6_J[27] = c6_d5;
  c6_J[30] = c6_d6;
  c6_J[33] = c6_d7;
  c6_J[1] = c6_d8;
  c6_J[4] = c6_d9;
  c6_J[7] = c6_d10;
  c6_J[10] = c6_d11;
  c6_J[13] = c6_d12;
  c6_J[16] = c6_d13;
  c6_J[19] = c6_d14;
  c6_J[22] = c6_b_x1x;
  c6_J[25] = c6_c_x1x;
  c6_J[28] = c6_d15;
  c6_J[31] = c6_d16;
  c6_J[34] = c6_d17;
  c6_J[2] = c6_d18;
  c6_J[5] = c6_d_x1x;
  c6_J[8] = c6_d19;
  c6_J[11] = c6_d20;
  c6_J[14] = c6_d21;
  c6_J[17] = c6_d22;
  c6_J[20] = c6_d23;
  c6_J[23] = c6_d24;
  c6_J[26] = c6_d25;
  c6_J[29] = c6_d26;
  c6_J[32] = c6_b_x1z;
  c6_J[35] = c6_a;
  for (c6_i2 = 0; c6_i2 < 36; c6_i2 = c6_i2 + 1) {
    (*c6_b_J)[c6_i2] = c6_J[c6_i2];
  }
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static real_T c6_power(SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c6_a, real_T c6_b)
{
  if ((c6_a < 0.0) && (muDoubleScalarFloor(c6_b) != c6_b)) {
    c6_eml_error(chartInstance);
  }

  return muDoubleScalarPower(c6_a, c6_b);
}

static void c6_eml_error(SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
  int32_T c6_i3;
  static char_T c6_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':'
    , 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c6_u[32];
  const mxArray *c6_y = NULL;
  static char_T c6_cv1[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ',', ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't',
    ' ', 'o', 'n', 'e', ' ',
    'i', 'n', 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ',', ' ',
    'e', '.', 'g', '.', ' ',
    '\'', 'p', 'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'a', ')', ',', 'b', ')',
    '\'', '.' };

  char_T c6_b_u[102];
  const mxArray *c6_b_y = NULL;
  for (c6_i3 = 0; c6_i3 < 32; c6_i3 = c6_i3 + 1) {
    c6_u[c6_i3] = c6_cv0[c6_i3];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c6_i3 = 0; c6_i3 < 102; c6_i3 = c6_i3 + 1) {
    c6_b_u[c6_i3] = c6_cv1[c6_i3];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call("error", 0U, 2U, 14, c6_y, 14, c6_b_y);
}

const mxArray *sf_c6_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[28];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i4;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 28));
  for (c6_i4 = 0; c6_i4 < 28; c6_i4 = c6_i4 + 1) {
    c6_r0 = &c6_info[c6_i4];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c6_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c6_r0->context)), "context", "nameCaptureInfo", c6_i4);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c6_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)c6_r0
      ->name)), "name", "nameCaptureInfo", c6_i4);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c6_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const char
      *)c6_r0->dominantType)), "dominantType", "nameCaptureInfo", c6_i4);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c6_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c6_r0->resolved)), "resolved", "nameCaptureInfo", c6_i4);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c6_i4);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c6_i4);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c6_i4);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[28])
{
  c6_info[0].context = "";
  c6_info[0].name = "uminus";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved = "[B]uminus";
  c6_info[0].fileLength = 0U;
  c6_info[0].fileTime1 = 0U;
  c6_info[0].fileTime2 = 0U;
  c6_info[1].context = "";
  c6_info[1].name = "times";
  c6_info[1].dominantType = "double";
  c6_info[1].resolved = "[B]times";
  c6_info[1].fileLength = 0U;
  c6_info[1].fileTime1 = 0U;
  c6_info[1].fileTime2 = 0U;
  c6_info[2].context = "";
  c6_info[2].name = "plus";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved = "[B]plus";
  c6_info[2].fileLength = 0U;
  c6_info[2].fileTime1 = 0U;
  c6_info[2].fileTime2 = 0U;
  c6_info[3].context = "";
  c6_info[3].name = "power";
  c6_info[3].dominantType = "double";
  c6_info[3].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[3].fileLength = 5380U;
  c6_info[3].fileTime1 = 1228090298U;
  c6_info[3].fileTime2 = 0U;
  c6_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[4].name = "nargin";
  c6_info[4].dominantType = "";
  c6_info[4].resolved = "[B]nargin";
  c6_info[4].fileLength = 0U;
  c6_info[4].fileTime1 = 0U;
  c6_info[4].fileTime2 = 0U;
  c6_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[5].name = "gt";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved = "[B]gt";
  c6_info[5].fileLength = 0U;
  c6_info[5].fileTime1 = 0U;
  c6_info[5].fileTime2 = 0U;
  c6_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[6].name = "isa";
  c6_info[6].dominantType = "double";
  c6_info[6].resolved = "[B]isa";
  c6_info[6].fileLength = 0U;
  c6_info[6].fileTime1 = 0U;
  c6_info[6].fileTime2 = 0U;
  c6_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[7].name = "isinteger";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved = "[B]isinteger";
  c6_info[7].fileLength = 0U;
  c6_info[7].fileTime1 = 0U;
  c6_info[7].fileTime2 = 0U;
  c6_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[8].name = "eml_scalar_eg";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[8].fileLength = 3068U;
  c6_info[8].fileTime1 = 1240258410U;
  c6_info[8].fileTime2 = 0U;
  c6_info[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c6_info[9].name = "false";
  c6_info[9].dominantType = "";
  c6_info[9].resolved = "[B]false";
  c6_info[9].fileLength = 0U;
  c6_info[9].fileTime1 = 0U;
  c6_info[9].fileTime2 = 0U;
  c6_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[10].name = "isstruct";
  c6_info[10].dominantType = "double";
  c6_info[10].resolved = "[B]isstruct";
  c6_info[10].fileLength = 0U;
  c6_info[10].fileTime1 = 0U;
  c6_info[10].fileTime2 = 0U;
  c6_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c6_info[11].name = "eq";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved = "[B]eq";
  c6_info[11].fileLength = 0U;
  c6_info[11].fileTime1 = 0U;
  c6_info[11].fileTime2 = 0U;
  c6_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c6_info[12].name = "class";
  c6_info[12].dominantType = "double";
  c6_info[12].resolved = "[B]class";
  c6_info[12].fileLength = 0U;
  c6_info[12].fileTime1 = 0U;
  c6_info[12].fileTime2 = 0U;
  c6_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c6_info[13].name = "cast";
  c6_info[13].dominantType = "double";
  c6_info[13].resolved = "[B]cast";
  c6_info[13].fileLength = 0U;
  c6_info[13].fileTime1 = 0U;
  c6_info[13].fileTime2 = 0U;
  c6_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/allreal";
  c6_info[14].name = "isreal";
  c6_info[14].dominantType = "double";
  c6_info[14].resolved = "[B]isreal";
  c6_info[14].fileLength = 0U;
  c6_info[14].fileTime1 = 0U;
  c6_info[14].fileTime2 = 0U;
  c6_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[15].name = "eml_scalexp_alloc";
  c6_info[15].dominantType = "double";
  c6_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[15].fileLength = 808U;
  c6_info[15].fileTime1 = 1230491098U;
  c6_info[15].fileTime2 = 0U;
  c6_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[16].name = "minus";
  c6_info[16].dominantType = "double";
  c6_info[16].resolved = "[B]minus";
  c6_info[16].fileLength = 0U;
  c6_info[16].fileTime1 = 0U;
  c6_info[16].fileTime2 = 0U;
  c6_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[17].name = "isscalar";
  c6_info[17].dominantType = "double";
  c6_info[17].resolved = "[B]isscalar";
  c6_info[17].fileLength = 0U;
  c6_info[17].fileTime1 = 0U;
  c6_info[17].fileTime2 = 0U;
  c6_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[18].name = "not";
  c6_info[18].dominantType = "logical";
  c6_info[18].resolved = "[B]not";
  c6_info[18].fileLength = 0U;
  c6_info[18].fileTime1 = 0U;
  c6_info[18].fileTime2 = 0U;
  c6_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[19].name = "lt";
  c6_info[19].dominantType = "double";
  c6_info[19].resolved = "[B]lt";
  c6_info[19].fileLength = 0U;
  c6_info[19].fileTime1 = 0U;
  c6_info[19].fileTime2 = 0U;
  c6_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[20].name = "eml_scalar_floor";
  c6_info[20].dominantType = "double";
  c6_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c6_info[20].fileLength = 260U;
  c6_info[20].fileTime1 = 1209327190U;
  c6_info[20].fileTime2 = 0U;
  c6_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[21].name = "ne";
  c6_info[21].dominantType = "double";
  c6_info[21].resolved = "[B]ne";
  c6_info[21].fileLength = 0U;
  c6_info[21].fileTime1 = 0U;
  c6_info[21].fileTime2 = 0U;
  c6_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[22].name = "eml_error";
  c6_info[22].dominantType = "char";
  c6_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c6_info[22].fileLength = 315U;
  c6_info[22].fileTime1 = 1213923144U;
  c6_info[22].fileTime2 = 0U;
  c6_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c6_info[23].name = "strcmp";
  c6_info[23].dominantType = "char";
  c6_info[23].resolved = "[B]strcmp";
  c6_info[23].fileLength = 0U;
  c6_info[23].fileTime1 = 0U;
  c6_info[23].fileTime2 = 0U;
  c6_info[24].context = "";
  c6_info[24].name = "mrdivide";
  c6_info[24].dominantType = "double";
  c6_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[24].fileLength = 800U;
  c6_info[24].fileTime1 = 1238430690U;
  c6_info[24].fileTime2 = 0U;
  c6_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[25].name = "ge";
  c6_info[25].dominantType = "double";
  c6_info[25].resolved = "[B]ge";
  c6_info[25].fileLength = 0U;
  c6_info[25].fileTime1 = 0U;
  c6_info[25].fileTime2 = 0U;
  c6_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[26].name = "rdivide";
  c6_info[26].dominantType = "double";
  c6_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[26].fileLength = 403U;
  c6_info[26].fileTime1 = 1244731952U;
  c6_info[26].fileTime2 = 0U;
  c6_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[27].name = "eml_div";
  c6_info[27].dominantType = "double";
  c6_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[27].fileLength = 4269U;
  c6_info[27].fileTime1 = 1228090226U;
  c6_info[27].fileTime2 = 0U;
}

static void c6_emlrt_marshallIn(SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, const mxArray *c6_J, const char_T *
  c6_name, real_T c6_y[36])
{
  real_T c6_dv1[36];
  int32_T c6_i5;
  sf_mex_import(c6_name, sf_mex_dup(c6_J), &c6_dv1, 1, 0, 0U, 1, 0U, 2, 3, 12);
  for (c6_i5 = 0; c6_i5 < 36; c6_i5 = c6_i5 + 1) {
    c6_y[c6_i5] = c6_dv1[c6_i5];
  }

  sf_mex_destroy(&c6_J);
}

static uint8_T c6_b_emlrt_marshallIn
  (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c6_b_is_active_c6_ODE_Hand_Model_v08_IPC_v03, const char_T *c6_name)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_name, sf_mex_dup(c6_b_is_active_c6_ODE_Hand_Model_v08_IPC_v03),
                &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_b_is_active_c6_ODE_Hand_Model_v08_IPC_v03);
  return c6_y;
}

static void init_dsm_address_info(SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(850253898U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2130627229U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2541351836U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2844924653U);
}

mxArray *sf_c6_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3725141371U);
    pr[1] = (double)(2969229707U);
    pr[2] = (double)(2870703636U);
    pr[3] = (double)(2056886616U);
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
      pr[1] = (double)(12);
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

static mxArray *sf_get_sim_state_info_c6_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"J\",},{M[8],M[0],T\"is_active_c6_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c6_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c6_ODE_Hand_Model_v08_IPC_v03
    ((SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c6_ODE_Hand_Model_v08_IPC_v03
    ((SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c6_ODE_Hand_Model_v08_IPC_v03
    ((SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c6_ODE_Hand_Model_v08_IPC_v03
    ((SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c6_ODE_Hand_Model_v08_IPC_v03
    ((SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c6_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_ODE_Hand_Model_v08_IPC_v03
    ((SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c6_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c6_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_ODE_Hand_Model_v08_IPC_v03
    ((SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c6_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c6_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c6_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c6_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c6_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_ODE_Hand_Model_v08_IPC_v03
      ((SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_ODE_Hand_Model_v08_IPC_v03
      ((SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",6,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",6,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",6,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2557665240U));
  ssSetChecksum1(S,(2463616148U));
  ssSetChecksum2(S,(3753093271U));
  ssSetChecksum3(S,(1224463222U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",6);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc(sizeof
    (SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c6_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c6_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_ODE_Hand_Model_v08_IPC_v03;
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

void c6_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
