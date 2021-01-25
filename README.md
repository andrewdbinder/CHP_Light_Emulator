# CHP Lighting Emulator

This project aims to create methods for accurately emulating the emergency lighting behavior the California Highway Patrol uses on their emergency vehicles. It is designed to run on embedded platforms, such as Arduino or STM32-based platforms. The software has three main functions: acting as a state machine for the different lighting modes, generating outputs for light heads, and generating outputs for sounds. My project utilizing this library can be seen [here](https://abinder.dev/chp/2020/08/21/chp-2.html).

To be continued.

# Usage


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
