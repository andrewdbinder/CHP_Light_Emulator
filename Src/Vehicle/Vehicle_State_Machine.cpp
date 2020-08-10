//
// Created by Andrew on 8/1/2020.
//

#include "Vehicle_State_Machine.h"
char Vehicle_State_Machine::StateChange(Indicators event) {
  State.Indicator_S = event;

  switch (event) {
    case Indicators::OFF:
      return '-';
    case Indicators::TURN_LEFT:
      return '[';
    case Indicators::TURN_RIGHT:
      return ']';
    case Indicators::HAZARD:
      return '=';
  }

  // TODO Start indicator timer if necessary
}
char Vehicle_State_Machine::StateChange(Gear event) {
  State.Gear_S = event;

  switch (event) {
    case Gear::PARK:
      return 'P';
    case Gear::REVERSE:
      return 'o';
    case Gear::DRIVE:
      return 'i';
  }
}

char Vehicle_State_Machine::StateChange(Headlights event) {
  State.Headlight_S = event;

  switch (event) {
    case Headlights::OFF:
      return 't';
    case Headlights::PARK:
      return 'y';
    case Headlights::ON:
      return 'u';
  }
}

char Vehicle_State_Machine::StateChange(Brights event) {
  State.Brights_S = event;

  switch (event) {
    case Brights::OFF:
      return 'T';
    case Brights::ON:
      return 'U';
  }
}

char Vehicle_State_Machine::StateChange(Brakes event) {
  State.Brakes_S = event;

  switch (event) {
    case Brakes::OFF:
      return 'V';
    case Brakes::ON:
      return 'v';
  }
}

char Vehicle_State_Machine::StateChange(Horn event) {
  State.Horn_S = event;

  switch (event) {
    case Horn::OFF:
      return 'R';
    case Horn::ON:
      return 'r';
  }
}
