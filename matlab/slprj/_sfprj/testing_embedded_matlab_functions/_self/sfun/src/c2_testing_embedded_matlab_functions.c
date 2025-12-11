/* Include files */

#include "blascompat32.h"
#include "testing_embedded_matlab_functions_sfun.h"
#include "c2_testing_embedded_matlab_functions.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "testing_embedded_matlab_functions_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c2_debug_family_names[14] = { "x1", "x2", "x3", "x4", "r1",
  "r1_unit", "r3", "r3_unit", "r2_unit", "l", "nargin", "nargout", "xi", "RO" };

static const char *c2_b_debug_family_names[5] = { "d", "nargin", "nargout", "l",
  "h" };

static const char *c2_c_debug_family_names[4] = { "nargin", "nargout", "v", "S"
};

static const char *c2_d_debug_family_names[5] = { "d", "nargin", "nargout", "l",
  "h" };

static const char *c2_e_debug_family_names[4] = { "nargin", "nargout", "v", "S"
};

/* Function Declarations */
static void initialize_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance);
static void initialize_params_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance);
static void enable_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance);
static void disable_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance);
static void set_sim_state_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance, const
   mxArray *c2_st);
static void finalize_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance);
static void sf_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance);
static void c2_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static real_T c2_norm(SFc2_testing_embedded_matlab_functionsInstanceStruct
                      *chartInstance, real_T c2_x[3]);
static real_T c2_ceval_xnrm2
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance, int32_T
   c2_n, real_T c2_x[3], int32_T c2_ix0, int32_T c2_incx);
static void c2_skew(SFc2_testing_embedded_matlab_functionsInstanceStruct
                    *chartInstance, real_T c2_v[3], real_T c2_S[9]);
static void c2_eml_scalar_eg
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance);
static real_T c2_b_norm(SFc2_testing_embedded_matlab_functionsInstanceStruct
  *chartInstance, real_T c2_x[3]);
static real_T c2_b_ceval_xnrm2
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance, int32_T
   c2_n, real_T c2_x[3], int32_T c2_ix0, int32_T c2_incx);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_e_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_f_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_g_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[61]);
static void c2_emlrt_marshallIn
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance, const
   mxArray *c2_RO, const char_T *c2_name, real_T c2_y[9]);
static uint8_T c2_b_emlrt_marshallIn
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_testing_embedded_matlab_functions, const char_T
   *c2_name);
static void init_dsm_address_info
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_testing_embedded_matlab_functions = 0U;
}

static void initialize_params_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *
   chartInstance)
{
}

static void enable_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *
   chartInstance)
{
}

static const mxArray *get_sim_state_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *
   chartInstance)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_hoistedGlobal[9];
  int32_T c2_i1;
  real_T c2_u[9];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_RO)[9];
  c2_RO = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  for (c2_i0 = 0; c2_i0 < 9; c2_i0 = c2_i0 + 1) {
    c2_hoistedGlobal[c2_i0] = (*c2_RO)[c2_i0];
  }

  for (c2_i1 = 0; c2_i1 < 9; c2_i1 = c2_i1 + 1) {
    c2_u[c2_i1] = c2_hoistedGlobal[c2_i1];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal =
    chartInstance->c2_is_active_c2_testing_embedded_matlab_functions;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance,
   const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[9];
  int32_T c2_i2;
  real_T (*c2_RO)[9];
  c2_RO = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "RO",
                      c2_dv0);
  for (c2_i2 = 0; c2_i2 < 9; c2_i2 = c2_i2 + 1) {
    (*c2_RO)[c2_i2] = c2_dv0[c2_i2];
  }

  chartInstance->c2_is_active_c2_testing_embedded_matlab_functions =
    c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    c2_u, 1)), "is_active_c2_testing_embedded_matlab_functions");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_testing_embedded_matlab_functions(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance)
{
}

static void sf_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance)
{
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_previousEvent;
  real_T (*c2_RO)[9];
  real_T (*c2_xi)[12];
  c2_RO = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_xi = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  for (c2_i3 = 0; c2_i3 < 12; c2_i3 = c2_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_xi)[c2_i3], 0U);
  }

  for (c2_i4 = 0; c2_i4 < 9; c2_i4 = c2_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_RO)[c2_i4], 1U);
  }

  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_testing_embedded_matlab_functions(chartInstance);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_testing_embedded_matlab_functionsMachineNumber_,
     chartInstance->chartNumber, chartInstance->
     instanceNumber);
}

static void c2_c2_testing_embedded_matlab_functions
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance)
{
  int32_T c2_i5;
  real_T c2_hoistedGlobal[12];
  int32_T c2_i6;
  real_T c2_xi[12];
  uint32_T c2_debug_family_var_map[14];
  static const char *c2_sv0[14] = { "x1", "x2", "x3", "x4", "r1", "r1_unit",
    "r3", "r3_unit", "r2_unit", "l", "nargin", "nargout",
    "xi", "RO" };

  real_T c2_x1[3];
  real_T c2_x2[3];
  real_T c2_x3[3];
  real_T c2_x4[3];
  real_T c2_r1[3];
  real_T c2_r1_unit[3];
  real_T c2_r3[3];
  real_T c2_r3_unit[3];
  real_T c2_r2_unit[3];
  real_T c2_l[9];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_RO[9];
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  real_T c2_A[3];
  int32_T c2_i16;
  real_T c2_b_x1[3];
  real_T c2_B;
  int32_T c2_i17;
  real_T c2_x[3];
  real_T c2_y;
  int32_T c2_i18;
  real_T c2_b_x[3];
  real_T c2_b_y;
  int32_T c2_i19;
  real_T c2_c_x[3];
  real_T c2_c_y;
  int32_T c2_i20;
  real_T c2_d_y[3];
  int32_T c2_i21;
  real_T c2_b_A[3];
  int32_T c2_i22;
  real_T c2_b_x2[3];
  real_T c2_b_B;
  int32_T c2_i23;
  real_T c2_d_x[3];
  real_T c2_e_y;
  int32_T c2_i24;
  real_T c2_e_x[3];
  real_T c2_f_y;
  int32_T c2_i25;
  real_T c2_f_x[3];
  real_T c2_g_y;
  int32_T c2_i26;
  real_T c2_h_y[3];
  int32_T c2_i27;
  int32_T c2_i28;
  real_T c2_c_A[3];
  int32_T c2_i29;
  real_T c2_b_r1[3];
  real_T c2_c_B;
  int32_T c2_i30;
  real_T c2_g_x[3];
  real_T c2_i_y;
  int32_T c2_i31;
  real_T c2_h_x[3];
  real_T c2_j_y;
  int32_T c2_i32;
  real_T c2_i_x[3];
  real_T c2_k_y;
  int32_T c2_i33;
  int32_T c2_i34;
  real_T c2_c_x1[3];
  real_T c2_a[9];
  int32_T c2_i35;
  real_T c2_b[3];
  int32_T c2_i36;
  real_T c2_d_A[9];
  int32_T c2_i37;
  real_T c2_d_B[3];
  int32_T c2_i38;
  int32_T c2_i39;
  real_T c2_e_A[9];
  int32_T c2_i40;
  real_T c2_e_B[3];
  int32_T c2_i41;
  real_T c2_f_A[9];
  int32_T c2_i42;
  real_T c2_f_B[3];
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  real_T c2_g_A[3];
  int32_T c2_i47;
  real_T c2_b_r3[3];
  real_T c2_g_B;
  int32_T c2_i48;
  real_T c2_j_x[3];
  real_T c2_l_y;
  int32_T c2_i49;
  real_T c2_k_x[3];
  real_T c2_m_y;
  int32_T c2_i50;
  real_T c2_l_x[3];
  real_T c2_n_y;
  int32_T c2_i51;
  int32_T c2_i52;
  real_T c2_v[3];
  uint32_T c2_b_debug_family_var_map[4];
  static const char *c2_sv1[4] = { "nargin", "nargout", "v", "S" };

  real_T c2_b_nargin = 1.0;
  real_T c2_b_nargout = 1.0;
  real_T c2_S[9];
  real_T c2_b_l;
  uint32_T c2_c_debug_family_var_map[5];
  static const char *c2_sv2[5] = { "d", "nargin", "nargout", "l", "h" };

  real_T c2_d[2];
  real_T c2_c_nargin = 2.0;
  real_T c2_c_nargout = 1.0;
  boolean_T c2_h;
  int32_T c2_i53;
  boolean_T c2_b0;
  int32_T c2_i54;
  real_T c2_b_a[9];
  int32_T c2_i55;
  real_T c2_b_b[3];
  int32_T c2_i56;
  real_T c2_h_A[9];
  int32_T c2_i57;
  real_T c2_h_B[3];
  int32_T c2_i58;
  int32_T c2_i59;
  real_T c2_i_A[9];
  int32_T c2_i60;
  real_T c2_i_B[3];
  int32_T c2_i61;
  real_T c2_j_A[9];
  int32_T c2_i62;
  real_T c2_j_B[3];
  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  int32_T c2_i70;
  real_T (*c2_b_RO)[9];
  real_T (*c2_b_xi)[12];
  c2_b_RO = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_xi = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for (c2_i5 = 0; c2_i5 < 12; c2_i5 = c2_i5 + 1) {
    c2_hoistedGlobal[c2_i5] = (*c2_b_xi)[c2_i5];
  }

  for (c2_i6 = 0; c2_i6 < 12; c2_i6 = c2_i6 + 1) {
    c2_xi[c2_i6] = c2_hoistedGlobal[c2_i6];
  }

  sf_debug_symbol_scope_push_eml(0U, 14U, 14U, c2_sv0, c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_x1, c2_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_x2, c2_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_x3, c2_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_x4, c2_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c2_r1, c2_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c2_r1_unit, c2_e_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c2_r3, c2_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c2_r3_unit, c2_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c2_r2_unit, c2_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c2_l, c2_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_c_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_c_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c2_xi, c2_b_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c2_RO, c2_sf_marshall, 13U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,6);
  c2_i7 = 0;
  for (c2_i8 = 0; c2_i8 < 3; c2_i8 = c2_i8 + 1) {
    c2_x1[c2_i8] = c2_xi[c2_i7];
    c2_i7 = c2_i7 + 4;
  }

  _SFD_EML_CALL(0,7);
  c2_i9 = 0;
  for (c2_i10 = 0; c2_i10 < 3; c2_i10 = c2_i10 + 1) {
    c2_x2[c2_i10] = c2_xi[c2_i9 + 1];
    c2_i9 = c2_i9 + 4;
  }

  _SFD_EML_CALL(0,8);
  c2_i11 = 0;
  for (c2_i12 = 0; c2_i12 < 3; c2_i12 = c2_i12 + 1) {
    c2_x3[c2_i12] = c2_xi[c2_i11 + 2];
    c2_i11 = c2_i11 + 4;
  }

  _SFD_EML_CALL(0,9);
  c2_i13 = 0;
  for (c2_i14 = 0; c2_i14 < 3; c2_i14 = c2_i14 + 1) {
    c2_x4[c2_i14] = c2_xi[c2_i13 + 3];
    c2_i13 = c2_i13 + 4;
  }

  /*  r1=( xi(1,:)-xi(3,:) )/norm( xi(1,:)-xi(3,:) ) + ... */
  /*      ( xi(2,:)-xi(4,:) )/norm( xi(2,:)-xi(4,:) ); */
  _SFD_EML_CALL(0,14);
  for (c2_i15 = 0; c2_i15 < 3; c2_i15 = c2_i15 + 1) {
    c2_A[c2_i15] = c2_x1[c2_i15] - c2_x3[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 3; c2_i16 = c2_i16 + 1) {
    c2_b_x1[c2_i16] = c2_x1[c2_i16] - c2_x3[c2_i16];
  }

  c2_B = c2_norm(chartInstance, c2_b_x1);
  for (c2_i17 = 0; c2_i17 < 3; c2_i17 = c2_i17 + 1) {
    c2_x[c2_i17] = c2_A[c2_i17];
  }

  c2_y = c2_B;
  for (c2_i18 = 0; c2_i18 < 3; c2_i18 = c2_i18 + 1) {
    c2_b_x[c2_i18] = c2_x[c2_i18];
  }

  c2_b_y = c2_y;
  for (c2_i19 = 0; c2_i19 < 3; c2_i19 = c2_i19 + 1) {
    c2_c_x[c2_i19] = c2_b_x[c2_i19];
  }

  c2_c_y = c2_b_y;
  for (c2_i20 = 0; c2_i20 < 3; c2_i20 = c2_i20 + 1) {
    c2_d_y[c2_i20] = c2_c_x[c2_i20] / c2_c_y;
  }

  for (c2_i21 = 0; c2_i21 < 3; c2_i21 = c2_i21 + 1) {
    c2_b_A[c2_i21] = c2_x2[c2_i21] - c2_x4[c2_i21];
  }

  for (c2_i22 = 0; c2_i22 < 3; c2_i22 = c2_i22 + 1) {
    c2_b_x2[c2_i22] = c2_x2[c2_i22] - c2_x4[c2_i22];
  }

  c2_b_B = c2_norm(chartInstance, c2_b_x2);
  for (c2_i23 = 0; c2_i23 < 3; c2_i23 = c2_i23 + 1) {
    c2_d_x[c2_i23] = c2_b_A[c2_i23];
  }

  c2_e_y = c2_b_B;
  for (c2_i24 = 0; c2_i24 < 3; c2_i24 = c2_i24 + 1) {
    c2_e_x[c2_i24] = c2_d_x[c2_i24];
  }

  c2_f_y = c2_e_y;
  for (c2_i25 = 0; c2_i25 < 3; c2_i25 = c2_i25 + 1) {
    c2_f_x[c2_i25] = c2_e_x[c2_i25];
  }

  c2_g_y = c2_f_y;
  for (c2_i26 = 0; c2_i26 < 3; c2_i26 = c2_i26 + 1) {
    c2_h_y[c2_i26] = c2_f_x[c2_i26] / c2_g_y;
  }

  for (c2_i27 = 0; c2_i27 < 3; c2_i27 = c2_i27 + 1) {
    c2_r1[c2_i27] = c2_d_y[c2_i27] + c2_h_y[c2_i27];
  }

  _SFD_EML_CALL(0,18);
  for (c2_i28 = 0; c2_i28 < 3; c2_i28 = c2_i28 + 1) {
    c2_c_A[c2_i28] = c2_r1[c2_i28];
  }

  for (c2_i29 = 0; c2_i29 < 3; c2_i29 = c2_i29 + 1) {
    c2_b_r1[c2_i29] = c2_r1[c2_i29];
  }

  c2_c_B = c2_norm(chartInstance, c2_b_r1);
  for (c2_i30 = 0; c2_i30 < 3; c2_i30 = c2_i30 + 1) {
    c2_g_x[c2_i30] = c2_c_A[c2_i30];
  }

  c2_i_y = c2_c_B;
  for (c2_i31 = 0; c2_i31 < 3; c2_i31 = c2_i31 + 1) {
    c2_h_x[c2_i31] = c2_g_x[c2_i31];
  }

  c2_j_y = c2_i_y;
  for (c2_i32 = 0; c2_i32 < 3; c2_i32 = c2_i32 + 1) {
    c2_i_x[c2_i32] = c2_h_x[c2_i32];
  }

  c2_k_y = c2_j_y;
  for (c2_i33 = 0; c2_i33 < 3; c2_i33 = c2_i33 + 1) {
    c2_r1_unit[c2_i33] = c2_i_x[c2_i33] / c2_k_y;
  }

  /*  r3= cross( (x1-x3),( x2-x4 ))'; */
  _SFD_EML_CALL(0,22);
  for (c2_i34 = 0; c2_i34 < 3; c2_i34 = c2_i34 + 1) {
    c2_c_x1[c2_i34] = c2_x1[c2_i34] - c2_x3[c2_i34];
  }

  c2_skew(chartInstance, c2_c_x1, c2_a);
  for (c2_i35 = 0; c2_i35 < 3; c2_i35 = c2_i35 + 1) {
    c2_b[c2_i35] = c2_x2[c2_i35] - c2_x4[c2_i35];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i36 = 0; c2_i36 < 9; c2_i36 = c2_i36 + 1) {
    c2_d_A[c2_i36] = c2_a[c2_i36];
  }

  for (c2_i37 = 0; c2_i37 < 3; c2_i37 = c2_i37 + 1) {
    c2_d_B[c2_i37] = c2_b[c2_i37];
  }

  for (c2_i38 = 0; c2_i38 < 3; c2_i38 = c2_i38 + 1) {
    c2_r3[c2_i38] = 0.0;
  }

  for (c2_i39 = 0; c2_i39 < 9; c2_i39 = c2_i39 + 1) {
    c2_e_A[c2_i39] = c2_d_A[c2_i39];
  }

  for (c2_i40 = 0; c2_i40 < 3; c2_i40 = c2_i40 + 1) {
    c2_e_B[c2_i40] = c2_d_B[c2_i40];
  }

  for (c2_i41 = 0; c2_i41 < 9; c2_i41 = c2_i41 + 1) {
    c2_f_A[c2_i41] = c2_e_A[c2_i41];
  }

  for (c2_i42 = 0; c2_i42 < 3; c2_i42 = c2_i42 + 1) {
    c2_f_B[c2_i42] = c2_e_B[c2_i42];
  }

  for (c2_i43 = 0; c2_i43 < 3; c2_i43 = c2_i43 + 1) {
    c2_r3[c2_i43] = 0.0;
    c2_i44 = 0;
    for (c2_i45 = 0; c2_i45 < 3; c2_i45 = c2_i45 + 1) {
      c2_r3[c2_i43] = c2_r3[c2_i43] + c2_f_A[c2_i44 + c2_i43] * c2_f_B[c2_i45];
      c2_i44 = c2_i44 + 3;
    }
  }

  _SFD_EML_CALL(0,23);
  for (c2_i46 = 0; c2_i46 < 3; c2_i46 = c2_i46 + 1) {
    c2_g_A[c2_i46] = c2_r3[c2_i46];
  }

  for (c2_i47 = 0; c2_i47 < 3; c2_i47 = c2_i47 + 1) {
    c2_b_r3[c2_i47] = c2_r3[c2_i47];
  }

  c2_g_B = c2_b_norm(chartInstance, c2_b_r3);
  for (c2_i48 = 0; c2_i48 < 3; c2_i48 = c2_i48 + 1) {
    c2_j_x[c2_i48] = c2_g_A[c2_i48];
  }

  c2_l_y = c2_g_B;
  for (c2_i49 = 0; c2_i49 < 3; c2_i49 = c2_i49 + 1) {
    c2_k_x[c2_i49] = c2_j_x[c2_i49];
  }

  c2_m_y = c2_l_y;
  for (c2_i50 = 0; c2_i50 < 3; c2_i50 = c2_i50 + 1) {
    c2_l_x[c2_i50] = c2_k_x[c2_i50];
  }

  c2_n_y = c2_m_y;
  for (c2_i51 = 0; c2_i51 < 3; c2_i51 = c2_i51 + 1) {
    c2_r3_unit[c2_i51] = c2_l_x[c2_i51] / c2_n_y;
  }

  _SFD_EML_CALL(0,25);
  for (c2_i52 = 0; c2_i52 < 3; c2_i52 = c2_i52 + 1) {
    c2_v[c2_i52] = c2_r3_unit[c2_i52];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c2_sv1, c2_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_b_nargin, c2_c_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_b_nargout, c2_c_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_v, c2_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_S, c2_sf_marshall, 3U);
  CV_SCRIPT_FCN(0, 0);

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
  _SFD_SCRIPT_CALL(0,30);
  c2_b_l = 3.0;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c2_sv2, c2_c_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_d, c2_g_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_c_nargin, c2_c_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_c_nargout, c2_c_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_b_l, c2_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c2_h, c2_f_sf_marshall, 4U);
  CV_SCRIPT_FCN(1, 0);

  /* ISVEC Test if argument is a vector */
  /*  */
  /*  ISVEC(V) is true (1) if the argument V is a 3-vector, else false (0). */
  /*  */
  /*  ISVEC(V, L) is true (1) if the argument V is a vector of length L, */
  /*  either a row- or column-vector.  Otherwise false (0). */
  /*  */
  /*  Notes:: */
  /*  - differs from MATLAB builtin function ISVECTOR, the latter returns true */
  /*    for the case of a scalar, ISVEC does not. */
  /*  */
  /*  See also ISHOMOG, ISROT. */
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
  _SFD_SCRIPT_CALL(1,33);
  CV_SCRIPT_IF(1, 0, FALSE);
  _SFD_SCRIPT_CALL(1,36);
  for (c2_i53 = 0; c2_i53 < 2; c2_i53 = c2_i53 + 1) {
    c2_d[c2_i53] = 3.0 + -2.0 * (real_T)c2_i53;
  }

  _SFD_SCRIPT_CALL(1,37);
  if (3.0 == c2_b_l) {
    c2_b0 = TRUE;
  } else {
    c2_b0 = FALSE;
  }

  c2_h = c2_b0;
  _SFD_SCRIPT_CALL(1,-37);
  sf_debug_symbol_scope_pop();
  CV_SCRIPT_IF(0, 0, c2_h);

  /*  SO(3) case */
  _SFD_SCRIPT_CALL(0,32);
  c2_S[0] = 0.0;
  c2_S[3] = -c2_v[2];
  c2_S[6] = c2_v[1];
  c2_S[1] = c2_v[2];
  c2_S[4] = 0.0;
  c2_S[7] = -c2_v[0];
  c2_S[2] = -c2_v[1];
  c2_S[5] = c2_v[0];
  c2_S[8] = 0.0;
  _SFD_SCRIPT_CALL(0,-39);
  sf_debug_symbol_scope_pop();
  for (c2_i54 = 0; c2_i54 < 9; c2_i54 = c2_i54 + 1) {
    c2_b_a[c2_i54] = c2_S[c2_i54];
  }

  for (c2_i55 = 0; c2_i55 < 3; c2_i55 = c2_i55 + 1) {
    c2_b_b[c2_i55] = c2_r1_unit[c2_i55];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i56 = 0; c2_i56 < 9; c2_i56 = c2_i56 + 1) {
    c2_h_A[c2_i56] = c2_b_a[c2_i56];
  }

  for (c2_i57 = 0; c2_i57 < 3; c2_i57 = c2_i57 + 1) {
    c2_h_B[c2_i57] = c2_b_b[c2_i57];
  }

  for (c2_i58 = 0; c2_i58 < 3; c2_i58 = c2_i58 + 1) {
    c2_r2_unit[c2_i58] = 0.0;
  }

  for (c2_i59 = 0; c2_i59 < 9; c2_i59 = c2_i59 + 1) {
    c2_i_A[c2_i59] = c2_h_A[c2_i59];
  }

  for (c2_i60 = 0; c2_i60 < 3; c2_i60 = c2_i60 + 1) {
    c2_i_B[c2_i60] = c2_h_B[c2_i60];
  }

  for (c2_i61 = 0; c2_i61 < 9; c2_i61 = c2_i61 + 1) {
    c2_j_A[c2_i61] = c2_i_A[c2_i61];
  }

  for (c2_i62 = 0; c2_i62 < 3; c2_i62 = c2_i62 + 1) {
    c2_j_B[c2_i62] = c2_i_B[c2_i62];
  }

  for (c2_i63 = 0; c2_i63 < 3; c2_i63 = c2_i63 + 1) {
    c2_r2_unit[c2_i63] = 0.0;
    c2_i64 = 0;
    for (c2_i65 = 0; c2_i65 < 3; c2_i65 = c2_i65 + 1) {
      c2_r2_unit[c2_i63] = c2_r2_unit[c2_i63] + c2_j_A[c2_i64 + c2_i63] *
        c2_j_B[c2_i65];
      c2_i64 = c2_i64 + 3;
    }
  }

  _SFD_EML_CALL(0,27);
  for (c2_i66 = 0; c2_i66 < 3; c2_i66 = c2_i66 + 1) {
    c2_l[c2_i66] = c2_r1_unit[c2_i66];
  }

  for (c2_i67 = 0; c2_i67 < 3; c2_i67 = c2_i67 + 1) {
    c2_l[c2_i67 + 3] = c2_r2_unit[c2_i67];
  }

  for (c2_i68 = 0; c2_i68 < 3; c2_i68 = c2_i68 + 1) {
    c2_l[c2_i68 + 6] = c2_r3_unit[c2_i68];
  }

  _SFD_EML_CALL(0,28);
  for (c2_i69 = 0; c2_i69 < 9; c2_i69 = c2_i69 + 1) {
    c2_RO[c2_i69] = c2_l[c2_i69];
  }

  _SFD_EML_CALL(0,-28);
  sf_debug_symbol_scope_pop();
  for (c2_i70 = 0; c2_i70 < 9; c2_i70 = c2_i70 + 1) {
    (*c2_b_RO)[c2_i70] = c2_RO[c2_i70];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 0U, sf_debug_get_script_id(
    "C:/Users/konstantinos/Documents/MATLAB/Thesis_Control_Building_stage8_IMU_Input/robot/skew.m"));
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 1U, sf_debug_get_script_id(
    "C:/Users/konstantinos/Documents/MATLAB/Thesis_Control_Building_stage8_IMU_Input/robot/isvec.m"));
}

static real_T c2_norm(SFc2_testing_embedded_matlab_functionsInstanceStruct
                      *chartInstance, real_T c2_x[3])
{
  int32_T c2_i71;
  real_T c2_b_x[3];
  int32_T c2_i72;
  real_T c2_c_x[3];
  int32_T c2_i73;
  real_T c2_d_x[3];
  int32_T c2_i74;
  real_T c2_e_x[3];
  for (c2_i71 = 0; c2_i71 < 3; c2_i71 = c2_i71 + 1) {
    c2_b_x[c2_i71] = c2_x[c2_i71];
  }

  for (c2_i72 = 0; c2_i72 < 3; c2_i72 = c2_i72 + 1) {
    c2_c_x[c2_i72] = c2_b_x[c2_i72];
  }

  for (c2_i73 = 0; c2_i73 < 3; c2_i73 = c2_i73 + 1) {
    c2_d_x[c2_i73] = c2_c_x[c2_i73];
  }

  for (c2_i74 = 0; c2_i74 < 3; c2_i74 = c2_i74 + 1) {
    c2_e_x[c2_i74] = c2_d_x[c2_i74];
  }

  return c2_ceval_xnrm2(chartInstance, 3, c2_e_x, 1, 1);
}

static real_T c2_ceval_xnrm2
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance, int32_T
   c2_n, real_T c2_x[3],
   int32_T c2_ix0, int32_T c2_incx)
{
  return dnrm232(&c2_n, &c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c2_ix0), 1, 3, 1, 0) - 1], &
                 c2_incx);
}

static void c2_skew(SFc2_testing_embedded_matlab_functionsInstanceStruct
                    *chartInstance, real_T c2_v[3], real_T c2_S[9])
{
  uint32_T c2_debug_family_var_map[4];
  static const char *c2_sv3[4] = { "nargin", "nargout", "v", "S" };

  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_l;
  uint32_T c2_b_debug_family_var_map[5];
  static const char *c2_sv4[5] = { "d", "nargin", "nargout", "l", "h" };

  real_T c2_d[2];
  real_T c2_b_nargin = 2.0;
  real_T c2_b_nargout = 1.0;
  boolean_T c2_h;
  int32_T c2_i75;
  boolean_T c2_b1;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c2_sv3, c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_c_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_c_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c2_v, c2_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c2_S, c2_sf_marshall, 3U);
  CV_SCRIPT_FCN(0, 0);

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
  _SFD_SCRIPT_CALL(0,30);
  c2_l = 3.0;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c2_sv4, c2_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_d, c2_g_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_b_nargin, c2_c_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_b_nargout, c2_c_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_l, c2_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c2_h, c2_f_sf_marshall, 4U);
  CV_SCRIPT_FCN(1, 0);

  /* ISVEC Test if argument is a vector */
  /*  */
  /*  ISVEC(V) is true (1) if the argument V is a 3-vector, else false (0). */
  /*  */
  /*  ISVEC(V, L) is true (1) if the argument V is a vector of length L, */
  /*  either a row- or column-vector.  Otherwise false (0). */
  /*  */
  /*  Notes:: */
  /*  - differs from MATLAB builtin function ISVECTOR, the latter returns true */
  /*    for the case of a scalar, ISVEC does not. */
  /*  */
  /*  See also ISHOMOG, ISROT. */
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
  _SFD_SCRIPT_CALL(1,33);
  CV_SCRIPT_IF(1, 0, FALSE);
  _SFD_SCRIPT_CALL(1,36);
  for (c2_i75 = 0; c2_i75 < 2; c2_i75 = c2_i75 + 1) {
    c2_d[c2_i75] = 1.0 + 2.0 * (real_T)c2_i75;
  }

  _SFD_SCRIPT_CALL(1,37);
  if (3.0 == c2_l) {
    c2_b1 = TRUE;
  } else {
    c2_b1 = FALSE;
  }

  c2_h = c2_b1;
  _SFD_SCRIPT_CALL(1,-37);
  sf_debug_symbol_scope_pop();
  CV_SCRIPT_IF(0, 0, c2_h);

  /*  SO(3) case */
  _SFD_SCRIPT_CALL(0,32);
  c2_S[0] = 0.0;
  c2_S[3] = -c2_v[2];
  c2_S[6] = c2_v[1];
  c2_S[1] = c2_v[2];
  c2_S[4] = 0.0;
  c2_S[7] = -c2_v[0];
  c2_S[2] = -c2_v[1];
  c2_S[5] = c2_v[0];
  c2_S[8] = 0.0;
  _SFD_SCRIPT_CALL(0,-39);
  sf_debug_symbol_scope_pop();
}

static void c2_eml_scalar_eg
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance)
{
}

static real_T c2_b_norm(SFc2_testing_embedded_matlab_functionsInstanceStruct
  *chartInstance, real_T c2_x[3])
{
  int32_T c2_i76;
  real_T c2_b_x[3];
  int32_T c2_i77;
  real_T c2_c_x[3];
  int32_T c2_i78;
  real_T c2_d_x[3];
  int32_T c2_i79;
  real_T c2_e_x[3];
  for (c2_i76 = 0; c2_i76 < 3; c2_i76 = c2_i76 + 1) {
    c2_b_x[c2_i76] = c2_x[c2_i76];
  }

  for (c2_i77 = 0; c2_i77 < 3; c2_i77 = c2_i77 + 1) {
    c2_c_x[c2_i77] = c2_b_x[c2_i77];
  }

  for (c2_i78 = 0; c2_i78 < 3; c2_i78 = c2_i78 + 1) {
    c2_d_x[c2_i78] = c2_c_x[c2_i78];
  }

  for (c2_i79 = 0; c2_i79 < 3; c2_i79 = c2_i79 + 1) {
    c2_e_x[c2_i79] = c2_d_x[c2_i79];
  }

  return c2_b_ceval_xnrm2(chartInstance, 3, c2_e_x, 1, 1);
}

static real_T c2_b_ceval_xnrm2
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance, int32_T
   c2_n, real_T c2_x[3],
   int32_T c2_ix0, int32_T c2_incx)
{
  return dnrm232(&c2_n, &c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c2_ix0), 1, 3, 1, 0) - 1], &
                 c2_incx);
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  real_T c2_b_u[9];
  const mxArray *c2_b_y = NULL;
  SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance;
  chartInstance = (SFc2_testing_embedded_matlab_functionsInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_i80 = 0;
  for (c2_i81 = 0; c2_i81 < 3; c2_i81 = c2_i81 + 1) {
    for (c2_i82 = 0; c2_i82 < 3; c2_i82 = c2_i82 + 1) {
      c2_b_u[c2_i82 + c2_i80] = (*((real_T (*)[9])c2_u))[c2_i82 + c2_i80];
    }

    c2_i80 = c2_i80 + 3;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i83;
  int32_T c2_i84;
  int32_T c2_i85;
  real_T c2_b_u[12];
  const mxArray *c2_b_y = NULL;
  SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance;
  chartInstance = (SFc2_testing_embedded_matlab_functionsInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_i83 = 0;
  for (c2_i84 = 0; c2_i84 < 3; c2_i84 = c2_i84 + 1) {
    for (c2_i85 = 0; c2_i85 < 4; c2_i85 = c2_i85 + 1) {
      c2_b_u[c2_i85 + c2_i83] = (*((real_T (*)[12])c2_u))[c2_i85 + c2_i83];
    }

    c2_i83 = c2_i83 + 4;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 4, 3));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance;
  chartInstance = (SFc2_testing_embedded_matlab_functionsInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_d_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i86;
  real_T c2_b_u[3];
  const mxArray *c2_b_y = NULL;
  SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance;
  chartInstance = (SFc2_testing_embedded_matlab_functionsInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  for (c2_i86 = 0; c2_i86 < 3; c2_i86 = c2_i86 + 1) {
    c2_b_u[c2_i86] = (*((real_T (*)[3])c2_u))[c2_i86];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_e_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i87;
  real_T c2_b_u[3];
  const mxArray *c2_b_y = NULL;
  SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance;
  chartInstance = (SFc2_testing_embedded_matlab_functionsInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  for (c2_i87 = 0; c2_i87 < 3; c2_i87 = c2_i87 + 1) {
    c2_b_u[c2_i87] = (*((real_T (*)[3])c2_u))[c2_i87];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_f_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance;
  chartInstance = (SFc2_testing_embedded_matlab_functionsInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_g_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i88;
  real_T c2_b_u[2];
  const mxArray *c2_b_y = NULL;
  SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance;
  chartInstance = (SFc2_testing_embedded_matlab_functionsInstanceStruct *)
    chartInstanceVoid;
  c2_y = NULL;
  for (c2_i88 = 0; c2_i88 < 2; c2_i88 = c2_i88 + 1) {
    c2_b_u[c2_i88] = (*((real_T (*)[2])c2_u))[c2_i88];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 1, 2));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray
  *sf_c2_testing_embedded_matlab_functions_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[61];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i89;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 61));
  for (c2_i89 = 0; c2_i89 < 61; c2_i89 = c2_i89 + 1) {
    c2_r0 = &c2_info[c2_i89];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i89);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i89);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i89);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i89);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i89);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i89
                    );
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i89
                    );
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[61])
{
  c2_info[0].context = "";
  c2_info[0].name = "minus";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]minus";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "norm";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[1].fileLength = 5312U;
  c2_info[1].fileTime1 = 1262616676U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[2].name = "nargin";
  c2_info[2].dominantType = "";
  c2_info[2].resolved = "[B]nargin";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[3].name = "gt";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[B]gt";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[4].name = "isa";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[B]isa";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[5].name = "ndims";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]ndims";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[6].name = "le";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[B]le";
  c2_info[6].fileLength = 0U;
  c2_info[6].fileTime1 = 0U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[7].name = "eq";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[B]eq";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[8].name = "lt";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[B]lt";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[9].name = "size";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]size";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[10].name = "isempty";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]isempty";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[11].name = "isscalar";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]isscalar";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[12].name = "isvector";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[B]isvector";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c2_info[13].name = "eml_index_class";
  c2_info[13].dominantType = "";
  c2_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[13].fileLength = 909U;
  c2_info[13].fileTime1 = 1192463182U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c2_info[14].name = "ones";
  c2_info[14].dominantType = "char";
  c2_info[14].resolved = "[B]ones";
  c2_info[14].fileLength = 0U;
  c2_info[14].fileTime1 = 0U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c2_info[15].name = "ischar";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[B]ischar";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c2_info[16].name = "eml_xnrm2";
  c2_info[16].dominantType = "int32";
  c2_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c2_info[16].fileLength = 718U;
  c2_info[16].fileTime1 = 1209327256U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_use_refblas.m";
  c2_info[17].name = "strcmp";
  c2_info[17].dominantType = "char";
  c2_info[17].resolved = "[B]strcmp";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c2_info[18].name = "cast";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[B]cast";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c2_info[19].name = "eml_refblas_xnrm2";
  c2_info[19].dominantType = "int32";
  c2_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[19].fileLength = 1433U;
  c2_info[19].fileTime1 = 1240258442U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[20].name = "class";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved = "[B]class";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[21].name = "zeros";
  c2_info[21].dominantType = "char";
  c2_info[21].resolved = "[B]zeros";
  c2_info[21].fileLength = 0U;
  c2_info[21].fileTime1 = 0U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[22].name = "true";
  c2_info[22].dominantType = "";
  c2_info[22].resolved = "[B]true";
  c2_info[22].fileLength = 0U;
  c2_info[22].fileTime1 = 0U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[23].name = "eml_index_minus";
  c2_info[23].dominantType = "int32";
  c2_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[23].fileLength = 277U;
  c2_info[23].fileTime1 = 1192463184U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[24].name = "eml_index_times";
  c2_info[24].dominantType = "int32";
  c2_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[24].fileLength = 280U;
  c2_info[24].fileTime1 = 1192463186U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[25].name = "eml_index_plus";
  c2_info[25].dominantType = "int32";
  c2_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[25].fileLength = 272U;
  c2_info[25].fileTime1 = 1192463184U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[26].name = "real";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved = "[B]real";
  c2_info[26].fileLength = 0U;
  c2_info[26].fileTime1 = 0U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[27].name = "ne";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved = "[B]ne";
  c2_info[27].fileLength = 0U;
  c2_info[27].fileTime1 = 0U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[28].name = "abs";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[28].fileLength = 566U;
  c2_info[28].fileTime1 = 1221263532U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[29].name = "islogical";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved = "[B]islogical";
  c2_info[29].fileLength = 0U;
  c2_info[29].fileTime1 = 0U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[30].name = "eml_scalar_abs";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[30].fileLength = 461U;
  c2_info[30].fileTime1 = 1203444360U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[31].name = "isinteger";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved = "[B]isinteger";
  c2_info[31].fileLength = 0U;
  c2_info[31].fileTime1 = 0U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[32].name = "isreal";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved = "[B]isreal";
  c2_info[32].fileLength = 0U;
  c2_info[32].fileTime1 = 0U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[33].name = "false";
  c2_info[33].dominantType = "";
  c2_info[33].resolved = "[B]false";
  c2_info[33].fileLength = 0U;
  c2_info[33].fileTime1 = 0U;
  c2_info[33].fileTime2 = 0U;
  c2_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[34].name = "times";
  c2_info[34].dominantType = "double";
  c2_info[34].resolved = "[B]times";
  c2_info[34].fileLength = 0U;
  c2_info[34].fileTime1 = 0U;
  c2_info[34].fileTime2 = 0U;
  c2_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[35].name = "plus";
  c2_info[35].dominantType = "double";
  c2_info[35].resolved = "[B]plus";
  c2_info[35].fileLength = 0U;
  c2_info[35].fileTime1 = 0U;
  c2_info[35].fileTime2 = 0U;
  c2_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[36].name = "imag";
  c2_info[36].dominantType = "double";
  c2_info[36].resolved = "[B]imag";
  c2_info[36].fileLength = 0U;
  c2_info[36].fileTime1 = 0U;
  c2_info[36].fileTime2 = 0U;
  c2_info[37].context = "";
  c2_info[37].name = "mrdivide";
  c2_info[37].dominantType = "double";
  c2_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[37].fileLength = 800U;
  c2_info[37].fileTime1 = 1238430690U;
  c2_info[37].fileTime2 = 0U;
  c2_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[38].name = "ge";
  c2_info[38].dominantType = "double";
  c2_info[38].resolved = "[B]ge";
  c2_info[38].fileLength = 0U;
  c2_info[38].fileTime1 = 0U;
  c2_info[38].fileTime2 = 0U;
  c2_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[39].name = "rdivide";
  c2_info[39].dominantType = "double";
  c2_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[39].fileLength = 403U;
  c2_info[39].fileTime1 = 1244731952U;
  c2_info[39].fileTime2 = 0U;
  c2_info[40].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[40].name = "eml_div";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[40].fileLength = 4269U;
  c2_info[40].fileTime1 = 1228090226U;
  c2_info[40].fileTime2 = 0U;
  c2_info[41].context = "";
  c2_info[41].name = "skew";
  c2_info[41].dominantType = "double";
  c2_info[41].resolved =
    "[]C:/Users/konstantinos/Documents/MATLAB/Thesis_Control_Building_stage8_IMU_Input/robot/skew.m";
  c2_info[41].fileLength = 1233U;
  c2_info[41].fileTime1 = 1348594888U;
  c2_info[41].fileTime2 = 0U;
  c2_info[42].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Thesis_Control_Building_stage8_IMU_Input/robot/skew.m";
  c2_info[42].name = "isvec";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved =
    "[]C:/Users/konstantinos/Documents/MATLAB/Thesis_Control_Building_stage8_IMU_Input/robot/isvec.m";
  c2_info[42].fileLength = 1299U;
  c2_info[42].fileTime1 = 1348594888U;
  c2_info[42].fileTime2 = 0U;
  c2_info[43].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Thesis_Control_Building_stage8_IMU_Input/robot/isvec.m";
  c2_info[43].name = "length";
  c2_info[43].dominantType = "double";
  c2_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[43].fileLength = 326U;
  c2_info[43].fileTime1 = 1226573674U;
  c2_info[43].fileTime2 = 0U;
  c2_info[44].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Thesis_Control_Building_stage8_IMU_Input/robot/isvec.m";
  c2_info[44].name = "min";
  c2_info[44].dominantType = "double";
  c2_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[44].fileLength = 362U;
  c2_info[44].fileTime1 = 1244731952U;
  c2_info[44].fileTime2 = 0U;
  c2_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[45].name = "nargout";
  c2_info[45].dominantType = "";
  c2_info[45].resolved = "[B]nargout";
  c2_info[45].fileLength = 0U;
  c2_info[45].fileTime1 = 0U;
  c2_info[45].fileTime2 = 0U;
  c2_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[46].name = "eml_min_or_max";
  c2_info[46].dominantType = "char";
  c2_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[46].fileLength = 9969U;
  c2_info[46].fileTime1 = 1240258406U;
  c2_info[46].fileTime2 = 0U;
  c2_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[47].name = "isnumeric";
  c2_info[47].dominantType = "double";
  c2_info[47].resolved = "[B]isnumeric";
  c2_info[47].fileLength = 0U;
  c2_info[47].fileTime1 = 0U;
  c2_info[47].fileTime2 = 0U;
  c2_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[48].name = "eml_const_nonsingleton_dim";
  c2_info[48].dominantType = "double";
  c2_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c2_info[48].fileLength = 1473U;
  c2_info[48].fileTime1 = 1240258402U;
  c2_info[48].fileTime2 = 0U;
  c2_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m/local_const_nonsingleton_dim";
  c2_info[49].name = "not";
  c2_info[49].dominantType = "logical";
  c2_info[49].resolved = "[B]not";
  c2_info[49].fileLength = 0U;
  c2_info[49].fileTime1 = 0U;
  c2_info[49].fileTime2 = 0U;
  c2_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[50].name = "eml_scalar_eg";
  c2_info[50].dominantType = "double";
  c2_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[50].fileLength = 3068U;
  c2_info[50].fileTime1 = 1240258410U;
  c2_info[50].fileTime2 = 0U;
  c2_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[51].name = "isstruct";
  c2_info[51].dominantType = "double";
  c2_info[51].resolved = "[B]isstruct";
  c2_info[51].fileLength = 0U;
  c2_info[51].fileTime1 = 0U;
  c2_info[51].fileTime2 = 0U;
  c2_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c2_info[52].name = "isnan";
  c2_info[52].dominantType = "double";
  c2_info[52].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[52].fileLength = 506U;
  c2_info[52].fileTime1 = 1228090210U;
  c2_info[52].fileTime2 = 0U;
  c2_info[53].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Thesis_Control_Building_stage8_IMU_Input/robot/isvec.m";
  c2_info[53].name = "numel";
  c2_info[53].dominantType = "double";
  c2_info[53].resolved = "[B]numel";
  c2_info[53].fileLength = 0U;
  c2_info[53].fileTime1 = 0U;
  c2_info[53].fileTime2 = 0U;
  c2_info[54].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Thesis_Control_Building_stage8_IMU_Input/robot/isvec.m";
  c2_info[54].name = "logical";
  c2_info[54].dominantType = "logical";
  c2_info[54].resolved = "[B]logical";
  c2_info[54].fileLength = 0U;
  c2_info[54].fileTime1 = 0U;
  c2_info[54].fileTime2 = 0U;
  c2_info[55].context =
    "[]C:/Users/konstantinos/Documents/MATLAB/Thesis_Control_Building_stage8_IMU_Input/robot/skew.m";
  c2_info[55].name = "uminus";
  c2_info[55].dominantType = "double";
  c2_info[55].resolved = "[B]uminus";
  c2_info[55].fileLength = 0U;
  c2_info[55].fileTime1 = 0U;
  c2_info[55].fileTime2 = 0U;
  c2_info[56].context = "";
  c2_info[56].name = "ctranspose";
  c2_info[56].dominantType = "double";
  c2_info[56].resolved = "[B]ctranspose";
  c2_info[56].fileLength = 0U;
  c2_info[56].fileTime1 = 0U;
  c2_info[56].fileTime2 = 0U;
  c2_info[57].context = "";
  c2_info[57].name = "mtimes";
  c2_info[57].dominantType = "double";
  c2_info[57].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[57].fileLength = 3425U;
  c2_info[57].fileTime1 = 1250669166U;
  c2_info[57].fileTime2 = 0U;
  c2_info[58].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[58].name = "eml_xgemm";
  c2_info[58].dominantType = "int32";
  c2_info[58].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[58].fileLength = 3184U;
  c2_info[58].fileTime1 = 1209327252U;
  c2_info[58].fileTime2 = 0U;
  c2_info[59].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c2_info[59].name = "eml_scalexp_alloc";
  c2_info[59].dominantType = "double";
  c2_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[59].fileLength = 808U;
  c2_info[59].fileTime1 = 1230491098U;
  c2_info[59].fileTime2 = 0U;
  c2_info[60].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[60].name = "eml_refblas_xgemm";
  c2_info[60].dominantType = "int32";
  c2_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[60].fileLength = 5748U;
  c2_info[60].fileTime1 = 1228090272U;
  c2_info[60].fileTime2 = 0U;
}

static void c2_emlrt_marshallIn
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance, const
   mxArray *c2_RO, const
   char_T *c2_name, real_T c2_y[9])
{
  real_T c2_dv1[9];
  int32_T c2_i90;
  sf_mex_import(c2_name, sf_mex_dup(c2_RO), &c2_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c2_i90 = 0; c2_i90 < 9; c2_i90 = c2_i90 + 1) {
    c2_y[c2_i90] = c2_dv1[c2_i90];
  }

  sf_mex_destroy(&c2_RO);
}

static uint8_T c2_b_emlrt_marshallIn
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance, const
   mxArray *
   c2_b_is_active_c2_testing_embedded_matlab_functions, const char_T *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup
                (c2_b_is_active_c2_testing_embedded_matlab_functions), &c2_u0, 1,
                3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_testing_embedded_matlab_functions);
  return c2_y;
}

static void init_dsm_address_info
  (SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_testing_embedded_matlab_functions_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4047609626U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3361242296U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1127675818U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(806688143U);
}

mxArray *sf_c2_testing_embedded_matlab_functions_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1851743948U);
    pr[1] = (double)(3584732691U);
    pr[2] = (double)(3921785175U);
    pr[3] = (double)(1234756608U);
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

static mxArray *sf_get_sim_state_info_c2_testing_embedded_matlab_functions(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"RO\",},{M[8],M[0],T\"is_active_c2_testing_embedded_matlab_functions\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_testing_embedded_matlab_functions_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance;
    chartInstance = (SFc2_testing_embedded_matlab_functionsInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_testing_embedded_matlab_functionsMachineNumber_,
           2,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           2,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_testing_embedded_matlab_functionsMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_testing_embedded_matlab_functionsMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_testing_embedded_matlab_functionsMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[2];
            dimVector[0]= 4;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"xi",0,(MexFcnForType)c2_b_sf_marshall);
          }

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"RO",0,(MexFcnForType)c2_sf_marshall);
          }

          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",6,-1,438);
        _SFD_CV_INIT_SCRIPT(0,1,2,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"skew",944,-1,1233);
        _SFD_CV_INIT_SCRIPT_IF(0,0,969,982,1100,1232);
        _SFD_CV_INIT_SCRIPT_IF(0,1,1100,1117,1168,1232);
        _SFD_CV_INIT_SCRIPT(1,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"isvec",1143,-1,1299);
        _SFD_CV_INIT_SCRIPT_IF(1,0,1172,1186,-1,1213);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c2_xi)[12];
          real_T (*c2_RO)[9];
          c2_RO = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_xi = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_xi);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_RO);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_testing_embedded_matlab_functionsMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_testing_embedded_matlab_functions(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc2_testing_embedded_matlab_functionsInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c2_testing_embedded_matlab_functions
    ((SFc2_testing_embedded_matlab_functionsInstanceStruct*) chartInstanceVar);
  initialize_c2_testing_embedded_matlab_functions
    ((SFc2_testing_embedded_matlab_functionsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_testing_embedded_matlab_functions(void
  *chartInstanceVar)
{
  enable_c2_testing_embedded_matlab_functions
    ((SFc2_testing_embedded_matlab_functionsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_testing_embedded_matlab_functions(void
  *chartInstanceVar)
{
  disable_c2_testing_embedded_matlab_functions
    ((SFc2_testing_embedded_matlab_functionsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_testing_embedded_matlab_functions(void
  *chartInstanceVar)
{
  sf_c2_testing_embedded_matlab_functions
    ((SFc2_testing_embedded_matlab_functionsInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c2_testing_embedded_matlab_functions
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_testing_embedded_matlab_functions
    ((SFc2_testing_embedded_matlab_functionsInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_testing_embedded_matlab_functions();/* state var info */
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

static void sf_internal_set_sim_state_c2_testing_embedded_matlab_functions
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c2_testing_embedded_matlab_functions();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_testing_embedded_matlab_functions
    ((SFc2_testing_embedded_matlab_functionsInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_testing_embedded_matlab_functions
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_testing_embedded_matlab_functions(S);
}

static void sf_opaque_set_sim_state_c2_testing_embedded_matlab_functions
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_testing_embedded_matlab_functions(S, st);
}

static void sf_opaque_terminate_c2_testing_embedded_matlab_functions(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_testing_embedded_matlab_functionsInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_testing_embedded_matlab_functions
      ((SFc2_testing_embedded_matlab_functionsInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_testing_embedded_matlab_functions(SimStruct *
  S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_testing_embedded_matlab_functions
      ((SFc2_testing_embedded_matlab_functionsInstanceStruct*)(((ChartInfoStruct
          *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_testing_embedded_matlab_functions(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("testing_embedded_matlab_functions",
      "testing_embedded_matlab_functions",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("testing_embedded_matlab_functions",
                "testing_embedded_matlab_functions",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "testing_embedded_matlab_functions","testing_embedded_matlab_functions",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"testing_embedded_matlab_functions",
        "testing_embedded_matlab_functions",2,1);
      sf_mark_chart_reusable_outputs(S,"testing_embedded_matlab_functions",
        "testing_embedded_matlab_functions",2,1);
    }

    sf_set_rtw_dwork_info(S,"testing_embedded_matlab_functions",
                          "testing_embedded_matlab_functions",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2662372781U));
  ssSetChecksum1(S,(3409564748U));
  ssSetChecksum2(S,(2614571681U));
  ssSetChecksum3(S,(1831545870U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_testing_embedded_matlab_functions(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "testing_embedded_matlab_functions",
      "testing_embedded_matlab_functions",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_testing_embedded_matlab_functions(SimStruct *S)
{
  SFc2_testing_embedded_matlab_functionsInstanceStruct *chartInstance;
  chartInstance = (SFc2_testing_embedded_matlab_functionsInstanceStruct *)malloc
    (sizeof(SFc2_testing_embedded_matlab_functionsInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc2_testing_embedded_matlab_functionsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_testing_embedded_matlab_functions;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_testing_embedded_matlab_functions;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_testing_embedded_matlab_functions;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_testing_embedded_matlab_functions;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_testing_embedded_matlab_functions;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_testing_embedded_matlab_functions;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_testing_embedded_matlab_functions;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_testing_embedded_matlab_functions;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_testing_embedded_matlab_functions;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c2_testing_embedded_matlab_functions;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_testing_embedded_matlab_functions;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info(chartInstance);
  }

  chart_debug_initialization(S,1);
}

void c2_testing_embedded_matlab_functions_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_testing_embedded_matlab_functions(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_testing_embedded_matlab_functions(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_testing_embedded_matlab_functions(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_testing_embedded_matlab_functions_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
