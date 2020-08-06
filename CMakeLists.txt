cmake_minimum_required(VERSION 3.15)
project(CHP_v4)

set(CMAKE_CXX_STANDARD 17)

add_executable(CHP_v4 main.cpp EmergencyEquipment/CHP_State_Machine.cpp EmergencyEquipment/CHP_State_Machine.h EmergencyEquipment/CHP_Enums.h EmergencyEquipment/CHP_Enums.cpp CHP.cpp CHP.h EmergencyEquipment/Emergency_Lights.cpp EmergencyEquipment/Emergency_Lights.h Vehicle/Vehicle_State_Machine.cpp Vehicle/Vehicle_State_Machine.h Vehicle/Vehicle_Lights.cpp Vehicle/Vehicle_Lights.h)