#ifndef __ODE_Hand_Model_v08_IPC_v03_sfun_h__
#define __ODE_Hand_Model_v08_IPC_v03_sfun_h__

/* Include files */
#define S_FUNCTION_NAME                sf_sfun
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#define rtInf                          (mxGetInf())
#define rtMinusInf                     (-(mxGetInf()))
#define rtNaN                          (mxGetNaN())
#define rtIsNaN(X)                     ((int)mxIsNaN(X))
#define rtIsInf(X)                     ((int)mxIsInf(X))

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */
extern int32_T _sfEvent_;
extern real_T _sfTime_;

/* Variable Definitions */

/* Function Declarations */
extern void ODE_Hand_Model_v08_IPC_v03_initializer(void);
extern void ODE_Hand_Model_v08_IPC_v03_terminator(void);

/* Function Definitions */
#endif
