//
// Created by Andrew on 7/6/2020.
//

#include "Emergency_Lights.h"

CHP_Lights::CHP_Lights() {
  // Lightbar
//  EmergencyLightState
      LB_FR_Inner_Red = EmergencyLightState::OFF;
      LB_FR_Outer_Red = EmergencyLightState::OFF;
      LB_FR_Corner_Red = EmergencyLightState::OFF;

      LB_FR_Inner_Blue = EmergencyLightState::OFF;
      LB_FR_Outer_Blue = EmergencyLightState::OFF;
      LB_FR_Corner_Blue = EmergencyLightState::OFF;

      LB_Side_Blue = EmergencyLightState::OFF;
      LB_Side_Red = EmergencyLightState::OFF;

      LB_Takedown_Center = EmergencyLightState::OFF;
      LB_Takedown_Outer = EmergencyLightState::OFF;

      LB_DR_Alley = EmergencyLightState::OFF;
      LB_PS_Alley = EmergencyLightState::OFF;

      LB_RE_Corner_Blue = EmergencyLightState::OFF;
      LB_RE_Blue = EmergencyLightState::OFF;

      LB_RE_Corner_Red = EmergencyLightState::OFF;
      LB_RE_Red = EmergencyLightState::OFF;

      LB_TA_1 = EmergencyLightState::OFF;
      LB_TA_2 = EmergencyLightState::OFF;
      LB_TA_3 = EmergencyLightState::OFF;
      LB_TA_4 = EmergencyLightState::OFF;
      LB_TA_5 = EmergencyLightState::OFF;

  // Single Lights
      PB_DR_Inner = EmergencyLightState::OFF;
      PB_DR_Outer = EmergencyLightState::OFF;

      PB_PS_Inner = EmergencyLightState::OFF;
      PB_PS_Outer = EmergencyLightState::OFF;

      Dash_Red = EmergencyLightState::OFF;
      Dash_Blue = EmergencyLightState::OFF;

  // Wig Wag
//  bool
      Wig_Wag = false;

  // Spotlights
//  bool
      Spot_DR = false;
      Spot_PS = false;
}