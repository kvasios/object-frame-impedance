/*
 * MATLAB Compiler: 4.13 (R2010a)
 * Date: Fri Jan 18 00:06:14 2013
 * Arguments: "-B" "macro_default" "-m" "-W" "main" "-T" "link:exe"
 * "gravity_dynamic_term.m" 
 */

#include "mclmcrrt.h"

#ifdef __cplusplus
extern "C" {
#endif
const unsigned char __MCC_gravity_dynamic_term_session_key[] = {
    '1', '8', '5', 'B', '7', 'B', 'A', 'D', '3', '8', 'F', '5', '9', '0', '7',
    '2', '1', '1', 'E', '8', 'A', '1', 'E', 'A', '3', '0', '9', '0', 'B', '0',
    '5', '3', 'F', '1', 'C', '2', 'F', '5', 'F', '5', 'F', 'B', '2', 'F', '0',
    '8', '2', '1', 'B', '9', 'F', 'D', 'F', 'C', '3', '5', '6', 'F', '2', 'E',
    'E', '3', '6', '5', '0', '2', '1', 'D', '8', 'E', '3', '7', '7', '9', 'B',
    '4', '4', '9', '9', '8', '5', 'F', '3', '1', 'B', '4', '2', 'A', 'D', '2',
    '2', '8', '5', '1', 'D', '8', 'C', 'C', '5', '8', '0', 'F', 'C', '5', 'F',
    '1', '8', 'C', 'F', '0', '0', 'C', 'F', '6', '2', '6', 'D', '8', '0', '3',
    '8', '4', '8', '9', 'F', 'F', 'B', '1', '2', '3', 'C', '9', 'E', '4', '8',
    '3', '4', '8', '0', '3', '9', 'D', '8', '6', '6', 'A', '8', '2', '0', '0',
    '0', '0', '0', '2', 'D', 'E', '4', 'C', '0', 'B', '1', '1', 'A', 'A', '4',
    '7', 'B', '0', 'D', 'C', '9', '2', '8', 'B', '7', '1', 'F', 'A', 'F', '6',
    '6', '5', '2', '6', '2', 'D', '9', 'F', 'D', '3', 'A', '7', '4', 'A', 'B',
    '4', '5', 'D', '4', '4', '5', '0', '0', '2', 'E', 'A', 'F', '6', '6', '8',
    'C', '3', '3', '0', 'A', 'B', 'F', '0', 'D', 'A', '1', '5', '8', '9', '1',
    'C', '9', 'F', '3', '8', 'B', '1', 'E', '7', '2', '5', 'B', 'B', '7', '3',
    'D', 'D', 'B', '5', 'A', 'A', 'E', '9', '3', '2', '7', '6', 'E', '5', '7',
    'A', '\0'};

const unsigned char __MCC_gravity_dynamic_term_public_key[] = {
    '3', '0', '8', '1', '9', 'D', '3', '0', '0', 'D', '0', '6', '0', '9', '2',
    'A', '8', '6', '4', '8', '8', '6', 'F', '7', '0', 'D', '0', '1', '0', '1',
    '0', '1', '0', '5', '0', '0', '0', '3', '8', '1', '8', 'B', '0', '0', '3',
    '0', '8', '1', '8', '7', '0', '2', '8', '1', '8', '1', '0', '0', 'C', '4',
    '9', 'C', 'A', 'C', '3', '4', 'E', 'D', '1', '3', 'A', '5', '2', '0', '6',
    '5', '8', 'F', '6', 'F', '8', 'E', '0', '1', '3', '8', 'C', '4', '3', '1',
    '5', 'B', '4', '3', '1', '5', '2', '7', '7', 'E', 'D', '3', 'F', '7', 'D',
    'A', 'E', '5', '3', '0', '9', '9', 'D', 'B', '0', '8', 'E', 'E', '5', '8',
    '9', 'F', '8', '0', '4', 'D', '4', 'B', '9', '8', '1', '3', '2', '6', 'A',
    '5', '2', 'C', 'C', 'E', '4', '3', '8', '2', 'E', '9', 'F', '2', 'B', '4',
    'D', '0', '8', '5', 'E', 'B', '9', '5', '0', 'C', '7', 'A', 'B', '1', '2',
    'E', 'D', 'E', '2', 'D', '4', '1', '2', '9', '7', '8', '2', '0', 'E', '6',
    '3', '7', '7', 'A', '5', 'F', 'E', 'B', '5', '6', '8', '9', 'D', '4', 'E',
    '6', '0', '3', '2', 'F', '6', '0', 'C', '4', '3', '0', '7', '4', 'A', '0',
    '4', 'C', '2', '6', 'A', 'B', '7', '2', 'F', '5', '4', 'B', '5', '1', 'B',
    'B', '4', '6', '0', '5', '7', '8', '7', '8', '5', 'B', '1', '9', '9', '0',
    '1', '4', '3', '1', '4', 'A', '6', '5', 'F', '0', '9', '0', 'B', '6', '1',
    'F', 'C', '2', '0', '1', '6', '9', '4', '5', '3', 'B', '5', '8', 'F', 'C',
    '8', 'B', 'A', '4', '3', 'E', '6', '7', '7', '6', 'E', 'B', '7', 'E', 'C',
    'D', '3', '1', '7', '8', 'B', '5', '6', 'A', 'B', '0', 'F', 'A', '0', '6',
    'D', 'D', '6', '4', '9', '6', '7', 'C', 'B', '1', '4', '9', 'E', '5', '0',
    '2', '0', '1', '1', '1', '\0'};

static const char * MCC_gravity_dynamic_term_matlabpath_data[] = 
  { "gravity_dyna/", "$TOOLBOXDEPLOYDIR/", "$TOOLBOXMATLABDIR/general/",
    "$TOOLBOXMATLABDIR/ops/", "$TOOLBOXMATLABDIR/lang/",
    "$TOOLBOXMATLABDIR/elmat/", "$TOOLBOXMATLABDIR/randfun/",
    "$TOOLBOXMATLABDIR/elfun/", "$TOOLBOXMATLABDIR/specfun/",
    "$TOOLBOXMATLABDIR/matfun/", "$TOOLBOXMATLABDIR/datafun/",
    "$TOOLBOXMATLABDIR/polyfun/", "$TOOLBOXMATLABDIR/funfun/",
    "$TOOLBOXMATLABDIR/sparfun/", "$TOOLBOXMATLABDIR/scribe/",
    "$TOOLBOXMATLABDIR/graph2d/", "$TOOLBOXMATLABDIR/graph3d/",
    "$TOOLBOXMATLABDIR/specgraph/", "$TOOLBOXMATLABDIR/graphics/",
    "$TOOLBOXMATLABDIR/uitools/", "$TOOLBOXMATLABDIR/strfun/",
    "$TOOLBOXMATLABDIR/imagesci/", "$TOOLBOXMATLABDIR/iofun/",
    "$TOOLBOXMATLABDIR/audiovideo/", "$TOOLBOXMATLABDIR/timefun/",
    "$TOOLBOXMATLABDIR/datatypes/", "$TOOLBOXMATLABDIR/verctrl/",
    "$TOOLBOXMATLABDIR/codetools/", "$TOOLBOXMATLABDIR/helptools/",
    "$TOOLBOXMATLABDIR/winfun/", "$TOOLBOXMATLABDIR/winfun/NET/",
    "$TOOLBOXMATLABDIR/demos/", "$TOOLBOXMATLABDIR/timeseries/",
    "$TOOLBOXMATLABDIR/hds/", "$TOOLBOXMATLABDIR/guide/",
    "$TOOLBOXMATLABDIR/plottools/", "toolbox/local/",
    "$TOOLBOXMATLABDIR/datamanager/", "toolbox/compiler/" };

static const char * MCC_gravity_dynamic_term_classpath_data[] = 
  { "" };

static const char * MCC_gravity_dynamic_term_libpath_data[] = 
  { "" };

static const char * MCC_gravity_dynamic_term_app_opts_data[] = 
  { "" };

static const char * MCC_gravity_dynamic_term_run_opts_data[] = 
  { "" };

static const char * MCC_gravity_dynamic_term_warning_state_data[] = 
  { "off:MATLAB:dispatcher:nameConflict" };


mclComponentData __MCC_gravity_dynamic_term_component_data = { 

  /* Public key data */
  __MCC_gravity_dynamic_term_public_key,

  /* Component name */
  "gravity_dynamic_term",

  /* Component Root */
  "",

  /* Application key data */
  __MCC_gravity_dynamic_term_session_key,

  /* Component's MATLAB Path */
  MCC_gravity_dynamic_term_matlabpath_data,

  /* Number of directories in the MATLAB Path */
  39,

  /* Component's Java class path */
  MCC_gravity_dynamic_term_classpath_data,
  /* Number of directories in the Java class path */
  0,

  /* Component's load library path (for extra shared libraries) */
  MCC_gravity_dynamic_term_libpath_data,
  /* Number of directories in the load library path */
  0,

  /* MCR instance-specific runtime options */
  MCC_gravity_dynamic_term_app_opts_data,
  /* Number of MCR instance-specific runtime options */
  0,

  /* MCR global runtime options */
  MCC_gravity_dynamic_term_run_opts_data,
  /* Number of MCR global runtime options */
  0,
  
  /* Component preferences directory */
  "gravity_dyna_DD9831037030FA2576DCA4FF8FB641DE",

  /* MCR warning status data */
  MCC_gravity_dynamic_term_warning_state_data,
  /* Number of MCR warning status modifiers */
  1,

  /* Path to component - evaluated at runtime */
  NULL

};

#ifdef __cplusplus
}
#endif


