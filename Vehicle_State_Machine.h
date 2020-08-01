//
// Created by Andrew on 8/1/2020.
//

#ifndef CHP_V4_VEHICLE_STATE_MACHINE_H
#define CHP_V4_VEHICLE_STATE_MACHINE_H

enum class Gear {
  PARK,
  REVERSE,
  DRIVE
};

enum class Headlights {
  OFF,
  PARK,
  ON
};

enum class Brights {
  OFF,
  ON
};

enum class Brakes {
  OFF,
  ON
};

enum class Indicators {
  OFF,
  TURN_LEFT,
  TURN_RIGHT,
  HAZARD
};

enum class Horn {
  OFF,
  ON
};

class Vehicle_States {
 public:
  Gear Gear_S;
  Headlights Headlight_S;
  Brights Brights_S;
  Brakes Brakes_S;
  Indicators Indicator_S;
};

class Vehicle_State_Machine {
 public:
  Vehicle_States State;

 void StateChange(Indicators);

};

#endif //CHP_V4_VEHICLE_STATE_MACHINE_H
