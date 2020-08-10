//
// Created by Andrew on 7/5/2020.
//

#ifndef CHP_V4_CHP_ENUMS_H
#define CHP_V4_CHP_ENUMS_H

enum class EmergencyStateEvent : char {
  ALL_OFF,
};

enum class Code1 : char {
  OFF,
  REAR_AMBER,
  FORWARD_CUTOFF,
  AMBER_ONLY
};

enum class Code2 : char {
  OFF,
  FORWARD_RED,
  FORWARD_RED_WW
};

enum class Code3 : char {
  OFF,
  CODE_3,
  CODE_3_WW,
  CODE_3_WW_AM,
  CODE_3_PK
};

enum class TrafficAdvisor : char {
  OFF,
  LEFT,
  RIGHT,
  SPLIT
};

enum class ContinuousSiren : char {
  OFF,
  WAIL,
  YELP
};

enum class IntermittentSiren : char {
  OFF,
  AIR_HORN,
  MANUAL
};

bool Active(Code1 &c);
bool Active(Code2 &c);
bool Active(Code3 &c);
bool Active(TrafficAdvisor &c);
bool Active(ContinuousSiren &c);
bool Active(IntermittentSiren &c);

#endif //CHP_V4_CHP_ENUMS_H
