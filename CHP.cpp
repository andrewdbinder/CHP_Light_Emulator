//
// Created by Andrew on 7/6/2020.
//

#include "CHP.h"
CHP::CHP(bool *main_ww_tim, bool *hdl_ww_tim, bool *ind_ww_tim) {
  // Emergency Lights WW
  MAIN_TIM = main_ww_tim;

  // Headlight Flasher
  HDL_TIM = hdl_ww_tim;

  // Indicator Flasher
  IND_TIM = ind_ww_tim;
}

void CHP::updateEmergencyOutput() {
  switch (StateMachine.State.Code1_S) {
    case Code1::OFF:
      break;
    case Code1::REAR_AMBER:
      if (MAIN_TIM[0]) {
        EmergencyLights.LB_RE_Blue = EmergencyLightState::ON;
        EmergencyLights.LB_RE_Corner_Blue = EmergencyLightState::ON;
      } else {
        EmergencyLights.LB_RE_Blue = EmergencyLightState::OFF;
        EmergencyLights.LB_RE_Corner_Blue = EmergencyLightState::OFF;
      }

      if (MAIN_TIM[1]) {
        EmergencyLights.LB_TA_3 = EmergencyLightState::ON;
        EmergencyLights.LB_TA_4 = EmergencyLightState::ON;
        EmergencyLights.LB_TA_5 = EmergencyLightState::ON;
      } else {
        EmergencyLights.LB_TA_3 = EmergencyLightState::OFF;
        EmergencyLights.LB_TA_4 = EmergencyLightState::OFF;
        EmergencyLights.LB_TA_5 = EmergencyLightState::OFF;
      }
      break;

    case Code1::FORWARD_CUTOFF:
      if (MAIN_TIM[0]) {
        EmergencyLights.LB_RE_Blue = EmergencyLightState::ON;
        EmergencyLights.LB_RE_Corner_Blue = EmergencyLightState::ON;

        EmergencyLights.LB_RE_Red = EmergencyLightState::ON;
        EmergencyLights.LB_RE_Corner_Red = EmergencyLightState::ON;
      } else {
        EmergencyLights.LB_RE_Blue = EmergencyLightState::OFF;
        EmergencyLights.LB_RE_Corner_Blue = EmergencyLightState::OFF;

        EmergencyLights.LB_RE_Red = EmergencyLightState::OFF;
        EmergencyLights.LB_RE_Corner_Red = EmergencyLightState::OFF;
      }

      if (MAIN_TIM[1]) {
        EmergencyLights.LB_TA_2 = EmergencyLightState::ON;
        EmergencyLights.LB_TA_3 = EmergencyLightState::ON;
        EmergencyLights.LB_TA_4 = EmergencyLightState::ON;
      } else {
        EmergencyLights.LB_TA_2 = EmergencyLightState::OFF;
        EmergencyLights.LB_TA_3 = EmergencyLightState::OFF;
        EmergencyLights.LB_TA_4 = EmergencyLightState::OFF;
      }
      break;

    case Code1::AMBER_ONLY:
      if (MAIN_TIM[0]) {
        EmergencyLights.LB_TA_1 = EmergencyLightState::ON;
        EmergencyLights.LB_TA_2 = EmergencyLightState::ON;
      } else {
        EmergencyLights.LB_TA_1 = EmergencyLightState::OFF;
        EmergencyLights.LB_TA_2 = EmergencyLightState::OFF;
      }

      if (MAIN_TIM[1]) {
        EmergencyLights.LB_TA_4 = EmergencyLightState::ON;
        EmergencyLights.LB_TA_5 = EmergencyLightState::ON;
      } else {
        EmergencyLights.LB_TA_4 = EmergencyLightState::OFF;
        EmergencyLights.LB_TA_5 = EmergencyLightState::OFF;
      }
      break;
  }

  switch(StateMachine.State.Code2_S) {
    case Code2::OFF:
      break;
    case Code2::FORWARD_RED: // F-RED
      EmergencyLights.LB_FR_Inner_Red = EmergencyLightState::STEADY_BURN;
      EmergencyLights.LB_FR_Outer_Red = EmergencyLightState::STEADY_BURN;
      EmergencyLights.LB_FR_Corner_Red = EmergencyLightState::STEADY_BURN;

      EmergencyLights.DASH_RED = EmergencyLightState::STEADY_BURN;

      EmergencyLights.PB_DR_Outer = EmergencyLightState::STEADY_BURN;
      EmergencyLights.PB_PS_Outer = EmergencyLightState::STEADY_BURN;

      if (VehicleStateMachine.State.Gear_S != Gear::PARK) {

        if (MAIN_TIM[0]) {
          EmergencyLights.PB_DR_Inner = EmergencyLightState::ON;
        } else {
          EmergencyLights.PB_DR_Inner = EmergencyLightState::OFF;
        }

        if (MAIN_TIM[1]) {
          EmergencyLights.PB_PS_Inner = EmergencyLightState::ON;
        } else {
          EmergencyLights.PB_PS_Inner = EmergencyLightState::OFF;
        }

      } else {
        EmergencyLights.PB_DR_Inner = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_PS_Inner = EmergencyLightState::STEADY_BURN;
      };

      break;
    case Code2::FORWARD_RED_WW: // F-RED + WW

      break;
  }
}

void CHP::updateVehicleOutput() {

}
