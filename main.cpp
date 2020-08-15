#include <iostream>
#include "Src/EmergencyEquipment/CHP_State_Machine.h"
#include "Src/CHP.h"
#include "Debug/CHP_Enum_cout.h"

using namespace std;

void testStateMachine(CHP);
void printState(CHP_Emergency_States state);

int main() {



  bool ww;
  bool e_ww[2];
  short test = 0;
//  ww = &e_ww[0];

  CHP CHP(e_ww, e_ww, &ww, &ww, &test, &test);

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
          switch (CHP.EmergencyStateMachine.State.Code1_S) {

            case Code1::OFF:
              CHP.EmergencyStateMachine.StateChange(Code1::REAR_AMBER);
              break;
            case Code1::REAR_AMBER:
              CHP.EmergencyStateMachine.StateChange(Code1::FORWARD_CUTOFF);
              break;
            case Code1::FORWARD_CUTOFF:
              CHP.EmergencyStateMachine.StateChange(Code1::AMBER_ONLY);
              break;
            case Code1::AMBER_ONLY:
              CHP.EmergencyStateMachine.StateChange(Code1::OFF);
              break;
          }
          printState(CHP.EmergencyStateMachine.State);
          break;

        case '2':
          switch (CHP.EmergencyStateMachine.State.Code2_S) {

            case Code2::OFF:
              CHP.EmergencyStateMachine.StateChange(Code2::FORWARD_RED);
              break;
            case Code2::FORWARD_RED:
              CHP.EmergencyStateMachine.StateChange(Code2::FORWARD_RED_WW);
              break;
            case Code2::FORWARD_RED_WW:
              CHP.EmergencyStateMachine.StateChange(Code2::OFF);
              break;
          }
          printState(CHP.EmergencyStateMachine.State);
          break;

        case '3':
          switch (CHP.EmergencyStateMachine.State.Code3_S) {

            case Code3::OFF:
              CHP.EmergencyStateMachine.StateChange(Code3::CODE_3);
              break;
            case Code3::CODE_3:
              CHP.EmergencyStateMachine.StateChange(Code3::CODE_3_WW);
              break;
            case Code3::CODE_3_WW:
              CHP.EmergencyStateMachine.StateChange(Code3::CODE_3_WW_AM);
              break;
            case Code3::CODE_3_WW_AM:
              CHP.EmergencyStateMachine.StateChange(Code3::CODE_3_PK);
              break;
            case Code3::CODE_3_PK:
              CHP.EmergencyStateMachine.StateChange(Code3::OFF);
              break;
          }
          printState(CHP.EmergencyStateMachine.State);
          break;
      }
    }
  } while (true);
}