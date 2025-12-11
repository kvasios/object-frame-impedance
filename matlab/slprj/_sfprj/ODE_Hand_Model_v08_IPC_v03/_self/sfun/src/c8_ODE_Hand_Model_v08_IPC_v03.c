/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c8_ODE_Hand_Model_v08_IPC_v03.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray
   *c8_st);
static void finalize_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static real_T c8_norm(SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct
                      *chartInstance, real_T c8_x[3]);
static real_T c8_ceval_xnrm2(SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c8_n, real_T c8_x[3], int32_T c8_ix0, int32_T c8_incx);
static void c8_mpower(SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct
                      *chartInstance, real_T c8_a[9], real_T c8_c[9]);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[78]);
static void c8_emlrt_marshallIn(SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, const mxArray *c8_J_r1, const char_T *c8_name, real_T c8_y[36]);
static uint8_T c8_b_emlrt_marshallIn
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray
   *c8_b_is_active_c8_ODE_Hand_Model_v08_IPC_v03, const char_T *c8_name);
static void init_dsm_address_info(SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  int32_T c8_i0;
  real_T c8_u[36];
  const mxArray *c8_b_y = NULL;
  uint8_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T (*c8_J_r1)[36];
  c8_J_r1 = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(2));
  for (c8_i0 = 0; c8_i0 < 36; c8_i0 = c8_i0 + 1) {
    c8_u[c8_i0] = (*c8_J_r1)[c8_i0];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 1U, 0U, 2, 3, 12));
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_u = chartInstance->c8_is_active_c8_ODE_Hand_Model_v08_IPC_v03;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y);
  return c8_st;
}

static void set_sim_state_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray
   *c8_st)
{
  const mxArray *c8_u;
  real_T c8_dv0[36];
  int32_T c8_i1;
  real_T (*c8_J_r1)[36];
  c8_J_r1 = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_u = sf_mex_dup(c8_st);
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)), "J_r1",
                      c8_dv0);
  for (c8_i1 = 0; c8_i1 < 36; c8_i1 = c8_i1 + 1) {
    (*c8_J_r1)[c8_i1] = c8_dv0[c8_i1];
  }

  chartInstance->c8_is_active_c8_ODE_Hand_Model_v08_IPC_v03 =
    c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1))
    , "is_active_c8_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c8_u);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c8_ODE_Hand_Model_v08_IPC_v03
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c8_previousEvent;
  int32_T c8_i2;
  int32_T c8_i3;
  real_T c8_B;
  real_T c8_x2[3];
  real_T c8_b_B;
  real_T c8_x4[3];
  real_T c8_x1[3];
  real_T c8_b_x1[3];
  real_T c8_x3[3];
  real_T c8_b_x2[3];
  real_T c8_partial_r1__term2_x1x3[9];
  real_T c8_c_x2[3];
  real_T c8_dv1[3];
  int32_T c8_i4;
  real_T c8_partial_r1__term2_x2x4[9];
  real_T c8_hoistedExpr[9];
  static int8_T c8_iv0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T c8_b_hoistedExpr[9];
  real_T c8_c_hoistedExpr[9];
  real_T c8_d_hoistedExpr[9];
  real_T c8_e_hoistedExpr[9];
  real_T c8_f_hoistedExpr[9];
  real_T c8_g_hoistedExpr[9];
  real_T c8_h_hoistedExpr[9];
  static int8_T c8_iv1[9] = { -1, 0, 0, 0, -1, 0, 0, 0, -1 };

  real_T c8_i_hoistedExpr[9];
  real_T (*c8_J_r1)[36];
  real_T (*c8_xi)[12];
  c8_J_r1 = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_xi = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c8_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c8_i2 = 0;
  for (c8_i3 = 0; c8_i3 < 3; c8_i3 = c8_i3 + 1) {
    c8_B = (*c8_xi)[c8_i2];
    c8_x2[c8_i3] = (*c8_xi)[c8_i2 + 1];
    c8_b_B = (*c8_xi)[c8_i2 + 2];
    c8_x4[c8_i3] = (*c8_xi)[c8_i2 + 3];
    c8_x1[c8_i3] = c8_B - c8_b_B;
    c8_b_x1[c8_i3] = c8_B;
    c8_x3[c8_i3] = c8_b_B;
    c8_i2 = c8_i2 + 4;
  }

  c8_B = c8_norm(chartInstance, c8_x1);
  for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
    c8_b_x2[c8_i2] = c8_x2[c8_i2] - c8_x4[c8_i2];
  }

  c8_b_B = c8_norm(chartInstance, c8_b_x2);
  for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
    c8_x1[c8_i2] = (c8_b_x1[c8_i2] - c8_x3[c8_i2]) / c8_B + (c8_x2[c8_i2] -
      c8_x4[c8_i2]) / c8_b_B;
  }

  /*  r1=(( x1-x3 )/norm( x1-x3 ) + ( x2-x4 )) */
  c8_norm(chartInstance, c8_x1);

  /* SKEW Create skew-symmetric matrix */
  /*  */
  /*  S = SKEW(V) is a skew-symmetric matrix formed from V (3x1). */
  /*  */
  /*            | 0   -vz  vy| */
  /*            | vz   0  -vx| */
  /*            |-vy   vx  0 | */
  /*  */
  /*  See also VEX. */
  /*  Copyright (C) 1993-2011, by Peter I. Corke */
  /*  */
  /*  This file is part of The Robotics Toolbox for Matlab (RTB). */
  /*   */
  /*  RTB is free software: you can redistribute it and/or modify */
  /*  it under the terms of the GNU Lesser General Public License as published by */
  /*  the Free Software Foundation, either version 3 of the License, or */
  /*  (at your option) any later version. */
  /*   */
  /*  RTB is distributed in the hope that it will be useful, */
  /*  but WITHOUT ANY WARRANTY; without even the implied warranty of */
  /*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
  /*  GNU Lesser General Public License for more details. */
  /*   */
  /*  You should have received a copy of the GNU Leser General Public License */
  /*  along with RTB.  If not, see <http://www.gnu.org/licenses/>. */
  /*  SO(3) case */
  c8_partial_r1__term2_x1x3[0] = 0.0;
  for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
    c8_b_x2[c8_i2] = c8_b_x1[c8_i2] - c8_x3[c8_i2];
    c8_c_x2[c8_i2] = c8_x2[c8_i2] - c8_x4[c8_i2];
  }

  c8_partial_r1__term2_x1x3[3] = -c8_b_x2[2];
  c8_partial_r1__term2_x1x3[6] = c8_b_x2[1];
  c8_partial_r1__term2_x1x3[1] = c8_b_x2[2];
  c8_partial_r1__term2_x1x3[4] = 0.0;
  c8_partial_r1__term2_x1x3[7] = -c8_b_x2[0];
  c8_partial_r1__term2_x1x3[2] = -c8_b_x2[1];
  c8_partial_r1__term2_x1x3[5] = c8_b_x2[0];
  c8_partial_r1__term2_x1x3[8] = 0.0;
  for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
    c8_dv1[c8_i2] = 0.0;
    c8_i3 = 0;
    for (c8_i4 = 0; c8_i4 < 3; c8_i4 = c8_i4 + 1) {
      c8_dv1[c8_i2] = c8_dv1[c8_i2] + c8_partial_r1__term2_x1x3[c8_i3 + c8_i2] *
        c8_c_x2[c8_i4];
      c8_i3 = c8_i3 + 3;
    }
  }

  c8_norm(chartInstance, c8_dv1);

  /*  RO=[r1_unit r2_unit r3_unit]; */
  /*  partial_r1__term1 = (((norm(r1)^2)*eye(3)-(r1)*(r1)') / (norm((r1))^3)); */
  /* SKEW Create skew-symmetric matrix */
  /*  */
  /*  S = SKEW(V) is a skew-symmetric matrix formed from V (3x1). */
  /*  */
  /*            | 0   -vz  vy| */
  /*            | vz   0  -vx| */
  /*            |-vy   vx  0 | */
  /*  */
  /*  See also VEX. */
  /*  Copyright (C) 1993-2011, by Peter I. Corke */
  /*  */
  /*  This file is part of The Robotics Toolbox for Matlab (RTB). */
  /*   */
  /*  RTB is free software: you can redistribute it and/or modify */
  /*  it under the terms of the GNU Lesser General Public License as published by */
  /*  the Free Software Foundation, either version 3 of the License, or */
  /*  (at your option) any later version. */
  /*   */
  /*  RTB is distributed in the hope that it will be useful, */
  /*  but WITHOUT ANY WARRANTY; without even the implied warranty of */
  /*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
  /*  GNU Lesser General Public License for more details. */
  /*   */
  /*  You should have received a copy of the GNU Leser General Public License */
  /*  along with RTB.  If not, see <http://www.gnu.org/licenses/>. */
  /*  SO(3) case */
  c8_B = c8_norm(chartInstance, c8_x1);
  c8_B = muDoubleScalarPower(c8_B, 3.0);
  c8_partial_r1__term2_x2x4[0] = 0.0;
  c8_partial_r1__term2_x2x4[3] = -c8_x1[2];
  c8_partial_r1__term2_x2x4[6] = c8_x1[1];
  c8_partial_r1__term2_x2x4[1] = c8_x1[2];
  c8_partial_r1__term2_x2x4[4] = 0.0;
  c8_partial_r1__term2_x2x4[7] = -c8_x1[0];
  c8_partial_r1__term2_x2x4[2] = -c8_x1[1];
  c8_partial_r1__term2_x2x4[5] = c8_x1[0];
  c8_partial_r1__term2_x2x4[8] = 0.0;
  c8_mpower(chartInstance, c8_partial_r1__term2_x2x4, c8_hoistedExpr);
  for (c8_i2 = 0; c8_i2 < 9; c8_i2 = c8_i2 + 1) {
    c8_hoistedExpr[c8_i2] = (-c8_hoistedExpr[c8_i2]) / c8_B;
  }

  for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
    c8_x1[c8_i2] = c8_b_x1[c8_i2] - c8_x3[c8_i2];
  }

  c8_B = c8_norm(chartInstance, c8_x1);
  c8_b_B = muDoubleScalarPower(c8_B, 2.0);
  for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
    c8_b_x2[c8_i2] = c8_b_x1[c8_i2] - c8_x3[c8_i2];
  }

  c8_B = c8_norm(chartInstance, c8_b_x2);
  c8_B = muDoubleScalarPower(c8_B, 3.0);
  for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
    c8_x1[c8_i2] = c8_b_x1[c8_i2] - c8_x3[c8_i2];
    c8_b_x2[c8_i2] = c8_b_x1[c8_i2] - c8_x3[c8_i2];
  }

  c8_i2 = 0;
  for (c8_i3 = 0; c8_i3 < 3; c8_i3 = c8_i3 + 1) {
    for (c8_i4 = 0; c8_i4 < 3; c8_i4 = c8_i4 + 1) {
      c8_partial_r1__term2_x1x3[c8_i4 + c8_i2] = (c8_b_B * (real_T)c8_iv0[c8_i4
        + c8_i2] - c8_x1[c8_i4] * c8_b_x2[c8_i3]) / c8_B;
    }

    c8_i2 = c8_i2 + 3;
  }

  for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
    c8_x1[c8_i2] = c8_x2[c8_i2] - c8_x4[c8_i2];
  }

  c8_B = c8_norm(chartInstance, c8_x1);
  c8_b_B = muDoubleScalarPower(c8_B, 2.0);
  for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
    c8_x1[c8_i2] = c8_x2[c8_i2] - c8_x4[c8_i2];
  }

  c8_B = c8_norm(chartInstance, c8_x1);
  c8_B = muDoubleScalarPower(c8_B, 3.0);
  for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
    c8_x1[c8_i2] = c8_x2[c8_i2] - c8_x4[c8_i2];
    c8_b_x2[c8_i2] = c8_x2[c8_i2] - c8_x4[c8_i2];
  }

  c8_i2 = 0;
  for (c8_i3 = 0; c8_i3 < 3; c8_i3 = c8_i3 + 1) {
    for (c8_i4 = 0; c8_i4 < 3; c8_i4 = c8_i4 + 1) {
      c8_partial_r1__term2_x2x4[c8_i4 + c8_i2] = (c8_b_B * (real_T)c8_iv0[c8_i4
        + c8_i2] - c8_x1[c8_i4] * c8_b_x2[c8_i3]) / c8_B;
    }

    c8_i2 = c8_i2 + 3;
  }

  /*  J_r1_x1 = [partial_r1__term1.*partial_r1__term2_x1x3.*partial_r1__term3_x1x2(:,1), ... */
  /*             partial_r1__term1.*partial_r1__term2_x1x3.*partial_r1__term3_x1x2(:,2), ... */
  /*             partial_r1__term1.*partial_r1__term2_x1x3.*partial_r1__term3_x1x2(:,3)]; */
  /*   */
  /*  J_r1_x2 = [partial_r1__term1.*partial_r1__term2_x2x4.*partial_r1__term3_x1x2(:,1), ... */
  /*             partial_r1__term1.*partial_r1__term2_x2x4.*partial_r1__term3_x1x2(:,2), ... */
  /*             partial_r1__term1.*partial_r1__term2_x2x4.*partial_r1__term3_x1x2(:,3)]; */
  /*          */
  /*  J_r1_x3 = [partial_r1__term1.*partial_r1__term2_x1x3.*partial_r1__term3_x3x4(:,1), ... */
  /*             partial_r1__term1.*partial_r1__term2_x1x3.*partial_r1__term3_x3x4(:,2), ... */
  /*             partial_r1__term1.*partial_r1__term2_x1x3.*partial_r1__term3_x3x4(:,3)]; */
  /*          */
  /*  J_r1_x4 = [partial_r1__term1.*partial_r1__term2_x2x4.*partial_r1__term3_x3x4(:,1), ... */
  /*             partial_r1__term1.*partial_r1__term2_x2x4.*partial_r1__term3_x3x4(:,2), ... */
  /*             partial_r1__term1.*partial_r1__term2_x2x4.*partial_r1__term3_x3x4(:,3)]; */
  for (c8_i4 = 0; c8_i4 < 3; c8_i4 = c8_i4 + 1) {
    for (c8_i3 = 0; c8_i3 < 3; c8_i3 = c8_i3 + 1) {
      c8_b_hoistedExpr[c8_i4 + 3 * c8_i3] = 0.0;
      for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
        c8_b_hoistedExpr[c8_i4 + 3 * c8_i3] = c8_b_hoistedExpr[c8_i4 + 3 * c8_i3]
          + c8_hoistedExpr[c8_i4 + 3 * c8_i2] *
          c8_partial_r1__term2_x1x3[c8_i2 + 3 * c8_i3];
      }

      c8_c_hoistedExpr[c8_i4 + 3 * c8_i3] = 0.0;
      for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
        c8_c_hoistedExpr[c8_i4 + 3 * c8_i3] = c8_c_hoistedExpr[c8_i4 + 3 * c8_i3]
          + c8_hoistedExpr[c8_i4 + 3 * c8_i2] *
          c8_partial_r1__term2_x2x4[c8_i2 + 3 * c8_i3];
      }

      c8_d_hoistedExpr[c8_i4 + 3 * c8_i3] = 0.0;
      for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
        c8_d_hoistedExpr[c8_i4 + 3 * c8_i3] = c8_d_hoistedExpr[c8_i4 + 3 * c8_i3]
          + c8_hoistedExpr[c8_i4 + 3 * c8_i2] *
          c8_partial_r1__term2_x1x3[c8_i2 + 3 * c8_i3];
      }

      c8_e_hoistedExpr[c8_i4 + 3 * c8_i3] = 0.0;
      for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
        c8_e_hoistedExpr[c8_i4 + 3 * c8_i3] = c8_e_hoistedExpr[c8_i4 + 3 * c8_i3]
          + c8_hoistedExpr[c8_i4 + 3 * c8_i2] *
          c8_partial_r1__term2_x2x4[c8_i2 + 3 * c8_i3];
      }
    }

    for (c8_i3 = 0; c8_i3 < 3; c8_i3 = c8_i3 + 1) {
      c8_f_hoistedExpr[c8_i4 + 3 * c8_i3] = 0.0;
      for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
        c8_f_hoistedExpr[c8_i4 + 3 * c8_i3] = c8_f_hoistedExpr[c8_i4 + 3 * c8_i3]
          + c8_b_hoistedExpr[c8_i4 + 3 * c8_i2] * (real_T)c8_iv0[
          c8_i2 + 3 * c8_i3];
      }

      c8_g_hoistedExpr[c8_i4 + 3 * c8_i3] = 0.0;
      for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
        c8_g_hoistedExpr[c8_i4 + 3 * c8_i3] = c8_g_hoistedExpr[c8_i4 + 3 * c8_i3]
          + c8_c_hoistedExpr[c8_i4 + 3 * c8_i2] * (real_T)c8_iv0[
          c8_i2 + 3 * c8_i3];
      }

      c8_h_hoistedExpr[c8_i4 + 3 * c8_i3] = 0.0;
      for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
        c8_h_hoistedExpr[c8_i4 + 3 * c8_i3] = c8_h_hoistedExpr[c8_i4 + 3 * c8_i3]
          + c8_d_hoistedExpr[c8_i4 + 3 * c8_i2] * (real_T)c8_iv1[
          c8_i2 + 3 * c8_i3];
      }

      c8_i_hoistedExpr[c8_i4 + 3 * c8_i3] = 0.0;
      for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
        c8_i_hoistedExpr[c8_i4 + 3 * c8_i3] = c8_i_hoistedExpr[c8_i4 + 3 * c8_i3]
          + c8_e_hoistedExpr[c8_i4 + 3 * c8_i2] * (real_T)c8_iv1[
          c8_i2 + 3 * c8_i3];
      }
    }
  }

  c8_i2 = 0;
  for (c8_i3 = 0; c8_i3 < 3; c8_i3 = c8_i3 + 1) {
    for (c8_i4 = 0; c8_i4 < 3; c8_i4 = c8_i4 + 1) {
      (*c8_J_r1)[c8_i4 + c8_i2] = c8_f_hoistedExpr[c8_i4 + c8_i2];
    }

    c8_i2 = c8_i2 + 3;
  }

  c8_i2 = 0;
  for (c8_i3 = 0; c8_i3 < 3; c8_i3 = c8_i3 + 1) {
    for (c8_i4 = 0; c8_i4 < 3; c8_i4 = c8_i4 + 1) {
      (*c8_J_r1)[(c8_i4 + c8_i2) + 9] = c8_g_hoistedExpr[c8_i4 + c8_i2];
    }

    c8_i2 = c8_i2 + 3;
  }

  c8_i2 = 0;
  for (c8_i3 = 0; c8_i3 < 3; c8_i3 = c8_i3 + 1) {
    for (c8_i4 = 0; c8_i4 < 3; c8_i4 = c8_i4 + 1) {
      (*c8_J_r1)[(c8_i4 + c8_i2) + 18] = c8_h_hoistedExpr[c8_i4 + c8_i2];
    }

    c8_i2 = c8_i2 + 3;
  }

  c8_i2 = 0;
  for (c8_i3 = 0; c8_i3 < 3; c8_i3 = c8_i3 + 1) {
    for (c8_i4 = 0; c8_i4 < 3; c8_i4 = c8_i4 + 1) {
      (*c8_J_r1)[(c8_i4 + c8_i2) + 27] = c8_i_hoistedExpr[c8_i4 + c8_i2];
    }

    c8_i2 = c8_i2 + 3;
  }

  _sfEvent_ = c8_previousEvent;
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static real_T c8_norm(SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct
                      *chartInstance, real_T c8_x[3])
{
  return c8_ceval_xnrm2(chartInstance, 3, c8_x, 1, 1);
}

static real_T c8_ceval_xnrm2(SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c8_n, real_T c8_x[3], int32_T
  c8_ix0, int32_T c8_incx)
{
  return dnrm232(&c8_n, &c8_x[sf_mex_lw_bounds_check(c8_ix0, 1, 3) - 1],
                 &c8_incx);
}

static void c8_mpower(SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct
                      *chartInstance, real_T c8_a[9], real_T c8_c[9])
{
  int32_T c8_i5;
  real_T c8_b_a[9];
  real_T c8_e;
  boolean_T c8_firstmult;
  int32_T c8_exitg1;
  real_T c8_ed2;
  int32_T c8_i6;
  int32_T c8_i7;
  real_T c8_b_c[9];
  int32_T c8_i8;
  int32_T c8_i9;
  for (c8_i5 = 0; c8_i5 < 9; c8_i5 = c8_i5 + 1) {
    c8_b_a[c8_i5] = c8_a[c8_i5];
  }

  c8_e = 2.0;
  c8_firstmult = TRUE;
  do {
    c8_exitg1 = 0U;
    c8_ed2 = muDoubleScalarFloor(c8_e / 2.0);
    if (2.0 * c8_ed2 != c8_e) {
      if (c8_firstmult) {
        c8_i5 = 0;
        for (c8_i6 = 0; c8_i6 < 3; c8_i6 = c8_i6 + 1) {
          for (c8_i7 = 0; c8_i7 < 3; c8_i7 = c8_i7 + 1) {
            c8_c[c8_i7 + c8_i5] = c8_b_a[c8_i7 + c8_i5];
          }

          c8_i5 = c8_i5 + 3;
        }

        c8_firstmult = FALSE;
      } else {
        for (c8_i5 = 0; c8_i5 < 3; c8_i5 = c8_i5 + 1) {
          c8_i6 = 0;
          for (c8_i7 = 0; c8_i7 < 3; c8_i7 = c8_i7 + 1) {
            c8_b_c[c8_i6 + c8_i5] = 0.0;
            c8_i8 = 0;
            for (c8_i9 = 0; c8_i9 < 3; c8_i9 = c8_i9 + 1) {
              c8_b_c[c8_i6 + c8_i5] = c8_b_c[c8_i6 + c8_i5] + c8_c[c8_i8 + c8_i5]
                * c8_b_a[c8_i9 + c8_i6];
              c8_i8 = c8_i8 + 3;
            }

            c8_i6 = c8_i6 + 3;
          }
        }

        c8_i5 = 0;
        for (c8_i6 = 0; c8_i6 < 3; c8_i6 = c8_i6 + 1) {
          for (c8_i7 = 0; c8_i7 < 3; c8_i7 = c8_i7 + 1) {
            c8_c[c8_i7 + c8_i5] = c8_b_c[c8_i7 + c8_i5];
          }

          c8_i5 = c8_i5 + 3;
        }
      }
    }

    if (c8_ed2 == 0.0) {
      c8_exitg1 = 1U;
    } else {
      c8_e = c8_ed2;
      for (c8_i5 = 0; c8_i5 < 3; c8_i5 = c8_i5 + 1) {
        c8_i6 = 0;
        for (c8_i7 = 0; c8_i7 < 3; c8_i7 = c8_i7 + 1) {
          c8_b_c[c8_i6 + c8_i5] = 0.0;
          c8_i8 = 0;
          for (c8_i9 = 0; c8_i9 < 3; c8_i9 = c8_i9 + 1) {
            c8_b_c[c8_i6 + c8_i5] = c8_b_c[c8_i6 + c8_i5] + c8_b_a[c8_i8 + c8_i5]
              * c8_b_a[c8_i9 + c8_i6];
            c8_i8 = c8_i8 + 3;
          }

          c8_i6 = c8_i6 + 3;
        }
      }

      c8_i5 = 0;
      for (c8_i6 = 0; c8_i6 < 3; c8_i6 = c8_i6 + 1) {
        for (c8_i7 = 0; c8_i7 < 3; c8_i7 = c8_i7 + 1) {
          c8_b_a[c8_i7 + c8_i5] = c8_b_c[c8_i7 + c8_i5];
        }

        c8_i5 = c8_i5 + 3;
      }
    }
  } while (c8_exitg1 == 0U);
}

const mxArray *sf_c8_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[78];
  c8_ResolvedFunctionInfo (*c8_b_info)[78];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i10;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  c8_b_info = (c8_ResolvedFunctionInfo (*)[78])c8_info;
  (*c8_b_info)[64].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  (*c8_b_info)[64].name = "inf";
  (*c8_b_info)[64].dominantType = "";
  (*c8_b_info)[64].resolved = "[B]inf";
  (*c8_b_info)[64].fileLength = 0U;
  (*c8_b_info)[64].fileTime1 = 0U;
  (*c8_b_info)[64].fileTime2 = 0U;
  (*c8_b_info)[65].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/mat1norm";
  (*c8_b_info)[65].name = "eml_guarded_nan";
  (*c8_b_info)[65].dominantType = "char";
  (*c8_b_info)[65].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  (*c8_b_info)[65].fileLength = 485U;
  (*c8_b_info)[65].fileTime1 = 1192463180U;
  (*c8_b_info)[65].fileTime2 = 0U;
  (*c8_b_info)[66].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  (*c8_b_info)[66].name = "eml_is_float_class";
  (*c8_b_info)[66].dominantType = "char";
  (*c8_b_info)[66].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  (*c8_b_info)[66].fileLength = 226U;
  (*c8_b_info)[66].fileTime1 = 1197846840U;
  (*c8_b_info)[66].fileTime2 = 0U;
  (*c8_b_info)[67].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  (*c8_b_info)[67].name = "nan";
  (*c8_b_info)[67].dominantType = "char";
  (*c8_b_info)[67].resolved = "[B]nan";
  (*c8_b_info)[67].fileLength = 0U;
  (*c8_b_info)[67].fileTime1 = 0U;
  (*c8_b_info)[67].fileTime2 = 0U;
  (*c8_b_info)[68].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/checkcond";
  (*c8_b_info)[68].name = "eml_warning";
  (*c8_b_info)[68].dominantType = "char";
  (*c8_b_info)[68].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  (*c8_b_info)[68].fileLength = 262U;
  (*c8_b_info)[68].fileTime1 = 1236253678U;
  (*c8_b_info)[68].fileTime2 = 0U;
  (*c8_b_info)[69].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/checkcond";
  (*c8_b_info)[69].name = "eps";
  (*c8_b_info)[69].dominantType = "char";
  (*c8_b_info)[69].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c8_b_info)[69].fileLength = 1331U;
  (*c8_b_info)[69].fileTime1 = 1246279786U;
  (*c8_b_info)[69].fileTime2 = 0U;
  (*c8_b_info)[70].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c8_b_info)[70].name = "power";
  (*c8_b_info)[70].dominantType = "double";
  (*c8_b_info)[70].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c8_b_info)[70].fileLength = 5380U;
  (*c8_b_info)[70].fileTime1 = 1228090298U;
  (*c8_b_info)[70].fileTime2 = 0U;
  (*c8_b_info)[71].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c8_b_info)[71].name = "eml_error";
  (*c8_b_info)[71].dominantType = "char";
  (*c8_b_info)[71].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c8_b_info)[71].fileLength = 315U;
  (*c8_b_info)[71].fileTime1 = 1213923144U;
  (*c8_b_info)[71].fileTime2 = 0U;
  (*c8_b_info)[72].context = "";
  (*c8_b_info)[72].name = "eye";
  (*c8_b_info)[72].dominantType = "double";
  (*c8_b_info)[72].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  (*c8_b_info)[72].fileLength = 1765U;
  (*c8_b_info)[72].fileTime1 = 1219749288U;
  (*c8_b_info)[72].fileTime2 = 0U;
  (*c8_b_info)[73].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  (*c8_b_info)[73].name = "eml_assert_valid_size_arg";
  (*c8_b_info)[73].dominantType = "double";
  (*c8_b_info)[73].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  (*c8_b_info)[73].fileLength = 3315U;
  (*c8_b_info)[73].fileTime1 = 1256041632U;
  (*c8_b_info)[73].fileTime2 = 0U;
  (*c8_b_info)[74].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  (*c8_b_info)[74].name = "isinf";
  (*c8_b_info)[74].dominantType = "double";
  (*c8_b_info)[74].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  (*c8_b_info)[74].fileLength = 506U;
  (*c8_b_info)[74].fileTime1 = 1228090208U;
  (*c8_b_info)[74].fileTime2 = 0U;
  (*c8_b_info)[75].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  (*c8_b_info)[75].name = "double";
  (*c8_b_info)[75].dominantType = "double";
  (*c8_b_info)[75].resolved = "[B]double";
  (*c8_b_info)[75].fileLength = 0U;
  (*c8_b_info)[75].fileTime1 = 0U;
  (*c8_b_info)[75].fileTime2 = 0U;
  (*c8_b_info)[76].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  (*c8_b_info)[76].name = "intmax";
  (*c8_b_info)[76].dominantType = "char";
  (*c8_b_info)[76].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  (*c8_b_info)[76].fileLength = 1535U;
  (*c8_b_info)[76].fileTime1 = 1192463128U;
  (*c8_b_info)[76].fileTime2 = 0U;
  (*c8_b_info)[77].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  (*c8_b_info)[77].name = "int32";
  (*c8_b_info)[77].dominantType = "double";
  (*c8_b_info)[77].resolved = "[B]int32";
  (*c8_b_info)[77].fileLength = 0U;
  (*c8_b_info)[77].fileTime1 = 0U;
  (*c8_b_info)[77].fileTime2 = 0U;
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 78));
  for (c8_i10 = 0; c8_i10 < 78; c8_i10 = c8_i10 + 1) {
    c8_r0 = &c8_info[c8_i10];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c8_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c8_r0->context)), "context", "nameCaptureInfo", c8_i10);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c8_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)c8_r0
      ->name)), "name", "nameCaptureInfo", c8_i10);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c8_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const char
      *)c8_r0->dominantType)), "dominantType", "nameCaptureInfo", c8_i10);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c8_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c8_r0->resolved)), "resolved", "nameCaptureInfo", c8_i10);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c8_i10);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c8_i10
                    );
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c8_i10
                    );
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[78])
{
  c8_info[0].context = "";
  c8_info[0].name = "ctranspose";
  c8_info[0].dominantType = "double";
  c8_info[0].resolved = "[B]ctranspose";
  c8_info[0].fileLength = 0U;
  c8_info[0].fileTime1 = 0U;
  c8_info[0].fileTime2 = 0U;
  c8_info[1].context = "";
  c8_info[1].name = "minus";
  c8_info[1].dominantType = "double";
  c8_info[1].resolved = "[B]minus";
  c8_info[1].fileLength = 0U;
  c8_info[1].fileTime1 = 0U;
  c8_info[1].fileTime2 = 0U;
  c8_info[2].context = "";
  c8_info[2].name = "norm";
  c8_info[2].dominantType = "double";
  c8_info[2].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[2].fileLength = 5312U;
  c8_info[2].fileTime1 = 1262616676U;
  c8_info[2].fileTime2 = 0U;
  c8_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[3].name = "nargin";
  c8_info[3].dominantType = "";
  c8_info[3].resolved = "[B]nargin";
  c8_info[3].fileLength = 0U;
  c8_info[3].fileTime1 = 0U;
  c8_info[3].fileTime2 = 0U;
  c8_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[4].name = "gt";
  c8_info[4].dominantType = "double";
  c8_info[4].resolved = "[B]gt";
  c8_info[4].fileLength = 0U;
  c8_info[4].fileTime1 = 0U;
  c8_info[4].fileTime2 = 0U;
  c8_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[5].name = "isa";
  c8_info[5].dominantType = "double";
  c8_info[5].resolved = "[B]isa";
  c8_info[5].fileLength = 0U;
  c8_info[5].fileTime1 = 0U;
  c8_info[5].fileTime2 = 0U;
  c8_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[6].name = "ndims";
  c8_info[6].dominantType = "double";
  c8_info[6].resolved = "[B]ndims";
  c8_info[6].fileLength = 0U;
  c8_info[6].fileTime1 = 0U;
  c8_info[6].fileTime2 = 0U;
  c8_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[7].name = "le";
  c8_info[7].dominantType = "double";
  c8_info[7].resolved = "[B]le";
  c8_info[7].fileLength = 0U;
  c8_info[7].fileTime1 = 0U;
  c8_info[7].fileTime2 = 0U;
  c8_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[8].name = "eq";
  c8_info[8].dominantType = "double";
  c8_info[8].resolved = "[B]eq";
  c8_info[8].fileLength = 0U;
  c8_info[8].fileTime1 = 0U;
  c8_info[8].fileTime2 = 0U;
  c8_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[9].name = "lt";
  c8_info[9].dominantType = "double";
  c8_info[9].resolved = "[B]lt";
  c8_info[9].fileLength = 0U;
  c8_info[9].fileTime1 = 0U;
  c8_info[9].fileTime2 = 0U;
  c8_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[10].name = "size";
  c8_info[10].dominantType = "double";
  c8_info[10].resolved = "[B]size";
  c8_info[10].fileLength = 0U;
  c8_info[10].fileTime1 = 0U;
  c8_info[10].fileTime2 = 0U;
  c8_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[11].name = "isempty";
  c8_info[11].dominantType = "double";
  c8_info[11].resolved = "[B]isempty";
  c8_info[11].fileLength = 0U;
  c8_info[11].fileTime1 = 0U;
  c8_info[11].fileTime2 = 0U;
  c8_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[12].name = "isscalar";
  c8_info[12].dominantType = "double";
  c8_info[12].resolved = "[B]isscalar";
  c8_info[12].fileLength = 0U;
  c8_info[12].fileTime1 = 0U;
  c8_info[12].fileTime2 = 0U;
  c8_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[13].name = "isvector";
  c8_info[13].dominantType = "double";
  c8_info[13].resolved = "[B]isvector";
  c8_info[13].fileLength = 0U;
  c8_info[13].fileTime1 = 0U;
  c8_info[13].fileTime2 = 0U;
  c8_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c8_info[14].name = "eml_index_class";
  c8_info[14].dominantType = "";
  c8_info[14].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[14].fileLength = 909U;
  c8_info[14].fileTime1 = 1192463182U;
  c8_info[14].fileTime2 = 0U;
  c8_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c8_info[15].name = "ones";
  c8_info[15].dominantType = "char";
  c8_info[15].resolved = "[B]ones";
  c8_info[15].fileLength = 0U;
  c8_info[15].fileTime1 = 0U;
  c8_info[15].fileTime2 = 0U;
  c8_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c8_info[16].name = "ischar";
  c8_info[16].dominantType = "double";
  c8_info[16].resolved = "[B]ischar";
  c8_info[16].fileLength = 0U;
  c8_info[16].fileTime1 = 0U;
  c8_info[16].fileTime2 = 0U;
  c8_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c8_info[17].name = "eml_xnrm2";
  c8_info[17].dominantType = "int32";
  c8_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c8_info[17].fileLength = 718U;
  c8_info[17].fileTime1 = 1209327256U;
  c8_info[17].fileTime2 = 0U;
  c8_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_use_refblas.m";
  c8_info[18].name = "strcmp";
  c8_info[18].dominantType = "char";
  c8_info[18].resolved = "[B]strcmp";
  c8_info[18].fileLength = 0U;
  c8_info[18].fileTime1 = 0U;
  c8_info[18].fileTime2 = 0U;
  c8_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c8_info[19].name = "cast";
  c8_info[19].dominantType = "double";
  c8_info[19].resolved = "[B]cast";
  c8_info[19].fileLength = 0U;
  c8_info[19].fileTime1 = 0U;
  c8_info[19].fileTime2 = 0U;
  c8_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c8_info[20].name = "eml_refblas_xnrm2";
  c8_info[20].dominantType = "int32";
  c8_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[20].fileLength = 1433U;
  c8_info[20].fileTime1 = 1240258442U;
  c8_info[20].fileTime2 = 0U;
  c8_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[21].name = "class";
  c8_info[21].dominantType = "double";
  c8_info[21].resolved = "[B]class";
  c8_info[21].fileLength = 0U;
  c8_info[21].fileTime1 = 0U;
  c8_info[21].fileTime2 = 0U;
  c8_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[22].name = "zeros";
  c8_info[22].dominantType = "char";
  c8_info[22].resolved = "[B]zeros";
  c8_info[22].fileLength = 0U;
  c8_info[22].fileTime1 = 0U;
  c8_info[22].fileTime2 = 0U;
  c8_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[23].name = "true";
  c8_info[23].dominantType = "";
  c8_info[23].resolved = "[B]true";
  c8_info[23].fileLength = 0U;
  c8_info[23].fileTime1 = 0U;
  c8_info[23].fileTime2 = 0U;
  c8_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[24].name = "eml_index_minus";
  c8_info[24].dominantType = "int32";
  c8_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[24].fileLength = 277U;
  c8_info[24].fileTime1 = 1192463184U;
  c8_info[24].fileTime2 = 0U;
  c8_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[25].name = "eml_index_times";
  c8_info[25].dominantType = "int32";
  c8_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[25].fileLength = 280U;
  c8_info[25].fileTime1 = 1192463186U;
  c8_info[25].fileTime2 = 0U;
  c8_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[26].name = "eml_index_plus";
  c8_info[26].dominantType = "int32";
  c8_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[26].fileLength = 272U;
  c8_info[26].fileTime1 = 1192463184U;
  c8_info[26].fileTime2 = 0U;
  c8_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[27].name = "real";
  c8_info[27].dominantType = "double";
  c8_info[27].resolved = "[B]real";
  c8_info[27].fileLength = 0U;
  c8_info[27].fileTime1 = 0U;
  c8_info[27].fileTime2 = 0U;
  c8_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[28].name = "ne";
  c8_info[28].dominantType = "double";
  c8_info[28].resolved = "[B]ne";
  c8_info[28].fileLength = 0U;
  c8_info[28].fileTime1 = 0U;
  c8_info[28].fileTime2 = 0U;
  c8_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[29].name = "abs";
  c8_info[29].dominantType = "double";
  c8_info[29].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[29].fileLength = 566U;
  c8_info[29].fileTime1 = 1221263532U;
  c8_info[29].fileTime2 = 0U;
  c8_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[30].name = "islogical";
  c8_info[30].dominantType = "double";
  c8_info[30].resolved = "[B]islogical";
  c8_info[30].fileLength = 0U;
  c8_info[30].fileTime1 = 0U;
  c8_info[30].fileTime2 = 0U;
  c8_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[31].name = "eml_scalar_abs";
  c8_info[31].dominantType = "double";
  c8_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[31].fileLength = 461U;
  c8_info[31].fileTime1 = 1203444360U;
  c8_info[31].fileTime2 = 0U;
  c8_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[32].name = "isinteger";
  c8_info[32].dominantType = "double";
  c8_info[32].resolved = "[B]isinteger";
  c8_info[32].fileLength = 0U;
  c8_info[32].fileTime1 = 0U;
  c8_info[32].fileTime2 = 0U;
  c8_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[33].name = "isreal";
  c8_info[33].dominantType = "double";
  c8_info[33].resolved = "[B]isreal";
  c8_info[33].fileLength = 0U;
  c8_info[33].fileTime1 = 0U;
  c8_info[33].fileTime2 = 0U;
  c8_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[34].name = "false";
  c8_info[34].dominantType = "";
  c8_info[34].resolved = "[B]false";
  c8_info[34].fileLength = 0U;
  c8_info[34].fileTime1 = 0U;
  c8_info[34].fileTime2 = 0U;
  c8_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[35].name = "times";
  c8_info[35].dominantType = "double";
  c8_info[35].resolved = "[B]times";
  c8_info[35].fileLength = 0U;
  c8_info[35].fileTime1 = 0U;
  c8_info[35].fileTime2 = 0U;
  c8_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[36].name = "plus";
  c8_info[36].dominantType = "double";
  c8_info[36].resolved = "[B]plus";
  c8_info[36].fileLength = 0U;
  c8_info[36].fileTime1 = 0U;
  c8_info[36].fileTime2 = 0U;
  c8_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[37].name = "imag";
  c8_info[37].dominantType = "double";
  c8_info[37].resolved = "[B]imag";
  c8_info[37].fileLength = 0U;
  c8_info[37].fileTime1 = 0U;
  c8_info[37].fileTime2 = 0U;
  c8_info[38].context = "";
  c8_info[38].name = "mrdivide";
  c8_info[38].dominantType = "double";
  c8_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c8_info[38].fileLength = 800U;
  c8_info[38].fileTime1 = 1238430690U;
  c8_info[38].fileTime2 = 0U;
  c8_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c8_info[39].name = "ge";
  c8_info[39].dominantType = "double";
  c8_info[39].resolved = "[B]ge";
  c8_info[39].fileLength = 0U;
  c8_info[39].fileTime1 = 0U;
  c8_info[39].fileTime2 = 0U;
  c8_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c8_info[40].name = "rdivide";
  c8_info[40].dominantType = "double";
  c8_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[40].fileLength = 403U;
  c8_info[40].fileTime1 = 1244731952U;
  c8_info[40].fileTime2 = 0U;
  c8_info[41].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[41].name = "eml_div";
  c8_info[41].dominantType = "double";
  c8_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[41].fileLength = 4269U;
  c8_info[41].fileTime1 = 1228090226U;
  c8_info[41].fileTime2 = 0U;
  c8_info[42].context = "";
  c8_info[42].name = "skew";
  c8_info[42].dominantType = "double";
  c8_info[42].resolved =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/skew.m";
  c8_info[42].fileLength = 1233U;
  c8_info[42].fileTime1 = 1348594888U;
  c8_info[42].fileTime2 = 0U;
  c8_info[43].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/skew.m";
  c8_info[43].name = "isvec";
  c8_info[43].dominantType = "double";
  c8_info[43].resolved =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/isvec.m";
  c8_info[43].fileLength = 1299U;
  c8_info[43].fileTime1 = 1348594888U;
  c8_info[43].fileTime2 = 0U;
  c8_info[44].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/isvec.m";
  c8_info[44].name = "length";
  c8_info[44].dominantType = "double";
  c8_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c8_info[44].fileLength = 326U;
  c8_info[44].fileTime1 = 1226573674U;
  c8_info[44].fileTime2 = 0U;
  c8_info[45].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/isvec.m";
  c8_info[45].name = "min";
  c8_info[45].dominantType = "double";
  c8_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[45].fileLength = 362U;
  c8_info[45].fileTime1 = 1244731952U;
  c8_info[45].fileTime2 = 0U;
  c8_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[46].name = "nargout";
  c8_info[46].dominantType = "";
  c8_info[46].resolved = "[B]nargout";
  c8_info[46].fileLength = 0U;
  c8_info[46].fileTime1 = 0U;
  c8_info[46].fileTime2 = 0U;
  c8_info[47].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[47].name = "eml_min_or_max";
  c8_info[47].dominantType = "char";
  c8_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c8_info[47].fileLength = 9969U;
  c8_info[47].fileTime1 = 1240258406U;
  c8_info[47].fileTime2 = 0U;
  c8_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c8_info[48].name = "isnumeric";
  c8_info[48].dominantType = "double";
  c8_info[48].resolved = "[B]isnumeric";
  c8_info[48].fileLength = 0U;
  c8_info[48].fileTime1 = 0U;
  c8_info[48].fileTime2 = 0U;
  c8_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c8_info[49].name = "eml_const_nonsingleton_dim";
  c8_info[49].dominantType = "double";
  c8_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c8_info[49].fileLength = 1473U;
  c8_info[49].fileTime1 = 1240258402U;
  c8_info[49].fileTime2 = 0U;
  c8_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m/local_const_nonsingleton_dim";
  c8_info[50].name = "not";
  c8_info[50].dominantType = "logical";
  c8_info[50].resolved = "[B]not";
  c8_info[50].fileLength = 0U;
  c8_info[50].fileTime1 = 0U;
  c8_info[50].fileTime2 = 0U;
  c8_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c8_info[51].name = "eml_scalar_eg";
  c8_info[51].dominantType = "double";
  c8_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[51].fileLength = 3068U;
  c8_info[51].fileTime1 = 1240258410U;
  c8_info[51].fileTime2 = 0U;
  c8_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[52].name = "isstruct";
  c8_info[52].dominantType = "double";
  c8_info[52].resolved = "[B]isstruct";
  c8_info[52].fileLength = 0U;
  c8_info[52].fileTime1 = 0U;
  c8_info[52].fileTime2 = 0U;
  c8_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c8_info[53].name = "isnan";
  c8_info[53].dominantType = "double";
  c8_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c8_info[53].fileLength = 506U;
  c8_info[53].fileTime1 = 1228090210U;
  c8_info[53].fileTime2 = 0U;
  c8_info[54].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/isvec.m";
  c8_info[54].name = "numel";
  c8_info[54].dominantType = "double";
  c8_info[54].resolved = "[B]numel";
  c8_info[54].fileLength = 0U;
  c8_info[54].fileTime1 = 0U;
  c8_info[54].fileTime2 = 0U;
  c8_info[55].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/isvec.m";
  c8_info[55].name = "logical";
  c8_info[55].dominantType = "logical";
  c8_info[55].resolved = "[B]logical";
  c8_info[55].fileLength = 0U;
  c8_info[55].fileTime1 = 0U;
  c8_info[55].fileTime2 = 0U;
  c8_info[56].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/skew.m";
  c8_info[56].name = "uminus";
  c8_info[56].dominantType = "double";
  c8_info[56].resolved = "[B]uminus";
  c8_info[56].fileLength = 0U;
  c8_info[56].fileTime1 = 0U;
  c8_info[56].fileTime2 = 0U;
  c8_info[57].context = "";
  c8_info[57].name = "mtimes";
  c8_info[57].dominantType = "double";
  c8_info[57].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[57].fileLength = 3425U;
  c8_info[57].fileTime1 = 1250669166U;
  c8_info[57].fileTime2 = 0U;
  c8_info[58].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[58].name = "eml_xgemm";
  c8_info[58].dominantType = "int32";
  c8_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c8_info[58].fileLength = 3184U;
  c8_info[58].fileTime1 = 1209327252U;
  c8_info[58].fileTime2 = 0U;
  c8_info[59].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c8_info[59].name = "eml_scalexp_alloc";
  c8_info[59].dominantType = "double";
  c8_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[59].fileLength = 808U;
  c8_info[59].fileTime1 = 1230491098U;
  c8_info[59].fileTime2 = 0U;
  c8_info[60].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c8_info[60].name = "eml_refblas_xgemm";
  c8_info[60].dominantType = "int32";
  c8_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[60].fileLength = 5748U;
  c8_info[60].fileTime1 = 1228090272U;
  c8_info[60].fileTime2 = 0U;
  c8_info[61].context = "";
  c8_info[61].name = "mpower";
  c8_info[61].dominantType = "double";
  c8_info[61].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c8_info[61].fileLength = 3710U;
  c8_info[61].fileTime1 = 1238430688U;
  c8_info[61].fileTime2 = 0U;
  c8_info[62].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c8_info[62].name = "eml_scalar_floor";
  c8_info[62].dominantType = "double";
  c8_info[62].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c8_info[62].fileLength = 260U;
  c8_info[62].fileTime1 = 1209327190U;
  c8_info[62].fileTime2 = 0U;
  c8_info[63].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m/matrix_to_integer_power";
  c8_info[63].name = "inv";
  c8_info[63].dominantType = "double";
  c8_info[63].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c8_info[63].fileLength = 4757U;
  c8_info[63].fileTime1 = 1251996502U;
  c8_info[63].fileTime2 = 0U;
}

static void c8_emlrt_marshallIn(SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, const mxArray *c8_J_r1, const char_T *
  c8_name, real_T c8_y[36])
{
  real_T c8_dv2[36];
  int32_T c8_i11;
  sf_mex_import(c8_name, sf_mex_dup(c8_J_r1), &c8_dv2, 1, 0, 0U, 1, 0U, 2, 3, 12);
  for (c8_i11 = 0; c8_i11 < 36; c8_i11 = c8_i11 + 1) {
    c8_y[c8_i11] = c8_dv2[c8_i11];
  }

  sf_mex_destroy(&c8_J_r1);
}

static uint8_T c8_b_emlrt_marshallIn
  (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c8_b_is_active_c8_ODE_Hand_Model_v08_IPC_v03, const char_T *c8_name)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_name, sf_mex_dup(c8_b_is_active_c8_ODE_Hand_Model_v08_IPC_v03),
                &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_b_is_active_c8_ODE_Hand_Model_v08_IPC_v03);
  return c8_y;
}

static void init_dsm_address_info(SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2139931622U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(364855985U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(217940558U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3953271522U);
}

mxArray *sf_c8_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2534517454U);
    pr[1] = (double)(2184529850U);
    pr[2] = (double)(2412190170U);
    pr[3] = (double)(1837034631U);
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

static mxArray *sf_get_sim_state_info_c8_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"J_r1\",},{M[8],M[0],T\"is_active_c8_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c8_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c8_ODE_Hand_Model_v08_IPC_v03
    ((SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c8_ODE_Hand_Model_v08_IPC_v03
    ((SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c8_ODE_Hand_Model_v08_IPC_v03
    ((SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c8_ODE_Hand_Model_v08_IPC_v03
    ((SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c8_ODE_Hand_Model_v08_IPC_v03
    ((SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c8_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_ODE_Hand_Model_v08_IPC_v03
    ((SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c8_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c8_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_ODE_Hand_Model_v08_IPC_v03
    ((SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c8_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c8_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c8_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c8_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c8_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_ODE_Hand_Model_v08_IPC_v03
      ((SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_ODE_Hand_Model_v08_IPC_v03
      ((SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",8,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",8,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",8,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(488535344U));
  ssSetChecksum1(S,(3944620691U));
  ssSetChecksum2(S,(1493416059U));
  ssSetChecksum3(S,(258738353U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",8);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc(sizeof
    (SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_ODE_Hand_Model_v08_IPC_v03;
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

void c8_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
