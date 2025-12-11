/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c1_ODE_Hand_Model_v08_IPC_v03.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static real_T c1_norm(SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct
                      *chartInstance, real_T c1_x[3]);
static real_T c1_ceval_xnrm2(SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[3], int32_T c1_ix0, int32_T c1_incx);
static real_T c1_b_ceval_xnrm2(SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[3], int32_T c1_ix0, int32_T c1_incx);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[61]);
static void c1_emlrt_marshallIn(SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, const mxArray *c1_RO, const char_T *c1_name, real_T c1_y[9]);
static uint8_T c1_b_emlrt_marshallIn
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray
   *c1_b_is_active_c1_ODE_Hand_Model_v08_IPC_v03, const char_T *c1_name);
static void init_dsm_address_info(SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[9];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_RO)[9];
  c1_RO = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2));
  for (c1_i0 = 0; c1_i0 < 9; c1_i0 = c1_i0 + 1) {
    c1_u[c1_i0] = (*c1_RO)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_u = chartInstance->c1_is_active_c1_ODE_Hand_Model_v08_IPC_v03;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[9];
  int32_T c1_i1;
  real_T (*c1_RO)[9];
  c1_RO = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "RO",
                      c1_dv0);
  for (c1_i1 = 0; c1_i1 < 9; c1_i1 = c1_i1 + 1) {
    (*c1_RO)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_ODE_Hand_Model_v08_IPC_v03 =
    c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1))
    , "is_active_c1_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c1_u);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c1_ODE_Hand_Model_v08_IPC_v03
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c1_previousEvent;
  int32_T c1_i2;
  int32_T c1_i3;
  real_T c1_B;
  real_T c1_x2[3];
  real_T c1_b_B;
  real_T c1_x4[3];
  real_T c1_x1[3];
  real_T c1_b_x1[3];
  real_T c1_x3[3];
  real_T c1_r1[3];
  real_T c1_dv1[9];
  real_T c1_r3[3];
  int32_T c1_i4;
  real_T (*c1_RO)[9];
  real_T (*c1_xi)[12];
  c1_RO = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_xi = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;

  /*  r1=( xi(1,:)-xi(3,:) )/norm( xi(1,:)-xi(3,:) ) + ... */
  /*      ( xi(2,:)-xi(4,:) )/norm( xi(2,:)-xi(4,:) ); */
  c1_i2 = 0;
  for (c1_i3 = 0; c1_i3 < 3; c1_i3 = c1_i3 + 1) {
    c1_B = (*c1_xi)[c1_i2];
    c1_x2[c1_i3] = (*c1_xi)[c1_i2 + 1];
    c1_b_B = (*c1_xi)[c1_i2 + 2];
    c1_x4[c1_i3] = (*c1_xi)[c1_i2 + 3];
    c1_x1[c1_i3] = c1_B - c1_b_B;
    c1_b_x1[c1_i3] = c1_B;
    c1_x3[c1_i3] = c1_b_B;
    c1_i2 = c1_i2 + 4;
  }

  c1_B = c1_norm(chartInstance, c1_x1);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2 = c1_i2 + 1) {
    c1_x1[c1_i2] = c1_x2[c1_i2] - c1_x4[c1_i2];
  }

  c1_b_B = c1_norm(chartInstance, c1_x1);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2 = c1_i2 + 1) {
    c1_r1[c1_i2] = (c1_b_x1[c1_i2] - c1_x3[c1_i2]) / c1_B + (c1_x2[c1_i2] -
      c1_x4[c1_i2]) / c1_b_B;
  }

  c1_B = c1_norm(chartInstance, c1_r1);

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
  c1_dv1[0] = 0.0;
  for (c1_i2 = 0; c1_i2 < 3; c1_i2 = c1_i2 + 1) {
    /*  r3= cross( (x1-x3),( x2-x4 ))'; */
    c1_x1[c1_i2] = c1_x2[c1_i2] - c1_x4[c1_i2];
    c1_b_x1[c1_i2] = c1_b_x1[c1_i2] - c1_x3[c1_i2];
    c1_r1[c1_i2] = c1_r1[c1_i2] / c1_B;
  }

  c1_dv1[3] = -c1_b_x1[2];
  c1_dv1[6] = c1_b_x1[1];
  c1_dv1[1] = c1_b_x1[2];
  c1_dv1[4] = 0.0;
  c1_dv1[7] = -c1_b_x1[0];
  c1_dv1[2] = -c1_b_x1[1];
  c1_dv1[5] = c1_b_x1[0];
  c1_dv1[8] = 0.0;
  for (c1_i2 = 0; c1_i2 < 3; c1_i2 = c1_i2 + 1) {
    c1_r3[c1_i2] = 0.0;
    c1_i3 = 0;
    for (c1_i4 = 0; c1_i4 < 3; c1_i4 = c1_i4 + 1) {
      c1_r3[c1_i2] = c1_r3[c1_i2] + c1_dv1[c1_i3 + c1_i2] * c1_x1[c1_i4];
      c1_i3 = c1_i3 + 3;
    }
  }

  c1_B = c1_b_ceval_xnrm2(chartInstance, 3, c1_r3, 1, 1);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2 = c1_i2 + 1) {
    c1_r3[c1_i2] = c1_r3[c1_i2] / c1_B;
  }

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
  c1_dv1[0] = 0.0;
  c1_dv1[3] = -c1_r3[2];
  c1_dv1[6] = c1_r3[1];
  c1_dv1[1] = c1_r3[2];
  c1_dv1[4] = 0.0;
  c1_dv1[7] = -c1_r3[0];
  c1_dv1[2] = -c1_r3[1];
  c1_dv1[5] = c1_r3[0];
  c1_dv1[8] = 0.0;
  for (c1_i2 = 0; c1_i2 < 3; c1_i2 = c1_i2 + 1) {
    c1_x1[c1_i2] = 0.0;
    c1_i3 = 0;
    for (c1_i4 = 0; c1_i4 < 3; c1_i4 = c1_i4 + 1) {
      c1_x1[c1_i2] = c1_x1[c1_i2] + c1_dv1[c1_i3 + c1_i2] * c1_r1[c1_i4];
      c1_i3 = c1_i3 + 3;
    }

    (*c1_RO)[c1_i2] = c1_r1[c1_i2];
    (*c1_RO)[c1_i2 + 3] = c1_x1[c1_i2];
    (*c1_RO)[c1_i2 + 6] = c1_r3[c1_i2];
  }

  _sfEvent_ = c1_previousEvent;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static real_T c1_norm(SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct
                      *chartInstance, real_T c1_x[3])
{
  return c1_ceval_xnrm2(chartInstance, 3, c1_x, 1, 1);
}

static real_T c1_ceval_xnrm2(SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[3], int32_T
  c1_ix0, int32_T c1_incx)
{
  return dnrm232(&c1_n, &c1_x[sf_mex_lw_bounds_check(c1_ix0, 1, 3) - 1],
                 &c1_incx);
}

static real_T c1_b_ceval_xnrm2(SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[3], int32_T
  c1_ix0, int32_T c1_incx)
{
  return dnrm232(&c1_n, &c1_x[sf_mex_lw_bounds_check(c1_ix0, 1, 3) - 1],
                 &c1_incx);
}

const mxArray *sf_c1_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[61];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i5;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 61));
  for (c1_i5 = 0; c1_i5 < 61; c1_i5 = c1_i5 + 1) {
    c1_r0 = &c1_info[c1_i5];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c1_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c1_r0->context)), "context", "nameCaptureInfo", c1_i5);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c1_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)c1_r0
      ->name)), "name", "nameCaptureInfo", c1_i5);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c1_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const char
      *)c1_r0->dominantType)), "dominantType", "nameCaptureInfo", c1_i5);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c1_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c1_r0->resolved)), "resolved", "nameCaptureInfo", c1_i5);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i5);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i5);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i5);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[61])
{
  c1_info[0].context = "";
  c1_info[0].name = "minus";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[B]minus";
  c1_info[0].fileLength = 0U;
  c1_info[0].fileTime1 = 0U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "norm";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[1].fileLength = 5312U;
  c1_info[1].fileTime1 = 1262616676U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[2].name = "nargin";
  c1_info[2].dominantType = "";
  c1_info[2].resolved = "[B]nargin";
  c1_info[2].fileLength = 0U;
  c1_info[2].fileTime1 = 0U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[3].name = "gt";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[B]gt";
  c1_info[3].fileLength = 0U;
  c1_info[3].fileTime1 = 0U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[4].name = "isa";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[B]isa";
  c1_info[4].fileLength = 0U;
  c1_info[4].fileTime1 = 0U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[5].name = "ndims";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[B]ndims";
  c1_info[5].fileLength = 0U;
  c1_info[5].fileTime1 = 0U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[6].name = "le";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[B]le";
  c1_info[6].fileLength = 0U;
  c1_info[6].fileTime1 = 0U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[7].name = "eq";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[B]eq";
  c1_info[7].fileLength = 0U;
  c1_info[7].fileTime1 = 0U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[8].name = "lt";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[B]lt";
  c1_info[8].fileLength = 0U;
  c1_info[8].fileTime1 = 0U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[9].name = "size";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[B]size";
  c1_info[9].fileLength = 0U;
  c1_info[9].fileTime1 = 0U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[10].name = "isempty";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[B]isempty";
  c1_info[10].fileLength = 0U;
  c1_info[10].fileTime1 = 0U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[11].name = "isscalar";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved = "[B]isscalar";
  c1_info[11].fileLength = 0U;
  c1_info[11].fileTime1 = 0U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[12].name = "isvector";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved = "[B]isvector";
  c1_info[12].fileLength = 0U;
  c1_info[12].fileTime1 = 0U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c1_info[13].name = "eml_index_class";
  c1_info[13].dominantType = "";
  c1_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[13].fileLength = 909U;
  c1_info[13].fileTime1 = 1192463182U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c1_info[14].name = "ones";
  c1_info[14].dominantType = "char";
  c1_info[14].resolved = "[B]ones";
  c1_info[14].fileLength = 0U;
  c1_info[14].fileTime1 = 0U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c1_info[15].name = "ischar";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved = "[B]ischar";
  c1_info[15].fileLength = 0U;
  c1_info[15].fileTime1 = 0U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c1_info[16].name = "eml_xnrm2";
  c1_info[16].dominantType = "int32";
  c1_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[16].fileLength = 718U;
  c1_info[16].fileTime1 = 1209327256U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_use_refblas.m";
  c1_info[17].name = "strcmp";
  c1_info[17].dominantType = "char";
  c1_info[17].resolved = "[B]strcmp";
  c1_info[17].fileLength = 0U;
  c1_info[17].fileTime1 = 0U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[18].name = "cast";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved = "[B]cast";
  c1_info[18].fileLength = 0U;
  c1_info[18].fileTime1 = 0U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[19].name = "eml_refblas_xnrm2";
  c1_info[19].dominantType = "int32";
  c1_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[19].fileLength = 1433U;
  c1_info[19].fileTime1 = 1240258442U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[20].name = "class";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved = "[B]class";
  c1_info[20].fileLength = 0U;
  c1_info[20].fileTime1 = 0U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[21].name = "zeros";
  c1_info[21].dominantType = "char";
  c1_info[21].resolved = "[B]zeros";
  c1_info[21].fileLength = 0U;
  c1_info[21].fileTime1 = 0U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[22].name = "true";
  c1_info[22].dominantType = "";
  c1_info[22].resolved = "[B]true";
  c1_info[22].fileLength = 0U;
  c1_info[22].fileTime1 = 0U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[23].name = "eml_index_minus";
  c1_info[23].dominantType = "int32";
  c1_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[23].fileLength = 277U;
  c1_info[23].fileTime1 = 1192463184U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[24].name = "eml_index_times";
  c1_info[24].dominantType = "int32";
  c1_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[24].fileLength = 280U;
  c1_info[24].fileTime1 = 1192463186U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[25].name = "eml_index_plus";
  c1_info[25].dominantType = "int32";
  c1_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[25].fileLength = 272U;
  c1_info[25].fileTime1 = 1192463184U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[26].name = "real";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved = "[B]real";
  c1_info[26].fileLength = 0U;
  c1_info[26].fileTime1 = 0U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[27].name = "ne";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved = "[B]ne";
  c1_info[27].fileLength = 0U;
  c1_info[27].fileTime1 = 0U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[28].name = "abs";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[28].fileLength = 566U;
  c1_info[28].fileTime1 = 1221263532U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[29].name = "islogical";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved = "[B]islogical";
  c1_info[29].fileLength = 0U;
  c1_info[29].fileTime1 = 0U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[30].name = "eml_scalar_abs";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[30].fileLength = 461U;
  c1_info[30].fileTime1 = 1203444360U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[31].name = "isinteger";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved = "[B]isinteger";
  c1_info[31].fileLength = 0U;
  c1_info[31].fileTime1 = 0U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[32].name = "isreal";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved = "[B]isreal";
  c1_info[32].fileLength = 0U;
  c1_info[32].fileTime1 = 0U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[33].name = "false";
  c1_info[33].dominantType = "";
  c1_info[33].resolved = "[B]false";
  c1_info[33].fileLength = 0U;
  c1_info[33].fileTime1 = 0U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[34].name = "times";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved = "[B]times";
  c1_info[34].fileLength = 0U;
  c1_info[34].fileTime1 = 0U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[35].name = "plus";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved = "[B]plus";
  c1_info[35].fileLength = 0U;
  c1_info[35].fileTime1 = 0U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[36].name = "imag";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved = "[B]imag";
  c1_info[36].fileLength = 0U;
  c1_info[36].fileTime1 = 0U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context = "";
  c1_info[37].name = "mrdivide";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[37].fileLength = 800U;
  c1_info[37].fileTime1 = 1238430690U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[38].name = "ge";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved = "[B]ge";
  c1_info[38].fileLength = 0U;
  c1_info[38].fileTime1 = 0U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c1_info[39].name = "rdivide";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[39].fileLength = 403U;
  c1_info[39].fileTime1 = 1244731952U;
  c1_info[39].fileTime2 = 0U;
  c1_info[40].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[40].name = "eml_div";
  c1_info[40].dominantType = "double";
  c1_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[40].fileLength = 4269U;
  c1_info[40].fileTime1 = 1228090226U;
  c1_info[40].fileTime2 = 0U;
  c1_info[41].context = "";
  c1_info[41].name = "skew";
  c1_info[41].dominantType = "double";
  c1_info[41].resolved =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/skew.m";
  c1_info[41].fileLength = 1233U;
  c1_info[41].fileTime1 = 1348594888U;
  c1_info[41].fileTime2 = 0U;
  c1_info[42].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/skew.m";
  c1_info[42].name = "isvec";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/isvec.m";
  c1_info[42].fileLength = 1299U;
  c1_info[42].fileTime1 = 1348594888U;
  c1_info[42].fileTime2 = 0U;
  c1_info[43].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/isvec.m";
  c1_info[43].name = "length";
  c1_info[43].dominantType = "double";
  c1_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[43].fileLength = 326U;
  c1_info[43].fileTime1 = 1226573674U;
  c1_info[43].fileTime2 = 0U;
  c1_info[44].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/isvec.m";
  c1_info[44].name = "min";
  c1_info[44].dominantType = "double";
  c1_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[44].fileLength = 362U;
  c1_info[44].fileTime1 = 1244731952U;
  c1_info[44].fileTime2 = 0U;
  c1_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[45].name = "nargout";
  c1_info[45].dominantType = "";
  c1_info[45].resolved = "[B]nargout";
  c1_info[45].fileLength = 0U;
  c1_info[45].fileTime1 = 0U;
  c1_info[45].fileTime2 = 0U;
  c1_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[46].name = "eml_min_or_max";
  c1_info[46].dominantType = "char";
  c1_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[46].fileLength = 9969U;
  c1_info[46].fileTime1 = 1240258406U;
  c1_info[46].fileTime2 = 0U;
  c1_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[47].name = "isnumeric";
  c1_info[47].dominantType = "double";
  c1_info[47].resolved = "[B]isnumeric";
  c1_info[47].fileLength = 0U;
  c1_info[47].fileTime1 = 0U;
  c1_info[47].fileTime2 = 0U;
  c1_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[48].name = "eml_const_nonsingleton_dim";
  c1_info[48].dominantType = "double";
  c1_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c1_info[48].fileLength = 1473U;
  c1_info[48].fileTime1 = 1240258402U;
  c1_info[48].fileTime2 = 0U;
  c1_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m/local_const_nonsingleton_dim";
  c1_info[49].name = "not";
  c1_info[49].dominantType = "logical";
  c1_info[49].resolved = "[B]not";
  c1_info[49].fileLength = 0U;
  c1_info[49].fileTime1 = 0U;
  c1_info[49].fileTime2 = 0U;
  c1_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[50].name = "eml_scalar_eg";
  c1_info[50].dominantType = "double";
  c1_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[50].fileLength = 3068U;
  c1_info[50].fileTime1 = 1240258410U;
  c1_info[50].fileTime2 = 0U;
  c1_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[51].name = "isstruct";
  c1_info[51].dominantType = "double";
  c1_info[51].resolved = "[B]isstruct";
  c1_info[51].fileLength = 0U;
  c1_info[51].fileTime1 = 0U;
  c1_info[51].fileTime2 = 0U;
  c1_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c1_info[52].name = "isnan";
  c1_info[52].dominantType = "double";
  c1_info[52].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[52].fileLength = 506U;
  c1_info[52].fileTime1 = 1228090210U;
  c1_info[52].fileTime2 = 0U;
  c1_info[53].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/isvec.m";
  c1_info[53].name = "numel";
  c1_info[53].dominantType = "double";
  c1_info[53].resolved = "[B]numel";
  c1_info[53].fileLength = 0U;
  c1_info[53].fileTime1 = 0U;
  c1_info[53].fileTime2 = 0U;
  c1_info[54].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/isvec.m";
  c1_info[54].name = "logical";
  c1_info[54].dominantType = "logical";
  c1_info[54].resolved = "[B]logical";
  c1_info[54].fileLength = 0U;
  c1_info[54].fileTime1 = 0U;
  c1_info[54].fileTime2 = 0U;
  c1_info[55].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Vasios_DT_Matlab_Code/robot/skew.m";
  c1_info[55].name = "uminus";
  c1_info[55].dominantType = "double";
  c1_info[55].resolved = "[B]uminus";
  c1_info[55].fileLength = 0U;
  c1_info[55].fileTime1 = 0U;
  c1_info[55].fileTime2 = 0U;
  c1_info[56].context = "";
  c1_info[56].name = "ctranspose";
  c1_info[56].dominantType = "double";
  c1_info[56].resolved = "[B]ctranspose";
  c1_info[56].fileLength = 0U;
  c1_info[56].fileTime1 = 0U;
  c1_info[56].fileTime2 = 0U;
  c1_info[57].context = "";
  c1_info[57].name = "mtimes";
  c1_info[57].dominantType = "double";
  c1_info[57].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[57].fileLength = 3425U;
  c1_info[57].fileTime1 = 1250669166U;
  c1_info[57].fileTime2 = 0U;
  c1_info[58].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[58].name = "eml_xgemm";
  c1_info[58].dominantType = "int32";
  c1_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[58].fileLength = 3184U;
  c1_info[58].fileTime1 = 1209327252U;
  c1_info[58].fileTime2 = 0U;
  c1_info[59].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c1_info[59].name = "eml_scalexp_alloc";
  c1_info[59].dominantType = "double";
  c1_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[59].fileLength = 808U;
  c1_info[59].fileTime1 = 1230491098U;
  c1_info[59].fileTime2 = 0U;
  c1_info[60].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[60].name = "eml_refblas_xgemm";
  c1_info[60].dominantType = "int32";
  c1_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[60].fileLength = 5748U;
  c1_info[60].fileTime1 = 1228090272U;
  c1_info[60].fileTime2 = 0U;
}

static void c1_emlrt_marshallIn(SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, const mxArray *c1_RO, const char_T *
  c1_name, real_T c1_y[9])
{
  real_T c1_dv2[9];
  int32_T c1_i6;
  sf_mex_import(c1_name, sf_mex_dup(c1_RO), &c1_dv2, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i6 = 0; c1_i6 < 9; c1_i6 = c1_i6 + 1) {
    c1_y[c1_i6] = c1_dv2[c1_i6];
  }

  sf_mex_destroy(&c1_RO);
}

static uint8_T c1_b_emlrt_marshallIn
  (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c1_b_is_active_c1_ODE_Hand_Model_v08_IPC_v03, const char_T *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_is_active_c1_ODE_Hand_Model_v08_IPC_v03),
                &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_b_is_active_c1_ODE_Hand_Model_v08_IPC_v03);
  return c1_y;
}

static void init_dsm_address_info(SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4047609626U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3361242296U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1127675818U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(806688143U);
}

mxArray *sf_c1_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2402370161U);
    pr[1] = (double)(1172369378U);
    pr[2] = (double)(1228519140U);
    pr[3] = (double)(3183277894U);
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

static mxArray *sf_get_sim_state_info_c1_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"RO\",},{M[8],M[0],T\"is_active_c1_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c1_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c1_ODE_Hand_Model_v08_IPC_v03
    ((SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c1_ODE_Hand_Model_v08_IPC_v03
    ((SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c1_ODE_Hand_Model_v08_IPC_v03
    ((SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c1_ODE_Hand_Model_v08_IPC_v03
    ((SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c1_ODE_Hand_Model_v08_IPC_v03
    ((SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c1_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_ODE_Hand_Model_v08_IPC_v03
    ((SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c1_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c1_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_ODE_Hand_Model_v08_IPC_v03
    ((SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c1_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c1_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c1_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c1_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_ODE_Hand_Model_v08_IPC_v03
      ((SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_ODE_Hand_Model_v08_IPC_v03
      ((SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",1,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",1,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3408062757U));
  ssSetChecksum1(S,(2209745276U));
  ssSetChecksum2(S,(3348370882U));
  ssSetChecksum3(S,(3120893167U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc(sizeof
    (SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_ODE_Hand_Model_v08_IPC_v03;
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

void c1_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
