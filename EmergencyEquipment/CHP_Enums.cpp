//
// Created by Andrew on 7/5/2020.
//
#include <iostream>
#include "CHP_Enums.h"

std::ostream& operator<<(std::ostream &os, const Code1 &c) {
  switch (c) {
    case Code1::OFF: os << "OFF"; break;
    case Code1::REAR_AMBER: os << "REAR_AMBER"; break;
    case Code1::FORWARD_CUTOFF: os << "FORWARD_CUTOFF"; break;
    case Code1::AMBER_ONLY: os << "AMBER_ONLY"; break;
  }
  return os;
}

std::ostream& operator<<(std::ostream &os, const Code2 &c) {
  switch (c) {
    case Code2::OFF: os << "OFF"; break;
    case Code2::FORWARD_RED: os << "F-RED"; break;
    case Code2::FORWARD_RED_WW: os << "F-RED+WW"; break;
  }
  return os;
}

std::ostream& operator<<(std::ostream &os, const Code3 &c) {
  switch (c) {
    case Code3::OFF: os << "OFF"; break;
    case Code3::CODE_3: os << "CODE 3"; break;
    case Code3::CODE_3_WW: os << "CODE 3-WW"; break;
    case Code3::CODE_3_WW_AM: os << "CODE 3-WW&AM"; break;
    case Code3::CODE_3_PK: os << "CODE 3-PK"; break;
  }
  return os;
}

std::ostream& operator<<(std::ostream &os, const TrafficAdvisor &c) {
  switch (c) {
    case TrafficAdvisor::OFF: os << "OFF"; break;
    case TrafficAdvisor::LEFT : os << "LEFT"; break;
    case TrafficAdvisor::RIGHT: os << "RIGHT"; break;
    case TrafficAdvisor::SPLIT: os << "SPLIT"; break;
  }
  return os;
}

std::ostream& operator<<(std::ostream &os, const ContinuousSiren &c)  {
  switch (c) {
    case ContinuousSiren::OFF: os << "OFF"; break;
    case ContinuousSiren::WAIL : os << "WAIL"; break;
    case ContinuousSiren::YELP: os << "YELP"; break;
  }
  return os;
}

std::ostream& operator<<(std::ostream &os, const IntermittentSiren &c)  {
  switch (c) {
    case IntermittentSiren::OFF: os << "OFF"; break;
    case IntermittentSiren::AIR_HORN: os << "AIR_HORN"; break;
    case IntermittentSiren::MANUAL: os << "MANUAL"; break;
  }
  return os;
}

bool Active(Code1 &c) {
  return c != Code1::OFF;
}

bool Active(Code2 &c) {
  return c != Code2::OFF;
}

bool Active(Code3 &c) {
  return c != Code3::OFF;
}

bool Active(TrafficAdvisor &c) {
  return c != TrafficAdvisor::OFF;
}

bool Active(ContinuousSiren &c) {
  return c != ContinuousSiren::OFF;
}

bool Active(IntermittentSiren &c) {
  return c != IntermittentSiren::OFF;
}