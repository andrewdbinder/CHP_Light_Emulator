# CHP Lighting Emulator

This project aims to create methods for accurately emulating the emergency lighting behavior the California Highway Patrol uses on their emergency vehicles. It is designed to run on embedded platforms, such as Arduino or STM32-based platforms. The software has three main functions: acting as a state machine for the different lighting modes (and generalized vehicle features), generating outputs for light heads, and generating outputs for sounds. My project utilizing this library can be seen [here](https://abinder.dev/chp/2020/08/21/chp-2.html).

# Usage

There are two constructors which can be used to run the software in two different modes. One is useful for only keeping track of states, while the other is used for actually generating outputs.

## State Only Mode

By using the constructor with no parameters (i.e. `CHP CHP;`), all states are initialized to default "off" modes. The `CHP.StateChange()` function can be used to enable different lighting modes or vehicle modes using the function parameters listed in the [State Controls](#state-controls) section. States can be accessed using `EmergencyStateMachine` and `VehicleStateMachine` members of the main `CHP` class. This is demonstrated in [main.cpp](main.cpp).

## Full Output Mode

The other available constructor takes a number of variables. These variables should update externally to the object, as the class does not include methods for updating them (except for `*ta_map` and `*aux_map`).

```C++
CHP(bool *main_ww_tim, (tim2 & tim3)
    bool *yelp_tim, (tim7)
    bool *hdl_ww_tim, (tim4)
    bool *ind_ww_tim, (tim6)
    unsigned short *ta_map, (
    unsigned short *aux_map);
```

`bool *main_ww_tim` is the main wig-wag pattern used by most patterns. It expects an array of two `bool` values that alternate, following Whelen's SF90 pattern. I suggest roughly 350 ms between each toggle including 80 ms of off time for each toggle.

`bool *yelp_tim` is the timer used for the yelp pattern. It expects a single `bool` value, that follows Whelen's SF120 pattern. I suggest inverting the variable every 250 ms.

`bool *hdl_ww_tim` is the timer for the headlight flasher. It expects a single `bool` value. The timing will vary depending on the headlight-flasher type used (incandescent  brights or DRL flashing). For incandescent emulation, I use a toggle frequency of 245 ms. For DRL flasher emulation, I use a slightly faster frequency of 290 ms.

`bool *in_ww_tim` is the timer used to flash the indicators. It expects a single `bool` value, which should follow vehicle flasher timing of 90 flashes per minute. This is the same timing as the Whelen SF90 pattern, though I suggest using a slightly different value than 350 ms (+/- 5 ms), so that emergency patterns do not unintentionally sync with the indicators.

`unsigned short *ta_map` is the timer used for the traffic advisor patterns. It expects a value that increments by one every 100 ms for left/right patterns, or 165 ms for the split pattern. The class will automatically set the variable to be in a range it expects depending on the object state.

`unsigned short *aux_map` is a general-purpose timer used for some auxiliary patterns. Similarly to the traffic advisor timer, it expects a value that increments by one every 25 ms. It also automatically keeps the variable within range depending on the state the object is in.

Once the object has been constructed, there are three functions that should be run to update lighting outputs based on the active patterns:

```C++
CHP.updateEmergencyOutput();
CHP.updateVehicleOutput();
CHP.updateSirenOutput();
```

These functions write outputs to variables stored in the `EmergencyLights` and `VehicleLights` members of the `CHP` class. Outputs can be seen in [Emergency_Lights.h](Src/EmergencyEquipment/Emergency_Lights.h) and [Vehicle_Lights.h](Src/Vehicle/Vehicle_Lights.h). Most outputs are enumerated to have three output states: off, dim, on; though these states are different for the emergency light outputs and vehicle light outputs and can be found in their respective header file.

# State Controls

Two main methods are implemented for changing lighting states. Internally, function calls can be used to change the state of the emulator. These calls return a `char` which when input into a StateChange call will update a remote emulator with the same state. These `char` commands can be sent over a lightweight communication protocal (e.g. UART) to keep two instances of the emulator synced together.

## Emergency Lighting

### Code 1 Lights
| Description         | Function Call           | Char |
|---------------------|-------------------------|------|
| Off                 | `Code1::OFF`            | `z`  |
| Rear Amber/Blue     | `Code1::REAR_AMBER`     | `1`  |
| Rear Amber/Blue/Red | `Code1::FORWARD_CUTOFF` | `q`  |
| Rear Amber Only     | `Code1::AMBER_ONLY`     | `a`  |
| Caltrans Amber      | `Code1::CALTRANS`       | `!`  |
| PCSO Rear           | `Code1::PCSO`           | `Q`  |

### Code 2 Lights
| Description            | Function Call           | Char |
|------------------------|-------------------------|------|
| Off                    | `Code2::OFF`            | `s`  |
| Forward Red            | `Code2::FORWARD_RED`    | `2`  |
| Forward Red w/ Wig Wag | `Code2::FORWARD_RED_WW` | `w`  |

### Code 3 Lights
| Description                 | Function Call            | Char |
|-----------------------------|--------------------------|------|
| Off                         | `Code3::OFF`             | `x`  |
| Code 3                      | `Code3::CODE_3`          | `3`  |
| Code 3 w/o Wig Wag          | `Code3::CODE_3_WW`       | `e`  |
| Code 3 w/o Wig Wag or Amber | `Code3::CODE_3_WW_AM`    | `d`  |
| Code 3 w/o Park Kill        | `Code3::CODE_3_PK`       | `c`  |
| Code 3 NextGen Style        | `Code3::CODE_3_NEW_YELP` | `#`  |

### Traffic Advisor
| Description | Function Call           | Char |
|-------------|-------------------------|------|
| Off         | `TrafficAdvisor::OFF`   | `h`  |
| Left T/A    | `TrafficAdvisor::LEFT`  | `j`  |
| Right T/A   | `TrafficAdvisor::RIGHT` | `l`  |
| Split T/A   | `TrafficAdvisor::SPLIT` | `k`  |

### Continuous Siren
| Description | Function Call           | Char |
|-------------|-------------------------|------|
| Off         | `ContinuousSiren::OFF`  | `b`  |
| Siren Wail  | `ContinuousSiren::WAIL` | `n`  |
| Siren Yelp  | `ContinuousSiren::YELP` | `m`  |

### Intermittent Siren
| Description  | Function Call                 | Char |
|--------------|-------------------------------|------|
| Off          | `IntermittentSiren::OFF`      | `,`  |
| Air Horn     | `IntermittentSiren::AIR_HORN` | `.`  |
| Manual Siren | `IntermittentSiren::MANUAL`   | `/`  |

## Scene Lighting

| Description               | Function Call         | Char |
|---------------------------|-----------------------|------|
| Takedown Lights On        | `Scene::TAKEDOWN_ON`  | `7`  |
| Takedown Lights Off       | `Scene::TAKEDOWN_OFF` | `&`  |
| Driver Alley Light On     | `Scene::D_ALLEY_ON`   | `6`  |
| Driver Alley Light Off    | `Scene::D_ALLEY_OFF`  | `^`  |
| Passenger Alley Light On  | `Scene::P_ALLEY_ON`   | `8`  |
| Passenger Alley Light Off | `Scene::P_ALLEY_OFF`  | `*`  |
| Driver Spotlight On       | `Scene::D_SPOT_ON`    | `4`  |
| Driver Spotlight Off      | `Scene::D_SPOT_OFF`   | `$`  |
| Passenger Spotlight On    | `Scene::P_SPOT_ON`    | `5`  |
| Passenger Spotlight Off   | `Scene::P_SPOT_OFF`   | `%`  |

## Vehicle Functions

### Gear
| Description | Function Call   | Char |
|-------------|-----------------|------|
| Park        | `Gear::PARK`    | `p`  |
| Reverse     | `Gear::REVERSE` | `o`  |
| Drive       | `Gear::DRIVE`   | `i`  |

### Indicators
| Description       | Function Call            | Char |
|-------------------|--------------------------|------|
| Turn Signal Off   | `Indicators::OFF`        | `-`  |
| Left Turn Signal  | `Indicators::TURN_LEFT`  | `[`  |
| Right Turn Signal | `Indicators::TURN_RIGHT` | `]`  |
| Hazard Lights     | `Indicators::HAZARD`     | `=`  |

### Headlights
| Description       | Function Call      | Char |
|-------------------|--------------------|------|
| Headlights Off    | `Headlights::OFF`  | `t`  |
| Parking Lights On | `Headlights::PARK` | `y`  |
| Headlights On     | `Headlights::ON`   | `u`  |

### Brights
| Description | Function Call  | Char |
|-------------|----------------|------|
| Brights Off | `Brights::OFF` | `T`  |
| Brights On  | `Brights::ON`  | `U`  |

### Brakes
| Description      | Function Call | Char |
|------------------|---------------|------|
| Brake Lights Off | `Brakes::OFF` | `V`  |
| Brake Lights On  | `Brakes::ON`  | `v`  |

### Horn
| Description | Function Call | Char |
|-------------|---------------|------|
| Horn Off    | `Horn::OFF`   | `R`  |
| Horn On     | `Horn::ON`    | `r`  |

## General Functions
| Description   | Function Call                    | Char |
|---------------|----------------------------------|------|
| Press Horn    | `HornTap(true)`                  | `g`  |
| Release Horn  | `Horn(false)`                    | `G`  |
| L/S Off       | `EmergencyStateEvent::LS_OFF`    | `0`  |
| Scene Off     | `EmergencyStateEvent::SCENE_OFF` | `(`  |
