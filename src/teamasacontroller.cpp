//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: teamasacontroller.cpp
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
#include "teamasacontroller.h"
#include <math.h>
#include "rtwtypes.h"
#include "teamasacontroller_types.h"

// Block signals (default storage)
B_teamasacontroller_T teamasacontroller_B;

// Block states (default storage)
DW_teamasacontroller_T teamasacontroller_DW;

// Real-time model
RT_MODEL_teamasacontroller_T teamasacontroller_M_ = RT_MODEL_teamasacontroller_T
  ();
RT_MODEL_teamasacontroller_T *const teamasacontroller_M = &teamasacontroller_M_;

// Model step function
void teamasacontroller_step(void)
{
  SL_Bus_teamasacontroller_std_msgs_Float64 b_varargout_2;
  SL_Bus_teamasacontroller_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_Accelerationratefactor;
  real_T rtb_Followingdistancefactor;
  real_T rtb_MaxSpeed;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S3>/SourceBlock'
  b_varargout_1 = Sub_teamasacontroller_33.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S6>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S6>/In1'
    teamasacontroller_B.In1_o = b_varargout_2;
  }

  // End of MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S4>/SourceBlock'
  b_varargout_1 = Sub_teamasacontroller_34.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S7>/In1'
    teamasacontroller_B.In1 = b_varargout_2;
  }

  // End of MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // MultiPortSwitch: '<S5>/Following distance factor' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<S5>/Constant'
  //   Constant: '<S5>/Constant1'
  //   Constant: '<S5>/Constant2'

  switch (static_cast<int32_T>(teamasacontroller_P.Constant_Value_b)) {
   case 1:
    rtb_Followingdistancefactor = teamasacontroller_P.Constant_Value_i;
    break;

   case 2:
    rtb_Followingdistancefactor = teamasacontroller_P.Constant1_Value;
    break;

   default:
    rtb_Followingdistancefactor = teamasacontroller_P.Constant2_Value;
    break;
  }

  // End of MultiPortSwitch: '<S5>/Following distance factor'

  // Sum: '<S5>/Time gap error' incorporates:
  //   MATLAB Function: '<S5>/Actual Time Gap'
  //   MATLAB Function: '<S5>/Desired Time Gap'

  rtb_Followingdistancefactor = teamasacontroller_B.In1.Data /
    teamasacontroller_B.In1_o.Data - ((teamasacontroller_B.In1_o.Data * 2.23694
    - 30.0) * rtb_Followingdistancefactor + 2.0);

  // MultiPortSwitch: '<S5>/Acceleration rate factor' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<S5>/Constant6'
  //   Constant: '<S5>/Constant7'
  //   Constant: '<S5>/Constant8'

  switch (static_cast<int32_T>(teamasacontroller_P.Constant_Value_b)) {
   case 1:
    rtb_Accelerationratefactor = teamasacontroller_P.Constant6_Value;

    // MultiPortSwitch: '<S5>/Max Speed' incorporates:
    //   Constant: '<S5>/Constant3'
    //   Constant: '<S5>/Constant6'

    rtb_MaxSpeed = teamasacontroller_P.Constant3_Value;
    break;

   case 2:
    rtb_Accelerationratefactor = teamasacontroller_P.Constant7_Value;

    // MultiPortSwitch: '<S5>/Max Speed' incorporates:
    //   Constant: '<S5>/Constant4'
    //   Constant: '<S5>/Constant7'

    rtb_MaxSpeed = teamasacontroller_P.Constant4_Value;
    break;

   default:
    rtb_Accelerationratefactor = teamasacontroller_P.Constant8_Value;

    // MultiPortSwitch: '<S5>/Max Speed' incorporates:
    //   Constant: '<S5>/Constant5'
    //   Constant: '<S5>/Constant8'

    rtb_MaxSpeed = teamasacontroller_P.Constant5_Value;
    break;
  }

  // End of MultiPortSwitch: '<S5>/Acceleration rate factor'

  // MATLAB Function: '<S5>/Speed Limiter' incorporates:
  //   Gain: '<S5>/mph to m//s'

  if (teamasacontroller_B.In1_o.Data < teamasacontroller_P.mphtoms_Gain *
      rtb_MaxSpeed) {
    // MATLAB Function: '<S5>/Calculate acceleration'
    if (teamasacontroller_B.In1.Data > 251.0) {
      // BusAssignment: '<Root>/Bus Assignment'
      rtb_BusAssignment.Data = rtb_Accelerationratefactor * 2.2;
    } else if (rtb_Followingdistancefactor < 0.0) {
      // BusAssignment: '<Root>/Bus Assignment'
      rtb_BusAssignment.Data = -rtb_Accelerationratefactor * sqrt(fabs
        (rtb_Followingdistancefactor));
    } else {
      // BusAssignment: '<Root>/Bus Assignment'
      rtb_BusAssignment.Data = rtb_Accelerationratefactor * sqrt
        (rtb_Followingdistancefactor);
    }
  } else {
    // BusAssignment: '<Root>/Bus Assignment' incorporates:
    //   MATLAB Function: '<S5>/Calculate acceleration'

    rtb_BusAssignment.Data = 0.0;
  }

  // End of MATLAB Function: '<S5>/Speed Limiter'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S2>/SinkBlock'
  Pub_teamasacontroller_31.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
}

// Model initialize function
void teamasacontroller_initialize(void)
{
  {
    char_T b_zeroDelimTopic[17];
    char_T b_zeroDelimTopic_0[11];
    static const char_T tmp[16] = { '/', 'c', 'a', 'r', '/', 's', 't', 'a', 't',
      'e', '/', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_0[10] = { '/', 'l', 'e', 'a', 'd', '_', 'd', 'i',
      's', 't' };

    static const char_T tmp_1[10] = { '/', 'c', 'm', 'd', '_', 'a', 'c', 'c',
      'e', 'l' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S6>/In1' incorporates:
    //   Outport: '<S6>/Out1'

    teamasacontroller_B.In1_o = teamasacontroller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    teamasacontroller_DW.obj_e.matlabCodegenIsDeleted = false;
    teamasacontroller_DW.obj_e.isInitialized = 1;
    for (int32_T i = 0; i < 16; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[16] = '\x00';
    Sub_teamasacontroller_33.createSubscriber(&b_zeroDelimTopic[0], 1);
    teamasacontroller_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S7>/In1' incorporates:
    //   Outport: '<S7>/Out1'

    teamasacontroller_B.In1 = teamasacontroller_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    teamasacontroller_DW.obj_n.matlabCodegenIsDeleted = false;
    teamasacontroller_DW.obj_n.isInitialized = 1;
    for (int32_T i = 0; i < 10; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[10] = '\x00';
    Sub_teamasacontroller_34.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    teamasacontroller_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    teamasacontroller_DW.obj.matlabCodegenIsDeleted = false;
    teamasacontroller_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 10; i++) {
      b_zeroDelimTopic_0[i] = tmp_1[i];
    }

    b_zeroDelimTopic_0[10] = '\x00';
    Pub_teamasacontroller_31.createPublisher(&b_zeroDelimTopic_0[0], 1);
    teamasacontroller_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void teamasacontroller_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!teamasacontroller_DW.obj_e.matlabCodegenIsDeleted) {
    teamasacontroller_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!teamasacontroller_DW.obj_n.matlabCodegenIsDeleted) {
    teamasacontroller_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  if (!teamasacontroller_DW.obj.matlabCodegenIsDeleted) {
    teamasacontroller_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
