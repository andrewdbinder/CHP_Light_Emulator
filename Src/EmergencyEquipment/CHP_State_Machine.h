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

  bool
    Takedown_S,
    D_Alley_S,
    P_Alley_S,
    D_Spot_S,
    P_Spot_S;

  CHP_Emergency_States();
};

class CHP_State_Machine {
 public:
  CHP_Emergency_States State;

  char StateChange(EmergencyStateEvent);
  char StateChange(Code1 event);
  char StateChange(Code2 event);
  char StateChange(Code3 event);
  char StateChange(TrafficAdvisor event);
  char StateChange(ContinuousSiren event);
  char StateChange(IntermittentSiren event);

  char StateChange(Scene event);
};

#endif //CHP_V4_CHP_STATE_MACHINE_H
