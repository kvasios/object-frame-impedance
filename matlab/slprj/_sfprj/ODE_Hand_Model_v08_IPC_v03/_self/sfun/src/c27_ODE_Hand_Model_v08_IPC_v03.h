#ifndef __c27_ODE_Hand_Model_v08_IPC_v03_h__
#define __c27_ODE_Hand_Model_v08_IPC_v03_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char *context;
  const char *name;
  const char *dominantType;
  const char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c27_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  uint8_T c27_is_active_c27_ODE_Hand_Model_v08_IPC_v03;
  ChartInfoStruct chartInfo;
} SFc27_ODE_Hand_Model_v08_IPC_v03InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c27_ODE_Hand_Model_v08_IPC_v03_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c27_ODE_Hand_Model_v08_IPC_v03_get_check_sum(mxArray *plhs[]);
extern void c27_ODE_Hand_Model_v08_IPC_v03_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
