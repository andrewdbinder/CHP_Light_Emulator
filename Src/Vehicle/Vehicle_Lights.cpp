//
// Created by Andrew on 8/1/2020.
//

#include "Vehicle_Lights.h"

Vehicle_Lights::Vehicle_Lights() {
  // Daytime Running Lights
  DRL_Const = VehicleLightState::OFF;
  DRL_Gear = VehicleLightState::OFF;

  DRL_Turn_D = VehicleLightState::OFF;
  DRL_Turn_P = VehicleLightState::OFF;

  Turn_F_D = VehicleLightState::OFF;
  Turn_F_P = VehicleLightState::OFF;

  Turn_Park_F_D = VehicleLightState::OFF;
  Turn_Park_F_P = VehicleLightState::OFF;

  Park_F = VehicleLightState::OFF;

  Headlight_D = VehicleLightState::OFF;
  Headlight_P = VehicleLightState::OFF;

  Brights_D = VehicleLightState::OFF;
  Brights_P = VehicleLightState::OFF;

  Brakes_3rd = VehicleLightState::OFF;

  Brakes_Park = VehicleLightState::OFF;

  Brakes_Combo_D = VehicleLightState::OFF;
  Brakes_Combo_P = VehicleLightState::OFF;

  Turn_R_D = VehicleLightState::OFF;
  Turn_R_P = VehicleLightState::OFF;

  Reverse = VehicleLightState::OFF;

  Park_R = VehicleLightState::OFF;
}

