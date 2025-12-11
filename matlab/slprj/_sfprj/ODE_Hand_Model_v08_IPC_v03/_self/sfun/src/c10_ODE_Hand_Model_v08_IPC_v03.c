/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c10_ODE_Hand_Model_v08_IPC_v03.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c10_st);
static void finalize_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static void c10_invNxN(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c10_x[100], real_T c10_y[100]);
static int32_T c10_ceval_ixamax(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c10_n, real_T c10_x[100], int32_T c10_ix0, int32_T
  c10_incx);
static real_T c10_norm(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c10_x[100]);
static void c10_eml_warning(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);
static void c10_b_eml_warning(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c10_varargin_3);
static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[83]);
static void c10_b_info_helper(c10_ResolvedFunctionInfo c10_info[83]);
static void c10_emlrt_marshallIn(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c10_y, const char_T *c10_name, real_T c10_b_y
  [100]);
static uint8_T c10_b_emlrt_marshallIn
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c10_b_is_active_c10_ODE_Hand_Model_v08_IPC_v03, const char_T *c10_name);
static void c10_refp2_ceval_xswap(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c10_n, real_T c10_x[100], int32_T c10_ix0, int32_T
  c10_incx, int32_T c10_iy0, int32_T c10_incy);
static void c10_refp8_ceval_xger(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, int32_T c10_m, int32_T c10_n, real_T c10_alpha1, int32_T
  c10_ix0, int32_T c10_incx, int32_T c10_iy0, int32_T c10_incy, real_T c10_A[100],
  int32_T c10_ia0, int32_T c10_lda);
static void c10_refp7_ceval_xtrsm(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c10_m, int32_T c10_n, real_T c10_alpha1, real_T c10_A
  [100], int32_T c10_ia0, int32_T c10_lda, real_T c10_B[100], int32_T c10_ib0,
  int32_T c10_ldb);
static void init_dsm_address_info(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c10_is_active_c10_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  int32_T c10_i0;
  real_T c10_u[100];
  const mxArray *c10_b_y = NULL;
  uint8_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  real_T (*c10_d_y)[100];
  c10_d_y = (real_T (*)[100])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(2));
  for (c10_i0 = 0; c10_i0 < 100; c10_i0 = c10_i0 + 1) {
    c10_u[c10_i0] = (*c10_d_y)[c10_i0];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 1U, 0U, 2, 10, 10));
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_u = chartInstance->c10_is_active_c10_ODE_Hand_Model_v08_IPC_v03;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y);
  return c10_st;
}

static void set_sim_state_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance,
   const mxArray *c10_st)
{
  const mxArray *c10_u;
  real_T c10_dv0[100];
  int32_T c10_i1;
  real_T (*c10_y)[100];
  c10_y = (real_T (*)[100])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_u = sf_mex_dup(c10_st);
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 0)), "y",
                       c10_dv0);
  for (c10_i1 = 0; c10_i1 < 100; c10_i1 = c10_i1 + 1) {
    (*c10_y)[c10_i1] = c10_dv0[c10_i1];
  }

  chartInstance->c10_is_active_c10_ODE_Hand_Model_v08_IPC_v03 =
    c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u
    , 1)), "is_active_c10_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c10_u);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c10_ODE_Hand_Model_v08_IPC_v03
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c10_previousEvent;
  real_T c10_y[100];
  real_T c10_n1x;
  real_T c10_n1xinv;
  real_T c10_rc;
  int32_T c10_i2;
  real_T (*c10_b_y)[100];
  real_T (*c10_u)[100];
  c10_b_y = (real_T (*)[100])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_u = (real_T (*)[100])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c10_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c10_invNxN(chartInstance, *c10_u, c10_y);
  c10_n1x = c10_norm(chartInstance, *c10_u);
  c10_n1xinv = c10_norm(chartInstance, c10_y);
  c10_rc = 1.0 / (c10_n1x * c10_n1xinv);
  if ((c10_n1x == 0.0) || (c10_n1xinv == 0.0) || (c10_rc == 0.0)) {
    c10_eml_warning(chartInstance);
  } else {
    if (muDoubleScalarIsNaN(c10_rc) || (c10_rc < 2.2204460492503131E-016)) {
      c10_b_eml_warning(chartInstance, c10_rc);
    }
  }

  for (c10_i2 = 0; c10_i2 < 100; c10_i2 = c10_i2 + 1) {
    (*c10_b_y)[c10_i2] = c10_y[c10_i2];
  }

  _sfEvent_ = c10_previousEvent;
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
}

static void c10_invNxN(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c10_x[100], real_T c10_y[100])
{
  int32_T c10_k;
  real_T c10_b_x[100];
  int32_T c10_ipiv[10];
  int32_T c10_j;
  int32_T c10_i;
  int32_T c10_jj;
  int32_T c10_jp1j;
  int32_T c10_c;
  int8_T c10_p[10];
  for (c10_k = 0; c10_k < 100; c10_k = c10_k + 1) {
    c10_y[c10_k] = 0.0;
  }

  for (c10_k = 0; c10_k < 100; c10_k = c10_k + 1) {
    c10_b_x[c10_k] = c10_x[c10_k];
  }

  for (c10_k = 0; c10_k < 10; c10_k = c10_k + 1) {
    c10_ipiv[c10_k] = 1 + c10_k;
  }

  for (c10_j = 0; c10_j < 9; c10_j = c10_j + 1) {
    c10_i = 9 - c10_j;
    c10_jj = 1 + c10_j * 11;
    c10_jp1j = c10_jj + 1;
    c10_k = c10_ceval_ixamax(chartInstance, c10_i + 1, c10_b_x, c10_jj, 1);
    c10_k = c10_k - 1;
    if (c10_b_x[sf_mex_lw_bounds_check(c10_jj + c10_k, 1, 100) - 1] != 0.0) {
      if (c10_k != 0) {
        c10_ipiv[c10_j] = (c10_j + 1) + c10_k;
        c10_c = 1 + c10_j;
        c10_refp2_ceval_xswap(chartInstance, 10, c10_b_x, c10_c, 10, c10_c +
                              c10_k, 10);
      }

      c10_k = c10_jp1j + (c10_i - 1);
      for (c10_c = c10_jp1j; c10_c <= c10_k; c10_c = c10_c + 1) {
        c10_b_x[c10_c - 1] = c10_b_x[c10_c - 1] / c10_b_x[c10_jj - 1];
      }
    }

    c10_refp8_ceval_xger(chartInstance, c10_i, 9 - c10_j, -1.0, c10_jp1j, 1,
                         c10_jj + 10, 10, c10_b_x, c10_jj + 11, 10);
  }

  for (c10_k = 0; c10_k < 10; c10_k = c10_k + 1) {
    c10_p[c10_k] = (int8_T)(1 + c10_k);
  }

  for (c10_k = 0; c10_k < 9; c10_k = c10_k + 1) {
    c10_c = c10_ipiv[c10_k];
    if (c10_c > c10_k + 1) {
      c10_j = (int32_T)c10_p[sf_mex_lw_bounds_check(c10_c, 1, 10) - 1];
      c10_p[c10_c - 1] = c10_p[c10_k];
      c10_p[c10_k] = (int8_T)c10_j;
    }
  }

  for (c10_k = 0; c10_k < 10; c10_k = c10_k + 1) {
    c10_c = (int32_T)c10_p[c10_k];
    c10_y[c10_k + 10 * (sf_mex_lw_bounds_check(c10_c, 1, 10) - 1)] = 1.0;
    for (c10_j = c10_k + 1; c10_j < 11; c10_j = c10_j + 1) {
      if (c10_y[(c10_j - 1) + 10 * (c10_c - 1)] != 0.0) {
        for (c10_i = c10_j + 1; c10_i < 11; c10_i = c10_i + 1) {
          c10_y[(c10_i - 1) + 10 * (c10_c - 1)] = c10_y[(c10_i - 1) + 10 *
            (c10_c - 1)] - c10_y[(c10_j - 1) + 10 * (c10_c - 1)] * c10_b_x[(
            c10_i - 1) + 10 * (c10_j - 1)];
        }
      }
    }
  }

  c10_refp7_ceval_xtrsm(chartInstance, 10, 10, 1.0, c10_b_x, 1, 10, c10_y, 1, 10);
}

static int32_T c10_ceval_ixamax(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c10_n, real_T c10_x[100],
  int32_T c10_ix0, int32_T c10_incx)
{
  return idamax32(&c10_n, &c10_x[sf_mex_lw_bounds_check(c10_ix0, 1, 100) - 1],
                  &c10_incx);
}

static real_T c10_norm(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c10_x[100])
{
  real_T c10_y;
  int32_T c10_j;
  boolean_T c10_exitg1;
  real_T c10_s;
  int32_T c10_i;
  c10_y = 0.0;
  c10_j = 1;
  c10_exitg1 = 0U;
  while ((c10_exitg1 == 0U) && (c10_j <= 10)) {
    c10_s = 0.0;
    for (c10_i = 0; c10_i < 10; c10_i = c10_i + 1) {
      c10_s = c10_s + muDoubleScalarAbs(c10_x[c10_i + 10 * (c10_j - 1)]);
    }

    if (muDoubleScalarIsNaN(c10_s)) {
      c10_y = rtNaN;
      c10_exitg1 = 1U;
    } else {
      if (c10_s > c10_y) {
        c10_y = c10_s;
      }

      c10_j = c10_j + 1;
    }
  }

  return c10_y;
}

static void c10_eml_warning(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
  int32_T c10_i3;
  static char_T c10_cv0[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i',
    'x' };

  char_T c10_u[21];
  const mxArray *c10_y = NULL;
  static char_T c10_cv1[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't',
    'o', ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i',
    's', 'i', 'o', 'n', '.' };

  char_T c10_b_u[40];
  const mxArray *c10_b_y = NULL;
  for (c10_i3 = 0; c10_i3 < 21; c10_i3 = c10_i3 + 1) {
    c10_u[c10_i3] = c10_cv0[c10_i3];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 10, 0U, 1U, 0U, 2, 1, 21));
  for (c10_i3 = 0; c10_i3 < 40; c10_i3 = c10_i3 + 1) {
    c10_b_u[c10_i3] = c10_cv1[c10_i3];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 10, 0U, 1U, 0U, 2, 1, 40));
  sf_mex_call("warning", 0U, 2U, 14, c10_y, 14, c10_b_y);
}

static void c10_b_eml_warning(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c10_varargin_3)
{
  int32_T c10_i4;
  static char_T c10_cv2[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'l', 'l',
    'C', 'o', 'n', 'd', 'i', 't', 'i', 'o', 'n', 'e',
    'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c10_u[27];
  const mxArray *c10_y = NULL;
  static char_T c10_cv3[103] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's',
    ' ', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ',', ' ',
    'c', 'l', 'o', 's', 'e', ' ', 't', 'o', ' ', 's', 'i', 'n', 'g', 'u', 'l',
    'a', 'r', ' ', 'o', 'r',
    ' ', 'b', 'a', 'd', 'l', 'y', ' ', 's', 'c', 'a', 'l', 'e', 'd', '.', '\\',
    'n', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', 'R', 'e', 's', 'u', 'l', 't', 's', ' ', 'm', 'a',
    'y', ' ', 'b', 'e', ' ',
    'i', 'n', 'a', 'c', 'c', 'u', 'r', 'a', 't', 'e', '.', ' ', 'R', 'C', 'O',
    'N', 'D', ' ', '=', ' ',
    '%', 'e', '.' };

  char_T c10_b_u[103];
  const mxArray *c10_b_y = NULL;
  real_T c10_c_u;
  const mxArray *c10_c_y = NULL;
  for (c10_i4 = 0; c10_i4 < 27; c10_i4 = c10_i4 + 1) {
    c10_u[c10_i4] = c10_cv2[c10_i4];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 10, 0U, 1U, 0U, 2, 1, 27));
  for (c10_i4 = 0; c10_i4 < 103; c10_i4 = c10_i4 + 1) {
    c10_b_u[c10_i4] = c10_cv3[c10_i4];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 10, 0U, 1U, 0U, 2, 1, 103));
  c10_c_u = c10_varargin_3;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_call("warning", 0U, 3U, 14, c10_y, 14, c10_b_y, 14, c10_c_y);
}

const mxArray *sf_c10_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c10_nameCaptureInfo;
  c10_ResolvedFunctionInfo c10_info[83];
  const mxArray *c10_m0 = NULL;
  int32_T c10_i5;
  c10_ResolvedFunctionInfo *c10_r0;
  c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  c10_info_helper(c10_info);
  c10_b_info_helper(c10_info);
  sf_mex_assign(&c10_m0, sf_mex_createstruct("nameCaptureInfo", 1, 83));
  for (c10_i5 = 0; c10_i5 < 83; c10_i5 = c10_i5 + 1) {
    c10_r0 = &c10_info[c10_i5];
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c10_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c10_r0->context)), "context", "nameCaptureInfo", c10_i5);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c10_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c10_r0->name)), "name", "nameCaptureInfo", c10_i5);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c10_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const
      char *)c10_r0->dominantType)), "dominantType", "nameCaptureInfo", c10_i5);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c10_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c10_r0->resolved)), "resolved", "nameCaptureInfo", c10_i5);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c10_i5);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c10_i5);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c10_i5);
  }

  sf_mex_assign(&c10_nameCaptureInfo, c10_m0);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[83])
{
  c10_info[0].context = "";
  c10_info[0].name = "inv";
  c10_info[0].dominantType = "double";
  c10_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c10_info[0].fileLength = 4757U;
  c10_info[0].fileTime1 = 1251996502U;
  c10_info[0].fileTime2 = 0U;
  c10_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c10_info[1].name = "nargin";
  c10_info[1].dominantType = "";
  c10_info[1].resolved = "[B]nargin";
  c10_info[1].fileLength = 0U;
  c10_info[1].fileTime1 = 0U;
  c10_info[1].fileTime2 = 0U;
  c10_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c10_info[2].name = "gt";
  c10_info[2].dominantType = "double";
  c10_info[2].resolved = "[B]gt";
  c10_info[2].fileLength = 0U;
  c10_info[2].fileTime1 = 0U;
  c10_info[2].fileTime2 = 0U;
  c10_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c10_info[3].name = "isa";
  c10_info[3].dominantType = "double";
  c10_info[3].resolved = "[B]isa";
  c10_info[3].fileLength = 0U;
  c10_info[3].fileTime1 = 0U;
  c10_info[3].fileTime2 = 0U;
  c10_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c10_info[4].name = "ndims";
  c10_info[4].dominantType = "double";
  c10_info[4].resolved = "[B]ndims";
  c10_info[4].fileLength = 0U;
  c10_info[4].fileTime1 = 0U;
  c10_info[4].fileTime2 = 0U;
  c10_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c10_info[5].name = "eq";
  c10_info[5].dominantType = "double";
  c10_info[5].resolved = "[B]eq";
  c10_info[5].fileLength = 0U;
  c10_info[5].fileTime1 = 0U;
  c10_info[5].fileTime2 = 0U;
  c10_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c10_info[6].name = "size";
  c10_info[6].dominantType = "double";
  c10_info[6].resolved = "[B]size";
  c10_info[6].fileLength = 0U;
  c10_info[6].fileTime1 = 0U;
  c10_info[6].fileTime2 = 0U;
  c10_info[7].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c10_info[7].name = "eml_index_class";
  c10_info[7].dominantType = "";
  c10_info[7].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[7].fileLength = 909U;
  c10_info[7].fileTime1 = 1192463182U;
  c10_info[7].fileTime2 = 0U;
  c10_info[8].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c10_info[8].name = "cast";
  c10_info[8].dominantType = "double";
  c10_info[8].resolved = "[B]cast";
  c10_info[8].fileLength = 0U;
  c10_info[8].fileTime1 = 0U;
  c10_info[8].fileTime2 = 0U;
  c10_info[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c10_info[9].name = "ones";
  c10_info[9].dominantType = "char";
  c10_info[9].resolved = "[B]ones";
  c10_info[9].fileLength = 0U;
  c10_info[9].fileTime1 = 0U;
  c10_info[9].fileTime2 = 0U;
  c10_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c10_info[10].name = "eml_xgetrf";
  c10_info[10].dominantType = "int32";
  c10_info[10].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c10_info[10].fileLength = 2229U;
  c10_info[10].fileTime1 = 1240258414U;
  c10_info[10].fileTime2 = 0U;
  c10_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c10_info[11].name = "false";
  c10_info[11].dominantType = "";
  c10_info[11].resolved = "[B]false";
  c10_info[11].fileLength = 0U;
  c10_info[11].fileTime1 = 0U;
  c10_info[11].fileTime2 = 0U;
  c10_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c10_info[12].name = "min";
  c10_info[12].dominantType = "int32";
  c10_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c10_info[12].fileLength = 362U;
  c10_info[12].fileTime1 = 1244731952U;
  c10_info[12].fileTime2 = 0U;
  c10_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c10_info[13].name = "le";
  c10_info[13].dominantType = "double";
  c10_info[13].resolved = "[B]le";
  c10_info[13].fileLength = 0U;
  c10_info[13].fileTime1 = 0U;
  c10_info[13].fileTime2 = 0U;
  c10_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c10_info[14].name = "nargout";
  c10_info[14].dominantType = "";
  c10_info[14].resolved = "[B]nargout";
  c10_info[14].fileLength = 0U;
  c10_info[14].fileTime1 = 0U;
  c10_info[14].fileTime2 = 0U;
  c10_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c10_info[15].name = "eml_min_or_max";
  c10_info[15].dominantType = "int32";
  c10_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c10_info[15].fileLength = 9969U;
  c10_info[15].fileTime1 = 1240258406U;
  c10_info[15].fileTime2 = 0U;
  c10_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c10_info[16].name = "ischar";
  c10_info[16].dominantType = "char";
  c10_info[16].resolved = "[B]ischar";
  c10_info[16].fileLength = 0U;
  c10_info[16].fileTime1 = 0U;
  c10_info[16].fileTime2 = 0U;
  c10_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c10_info[17].name = "strcmp";
  c10_info[17].dominantType = "char";
  c10_info[17].resolved = "[B]strcmp";
  c10_info[17].fileLength = 0U;
  c10_info[17].fileTime1 = 0U;
  c10_info[17].fileTime2 = 0U;
  c10_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c10_info[18].name = "isnumeric";
  c10_info[18].dominantType = "int32";
  c10_info[18].resolved = "[B]isnumeric";
  c10_info[18].fileLength = 0U;
  c10_info[18].fileTime1 = 0U;
  c10_info[18].fileTime2 = 0U;
  c10_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c10_info[19].name = "isreal";
  c10_info[19].dominantType = "int32";
  c10_info[19].resolved = "[B]isreal";
  c10_info[19].fileLength = 0U;
  c10_info[19].fileTime1 = 0U;
  c10_info[19].fileTime2 = 0U;
  c10_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c10_info[20].name = "class";
  c10_info[20].dominantType = "int32";
  c10_info[20].resolved = "[B]class";
  c10_info[20].fileLength = 0U;
  c10_info[20].fileTime1 = 0U;
  c10_info[20].fileTime2 = 0U;
  c10_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c10_info[21].name = "islogical";
  c10_info[21].dominantType = "int32";
  c10_info[21].resolved = "[B]islogical";
  c10_info[21].fileLength = 0U;
  c10_info[21].fileTime1 = 0U;
  c10_info[21].fileTime2 = 0U;
  c10_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c10_info[22].name = "eml_scalar_eg";
  c10_info[22].dominantType = "int32";
  c10_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c10_info[22].fileLength = 3068U;
  c10_info[22].fileTime1 = 1240258410U;
  c10_info[22].fileTime2 = 0U;
  c10_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c10_info[23].name = "isstruct";
  c10_info[23].dominantType = "int32";
  c10_info[23].resolved = "[B]isstruct";
  c10_info[23].fileLength = 0U;
  c10_info[23].fileTime1 = 0U;
  c10_info[23].fileTime2 = 0U;
  c10_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c10_info[24].name = "plus";
  c10_info[24].dominantType = "int32";
  c10_info[24].resolved = "[B]plus";
  c10_info[24].fileLength = 0U;
  c10_info[24].fileTime1 = 0U;
  c10_info[24].fileTime2 = 0U;
  c10_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c10_info[25].name = "eml_scalexp_alloc";
  c10_info[25].dominantType = "int32";
  c10_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c10_info[25].fileLength = 808U;
  c10_info[25].fileTime1 = 1230491098U;
  c10_info[25].fileTime2 = 0U;
  c10_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c10_info[26].name = "minus";
  c10_info[26].dominantType = "double";
  c10_info[26].resolved = "[B]minus";
  c10_info[26].fileLength = 0U;
  c10_info[26].fileTime1 = 0U;
  c10_info[26].fileTime2 = 0U;
  c10_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c10_info[27].name = "isscalar";
  c10_info[27].dominantType = "int32";
  c10_info[27].resolved = "[B]isscalar";
  c10_info[27].fileLength = 0U;
  c10_info[27].fileTime1 = 0U;
  c10_info[27].fileTime2 = 0U;
  c10_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c10_info[28].name = "not";
  c10_info[28].dominantType = "logical";
  c10_info[28].resolved = "[B]not";
  c10_info[28].fileLength = 0U;
  c10_info[28].fileTime1 = 0U;
  c10_info[28].fileTime2 = 0U;
  c10_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c10_info[29].name = "colon";
  c10_info[29].dominantType = "int32";
  c10_info[29].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c10_info[29].fileLength = 8592U;
  c10_info[29].fileTime1 = 1257779782U;
  c10_info[29].fileTime2 = 0U;
  c10_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c10_info[30].name = "ge";
  c10_info[30].dominantType = "double";
  c10_info[30].resolved = "[B]ge";
  c10_info[30].fileLength = 0U;
  c10_info[30].fileTime1 = 0U;
  c10_info[30].fileTime2 = 0U;
  c10_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c10_info[31].name = "lt";
  c10_info[31].dominantType = "double";
  c10_info[31].resolved = "[B]lt";
  c10_info[31].fileLength = 0U;
  c10_info[31].fileTime1 = 0U;
  c10_info[31].fileTime2 = 0U;
  c10_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c10_info[32].name = "isinteger";
  c10_info[32].dominantType = "double";
  c10_info[32].resolved = "[B]isinteger";
  c10_info[32].fileLength = 0U;
  c10_info[32].fileTime1 = 0U;
  c10_info[32].fileTime2 = 0U;
  c10_info[33].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c10_info[33].name = "floor";
  c10_info[33].dominantType = "double";
  c10_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c10_info[33].fileLength = 332U;
  c10_info[33].fileTime1 = 1203444422U;
  c10_info[33].fileTime2 = 0U;
  c10_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c10_info[34].name = "eml_scalar_floor";
  c10_info[34].dominantType = "double";
  c10_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c10_info[34].fileLength = 260U;
  c10_info[34].fileTime1 = 1209327190U;
  c10_info[34].fileTime2 = 0U;
  c10_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c10_info[35].name = "intmin";
  c10_info[35].dominantType = "char";
  c10_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c10_info[35].fileLength = 1505U;
  c10_info[35].fileTime1 = 1192463128U;
  c10_info[35].fileTime2 = 0U;
  c10_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c10_info[36].name = "uminus";
  c10_info[36].dominantType = "double";
  c10_info[36].resolved = "[B]uminus";
  c10_info[36].fileLength = 0U;
  c10_info[36].fileTime1 = 0U;
  c10_info[36].fileTime2 = 0U;
  c10_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c10_info[37].name = "int32";
  c10_info[37].dominantType = "double";
  c10_info[37].resolved = "[B]int32";
  c10_info[37].fileLength = 0U;
  c10_info[37].fileTime1 = 0U;
  c10_info[37].fileTime2 = 0U;
  c10_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c10_info[38].name = "intmax";
  c10_info[38].dominantType = "char";
  c10_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c10_info[38].fileLength = 1535U;
  c10_info[38].fileTime1 = 1192463128U;
  c10_info[38].fileTime2 = 0U;
  c10_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/eml_integer_colon";
  c10_info[39].name = "double";
  c10_info[39].dominantType = "double";
  c10_info[39].resolved = "[B]double";
  c10_info[39].fileLength = 0U;
  c10_info[39].fileTime1 = 0U;
  c10_info[39].fileTime2 = 0U;
  c10_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c10_info[40].name = "isnan";
  c10_info[40].dominantType = "double";
  c10_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c10_info[40].fileLength = 506U;
  c10_info[40].fileTime1 = 1228090210U;
  c10_info[40].fileTime2 = 0U;
  c10_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c10_info[41].name = "isinf";
  c10_info[41].dominantType = "double";
  c10_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c10_info[41].fileLength = 506U;
  c10_info[41].fileTime1 = 1228090208U;
  c10_info[41].fileTime2 = 0U;
  c10_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c10_info[42].name = "realmax";
  c10_info[42].dominantType = "";
  c10_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c10_info[42].fileLength = 771U;
  c10_info[42].fileTime1 = 1226573676U;
  c10_info[42].fileTime2 = 0U;
  c10_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c10_info[43].name = "mpower";
  c10_info[43].dominantType = "double";
  c10_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c10_info[43].fileLength = 3710U;
  c10_info[43].fileTime1 = 1238430688U;
  c10_info[43].fileTime2 = 0U;
  c10_info[44].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c10_info[44].name = "power";
  c10_info[44].dominantType = "double";
  c10_info[44].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c10_info[44].fileLength = 5380U;
  c10_info[44].fileTime1 = 1228090298U;
  c10_info[44].fileTime2 = 0U;
  c10_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c10_info[45].name = "ne";
  c10_info[45].dominantType = "double";
  c10_info[45].resolved = "[B]ne";
  c10_info[45].fileLength = 0U;
  c10_info[45].fileTime1 = 0U;
  c10_info[45].fileTime2 = 0U;
  c10_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c10_info[46].name = "eml_error";
  c10_info[46].dominantType = "char";
  c10_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c10_info[46].fileLength = 315U;
  c10_info[46].fileTime1 = 1213923144U;
  c10_info[46].fileTime2 = 0U;
  c10_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c10_info[47].name = "mtimes";
  c10_info[47].dominantType = "double";
  c10_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[47].fileLength = 3425U;
  c10_info[47].fileTime1 = 1250669166U;
  c10_info[47].fileTime2 = 0U;
  c10_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/eml_integer_colon";
  c10_info[48].name = "transpose";
  c10_info[48].dominantType = "int32";
  c10_info[48].resolved = "[B]transpose";
  c10_info[48].fileLength = 0U;
  c10_info[48].fileTime1 = 0U;
  c10_info[48].fileTime2 = 0U;
  c10_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c10_info[49].name = "zeros";
  c10_info[49].dominantType = "char";
  c10_info[49].resolved = "[B]zeros";
  c10_info[49].fileLength = 0U;
  c10_info[49].fileTime1 = 0U;
  c10_info[49].fileTime2 = 0U;
  c10_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c10_info[50].name = "eml_index_plus";
  c10_info[50].dominantType = "int32";
  c10_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c10_info[50].fileLength = 272U;
  c10_info[50].fileTime1 = 1192463184U;
  c10_info[50].fileTime2 = 0U;
  c10_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c10_info[51].name = "eml_index_minus";
  c10_info[51].dominantType = "int32";
  c10_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c10_info[51].fileLength = 277U;
  c10_info[51].fileTime1 = 1192463184U;
  c10_info[51].fileTime2 = 0U;
  c10_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c10_info[52].name = "eml_index_times";
  c10_info[52].dominantType = "int32";
  c10_info[52].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c10_info[52].fileLength = 280U;
  c10_info[52].fileTime1 = 1192463186U;
  c10_info[52].fileTime2 = 0U;
  c10_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c10_info[53].name = "eml_ixamax";
  c10_info[53].dominantType = "int32";
  c10_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c10_info[53].fileLength = 731U;
  c10_info[53].fileTime1 = 1209327244U;
  c10_info[53].fileTime2 = 0U;
  c10_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c10_info[54].name = "eml_refblas_ixamax";
  c10_info[54].dominantType = "int32";
  c10_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c10_info[54].fileLength = 740U;
  c10_info[54].fileTime1 = 1192463266U;
  c10_info[54].fileTime2 = 0U;
  c10_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c10_info[55].name = "eml_xcabs1";
  c10_info[55].dominantType = "double";
  c10_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c10_info[55].fileLength = 419U;
  c10_info[55].fileTime1 = 1209327246U;
  c10_info[55].fileTime2 = 0U;
  c10_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c10_info[56].name = "real";
  c10_info[56].dominantType = "double";
  c10_info[56].resolved = "[B]real";
  c10_info[56].fileLength = 0U;
  c10_info[56].fileTime1 = 0U;
  c10_info[56].fileTime2 = 0U;
  c10_info[57].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c10_info[57].name = "abs";
  c10_info[57].dominantType = "double";
  c10_info[57].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c10_info[57].fileLength = 566U;
  c10_info[57].fileTime1 = 1221263532U;
  c10_info[57].fileTime2 = 0U;
  c10_info[58].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c10_info[58].name = "eml_scalar_abs";
  c10_info[58].dominantType = "double";
  c10_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c10_info[58].fileLength = 461U;
  c10_info[58].fileTime1 = 1203444360U;
  c10_info[58].fileTime2 = 0U;
  c10_info[59].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c10_info[59].name = "imag";
  c10_info[59].dominantType = "double";
  c10_info[59].resolved = "[B]imag";
  c10_info[59].fileLength = 0U;
  c10_info[59].fileTime1 = 0U;
  c10_info[59].fileTime2 = 0U;
  c10_info[60].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c10_info[60].name = "eml_xswap";
  c10_info[60].dominantType = "int32";
  c10_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c10_info[60].fileLength = 1330U;
  c10_info[60].fileTime1 = 1209327260U;
  c10_info[60].fileTime2 = 0U;
  c10_info[61].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c10_info[61].name = "eml_refblas_xswap";
  c10_info[61].dominantType = "int32";
  c10_info[61].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c10_info[61].fileLength = 905U;
  c10_info[61].fileTime1 = 1238430670U;
  c10_info[61].fileTime2 = 0U;
  c10_info[62].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c10_info[62].name = "isempty";
  c10_info[62].dominantType = "double";
  c10_info[62].resolved = "[B]isempty";
  c10_info[62].fileLength = 0U;
  c10_info[62].fileTime1 = 0U;
  c10_info[62].fileTime2 = 0U;
  c10_info[63].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c10_info[63].name = "eml_div";
  c10_info[63].dominantType = "double";
  c10_info[63].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c10_info[63].fileLength = 4269U;
  c10_info[63].fileTime1 = 1228090226U;
  c10_info[63].fileTime2 = 0U;
}

static void c10_b_info_helper(c10_ResolvedFunctionInfo c10_info[83])
{
  c10_info[64].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c10_info[64].name = "eml_xgeru";
  c10_info[64].dominantType = "int32";
  c10_info[64].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c10_info[64].fileLength = 2462U;
  c10_info[64].fileTime1 = 1209327256U;
  c10_info[64].fileTime2 = 0U;
  c10_info[65].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c10_info[65].name = "eml_xger";
  c10_info[65].dominantType = "int32";
  c10_info[65].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c10_info[65].fileLength = 2168U;
  c10_info[65].fileTime1 = 1209327254U;
  c10_info[65].fileTime2 = 0U;
  c10_info[66].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c10_info[66].name = "eml_refblas_xger";
  c10_info[66].dominantType = "int32";
  c10_info[66].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c10_info[66].fileLength = 411U;
  c10_info[66].fileTime1 = 1211212448U;
  c10_info[66].fileTime2 = 0U;
  c10_info[67].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c10_info[67].name = "eml_refblas_xgerx";
  c10_info[67].dominantType = "int32";
  c10_info[67].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c10_info[67].fileLength = 2231U;
  c10_info[67].fileTime1 = 1238430668U;
  c10_info[67].fileTime2 = 0U;
  c10_info[68].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c10_info[68].name = "times";
  c10_info[68].dominantType = "double";
  c10_info[68].resolved = "[B]times";
  c10_info[68].fileLength = 0U;
  c10_info[68].fileTime1 = 0U;
  c10_info[68].fileTime2 = 0U;
  c10_info[69].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c10_info[69].name = "eml_ipiv2perm";
  c10_info[69].dominantType = "int32";
  c10_info[69].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c10_info[69].fileLength = 673U;
  c10_info[69].fileTime1 = 1246279788U;
  c10_info[69].fileTime2 = 0U;
  c10_info[70].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c10_info[70].name = "eml_xtrsm";
  c10_info[70].dominantType = "int32";
  c10_info[70].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c10_info[70].fileLength = 2383U;
  c10_info[70].fileTime1 = 1209327262U;
  c10_info[70].fileTime2 = 0U;
  c10_info[71].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m/itcount";
  c10_info[71].name = "length";
  c10_info[71].dominantType = "double";
  c10_info[71].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c10_info[71].fileLength = 326U;
  c10_info[71].fileTime1 = 1226573674U;
  c10_info[71].fileTime2 = 0U;
  c10_info[72].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m/itcount";
  c10_info[72].name = "mrdivide";
  c10_info[72].dominantType = "double";
  c10_info[72].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[72].fileLength = 800U;
  c10_info[72].fileTime1 = 1238430690U;
  c10_info[72].fileTime2 = 0U;
  c10_info[73].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[73].name = "rdivide";
  c10_info[73].dominantType = "double";
  c10_info[73].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[73].fileLength = 403U;
  c10_info[73].fileTime1 = 1244731952U;
  c10_info[73].fileTime2 = 0U;
  c10_info[74].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c10_info[74].name = "eml_refblas_xtrsm";
  c10_info[74].dominantType = "int32";
  c10_info[74].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c10_info[74].fileLength = 13101U;
  c10_info[74].fileTime1 = 1251996502U;
  c10_info[74].fileTime2 = 0U;
  c10_info[75].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/checkcond";
  c10_info[75].name = "norm";
  c10_info[75].dominantType = "double";
  c10_info[75].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c10_info[75].fileLength = 5312U;
  c10_info[75].fileTime1 = 1262616676U;
  c10_info[75].fileTime2 = 0U;
  c10_info[76].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c10_info[76].name = "isvector";
  c10_info[76].dominantType = "double";
  c10_info[76].resolved = "[B]isvector";
  c10_info[76].fileLength = 0U;
  c10_info[76].fileTime1 = 0U;
  c10_info[76].fileTime2 = 0U;
  c10_info[77].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c10_info[77].name = "inf";
  c10_info[77].dominantType = "";
  c10_info[77].resolved = "[B]inf";
  c10_info[77].fileLength = 0U;
  c10_info[77].fileTime1 = 0U;
  c10_info[77].fileTime2 = 0U;
  c10_info[78].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/mat1norm";
  c10_info[78].name = "eml_guarded_nan";
  c10_info[78].dominantType = "char";
  c10_info[78].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c10_info[78].fileLength = 485U;
  c10_info[78].fileTime1 = 1192463180U;
  c10_info[78].fileTime2 = 0U;
  c10_info[79].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c10_info[79].name = "eml_is_float_class";
  c10_info[79].dominantType = "char";
  c10_info[79].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c10_info[79].fileLength = 226U;
  c10_info[79].fileTime1 = 1197846840U;
  c10_info[79].fileTime2 = 0U;
  c10_info[80].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c10_info[80].name = "nan";
  c10_info[80].dominantType = "char";
  c10_info[80].resolved = "[B]nan";
  c10_info[80].fileLength = 0U;
  c10_info[80].fileTime1 = 0U;
  c10_info[80].fileTime2 = 0U;
  c10_info[81].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/checkcond";
  c10_info[81].name = "eml_warning";
  c10_info[81].dominantType = "char";
  c10_info[81].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c10_info[81].fileLength = 262U;
  c10_info[81].fileTime1 = 1236253678U;
  c10_info[81].fileTime2 = 0U;
  c10_info[82].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/checkcond";
  c10_info[82].name = "eps";
  c10_info[82].dominantType = "char";
  c10_info[82].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c10_info[82].fileLength = 1331U;
  c10_info[82].fileTime1 = 1246279786U;
  c10_info[82].fileTime2 = 0U;
}

static void c10_emlrt_marshallIn(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c10_y, const char_T *
  c10_name, real_T c10_b_y[100])
{
  real_T c10_dv1[100];
  int32_T c10_i6;
  sf_mex_import(c10_name, sf_mex_dup(c10_y), &c10_dv1, 1, 0, 0U, 1, 0U, 2, 10,
                10);
  for (c10_i6 = 0; c10_i6 < 100; c10_i6 = c10_i6 + 1) {
    c10_b_y[c10_i6] = c10_dv1[c10_i6];
  }

  sf_mex_destroy(&c10_y);
}

static uint8_T c10_b_emlrt_marshallIn
  (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c10_b_is_active_c10_ODE_Hand_Model_v08_IPC_v03, const char_T *c10_name)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  sf_mex_import(c10_name, sf_mex_dup
                (c10_b_is_active_c10_ODE_Hand_Model_v08_IPC_v03), &c10_u0, 1, 3,
                0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_b_is_active_c10_ODE_Hand_Model_v08_IPC_v03);
  return c10_y;
}

static void c10_refp2_ceval_xswap(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c10_n, real_T c10_x[100],
  int32_T c10_ix0, int32_T c10_incx, int32_T c10_iy0, int32_T c10_incy)
{
  /* Empty Loop. */
  dswap32(&c10_n, &c10_x[sf_mex_lw_bounds_check(c10_ix0, 1, 100) - 1], &c10_incx,
          &c10_x[sf_mex_lw_bounds_check(c10_iy0, 1, 100) - 1]
          , &c10_incy);
}

static void c10_refp8_ceval_xger(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, int32_T c10_m, int32_T c10_n, real_T
  c10_alpha1, int32_T c10_ix0, int32_T c10_incx, int32_T c10_iy0, int32_T
  c10_incy, real_T c10_A[100], int32_T c10_ia0, int32_T
  c10_lda)
{
  dger32(&c10_m, &c10_n, &c10_alpha1, &c10_A[sf_mex_lw_bounds_check(c10_ix0, 1,
          100) - 1], &c10_incx, &c10_A[sf_mex_lw_bounds_check(
          c10_iy0, 1, 100) - 1], &c10_incy, &c10_A[sf_mex_lw_bounds_check
         (c10_ia0, 1, 100) - 1], &c10_lda);
}

static void c10_refp7_ceval_xtrsm(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c10_m, int32_T c10_n,
  real_T c10_alpha1, real_T c10_A[100], int32_T c10_ia0, int32_T c10_lda, real_T
  c10_B[100], int32_T c10_ib0, int32_T c10_ldb)
{
  char_T c10_SIDE;
  char_T c10_UPLO;
  char_T c10_TRANSA;
  char_T c10_DIAGA;
  c10_SIDE = 'L';
  c10_UPLO = 'U';
  c10_TRANSA = 'N';
  c10_DIAGA = 'N';
  dtrsm32(&c10_SIDE, &c10_UPLO, &c10_TRANSA, &c10_DIAGA, &c10_m, &c10_n,
          &c10_alpha1, &c10_A[sf_mex_lw_bounds_check(c10_ia0, 1, 100)
          - 1], &c10_lda, &c10_B[sf_mex_lw_bounds_check(c10_ib0, 1, 100) - 1],
          &c10_ldb);
}

static void init_dsm_address_info(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c10_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1918672192U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1482972178U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3261845545U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4193601036U);
}

mxArray *sf_c10_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1313749230U);
    pr[1] = (double)(1060062271U);
    pr[2] = (double)(2367577651U);
    pr[3] = (double)(2190407580U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
      pr[1] = (double)(10);
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
      pr[0] = (double)(10);
      pr[1] = (double)(10);
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

static mxArray *sf_get_sim_state_info_c10_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c10_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c10_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c10_ODE_Hand_Model_v08_IPC_v03
    ((SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c10_ODE_Hand_Model_v08_IPC_v03
    ((SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c10_ODE_Hand_Model_v08_IPC_v03
    ((SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c10_ODE_Hand_Model_v08_IPC_v03
    ((SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c10_ODE_Hand_Model_v08_IPC_v03
    ((SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c10_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_ODE_Hand_Model_v08_IPC_v03
    ((SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c10_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c10_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_ODE_Hand_Model_v08_IPC_v03
    ((SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c10_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c10_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c10_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c10_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c10_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c10_ODE_Hand_Model_v08_IPC_v03
      ((SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_ODE_Hand_Model_v08_IPC_v03
      ((SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",10,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",10,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",10,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2551910602U));
  ssSetChecksum1(S,(3039569047U));
  ssSetChecksum2(S,(2132817755U));
  ssSetChecksum3(S,(3848276697U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c10_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",10);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc
    (sizeof(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c10_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_ODE_Hand_Model_v08_IPC_v03;
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

void c10_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
