#ifndef __c2_sf_newtons_cradle_h__
#define __c2_sf_newtons_cradle_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  const mxArray *c2_setSimStateSideEffectsInfo;
  uint8_T c2_doSetSimStateSideEffects;
  uint8_T c2_is_active_c2_sf_newtons_cradle;
  uint8_T c2_is_c2_sf_newtons_cradle;
  ChartInfoStruct chartInfo;
} SFc2_sf_newtons_cradleInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_sf_newtons_cradle_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_sf_newtons_cradle_get_check_sum(mxArray *plhs[]);
extern void c2_sf_newtons_cradle_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
