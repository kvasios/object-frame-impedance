/* Include files */

#include "blascompat32.h"
#include "ODE_Hand_Model_v08_IPC_v03_sfun.h"
#include "c18_ODE_Hand_Model_v08_IPC_v03.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void initialize_params_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void enable_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void disable_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void set_sim_state_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c18_st);
static void finalize_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void sf_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void c18_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber);
static void c18_find(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
                     *chartInstance, boolean_T c18_x, real_T c18_i_data[1],
                     int32_T c18_i_sizes[2]);
static void c18_eml_error(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);
static void c18_power(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
                      *chartInstance, real_T c18_a[4], real_T c18_b, real_T
                      c18_y[4]);
static real_T c18_sum(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
                      *chartInstance, real_T c18_x[4]);
static void c18_bsxfun(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c18_a[4], real_T c18_b, real_T c18_c[4]);
static void c18_info_helper(c18_ResolvedFunctionInfo c18_info[56]);
static void c18_emlrt_marshallIn(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c18_out, const char_T *c18_name, real_T c18_y[4]);
static uint8_T c18_b_emlrt_marshallIn
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c18_b_is_active_c18_ODE_Hand_Model_v08_IPC_v03, const char_T *c18_name);
static void c18_refp1_sqrt(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c18_x_data[1], int32_T c18_x_sizes[2]);
static void c18_b_refp1_sqrt(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T *c18_x);
static void init_dsm_address_info(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c18_is_active_c18_ODE_Hand_Model_v08_IPC_v03 = 0U;
}

static void initialize_params_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void enable_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  const mxArray *c18_st;
  const mxArray *c18_y = NULL;
  int32_T c18_i0;
  real_T c18_u[4];
  const mxArray *c18_b_y = NULL;
  uint8_T c18_b_u;
  const mxArray *c18_c_y = NULL;
  real_T (*c18_out)[4];
  c18_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c18_st = NULL;
  c18_st = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_createcellarray(2));
  for (c18_i0 = 0; c18_i0 < 4; c18_i0 = c18_i0 + 1) {
    c18_u[c18_i0] = (*c18_out)[c18_i0];
  }

  c18_b_y = NULL;
  sf_mex_assign(&c18_b_y, sf_mex_create("y", &c18_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c18_y, 0, c18_b_y);
  c18_b_u = chartInstance->c18_is_active_c18_ODE_Hand_Model_v08_IPC_v03;
  c18_c_y = NULL;
  sf_mex_assign(&c18_c_y, sf_mex_create("y", &c18_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c18_y, 1, c18_c_y);
  sf_mex_assign(&c18_st, c18_y);
  return c18_st;
}

static void set_sim_state_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance,
   const mxArray *c18_st)
{
  const mxArray *c18_u;
  real_T c18_dv0[4];
  int32_T c18_i1;
  real_T (*c18_out)[4];
  c18_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c18_u = sf_mex_dup(c18_st);
  c18_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 0)),
                       "out", c18_dv0);
  for (c18_i1 = 0; c18_i1 < 4; c18_i1 = c18_i1 + 1) {
    (*c18_out)[c18_i1] = c18_dv0[c18_i1];
  }

  chartInstance->c18_is_active_c18_ODE_Hand_Model_v08_IPC_v03 =
    c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u
    , 1)), "is_active_c18_ODE_Hand_Model_v08_IPC_v03");
  sf_mex_destroy(&c18_u);
  sf_mex_destroy(&c18_st);
}

static void finalize_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
}

static void sf_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  int32_T c18_previousEvent;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  c18_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c18_c18_ODE_Hand_Model_v08_IPC_v03(chartInstance);
  _sfEvent_ = c18_previousEvent;
}

static void c18_c18_ODE_Hand_Model_v08_IPC_v03
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance)
{
  real_T c18_a;
  real_T c18_b_a;
  real_T c18_c_a;
  real_T c18_d_a;
  real_T c18_e_a;
  real_T c18_f_a;
  real_T c18_g_a;
  real_T c18_h_a;
  real_T c18_i_a;
  real_T c18_t;
  int32_T c18_ind_sizes[2];
  real_T c18_ind_data[1];
  int32_T c18_ind[2];
  int32_T c18_tmp_sizes[2];
  int32_T c18_b_ind[2];
  int32_T c18_c_ind[2];
  int32_T c18_b_tmp_sizes[2];
  int32_T c18_d_ind[2];
  int32_T c18_y_sizes[2];
  int32_T c18_loop_ub;
  int32_T c18_y;
  real_T c18_y_data[1];
  int8_T c18_iv0[2];
  real_T c18_r;
  int32_T c18_e_ind[2];
  int32_T c18_f_ind[2];
  int32_T c18_g_ind[2];
  int32_T c18_h_ind[2];
  int32_T c18_b_loop_ub;
  int32_T c18_i2;
  real_T c18_s;
  int32_T c18_i_ind[2];
  int32_T c18_j_ind[2];
  int32_T c18_k_ind[2];
  int32_T c18_l_ind[2];
  int32_T c18_m_ind[2];
  int32_T c18_n_ind[2];
  int32_T c18_o_ind[2];
  int32_T c18_p_ind[2];
  int32_T c18_c_tmp_sizes[2];
  real_T c18_tmp_data[1];
  int32_T c18_q_ind[2];
  int32_T c18_r_ind[2];
  int32_T c18_d_tmp_sizes[2];
  real_T c18_b_tmp_data[1];
  int32_T c18_s_ind[2];
  int32_T c18_t_ind[2];
  int32_T c18_u_ind[2];
  int32_T c18_v_ind[2];
  int32_T c18_w_ind[2];
  int32_T c18_x_ind[2];
  int32_T c18_y_ind[2];
  int32_T c18_ab_ind[2];
  int32_T c18_bb_ind[2];
  int32_T c18_cb_ind[2];
  int32_T c18_db_ind[2];
  int32_T c18_eb_ind[2];
  int32_T c18_fb_ind[2];
  int32_T c18_gb_ind[2];
  int32_T c18_hb_ind[2];
  int32_T c18_ib_ind[2];
  int32_T c18_jb_ind[2];
  int32_T c18_kb_ind[2];
  int32_T c18_lb_ind[2];
  int32_T c18_mb_ind[2];
  int32_T c18_nb_ind[2];
  int32_T c18_ob_ind[2];
  int32_T c18_pb_ind[2];
  int32_T c18_qb_ind[2];
  int32_T c18_rb_ind[2];
  int32_T c18_sb_ind[2];
  int32_T c18_tb_ind[2];
  int32_T c18_ub_ind[2];
  int32_T c18_vb_ind[2];
  int32_T c18_wb_ind[2];
  int32_T c18_xb_ind[2];
  int32_T c18_yb_ind[2];
  int32_T c18_ac_ind[2];
  int32_T c18_bc_ind[2];
  int32_T c18_cc_ind[2];
  int32_T c18_dc_ind[2];
  int32_T c18_ec_ind[2];
  int32_T c18_fc_ind[2];
  int32_T c18_gc_ind[2];
  int32_T c18_hc_ind[2];
  int32_T c18_ic_ind[2];
  int32_T c18_jc_ind[2];
  int32_T c18_kc_ind[2];
  int32_T c18_lc_ind[2];
  int32_T c18_mc_ind[2];
  int32_T c18_nc_ind[2];
  int32_T c18_oc_ind[2];
  int32_T c18_pc_ind[2];
  int32_T c18_qc_ind[2];
  int32_T c18_rc_ind[2];
  int32_T c18_sc_ind[2];
  int32_T c18_tc_ind[2];
  int32_T c18_uc_ind[2];
  int32_T c18_vc_ind[2];
  int32_T c18_wc_ind[2];
  int32_T c18_xc_ind[2];
  int32_T c18_yc_ind[2];
  int32_T c18_ad_ind[2];
  int32_T c18_bd_ind[2];
  int32_T c18_cd_ind[2];
  int32_T c18_dd_ind[2];
  int32_T c18_ed_ind[2];
  int32_T c18_fd_ind[2];
  int32_T c18_gd_ind[2];
  int32_T c18_hd_ind[2];
  int32_T c18_id_ind[2];
  int32_T c18_jd_ind[2];
  int32_T c18_kd_ind[2];
  int32_T c18_ld_ind[2];
  int32_T c18_md_ind[2];
  int32_T c18_nd_ind[2];
  int32_T c18_od_ind[2];
  int32_T c18_pd_ind[2];
  int32_T c18_qd_ind[2];
  int32_T c18_rd_ind[2];
  int32_T c18_sd_ind[2];
  int32_T c18_td_ind[2];
  int32_T c18_ud_ind[2];
  int32_T c18_vd_ind[2];
  int32_T c18_wd_ind[2];
  int32_T c18_xd_ind[2];
  int32_T c18_yd_ind[2];
  int32_T c18_ae_ind[2];
  int32_T c18_be_ind[2];
  int32_T c18_ce_ind[2];
  int32_T c18_de_ind[2];
  int32_T c18_ee_ind[2];
  int32_T c18_fe_ind[2];
  int32_T c18_ge_ind[2];
  int32_T c18_he_ind[2];
  int32_T c18_ie_ind[2];
  int32_T c18_je_ind[2];
  int32_T c18_ke_ind[2];
  int32_T c18_le_ind[2];
  int32_T c18_me_ind[2];
  int32_T c18_ne_ind[2];
  int32_T c18_oe_ind[2];
  int32_T c18_pe_ind[2];
  int32_T c18_qe_ind[2];
  int32_T c18_re_ind[2];
  int32_T c18_se_ind[2];
  int32_T c18_te_ind[2];
  int32_T c18_ue_ind[2];
  int32_T c18_ve_ind[2];
  int32_T c18_we_ind[2];
  int32_T c18_xe_ind[2];
  int32_T c18_ye_ind[2];
  int32_T c18_af_ind[2];
  int32_T c18_bf_ind[2];
  int32_T c18_cf_ind[2];
  int32_T c18_df_ind[2];
  int32_T c18_ef_ind[2];
  int32_T c18_ff_ind[2];
  int32_T c18_gf_ind[2];
  int32_T c18_e_tmp_sizes[2];
  real_T c18_c_tmp_data[1];
  int32_T c18_hf_ind[2];
  int32_T c18_if_ind[2];
  int32_T c18_jf_ind[2];
  int32_T c18_kf_ind[2];
  int32_T c18_lf_ind[2];
  int32_T c18_mf_ind[2];
  int32_T c18_nf_ind[2];
  int32_T c18_of_ind[2];
  int32_T c18_f_tmp_sizes[2];
  real_T c18_d_tmp_data[1];
  int32_T c18_pf_ind[2];
  int32_T c18_qf_ind[2];
  int32_T c18_rf_ind[2];
  int32_T c18_sf_ind[2];
  int8_T c18_iv1[2];
  int32_T c18_tf_ind[2];
  int32_T c18_uf_ind[2];
  int32_T c18_vf_ind[2];
  int32_T c18_wf_ind[2];
  int32_T c18_xf_ind[2];
  int32_T c18_yf_ind[2];
  int32_T c18_ag_ind[2];
  int32_T c18_bg_ind[2];
  int8_T c18_iv2[2];
  int32_T c18_cg_ind[2];
  int32_T c18_dg_ind[2];
  int32_T c18_eg_ind[2];
  int32_T c18_fg_ind[2];
  int8_T c18_iv3[2];
  real_T c18_out[4];
  real_T c18_hoistedExpr[4];
  real_T c18_b_out[4];
  real_T (*c18_c_out)[4];
  real_T (*c18_in)[9];
  c18_c_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c18_in = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);

  /*  Converts between rotation matrix and quaternion representation */
  /*  */
  /*  The formulas were taken from wikipedia: */
  /*  http://en.wikipedia.org/wiki/Rotation_matrix */
  /*  */
  /*  USAGE */
  /*   Q = quaternion( R ) */
  /*   R = quaternion( Q ) */
  /*  */
  /*  INPUTS */
  /*   in       - either 3x3xN set of rotation matrices or 4xN or Nx4 */
  /*              set of quaternions */
  /*   doSmooth - if set to true, the output quaternions are opposed if */
  /*              necessary to get smoother data */
  /*  */
  /*  OUTPUTS */
  /*   out      - 4xN set of quaternion or 3x3xN set of rotation matrices */
  /*  */
  /*  EXAMPLE */
  /*   R = zeros(3,3,1000); */
  /*   for i=1:1000 */
  /*     R(:,:,i) = rotationMatrix( rand(1, 3) ); */
  /*   end */
  /*   norm( sum((quaternion(quaternion(R)) - R).^2,3), 'fro' ) */
  /*  */
  /*  See also */
  /*  */
  /*  Vincent's Structure From Motion Toolbox      Version 3.0 */
  /*  Copyright (C) 2008-2011 Vincent Rabaud.  [vrabaud-at-cs.ucsd.edu] */
  /*  Please email me if you find bugs, or have suggestions or questions! */
  /*  Licensed under the GPL [see external/gpl.txt] */
  /*  if nargin<=1; doSmooth = false; end */
  c18_a = (*c18_in)[0];
  c18_b_a = (*c18_in)[1];
  c18_c_a = (*c18_in)[2];
  c18_d_a = (*c18_in)[3];
  c18_e_a = (*c18_in)[4];
  c18_f_a = (*c18_in)[5];
  c18_g_a = (*c18_in)[6];
  c18_h_a = (*c18_in)[7];
  c18_i_a = (*c18_in)[8];
  c18_t = ((c18_a + c18_e_a) + c18_i_a) + 1.0;
  c18_find(chartInstance, c18_t >= 0.001, c18_ind_data, c18_ind_sizes);
  c18_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_ind[0];
  c18_b_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_b_ind[1];
  c18_c_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_c_ind[0];
  c18_d_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_d_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_t;
  }

  c18_refp1_sqrt(chartInstance, c18_y_data, c18_y_sizes);
  sf_mex_lw_size_eq_check_1d(c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1],
    c18_y_sizes[0] * c18_y_sizes[1]);
  for (c18_loop_ub = 0; c18_loop_ub < 2; c18_loop_ub = c18_loop_ub + 1) {
    c18_iv0[c18_loop_ub] = (int8_T)c18_y_sizes[c18_loop_ub];
  }

  c18_r = c18_y_data[(c18_iv0[0] - 1) + c18_y_sizes[0] * (c18_iv0[1] - 1)];
  c18_e_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_e_ind[0];
  c18_f_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_f_ind[1];
  c18_g_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_g_ind[0];
  c18_h_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_h_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_r;
  }

  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_loop_ub = c18_y_sizes[0] - 1;
    for (c18_i2 = 0; c18_i2 <= c18_b_loop_ub; c18_i2 = c18_i2 + 1) {
      c18_y_data[c18_i2 + c18_y_sizes[0] * c18_y] = 0.5 / c18_y_data[c18_i2 +
        c18_y_sizes[0] * c18_y];
    }
  }

  sf_mex_lw_size_eq_check_1d(c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1],
    c18_y_sizes[0] * c18_y_sizes[1]);
  for (c18_loop_ub = 0; c18_loop_ub < 2; c18_loop_ub = c18_loop_ub + 1) {
    c18_iv0[c18_loop_ub] = (int8_T)c18_y_sizes[c18_loop_ub];
  }

  c18_s = c18_y_data[(c18_iv0[0] - 1) + c18_y_sizes[0] * (c18_iv0[1] - 1)];
  c18_i_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_i_ind[0];
  c18_j_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_j_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_r;
  }

  c18_k_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_k_ind[0];
  c18_l_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_l_ind[1];
  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_loop_ub = c18_y_sizes[0] - 1;
    for (c18_i2 = 0; c18_i2 <= c18_b_loop_ub; c18_i2 = c18_i2 + 1) {
      c18_y_data[c18_i2 + c18_y_sizes[0] * c18_y] = 0.5 * c18_y_data[c18_i2 +
        c18_y_sizes[0] * c18_y];
    }
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  c18_m_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_m_ind[0];
  c18_n_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_n_ind[1];
  c18_o_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_o_ind[0];
  c18_p_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_p_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_f_a;
  }

  c18_c_tmp_sizes[0] = c18_b_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_b_tmp_sizes[1];
  c18_loop_ub = c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_h_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_c_tmp_sizes, 2);
  c18_q_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_q_ind[0];
  c18_r_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_r_ind[1];
  c18_d_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_d_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = c18_s;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_d_tmp_sizes, 2);
  c18_s_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_s_ind[0];
  c18_t_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_t_ind[1];
  c18_loop_ub = c18_y_sizes[0];
  c18_y = c18_y_sizes[1];
  c18_loop_ub = c18_loop_ub * c18_y - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = (c18_y_data[c18_y] - c18_tmp_data[c18_y]) *
      c18_b_tmp_data[c18_y];
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  c18_u_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_u_ind[0];
  c18_v_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_v_ind[1];
  c18_w_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_w_ind[0];
  c18_x_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_x_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_g_a;
  }

  c18_c_tmp_sizes[0] = c18_b_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_b_tmp_sizes[1];
  c18_loop_ub = c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_c_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_c_tmp_sizes, 2);
  c18_y_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_y_ind[0];
  c18_ab_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_ab_ind[1];
  c18_d_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_d_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = c18_s;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_d_tmp_sizes, 2);
  c18_bb_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_bb_ind[0];
  c18_cb_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_cb_ind[1];
  c18_loop_ub = c18_y_sizes[0];
  c18_y = c18_y_sizes[1];
  c18_loop_ub = c18_loop_ub * c18_y - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = (c18_y_data[c18_y] - c18_tmp_data[c18_y]) *
      c18_b_tmp_data[c18_y];
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  c18_db_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_db_ind[0];
  c18_eb_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_eb_ind[1];
  c18_fb_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_fb_ind[0];
  c18_gb_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_gb_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_b_a;
  }

  c18_c_tmp_sizes[0] = c18_b_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_b_tmp_sizes[1];
  c18_loop_ub = c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_d_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_c_tmp_sizes, 2);
  c18_hb_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_hb_ind[0];
  c18_ib_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_ib_ind[1];
  c18_d_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_d_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = c18_s;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_d_tmp_sizes, 2);
  c18_jb_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_jb_ind[0];
  c18_kb_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_kb_ind[1];
  c18_loop_ub = c18_y_sizes[0];
  c18_y = c18_y_sizes[1];
  c18_loop_ub = c18_loop_ub * c18_y - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = (c18_y_data[c18_y] - c18_tmp_data[c18_y]) *
      c18_b_tmp_data[c18_y];
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  c18_find(chartInstance, (c18_t < 0.001) && (c18_a >= c18_e_a) && (c18_a >=
            c18_i_a), c18_ind_data, c18_ind_sizes);
  c18_lb_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_lb_ind[0];
  c18_mb_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_mb_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_a;
  }

  c18_nb_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_nb_ind[0];
  c18_ob_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_ob_ind[1];
  c18_c_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_e_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_c_tmp_sizes, 2);
  c18_pb_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_pb_ind[0];
  c18_qb_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_qb_ind[1];
  c18_d_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_d_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = c18_i_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_d_tmp_sizes, 2);
  c18_rb_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_rb_ind[0];
  c18_sb_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_sb_ind[1];
  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_loop_ub = c18_y_sizes[0] - 1;
    for (c18_i2 = 0; c18_i2 <= c18_b_loop_ub; c18_i2 = c18_i2 + 1) {
      c18_y_data[c18_i2 + c18_y_sizes[0] * c18_y] = ((1.0 + c18_y_data[c18_i2 +
        c18_y_sizes[0] * c18_y]) - c18_tmp_data[c18_i2 +
        c18_c_tmp_sizes[0] * c18_y]) - c18_b_tmp_data[c18_i2 + c18_d_tmp_sizes[0]
        * c18_y];
    }
  }

  c18_refp1_sqrt(chartInstance, c18_y_data, c18_y_sizes);
  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  for (c18_loop_ub = 0; c18_loop_ub < 2; c18_loop_ub = c18_loop_ub + 1) {
    c18_iv0[c18_loop_ub] = (int8_T)c18_y_sizes[c18_loop_ub];
  }

  c18_r = c18_y_data[(c18_iv0[0] - 1) + c18_y_sizes[0] * (c18_iv0[1] - 1)];
  c18_tb_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_tb_ind[0];
  c18_ub_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_ub_ind[1];
  c18_vb_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_vb_ind[0];
  c18_wb_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_wb_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_r;
  }

  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_loop_ub = c18_y_sizes[0] - 1;
    for (c18_i2 = 0; c18_i2 <= c18_b_loop_ub; c18_i2 = c18_i2 + 1) {
      c18_y_data[c18_i2 + c18_y_sizes[0] * c18_y] = 0.5 / c18_y_data[c18_i2 +
        c18_y_sizes[0] * c18_y];
    }
  }

  sf_mex_lw_size_eq_check_1d(c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1],
    c18_y_sizes[0] * c18_y_sizes[1]);
  for (c18_loop_ub = 0; c18_loop_ub < 2; c18_loop_ub = c18_loop_ub + 1) {
    c18_iv0[c18_loop_ub] = (int8_T)c18_y_sizes[c18_loop_ub];
  }

  c18_s = c18_y_data[(c18_iv0[0] - 1) + c18_y_sizes[0] * (c18_iv0[1] - 1)];
  c18_xb_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_xb_ind[0];
  c18_yb_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_yb_ind[1];
  c18_ac_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_ac_ind[0];
  c18_bc_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_bc_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_f_a;
  }

  c18_c_tmp_sizes[0] = c18_b_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_b_tmp_sizes[1];
  c18_loop_ub = c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_h_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_c_tmp_sizes, 2);
  c18_cc_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_cc_ind[0];
  c18_dc_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_dc_ind[1];
  c18_d_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_d_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = c18_s;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_d_tmp_sizes, 2);
  c18_ec_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_ec_ind[0];
  c18_fc_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_fc_ind[1];
  c18_loop_ub = c18_y_sizes[0];
  c18_y = c18_y_sizes[1];
  c18_loop_ub = c18_loop_ub * c18_y - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = (c18_y_data[c18_y] - c18_tmp_data[c18_y]) *
      c18_b_tmp_data[c18_y];
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  c18_gc_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_gc_ind[0];
  c18_hc_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_hc_ind[1];
  c18_ic_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_ic_ind[0];
  c18_jc_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_jc_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_r;
  }

  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_loop_ub = c18_y_sizes[0] - 1;
    for (c18_i2 = 0; c18_i2 <= c18_b_loop_ub; c18_i2 = c18_i2 + 1) {
      c18_y_data[c18_i2 + c18_y_sizes[0] * c18_y] = 0.5 * c18_y_data[c18_i2 +
        c18_y_sizes[0] * c18_y];
    }
  }

  sf_mex_lw_size_eq_check_1d(c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1],
    c18_y_sizes[0] * c18_y_sizes[1]);
  c18_kc_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_kc_ind[0];
  c18_lc_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_lc_ind[1];
  c18_mc_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_mc_ind[0];
  c18_nc_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_nc_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_d_a;
  }

  c18_c_tmp_sizes[0] = c18_b_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_b_tmp_sizes[1];
  c18_loop_ub = c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_b_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_c_tmp_sizes, 2);
  c18_oc_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_oc_ind[0];
  c18_pc_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_pc_ind[1];
  c18_d_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_d_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = c18_s;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_d_tmp_sizes, 2);
  c18_qc_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_qc_ind[0];
  c18_rc_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_rc_ind[1];
  c18_loop_ub = c18_y_sizes[0];
  c18_y = c18_y_sizes[1];
  c18_loop_ub = c18_loop_ub * c18_y - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = (c18_y_data[c18_y] + c18_tmp_data[c18_y]) *
      c18_b_tmp_data[c18_y];
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  c18_sc_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_sc_ind[0];
  c18_tc_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_tc_ind[1];
  c18_uc_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_uc_ind[0];
  c18_vc_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_vc_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_g_a;
  }

  c18_c_tmp_sizes[0] = c18_b_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_b_tmp_sizes[1];
  c18_loop_ub = c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_c_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_c_tmp_sizes, 2);
  c18_wc_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_wc_ind[0];
  c18_xc_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_xc_ind[1];
  c18_d_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_d_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = c18_s;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_d_tmp_sizes, 2);
  c18_yc_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_yc_ind[0];
  c18_ad_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_ad_ind[1];
  c18_loop_ub = c18_y_sizes[0];
  c18_y = c18_y_sizes[1];
  c18_loop_ub = c18_loop_ub * c18_y - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = (c18_y_data[c18_y] + c18_tmp_data[c18_y]) *
      c18_b_tmp_data[c18_y];
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  c18_find(chartInstance, (c18_t < 0.001) && (c18_e_a >= c18_a) && (c18_e_a >=
            c18_i_a), c18_ind_data, c18_ind_sizes);
  c18_bd_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_bd_ind[0];
  c18_cd_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_cd_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_e_a;
  }

  c18_dd_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_dd_ind[0];
  c18_ed_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_ed_ind[1];
  c18_c_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_c_tmp_sizes, 2);
  c18_fd_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_fd_ind[0];
  c18_gd_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_gd_ind[1];
  c18_d_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_d_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = c18_i_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_d_tmp_sizes, 2);
  c18_hd_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_hd_ind[0];
  c18_id_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_id_ind[1];
  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_loop_ub = c18_y_sizes[0] - 1;
    for (c18_i2 = 0; c18_i2 <= c18_b_loop_ub; c18_i2 = c18_i2 + 1) {
      c18_y_data[c18_i2 + c18_y_sizes[0] * c18_y] = ((1.0 + c18_y_data[c18_i2 +
        c18_y_sizes[0] * c18_y]) - c18_tmp_data[c18_i2 +
        c18_c_tmp_sizes[0] * c18_y]) - c18_b_tmp_data[c18_i2 + c18_d_tmp_sizes[0]
        * c18_y];
    }
  }

  c18_refp1_sqrt(chartInstance, c18_y_data, c18_y_sizes);
  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  for (c18_loop_ub = 0; c18_loop_ub < 2; c18_loop_ub = c18_loop_ub + 1) {
    c18_iv0[c18_loop_ub] = (int8_T)c18_y_sizes[c18_loop_ub];
  }

  c18_r = c18_y_data[(c18_iv0[0] - 1) + c18_y_sizes[0] * (c18_iv0[1] - 1)];
  c18_jd_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_jd_ind[0];
  c18_kd_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_kd_ind[1];
  c18_ld_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_ld_ind[0];
  c18_md_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_md_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_r;
  }

  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_loop_ub = c18_y_sizes[0] - 1;
    for (c18_i2 = 0; c18_i2 <= c18_b_loop_ub; c18_i2 = c18_i2 + 1) {
      c18_y_data[c18_i2 + c18_y_sizes[0] * c18_y] = 0.5 / c18_y_data[c18_i2 +
        c18_y_sizes[0] * c18_y];
    }
  }

  sf_mex_lw_size_eq_check_1d(c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1],
    c18_y_sizes[0] * c18_y_sizes[1]);
  for (c18_loop_ub = 0; c18_loop_ub < 2; c18_loop_ub = c18_loop_ub + 1) {
    c18_iv0[c18_loop_ub] = (int8_T)c18_y_sizes[c18_loop_ub];
  }

  c18_s = c18_y_data[(c18_iv0[0] - 1) + c18_y_sizes[0] * (c18_iv0[1] - 1)];
  c18_nd_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_nd_ind[0];
  c18_od_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_od_ind[1];
  c18_pd_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_pd_ind[0];
  c18_qd_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_qd_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_g_a;
  }

  c18_c_tmp_sizes[0] = c18_b_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_b_tmp_sizes[1];
  c18_loop_ub = c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_c_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_c_tmp_sizes, 2);
  c18_rd_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_rd_ind[0];
  c18_sd_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_sd_ind[1];
  c18_d_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_d_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = c18_s;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_d_tmp_sizes, 2);
  c18_td_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_td_ind[0];
  c18_ud_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_ud_ind[1];
  c18_loop_ub = c18_y_sizes[0];
  c18_y = c18_y_sizes[1];
  c18_loop_ub = c18_loop_ub * c18_y - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = (c18_y_data[c18_y] - c18_tmp_data[c18_y]) *
      c18_b_tmp_data[c18_y];
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  c18_vd_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_vd_ind[0];
  c18_wd_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_wd_ind[1];
  c18_xd_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_xd_ind[0];
  c18_yd_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_yd_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_d_a;
  }

  c18_c_tmp_sizes[0] = c18_b_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_b_tmp_sizes[1];
  c18_loop_ub = c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_b_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_c_tmp_sizes, 2);
  c18_ae_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_ae_ind[0];
  c18_be_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_be_ind[1];
  c18_d_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_d_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = c18_s;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_d_tmp_sizes, 2);
  c18_ce_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_ce_ind[0];
  c18_de_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_de_ind[1];
  c18_loop_ub = c18_y_sizes[0];
  c18_y = c18_y_sizes[1];
  c18_loop_ub = c18_loop_ub * c18_y - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = (c18_y_data[c18_y] + c18_tmp_data[c18_y]) *
      c18_b_tmp_data[c18_y];
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  c18_ee_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_ee_ind[0];
  c18_fe_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_fe_ind[1];
  c18_ge_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_ge_ind[0];
  c18_he_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_he_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_r;
  }

  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_loop_ub = c18_y_sizes[0] - 1;
    for (c18_i2 = 0; c18_i2 <= c18_b_loop_ub; c18_i2 = c18_i2 + 1) {
      c18_y_data[c18_i2 + c18_y_sizes[0] * c18_y] = 0.5 * c18_y_data[c18_i2 +
        c18_y_sizes[0] * c18_y];
    }
  }

  sf_mex_lw_size_eq_check_1d(c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1],
    c18_y_sizes[0] * c18_y_sizes[1]);
  c18_ie_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_ie_ind[0];
  c18_je_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_je_ind[1];
  c18_ke_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_ke_ind[0];
  c18_le_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_le_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_h_a;
  }

  c18_c_tmp_sizes[0] = c18_b_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_b_tmp_sizes[1];
  c18_loop_ub = c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_f_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_c_tmp_sizes, 2);
  c18_me_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_me_ind[0];
  c18_ne_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_ne_ind[1];
  c18_d_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_d_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = c18_s;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_d_tmp_sizes, 2);
  c18_oe_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_oe_ind[0];
  c18_pe_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_pe_ind[1];
  c18_loop_ub = c18_y_sizes[0];
  c18_y = c18_y_sizes[1];
  c18_loop_ub = c18_loop_ub * c18_y - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = (c18_y_data[c18_y] + c18_tmp_data[c18_y]) *
      c18_b_tmp_data[c18_y];
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  c18_find(chartInstance, (c18_t < 0.001) && (c18_i_a >= c18_a) && (c18_i_a >=
            c18_e_a), c18_ind_data, c18_ind_sizes);
  c18_qe_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_qe_ind[0];
  c18_re_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_re_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_i_a;
  }

  c18_se_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_se_ind[0];
  c18_te_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_te_ind[1];
  c18_c_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_c_tmp_sizes, 2);
  c18_ue_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_ue_ind[0];
  c18_ve_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_ve_ind[1];
  c18_d_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_d_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = c18_e_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_y_sizes, c18_d_tmp_sizes, 2);
  c18_we_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_we_ind[0];
  c18_xe_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_xe_ind[1];
  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_loop_ub = c18_y_sizes[0] - 1;
    for (c18_i2 = 0; c18_i2 <= c18_b_loop_ub; c18_i2 = c18_i2 + 1) {
      c18_y_data[c18_i2 + c18_y_sizes[0] * c18_y] = ((1.0 + c18_y_data[c18_i2 +
        c18_y_sizes[0] * c18_y]) - c18_tmp_data[c18_i2 +
        c18_c_tmp_sizes[0] * c18_y]) - c18_b_tmp_data[c18_i2 + c18_d_tmp_sizes[0]
        * c18_y];
    }
  }

  c18_refp1_sqrt(chartInstance, c18_y_data, c18_y_sizes);
  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  for (c18_loop_ub = 0; c18_loop_ub < 2; c18_loop_ub = c18_loop_ub + 1) {
    c18_iv0[c18_loop_ub] = (int8_T)c18_y_sizes[c18_loop_ub];
  }

  c18_r = c18_y_data[(c18_iv0[0] - 1) + c18_y_sizes[0] * (c18_iv0[1] - 1)];
  c18_ye_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_ye_ind[0];
  c18_af_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_af_ind[1];
  c18_bf_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_bf_ind[0];
  c18_cf_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_cf_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_r;
  }

  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_loop_ub = c18_y_sizes[0] - 1;
    for (c18_i2 = 0; c18_i2 <= c18_b_loop_ub; c18_i2 = c18_i2 + 1) {
      c18_y_data[c18_i2 + c18_y_sizes[0] * c18_y] = 0.5 / c18_y_data[c18_i2 +
        c18_y_sizes[0] * c18_y];
    }
  }

  sf_mex_lw_size_eq_check_1d(c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1],
    c18_y_sizes[0] * c18_y_sizes[1]);
  for (c18_loop_ub = 0; c18_loop_ub < 2; c18_loop_ub = c18_loop_ub + 1) {
    c18_iv0[c18_loop_ub] = (int8_T)c18_y_sizes[c18_loop_ub];
  }

  c18_s = c18_y_data[(c18_iv0[0] - 1) + c18_y_sizes[0] * (c18_iv0[1] - 1)];
  c18_df_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_df_ind[0];
  c18_ef_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_ef_ind[1];
  c18_ff_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_ff_ind[0];
  c18_gf_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_gf_ind[1];
  c18_e_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_e_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_c_tmp_data[c18_y] = c18_b_a;
  }

  c18_y_sizes[0] = c18_b_tmp_sizes[0];
  c18_y_sizes[1] = c18_b_tmp_sizes[1];
  c18_loop_ub = c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_d_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_e_tmp_sizes, c18_y_sizes, 2);
  c18_hf_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_hf_ind[0];
  c18_if_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_if_ind[1];
  c18_c_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_s;
  }

  sf_mex_lw_size_eq_check_nd(c18_e_tmp_sizes, c18_c_tmp_sizes, 2);
  c18_jf_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_jf_ind[0];
  c18_kf_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_kf_ind[1];
  c18_loop_ub = c18_e_tmp_sizes[0];
  c18_y = c18_e_tmp_sizes[1];
  c18_loop_ub = c18_loop_ub * c18_y - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_c_tmp_data[c18_y] = (c18_c_tmp_data[c18_y] - c18_y_data[c18_y]) *
      c18_tmp_data[c18_y];
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1],
    c18_e_tmp_sizes[0] * c18_e_tmp_sizes[1]);
  for (c18_loop_ub = 0; c18_loop_ub < 2; c18_loop_ub = c18_loop_ub + 1) {
    c18_iv0[c18_loop_ub] = (int8_T)c18_e_tmp_sizes[c18_loop_ub];
  }

  c18_lf_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_lf_ind[0];
  c18_mf_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_mf_ind[1];
  c18_nf_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_nf_ind[0];
  c18_of_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_of_ind[1];
  c18_f_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_f_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_d_tmp_data[c18_y] = c18_g_a;
  }

  c18_y_sizes[0] = c18_b_tmp_sizes[0];
  c18_y_sizes[1] = c18_b_tmp_sizes[1];
  c18_loop_ub = c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_c_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_f_tmp_sizes, c18_y_sizes, 2);
  c18_pf_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_pf_ind[0];
  c18_qf_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_qf_ind[1];
  c18_c_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_s;
  }

  sf_mex_lw_size_eq_check_nd(c18_f_tmp_sizes, c18_c_tmp_sizes, 2);
  c18_rf_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_rf_ind[0];
  c18_sf_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_sf_ind[1];
  c18_loop_ub = c18_f_tmp_sizes[0];
  c18_y = c18_f_tmp_sizes[1];
  c18_loop_ub = c18_loop_ub * c18_y - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_d_tmp_data[c18_y] = (c18_d_tmp_data[c18_y] + c18_y_data[c18_y]) *
      c18_tmp_data[c18_y];
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1],
    c18_f_tmp_sizes[0] * c18_f_tmp_sizes[1]);
  for (c18_loop_ub = 0; c18_loop_ub < 2; c18_loop_ub = c18_loop_ub + 1) {
    c18_iv1[c18_loop_ub] = (int8_T)c18_f_tmp_sizes[c18_loop_ub];
  }

  c18_tf_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_tf_ind[0];
  c18_uf_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_uf_ind[1];
  c18_vf_ind[0] = c18_ind_sizes[0];
  c18_b_tmp_sizes[0] = c18_vf_ind[0];
  c18_wf_ind[1] = c18_ind_sizes[1];
  c18_b_tmp_sizes[1] = c18_wf_ind[1];
  c18_d_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_d_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = c18_h_a;
  }

  c18_y_sizes[0] = c18_b_tmp_sizes[0];
  c18_y_sizes[1] = c18_b_tmp_sizes[1];
  c18_loop_ub = c18_b_tmp_sizes[0] * c18_b_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_f_a;
  }

  sf_mex_lw_size_eq_check_nd(c18_d_tmp_sizes, c18_y_sizes, 2);
  c18_xf_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_xf_ind[0];
  c18_yf_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_yf_ind[1];
  c18_c_tmp_sizes[0] = c18_tmp_sizes[0];
  c18_c_tmp_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_tmp_data[c18_y] = c18_s;
  }

  sf_mex_lw_size_eq_check_nd(c18_d_tmp_sizes, c18_c_tmp_sizes, 2);
  c18_ag_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_ag_ind[0];
  c18_bg_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_bg_ind[1];
  c18_loop_ub = c18_d_tmp_sizes[0];
  c18_y = c18_d_tmp_sizes[1];
  c18_loop_ub = c18_loop_ub * c18_y - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_tmp_data[c18_y] = (c18_b_tmp_data[c18_y] + c18_y_data[c18_y]) *
      c18_tmp_data[c18_y];
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1],
    c18_d_tmp_sizes[0] * c18_d_tmp_sizes[1]);
  for (c18_loop_ub = 0; c18_loop_ub < 2; c18_loop_ub = c18_loop_ub + 1) {
    c18_iv2[c18_loop_ub] = (int8_T)c18_d_tmp_sizes[c18_loop_ub];
  }

  c18_cg_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_cg_ind[0];
  c18_dg_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_dg_ind[1];
  c18_y_sizes[0] = c18_tmp_sizes[0];
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_y_data[c18_y] = c18_r;
  }

  c18_eg_ind[0] = c18_ind_sizes[0];
  c18_tmp_sizes[0] = c18_eg_ind[0];
  c18_fg_ind[1] = c18_ind_sizes[1];
  c18_tmp_sizes[1] = c18_fg_ind[1];
  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_y = 0; c18_y <= c18_loop_ub; c18_y = c18_y + 1) {
    c18_b_loop_ub = c18_y_sizes[0] - 1;
    for (c18_i2 = 0; c18_i2 <= c18_b_loop_ub; c18_i2 = c18_i2 + 1) {
      c18_y_data[c18_i2 + c18_y_sizes[0] * c18_y] = 0.5 * c18_y_data[c18_i2 +
        c18_y_sizes[0] * c18_y];
    }
  }

  sf_mex_lw_size_eq_check_1d(c18_tmp_sizes[0] * c18_tmp_sizes[1], c18_y_sizes[0]
    * c18_y_sizes[1]);
  for (c18_loop_ub = 0; c18_loop_ub < 2; c18_loop_ub = c18_loop_ub + 1) {
    c18_iv3[c18_loop_ub] = (int8_T)c18_y_sizes[c18_loop_ub];
  }

  c18_out[0] = c18_c_tmp_data[(c18_iv0[0] - 1) + c18_e_tmp_sizes[0] * (c18_iv0[1]
    - 1)];
  c18_out[1] = c18_d_tmp_data[(c18_iv1[0] - 1) + c18_f_tmp_sizes[0] * (c18_iv1[1]
    - 1)];
  c18_out[2] = c18_b_tmp_data[(c18_iv2[0] - 1) + c18_d_tmp_sizes[0] * (c18_iv2[1]
    - 1)];
  c18_out[3] = c18_y_data[(c18_iv3[0] - 1) + c18_y_sizes[0] * (c18_iv3[1] - 1)];

  /*  Normalize */
  c18_power(chartInstance, c18_out, 2.0, c18_hoistedExpr);
  c18_a = c18_sum(chartInstance, c18_hoistedExpr);
  c18_b_refp1_sqrt(chartInstance, &c18_a);
  for (c18_loop_ub = 0; c18_loop_ub < 4; c18_loop_ub = c18_loop_ub + 1) {
    c18_b_out[c18_loop_ub] = c18_out[c18_loop_ub];
  }

  c18_bsxfun(chartInstance, c18_b_out, c18_a, c18_out);

  /*  Smooth if requested */
  for (c18_loop_ub = 0; c18_loop_ub < 4; c18_loop_ub = c18_loop_ub + 1) {
    (*c18_c_out)[c18_loop_ub] = c18_out[c18_loop_ub];
  }
}

static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber)
{
}

static void c18_find(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
                     *chartInstance, boolean_T c18_x, real_T c18_i_data[1],
                     int32_T
                     c18_i_sizes[2])
{
  if (c18_x) {
    c18_i_sizes[0] = 1;
    c18_i_sizes[1] = 1;
    c18_i_data[0] = 1.0;
  } else {
    c18_i_sizes[0] = 0;
    c18_i_sizes[1] = 0;

    /* Empty Loop. */
  }
}

static void c18_eml_error(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
  int32_T c18_i3;
  static char_T c18_cv0[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c18_u[31];
  const mxArray *c18_y = NULL;
  static char_T c18_cv1[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 's',
    'q', 'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c18_b_u[77];
  const mxArray *c18_b_y = NULL;
  for (c18_i3 = 0; c18_i3 < 31; c18_i3 = c18_i3 + 1) {
    c18_u[c18_i3] = c18_cv0[c18_i3];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c18_i3 = 0; c18_i3 < 77; c18_i3 = c18_i3 + 1) {
    c18_b_u[c18_i3] = c18_cv1[c18_i3];
  }

  c18_b_y = NULL;
  sf_mex_assign(&c18_b_y, sf_mex_create("y", &c18_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call("error", 0U, 2U, 14, c18_y, 14, c18_b_y);
}

static void c18_power(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
                      *chartInstance, real_T c18_a[4], real_T c18_b, real_T
                      c18_y[4])
{
  int32_T c18_k;
  for (c18_k = 0; c18_k < 4; c18_k = c18_k + 1) {
    c18_y[c18_k] = muDoubleScalarPower(c18_a[c18_k], 2.0);
  }
}

static real_T c18_sum(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
                      *chartInstance, real_T c18_x[4])
{
  real_T c18_y;
  int32_T c18_k;
  c18_y = c18_x[0];
  for (c18_k = 2; c18_k < 5; c18_k = c18_k + 1) {
    c18_y = c18_y + c18_x[c18_k - 1];
  }

  return c18_y;
}

static void c18_bsxfun(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c18_a[4], real_T c18_b, real_T c18_c[4]
  )
{
  int32_T c18_k;
  for (c18_k = 0; c18_k < 4; c18_k = c18_k + 1) {
    c18_c[c18_k] = c18_a[c18_k] / c18_b;
  }
}

const mxArray *sf_c18_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c18_nameCaptureInfo;
  c18_ResolvedFunctionInfo c18_info[56];
  const mxArray *c18_m0 = NULL;
  int32_T c18_i4;
  c18_ResolvedFunctionInfo *c18_r0;
  c18_nameCaptureInfo = NULL;
  c18_nameCaptureInfo = NULL;
  c18_info_helper(c18_info);
  sf_mex_assign(&c18_m0, sf_mex_createstruct("nameCaptureInfo", 1, 56));
  for (c18_i4 = 0; c18_i4 < 56; c18_i4 = c18_i4 + 1) {
    c18_r0 = &c18_info[c18_i4];
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c18_r0->context, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c18_r0->context)), "context", "nameCaptureInfo", c18_i4);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c18_r0->name, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c18_r0->name)), "name", "nameCaptureInfo", c18_i4);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c18_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen((const
      char *)c18_r0->dominantType)), "dominantType", "nameCaptureInfo", c18_i4);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", (const char *)
      c18_r0->resolved, 15, 0U, 0U, 0U, 2, 1, strlen((const char *)
      c18_r0->resolved)), "resolved", "nameCaptureInfo", c18_i4);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", &c18_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c18_i4);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", &c18_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c18_i4);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", &c18_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c18_i4);
  }

  sf_mex_assign(&c18_nameCaptureInfo, c18_m0);
  return c18_nameCaptureInfo;
}

static void c18_info_helper(c18_ResolvedFunctionInfo c18_info[56])
{
  c18_info[0].context = "";
  c18_info[0].name = "false";
  c18_info[0].dominantType = "";
  c18_info[0].resolved = "[B]false";
  c18_info[0].fileLength = 0U;
  c18_info[0].fileTime1 = 0U;
  c18_info[0].fileTime2 = 0U;
  c18_info[1].context = "";
  c18_info[1].name = "size";
  c18_info[1].dominantType = "double";
  c18_info[1].resolved = "[B]size";
  c18_info[1].fileLength = 0U;
  c18_info[1].fileTime1 = 0U;
  c18_info[1].fileTime2 = 0U;
  c18_info[2].context = "";
  c18_info[2].name = "eq";
  c18_info[2].dominantType = "double";
  c18_info[2].resolved = "[B]eq";
  c18_info[2].fileLength = 0U;
  c18_info[2].fileTime1 = 0U;
  c18_info[2].fileTime2 = 0U;
  c18_info[3].context = "";
  c18_info[3].name = "zeros";
  c18_info[3].dominantType = "double";
  c18_info[3].resolved = "[B]zeros";
  c18_info[3].fileLength = 0U;
  c18_info[3].fileTime1 = 0U;
  c18_info[3].fileTime2 = 0U;
  c18_info[4].context = "";
  c18_info[4].name = "squeeze";
  c18_info[4].dominantType = "double";
  c18_info[4].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/squeeze.m";
  c18_info[4].fileLength = 2029U;
  c18_info[4].fileTime1 = 1242294776U;
  c18_info[4].fileTime2 = 0U;
  c18_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/squeeze.m";
  c18_info[5].name = "nargin";
  c18_info[5].dominantType = "";
  c18_info[5].resolved = "[B]nargin";
  c18_info[5].fileLength = 0U;
  c18_info[5].fileTime1 = 0U;
  c18_info[5].fileTime2 = 0U;
  c18_info[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/squeeze.m";
  c18_info[6].name = "eml_index_class";
  c18_info[6].dominantType = "";
  c18_info[6].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c18_info[6].fileLength = 909U;
  c18_info[6].fileTime1 = 1192463182U;
  c18_info[6].fileTime2 = 0U;
  c18_info[7].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/squeeze.m";
  c18_info[7].name = "ones";
  c18_info[7].dominantType = "char";
  c18_info[7].resolved = "[B]ones";
  c18_info[7].fileLength = 0U;
  c18_info[7].fileTime1 = 0U;
  c18_info[7].fileTime2 = 0U;
  c18_info[8].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/squeeze.m";
  c18_info[8].name = "ndims";
  c18_info[8].dominantType = "double";
  c18_info[8].resolved = "[B]ndims";
  c18_info[8].fileLength = 0U;
  c18_info[8].fileTime1 = 0U;
  c18_info[8].fileTime2 = 0U;
  c18_info[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/squeeze.m";
  c18_info[9].name = "le";
  c18_info[9].dominantType = "double";
  c18_info[9].resolved = "[B]le";
  c18_info[9].fileLength = 0U;
  c18_info[9].fileTime1 = 0U;
  c18_info[9].fileTime2 = 0U;
  c18_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/squeeze.m";
  c18_info[10].name = "cast";
  c18_info[10].dominantType = "double";
  c18_info[10].resolved = "[B]cast";
  c18_info[10].fileLength = 0U;
  c18_info[10].fileTime1 = 0U;
  c18_info[10].fileTime2 = 0U;
  c18_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/squeeze.m";
  c18_info[11].name = "eml_scalar_eg";
  c18_info[11].dominantType = "double";
  c18_info[11].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c18_info[11].fileLength = 3068U;
  c18_info[11].fileTime1 = 1240258410U;
  c18_info[11].fileTime2 = 0U;
  c18_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c18_info[12].name = "gt";
  c18_info[12].dominantType = "double";
  c18_info[12].resolved = "[B]gt";
  c18_info[12].fileLength = 0U;
  c18_info[12].fileTime1 = 0U;
  c18_info[12].fileTime2 = 0U;
  c18_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c18_info[13].name = "isstruct";
  c18_info[13].dominantType = "double";
  c18_info[13].resolved = "[B]isstruct";
  c18_info[13].fileLength = 0U;
  c18_info[13].fileTime1 = 0U;
  c18_info[13].fileTime2 = 0U;
  c18_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c18_info[14].name = "isa";
  c18_info[14].dominantType = "double";
  c18_info[14].resolved = "[B]isa";
  c18_info[14].fileLength = 0U;
  c18_info[14].fileTime1 = 0U;
  c18_info[14].fileTime2 = 0U;
  c18_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c18_info[15].name = "class";
  c18_info[15].dominantType = "double";
  c18_info[15].resolved = "[B]class";
  c18_info[15].fileLength = 0U;
  c18_info[15].fileTime1 = 0U;
  c18_info[15].fileTime2 = 0U;
  c18_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/allreal";
  c18_info[16].name = "isreal";
  c18_info[16].dominantType = "double";
  c18_info[16].resolved = "[B]isreal";
  c18_info[16].fileLength = 0U;
  c18_info[16].fileTime1 = 0U;
  c18_info[16].fileTime2 = 0U;
  c18_info[17].context = "";
  c18_info[17].name = "ctranspose";
  c18_info[17].dominantType = "double";
  c18_info[17].resolved = "[B]ctranspose";
  c18_info[17].fileLength = 0U;
  c18_info[17].fileTime1 = 0U;
  c18_info[17].fileTime2 = 0U;
  c18_info[18].context = "";
  c18_info[18].name = "plus";
  c18_info[18].dominantType = "double";
  c18_info[18].resolved = "[B]plus";
  c18_info[18].fileLength = 0U;
  c18_info[18].fileTime1 = 0U;
  c18_info[18].fileTime2 = 0U;
  c18_info[19].context = "";
  c18_info[19].name = "ge";
  c18_info[19].dominantType = "double";
  c18_info[19].resolved = "[B]ge";
  c18_info[19].fileLength = 0U;
  c18_info[19].fileTime1 = 0U;
  c18_info[19].fileTime2 = 0U;
  c18_info[20].context = "";
  c18_info[20].name = "find";
  c18_info[20].dominantType = "logical";
  c18_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  c18_info[20].fileLength = 7812U;
  c18_info[20].fileTime1 = 1258397990U;
  c18_info[20].fileTime2 = 0U;
  c18_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  c18_info[21].name = "assert";
  c18_info[21].dominantType = "logical";
  c18_info[21].resolved = "[B]assert";
  c18_info[21].fileLength = 0U;
  c18_info[21].fileTime1 = 0U;
  c18_info[21].fileTime2 = 0U;
  c18_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  c18_info[22].name = "true";
  c18_info[22].dominantType = "";
  c18_info[22].resolved = "[B]true";
  c18_info[22].fileLength = 0U;
  c18_info[22].fileTime1 = 0U;
  c18_info[22].fileTime2 = 0U;
  c18_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  c18_info[23].name = "isempty";
  c18_info[23].dominantType = "logical";
  c18_info[23].resolved = "[B]isempty";
  c18_info[23].fileLength = 0U;
  c18_info[23].fileTime1 = 0U;
  c18_info[23].fileTime2 = 0U;
  c18_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  c18_info[24].name = "isscalar";
  c18_info[24].dominantType = "logical";
  c18_info[24].resolved = "[B]isscalar";
  c18_info[24].fileLength = 0U;
  c18_info[24].fileTime1 = 0U;
  c18_info[24].fileTime2 = 0U;
  c18_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  c18_info[25].name = "islogical";
  c18_info[25].dominantType = "logical";
  c18_info[25].resolved = "[B]islogical";
  c18_info[25].fileLength = 0U;
  c18_info[25].fileTime1 = 0U;
  c18_info[25].fileTime2 = 0U;
  c18_info[26].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  c18_info[26].name = "not";
  c18_info[26].dominantType = "logical";
  c18_info[26].resolved = "[B]not";
  c18_info[26].fileLength = 0U;
  c18_info[26].fileTime1 = 0U;
  c18_info[26].fileTime2 = 0U;
  c18_info[27].context = "";
  c18_info[27].name = "sqrt";
  c18_info[27].dominantType = "double";
  c18_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c18_info[27].fileLength = 572U;
  c18_info[27].fileTime1 = 1203444444U;
  c18_info[27].fileTime2 = 0U;
  c18_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c18_info[28].name = "lt";
  c18_info[28].dominantType = "double";
  c18_info[28].resolved = "[B]lt";
  c18_info[28].fileLength = 0U;
  c18_info[28].fileTime1 = 0U;
  c18_info[28].fileTime2 = 0U;
  c18_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c18_info[29].name = "eml_error";
  c18_info[29].dominantType = "char";
  c18_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c18_info[29].fileLength = 315U;
  c18_info[29].fileTime1 = 1213923144U;
  c18_info[29].fileTime2 = 0U;
  c18_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c18_info[30].name = "strcmp";
  c18_info[30].dominantType = "char";
  c18_info[30].resolved = "[B]strcmp";
  c18_info[30].fileLength = 0U;
  c18_info[30].fileTime1 = 0U;
  c18_info[30].fileTime2 = 0U;
  c18_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c18_info[31].name = "eml_scalar_sqrt";
  c18_info[31].dominantType = "double";
  c18_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c18_info[31].fileLength = 664U;
  c18_info[31].fileTime1 = 1209327194U;
  c18_info[31].fileTime2 = 0U;
  c18_info[32].context = "";
  c18_info[32].name = "rdivide";
  c18_info[32].dominantType = "double";
  c18_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c18_info[32].fileLength = 403U;
  c18_info[32].fileTime1 = 1244731952U;
  c18_info[32].fileTime2 = 0U;
  c18_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c18_info[33].name = "eml_div";
  c18_info[33].dominantType = "double";
  c18_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c18_info[33].fileLength = 4269U;
  c18_info[33].fileTime1 = 1228090226U;
  c18_info[33].fileTime2 = 0U;
  c18_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c18_info[34].name = "isinteger";
  c18_info[34].dominantType = "double";
  c18_info[34].resolved = "[B]isinteger";
  c18_info[34].fileLength = 0U;
  c18_info[34].fileTime1 = 0U;
  c18_info[34].fileTime2 = 0U;
  c18_info[35].context = "";
  c18_info[35].name = "times";
  c18_info[35].dominantType = "double";
  c18_info[35].resolved = "[B]times";
  c18_info[35].fileLength = 0U;
  c18_info[35].fileTime1 = 0U;
  c18_info[35].fileTime2 = 0U;
  c18_info[36].context = "";
  c18_info[36].name = "minus";
  c18_info[36].dominantType = "double";
  c18_info[36].resolved = "[B]minus";
  c18_info[36].fileLength = 0U;
  c18_info[36].fileTime1 = 0U;
  c18_info[36].fileTime2 = 0U;
  c18_info[37].context = "";
  c18_info[37].name = "and";
  c18_info[37].dominantType = "logical";
  c18_info[37].resolved = "[B]and";
  c18_info[37].fileLength = 0U;
  c18_info[37].fileTime1 = 0U;
  c18_info[37].fileTime2 = 0U;
  c18_info[38].context = "";
  c18_info[38].name = "mtimes";
  c18_info[38].dominantType = "double";
  c18_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c18_info[38].fileLength = 3425U;
  c18_info[38].fileTime1 = 1250669166U;
  c18_info[38].fileTime2 = 0U;
  c18_info[39].context = "";
  c18_info[39].name = "power";
  c18_info[39].dominantType = "double";
  c18_info[39].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c18_info[39].fileLength = 5380U;
  c18_info[39].fileTime1 = 1228090298U;
  c18_info[39].fileTime2 = 0U;
  c18_info[40].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c18_info[40].name = "eml_scalexp_alloc";
  c18_info[40].dominantType = "double";
  c18_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c18_info[40].fileLength = 808U;
  c18_info[40].fileTime1 = 1230491098U;
  c18_info[40].fileTime2 = 0U;
  c18_info[41].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c18_info[41].name = "eml_scalar_floor";
  c18_info[41].dominantType = "double";
  c18_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c18_info[41].fileLength = 260U;
  c18_info[41].fileTime1 = 1209327190U;
  c18_info[41].fileTime2 = 0U;
  c18_info[42].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c18_info[42].name = "ne";
  c18_info[42].dominantType = "double";
  c18_info[42].resolved = "[B]ne";
  c18_info[42].fileLength = 0U;
  c18_info[42].fileTime1 = 0U;
  c18_info[42].fileTime2 = 0U;
  c18_info[43].context = "";
  c18_info[43].name = "sum";
  c18_info[43].dominantType = "double";
  c18_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c18_info[43].fileLength = 3457U;
  c18_info[43].fileTime1 = 1244731952U;
  c18_info[43].fileTime2 = 0U;
  c18_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c18_info[44].name = "ischar";
  c18_info[44].dominantType = "double";
  c18_info[44].resolved = "[B]ischar";
  c18_info[44].fileLength = 0U;
  c18_info[44].fileTime1 = 0U;
  c18_info[44].fileTime2 = 0U;
  c18_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c18_info[45].name = "eml_assert_valid_dim";
  c18_info[45].dominantType = "double";
  c18_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c18_info[45].fileLength = 909U;
  c18_info[45].fileTime1 = 1240258402U;
  c18_info[45].fileTime2 = 0U;
  c18_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c18_info[46].name = "intmax";
  c18_info[46].dominantType = "char";
  c18_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c18_info[46].fileLength = 1535U;
  c18_info[46].fileTime1 = 1192463128U;
  c18_info[46].fileTime2 = 0U;
  c18_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c18_info[47].name = "int32";
  c18_info[47].dominantType = "double";
  c18_info[47].resolved = "[B]int32";
  c18_info[47].fileLength = 0U;
  c18_info[47].fileTime1 = 0U;
  c18_info[47].fileTime2 = 0U;
  c18_info[48].context = "";
  c18_info[48].name = "bsxfun";
  c18_info[48].dominantType = "function_handle";
  c18_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/bsxfun.m";
  c18_info[48].fileLength = 5346U;
  c18_info[48].fileTime1 = 1240258374U;
  c18_info[48].fileTime2 = 0U;
  c18_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/bsxfun.m/bsxfun_compatible";
  c18_info[49].name = "min";
  c18_info[49].dominantType = "double";
  c18_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c18_info[49].fileLength = 362U;
  c18_info[49].fileTime1 = 1244731952U;
  c18_info[49].fileTime2 = 0U;
  c18_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c18_info[50].name = "nargout";
  c18_info[50].dominantType = "";
  c18_info[50].resolved = "[B]nargout";
  c18_info[50].fileLength = 0U;
  c18_info[50].fileTime1 = 0U;
  c18_info[50].fileTime2 = 0U;
  c18_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c18_info[51].name = "eml_min_or_max";
  c18_info[51].dominantType = "char";
  c18_info[51].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c18_info[51].fileLength = 9969U;
  c18_info[51].fileTime1 = 1240258406U;
  c18_info[51].fileTime2 = 0U;
  c18_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c18_info[52].name = "isnumeric";
  c18_info[52].dominantType = "double";
  c18_info[52].resolved = "[B]isnumeric";
  c18_info[52].fileLength = 0U;
  c18_info[52].fileTime1 = 0U;
  c18_info[52].fileTime2 = 0U;
  c18_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/bsxfun.m";
  c18_info[53].name = "max";
  c18_info[53].dominantType = "double";
  c18_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c18_info[53].fileLength = 362U;
  c18_info[53].fileTime1 = 1244731952U;
  c18_info[53].fileTime2 = 0U;
  c18_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/bsxfun.m";
  c18_info[54].name = "eml_index_minus";
  c18_info[54].dominantType = "int32";
  c18_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c18_info[54].fileLength = 277U;
  c18_info[54].fileTime1 = 1192463184U;
  c18_info[54].fileTime2 = 0U;
  c18_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/bsxfun.m";
  c18_info[55].name = "eml_index_plus";
  c18_info[55].dominantType = "int32";
  c18_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c18_info[55].fileLength = 272U;
  c18_info[55].fileTime1 = 1192463184U;
  c18_info[55].fileTime2 = 0U;
}

static void c18_emlrt_marshallIn(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *
  chartInstance, const mxArray *c18_out, const char_T
  *c18_name, real_T c18_y[4])
{
  real_T c18_dv1[4];
  int32_T c18_i5;
  sf_mex_import(c18_name, sf_mex_dup(c18_out), &c18_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c18_i5 = 0; c18_i5 < 4; c18_i5 = c18_i5 + 1) {
    c18_y[c18_i5] = c18_dv1[c18_i5];
  }

  sf_mex_destroy(&c18_out);
}

static uint8_T c18_b_emlrt_marshallIn
  (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance, const mxArray *
   c18_b_is_active_c18_ODE_Hand_Model_v08_IPC_v03, const char_T *c18_name)
{
  uint8_T c18_y;
  uint8_T c18_u0;
  sf_mex_import(c18_name, sf_mex_dup
                (c18_b_is_active_c18_ODE_Hand_Model_v08_IPC_v03), &c18_u0, 1, 3,
                0U, 0, 0U, 0);
  c18_y = c18_u0;
  sf_mex_destroy(&c18_b_is_active_c18_ODE_Hand_Model_v08_IPC_v03);
  return c18_y;
}

static void c18_refp1_sqrt(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T c18_x_data[1], int32_T c18_x_sizes[
  2])
{
  int32_T c18_b_x_sizes[2];
  int32_T c18_c_x_sizes[2];
  int32_T c18_loop_ub;
  int32_T c18_k;
  int32_T c18_d_x_sizes[2];
  int32_T c18_e_x_sizes[2];
  int32_T c18_f_x_sizes[2];
  int32_T c18_g_x_sizes[2];
  int32_T c18_h_x_sizes[2];
  int32_T c18_i_x_sizes[2];
  int32_T c18_j_x_sizes[2];
  int32_T c18_k_x_sizes[2];
  c18_b_x_sizes[0] = c18_x_sizes[0];
  c18_c_x_sizes[1] = c18_x_sizes[1];
  c18_loop_ub = c18_b_x_sizes[0] * c18_c_x_sizes[1];
  for (c18_k = 1; c18_k <= c18_loop_ub; c18_k = 2) {
    c18_d_x_sizes[0] = c18_x_sizes[0];
    c18_e_x_sizes[1] = c18_x_sizes[1];
    sf_mex_lw_bounds_check(1, 1, c18_d_x_sizes[0] * c18_e_x_sizes[1]);
    if (c18_x_data[0] < 0.0) {
      c18_eml_error(chartInstance);
    }
  }

  c18_f_x_sizes[0] = c18_x_sizes[0];
  c18_g_x_sizes[1] = c18_x_sizes[1];
  c18_loop_ub = c18_f_x_sizes[0] * c18_g_x_sizes[1];
  for (c18_k = 1; c18_k <= c18_loop_ub; c18_k = 2) {
    c18_h_x_sizes[0] = c18_x_sizes[0];
    c18_i_x_sizes[1] = c18_x_sizes[1];
    sf_mex_lw_bounds_check(1, 1, c18_h_x_sizes[0] * c18_i_x_sizes[1]);
    c18_j_x_sizes[0] = c18_x_sizes[0];
    c18_k_x_sizes[1] = c18_x_sizes[1];
    sf_mex_lw_bounds_check(1, 1, c18_j_x_sizes[0] * c18_k_x_sizes[1]);
    c18_x_data[0] = muDoubleScalarSqrt(c18_x_data[0]);
  }
}

static void c18_b_refp1_sqrt(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance, real_T *c18_x)
{
  if (*c18_x < 0.0) {
    c18_eml_error(chartInstance);
  }

  *c18_x = muDoubleScalarSqrt(*c18_x);
}

static void init_dsm_address_info(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c18_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2038107267U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3084274462U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(951672743U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1752026187U);
}

mxArray *sf_c18_ODE_Hand_Model_v08_IPC_v03_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3572419442U);
    pr[1] = (double)(1388820143U);
    pr[2] = (double)(3803205711U);
    pr[3] = (double)(605723605U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

static mxArray *sf_get_sim_state_info_c18_ODE_Hand_Model_v08_IPC_v03(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"out\",},{M[8],M[0],T\"is_active_c18_ODE_Hand_Model_v08_IPC_v03\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c18_ODE_Hand_Model_v08_IPC_v03_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void sf_opaque_initialize_c18_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  initialize_params_c18_ODE_Hand_Model_v08_IPC_v03
    ((SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
  initialize_c18_ODE_Hand_Model_v08_IPC_v03
    ((SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c18_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  enable_c18_ODE_Hand_Model_v08_IPC_v03
    ((SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c18_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  disable_c18_ODE_Hand_Model_v08_IPC_v03
    ((SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c18_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  sf_c18_ODE_Hand_Model_v08_IPC_v03
    ((SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c18_ODE_Hand_Model_v08_IPC_v03
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c18_ODE_Hand_Model_v08_IPC_v03
    ((SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c18_ODE_Hand_Model_v08_IPC_v03();/* state var info */
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

static void sf_internal_set_sim_state_c18_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c18_ODE_Hand_Model_v08_IPC_v03();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c18_ODE_Hand_Model_v08_IPC_v03
    ((SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c18_ODE_Hand_Model_v08_IPC_v03(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c18_ODE_Hand_Model_v08_IPC_v03(S);
}

static void sf_opaque_set_sim_state_c18_ODE_Hand_Model_v08_IPC_v03(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c18_ODE_Hand_Model_v08_IPC_v03(S, st);
}

static void sf_opaque_terminate_c18_ODE_Hand_Model_v08_IPC_v03(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c18_ODE_Hand_Model_v08_IPC_v03
      ((SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c18_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c18_ODE_Hand_Model_v08_IPC_v03
      ((SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c18_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",18);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ODE_Hand_Model_v08_IPC_v03",
                "ODE_Hand_Model_v08_IPC_v03",18,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "ODE_Hand_Model_v08_IPC_v03","ODE_Hand_Model_v08_IPC_v03",18,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",18,1);
      sf_mark_chart_reusable_outputs(S,"ODE_Hand_Model_v08_IPC_v03",
        "ODE_Hand_Model_v08_IPC_v03",18,1);
    }

    sf_set_rtw_dwork_info(S,"ODE_Hand_Model_v08_IPC_v03",
                          "ODE_Hand_Model_v08_IPC_v03",18);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3342248092U));
  ssSetChecksum1(S,(3919856176U));
  ssSetChecksum2(S,(986688841U));
  ssSetChecksum3(S,(1998956536U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c18_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ODE_Hand_Model_v08_IPC_v03",
      "ODE_Hand_Model_v08_IPC_v03",18);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c18_ODE_Hand_Model_v08_IPC_v03(SimStruct *S)
{
  SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *chartInstance;
  chartInstance = (SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct *)malloc
    (sizeof(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc18_ODE_Hand_Model_v08_IPC_v03InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c18_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c18_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c18_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c18_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c18_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c18_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c18_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c18_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c18_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlStart = mdlStart_c18_ODE_Hand_Model_v08_IPC_v03;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c18_ODE_Hand_Model_v08_IPC_v03;
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

void c18_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c18_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c18_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c18_ODE_Hand_Model_v08_IPC_v03(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c18_ODE_Hand_Model_v08_IPC_v03_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
