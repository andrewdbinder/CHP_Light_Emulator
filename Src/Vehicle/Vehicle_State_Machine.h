//
// Created by Andrew on 8/1/2020.
//

#ifndef CHP_V4_VEHICLE_STATE_MACHINE_H
#define CHP_V4_VEHICLE_STATE_MACHINE_H

enum class Gear : char {
  PARK,
  REVERSE,
  DRIVE
};

enum class Headlights : char {
  OFF,
  PARK,
  ON
};

enum class Brights : char {
  OFF,
  ON
};

enum class Brakes : char {
  OFF,
  ON
};

enum class Indicators : char {
  OFF,
  TURN_LEFT,
  TURN_RIGHT,
  HAZARD
};

enum class Horn : char {
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
  Horn Horn_S;
};

class Vehicle_State_Machine {
 public:
  Vehicle_States State;

  char StateChange(Indicators);
  char StateChange(Gear);
  char StateChange(Headlights);
  char StateChange(Brights);
  char StateChange(Brakes);
  char StateChange(Horn);

};

#endif //CHP_V4_VEHICLE_STATE_MACHINE_H
