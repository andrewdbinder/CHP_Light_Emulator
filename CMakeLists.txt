cmake_minimum_required(VERSION 3.15)
project(CHP_v4)

set(CMAKE_CXX_STANDARD 17)

add_executable(CHP_v4 main.cpp Src/EmergencyEquipment/CHP_State_Machine.cpp Src/EmergencyEquipment/CHP_State_Machine.h Src/EmergencyEquipment/CHP_Enums.h Src/EmergencyEquipment/CHP_Enums.cpp Src/CHP.cpp Src/CHP.h Src/EmergencyEquipment/Emergency_Lights.cpp Src/EmergencyEquipment/Emergency_Lights.h Src/Vehicle/Vehicle_State_Machine.cpp Src/Vehicle/Vehicle_State_Machine.h Src/Vehicle/Vehicle_Lights.cpp Src/Vehicle/Vehicle_Lights.h Debug/CHP_Enum_cout.cpp Debug/CHP_Enum_cout.h)