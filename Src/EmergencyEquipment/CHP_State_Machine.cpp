//
// Created by Andrew on 7/5/2020.
//

#include "CHP_State_Machine.h"

char CHP_State_Machine::StateChange(EmergencyStateEvent event) {
  switch(event) {
    case EmergencyStateEvent::ALL_OFF:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      State.ConSiren_S = ContinuousSiren::OFF;
      return '0';
  }
}

char CHP_State_Machine::StateChange(Code1 event) {
  switch(event) {
    case Code1::OFF:
      State.Code1_S = Code1::OFF;
      return 'z';

    case Code1::REAR_AMBER:
      State.Code1_S = Code1::REAR_AMBER;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      return '1';

    case Code1::FORWARD_CUTOFF:
      State.Code1_S = Code1::FORWARD_CUTOFF;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      return 'q';

    case Code1::AMBER_ONLY:
      State.Code1_S = Code1::AMBER_ONLY;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      return 'a';
  }
}

char CHP_State_Machine::StateChange(Code2 event) {
  switch(event) {
    case Code2::OFF:
      State.Code2_S = Code2::OFF;
      return 's';

    case Code2::FORWARD_RED:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::FORWARD_RED;
      State.Code3_S = Code3::OFF;
      return '2';

      case Code2::FORWARD_RED_WW:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::FORWARD_RED_WW;
      State.Code3_S = Code3::OFF;
      return 'w';
  }
}

char CHP_State_Machine::StateChange(Code3 event) {
  switch(event) {
    case Code3::OFF:
      State.Code3_S = Code3::OFF;
      return 'x';

    case Code3::CODE_3:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::CODE_3;
      return '3';

    case Code3::CODE_3_WW:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::CODE_3_WW;
      return 'e';

      // TODO: Not sure if this mode should force shut off TA
    case Code3::CODE_3_WW_AM:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::CODE_3_WW_AM;
      return 'd';

    case Code3::CODE_3_PK:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::CODE_3_PK;
      return 'c';
  }
}

char CHP_State_Machine::StateChange(TrafficAdvisor event) {
  switch(event) {
    case TrafficAdvisor::OFF:
      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      return 'h';

    case TrafficAdvisor::LEFT:
      State.Code1_S = Code1::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::LEFT;
      return 'j';

    case TrafficAdvisor::RIGHT:
      State.Code1_S = Code1::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::RIGHT;
      return 'l';

    case TrafficAdvisor::SPLIT:
      State.Code1_S = Code1::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::SPLIT;
      return 'k';
  }
}

char CHP_State_Machine::StateChange(ContinuousSiren event) {
  switch(event) {
    case ContinuousSiren::OFF:
      State.ConSiren_S = ContinuousSiren::OFF;
      return 'b';

    case ContinuousSiren::WAIL:
      if (Active(State.Code3_S) || State.Code2_S == Code2::FORWARD_RED_WW) {
        State.ConSiren_S = ContinuousSiren::WAIL;
      }
      return 'n';

    case ContinuousSiren::YELP:
      if (Active(State.Code3_S) || State.Code2_S == Code2::FORWARD_RED_WW) {
        State.ConSiren_S = ContinuousSiren::YELP;
      }
      return 'm';
  }
}

char CHP_State_Machine::StateChange(IntermittentSiren event) {
  switch(event) {
    case IntermittentSiren::OFF:
      State.IntSiren_S = IntermittentSiren::OFF;
      return ',';

    case IntermittentSiren::AIR_HORN:
      if (State.Code2_S == Code2::FORWARD_RED) {
        State.IntSiren_S = IntermittentSiren::AIR_HORN;
      }
      return '.';

    case IntermittentSiren::MANUAL:
      if (Active(State.Code3_S) || State.Code2_S == Code2::FORWARD_RED_WW) {
        State.IntSiren_S = IntermittentSiren::MANUAL;
      }
      return '/';
  }
}
