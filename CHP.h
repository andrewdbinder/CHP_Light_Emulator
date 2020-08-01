//
// Created by Andrew on 7/6/2020.
//

#ifndef CHP_V4_CHP_H
#define CHP_V4_CHP_H

#include "CHP_State_Machine.h"
#include "Emergency_Lights.h"
#include "Vehicle_State_Machine.h"
#include "Vehicle_Lights.h"

class CHP {
 public:

  CHP(bool *main_ww_tim, bool *hdl_ww_tim, bool *ind_ww_tim);

  bool
    *MAIN_TIM,
    *HDL_TIM,
    *IND_TIM;

  CHP_Lights EmergencyLights;
  CHP_State_Machine StateMachine;

  Vehicle_Lights VehicleLights;
  Vehicle_State_Machine VehicleStateMachine;


 private:
  void updateEmergencyOutput();
  void updateVehicleOutput();

};

#endif //CHP_V4_CHP_H
