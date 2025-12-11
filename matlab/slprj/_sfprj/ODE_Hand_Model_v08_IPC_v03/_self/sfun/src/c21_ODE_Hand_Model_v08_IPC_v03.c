/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c21_ODE_Hand_Model_v08_IPC_v03.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c21_st);
static void finalize_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber);
static real_T c21_norm(SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c21_x[3]);
static real_T c21_ceval_xnrm2(SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c21_n, real_T c21_x[3], int32_T c21_ix0, int32_T
  c21_incx);
static void c21_info_helper(c21_ResolvedFunctionInfo c21_info[44]);
static void c21_emlrt_marshallIn(SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c21_Deltax, const char_T *c21_name, real_T
  c21_y[4]);
static uint8_T c21_b_emlrt_marshallIn
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c21_b_is_active_c21_ODE_Hand_Model_v08_IPC_v03, const char_T *c21_name);
static void init_dsm_address_info(SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c21_is_active_c21_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c21_st;
  const mxArray *c21_y = NULL;
  int32_T c21_i0;
  real_T c21_u[4];
  const mxArray *c21_b_y = NULL;
  uint8_T c21_b_u;
  const mxArray *c21_c_y = NULL;
  real_T (*c21_Deltax)[4];
  c21_Deltax = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c21_st = NULL;
  c21_st = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_createcellarray(2));
  for (c21_i0 = 0; c21_i0 < 4; c21_i0 = c21_i0 + 1) {
    c21_u[c21_i0] = (*c21_Deltax)[c21_i0];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c21_y, 0, c21_b_y);
  c21_b_u = chartInstance->c21_is_active_c21_ODE_Hand_Model_v08_IPC_v03;
  c21_c_y = NULL;
  sf_mex_assign(&c21_c_y, sf_mex_create("y", &c21_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c21_y, 1, c21_c_y);
  sf_mex_assign(&c21_st, c21_y);
  return c21_st;
}

static void set_sim_state_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance,
   const mxArray *c21_st)
{
  const mxArray *c21_u;
  real_T c21_dv0[4];
  int32_T c21_i1;
  real_T (*c21_Deltax)[4];
  c21_Deltax = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c21_u = sf_mex_dup(c21_st);
  c21_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 0)),
                       "Deltax", c21_dv0);
  for (c21_i1 = 0; c21_i1 < 4; c21_i1 = c21_i1 + 1) {
    (*c21_Deltax)[c21_i1] = c21_dv0[c21_i1];
  }

  chartInstance->c21_is_active_c21_ODE_Hand_Model_v08_IPC_v03 =
    c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u
    , 1)), "is_active_c21_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c21_u);
  sf_mex_destroy(&c21_st);
}

static void finalize_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c21_ODE_Hand_Model_v08_IPC_v03
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c21_previousEvent;
  int32_T c21_i2;
  int32_T c21_i3;
  real_T c21_x1;
  real_T c21_x2;
  real_T c21_x3;
  real_T c21_x4;
  real_T c21_xO;
  real_T c21_b_x1[3];
  real_T c21_b_xO[3];
  real_T c21_b_x2[3];
  real_T c21_b_x3[3];
  real_T c21_b_x4[3];
  real_T c21_dx[4];
  real_T (*c21_Deltax)[4];
  real_T (*c21_xi)[12];
  c21_Deltax = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c21_xi = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c21_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;

  /*  xO =[0.2000         0    2.0900]; */
  /*   */
  c21_i2 = 0;
  for (c21_i3 = 0; c21_i3 < 3; c21_i3 = c21_i3 + 1) {
    c21_x1 = (*c21_xi)[c21_i2];
    c21_x2 = (*c21_xi)[c21_i2 + 1];
    c21_x3 = (*c21_xi)[c21_i2 + 2];
    c21_x4 = (*c21_xi)[c21_i2 + 3];
    c21_xO = 0.25 * (((c21_x1 + c21_x2) + c21_x3) + c21_x4);
    c21_b_x1[c21_i3] = c21_x1 - c21_xO;
    c21_b_xO[c21_i3] = c21_xO;
    c21_b_x2[c21_i3] = c21_x2;
    c21_b_x3[c21_i3] = c21_x3;
    c21_b_x4[c21_i3] = c21_x4;
    c21_i2 = c21_i2 + 4;
  }

  c21_dx[0] = c21_norm(chartInstance, c21_b_x1);
  for (c21_i2 = 0; c21_i2 < 3; c21_i2 = c21_i2 + 1) {
    c21_b_x1[c21_i2] = c21_b_x2[c21_i2] - c21_b_xO[c21_i2];
  }

  c21_dx[1] = c21_norm(chartInstance, c21_b_x1);
  for (c21_i2 = 0; c21_i2 < 3; c21_i2 = c21_i2 + 1) {
    c21_b_x1[c21_i2] = c21_b_x3[c21_i2] - c21_b_xO[c21_i2];
  }

  c21_dx[2] = c21_norm(chartInstance, c21_b_x1);
  for (c21_i2 = 0; c21_i2 < 3; c21_i2 = c21_i2 + 1) {
    c21_b_x1[c21_i2] = c21_b_x4[c21_i2] - c21_b_xO[c21_i2];
  }

  c21_dx[3] = c21_norm(chartInstance, c21_b_x1);
  for (c21_i2 = 0; c21_i2 < 4; c21_i2 = c21_i2 + 1) {
    (*c21_Deltax)[c21_i2] = c21_dx[c21_i2];
  }

  _sfEvent_ = c21_previousEvent;
}

static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber)
{
}

static real_T c21_norm(SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c21_x[3])
{
  return c21_ceval_xnrm2(chartInstance, 3, c21_x, 1, 1);
}

static real_T c21_ceval_xnrm2(SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, int32_T c21_n, real_T c21_x[3], int32_T
  c21_ix0, int32_T c21_incx)
{
  return dnrm232(&c21_n, &c21_x[sf_mex_lw_bounds_check(c21_ix0, 1, 3) - 1],
                 &c21_incx);
}

const mxArray *sf_c21_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c21_nameCaptureInfo;
  c21_ResolvedFunctionInfo c21_info[44];
  const mxArray *c21_m0 = NULL;
  int32_T c21_i4;
  c21_ResolvedFunctionInfo *c21_r0;
  c21_nameCaptureInfo = NULL;
  c21_nameCaptureInfo = NULL;
  c21_info_helper(c21_info);
  sf_mex_assign(&c21_m0, sf_mex_createstruct("nameCaptureInfo", 1, 44));
  for (c21_i4 = 0; c21_i4 < 44; c21_i4 = c21_i4 + 1) {
    c21_r0 = &c21_info[c21_i4];
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c21_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c21_r0->context)), "context", "nameCaptureInfo", c21_i4);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c21_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c21_r0->name)), "name", "nameCaptureInfo", c21_i4);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c21_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const
      char *)c21_r0->dominantType)), "dominantType", "nameCaptureInfo", c21_i4);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c21_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c21_r0->resolved)), "resolved", "nameCaptureInfo", c21_i4);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c21_i4);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c21_i4);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c21_i4);
  }

  sf_mex_assign(&c21_nameCaptureInfo, c21_m0);
  return c21_nameCaptureInfo;
}

static void c21_info_helper(c21_ResolvedFunctionInfo c21_info[44])
{
  c21_info[0].context = "";
  c21_info[0].name = "zeros";
  c21_info[0].dominantType = "double";
  c21_info[0].resolved = "[B]zeros";
  c21_info[0].fileLength = 0U;
  c21_info[0].fileTime1 = 0U;
  c21_info[0].fileTime2 = 0U;
  c21_info[1].context = "";
  c21_info[1].name = "mrdivide";
  c21_info[1].dominantType = "double";
  c21_info[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c21_info[1].fileLength = 800U;
  c21_info[1].fileTime1 = 1238430690U;
  c21_info[1].fileTime2 = 0U;
  c21_info[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c21_info[2].name = "nargin";
  c21_info[2].dominantType = "";
  c21_info[2].resolved = "[B]nargin";
  c21_info[2].fileLength = 0U;
  c21_info[2].fileTime1 = 0U;
  c21_info[2].fileTime2 = 0U;
  c21_info[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c21_info[3].name = "ge";
  c21_info[3].dominantType = "double";
  c21_info[3].resolved = "[B]ge";
  c21_info[3].fileLength = 0U;
  c21_info[3].fileTime1 = 0U;
  c21_info[3].fileTime2 = 0U;
  c21_info[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c21_info[4].name = "isscalar";
  c21_info[4].dominantType = "double";
  c21_info[4].resolved = "[B]isscalar";
  c21_info[4].fileLength = 0U;
  c21_info[4].fileTime1 = 0U;
  c21_info[4].fileTime2 = 0U;
  c21_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c21_info[5].name = "rdivide";
  c21_info[5].dominantType = "double";
  c21_info[5].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c21_info[5].fileLength = 403U;
  c21_info[5].fileTime1 = 1244731952U;
  c21_info[5].fileTime2 = 0U;
  c21_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c21_info[6].name = "gt";
  c21_info[6].dominantType = "double";
  c21_info[6].resolved = "[B]gt";
  c21_info[6].fileLength = 0U;
  c21_info[6].fileTime1 = 0U;
  c21_info[6].fileTime2 = 0U;
  c21_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c21_info[7].name = "isa";
  c21_info[7].dominantType = "double";
  c21_info[7].resolved = "[B]isa";
  c21_info[7].fileLength = 0U;
  c21_info[7].fileTime1 = 0U;
  c21_info[7].fileTime2 = 0U;
  c21_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c21_info[8].name = "eml_div";
  c21_info[8].dominantType = "double";
  c21_info[8].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c21_info[8].fileLength = 4269U;
  c21_info[8].fileTime1 = 1228090226U;
  c21_info[8].fileTime2 = 0U;
  c21_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c21_info[9].name = "isinteger";
  c21_info[9].dominantType = "double";
  c21_info[9].resolved = "[B]isinteger";
  c21_info[9].fileLength = 0U;
  c21_info[9].fileTime1 = 0U;
  c21_info[9].fileTime2 = 0U;
  c21_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c21_info[10].name = "isreal";
  c21_info[10].dominantType = "double";
  c21_info[10].resolved = "[B]isreal";
  c21_info[10].fileLength = 0U;
  c21_info[10].fileTime1 = 0U;
  c21_info[10].fileTime2 = 0U;
  c21_info[11].context = "";
  c21_info[11].name = "plus";
  c21_info[11].dominantType = "double";
  c21_info[11].resolved = "[B]plus";
  c21_info[11].fileLength = 0U;
  c21_info[11].fileTime1 = 0U;
  c21_info[11].fileTime2 = 0U;
  c21_info[12].context = "";
  c21_info[12].name = "mtimes";
  c21_info[12].dominantType = "double";
  c21_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[12].fileLength = 3425U;
  c21_info[12].fileTime1 = 1250669166U;
  c21_info[12].fileTime2 = 0U;
  c21_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[13].name = "strcmp";
  c21_info[13].dominantType = "char";
  c21_info[13].resolved = "[B]strcmp";
  c21_info[13].fileLength = 0U;
  c21_info[13].fileTime1 = 0U;
  c21_info[13].fileTime2 = 0U;
  c21_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[14].name = "size";
  c21_info[14].dominantType = "double";
  c21_info[14].resolved = "[B]size";
  c21_info[14].fileLength = 0U;
  c21_info[14].fileTime1 = 0U;
  c21_info[14].fileTime2 = 0U;
  c21_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[15].name = "eq";
  c21_info[15].dominantType = "double";
  c21_info[15].resolved = "[B]eq";
  c21_info[15].fileLength = 0U;
  c21_info[15].fileTime1 = 0U;
  c21_info[15].fileTime2 = 0U;
  c21_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[16].name = "class";
  c21_info[16].dominantType = "double";
  c21_info[16].resolved = "[B]class";
  c21_info[16].fileLength = 0U;
  c21_info[16].fileTime1 = 0U;
  c21_info[16].fileTime2 = 0U;
  c21_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[17].name = "not";
  c21_info[17].dominantType = "logical";
  c21_info[17].resolved = "[B]not";
  c21_info[17].fileLength = 0U;
  c21_info[17].fileTime1 = 0U;
  c21_info[17].fileTime2 = 0U;
  c21_info[18].context = "";
  c21_info[18].name = "minus";
  c21_info[18].dominantType = "double";
  c21_info[18].resolved = "[B]minus";
  c21_info[18].fileLength = 0U;
  c21_info[18].fileTime1 = 0U;
  c21_info[18].fileTime2 = 0U;
  c21_info[19].context = "";
  c21_info[19].name = "norm";
  c21_info[19].dominantType = "double";
  c21_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c21_info[19].fileLength = 5312U;
  c21_info[19].fileTime1 = 1262616676U;
  c21_info[19].fileTime2 = 0U;
  c21_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c21_info[20].name = "ndims";
  c21_info[20].dominantType = "double";
  c21_info[20].resolved = "[B]ndims";
  c21_info[20].fileLength = 0U;
  c21_info[20].fileTime1 = 0U;
  c21_info[20].fileTime2 = 0U;
  c21_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c21_info[21].name = "le";
  c21_info[21].dominantType = "double";
  c21_info[21].resolved = "[B]le";
  c21_info[21].fileLength = 0U;
  c21_info[21].fileTime1 = 0U;
  c21_info[21].fileTime2 = 0U;
  c21_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c21_info[22].name = "lt";
  c21_info[22].dominantType = "double";
  c21_info[22].resolved = "[B]lt";
  c21_info[22].fileLength = 0U;
  c21_info[22].fileTime1 = 0U;
  c21_info[22].fileTime2 = 0U;
  c21_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c21_info[23].name = "isempty";
  c21_info[23].dominantType = "double";
  c21_info[23].resolved = "[B]isempty";
  c21_info[23].fileLength = 0U;
  c21_info[23].fileTime1 = 0U;
  c21_info[23].fileTime2 = 0U;
  c21_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c21_info[24].name = "isvector";
  c21_info[24].dominantType = "double";
  c21_info[24].resolved = "[B]isvector";
  c21_info[24].fileLength = 0U;
  c21_info[24].fileTime1 = 0U;
  c21_info[24].fileTime2 = 0U;
  c21_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c21_info[25].name = "eml_index_class";
  c21_info[25].dominantType = "";
  c21_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[25].fileLength = 909U;
  c21_info[25].fileTime1 = 1192463182U;
  c21_info[25].fileTime2 = 0U;
  c21_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c21_info[26].name = "ones";
  c21_info[26].dominantType = "char";
  c21_info[26].resolved = "[B]ones";
  c21_info[26].fileLength = 0U;
  c21_info[26].fileTime1 = 0U;
  c21_info[26].fileTime2 = 0U;
  c21_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c21_info[27].name = "ischar";
  c21_info[27].dominantType = "double";
  c21_info[27].resolved = "[B]ischar";
  c21_info[27].fileLength = 0U;
  c21_info[27].fileTime1 = 0U;
  c21_info[27].fileTime2 = 0U;
  c21_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c21_info[28].name = "eml_xnrm2";
  c21_info[28].dominantType = "int32";
  c21_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c21_info[28].fileLength = 718U;
  c21_info[28].fileTime1 = 1209327256U;
  c21_info[28].fileTime2 = 0U;
  c21_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c21_info[29].name = "cast";
  c21_info[29].dominantType = "double";
  c21_info[29].resolved = "[B]cast";
  c21_info[29].fileLength = 0U;
  c21_info[29].fileTime1 = 0U;
  c21_info[29].fileTime2 = 0U;
  c21_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c21_info[30].name = "eml_refblas_xnrm2";
  c21_info[30].dominantType = "int32";
  c21_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c21_info[30].fileLength = 1433U;
  c21_info[30].fileTime1 = 1240258442U;
  c21_info[30].fileTime2 = 0U;
  c21_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c21_info[31].name = "true";
  c21_info[31].dominantType = "";
  c21_info[31].resolved = "[B]true";
  c21_info[31].fileLength = 0U;
  c21_info[31].fileTime1 = 0U;
  c21_info[31].fileTime2 = 0U;
  c21_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c21_info[32].name = "eml_index_minus";
  c21_info[32].dominantType = "int32";
  c21_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c21_info[32].fileLength = 277U;
  c21_info[32].fileTime1 = 1192463184U;
  c21_info[32].fileTime2 = 0U;
  c21_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c21_info[33].name = "eml_index_times";
  c21_info[33].dominantType = "int32";
  c21_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c21_info[33].fileLength = 280U;
  c21_info[33].fileTime1 = 1192463186U;
  c21_info[33].fileTime2 = 0U;
  c21_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c21_info[34].name = "eml_index_plus";
  c21_info[34].dominantType = "int32";
  c21_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c21_info[34].fileLength = 272U;
  c21_info[34].fileTime1 = 1192463184U;
  c21_info[34].fileTime2 = 0U;
  c21_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c21_info[35].name = "real";
  c21_info[35].dominantType = "double";
  c21_info[35].resolved = "[B]real";
  c21_info[35].fileLength = 0U;
  c21_info[35].fileTime1 = 0U;
  c21_info[35].fileTime2 = 0U;
  c21_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c21_info[36].name = "ne";
  c21_info[36].dominantType = "double";
  c21_info[36].resolved = "[B]ne";
  c21_info[36].fileLength = 0U;
  c21_info[36].fileTime1 = 0U;
  c21_info[36].fileTime2 = 0U;
  c21_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c21_info[37].name = "abs";
  c21_info[37].dominantType = "double";
  c21_info[37].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[37].fileLength = 566U;
  c21_info[37].fileTime1 = 1221263532U;
  c21_info[37].fileTime2 = 0U;
  c21_info[38].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[38].name = "islogical";
  c21_info[38].dominantType = "double";
  c21_info[38].resolved = "[B]islogical";
  c21_info[38].fileLength = 0U;
  c21_info[38].fileTime1 = 0U;
  c21_info[38].fileTime2 = 0U;
  c21_info[39].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[39].name = "eml_scalar_abs";
  c21_info[39].dominantType = "double";
  c21_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c21_info[39].fileLength = 461U;
  c21_info[39].fileTime1 = 1203444360U;
  c21_info[39].fileTime2 = 0U;
  c21_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c21_info[40].name = "false";
  c21_info[40].dominantType = "";
  c21_info[40].resolved = "[B]false";
  c21_info[40].fileLength = 0U;
  c21_info[40].fileTime1 = 0U;
  c21_info[40].fileTime2 = 0U;
  c21_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c21_info[41].name = "times";
  c21_info[41].dominantType = "double";
  c21_info[41].resolved = "[B]times";
  c21_info[41].fileLength = 0U;
  c21_info[41].fileTime1 = 0U;
  c21_info[41].fileTime2 = 0U;
  c21_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c21_info[42].name = "imag";
  c21_info[42].dominantType = "double";
  c21_info[42].resolved = "[B]imag";
  c21_info[42].fileLength = 0U;
  c21_info[42].fileTime1 = 0U;
  c21_info[42].fileTime2 = 0U;
  c21_info[43].context = "";
  c21_info[43].name = "ctranspose";
  c21_info[43].dominantType = "double";
  c21_info[43].resolved = "[B]ctranspose";
  c21_info[43].fileLength = 0U;
  c21_info[43].fileTime1 = 0U;
  c21_info[43].fileTime2 = 0U;
}

static void c21_emlrt_marshallIn(SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c21_Deltax, const
  char_T *c21_name, real_T c21_y[4])
{
  real_T c21_dv1[4];
  int32_T c21_i5;
  sf_mex_import(c21_name, sf_mex_dup(c21_Deltax), &c21_dv1, 1, 0, 0U, 1, 0U, 1,
                4);
  for (c21_i5 = 0; c21_i5 < 4; c21_i5 = c21_i5 + 1) {
    c21_y[c21_i5] = c21_dv1[c21_i5];
  }

  sf_mex_destroy(&c21_Deltax);
}

static uint8_T c21_b_emlrt_marshallIn
  (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c21_b_is_active_c21_ODE_Hand_Model_v08_IPC_v03, const char_T *c21_name)
{
  uint8_T c21_y;
  uint8_T c21_u0;
  sf_mex_import(c21_name, sf_mex_dup
                (c21_b_is_active_c21_ODE_Hand_Model_v08_IPC_v03), &c21_u0, 1, 3,
                0U, 0, 0U, 0);
  c21_y = c21_u0;
  sf_mex_destroy(&c21_b_is_active_c21_ODE_Hand_Model_v08_IPC_v03);
  return c21_y;
}

static void init_dsm_address_info(SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c21_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3358530343U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3222296053U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1811352667U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1879417474U);
}

mxArray *sf_c21_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2201907500U);
    pr[1] = (double)(3134055047U);
    pr[2] = (double)(3594782307U);
    pr[3] = (double)(1245422734U);
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
      pr[0] = (double)(4);
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

static mxArray *sf_get_sim_state_info_c21_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Deltax\",},{M[8],M[0],T\"is_active_c21_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c21_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c21_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c21_ODE_Hand_Model_v08_IPC_v03
    ((SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c21_ODE_Hand_Model_v08_IPC_v03
    ((SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c21_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c21_ODE_Hand_Model_v08_IPC_v03
    ((SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c21_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c21_ODE_Hand_Model_v08_IPC_v03
    ((SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c21_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c21_ODE_Hand_Model_v08_IPC_v03
    ((SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c21_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c21_ODE_Hand_Model_v08_IPC_v03
    ((SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c21_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c21_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c21_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c21_ODE_Hand_Model_v08_IPC_v03
    ((SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c21_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c21_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c21_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c21_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c21_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c21_ODE_Hand_Model_v08_IPC_v03
      ((SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c21_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c21_ODE_Hand_Model_v08_IPC_v03
      ((SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c21_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",21);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",21,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",21,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",21,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",21,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",21);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(934951821U));
  ssSetChecksum1(S,(1633608781U));
  ssSetChecksum2(S,(1046299272U));
  ssSetChecksum3(S,(3900646594U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c21_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",21);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c21_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc
    (sizeof(SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc21_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c21_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c21_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c21_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c21_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c21_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c21_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c21_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c21_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c21_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c21_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c21_ODE_Hand_Model_v08_IPC_v03;
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

void c21_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c21_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c21_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c21_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c21_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
