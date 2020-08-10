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

  EmergencyLights = CHP_Lights();
  VehicleLights = Vehicle_Lights();
}

void CHP::updateEmergencyOutput() {
  switch (EmergencyStateMachine.State.Code1_S) {
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

  switch(EmergencyStateMachine.State.Code2_S) {
    case Code2::OFF:
      break;
    case Code2::FORWARD_RED: // F-RED
      EmergencyLights.LB_FR_Inner_Red = EmergencyLightState::STEADY_BURN;
      EmergencyLights.LB_FR_Outer_Red = EmergencyLightState::STEADY_BURN;
      EmergencyLights.LB_FR_Corner_Red = EmergencyLightState::STEADY_BURN;

      EmergencyLights.Dash_Red = EmergencyLightState::STEADY_BURN;

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
      EmergencyLights.Wig_Wag = true;

      EmergencyLights.LB_FR_Inner_Red = EmergencyLightState::STEADY_BURN;
      EmergencyLights.LB_FR_Outer_Red = EmergencyLightState::STEADY_BURN;

      EmergencyLights.Dash_Red = EmergencyLightState::STEADY_BURN;


      if (VehicleStateMachine.State.Gear_S != Gear::PARK) {

        if (MAIN_TIM[0]) {
          EmergencyLights.LB_FR_Corner_Red = EmergencyLightState::ON;
          EmergencyLights.PB_DR_Inner = EmergencyLightState::ON;
          EmergencyLights.PB_DR_Outer = EmergencyLightState::ON;
        } else {
          EmergencyLights.LB_FR_Corner_Red = EmergencyLightState::OFF;
          EmergencyLights.PB_DR_Inner = EmergencyLightState::OFF;
          EmergencyLights.PB_DR_Outer = EmergencyLightState::OFF;
        }

        if (MAIN_TIM[1]) {
          EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::ON;
          EmergencyLights.PB_PS_Inner = EmergencyLightState::ON;
          EmergencyLights.PB_PS_Outer = EmergencyLightState::ON;
        } else {
          EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::OFF;
          EmergencyLights.PB_PS_Inner = EmergencyLightState::OFF;
          EmergencyLights.PB_PS_Outer = EmergencyLightState::OFF;
        }

      } else {
        EmergencyLights.Wig_Wag = false;

        EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::STEADY_BURN;
        EmergencyLights.LB_FR_Corner_Red = EmergencyLightState::STEADY_BURN;

        EmergencyLights.PB_DR_Inner = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_PS_Inner = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_DR_Outer = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_PS_Outer = EmergencyLightState::STEADY_BURN;
      };
      break;
  }

  switch(EmergencyStateMachine.State.Code3_S) {

    case Code3::OFF:
      break;

    case Code3::CODE_3:
      EmergencyLights.Wig_Wag = true;

      EmergencyLights.LB_FR_Outer_Red = EmergencyLightState::STEADY_BURN;
      EmergencyLights.Dash_Red = EmergencyLightState::STEADY_BURN;

      if (VehicleStateMachine.State.Gear_S != Gear::PARK) {
        if (EmergencyStateMachine.State.ConSiren_S != ContinuousSiren::YELP) {
          if (MAIN_TIM[0]) {
            EmergencyLights.LB_FR_Inner_Red = EmergencyLightState::ON;
            EmergencyLights.LB_FR_Corner_Red = EmergencyLightState::ON;

            EmergencyLights.PB_DR_Inner = EmergencyLightState::ON;
            EmergencyLights.PB_DR_Outer = EmergencyLightState::ON;
          } else {
            EmergencyLights.LB_FR_Inner_Red = EmergencyLightState::OFF;
            EmergencyLights.LB_FR_Corner_Red = EmergencyLightState::OFF;

            EmergencyLights.PB_DR_Inner = EmergencyLightState::OFF;
            EmergencyLights.PB_DR_Outer = EmergencyLightState::OFF;
          }

          if (MAIN_TIM[1]) {
            EmergencyLights.LB_FR_Inner_Blue = EmergencyLightState::ON;
            EmergencyLights.LB_FR_Outer_Blue = EmergencyLightState::ON;
            EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::ON;

            EmergencyLights.Dash_Blue = EmergencyLightState::ON;

            EmergencyLights.PB_PS_Inner = EmergencyLightState::ON;
            EmergencyLights.PB_PS_Outer = EmergencyLightState::ON;
          } else {
            EmergencyLights.LB_FR_Inner_Blue = EmergencyLightState::OFF;
            EmergencyLights.LB_FR_Outer_Blue = EmergencyLightState::OFF;
            EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::OFF;

            EmergencyLights.Dash_Blue = EmergencyLightState::OFF;

            EmergencyLights.PB_PS_Inner = EmergencyLightState::OFF;
            EmergencyLights.PB_PS_Outer = EmergencyLightState::OFF;
          }
        } else {
          // TODO: "Wall of light" Yelp pattern
        }

      } else {
        EmergencyLights.Wig_Wag = false;

        EmergencyLights.LB_FR_Inner_Blue = EmergencyLightState::STEADY_BURN;
        EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::STEADY_BURN;
        EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::STEADY_BURN;

        EmergencyLights.LB_FR_Inner_Red = EmergencyLightState::STEADY_BURN;
        EmergencyLights.LB_FR_Corner_Red = EmergencyLightState::STEADY_BURN;
        EmergencyLights.LB_FR_Corner_Red = EmergencyLightState::STEADY_BURN;

        EmergencyLights.Dash_Blue = EmergencyLightState::STEADY_BURN;

        EmergencyLights.PB_DR_Inner = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_DR_Outer = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_PS_Inner = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_PS_Outer = EmergencyLightState::STEADY_BURN;
      }
      break;
    case Code3::CODE_3_WW:break;
    case Code3::CODE_3_WW_AM:break;
    case Code3::CODE_3_PK:break;
  }
}

void CHP::updateVehicleOutput() {
  // Const DRL
  if (VehicleStateMachine.State.Headlight_S == Headlights::OFF) {
    VehicleLights.DRL_Const = VehicleLightState::ON;
  } else {
    VehicleLights.DRL_Const = VehicleLightState::DIM;
  }

  // Gear DRL
  if (VehicleStateMachine.State.Headlight_S == Headlights::OFF) {
    if (VehicleStateMachine.State.Gear_S == Gear::PARK) {
      VehicleLights.DRL_Const = VehicleLightState::OFF;
    } else {
      VehicleLights.DRL_Const = VehicleLightState::ON;
    }
  } else {
    VehicleLights.DRL_Const = VehicleLightState::DIM;
  }

  // Turn DRL
  if (VehicleStateMachine.State.Headlight_S == Headlights::OFF) {
    if (VehicleStateMachine.State.Gear_S == Gear::PARK) {
      VehicleLights.DRL_Turn_D = VehicleLightState::OFF;
      VehicleLights.DRL_Turn_P = VehicleLightState::OFF;
    } else {
      if (VehicleStateMachine.State.Indicator_S == Indicators::TURN_LEFT ||
          VehicleStateMachine.State.Indicator_S == Indicators::HAZARD ) {
        VehicleLights.DRL_Turn_D = VehicleLightState::OFF;
      } else {
        VehicleLights.DRL_Turn_D = VehicleLightState::ON;
      }

      if (VehicleStateMachine.State.Indicator_S == Indicators::TURN_RIGHT ||
          VehicleStateMachine.State.Indicator_S == Indicators::HAZARD ) {
        VehicleLights.DRL_Turn_P = VehicleLightState::OFF;
      } else {
        VehicleLights.DRL_Turn_P = VehicleLightState::ON;
      }
    }
  } else {
    VehicleLights.DRL_Turn_D = VehicleLightState::DIM;
    VehicleLights.DRL_Turn_P = VehicleLightState::DIM;
  }

  // Turn Signals
  if (VehicleStateMachine.State.Indicator_S == Indicators::TURN_LEFT ||
      VehicleStateMachine.State.Indicator_S == Indicators::HAZARD) {
    if (IND_TIM) {
      VehicleLights.Turn_F_D = VehicleLightState::ON;
      VehicleLights.Turn_Park_F_D = VehicleLightState::ON;
    } else {
      VehicleLights.Turn_F_D = VehicleLightState::OFF;

      if (VehicleStateMachine.State.Headlight_S != Headlights::OFF) {
        VehicleLights.Turn_Park_F_D = VehicleLightState::DIM;
      } else {
        VehicleLights.Turn_Park_F_D = VehicleLightState::OFF;
      }
    }
  }

  if (VehicleStateMachine.State.Indicator_S == Indicators::TURN_RIGHT ||
      VehicleStateMachine.State.Indicator_S == Indicators::HAZARD) {
    if (IND_TIM) {
      VehicleLights.Turn_F_P = VehicleLightState::ON;
      VehicleLights.Turn_Park_F_P = VehicleLightState::ON;
    } else {
      VehicleLights.Turn_F_P = VehicleLightState::OFF;

      if (VehicleStateMachine.State.Headlight_S != Headlights::OFF) {
        VehicleLights.Turn_Park_F_P = VehicleLightState::DIM;
      } else {
        VehicleLights.Turn_Park_F_P = VehicleLightState::OFF;
      }
    }
  }

}
