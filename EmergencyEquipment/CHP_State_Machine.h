//
// Created by Andrew on 7/5/2020.
//

#ifndef CHP_V4_CHP_STATE_MACHINE_H
#define CHP_V4_CHP_STATE_MACHINE_H

#include "CHP_Enums.h"

class CHP_Emergency_States {
 public:
  Code1 Code1_S;
  Code2 Code2_S;
  Code3 Code3_S;
  TrafficAdvisor TrafficAdvisor_S;

  ContinuousSiren ConSiren_S;
  IntermittentSiren IntSiren_S;
};

class CHP_State_Machine {
 public:
  CHP_Emergency_States State;

  void StateChange(EmergencyStateEvent);
  void StateChange(Code1 event);
  void StateChange(Code2 event);
  void StateChange(Code3 event);
  void StateChange(TrafficAdvisor event);
  void StateChange(ContinuousSiren event);
  void StateChange(IntermittentSiren event);

};

#endif //CHP_V4_CHP_STATE_MACHINE_H
