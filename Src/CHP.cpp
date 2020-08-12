//
// Created by Andrew on 7/6/2020.
//

#include "CHP.h"
CHP::CHP(bool *main_ww_tim, bool *hdl_ww_tim, bool *ind_ww_tim) {
  // Emergency Lights WW1
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

          EmergencyLights.Dash_Blue = EmergencyLightState::ON;
        } else {
          EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::OFF;
          EmergencyLights.PB_PS_Inner = EmergencyLightState::OFF;
          EmergencyLights.PB_PS_Outer = EmergencyLightState::OFF;

          EmergencyLights.Dash_Blue = EmergencyLightState::OFF;
        }

      } else {
        EmergencyLights.Wig_Wag = false;

        EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::STEADY_BURN;
        EmergencyLights.LB_FR_Corner_Red = EmergencyLightState::STEADY_BURN;

        EmergencyLights.Dash_Blue = EmergencyLightState::STEADY_BURN;

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
        EmergencyLights.LB_FR_Outer_Blue = EmergencyLightState::STEADY_BURN;
        EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::STEADY_BURN;

        EmergencyLights.LB_FR_Inner_Red = EmergencyLightState::STEADY_BURN;
        EmergencyLights.LB_FR_Corner_Red = EmergencyLightState::STEADY_BURN;

        EmergencyLights.Dash_Blue = EmergencyLightState::STEADY_BURN;

        EmergencyLights.PB_DR_Inner = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_DR_Outer = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_PS_Inner = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_PS_Outer = EmergencyLightState::STEADY_BURN;
      }
      break;
    case Code3::CODE_3_WW:
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
          EmergencyLights.LB_FR_Outer_Blue = EmergencyLightState::ON;
          EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::ON;

          EmergencyLights.Dash_Blue = EmergencyLightState::ON;

          EmergencyLights.PB_PS_Inner = EmergencyLightState::ON;
          EmergencyLights.PB_PS_Outer = EmergencyLightState::ON;
        } else {
          EmergencyLights.LB_FR_Outer_Blue = EmergencyLightState::OFF;
          EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::OFF;

          EmergencyLights.Dash_Blue = EmergencyLightState::OFF;

          EmergencyLights.PB_PS_Inner = EmergencyLightState::OFF;
          EmergencyLights.PB_PS_Outer = EmergencyLightState::OFF;
        }

      } else {
        EmergencyLights.LB_FR_Outer_Blue = EmergencyLightState::STEADY_BURN;
        EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::STEADY_BURN;

        EmergencyLights.LB_FR_Corner_Red = EmergencyLightState::STEADY_BURN;

        EmergencyLights.Dash_Blue = EmergencyLightState::STEADY_BURN;

        EmergencyLights.PB_DR_Inner = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_DR_Outer = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_PS_Inner = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_PS_Outer = EmergencyLightState::STEADY_BURN;
      }
      break;
    case Code3::CODE_3_WW_AM:
      EmergencyLights.LB_FR_Outer_Red = EmergencyLightState::STEADY_BURN;
      EmergencyLights.Dash_Red = EmergencyLightState::STEADY_BURN;

      if (VehicleStateMachine.State.Gear_S != Gear::PARK) {
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
        EmergencyLights.LB_FR_Inner_Blue = EmergencyLightState::STEADY_BURN;
        EmergencyLights.LB_FR_Outer_Blue = EmergencyLightState::STEADY_BURN;
        EmergencyLights.LB_FR_Corner_Blue = EmergencyLightState::STEADY_BURN;

        EmergencyLights.LB_FR_Inner_Red = EmergencyLightState::STEADY_BURN;
        EmergencyLights.LB_FR_Corner_Red = EmergencyLightState::STEADY_BURN;

        EmergencyLights.Dash_Blue = EmergencyLightState::STEADY_BURN;

        EmergencyLights.PB_DR_Inner = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_DR_Outer = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_PS_Inner = EmergencyLightState::STEADY_BURN;
        EmergencyLights.PB_PS_Outer = EmergencyLightState::STEADY_BURN;
      }

      // Rear lightbar pattern
      // TODO: determine if this is active in park
      if (!Active(EmergencyStateMachine.State.TrafficAdvisor_S)) {
        if (MAIN_TIM[0]) {
          EmergencyLights.LB_RE_Blue = EmergencyLightState::ON;
          EmergencyLights.LB_RE_Corner_Blue = EmergencyLightState::ON;
        } else {
          EmergencyLights.LB_RE_Blue = EmergencyLightState::OFF;
          EmergencyLights.LB_RE_Corner_Blue = EmergencyLightState::OFF;
        }

        if (MAIN_TIM[1]) {
          EmergencyLights.LB_RE_Red = EmergencyLightState::ON;
          EmergencyLights.LB_RE_Corner_Red = EmergencyLightState::ON;
        } else {
          EmergencyLights.LB_RE_Red = EmergencyLightState::OFF;
          EmergencyLights.LB_RE_Corner_Red = EmergencyLightState::OFF;
        }
      }
      break;
    case Code3::CODE_3_PK:break;
  }

  // make rear pattern active in appropriate code states
  if (Active(EmergencyStateMachine.State.Code3_S) &&
      EmergencyStateMachine.State.Code3_S != Code3::CODE_3_WW_AM  ||
      Active(EmergencyStateMachine.State.Code2_S) &&
      !Active(EmergencyStateMachine.State.TrafficAdvisor_S)) {
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
  }

  // Side lightbar lights: always active in code 2/3
  if (Active(EmergencyStateMachine.State.Code2_S) || Active(EmergencyStateMachine.State.Code3_S)) {
    if (MAIN_TIM[0]) {
      EmergencyLights.LB_Side_Red = EmergencyLightState::ON;
    } else {
      EmergencyLights.LB_Side_Red = EmergencyLightState::OFF;
    }

    if (MAIN_TIM[1]) {
      EmergencyLights.LB_Side_Blue = EmergencyLightState::ON;
    } else {
      EmergencyLights.LB_Side_Blue = EmergencyLightState::OFF;
    }
  }


  // Scene lights
  if (EmergencyStateMachine.State.Takedown_S) {
    if (VehicleStateMachine.State.Gear_S == Gear::PARK) {
      EmergencyLights.LB_Takedown_Center = EmergencyLightState::ON;
      EmergencyLights.LB_Takedown_Outer = EmergencyLightState::ON;
    }
  }

  if (EmergencyStateMachine.State.D_Spot_S) {
    EmergencyLights.Spot_DR = true;
  }

  if (EmergencyStateMachine.State.P_Spot_S) {
    EmergencyLights.Spot_PS = true;
  }

  if (EmergencyStateMachine.State.D_Alley_S) {
    EmergencyLights.LB_DR_Alley = EmergencyLightState::ON;
  }

  if (EmergencyStateMachine.State.P_Alley_S) {
    EmergencyLights.LB_PS_Alley = EmergencyLightState::ON;
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
      VehicleLights.DRL_Gear = VehicleLightState::OFF;
    } else {
      VehicleLights.DRL_Gear = VehicleLightState::ON;
    }
  } else {
    VehicleLights.DRL_Gear = VehicleLightState::DIM;
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

  // Park Brakes
  if (VehicleStateMachine.State.Headlight_S != Headlights::OFF) {
    VehicleLights.Brakes_Combo_D = VehicleLightState::DIM;
    VehicleLights.Brakes_Combo_P = VehicleLightState::DIM;

    VehicleLights.Brakes_Park = VehicleLightState::DIM;

    VehicleLights.Park_F = VehicleLightState::ON;
    VehicleLights.Park_R = VehicleLightState::ON;
  }

  // Brakes
  if (VehicleStateMachine.State.Brakes_S == Brakes::ON) {
    VehicleLights.Brakes_Combo_D = VehicleLightState::ON;
    VehicleLights.Brakes_Combo_P = VehicleLightState::ON;

    VehicleLights.Brakes_Park = VehicleLightState::ON;

    VehicleLights.Brakes_3rd = VehicleLightState::ON;
  } else {
    VehicleLights.Brakes_3rd = VehicleLightState::OFF;
  }

  if (VehicleStateMachine.State.Indicator_S == Indicators::TURN_RIGHT ||
      VehicleStateMachine.State.Indicator_S == Indicators::HAZARD) {
    if (*IND_TIM) {
      VehicleLights.Turn_F_P = VehicleLightState::ON;
      VehicleLights.Turn_Park_F_P = VehicleLightState::ON;
      VehicleLights.Brakes_Combo_P = VehicleLightState::ON;
    } else {
      VehicleLights.Turn_F_P = VehicleLightState::OFF;

      if (VehicleStateMachine.State.Headlight_S != Headlights::OFF) {
        VehicleLights.Turn_Park_F_P = VehicleLightState::DIM;
        VehicleLights.Brakes_Combo_P = VehicleLightState::DIM;
      } else {
        VehicleLights.Turn_Park_F_P = VehicleLightState::OFF;
        VehicleLights.Brakes_Combo_P = VehicleLightState::OFF;
      }
    }
  }

  // Turn Signals
  if (VehicleStateMachine.State.Indicator_S == Indicators::TURN_LEFT ||
      VehicleStateMachine.State.Indicator_S == Indicators::HAZARD) {
    if (*IND_TIM) {
      VehicleLights.Turn_F_D = VehicleLightState::ON;
      VehicleLights.Turn_Park_F_D = VehicleLightState::ON;
      VehicleLights.Brakes_Combo_D = VehicleLightState::ON;
    } else {
      VehicleLights.Turn_F_D = VehicleLightState::OFF;

      if (VehicleStateMachine.State.Headlight_S != Headlights::OFF) {
        VehicleLights.Turn_Park_F_D = VehicleLightState::DIM;
        VehicleLights.Brakes_Combo_D = VehicleLightState::DIM;
      } else {
        VehicleLights.Turn_Park_F_D = VehicleLightState::OFF;
        VehicleLights.Brakes_Combo_D = VehicleLightState::OFF;
      }
    }
  }

  // Headlights
  if (VehicleStateMachine.State.Headlight_S == Headlights::ON) {
    VehicleLights.Headlight_D = VehicleLightState::ON;
    VehicleLights.Headlight_P = VehicleLightState::ON;
  } else {
    VehicleLights.Headlight_D = VehicleLightState::OFF;
    VehicleLights.Headlight_P = VehicleLightState::OFF;
  }

  // Reverse Lights
  if (VehicleStateMachine.State.Gear_S == Gear::REVERSE) {
    VehicleLights.Reverse = VehicleLightState::ON;
  } else {
    VehicleLights.Reverse = VehicleLightState::OFF;
  }

  // DRL WW Flash
  // TODO: May need to change; add config/DEFINE option?
  if (EmergencyLights.Wig_Wag) {
    if (*HDL_TIM) {
      VehicleLights.DRL_Turn_D = VehicleLightState::OFF;
      VehicleLights.DRL_Turn_P = VehicleLightState::ON;

      VehicleLights.Brights_D = VehicleLightState::OFF;
      VehicleLights.Brights_P = VehicleLightState::ON;
    } else {
      VehicleLights.DRL_Turn_D = VehicleLightState::ON;
      VehicleLights.DRL_Turn_P = VehicleLightState::OFF;

      VehicleLights.Brights_D = VehicleLightState::ON;
      VehicleLights.Brights_P = VehicleLightState::OFF;
    }
  }

}

char CHP::StateChange(char input) {
  // Reset all light states
  EmergencyLights = CHP_Lights();
  VehicleLights = Vehicle_Lights();

  // Emergency Lights
  switch (input) {

    // Code 1
    case 'z':
      return EmergencyStateMachine.StateChange(Code1::OFF);
    case '1':
      return EmergencyStateMachine.StateChange(Code1::REAR_AMBER);
    case'q':
      return EmergencyStateMachine.StateChange(Code1::FORWARD_CUTOFF);
    case 'a':
      return EmergencyStateMachine.StateChange(Code1::AMBER_ONLY);

    // Code 2
    case 's':
      return EmergencyStateMachine.StateChange(Code2::OFF);
    case '2':
      return EmergencyStateMachine.StateChange(Code2::FORWARD_RED);
    case 'w':
      return EmergencyStateMachine.StateChange(Code2::FORWARD_RED_WW);

    // Code 3
    case 'x':
      return EmergencyStateMachine.StateChange(Code3::OFF);
    case '3':
      return EmergencyStateMachine.StateChange(Code3::CODE_3);
    case 'e':
      return EmergencyStateMachine.StateChange(Code3::CODE_3_WW);
    case 'd':
      return EmergencyStateMachine.StateChange(Code3::CODE_3_WW_AM);
    case 'c':
      return EmergencyStateMachine.StateChange(Code3::CODE_3_PK);

    // Traffic Advisor
    case 'h':
      return EmergencyStateMachine.StateChange(TrafficAdvisor::OFF);
    case 'j':
      return EmergencyStateMachine.StateChange(TrafficAdvisor::LEFT);
    case 'l':
      return EmergencyStateMachine.StateChange(TrafficAdvisor::RIGHT);
    case 'k':
      return EmergencyStateMachine.StateChange(TrafficAdvisor::SPLIT);

    // Siren
    case 'b':
      return EmergencyStateMachine.StateChange(ContinuousSiren::OFF);
    case 'n':
      return EmergencyStateMachine.StateChange(ContinuousSiren::WAIL);
    case 'm':
      return EmergencyStateMachine.StateChange(ContinuousSiren::YELP);

    // Int. Siren
    case ',':
      return EmergencyStateMachine.StateChange(IntermittentSiren::OFF);
    case '.':
      return EmergencyStateMachine.StateChange(IntermittentSiren::AIR_HORN);
    case '/':
      return EmergencyStateMachine.StateChange(IntermittentSiren::MANUAL);

    // Other
    case '0':
      return EmergencyStateMachine.StateChange(EmergencyStateEvent::ALL_OFF);

    // Indicators
    case '-':
      return VehicleStateMachine.StateChange(Indicators::OFF);
    case '[':
      return VehicleStateMachine.StateChange(Indicators::TURN_LEFT);
    case ']':
      return VehicleStateMachine.StateChange(Indicators::TURN_RIGHT);
    case '=':
      return VehicleStateMachine.StateChange(Indicators::HAZARD);

    // Gear
    case 'p':
      return VehicleStateMachine.StateChange(Gear::PARK);
    case 'o':
      return VehicleStateMachine.StateChange(Gear::REVERSE);
    case 'i':
      return VehicleStateMachine.StateChange(Gear::DRIVE);

    // Headlights
    case 't':
      return VehicleStateMachine.StateChange(Headlights::OFF);
    case 'y':
      return VehicleStateMachine.StateChange(Headlights::PARK);
    case 'u':
      return VehicleStateMachine.StateChange(Headlights::ON);

    // Brights
    case 'T':
      return VehicleStateMachine.StateChange(Brights::OFF);
    case 'U':
      return VehicleStateMachine.StateChange(Brights::ON);

    // Brakes
    case 'V':
      return VehicleStateMachine.StateChange(Brakes::OFF);
    case 'v':
      return VehicleStateMachine.StateChange(Brakes::ON);

    // Horn
    case 'R':
      return VehicleStateMachine.StateChange(Horn::OFF);
    case 'r':
      return VehicleStateMachine.StateChange(Horn::ON);

    // Scene
    case '7':
      return EmergencyStateMachine.StateChange(Scene::TAKEDOWN_ON);
    case '&':
      return EmergencyStateMachine.StateChange(Scene::TAKEDOWN_OFF);
    case '6':
      return EmergencyStateMachine.StateChange(Scene::D_ALLEY_ON);
    case '^':
      return EmergencyStateMachine.StateChange(Scene::D_ALLEY_OFF);
    case '8':
      return EmergencyStateMachine.StateChange(Scene::P_ALLEY_ON);
    case '*':
      return EmergencyStateMachine.StateChange(Scene::P_ALLEY_OFF);

    case '4':
      return EmergencyStateMachine.StateChange(Scene::D_SPOT_ON);
    case '$':
      return EmergencyStateMachine.StateChange(Scene::D_SPOT_OFF);
    case '5':
      return EmergencyStateMachine.StateChange(Scene::P_SPOT_ON);
    case '%':
      return EmergencyStateMachine.StateChange(Scene::P_SPOT_OFF);
  }
  return 1;
}
