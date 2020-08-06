#include <iostream>
#include "EmergencyEquipment/CHP_State_Machine.h"
#include "CHP.h"

using namespace std;


void testStateMachine(CHP);
void printState(CHP_Emergency_States state);

int main() {



  bool ww;
  bool e_ww[2];

//  ww = &e_ww[0];

  CHP CHP(e_ww, e_ww, &ww);

  e_ww[0] = true;
  e_ww[1] = false;
  cout << CHP.MAIN_TIM[0] << CHP.MAIN_TIM[1] << endl;
  e_ww[0] = false;
  e_ww[1] = true;
  cout << CHP.MAIN_TIM[0] << CHP.MAIN_TIM[1] << endl;

  CHP.EmergencyLights = CHP_Lights();


  cout << sizeof(CHP.EmergencyLights.PB_DR_Inner);
  return 0;
}

void printState(CHP_Emergency_States state) {
  using namespace std;

  cout << "Code 1: " << state.Code1_S << endl;
  cout << "Code 2: " << state.Code2_S << endl;
  cout << "Code 3: " << state.Code3_S << endl;
  cout << "Traffic Advisor: " << state.TrafficAdvisor_S << endl;
  cout << "Siren: " << state.ConSiren_S << endl;
  cout << endl;
}

void testStateMachine(CHP CHP) {
  char char_input;
  do {
    cin >> char_input;

    if (cin) {
      switch (char_input) {
        case '1':
          switch (CHP.StateMachine.State.Code1_S) {

            case Code1::OFF:
              CHP.StateMachine.StateChange(Code1::REAR_AMBER);
              break;
            case Code1::REAR_AMBER:
              CHP.StateMachine.StateChange(Code1::FORWARD_CUTOFF);
              break;
            case Code1::FORWARD_CUTOFF:
              CHP.StateMachine.StateChange(Code1::AMBER_ONLY);
              break;
            case Code1::AMBER_ONLY:
              CHP.StateMachine.StateChange(Code1::OFF);
              break;
          }
          printState(CHP.StateMachine.State);
          break;

        case '2':
          switch (CHP.StateMachine.State.Code2_S) {

            case Code2::OFF:
              CHP.StateMachine.StateChange(Code2::FORWARD_RED);
              break;
            case Code2::FORWARD_RED:
              CHP.StateMachine.StateChange(Code2::FORWARD_RED_WW);
              break;
            case Code2::FORWARD_RED_WW:
              CHP.StateMachine.StateChange(Code2::OFF);
              break;
          }
          printState(CHP.StateMachine.State);
          break;

        case '3':
          switch (CHP.StateMachine.State.Code3_S) {

            case Code3::OFF:
              CHP.StateMachine.StateChange(Code3::CODE_3);
              break;
            case Code3::CODE_3:
              CHP.StateMachine.StateChange(Code3::CODE_3_WW);
              break;
            case Code3::CODE_3_WW:
              CHP.StateMachine.StateChange(Code3::CODE_3_WW_AM);
              break;
            case Code3::CODE_3_WW_AM:
              CHP.StateMachine.StateChange(Code3::CODE_3_PK);
              break;
            case Code3::CODE_3_PK:
              CHP.StateMachine.StateChange(Code3::OFF);
              break;
          }
          printState(CHP.StateMachine.State);
          break;
      }
    }
  } while (true);
}