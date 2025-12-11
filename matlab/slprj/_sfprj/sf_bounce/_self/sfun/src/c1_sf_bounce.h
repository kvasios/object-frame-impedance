#ifndef __c1_sf_bounce_h__
#define __c1_sf_bounce_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  real_T c1_lastMajorTime;
  SimStruct *S;
  const mxArray *c1_setSimStateSideEffectsInfo;
  uint8_T c1_doSetSimStateSideEffects;
  uint8_T c1_is_active_c1_sf_bounce;
  uint8_T c1_is_c1_sf_bounce;
  ChartInfoStruct chartInfo;
} SFc1_sf_bounceInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_sf_bounce_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_sf_bounce_get_check_sum(mxArray *plhs[]);
extern void c1_sf_bounce_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
