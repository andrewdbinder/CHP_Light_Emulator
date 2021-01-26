// Example implementation of chp-lighting state machine

#include <iostream>
#include "Src/EmergencyEquipment/CHP_State_Machine.h"
#include "Src/CHP.h"
#include "Debug/CHP_Enum_cout.h"

using namespace std;

// Function Prototypes
void printState(CHP_Emergency_States state);

int main() {
  // Create CHP Variable, no parameters needed for state machine emulation
  CHP CHP;

  // Variable to input character from console
  char input;

  // Continuously read console, change state, and print state to console
  do {
    cin >> input;
    if (cin) {
      // Call CHP.StateChange with char to change state of CHP Object
      CHP.StateChange(input);
      printState(CHP.EmergencyStateMachine.State);
    }
  } while (true);

  return 0;
}

// Inputs state, outputs easy to read states of main emergency states
void printState(CHP_Emergency_States state) {
  using namespace std;

  cout << "Code 1: " << state.Code1_S << endl;
  cout << "Code 2: " << state.Code2_S << endl;
  cout << "Code 3: " << state.Code3_S << endl;
  cout << "Traffic Advisor: " << state.TrafficAdvisor_S << endl;
  cout << "Siren: " << state.ConSiren_S << endl;
  cout << endl;
}
