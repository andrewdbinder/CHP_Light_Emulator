cmake_minimum_required(VERSION 3.15)
project(CHP_v4)

set(CMAKE_CXX_STANDARD 17)

add_executable(CHP_v4 main.cpp CHP_State_Machine.cpp CHP_State_Machine.h CHP_Enums.h CHP_Enums.cpp CHP.cpp CHP.h Emergency_Lights.cpp Emergency_Lights.h Vehicle_State_Machine.cpp Vehicle_State_Machine.h Vehicle_Lights.cpp Vehicle_Lights.h)