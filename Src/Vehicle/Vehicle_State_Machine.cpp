//
// Created by Andrew on 8/1/2020.
//

#include "Vehicle_State_Machine.h"
void Vehicle_State_Machine::StateChange(Indicators event) {
  State.Indicator_S = event;

  // TODO Start indicator timer if necessary
}
