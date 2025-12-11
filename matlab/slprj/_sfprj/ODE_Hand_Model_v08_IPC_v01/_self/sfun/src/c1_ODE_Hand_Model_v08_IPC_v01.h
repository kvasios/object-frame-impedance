#ifndef __c1_ODE_Hand_Model_v08_IPC_v01_h__
#define __c1_ODE_Hand_Model_v08_IPC_v01_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c1_doneDoubleBufferReInit;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_ODE_Hand_Model_v08_IPC_v01;
  ChartInfoStruct chartInfo;
} SFc1_ODE_Hand_Model_v08_IPC_v01InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_ODE_Hand_Model_v08_IPC_v01_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_ODE_Hand_Model_v08_IPC_v01_get_check_sum(mxArray *plhs[]);
extern void c1_ODE_Hand_Model_v08_IPC_v01_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
