//
// Created by Andrew on 7/5/2020.
//

#include "CHP_Enums.h"

bool Active(Code1 &c) {
  return c != Code1::OFF;
}

bool Active(Code2 &c) {
  return c != Code2::OFF;
}

bool Active(Code3 &c) {
  return c != Code3::OFF;
}

bool Active(TrafficAdvisor &c) {
  return c != TrafficAdvisor::OFF;
}

bool Active(ContinuousSiren &c) {
  return c != ContinuousSiren::OFF;
}

bool Active(IntermittentSiren &c) {
  return c != IntermittentSiren::OFF;
}