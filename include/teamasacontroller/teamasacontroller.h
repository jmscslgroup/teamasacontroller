//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: teamasacontroller.h
//
// Code generated for Simulink model 'teamasacontroller'.
//
// Model version                  : 1.5
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Tue Nov 14 15:12:52 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_teamasacontroller_h_
#define RTW_HEADER_teamasacontroller_h_
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "teamasacontroller_types.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_teamasacontroller_T {
  SL_Bus_teamasacontroller_std_msgs_Float64 In1;// '<S7>/In1'
  SL_Bus_teamasacontroller_std_msgs_Float64 In1_o;// '<S6>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_teamasacontroller_T {
  ros_slroscpp_internal_block_P_T obj; // '<S2>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S4>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_e;// '<S3>/SourceBlock'
};

// Parameters (default storage)
struct P_teamasacontroller_T_ {
  SL_Bus_teamasacontroller_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S1>/Constant'

  SL_Bus_teamasacontroller_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                       //  Referenced by: '<S6>/Out1'

  SL_Bus_teamasacontroller_std_msgs_Float64 Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                                //  Referenced by: '<S3>/Constant'

  SL_Bus_teamasacontroller_std_msgs_Float64 Out1_Y0_d;// Computed Parameter: Out1_Y0_d
                                                         //  Referenced by: '<S7>/Out1'

  SL_Bus_teamasacontroller_std_msgs_Float64 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                //  Referenced by: '<S4>/Constant'

  real_T Constant6_Value;              // Expression: 1
                                          //  Referenced by: '<S5>/Constant6'

  real_T Constant7_Value;              // Expression: 2
                                          //  Referenced by: '<S5>/Constant7'

  real_T Constant8_Value;              // Expression: 3
                                          //  Referenced by: '<S5>/Constant8'

  real_T Constant_Value_i;             // Expression: 1/10
                                          //  Referenced by: '<S5>/Constant'

  real_T Constant1_Value;              // Expression: 1/15
                                          //  Referenced by: '<S5>/Constant1'

  real_T Constant2_Value;              // Expression: 1/20
                                          //  Referenced by: '<S5>/Constant2'

  real_T Constant3_Value;              // Expression: 75
                                          //  Referenced by: '<S5>/Constant3'

  real_T Constant4_Value;              // Expression: 85
                                          //  Referenced by: '<S5>/Constant4'

  real_T Constant5_Value;              // Expression: 95
                                          //  Referenced by: '<S5>/Constant5'

  real_T Constant_Value_b;             // Expression: 1
                                          //  Referenced by: '<Root>/Constant'

  real_T mphtoms_Gain;                 // Expression: 0.44704
                                          //  Referenced by: '<S5>/mph to m//s'

};

// Real-time Model Data Structure
struct tag_RTM_teamasacontroller_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_teamasacontroller_T teamasacontroller_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_teamasacontroller_T teamasacontroller_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_teamasacontroller_T teamasacontroller_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void teamasacontroller_initialize(void);
  extern void teamasacontroller_step(void);
  extern void teamasacontroller_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_teamasacontroller_T *const teamasacontroller_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'teamasacontroller'
//  '<S1>'   : 'teamasacontroller/Blank Message'
//  '<S2>'   : 'teamasacontroller/Publish'
//  '<S3>'   : 'teamasacontroller/Subscribe'
//  '<S4>'   : 'teamasacontroller/Subscribe1'
//  '<S5>'   : 'teamasacontroller/Subsystem'
//  '<S6>'   : 'teamasacontroller/Subscribe/Enabled Subsystem'
//  '<S7>'   : 'teamasacontroller/Subscribe1/Enabled Subsystem'
//  '<S8>'   : 'teamasacontroller/Subsystem/Actual Time Gap'
//  '<S9>'   : 'teamasacontroller/Subsystem/Calculate acceleration'
//  '<S10>'  : 'teamasacontroller/Subsystem/Desired Time Gap'
//  '<S11>'  : 'teamasacontroller/Subsystem/Speed Limiter'

#endif                                 // RTW_HEADER_teamasacontroller_h_

//
// File trailer for generated code.
//
// [EOF]
//
