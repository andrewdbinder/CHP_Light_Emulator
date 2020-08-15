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
      State.IntSiren_S = IntermittentSiren::OFF;
      return '0';
  }

  return 1;
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

    case Code1::CALTRANS:
      State.Code1_S = Code1::CALTRANS;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      return '!';

    case Code1::PCSO:
      State.Code1_S = Code1::PCSO;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::OFF;
      State.TrafficAdvisor_S = TrafficAdvisor::OFF;
      return 'Q';
  }

  return 1;
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

  return 1;
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


    case Code3::CODE_3_NEW_YELP:
      State.Code1_S = Code1::OFF;
      State.Code2_S = Code2::OFF;
      State.Code3_S = Code3::CODE_3_NEW_YELP;
      return '#';
  }

  return 1;
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

  return 1;
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

  return 1;
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

  return 1;
}
char CHP_State_Machine::StateChange(Scene event) {
  switch (event) {
    case Scene::TAKEDOWN_OFF:
      State.Takedown_S = false;
      return '&';
    case Scene::TAKEDOWN_ON:
      State.Takedown_S = true;
      return '7';
    case Scene::D_ALLEY_OFF:
      State.D_Alley_S = false;
      return '^';
    case Scene::D_ALLEY_ON:
      State.D_Alley_S = true;
      return '6';
    case Scene::P_ALLEY_OFF:
      State.P_Alley_S = false;
      return '*';
    case Scene::P_ALLEY_ON:
      State.P_Alley_S = true;
      return '8';
    case Scene::D_SPOT_OFF:
      State.D_Spot_S = false;
      return '$';
    case Scene::D_SPOT_ON:
      State.D_Spot_S = true;
      return '4';
    case Scene::P_SPOT_OFF:
      State.P_Spot_S = false;
      return '%';
    case Scene::P_SPOT_ON:
      State.P_Spot_S = true;
      return '5';
  }

  return 1;
}

CHP_Emergency_States::CHP_Emergency_States() {
  Code1_S = Code1::OFF;
  Code2_S = Code2::OFF;
  Code3_S = Code3::OFF;
  TrafficAdvisor_S = TrafficAdvisor::OFF;

  ConSiren_S = ContinuousSiren::OFF;
  IntSiren_S = IntermittentSiren::OFF;

  Takedown_S = false;
  D_Alley_S = false;
  P_Alley_S = false;
  D_Spot_S = false;
  P_Spot_S = false;
}
