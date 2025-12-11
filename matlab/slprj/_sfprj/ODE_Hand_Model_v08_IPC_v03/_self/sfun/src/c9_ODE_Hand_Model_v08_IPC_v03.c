/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c9_ODE_Hand_Model_v08_IPC_v03.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray
   *c9_st);
static void finalize_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void c9_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static real_T c9_power(SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c9_a, real_T c9_b);
static void c9_eml_error(SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);
static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[33]);
static void c9_emlrt_marshallIn(SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, const mxArray *c9_M, const char_T *c9_name, real_T c9_y[256]);
static uint8_T c9_b_emlrt_marshallIn
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray
   *c9_b_is_active_c9_ODE_Hand_Model_v08_IPC_v03, const char_T *c9_name);
static void init_dsm_address_info(SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  int32_T c9_i0;
  real_T c9_u[256];
  const mxArray *c9_b_y = NULL;
  uint8_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T (*c9_M)[256];
  c9_M = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(2));
  for (c9_i0 = 0; c9_i0 < 256; c9_i0 = c9_i0 + 1) {
    c9_u[c9_i0] = (*c9_M)[c9_i0];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 1U, 0U, 2, 16, 16));
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_u = chartInstance->c9_is_active_c9_ODE_Hand_Model_v08_IPC_v03;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 1, c9_c_y);
  sf_mex_assign(&c9_st, c9_y);
  return c9_st;
}

static void set_sim_state_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray
   *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[256];
  int32_T c9_i1;
  real_T (*c9_M)[256];
  c9_M = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)), "M",
                      c9_dv0);
  for (c9_i1 = 0; c9_i1 < 256; c9_i1 = c9_i1 + 1) {
    (*c9_M)[c9_i1] = c9_dv0[c9_i1];
  }

  chartInstance->c9_is_active_c9_ODE_Hand_Model_v08_IPC_v03 =
    c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1))
    , "is_active_c9_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c9_u);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c9_previousEvent;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c9_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c9_c9_ODE_Hand_Model_v08_IPC_v03(chartInstance);
  _sfEvent_ = c9_previousEvent;
}

static void c9_c9_ODE_Hand_Model_v08_IPC_v03
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c9_i;
  real_T c9_q[16];
  real_T c9_M1[256];
  real_T c9_q1;
  real_T c9_q2;
  real_T c9_q3;
  real_T c9_q4;
  int32_T c9_b_i;
  int32_T c9_c_i;
  real_T c9_d0;
  real_T c9_d1;
  real_T c9_d2;
  real_T c9_d3;
  real_T c9_d4;
  real_T c9_d5;
  real_T (*c9_M)[256];
  real_T (*c9_b_q)[16];
  c9_M = (real_T (*)[256])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_q = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  for (c9_i = 0; c9_i < 16; c9_i = c9_i + 1) {
    c9_q[c9_i] = (*c9_b_q)[c9_i];
  }

  for (c9_i = 0; c9_i < 256; c9_i = c9_i + 1) {
    c9_M1[c9_i] = 0.0;
  }

  for (c9_i = 0; c9_i < 16; c9_i = c9_i + 4) {
    c9_q1 = c9_q[c9_i];
    c9_q2 = c9_q[sf_mex_lw_bounds_check(c9_i + 2, 1, 16) - 1];
    c9_q3 = c9_q[sf_mex_lw_bounds_check(c9_i + 3, 1, 16) - 1];
    c9_q4 = c9_q[sf_mex_lw_bounds_check(c9_i + 4, 1, 16) - 1];
    c9_b_i = c9_i + 1;
    c9_c_i = c9_i + 1;
    c9_d0 = (((((((0.1675 * c9_power(chartInstance, muDoubleScalarCos(c9_q2),
      2.0) + 0.0837 * c9_power(chartInstance, muDoubleScalarCos(
      c9_q2 + c9_q3), 2.0)) + 0.0834 * c9_power(chartInstance, muDoubleScalarCos
                   ((c9_q2 + c9_q3) + c9_q4), 2.0)) + 2.0 * (0.25 * c9_power(
      chartInstance, 1.1, 2.0) * c9_power(chartInstance, muDoubleScalarCos(c9_q1),
      2.0) * c9_power(chartInstance, muDoubleScalarCos(c9_q2)
                      , 2.0) + 0.25 * c9_power(chartInstance, 1.1, 2.0) *
      c9_power(chartInstance, muDoubleScalarCos(c9_q2), 2.0) * c9_power
      (chartInstance
       , muDoubleScalarSin(c9_q1), 2.0))) + (c9_power(chartInstance, -0.3 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2 + c9_q3) +
      muDoubleScalarCos(c9_q1) * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3)), 2.0) + c9_power(chartInstance
      , 0.3 * muDoubleScalarCos(c9_q2 + c9_q3) * muDoubleScalarSin(c9_q1) + -1.0
      * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
         muDoubleScalarCos(c9_q2 + c9_q3)) * muDoubleScalarSin(c9_q1), 2.0))) +
               (c9_power(chartInstance, -0.275 * muDoubleScalarCos(c9_q1) *
                         muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) +
                         muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos
      (c9_q2) + 0.6 * muDoubleScalarCos(
      c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)), 2.0)
                + c9_power(chartInstance, 0.275 * muDoubleScalarCos((
      c9_q2 + c9_q3) + c9_q4) * muDoubleScalarSin(c9_q1) + -1.0 * ((1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3
      )) + 0.55 * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) *
      muDoubleScalarSin(c9_q1), 2.0))) + 0.1675 * c9_power(chartInstance,
               muDoubleScalarSin(c9_q2), 2.0)) + 0.0837 * c9_power(chartInstance,
              muDoubleScalarSin(c9_q2 + c9_q3), 2.0)) + 0.0834 * c9_power(
      chartInstance, muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4), 2.0);
    c9_d1 = (((((((0.1675 * c9_power(chartInstance, muDoubleScalarCos(c9_q1),
      2.0) * (c9_power(chartInstance, muDoubleScalarCos(c9_q1),
                       2.0) + c9_power(chartInstance, muDoubleScalarSin(c9_q1),
      2.0)) + 0.0837 * c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) *
                   (
                    c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) +
                    c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0))) +
                  0.0834 *
                  c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) *
                  (c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) +
                   c9_power(
      chartInstance, muDoubleScalarSin(c9_q1), 2.0))) + 0.1675 * c9_power
                 (chartInstance, muDoubleScalarSin(c9_q1), 2.0) * (c9_power(
      chartInstance, muDoubleScalarCos(c9_q1), 2.0) + c9_power(chartInstance,
      muDoubleScalarSin(c9_q1), 2.0))) + 0.0837 * c9_power(
      chartInstance, muDoubleScalarSin(c9_q1), 2.0) * (c9_power(chartInstance,
      muDoubleScalarCos(c9_q1), 2.0) + c9_power(chartInstance,
      muDoubleScalarSin(c9_q1), 2.0))) + 0.0834 * c9_power(chartInstance,
                muDoubleScalarSin(c9_q1), 2.0) * (c9_power(chartInstance,
      muDoubleScalarCos(c9_q1), 2.0) + c9_power(chartInstance, muDoubleScalarSin
                 (c9_q1), 2.0))) + 2.0 * ((c9_power(chartInstance, 0.55 *
      c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) * muDoubleScalarCos
                 (c9_q2) + 0.55 * muDoubleScalarCos(c9_q2) * c9_power(
      chartInstance, muDoubleScalarSin(c9_q1), 2.0), 2.0) + 0.25 * c9_power
                (chartInstance, 1.1, 2.0) * c9_power(chartInstance,
      muDoubleScalarCos(c9_q1), 2.0) * c9_power(chartInstance, muDoubleScalarSin
                 (c9_q2), 2.0)) + 0.25 * c9_power(chartInstance, 1.1, 2.0)
               * c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0) *
               c9_power(chartInstance, muDoubleScalarSin(c9_q2), 2.0))) +
             ((c9_power(
                        chartInstance, muDoubleScalarCos(c9_q1) * (-0.3 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2 + c9_q3) +
      muDoubleScalarCos(
                        c9_q1) * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3))) + muDoubleScalarSin(c9_q1) * (-0.3 *
      muDoubleScalarCos(c9_q2 + c9_q3) * muDoubleScalarSin(c9_q1) + (1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 +
      c9_q3)) * muDoubleScalarSin(c9_q1)), 2.0) + c9_power(chartInstance,
                muDoubleScalarCos(c9_q1), 2.0) * c9_power(chartInstance, 1.1 *
                muDoubleScalarSin(c9_q2) + 0.3 * muDoubleScalarSin(c9_q2 + c9_q3),
                2.0)) + c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0) *
              c9_power(chartInstance, 1.1 * muDoubleScalarSin(c9_q2) + 0.3 *
                       muDoubleScalarSin(c9_q2 + c9_q3), 2.0))) + ((c9_power
      (chartInstance,
       muDoubleScalarCos(c9_q1) * (-0.275 * muDoubleScalarCos(c9_q1) *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) + muDoubleScalarCos(c9_q1
      ) * ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 +
      c9_q3)) + 0.55 * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)))
       + muDoubleScalarSin(c9_q1) * (-0.275 * muDoubleScalarCos((c9_q2 + c9_q3)
      + c9_q4) * muDoubleScalarSin(c9_q1) + ((1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) *
      muDoubleScalarSin(c9_q1)), 2.0) + c9_power(chartInstance,
      muDoubleScalarCos(c9_q1), 2.0) * c9_power(chartInstance, (1.1 *
      muDoubleScalarSin(c9_q2) + 0.6 * muDoubleScalarSin(c9_q2 + c9_q3)) + 0.275
      * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4), 2.0)) +
      c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0) * c9_power
      (chartInstance, (1.1 * muDoubleScalarSin(c9_q2) + 0.6 *
                       muDoubleScalarSin(c9_q2 + c9_q3)) + 0.275 *
       muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4), 2.0));
    c9_d2 = ((((0.0837 * c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) *
                (c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0
                          ) + c9_power(chartInstance, muDoubleScalarSin(c9_q1),
      2.0)) + 0.0834 * c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) *
                (
                 c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) +
                 c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0))) +
               0.0837 *
               c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0) *
               (c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) +
                c9_power(
                         chartInstance, muDoubleScalarSin(c9_q1), 2.0))) +
              0.0834 * c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0) *
              (c9_power(
                        chartInstance, muDoubleScalarCos(c9_q1), 2.0) + c9_power
               (chartInstance, muDoubleScalarSin(c9_q1), 2.0))) +
             (((muDoubleScalarCos(
      c9_q1) * (-0.3 * muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2 +
      c9_q3) + muDoubleScalarCos(c9_q1) * (1.1 * muDoubleScalarCos(
      c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3))) + muDoubleScalarSin
                (c9_q1) * (-0.3 * muDoubleScalarCos(c9_q2 + c9_q3) *
      muDoubleScalarSin(c9_q1) + (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3)) * muDoubleScalarSin(c9_q1))) *
               (muDoubleScalarCos(c9_q1) * ((-1.1 * muDoubleScalarCos(c9_q1) *
      muDoubleScalarCos(c9_q2) + -0.3 * muDoubleScalarCos(c9_q1) *
      muDoubleScalarCos(c9_q2 + c9_q3)) + muDoubleScalarCos(c9_q1) * (1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 +
      c9_q3))) + muDoubleScalarSin(c9_q1) * ((-1.1 * muDoubleScalarCos(c9_q2) *
      muDoubleScalarSin(c9_q1) + -0.3 * muDoubleScalarCos(c9_q2
      + c9_q3) * muDoubleScalarSin(c9_q1)) + (1.1 * muDoubleScalarCos(c9_q2) +
      0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) *
      muDoubleScalarSin(c9_q1))) + 0.3 * c9_power(chartInstance,
                muDoubleScalarCos(c9_q1), 2.0) * muDoubleScalarSin(c9_q2 + c9_q3)
               * (1.1
                  * muDoubleScalarSin(c9_q2) + 0.3 * muDoubleScalarSin(c9_q2 +
      c9_q3))) + 0.3 * c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0
               ) * muDoubleScalarSin(c9_q2 + c9_q3) * (1.1 * muDoubleScalarSin
               (c9_q2) + 0.3 * muDoubleScalarSin(c9_q2 + c9_q3)))) + (((
      muDoubleScalarCos(c9_q1) * (-0.275 * muDoubleScalarCos(c9_q1) *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) + muDoubleScalarCos(c9_q1
      ) * ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 +
      c9_q3)) + 0.55 * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)))
      + muDoubleScalarSin(c9_q1) * (-0.275 * muDoubleScalarCos((c9_q2 + c9_q3) +
      c9_q4) * muDoubleScalarSin(c9_q1) + ((1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) *
      muDoubleScalarSin(c9_q1))) * (muDoubleScalarCos(c9_q1) * ((-1.1 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2) + -0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) +
      muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2)
      + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
      ((c9_q2 + c9_q3) + c9_q4))) + muDoubleScalarSin(c9_q1) * ((-1.1
      * muDoubleScalarCos(c9_q2) * muDoubleScalarSin(c9_q1) + -0.275 *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) * muDoubleScalarSin(
      c9_q1)) + ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2
      + c9_q3)) + 0.55 * muDoubleScalarCos((c9_q2 + c9_q3) +
      c9_q4)) * muDoubleScalarSin(c9_q1))) + c9_power(chartInstance,
      muDoubleScalarCos(c9_q1), 2.0) * (0.6 * muDoubleScalarSin(c9_q2 +
      c9_q3) + 0.275 * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4)) * ((1.1 *
      muDoubleScalarSin(c9_q2) + 0.6 * muDoubleScalarSin(c9_q2 +
      c9_q3)) + 0.275 * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4))) + c9_power
      (chartInstance, muDoubleScalarSin(c9_q1), 2.0) * (0.6 *
      muDoubleScalarSin(c9_q2 + c9_q3) + 0.275 * muDoubleScalarSin((c9_q2 +
      c9_q3) + c9_q4)) * ((1.1 * muDoubleScalarSin(c9_q2) + 0.6 *
      muDoubleScalarSin(c9_q2 + c9_q3)) + 0.275 * muDoubleScalarSin((c9_q2 +
      c9_q3) + c9_q4)));
    c9_d3 = (0.0834 * c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) *
             (c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0)
              + c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0)) + 0.0834
             * c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0) * (
              c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) + c9_power
              (chartInstance, muDoubleScalarSin(c9_q1), 2.0))) + (((
      muDoubleScalarCos(c9_q1) * (-0.275 * muDoubleScalarCos(c9_q1) *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) + muDoubleScalarCos(c9_q1
      ) * ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 +
      c9_q3)) + 0.55 * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)))
      + muDoubleScalarSin(c9_q1) * (-0.275 * muDoubleScalarCos((c9_q2 + c9_q3) +
      c9_q4) * muDoubleScalarSin(c9_q1) + ((1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) *
      muDoubleScalarSin(c9_q1))) * (muDoubleScalarCos(c9_q1) * ((-1.0 *
      muDoubleScalarCos(c9_q1) * (1.1 * muDoubleScalarCos(c9_q2) + 0.6
      * muDoubleScalarCos(c9_q2 + c9_q3)) + -0.275 * muDoubleScalarCos(c9_q1) *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) +
      muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos((
      c9_q2 + c9_q3) + c9_q4))) + muDoubleScalarSin(c9_q1) * ((-1.0 * (1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 +
      c9_q3)) * muDoubleScalarSin(c9_q1) + -0.275 * muDoubleScalarCos((c9_q2 +
      c9_q3) + c9_q4) * muDoubleScalarSin(c9_q1)) + ((1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) *
      muDoubleScalarSin(c9_q1))) + 0.275 * c9_power(chartInstance,
      muDoubleScalarCos(c9_q1), 2.0) * muDoubleScalarSin((c9_q2 + c9_q3) +
      c9_q4) * ((1.1 * muDoubleScalarSin(c9_q2) + 0.6 * muDoubleScalarSin(c9_q2
      + c9_q3)) + 0.275 * muDoubleScalarSin((c9_q2 + c9_q3) +
      c9_q4))) + 0.275 * c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0) *
      muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4) * ((1.1 *
      muDoubleScalarSin(c9_q2) + 0.6 * muDoubleScalarSin(c9_q2 + c9_q3)) + 0.275
      * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4)));
    c9_d4 = ((((0.0837 * c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) *
                (c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0
                          ) + c9_power(chartInstance, muDoubleScalarSin(c9_q1),
      2.0)) + 0.0834 * c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) *
                (
                 c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) +
                 c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0))) +
               0.0837 *
               c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0) *
               (c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) +
                c9_power(
                         chartInstance, muDoubleScalarSin(c9_q1), 2.0))) +
              0.0834 * c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0) *
              (c9_power(
                        chartInstance, muDoubleScalarCos(c9_q1), 2.0) + c9_power
               (chartInstance, muDoubleScalarSin(c9_q1), 2.0))) +
             (((muDoubleScalarCos(
      c9_q1) * (-0.3 * muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2 +
      c9_q3) + muDoubleScalarCos(c9_q1) * (1.1 * muDoubleScalarCos(
      c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3))) + muDoubleScalarSin
                (c9_q1) * (-0.3 * muDoubleScalarCos(c9_q2 + c9_q3) *
      muDoubleScalarSin(c9_q1) + (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3)) * muDoubleScalarSin(c9_q1))) *
               (muDoubleScalarCos(c9_q1) * ((-1.1 * muDoubleScalarCos(c9_q1) *
      muDoubleScalarCos(c9_q2) + -0.3 * muDoubleScalarCos(c9_q1) *
      muDoubleScalarCos(c9_q2 + c9_q3)) + muDoubleScalarCos(c9_q1) * (1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 +
      c9_q3))) + muDoubleScalarSin(c9_q1) * ((-1.1 * muDoubleScalarCos(c9_q2) *
      muDoubleScalarSin(c9_q1) + -0.3 * muDoubleScalarCos(c9_q2
      + c9_q3) * muDoubleScalarSin(c9_q1)) + (1.1 * muDoubleScalarCos(c9_q2) +
      0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) *
      muDoubleScalarSin(c9_q1))) + 0.3 * c9_power(chartInstance,
                muDoubleScalarCos(c9_q1), 2.0) * muDoubleScalarSin(c9_q2 + c9_q3)
               * (1.1
                  * muDoubleScalarSin(c9_q2) + 0.3 * muDoubleScalarSin(c9_q2 +
      c9_q3))) + 0.3 * c9_power(chartInstance, muDoubleScalarSin(c9_q1), 2.0
               ) * muDoubleScalarSin(c9_q2 + c9_q3) * (1.1 * muDoubleScalarSin
               (c9_q2) + 0.3 * muDoubleScalarSin(c9_q2 + c9_q3)))) + (((
      muDoubleScalarCos(c9_q1) * (-0.275 * muDoubleScalarCos(c9_q1) *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) + muDoubleScalarCos(c9_q1
      ) * ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 +
      c9_q3)) + 0.55 * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)))
      + muDoubleScalarSin(c9_q1) * (-0.275 * muDoubleScalarCos((c9_q2 + c9_q3) +
      c9_q4) * muDoubleScalarSin(c9_q1) + ((1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) *
      muDoubleScalarSin(c9_q1))) * (muDoubleScalarCos(c9_q1) * ((-1.1 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2) + -0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) +
      muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2)
      + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
      ((c9_q2 + c9_q3) + c9_q4))) + muDoubleScalarSin(c9_q1) * ((-1.1
      * muDoubleScalarCos(c9_q2) * muDoubleScalarSin(c9_q1) + -0.275 *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) * muDoubleScalarSin(
      c9_q1)) + ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2
      + c9_q3)) + 0.55 * muDoubleScalarCos((c9_q2 + c9_q3) +
      c9_q4)) * muDoubleScalarSin(c9_q1))) + c9_power(chartInstance,
      muDoubleScalarCos(c9_q1), 2.0) * (0.6 * muDoubleScalarSin(c9_q2 +
      c9_q3) + 0.275 * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4)) * ((1.1 *
      muDoubleScalarSin(c9_q2) + 0.6 * muDoubleScalarSin(c9_q2 +
      c9_q3)) + 0.275 * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4))) + c9_power
      (chartInstance, muDoubleScalarSin(c9_q1), 2.0) * (0.6 *
      muDoubleScalarSin(c9_q2 + c9_q3) + 0.275 * muDoubleScalarSin((c9_q2 +
      c9_q3) + c9_q4)) * ((1.1 * muDoubleScalarSin(c9_q2) + 0.6 *
      muDoubleScalarSin(c9_q2 + c9_q3)) + 0.275 * muDoubleScalarSin((c9_q2 +
      c9_q3) + c9_q4)));
    c9_d5 = ((((0.0837 * c9_power(chartInstance, muDoubleScalarCos(c9_q1), 2.0) *
                (muDoubleScalarPower(muDoubleScalarCos(c9_q1), 2.0) +
                 muDoubleScalarPower(muDoubleScalarSin(c9_q1), 2.0)) + 0.0834 *
                muDoubleScalarPower(muDoubleScalarCos(c9_q1), 2.0) * (
      muDoubleScalarPower(muDoubleScalarCos(c9_q1), 2.0) + muDoubleScalarPower
      (muDoubleScalarSin(c9_q1), 2.0))) + 0.0837 *
               muDoubleScalarPower(muDoubleScalarSin(c9_q1), 2.0) *
               (muDoubleScalarPower(muDoubleScalarCos(c9_q1), 2.0) +
                muDoubleScalarPower(
      muDoubleScalarSin(c9_q1), 2.0))) + 0.0834 * muDoubleScalarPower
              (muDoubleScalarSin(c9_q1), 2.0) * (muDoubleScalarPower(
                muDoubleScalarCos(c9_q1), 2.0) + muDoubleScalarPower
               (muDoubleScalarSin(c9_q1), 2.0))) + ((muDoubleScalarPower
               (muDoubleScalarCos(
      c9_q1) * ((-1.1 * muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2) +
                 -0.3 * muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2 +
      c9_q3)) + muDoubleScalarCos(c9_q1) * (1.1 * muDoubleScalarCos(c9_q2) + 0.6
      * muDoubleScalarCos(c9_q2 + c9_q3))) + muDoubleScalarSin(
      c9_q1) * ((-1.1 * muDoubleScalarCos(c9_q2) * muDoubleScalarSin(c9_q1) +
                 -0.3 * muDoubleScalarCos(c9_q2 + c9_q3) * muDoubleScalarSin(
      c9_q1)) + (1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2
      + c9_q3)) * muDoubleScalarSin(c9_q1)), 2.0) + 0.09 *
               muDoubleScalarPower(muDoubleScalarCos(c9_q1), 2.0) *
               muDoubleScalarPower(muDoubleScalarSin(c9_q2 + c9_q3), 2.0)) +
              0.09 *
              muDoubleScalarPower(muDoubleScalarSin(c9_q1), 2.0) *
              muDoubleScalarPower(muDoubleScalarSin(c9_q2 + c9_q3), 2.0))) + ((
      muDoubleScalarPower(muDoubleScalarCos(c9_q1) * ((-1.1 * muDoubleScalarCos
      (c9_q1) * muDoubleScalarCos(c9_q2) + -0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) +
      muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2)
      + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
      ((c9_q2 + c9_q3) + c9_q4))) + muDoubleScalarSin(c9_q1) * ((-1.1
      * muDoubleScalarCos(c9_q2) * muDoubleScalarSin(c9_q1) + -0.275 *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) * muDoubleScalarSin(
      c9_q1)) + ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2
      + c9_q3)) + 0.55 * muDoubleScalarCos((c9_q2 + c9_q3) +
      c9_q4)) * muDoubleScalarSin(c9_q1)), 2.0) + muDoubleScalarPower
      (muDoubleScalarCos(c9_q1), 2.0) * muDoubleScalarPower(0.6 *
      muDoubleScalarSin(c9_q2 + c9_q3) + 0.275 * muDoubleScalarSin((c9_q2 +
      c9_q3) + c9_q4), 2.0)) + muDoubleScalarPower(muDoubleScalarSin
      (c9_q1), 2.0) * muDoubleScalarPower(0.6 * muDoubleScalarSin(c9_q2 + c9_q3)
      + 0.275 * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4), 2.0
      ));
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i, 1, 16) - 1) + ((sf_mex_lw_bounds_check
      (c9_c_i, 1, 16) - 1) << 4)] = c9_d0;
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i, 1, 16) - 1) + ((sf_mex_lw_bounds_check
      (c9_c_i + 1, 1, 16) - 1) << 4)] = (-1.0 * (-0.3 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2 + c9_q3) +
      muDoubleScalarCos(c9_q1) * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3))) * muDoubleScalarSin(c9_q1) * (1.1 *
      muDoubleScalarSin(c9_q2) + 0.3 * muDoubleScalarSin(c9_q2 +
      c9_q3)) + -1.0 * muDoubleScalarCos(c9_q1) * (0.3 * muDoubleScalarCos(c9_q2
      + c9_q3) * muDoubleScalarSin(c9_q1) + -1.0 * (1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) *
      muDoubleScalarSin(c9_q1)) * (1.1 * muDoubleScalarSin(c9_q2) +
      0.3 * muDoubleScalarSin(c9_q2 + c9_q3))) + (-1.0 * (-0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)
      + muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos(
      (c9_q2 + c9_q3) + c9_q4))) * muDoubleScalarSin(c9_q1) * ((1.1 *
      muDoubleScalarSin(c9_q2) + 0.6 * muDoubleScalarSin(c9_q2 + c9_q3))
      + 0.275 * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4)) + -1.0 *
      muDoubleScalarCos(c9_q1) * (0.275 * muDoubleScalarCos((c9_q2 + c9_q3
      ) + c9_q4) * muDoubleScalarSin(c9_q1) + -1.0 * ((1.1 * muDoubleScalarCos
      (c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) * muDoubleScalarSin(c9_q1)) *
      ((1.1 * muDoubleScalarSin(c9_q2) + 0.6 * muDoubleScalarSin
        (c9_q2 + c9_q3)) + 0.275 * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4)));
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i, 1, 16) - 1) + ((sf_mex_lw_bounds_check
      (c9_c_i + 2, 1, 16) - 1) << 4)] = (-0.3 * (-0.3 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2 + c9_q3) +
      muDoubleScalarCos(c9_q1) * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3))) * muDoubleScalarSin(c9_q1) *
      muDoubleScalarSin(c9_q2 + c9_q3) + -0.3 * muDoubleScalarCos(c9_q1)
      * (0.3 * muDoubleScalarCos(c9_q2 + c9_q3) * muDoubleScalarSin(c9_q1) +
         -1.0 * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
                 muDoubleScalarCos(c9_q2 + c9_q3)) * muDoubleScalarSin(c9_q1)) *
      muDoubleScalarSin(c9_q2 + c9_q3)) + (-1.0 * (-0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) +
      muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2)
      + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
      ((c9_q2 + c9_q3) + c9_q4))) * muDoubleScalarSin(c9_q1) * (0.6
      * muDoubleScalarSin(c9_q2 + c9_q3) + 0.275 * muDoubleScalarSin((c9_q2 +
      c9_q3) + c9_q4)) + -1.0 * muDoubleScalarCos(c9_q1) * (0.275
      * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) * muDoubleScalarSin(c9_q1) +
      -1.0 * ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
               muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
              ((c9_q2 + c9_q3) + c9_q4)) * muDoubleScalarSin(c9_q1)) * (0.6 *
      muDoubleScalarSin(c9_q2 + c9_q3) + 0.275 * muDoubleScalarSin((c9_q2 +
      c9_q3) + c9_q4)));
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i, 1, 16) - 1) + ((sf_mex_lw_bounds_check
      (c9_c_i + 3, 1, 16) - 1) << 4)] = -0.275 * (-0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) +
      muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2)
      + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
      ((c9_q2 + c9_q3) + c9_q4))) * muDoubleScalarSin(c9_q1) *
      muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4) + -0.275 * muDoubleScalarCos
      (c9_q1) * (0.275 * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)
                 * muDoubleScalarSin(c9_q1) + -1.0 * ((1.1 * muDoubleScalarCos
      (c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) * muDoubleScalarSin(c9_q1)) *
      muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4);
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i + 1, 1, 16) - 1) +
      ((sf_mex_lw_bounds_check(c9_c_i, 1, 16) - 1) << 4)] = (-1.0 * (-0.3 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2 + c9_q3) +
      muDoubleScalarCos(c9_q1) * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3))) * muDoubleScalarSin(c9_q1) * (1.1 *
      muDoubleScalarSin(c9_q2) + 0.3 * muDoubleScalarSin(c9_q2 +
      c9_q3)) + -1.0 * muDoubleScalarCos(c9_q1) * (0.3 * muDoubleScalarCos(c9_q2
      + c9_q3) * muDoubleScalarSin(c9_q1) + -1.0 * (1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) *
      muDoubleScalarSin(c9_q1)) * (1.1 * muDoubleScalarSin(c9_q2) +
      0.3 * muDoubleScalarSin(c9_q2 + c9_q3))) + (-1.0 * (-0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)
      + muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos(
      (c9_q2 + c9_q3) + c9_q4))) * muDoubleScalarSin(c9_q1) * ((1.1 *
      muDoubleScalarSin(c9_q2) + 0.6 * muDoubleScalarSin(c9_q2 + c9_q3))
      + 0.275 * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4)) + -1.0 *
      muDoubleScalarCos(c9_q1) * (0.275 * muDoubleScalarCos((c9_q2 + c9_q3
      ) + c9_q4) * muDoubleScalarSin(c9_q1) + -1.0 * ((1.1 * muDoubleScalarCos
      (c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) * muDoubleScalarSin(c9_q1)) *
      ((1.1 * muDoubleScalarSin(c9_q2) + 0.6 * muDoubleScalarSin
        (c9_q2 + c9_q3)) + 0.275 * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4)));
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i + 1, 1, 16) - 1) +
      ((sf_mex_lw_bounds_check(c9_c_i + 1, 1, 16) - 1) << 4)] = c9_d1;
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i + 1, 1, 16) - 1) +
      ((sf_mex_lw_bounds_check(c9_c_i + 2, 1, 16) - 1) << 4)] = c9_d2;
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i + 1, 1, 16) - 1) +
      ((sf_mex_lw_bounds_check(c9_c_i + 3, 1, 16) - 1) << 4)] = c9_d3;
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i + 2, 1, 16) - 1) +
      ((sf_mex_lw_bounds_check(c9_c_i, 1, 16) - 1) << 4)] = (-0.3 * (-0.3 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2 + c9_q3) +
      muDoubleScalarCos(c9_q1) * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3))) * muDoubleScalarSin(c9_q1) *
      muDoubleScalarSin(c9_q2 + c9_q3) + -0.3 * muDoubleScalarCos(c9_q1)
      * (0.3 * muDoubleScalarCos(c9_q2 + c9_q3) * muDoubleScalarSin(c9_q1) +
         -1.0 * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
                 muDoubleScalarCos(c9_q2 + c9_q3)) * muDoubleScalarSin(c9_q1)) *
      muDoubleScalarSin(c9_q2 + c9_q3)) + (-1.0 * (-0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) +
      muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2)
      + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
      ((c9_q2 + c9_q3) + c9_q4))) * muDoubleScalarSin(c9_q1) * (0.6
      * muDoubleScalarSin(c9_q2 + c9_q3) + 0.275 * muDoubleScalarSin((c9_q2 +
      c9_q3) + c9_q4)) + -1.0 * muDoubleScalarCos(c9_q1) * (0.275
      * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) * muDoubleScalarSin(c9_q1) +
      -1.0 * ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
               muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
              ((c9_q2 + c9_q3) + c9_q4)) * muDoubleScalarSin(c9_q1)) * (0.6 *
      muDoubleScalarSin(c9_q2 + c9_q3) + 0.275 * muDoubleScalarSin((c9_q2 +
      c9_q3) + c9_q4)));
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i + 2, 1, 16) - 1) +
      ((sf_mex_lw_bounds_check(c9_c_i + 1, 1, 16) - 1) << 4)] = c9_d4;
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i + 2, 1, 16) - 1) +
      ((sf_mex_lw_bounds_check(c9_c_i + 2, 1, 16) - 1) << 4)] = c9_d5;
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i + 2, 1, 16) - 1) +
      ((sf_mex_lw_bounds_check(c9_c_i + 3, 1, 16) - 1) << 4)] = (0.0834 *
      muDoubleScalarPower(muDoubleScalarCos(c9_q1), 2.0) * (muDoubleScalarPower
      (muDoubleScalarCos(c9_q1), 2.0) + muDoubleScalarPower(
      muDoubleScalarSin(c9_q1), 2.0)) + 0.0834 * muDoubleScalarPower
      (muDoubleScalarSin(c9_q1), 2.0) * (muDoubleScalarPower(
      muDoubleScalarCos(c9_q1), 2.0) + muDoubleScalarPower(muDoubleScalarSin
      (c9_q1), 2.0))) + (((muDoubleScalarCos(c9_q1) * ((-1.1 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2) + -0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)
      ) + muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
                             ((c9_q2 + c9_q3) + c9_q4))) + muDoubleScalarSin
      (c9_q1) * ((-1.1 * muDoubleScalarCos(c9_q2) * muDoubleScalarSin(c9_q1) +
                  -0.275 *
                  muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) * muDoubleScalarSin
                  (c9_q1)) + ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(
                        c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos((c9_q2 +
      c9_q3) + c9_q4)) * muDoubleScalarSin(c9_q1))) * (muDoubleScalarCos(c9_q1) *
                           ((
      -1.0 * muDoubleScalarCos(c9_q1) * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3)) + -0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) +
      muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2)
      + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
      ((c9_q2 + c9_q3) + c9_q4))) + muDoubleScalarSin(c9_q1) * ((-1.0
      * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3))
      * muDoubleScalarSin(c9_q1) + -0.275 * muDoubleScalarCos
                             ((c9_q2 + c9_q3) + c9_q4) * muDoubleScalarSin(c9_q1))
      + ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3))
         + 0.55 * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) *
      muDoubleScalarSin(c9_q1))) + 0.275 * muDoubleScalarPower(muDoubleScalarCos
                           (
      c9_q1), 2.0) * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4) * (0.6 *
      muDoubleScalarSin(c9_q2 + c9_q3) + 0.275 * muDoubleScalarSin((
      c9_q2 + c9_q3) + c9_q4))) + 0.275 * muDoubleScalarPower(muDoubleScalarSin
      (c9_q1), 2.0) * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4)
                         * (0.6 * muDoubleScalarSin(c9_q2 + c9_q3) + 0.275 *
      muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4)));
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i + 3, 1, 16) - 1) +
      ((sf_mex_lw_bounds_check(c9_c_i, 1, 16) - 1) << 4)] = -0.275 * (-0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) +
      muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2)
      + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
      ((c9_q2 + c9_q3) + c9_q4))) * muDoubleScalarSin(c9_q1) *
      muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4) + -0.275 * muDoubleScalarCos
      (c9_q1) * (0.275 * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)
                 * muDoubleScalarSin(c9_q1) + -1.0 * ((1.1 * muDoubleScalarCos
      (c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) * muDoubleScalarSin(c9_q1)) *
      muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4);
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i + 3, 1, 16) - 1) +
      ((sf_mex_lw_bounds_check(c9_c_i + 1, 1, 16) - 1) << 4)] = (0.0834 *
      muDoubleScalarPower(muDoubleScalarCos(c9_q1), 2.0) * (muDoubleScalarPower
      (muDoubleScalarCos(c9_q1), 2.0) + muDoubleScalarPower(
      muDoubleScalarSin(c9_q1), 2.0)) + 0.0834 * muDoubleScalarPower
      (muDoubleScalarSin(c9_q1), 2.0) * (muDoubleScalarPower(
      muDoubleScalarCos(c9_q1), 2.0) + muDoubleScalarPower(muDoubleScalarSin
      (c9_q1), 2.0))) + (((muDoubleScalarCos(c9_q1) * (-0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) +
      muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2)
      + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
      ((c9_q2 + c9_q3) + c9_q4))) + muDoubleScalarSin(c9_q1) * (
      -0.275 * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) * muDoubleScalarSin
      (c9_q1) + ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
                  muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
                 ((c9_q2 + c9_q3) + c9_q4)) * muDoubleScalarSin(c9_q1))) * (
      muDoubleScalarCos(c9_q1) * ((-1.0 * muDoubleScalarCos(c9_q1) * (1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 +
      c9_q3)) + -0.275 * muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 +
      c9_q3) + c9_q4)) + muDoubleScalarCos(c9_q1) * ((1.1 *
      muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 *
      muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4))) +
      muDoubleScalarSin(c9_q1) * ((-1.0 * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3)) * muDoubleScalarSin(
      c9_q1) + -0.275 * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) *
      muDoubleScalarSin(c9_q1)) + ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos((c9_q2 +
      c9_q3) + c9_q4)) * muDoubleScalarSin(c9_q1))) + 0.275 *
                          muDoubleScalarPower(muDoubleScalarCos(c9_q1), 2.0) *
                          muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4) * ((1.1 *
      muDoubleScalarSin(c9_q2)
      + 0.6 * muDoubleScalarSin(c9_q2 + c9_q3)) + 0.275 * muDoubleScalarSin
      ((c9_q2 + c9_q3) + c9_q4))) + 0.275 * muDoubleScalarPower(
      muDoubleScalarSin(c9_q1), 2.0) * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4)
                         * ((1.1 * muDoubleScalarSin(c9_q2) + 0.6 *
      muDoubleScalarSin(c9_q2 + c9_q3)) + 0.275 * muDoubleScalarSin((c9_q2 +
      c9_q3) + c9_q4)));
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i + 3, 1, 16) - 1) +
      ((sf_mex_lw_bounds_check(c9_c_i + 2, 1, 16) - 1) << 4)] = (0.0834 *
      muDoubleScalarPower(muDoubleScalarCos(c9_q1), 2.0) * (muDoubleScalarPower
      (muDoubleScalarCos(c9_q1), 2.0) + muDoubleScalarPower(
      muDoubleScalarSin(c9_q1), 2.0)) + 0.0834 * muDoubleScalarPower
      (muDoubleScalarSin(c9_q1), 2.0) * (muDoubleScalarPower(
      muDoubleScalarCos(c9_q1), 2.0) + muDoubleScalarPower(muDoubleScalarSin
      (c9_q1), 2.0))) + (((muDoubleScalarCos(c9_q1) * ((-1.1 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos(c9_q2) + -0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)
      ) + muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
                             ((c9_q2 + c9_q3) + c9_q4))) + muDoubleScalarSin
      (c9_q1) * ((-1.1 * muDoubleScalarCos(c9_q2) * muDoubleScalarSin(c9_q1) +
                  -0.275 *
                  muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4) * muDoubleScalarSin
                  (c9_q1)) + ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(
                        c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos((c9_q2 +
      c9_q3) + c9_q4)) * muDoubleScalarSin(c9_q1))) * (muDoubleScalarCos(c9_q1) *
                           ((
      -1.0 * muDoubleScalarCos(c9_q1) * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 *
      muDoubleScalarCos(c9_q2 + c9_q3)) + -0.275 *
      muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) +
      muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2)
      + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
      ((c9_q2 + c9_q3) + c9_q4))) + muDoubleScalarSin(c9_q1) * ((-1.0
      * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3))
      * muDoubleScalarSin(c9_q1) + -0.275 * muDoubleScalarCos
                             ((c9_q2 + c9_q3) + c9_q4) * muDoubleScalarSin(c9_q1))
      + ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3))
         + 0.55 * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) *
      muDoubleScalarSin(c9_q1))) + 0.275 * muDoubleScalarPower(muDoubleScalarCos
                           (
      c9_q1), 2.0) * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4) * (0.6 *
      muDoubleScalarSin(c9_q2 + c9_q3) + 0.275 * muDoubleScalarSin((
      c9_q2 + c9_q3) + c9_q4))) + 0.275 * muDoubleScalarPower(muDoubleScalarSin
      (c9_q1), 2.0) * muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4)
                         * (0.6 * muDoubleScalarSin(c9_q2 + c9_q3) + 0.275 *
      muDoubleScalarSin((c9_q2 + c9_q3) + c9_q4)));
    c9_M1[(sf_mex_lw_bounds_check(c9_b_i + 3, 1, 16) - 1) +
      ((sf_mex_lw_bounds_check(c9_c_i + 3, 1, 16) - 1) << 4)] = (0.0834 *
      muDoubleScalarPower(muDoubleScalarCos(c9_q1), 2.0) * (muDoubleScalarPower
      (muDoubleScalarCos(c9_q1), 2.0) + muDoubleScalarPower(
      muDoubleScalarSin(c9_q1), 2.0)) + 0.0834 * muDoubleScalarPower
      (muDoubleScalarSin(c9_q1), 2.0) * (muDoubleScalarPower(
      muDoubleScalarCos(c9_q1), 2.0) + muDoubleScalarPower(muDoubleScalarSin
      (c9_q1), 2.0))) + ((muDoubleScalarPower(muDoubleScalarCos(
      c9_q1) * ((-1.0 * muDoubleScalarCos(c9_q1) * (1.1 * muDoubleScalarCos
      (c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + -0.275 *
                 muDoubleScalarCos(c9_q1) * muDoubleScalarCos((c9_q2 + c9_q3) +
      c9_q4)) + muDoubleScalarCos(c9_q1) * ((1.1 * muDoubleScalarCos(c9_q2)
      + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3)) + 0.55 * muDoubleScalarCos
      ((c9_q2 + c9_q3) + c9_q4))) + muDoubleScalarSin(c9_q1) * ((-1.0
      * (1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3))
      * muDoubleScalarSin(c9_q1) + -0.275 * muDoubleScalarCos
                             ((c9_q2 + c9_q3) + c9_q4) * muDoubleScalarSin(c9_q1))
      + ((1.1 * muDoubleScalarCos(c9_q2) + 0.6 * muDoubleScalarCos(c9_q2 + c9_q3))
         + 0.55 * muDoubleScalarCos((c9_q2 + c9_q3) + c9_q4)) *
      muDoubleScalarSin(c9_q1)), 2.0) + 7.5625000000000012E-002 *
                          muDoubleScalarPower(muDoubleScalarCos(c9_q1), 2.0) *
                          muDoubleScalarPower(muDoubleScalarSin((c9_q2 + c9_q3)
      + c9_q4), 2.0)) +
                         7.5625000000000012E-002 * muDoubleScalarPower
                         (muDoubleScalarSin(c9_q1), 2.0) * muDoubleScalarPower
                         (muDoubleScalarSin((c9_q2 + c9_q3)
      + c9_q4), 2.0));
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  for (c9_i = 0; c9_i < 256; c9_i = c9_i + 1) {
    (*c9_M)[c9_i] = c9_M1[c9_i];
  }
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static real_T c9_power(SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c9_a, real_T c9_b)
{
  if ((c9_a < 0.0) && (muDoubleScalarFloor(c9_b) != c9_b)) {
    c9_eml_error(chartInstance);
  }

  return muDoubleScalarPower(c9_a, c9_b);
}

static void c9_eml_error(SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
  int32_T c9_i2;
  static char_T c9_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':'
    , 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c9_u[32];
  const mxArray *c9_y = NULL;
  static char_T c9_cv1[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
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

  char_T c9_b_u[102];
  const mxArray *c9_b_y = NULL;
  for (c9_i2 = 0; c9_i2 < 32; c9_i2 = c9_i2 + 1) {
    c9_u[c9_i2] = c9_cv0[c9_i2];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c9_i2 = 0; c9_i2 < 102; c9_i2 = c9_i2 + 1) {
    c9_b_u[c9_i2] = c9_cv1[c9_i2];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call("error", 0U, 2U, 14, c9_y, 14, c9_b_y);
}

const mxArray *sf_c9_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[33];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i3;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_info_helper(c9_info);
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 33));
  for (c9_i3 = 0; c9_i3 < 33; c9_i3 = c9_i3 + 1) {
    c9_r0 = &c9_info[c9_i3];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c9_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c9_r0->context)), "context", "nameCaptureInfo", c9_i3);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c9_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)c9_r0
      ->name)), "name", "nameCaptureInfo", c9_i3);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c9_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const char
      *)c9_r0->dominantType)), "dominantType", "nameCaptureInfo", c9_i3);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c9_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c9_r0->resolved)), "resolved", "nameCaptureInfo", c9_i3);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c9_i3);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c9_i3);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c9_i3);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[33])
{
  c9_info[0].context = "";
  c9_info[0].name = "zeros";
  c9_info[0].dominantType = "double";
  c9_info[0].resolved = "[B]zeros";
  c9_info[0].fileLength = 0U;
  c9_info[0].fileTime1 = 0U;
  c9_info[0].fileTime2 = 0U;
  c9_info[1].context = "";
  c9_info[1].name = "plus";
  c9_info[1].dominantType = "double";
  c9_info[1].resolved = "[B]plus";
  c9_info[1].fileLength = 0U;
  c9_info[1].fileTime1 = 0U;
  c9_info[1].fileTime2 = 0U;
  c9_info[2].context = "";
  c9_info[2].name = "cos";
  c9_info[2].dominantType = "double";
  c9_info[2].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c9_info[2].fileLength = 324U;
  c9_info[2].fileTime1 = 1203444350U;
  c9_info[2].fileTime2 = 0U;
  c9_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c9_info[3].name = "nargin";
  c9_info[3].dominantType = "";
  c9_info[3].resolved = "[B]nargin";
  c9_info[3].fileLength = 0U;
  c9_info[3].fileTime1 = 0U;
  c9_info[3].fileTime2 = 0U;
  c9_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c9_info[4].name = "gt";
  c9_info[4].dominantType = "double";
  c9_info[4].resolved = "[B]gt";
  c9_info[4].fileLength = 0U;
  c9_info[4].fileTime1 = 0U;
  c9_info[4].fileTime2 = 0U;
  c9_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c9_info[5].name = "isa";
  c9_info[5].dominantType = "double";
  c9_info[5].resolved = "[B]isa";
  c9_info[5].fileLength = 0U;
  c9_info[5].fileTime1 = 0U;
  c9_info[5].fileTime2 = 0U;
  c9_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c9_info[6].name = "eml_scalar_cos";
  c9_info[6].dominantType = "double";
  c9_info[6].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c9_info[6].fileLength = 602U;
  c9_info[6].fileTime1 = 1209327186U;
  c9_info[6].fileTime2 = 0U;
  c9_info[7].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c9_info[7].name = "isreal";
  c9_info[7].dominantType = "double";
  c9_info[7].resolved = "[B]isreal";
  c9_info[7].fileLength = 0U;
  c9_info[7].fileTime1 = 0U;
  c9_info[7].fileTime2 = 0U;
  c9_info[8].context = "";
  c9_info[8].name = "power";
  c9_info[8].dominantType = "double";
  c9_info[8].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[8].fileLength = 5380U;
  c9_info[8].fileTime1 = 1228090298U;
  c9_info[8].fileTime2 = 0U;
  c9_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[9].name = "isinteger";
  c9_info[9].dominantType = "double";
  c9_info[9].resolved = "[B]isinteger";
  c9_info[9].fileLength = 0U;
  c9_info[9].fileTime1 = 0U;
  c9_info[9].fileTime2 = 0U;
  c9_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[10].name = "eml_scalar_eg";
  c9_info[10].dominantType = "double";
  c9_info[10].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[10].fileLength = 3068U;
  c9_info[10].fileTime1 = 1240258410U;
  c9_info[10].fileTime2 = 0U;
  c9_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c9_info[11].name = "false";
  c9_info[11].dominantType = "";
  c9_info[11].resolved = "[B]false";
  c9_info[11].fileLength = 0U;
  c9_info[11].fileTime1 = 0U;
  c9_info[11].fileTime2 = 0U;
  c9_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[12].name = "isstruct";
  c9_info[12].dominantType = "double";
  c9_info[12].resolved = "[B]isstruct";
  c9_info[12].fileLength = 0U;
  c9_info[12].fileTime1 = 0U;
  c9_info[12].fileTime2 = 0U;
  c9_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c9_info[13].name = "eq";
  c9_info[13].dominantType = "double";
  c9_info[13].resolved = "[B]eq";
  c9_info[13].fileLength = 0U;
  c9_info[13].fileTime1 = 0U;
  c9_info[13].fileTime2 = 0U;
  c9_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c9_info[14].name = "class";
  c9_info[14].dominantType = "double";
  c9_info[14].resolved = "[B]class";
  c9_info[14].fileLength = 0U;
  c9_info[14].fileTime1 = 0U;
  c9_info[14].fileTime2 = 0U;
  c9_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c9_info[15].name = "cast";
  c9_info[15].dominantType = "double";
  c9_info[15].resolved = "[B]cast";
  c9_info[15].fileLength = 0U;
  c9_info[15].fileTime1 = 0U;
  c9_info[15].fileTime2 = 0U;
  c9_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[16].name = "eml_scalexp_alloc";
  c9_info[16].dominantType = "double";
  c9_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[16].fileLength = 808U;
  c9_info[16].fileTime1 = 1230491098U;
  c9_info[16].fileTime2 = 0U;
  c9_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[17].name = "minus";
  c9_info[17].dominantType = "double";
  c9_info[17].resolved = "[B]minus";
  c9_info[17].fileLength = 0U;
  c9_info[17].fileTime1 = 0U;
  c9_info[17].fileTime2 = 0U;
  c9_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[18].name = "isscalar";
  c9_info[18].dominantType = "double";
  c9_info[18].resolved = "[B]isscalar";
  c9_info[18].fileLength = 0U;
  c9_info[18].fileTime1 = 0U;
  c9_info[18].fileTime2 = 0U;
  c9_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[19].name = "not";
  c9_info[19].dominantType = "logical";
  c9_info[19].resolved = "[B]not";
  c9_info[19].fileLength = 0U;
  c9_info[19].fileTime1 = 0U;
  c9_info[19].fileTime2 = 0U;
  c9_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[20].name = "lt";
  c9_info[20].dominantType = "double";
  c9_info[20].resolved = "[B]lt";
  c9_info[20].fileLength = 0U;
  c9_info[20].fileTime1 = 0U;
  c9_info[20].fileTime2 = 0U;
  c9_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[21].name = "eml_scalar_floor";
  c9_info[21].dominantType = "double";
  c9_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c9_info[21].fileLength = 260U;
  c9_info[21].fileTime1 = 1209327190U;
  c9_info[21].fileTime2 = 0U;
  c9_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[22].name = "ne";
  c9_info[22].dominantType = "double";
  c9_info[22].resolved = "[B]ne";
  c9_info[22].fileLength = 0U;
  c9_info[22].fileTime1 = 0U;
  c9_info[22].fileTime2 = 0U;
  c9_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c9_info[23].name = "eml_error";
  c9_info[23].dominantType = "char";
  c9_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c9_info[23].fileLength = 315U;
  c9_info[23].fileTime1 = 1213923144U;
  c9_info[23].fileTime2 = 0U;
  c9_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c9_info[24].name = "strcmp";
  c9_info[24].dominantType = "char";
  c9_info[24].resolved = "[B]strcmp";
  c9_info[24].fileLength = 0U;
  c9_info[24].fileTime1 = 0U;
  c9_info[24].fileTime2 = 0U;
  c9_info[25].context = "";
  c9_info[25].name = "times";
  c9_info[25].dominantType = "double";
  c9_info[25].resolved = "[B]times";
  c9_info[25].fileLength = 0U;
  c9_info[25].fileTime1 = 0U;
  c9_info[25].fileTime2 = 0U;
  c9_info[26].context = "";
  c9_info[26].name = "mrdivide";
  c9_info[26].dominantType = "double";
  c9_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c9_info[26].fileLength = 800U;
  c9_info[26].fileTime1 = 1238430690U;
  c9_info[26].fileTime2 = 0U;
  c9_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c9_info[27].name = "ge";
  c9_info[27].dominantType = "double";
  c9_info[27].resolved = "[B]ge";
  c9_info[27].fileLength = 0U;
  c9_info[27].fileTime1 = 0U;
  c9_info[27].fileTime2 = 0U;
  c9_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c9_info[28].name = "rdivide";
  c9_info[28].dominantType = "double";
  c9_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[28].fileLength = 403U;
  c9_info[28].fileTime1 = 1244731952U;
  c9_info[28].fileTime2 = 0U;
  c9_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[29].name = "eml_div";
  c9_info[29].dominantType = "double";
  c9_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c9_info[29].fileLength = 4269U;
  c9_info[29].fileTime1 = 1228090226U;
  c9_info[29].fileTime2 = 0U;
  c9_info[30].context = "";
  c9_info[30].name = "sin";
  c9_info[30].dominantType = "double";
  c9_info[30].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c9_info[30].fileLength = 324U;
  c9_info[30].fileTime1 = 1203444442U;
  c9_info[30].fileTime2 = 0U;
  c9_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c9_info[31].name = "eml_scalar_sin";
  c9_info[31].dominantType = "double";
  c9_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c9_info[31].fileLength = 601U;
  c9_info[31].fileTime1 = 1209327190U;
  c9_info[31].fileTime2 = 0U;
  c9_info[32].context = "";
  c9_info[32].name = "uminus";
  c9_info[32].dominantType = "double";
  c9_info[32].resolved = "[B]uminus";
  c9_info[32].fileLength = 0U;
  c9_info[32].fileTime1 = 0U;
  c9_info[32].fileTime2 = 0U;
}

static void c9_emlrt_marshallIn(SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, const mxArray *c9_M, const char_T *
  c9_name, real_T c9_y[256])
{
  real_T c9_dv1[256];
  int32_T c9_i4;
  sf_mex_import(c9_name, sf_mex_dup(c9_M), &c9_dv1, 1, 0, 0U, 1, 0U, 2, 16, 16);
  for (c9_i4 = 0; c9_i4 < 256; c9_i4 = c9_i4 + 1) {
    c9_y[c9_i4] = c9_dv1[c9_i4];
  }

  sf_mex_destroy(&c9_M);
}

static uint8_T c9_b_emlrt_marshallIn
  (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c9_b_is_active_c9_ODE_Hand_Model_v08_IPC_v03, const char_T *c9_name)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_name, sf_mex_dup(c9_b_is_active_c9_ODE_Hand_Model_v08_IPC_v03),
                &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_b_is_active_c9_ODE_Hand_Model_v08_IPC_v03);
  return c9_y;
}

static void init_dsm_address_info(SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance)
{
}

/* SFunction Glue Code */
void sf_c9_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3774499571U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4132659741U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(724690999U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2039008428U);
}

mxArray *sf_c9_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3882110105U);
    pr[1] = (double)(2812093344U);
    pr[2] = (double)(3077186284U);
    pr[3] = (double)(1590568782U);
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
      pr[0] = (double)(16);
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

static mxArray *sf_get_sim_state_info_c9_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"M\",},{M[8],M[0],T\"is_active_c9_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c9_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c9_ODE_Hand_Model_v08_IPC_v03
    ((SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c9_ODE_Hand_Model_v08_IPC_v03
    ((SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c9_ODE_Hand_Model_v08_IPC_v03
    ((SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c9_ODE_Hand_Model_v08_IPC_v03
    ((SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c9_ODE_Hand_Model_v08_IPC_v03
    ((SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c9_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_ODE_Hand_Model_v08_IPC_v03
    ((SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c9_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c9_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_ODE_Hand_Model_v08_IPC_v03
    ((SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c9_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c9_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c9_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c9_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c9_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c9_ODE_Hand_Model_v08_IPC_v03
      ((SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_ODE_Hand_Model_v08_IPC_v03
      ((SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",9,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",9,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",9,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(975737466U));
  ssSetChecksum1(S,(565767500U));
  ssSetChecksum2(S,(2680037668U));
  ssSetChecksum3(S,(1969188648U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c9_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",9);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc(sizeof
    (SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_ODE_Hand_Model_v08_IPC_v03;
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

void c9_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
