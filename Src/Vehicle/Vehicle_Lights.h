//
// Created by Andrew on 8/1/2020.
//

#ifndef CHP_V4_VEHICLE_LIGHTS_H
#define CHP_V4_VEHICLE_LIGHTS_H

enum class VehicleLightState {
  OFF,
  DIM, // ~15% brightness, IE park lights
  ON
};


class Vehicle_Lights {
 public:
  VehicleLightState
    // Daytime Running Lights
    DRL_Const,  // Always on; IE 2016 Explorer
    DRL_Gear,   // On in drive/dim with park lights; IE Tahoe

    // Same as Gear, turns off for indicators during daytime
    DRL_Turn_D,
    DRL_Turn_P,

    // Front turn signal, LED ON/OFF
    Turn_F_D,
    Turn_F_P,

    // Front turn signal, Incandescent ON/DIM/OFF; ie crown vic
    Turn_Park_F_D,
    Turn_Park_F_P,

    // Front Park Lights
    Park_F,

    // Headlights
    Headlight_D,
    Headlight_P,

    // Brights
    Brights_D,
    Brights_P,

    // Brakes, ON/OFF
    Brakes_3rd,

    // Brakes, ON/DIM/OFF
    Brakes_Park,

    // Brakes, Incandescent ON/DIM/OFF + Turn
    Brakes_Combo_D,
    Brakes_Combo_P,

    // Turn Signal, LED ON/OFF
    Turn_R_D,
    Turn_R_P,

    // Reverse Lights
    Reverse,

    // Rear Park Lights
    Park_R;

  Vehicle_Lights();
  };

#endif //CHP_V4_VEHICLE_LIGHTS_H
