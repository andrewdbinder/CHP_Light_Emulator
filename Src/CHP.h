//
// Created by Andrew on 7/6/2020.
//

#ifndef CHP_V4_CHP_H
#define CHP_V4_CHP_H

#include "EmergencyEquipment/CHP_State_Machine.h"
#include "EmergencyEquipment/Emergency_Lights.h"
#include "Vehicle/Vehicle_State_Machine.h"
#include "Vehicle/Vehicle_Lights.h"

class CHP {
 public:

  CHP(bool *main_ww_tim, bool *hdl_ww_tim, bool *ind_ww_tim);

  bool
    *MAIN_TIM,
    *YELP_TIM,
    *HDL_TIM,
    *IND_TIM;

  short
    *YELP_CNT;

  CHP_Lights EmergencyLights;
  CHP_State_Machine EmergencyStateMachine;

  Vehicle_Lights VehicleLights;
  Vehicle_State_Machine VehicleStateMachine;

  void updateEmergencyOutput();
  void updateVehicleOutput();

};

#endif //CHP_V4_CHP_H
