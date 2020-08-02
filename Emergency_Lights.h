//
// Created by Andrew on 7/6/2020.
//

#ifndef CHP_V4_EMERGENCY_LIGHTS_H
#define CHP_V4_EMERGENCY_LIGHTS_H

enum class EmergencyLightState {
  OFF,
  ON,
  STEADY_BURN
};

class CHP_Lights {
 public:
  // Lightbar
  EmergencyLightState
      LB_FR_Inner_Red,
      LB_FR_Outer_Red,
      LB_FR_Corner_Red,

      LB_FR_Inner_Blue,
      LB_FR_Outer_Blue,
      LB_FR_Corner_Blue,

      LB_Side_Blue,
      LB_Side_Red,

      LB_Takedown_Center,
      LB_Takedown_Outer,

      LB_DR_Alley,
      LB_PS_Alley,

      LB_RE_Corner_Blue,
      LB_RE_Blue,

      LB_RE_Corner_Red,
      LB_RE_Red,

      LB_TA_1,
      LB_TA_2,
      LB_TA_3,
      LB_TA_4,
      LB_TA_5;

  // Single Lights
  EmergencyLightState
      PB_DR_Inner,
      PB_DR_Outer,

      PB_PS_Inner,
      PB_PS_Outer,

      Dash_Red,
      Dash_Blue;

  // Wig Wag
  bool
      Wig_Wag;

  // Spotlights
  bool
      Spot_DR,
      Spot_PS;
};


#endif //CHP_V4_EMERGENCY_LIGHTS_H
