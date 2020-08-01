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
      LB_FR_INNER_RED,
      LB_FR_OUTER_RED,
      LB_FR_CORNER_RED,

      LB_FR_INNER_BLUE,
      LB_FR_OUTER_BLUE,
      LB_FR_CORNER_BLUE,

      LB_SIDE_BLUE,
      LB_SIDE_RED,

      LB_TAKEDOWN_CENTER,
      LB_TAKEDOWN_OUTER,

      LB_DR_ALLEY,
      LB_PS_ALLEY,

      LB_RE_CORNER_BLUE,
      LB_RE_BLUE,

      LB_RE_CORNER_RED,
      LB_RE_RED,

      LB_TA_1,
      LB_TA_2,
      LB_TA_3,
      LB_TA_4,
      LB_TA_5;

  // Single Lights
  EmergencyLightState
      PB_DR_INNER,
      PB_DR_OUTER,

      PB_PS_INNER,
      PB_PS_OUTER,

      DASH_RED,
      DASH_BLUE;

  // Spotlights
  bool
      SPOT_DR,
      SPOT_PS;
};


#endif //CHP_V4_EMERGENCY_LIGHTS_H
