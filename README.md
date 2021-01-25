# CHP Lighting Emulator

This project aims to create methods for accurately emulating the emergency lighting behavior the California Highway Patrol uses on their emergency vehicles. It is designed to run on embedded platforms, such as Arduino or STM32-based platforms. The software has three main functions: acting as a state machine for the different lighting modes, generating outputs for light heads, and generating outputs for sounds. My project utilizing this library can be seen [here](https://abinder.dev/chp/2020/08/21/chp-2.html).

To be continued.

# Usage


## Emergency Lighting

### Code 1 Lights
| Description         | Function Call         | Char |
|---------------------|-----------------------|------|
| Off                 | Code1::OFF            | z    |
| Rear Amber/Blue     | Code1::REAR_AMBER     | 1    |
| Rear Amber/Blue/Red | Code1::FORWARD_CUTOFF | q    |
| Rear Amber Only     | Code1::AMBER_ONLY     | a    |
| Caltrans Amber      | Code1::CALTRANS       | !    |
| PCSO Rear           | Code1::PCSO           | Q    |


### Code 2 Lights
|                | Description            | Function Call         | Char |
|----------------|------------------------|-----------------------|------|
| OFF            | Off                    | Code2::OFF            | s    |
| FORWARD_RED    | Forward Red            | Code2::FORWARD_RED    | 2    |
| FORWARD_RED_WW | Forward Red w/ Wig Wag | Code2::FORWARD_RED_WW | w    |

### Code 3 Lights
|                 | Description                 | Function Call          | Char |
|-----------------|-----------------------------|------------------------|------|
| OFF             | Off                         | Code3::OFF             | x    |
| CODE_3          | Code 3                      | Code3::CODE_3          | 3    |
| CODE_3_WW       | Code 3 w/o Wig Wag          | Code3::CODE_3_WW       | e    |
| CODE_3_WW_AM    | Code 3 w/o Wig Wag or Amber | Code3::CODE_3_WW_AM    | d    |
| CODE_3_PK       | Code 3 w/o Park Kill        | Code3::CODE_3_PK       | c    |
| CODE_3_NEW_YELP | Code 3 NextGen Style        | Code3::CODE_3_NEW_YELP | #    |

### Traffic Advisor
|       | Description | Function Call         | Char |
|-------|-------------|-----------------------|------|
| OFF   | Off         | TrafficAdvisor::OFF   | h    |
| LEFT  | Left T/A    | TrafficAdvisor::LEFT  | j    |
| RIGHT | Right T/A   | TrafficAdvisor::RIGHT | l    |
| SPLIT | Split T/A   | TrafficAdvisor::SPLIT | k    |

### Continuous Siren
|      | Description | Function Call         | Char |
|------|-------------|-----------------------|------|
| OFF  | Off         | ContinuousSiren::OFF  | b    |
| WAIL | Siren Wail  | ContinuousSiren::WAIL | n    |
| YELP | Siren Yelp  | ContinuousSiren::YELP | m    |

### Intermittent Siren
|          | Description  | Function Call               | Char |
|----------|--------------|-----------------------------|------|
| OFF      | Off          | IntermittentSiren::OFF      | ,    |
| AIR_HORN | Air Horn     | IntermittentSiren::AIR_HORN | .    |
| MANUAL   | Manual Siren | IntermittentSiren::MANUAL   | /    |
