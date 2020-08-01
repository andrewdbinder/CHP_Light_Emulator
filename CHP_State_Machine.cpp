//
// Created by Andrew on 7/5/2020.
//

#include "CHP_State_Machine.h"
CHP_Emergency_States CHP_State_Machine::thisObject() {
  return State;
}

void CHP_State_Machine::StateChange(EmergencyStateEvent event) {
  switch(event) {
    case EmergencyStateEvent::ALL_OFF:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      State.ConSiren_S = ContinuousSiren::OFF;
      break;
    case EmergencyStateEvent::AIR_HORN_ON:break;
    case EmergencyStateEvent::AIR_HORN_OFF:break;
    case EmergencyStateEvent::MANUAL_ON:break;
    case EmergencyStateEvent::MANUAL_OFF:break;
  }
}

void CHP_State_Machine::StateChange(Code1 event) {
  switch(event) {
    case Code1::OFF:
      State.Code1_S = Code1::OFF;
      break;

    case Code1::REAR_AMBER:
      State.Code1_S = Code1::REAR_AMBER;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      break;

    case Code1::FORWARD_CUTOFF:
      State.Code1_S = Code1::FORWARD_CUTOFF;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      break;

    case Code1::AMBER_ONLY:
      State.Code1_S = Code1::AMBER_ONLY;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      break;
  }
}

void CHP_State_Machine::StateChange(Code2 event) {
  switch(event) {
    case Code2::OFF:
      State.Code2_S = Code2::OFF;
      break;

    case Code2::FORWARD_RED:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::FORWARD_RED;
      State.Code3_S = Code3::OFF;
//      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      break;

    case Code2::FORWARD_RED_WW:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::FORWARD_RED_WW;
      State.Code3_S = Code3::OFF;
//      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      break;
  }
}
void CHP_State_Machine::StateChange(Code3 event) {
  switch(event) {
    case Code3::OFF:
      State.Code3_S = Code3::OFF;
      break;

    case Code3::CODE_3:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::CODE_3;
      break;

    case Code3::CODE_3_WW:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::CODE_3_WW;
      break;

      // TODO: Not sure if this mode should force shut off TA
    case Code3::CODE_3_WW_AM:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::CODE_3_WW_AM;
      break;

    case Code3::CODE_3_PK:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::CODE_3_PK;
      break;
  }
}
void CHP_State_Machine::StateChange(TrafficAdvisor event) {
  switch(event) {
    case TrafficAdvisor::OFF:
      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      break;

    case TrafficAdvisor::LEFT:
      State.Code1_S = Code1::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::LEFT;
      break;

    case TrafficAdvisor::RIGHT:
      State.Code1_S = Code1::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::RIGHT;
      break;

    case TrafficAdvisor::SPLIT:
      State.Code1_S = Code1::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::SPLIT;
      break;
  }
}

void CHP_State_Machine::StateChange(ContinuousSiren event) {
  switch(event) {
    case ContinuousSiren::OFF:
      State.ConSiren_S = ContinuousSiren::OFF;
      break;

    case ContinuousSiren::WAIL:
      if (Active(State.Code3_S) || State.Code2_S == Code2::FORWARD_RED_WW) {
        State.ConSiren_S = ContinuousSiren::WAIL;
      }
      break;

    case ContinuousSiren::YELP:
      if (Active(State.Code3_S) || State.Code2_S == Code2::FORWARD_RED_WW) {
        State.ConSiren_S = ContinuousSiren::YELP;
      }
      break;
  }
}

void CHP_State_Machine::StateChange(IntermittentSiren event) {
  switch(event) {
    case IntermittentSiren::OFF:
      State.IntSiren_S = IntermittentSiren::OFF;
      break;

    case IntermittentSiren::AIR_HORN:
      if (State.Code2_S == Code2::FORWARD_RED) {
        State.IntSiren_S = IntermittentSiren::AIR_HORN;
      }
      break;

    case IntermittentSiren::MANUAL:
      if (Active(State.Code3_S) || State.Code2_S == Code2::FORWARD_RED_WW) {
        State.IntSiren_S = IntermittentSiren::MANUAL;
      }
      break;
  }
}
