//
// Created by Andrew on 8/9/2020.
//

#ifndef CHP_V4_CHP_ENUM_COUT_H
#define CHP_V4_CHP_ENUM_COUT_H

#include <iostream>
#include "../Src/EmergencyEquipment/CHP_Enums.h"

std::ostream& operator<<(std::ostream &os, const Code1 &c);
std::ostream& operator<<(std::ostream &os, const Code2 &c);
std::ostream& operator<<(std::ostream &os, const Code3 &c);
std::ostream& operator<<(std::ostream &os, const TrafficAdvisor &c);
std::ostream& operator<<(std::ostream &os, const ContinuousSiren &c);
std::ostream& operator<<(std::ostream &os, const IntermittentSiren &c);

#endif //CHP_V4_CHP_ENUM_COUT_H
