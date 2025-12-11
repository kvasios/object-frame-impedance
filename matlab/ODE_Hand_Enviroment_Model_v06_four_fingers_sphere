#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME ODE_Hand_Enviroment_Model_v05_four_fingers_sphere

#define NUM_INPUTS          1
/* Input Port  0 */
#define IN_PORT_0_NAME      tau
#define INPUT_0_WIDTH       12
#define INPUT_DIMS_0_COL    1
#define INPUT_0_DTYPE       real_T
#define INPUT_0_COMPLEX     COMPLEX_NO
#define IN_0_FRAME_BASED    FRAME_NO
#define IN_0_BUS_BASED      0
#define IN_0_BUS_NAME
#define IN_0_DIMS           1-D
#define INPUT_0_FEEDTHROUGH  0
#define IN_0_ISSIGNED        0
#define IN_0_WORDLENGTH      8
#define IN_0_FIXPOINTSCALING 1
#define IN_0_FRACTIONLENGTH  9
#define IN_0_BIAS            0
#define IN_0_SLOPE           0.125

#define NUM_OUTPUTS          3
/* Output Port  0, joint positions q */
#define OUT_PORT_0_NAME      q
#define OUTPUT_0_WIDTH       12
#define OUTPUT_DIMS_0_COL    1
#define OUTPUT_0_DTYPE       real_T
#define OUTPUT_0_COMPLEX     COMPLEX_NO
#define OUT_0_FRAME_BASED    FRAME_NO
#define OUT_0_BUS_BASED      0
#define OUT_0_BUS_NAME
#define OUT_0_DIMS           1-D
#define OUT_0_ISSIGNED        1
#define OUT_0_WORDLENGTH      8
#define OUT_0_FIXPOINTSCALING 1
#define OUT_0_FRACTIONLENGTH  3
#define OUT_0_BIAS            0
#define OUT_0_SLOPE           0.125


/* Output Port  1, joint velocities dq*/
#define OUT_PORT_1_NAME      dq
#define OUTPUT_1_WIDTH       12
#define OUTPUT_DIMS_1_COL    1
#define OUTPUT_1_DTYPE       real_T
#define OUTPUT_1_COMPLEX     COMPLEX_NO
#define OUT_1_FRAME_BASED    FRAME_NO
#define OUT_1_BUS_BASED      0
#define OUT_1_BUS_NAME
#define OUT_1_DIMS           1-D
#define OUT_1_ISSIGNED        1
#define OUT_1_WORDLENGTH      8
#define OUT_1_FIXPOINTSCALING 1
#define OUT_1_FRACTIONLENGTH  3
#define OUT_1_BIAS            0
#define OUT_1_SLOPE           0.125

/* Output Port  2, joints accelerations ddq */
#define OUT_PORT_2_NAME      ddq
#define OUTPUT_2_WIDTH       12
#define OUTPUT_DIMS_2_COL    1
#define OUTPUT_2_DTYPE       real_T
#define OUTPUT_2_COMPLEX     COMPLEX_NO
#define OUT_2_FRAME_BASED    FRAME_NO
#define OUT_2_BUS_BASED      0
#define OUT_2_BUS_NAME
#define OUT_2_DIMS           1-D
#define OUT_2_ISSIGNED        1
#define OUT_2_WORDLENGTH      8
#define OUT_2_FIXPOINTSCALING 1
#define OUT_2_FRACTIONLENGTH  3
#define OUT_2_BIAS            0
#define OUT_2_SLOPE           0.125

#define NPARAMS              0

#define SAMPLE_TIME_0        INHERITED_SAMPLE_TIME
#define NUM_DISC_STATES      1
#define DISC_STATES_IC       [0]
#define NUM_CONT_STATES      0
#define CONT_STATES_IC       [0]

#define SFUNWIZ_GENERATE_TLC 1
#define SOURCEFILES "__SFB__"
#define PANELINDEX           6
#define USE_SIMSTRUCT        0
#define SHOW_COMPILE_STEPS   0
#define CREATE_DEBUG_MEXFILE 0
#define SAVE_CODE_ONLY       0
#define SFUNWIZ_REVISION     3.0

#define NRWORK               12

#include "simstruc.h"
#include <math.h>

#include <assert.h>
#include <ode/ode.h>
#include <drawstuff/drawstuff.h>
//#include <trimesh/TriMesh.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#include <errno.h>


/*
 * kinematic and dynamic parameters
 */
#define NUM   4         /* Number of links; */
#define NUM_FINGERS   4         
//#define hole_height			0.07

#define time_step			0.0315/(3*12)

dsFunctions fn;

dWorldID    world;
dSpaceID	space;
dBodyID		body;
dGeomID		geom;

dJointGroupID contactgroup;


dBodyID     link_thumb[NUM];     // links, link[0] is a base; ????????????link[0]?????????
dJointID    joint_thumb[NUM];

dBodyID     link[NUM];     // links, link[0] is a base; ????????????link[0]?????????
dJointID    joint[NUM];

dBodyID     link2[NUM];     // links, link[0] is a base; ????????????link[0]?????????
dJointID    joint2[NUM];

dBodyID     link3[NUM];     // links, link[0] is a base; ????????????link[0]?????????
dJointID    joint3[NUM];


dBodyID     sphere;

/*Setting the finger parameters*/
static double l[NUM]  = {0.08, 1.00, 0.50, 0.50};  // length of links; ????????????[m]
static double r[NUM]  = {0.10, 0.04, 0.04, 0.02};  // radius of links; ???????????????[m]
static double m[NUM] = {10.00, 2.00, 1.00, 1.00};           // mass; ??????

static double radius = 0.55;
static double sphere_mass = 0.8;

static double axis_x[NUM]  = { 0.00, 0.00, 0.00, 0.00};  // rotation axis; ?????????
static double axis_y[NUM]  = { 0.00, 0.00, 1.00, 1.00};
static double axis_z[NUM]  = { 1.00, 1.00, 0.00, 0.00};

/*thumb*/
static double x_thumb[NUM]= {-0.70,-0.70, -0.70,-0.70};
static double y_thumb[NUM] = {0.00};  // COG; ????????????
static double z_thumb[NUM] = {0.04, 0.75, 1.60, 2.20};

static double anchor_x_thumb[NUM]  = {-0.70,-0.70, -0.70,-0.70};
static double anchor_y_thumb[NUM] = {0.00}; // anchor point; ????????????
static double anchor_z_thumb[NUM] = { 0.00, 0.20, 1.30, 1.90};


/*finger 1*/
static double x[NUM]= {0.60,0.60, 0.60, 0.60};
static double y[NUM] = {0.40, 0.40, 0.40, 0.40};  // COG; ????????????
static double z[NUM] = {0.04, 0.75, 1.60, 2.20};

static double anchor_x[NUM]  = {0.60,0.60, 0.60, 0.60};
static double anchor_y[NUM] = {0.40, 0.40, 0.40, 0.40}; // anchor point; ????????????
static double anchor_z[NUM] = { 0.00, 0.20, 1.30, 1.90};
// 
// 
/*finger 2*/
static double x2[NUM]= {0.70,0.70, 0.70, 0.70};
static double y2[NUM] = {0.00};  // COG; ????????????
static double z2[NUM] = {0.04, 0.75, 1.60, 2.20};

static double anchor_x2[NUM]  = {0.70, 0.70, 0.70, 0.70};
static double anchor_y2[NUM] = {0.00}; // anchor point; ????????????
static double anchor_z2[NUM] = { 0.00, 0.20, 1.30, 1.90};
// 
// 
/*finger 3*/
static double x3[NUM]= {0.60,0.60, 0.60, 0.60};
static double y3[NUM] = {-0.40, -0.40, -0.40, -0.40};  // COG; ????????????
static double z3[NUM] = {0.04, 0.75, 1.60, 2.20};

static double anchor_x3[NUM]  = {0.60,0.60, 0.60, 0.60};
static double anchor_y3[NUM] = {-0.40, -0.40, -0.40, -0.40}; // anchor point; ????????????
static double anchor_z3[NUM] = { 0.00, 0.20, 1.30, 1.90};



static double x_sphere = 0.00;
static double y_sphere = 0.00;
static double z_sphere = 2.10;

static double x_thumb_touch_initial = -0.55;
static double y_thumb_touch_initial =  0.00;
static double z_thumb_touch_initial =  2.08;



pthread_t 		sim_loop_thread;
pthread_mutex_t sync_mutex			= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  data_ready_cond 	= PTHREAD_COND_INITIALIZER;
pthread_cond_t  data_consumed_cond	= PTHREAD_COND_INITIALIZER;

static int				consumed			= 0;
static int				ready				= 0;
static int				drawstuff_run		= 1;
static int				simulink_run		= 1;

static real_T			dq_old[(NUM-1)*NUM_FINGERS]			= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// , 0, 0, 0, 0, 0, 0, 0, 0, 0};




// class Finger{
// public:
//     Finger(double x_basis, double y_basis,double z_basis){
//     }
//     ~Finger(){}
//     
// 
// 
// private:
//     
// }


/** caltulates magnitude of a dVector3 vector 
 */
double vectorMagnitude(dVector3 vector) {
	return dSqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2]);
}

/** gets called everytime a collision is detected
 */
void nearCallback (void *data, dGeomID o1, dGeomID o2)
{
    dBodyID b1 = dGeomGetBody(o1);
    dBodyID b2 = dGeomGetBody(o2);
    dContact contact;  
    contact.surface.mode = dContactBounce | dContactSoftCFM;
    // friction parameter
    contact.surface.mu = 0.8;
    // bounce is the amount of "bouncyness".
    contact.surface.bounce = 0.01;
    // bounce_vel is the minimum incoming velocity to cause a bounce
    contact.surface.bounce_vel = 0.5;
    // constraint force mixing parameter
    contact.surface.soft_cfm = 0.001;  
    if (int numc = dCollide (o1,o2,1,&contact.geom,sizeof(dContact))) {
        dJointID c = dJointCreateContact (world,contactgroup,&contact);
        dJointAttach (c,b1,b2);
    }
}

/** initializes drawstuff visualizer
 */
void start()   /*** Initialize drawing API; ??????API???????????? ***/
{
    float xyz[3] = {  3.04, 1.28, 0.76};   // view point; ??????x, y, z???[m]
    float hpr[3] = { -160.0, 4.50, 0.00};  // view direction; ??????(heading, pitch, roll)???[??]
    dsSetViewpoint(xyz,hpr);               // setting of view point and direction; ????????????????????????
}
/** stub to insert keybindings during the visualization using drawstuff
 */
void command(int cmd)   /*  key control function */
{
    switch (cmd)
    {
		default:
			break;
    }
}

/** executed during each step of the simulation by the dsSimulationLoop function
 * In this function, one major integration step inside ODE is computed,
 * collisions are computed and drawing instructions are performed. */
void simLoop(int pause)
{
	int i = 0;
	int err;
	double* v0;
	double* v1;
	double* v2;
	int i0;
	int i1;
	int i2;

	timespec abstime;
	timeval now;

	/* simulation thread waits for input data */
    pthread_mutex_lock( &sync_mutex );
    if(!ready) {
    	gettimeofday(&now, NULL);
    	abstime.tv_sec = now.tv_sec+10;
    	abstime.tv_nsec = now.tv_usec*1000;
    	err = pthread_cond_timedwait(&data_ready_cond, &sync_mutex, &abstime);
    	if(err == ETIMEDOUT || !simulink_run) {
    		dsStop();
    		pthread_mutex_unlock( &sync_mutex );
    		return;
    	}
    }
    ready = 0;

    /* collision detection */
    dSpaceCollide(space,0,&nearCallback);
    dWorldStep(world, time_step);
    dJointGroupEmpty(contactgroup);

    dsSetColor(1.0,1.0,1.0); // set color; ????????????(r, g, b) ?????????0???1???????????????????????????
    for (int i = 0; i <NUM; i++ ) // ????????????????????????????????????????????????
        dsDrawCapsuleD(dBodyGetPosition(link_thumb[i]), dBodyGetRotation(link_thumb[i]), l[i], r[i]);
    for (int i = 0; i <NUM; i++ ) // ????????????????????????????????????????????????
        dsDrawCapsuleD(dBodyGetPosition(link[i]), dBodyGetRotation(link[i]), l[i], r[i]);
    for (int i = 0; i <NUM; i++ ) // ????????????????????????????????????????????????
        dsDrawCapsuleD(dBodyGetPosition(link2[i]), dBodyGetRotation(link2[i]), l[i], r[i]);
    for (int i = 0; i <NUM; i++ ) // ????????????????????????????????????????????????
        dsDrawCapsuleD(dBodyGetPosition(link3[i]), dBodyGetRotation(link3[i]), l[i], r[i]);

     dsSetColor(0.5,1.0,0);
	 dsDrawSphereD(dBodyGetPosition(sphere), dBodyGetRotation(sphere), radius);
    	/* alerting the main thread the simulation and drawing code has been executed */
    	consumed = 1;
    	pthread_cond_signal(&data_consumed_cond);
    	pthread_mutex_unlock( &sync_mutex );
}

/** executes the visualization code in another thread
 */
void *simLoopThread( void *data )
{
	dAllocateODEDataForThread(dAllocateMaskAll);
	dsFunctions* fn = (dsFunctions*)data;
	dsSimulationLoop(0, NULL, 640, 570, fn);
	pthread_exit(NULL);
    return NULL;
}


/** Output functions
 */
void ODEFrank_RR_Outputs_wrapper(real_T *q,
								 real_T *dq,
								 real_T *ddq,
                          const real_T *xC,
                          const real_T *rWork)
{
		int i = 0;
		int err;

		timespec abstime;
		timeval now;
		
		/* reading inputs */
        dJointAddUniversalTorques(joint_thumb[1],rWork[0],rWork[1]);
        dJointAddHingeTorque(joint_thumb[2],rWork[2]);
        dJointAddHingeTorque(joint_thumb[3],rWork[2]);
        
//         dJointSetHingeParam(joint_thumb[3],dParamVel, 1000*(dJointGetHingeAngle(joint_thumb[3])-dJointGetHingeAngle(joint_thumb[2]))); // Setting of angular velocity
//         dJointSetHingeParam (joint [ j ], dParamFMax and fMax); // Setting of largest torque
        
        
        
//         dJointAddHingeTorque(joint_thumb[3],rWork[2]);

        
        dJointAddUniversalTorques(joint[1],rWork[3],rWork[4]);
        dJointAddHingeTorque(joint[2],rWork[5]);
        dJointAddHingeTorque(joint[3],rWork[5]);

        
        dJointAddUniversalTorques(joint2[1],rWork[6],rWork[7]);
        dJointAddHingeTorque(joint2[2],rWork[8]);
        dJointAddHingeTorque(joint2[3],rWork[8]);
// 
//         
        dJointAddUniversalTorques(joint3[1],rWork[9],rWork[10]);
        dJointAddHingeTorque(joint3[2],rWork[11]);
        dJointAddHingeTorque(joint3[3],rWork[11]);

        
        
        /* signaling simulation thread that inputs are ready */
		pthread_mutex_lock( &sync_mutex );
		ready = 1;
		pthread_cond_signal(&data_ready_cond);

		/* waiting for simulation thread to execute */
		if(!consumed) {
			gettimeofday(&now, NULL);
			abstime.tv_sec = now.tv_sec+1;
			abstime.tv_nsec = now.tv_usec*1000;
			err = pthread_cond_timedwait(&data_consumed_cond, &sync_mutex, &abstime);
			if(err == ETIMEDOUT) {
				drawstuff_run = 0;
				pthread_mutex_unlock( &sync_mutex );
				return;
			}
		}

		/* writing outputs */
        q[0]   =  dJointGetUniversalAngle1(joint_thumb[1]);
		dq[0]  = dJointGetUniversalAngle1Rate(joint_thumb[1]);
		ddq[0] = (dq[0] - dq_old[0])/time_step;
		dq_old[0] = dq[0];
		
        q[1]  = dJointGetUniversalAngle2(joint_thumb[1]);
		dq[1] = dJointGetUniversalAngle2Rate(joint_thumb[1]);
		ddq[1] = (dq[1] - dq_old[1])/time_step;
		dq_old[1] = dq[1];
        
        q[2]  = dJointGetHingeAngle(joint_thumb[2]);
		dq[2] = dJointGetHingeAngleRate(joint_thumb[2]);
		ddq[2] = (dq[2] - dq_old[2])/time_step;
		dq_old[2] = dq[2];
        
        
        
        
        q[3]   = dJointGetUniversalAngle1(joint[1]);
		dq[3]  = dJointGetUniversalAngle1Rate(joint[1]);
		ddq[3] = (dq[3] - dq_old[3])/time_step;
		dq_old[3] = dq[3];
		
        q[4]  = dJointGetUniversalAngle2(joint[1]);
		dq[4] = dJointGetUniversalAngle2Rate(joint[1]);
		ddq[4] = (dq[4] - dq_old[4])/time_step;
		dq_old[4] = dq[4];
        
        q[5]  = dJointGetHingeAngle(joint[2]);
		dq[5] = dJointGetHingeAngleRate(joint[2]);
		ddq[5] = (dq[5] - dq_old[5])/time_step;
		dq_old[5] = dq[5];
//         
//         
        
        q[6]   = dJointGetUniversalAngle1(joint2[1]);
		dq[6]  = dJointGetUniversalAngle1Rate(joint[1]);
		ddq[6] = (dq[6] - dq_old[6])/time_step;
		dq_old[6] = dq[6];
		
        q[7]  = dJointGetUniversalAngle2(joint2[1]);
		dq[7] = dJointGetUniversalAngle2Rate(joint2[1]);
		ddq[7] = (dq[7] - dq_old[7])/time_step;
		dq_old[7] = dq[7];
        
        q[8]  = dJointGetHingeAngle(joint2[2]);
		dq[8] = dJointGetHingeAngleRate(joint2[2]);
		ddq[8] = (dq[8] - dq_old[8])/time_step;
		dq_old[8] = dq[8];
//         
//         
//         
        q[9]   =  dJointGetUniversalAngle1(joint3[1]);
		dq[9]  = dJointGetUniversalAngle1Rate(joint3[1]);
		ddq[9] = (dq[9] - dq_old[9])/time_step;
		dq_old[9] = dq[9];
		
        q[10]  = dJointGetUniversalAngle2(joint3[1]);
		dq[10] = dJointGetUniversalAngle2Rate(joint3[1]);
		ddq[10] = (dq[10] - dq_old[10])/time_step;
		dq_old[10] = dq[10];
        
        q[11]  = dJointGetHingeAngle(joint3[2]);
		dq[11] = dJointGetHingeAngleRate(joint3[2]);
		ddq[11] = (dq[11] - dq_old[11])/time_step;
		dq_old[11] = dq[11];

		consumed = 0;
		pthread_mutex_unlock( &sync_mutex );

}

/**  update function which gets called for every simulation step.
 * 	 Note how, in order to obtain consistent results, simulink simulation time
 * 	 and integration methods must the the same as the one used inside ODE. 
 */
void ODEFrank_RR_mdlUpdate_wrapper(const real_T *tau,
                          const real_T *q,
                          const real_T *dq,
                          const real_T *ddq,
                          real_T *xC,
                          real_T *rWork)
{
	int i = 0;
	xC[0] = 0;
	for(i = 0; i < (NUM-1)*NUM_FINGERS; ++i)
		rWork[i] = tau[i];
}

/*====================*
 * S-function methods *
 *====================*/

/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{

    DECL_AND_INIT_DIMSINFO(inputDimsInfo);
    DECL_AND_INIT_DIMSINFO(outputDimsInfo);
    ssSetNumSFcnParams(S, NPARAMS);
     if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
	 return; /* Parameter mismatch will be reported by Simulink */
     }

    ssSetNumContStates(S, NUM_CONT_STATES);
    ssSetNumDiscStates(S, NUM_DISC_STATES);

    if (!ssSetNumInputPorts(S, NUM_INPUTS)) return;
    inputDimsInfo.width = INPUT_0_WIDTH;
    ssSetInputPortDimensionInfo(S, 0, &inputDimsInfo);
    ssSetInputPortFrameData(S, 0, IN_0_FRAME_BASED);
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 0, INPUT_0_COMPLEX);
    ssSetInputPortDirectFeedThrough(S, 0, INPUT_0_FEEDTHROUGH);
    ssSetInputPortRequiredContiguous(S, 0, 1); /*direct input signal access*/

    if (!ssSetNumOutputPorts(S, NUM_OUTPUTS)) return;
    outputDimsInfo.width = OUTPUT_0_WIDTH;
    ssSetOutputPortDimensionInfo(S, 0, &outputDimsInfo);
    ssSetOutputPortFrameData(S, 0, OUT_0_FRAME_BASED);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 0, OUTPUT_0_COMPLEX);

    outputDimsInfo.width = OUTPUT_1_WIDTH;
    ssSetOutputPortDimensionInfo(S, 1, &outputDimsInfo);
    ssSetOutputPortFrameData(S, 1, OUT_1_FRAME_BASED);
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 1, OUTPUT_1_COMPLEX);

    outputDimsInfo.width = OUTPUT_2_WIDTH;
    ssSetOutputPortDimensionInfo(S, 2, &outputDimsInfo);
    ssSetOutputPortFrameData(S, 2, OUT_2_FRAME_BASED);
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 2, OUTPUT_2_COMPLEX);

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, NRWORK);
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE |
                     SS_OPTION_USE_TLC_WITH_ACCELERATOR |
		     SS_OPTION_WORKS_WITH_CODE_REUSE));
}

#if defined(MATLAB_MEX_FILE)
#define MDL_SET_INPUT_PORT_DIMENSION_INFO
static void mdlSetInputPortDimensionInfo(SimStruct        *S,
                                         int_T            port,
                                         const DimsInfo_T *dimsInfo)
{
    if(!ssSetInputPortDimensionInfo(S, port, dimsInfo)) return;
}
#endif

#define MDL_SET_OUTPUT_PORT_DIMENSION_INFO
#if defined(MDL_SET_OUTPUT_PORT_DIMENSION_INFO)
static void mdlSetOutputPortDimensionInfo(SimStruct        *S,
                                          int_T            port,
                                          const DimsInfo_T *dimsInfo)
{
 if (!ssSetOutputPortDimensionInfo(S, port, dimsInfo)) return;
}
#endif
# define MDL_SET_INPUT_PORT_FRAME_DATA
static void mdlSetInputPortFrameData(SimStruct  *S,
                                     int_T      port,
                                     Frame_T    frameData)
{
    ssSetInputPortFrameData(S, port, frameData);
}

/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specifiy  the sample time.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, time_step);
    ssSetOffsetTime(S, 0, 0.0);
}

#define MDL_INITIALIZE_CONDITIONS
 /* Function: mdlInitializeConditions ========================================
  * Abstract:
  *    Initialize the states
  */
 static void mdlInitializeConditions(SimStruct *S)
 {
	 int i;
	 
	 real_T *xC   = ssGetDiscStates(S);
	 xC[0] =  0;

	 for(i=0; i < (NUM-1)*NUM_FINGERS; ++i)
		 dq_old[i]		= 0;
     
     
     /*Initialize Robotic Posture*/
//      dJointSetAMotorNumAxes(joint_thumb[1],1);
//      dJointSetAMotorAxis(joint_thumb[1],1,1,);
 }

#define MDL_START  /* Change to #undef to remove function */
#if defined(MDL_START)
  /** mdlStart is called once at start of model execution
   * Here ODE and drawstuff are initialized, the simulation thread is started,
   * and physics objects (bodies) and geometric objects (geoms for collision detection)
   * are created. 
   */
  static void mdlStart(SimStruct *S)
  {
	  	int i,j;
	    dMass mass;
	    dMatrix3 rotation;

	    fn.version = DS_VERSION;
	    fn.start   = &start;
	    fn.step    = &simLoop;
	    fn.command = &command;
        fn.path_to_textures = "C:\\odewin\\share\\drawstuff\\textures";


	    dInitODE();

	    consumed = 0;
	    ready = 0;
	    simulink_run = 1;
	    drawstuff_run = 1;
	    for(i=0;i<(NUM-1)*NUM_FINGERS;i++) {
	    	dq_old[i]=0;
	    }

	    world = dWorldCreate();
	    dWorldSetGravity(world, 0, 0, -9.81);
	    /*
	    dWorldSetERP(world, 0.2);
	    dWorldSetCFM(world, 1e-4);
	    */

	    space = dHashSpaceCreate(0);
	    dCreatePlane(space,0,0,1,0);
	    contactgroup = dJointGroupCreate(0);

	  for (int i = 0; i <NUM; i++)         // creation and setting of links; ???????????????????????????
	  {
		  //dMass mass;  // mass parameter; ?????????????????????
		  link_thumb[i] = dBodyCreate(world);     // create link; ??????????????????
		  geom = dCreateCapsule(space, r[i], l[i]);
		  dBodySetPosition(link_thumb[i], x_thumb[i], y_thumb[i], z_thumb[i]); // set position; ???????????????
		  dMassSetZero(&mass);      // initialize the mass parameter; ?????????????????????????????????
		  dMassSetCapsuleTotal(&mass,m[i],3,r[i],l[i]);  // calculate the mass parameter; ????????????????????????
		  dBodySetMass(link_thumb[i], &mass);  // set the mass parameter to the body; ???????????????
		  dGeomSetBody (geom,link_thumb[i]);
	  }
	  
	  joint_thumb[0] = dJointCreateFixed(world, 0); // a fixed joint; ??????????????????????????????????????????
	  dJointAttach(joint_thumb[0], link_thumb[0], 0);     // attach the fixed joint to the ground; ????????????????????????
	  dJointSetFixed(joint_thumb[0]);               // set the fixed joint; ?????????????????????
	  
      joint_thumb[1] = dJointCreateUniversal(world,0);
      dJointAttach(joint_thumb[1],link_thumb[0], link_thumb[1]);
      dJointSetUniversalAnchor(joint_thumb[1],anchor_x_thumb[1], anchor_y_thumb[1],anchor_z_thumb[1]);
      
      for (int j = 2; j <NUM; j++)
	  {
		  joint_thumb[j] = dJointCreateHinge(world, 0);     // create a hinge joint; ?????????????????????
		  dJointAttach(joint_thumb[j], link_thumb[j-1], link_thumb[j]); // attach the joints; ??????????????????
		  dJointSetHingeAnchor(joint_thumb[j], anchor_x_thumb[j], anchor_y_thumb[j],anchor_z_thumb[j]); // set an anchor point; ?????????????????????
		  dJointSetHingeAxis(joint_thumb[j], axis_x[j], axis_y[j], axis_z[j]); // set an rotation axis; ????????????????????????
	  }
	  
      
      
      
      
      
      for (int i = 0; i <NUM; i++)         // creation and setting of links; ???????????????????????????
	  {
		  //dMass mass;  // mass parameter; ?????????????????????
		  link[i] = dBodyCreate(world);     // create link; ??????????????????
		  geom = dCreateCapsule(space, r[i], l[i]);
		  dBodySetPosition(link[i], x[i], y[i], z[i]); // set position; ???????????????
		  dMassSetZero(&mass);      // initialize the mass parameter; ?????????????????????????????????
		  dMassSetCapsuleTotal(&mass,m[i],3,r[i],l[i]);  // calculate the mass parameter; ????????????????????????
		  dBodySetMass(link[i], &mass);  // set the mass parameter to the body; ???????????????
		  dGeomSetBody (geom,link[i]);
	  }
	  
	  joint[0] = dJointCreateFixed(world, 0); // a fixed joint; ??????????????????????????????????????????
	  dJointAttach(joint[0], link[0], 0);     // attach the fixed joint to the ground; ????????????????????????
	  dJointSetFixed(joint[0]);               // set the fixed joint; ?????????????????????
	  
      joint[1] = dJointCreateUniversal(world,0);
      dJointAttach(joint[1],link[0], link[1]);
      dJointSetUniversalAnchor(joint[1],anchor_x[1], anchor_y[1],anchor_z[1]);
      
      for (int j = 2; j <NUM; j++)
	  {
		  joint[j] = dJointCreateHinge(world, 0);     // create a hinge joint; ?????????????????????
		  dJointAttach(joint[j], link[j-1], link[j]); // attach the joints; ??????????????????
		  dJointSetHingeAnchor(joint[j], anchor_x[j], anchor_y[j],anchor_z[j]); // set an anchor point; ?????????????????????
		  dJointSetHingeAxis(joint[j], axis_x[j], axis_y[j], axis_z[j]); // set an rotation axis; ????????????????????????
	  }
      
      
      
      
      for (int i = 0; i <NUM; i++)         // creation and setting of links; ???????????????????????????
	  {
		  //dMass mass;  // mass parameter; ?????????????????????
		  link2[i] = dBodyCreate(world);     // create link; ??????????????????
		  geom = dCreateCapsule(space, r[i], l[i]);
		  dBodySetPosition(link2[i], x2[i], y2[i], z2[i]); // set position; ???????????????
		  dMassSetZero(&mass);      // initialize the mass parameter; ?????????????????????????????????
		  dMassSetCapsuleTotal(&mass,m[i],3,r[i],l[i]);  // calculate the mass parameter; ????????????????????????
		  dBodySetMass(link2[i], &mass);  // set the mass parameter to the body; ???????????????
		  dGeomSetBody (geom,link2[i]);
	  }
	  
	  joint2[0] = dJointCreateFixed(world, 0); // a fixed joint; ??????????????????????????????????????????
	  dJointAttach(joint2[0], link2[0], 0);     // attach the fixed joint to the ground; ????????????????????????
	  dJointSetFixed(joint2[0]);               // set the fixed joint; ?????????????????????
	  
      joint2[1] = dJointCreateUniversal(world,0);
      dJointAttach(joint2[1],link[0], link2[1]);
      dJointSetUniversalAnchor(joint2[1],anchor_x2[1], anchor_y2[1],anchor_z2[1]);
      
      for (int j = 2; j <NUM; j++)
	  {
		  joint2[j] = dJointCreateHinge(world, 0);     // create a hinge joint; ?????????????????????
		  dJointAttach(joint2[j], link2[j-1], link2[j]); // attach the joints; ??????????????????
		  dJointSetHingeAnchor(joint2[j], anchor_x2[j], anchor_y2[j],anchor_z2[j]); // set an anchor point; ?????????????????????
		  dJointSetHingeAxis(joint2[j], axis_x[j], axis_y[j], axis_z[j]); // set an rotation axis; ????????????????????????
	  }
//       
//       
      for (int i = 0; i <NUM; i++)         // creation and setting of links; ???????????????????????????
	  {
		  //dMass mass;  // mass parameter; ?????????????????????
		  link3[i] = dBodyCreate(world);     // create link; ??????????????????
		  geom = dCreateCapsule(space, r[i], l[i]);
		  dBodySetPosition(link3[i], x3[i], y3[i], z3[i]); // set position; ???????????????
		  dMassSetZero(&mass);      // initialize the mass parameter; ?????????????????????????????????
		  dMassSetCapsuleTotal(&mass,m[i],3,r[i],l[i]);  // calculate the mass parameter; ????????????????????????
		  dBodySetMass(link3[i], &mass);  // set the mass parameter to the body; ???????????????
		  dGeomSetBody (geom,link3[i]);
	  }
	  
	  joint3[0] = dJointCreateFixed(world, 0); // a fixed joint; ??????????????????????????????????????????
	  dJointAttach(joint3[0], link3[0], 0);     // attach the fixed joint to the ground; ????????????????????????
	  dJointSetFixed(joint3[0]);               // set the fixed joint; ?????????????????????
	  
      joint3[1] = dJointCreateUniversal(world,0);
      dJointAttach(joint3[1],link3[0], link3[1]);
      dJointSetUniversalAnchor(joint3[1],anchor_x3[1], anchor_y3[1],anchor_z3[1]);
      
      for (int j = 2; j <NUM; j++)
	  {
		  joint3[j] = dJointCreateHinge(world, 0);     // create a hinge joint; ?????????????????????
		  dJointAttach(joint3[j], link3[j-1], link3[j]); // attach the joints; ??????????????????
		  dJointSetHingeAnchor(joint3[j], anchor_x3[j], anchor_y3[j],anchor_z3[j]); // set an anchor point; ?????????????????????
		  dJointSetHingeAxis(joint3[j], axis_x[j], axis_y[j], axis_z[j]); // set an rotation axis; ????????????????????????
	  }
      
      
      sphere = dBodyCreate(world);
      dMassSetZero(&mass);
      dMassSetSphereTotal(&mass,sphere_mass,radius);
      dBodySetMass(sphere,&mass);
      geom = dCreateSphere(space,radius);
      dBodySetPosition(sphere,x_sphere,y_sphere,z_sphere);
      dGeomSetBody(geom,sphere);
      
      
      
	  pthread_create( &sim_loop_thread, NULL, &simLoopThread, (void*) &fn);
  }
#endif /*  MDL_START */

#define MDL_SET_INPUT_PORT_DATA_TYPE
static void mdlSetInputPortDataType(SimStruct *S, int port, DTypeId dType)
{
    ssSetInputPortDataType( S, 0, dType);
}
#define MDL_SET_OUTPUT_PORT_DATA_TYPE
static void mdlSetOutputPortDataType(SimStruct *S, int port, DTypeId dType)
{
    ssSetOutputPortDataType(S, 0, dType);
    ssSetOutputPortDataType(S, 1, dType);
    ssSetOutputPortDataType(S, 2, dType);
}

#define MDL_SET_DEFAULT_PORT_DATA_TYPES
static void mdlSetDefaultPortDataTypes(SimStruct *S)
{
  ssSetInputPortDataType( S, 0, SS_DOUBLE);
  ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  ssSetOutputPortDataType(S, 1, SS_DOUBLE);
  ssSetOutputPortDataType(S, 2, SS_DOUBLE);
}




/* Function: mdlOutputs =======================================================
 *
*/
static void mdlOutputs(SimStruct *S, int_T tid)
{
    real_T        *q  = (real_T *)ssGetOutputPortRealSignal(S,0);
    real_T        *dq  = (real_T *)ssGetOutputPortRealSignal(S,1);
    real_T		  *ddq = (real_T *)ssGetOutputPortRealSignal(S,2);
    const real_T   *xC = ssGetDiscStates(S);
    const real_T   *rWork = ssGetRWork(S);

    ODEFrank_RR_Outputs_wrapper(q, dq, ddq, xC, rWork);
    if(!drawstuff_run) ssSetErrorStatus(S,"error encountered while processing Output. Did you close the simulation window?");
}

#define MDL_UPDATE	// Change to #undef to remove function
#if defined(MDL_UPDATE)
static void mdlUpdate( SimStruct *S, int_T tid )
{
    const real_T   *tau  = (const real_T*) ssGetInputPortSignal(S,0);
    real_T         *xC  = ssGetDiscStates(S);
    real_T        *q  = (real_T *) ssGetOutputPortRealSignal(S,0);
    real_T        *dq  = (real_T *) ssGetOutputPortRealSignal(S,1);
    real_T        *ddq  = (real_T *) ssGetOutputPortRealSignal(S,2);
    real_T        *rWork = (real_T *) ssGetRWork(S);

    ODEFrank_RR_mdlUpdate_wrapper(tau,q,dq,ddq,xC,rWork);
}
#endif /* MDL_UPDATE */

/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{
	simulink_run = 0;
	pthread_cond_signal(&data_ready_cond);

	pthread_join(sim_loop_thread,NULL);
	dJointGroupDestroy(contactgroup);
	dSpaceDestroy(space);
	dWorldDestroy(world);
	dCloseODE();
}
#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif


