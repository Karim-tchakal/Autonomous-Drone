# Horizon1

Autonomous drone built around a dual-ESP32 architecture, integrating onboard sensors, flight-controller communication, and autonomous navigation.

>  **Project Status:** In development

## Overview

Horizon1 is an embedded drone project designed to combine conventional flight control with a dedicated onboard autonomy system.

The system uses two ESP32-based controllers:

* **ESP32-S3 — Flight Controller**

  * Configured using Betaflight Configurator 10.10
  * Custom Betaflight firmware [Firmware](https://github.com/rtlopez/esp-fc.git) 
  * Handles the core flight-control system
  * Responsible for stabilisation, motor control, and flight modes
 
* **ESP32-S3 N16R8 — Autonomy Controller**

  * Equipped with a camera
  * Handles the autonomous navigation layer
  * Interfaces with onboard sensors
  * Currently supports manual control through a web-based interface
  * Intended to progressively take over navigation and autonomous flight tasks

## Current Features

* Dual-ESP32 architecture
* Betaflight-based flight controller
* ESP32-S3 N16R8 camera system
* Onboard sensor integration
* Wireless manual control
* Web-based control interface
* Flight-controller communication
* Initial navigation and autonomy development

## Hardware

- ESP32-S3 — Flight Controller
- ESP32-S3 N16R8 — Autonomy Controller + Camera
- MPU6500 — IMU
- BMP280 — Barometric sensor
- Motors + ESCs
See the full [Hardware Documentation](docs/hardware.md).

### Flight Controller

* ESP32-S3
* Betaflight
* Motor outputs
* Flight-control sensors

### Autonomy Controller

* ESP32-S3 N16R8
* Camera
* MPU6500
* BMP280
* Additional sensors under development

## Development Roadmap

* [x] Establish flight-controller platform
* [x] Configure Betaflight
* [x] Establish ESP32-S3 autonomy platform
* [x] Camera integration
* [x] Sensor testing
* [x] Manual web-based control
* [ ] Reliable communication between autonomy controller and flight controller
* [ ] Sensor fusion
* [ ] Autonomous navigation
* [ ] Autonomous flight
* [ ] Vision-based navigation
* [ ] Full autonomous mission system

## Documentation
# Horizon1

Autonomous drone built around a dual-ESP32 architecture, integrating onboard sensors, flight-controller communication, and autonomous navigation.

> **Project Status:** In development

## Overview

Horizon1 is an embedded drone project combining a dedicated flight controller with an onboard autonomy system.

The system uses two ESP32-based controllers:

- **ESP32-S3 — Flight Controller**
  - Betaflight-based flight control
  - Stabilisation, motor control, and flight modes
  - Betaflight Configurator 10.10
  - Custom ESP32 firmware: [esp-fc](https://github.com/rtlopez/esp-fc)

- **ESP32-S3 N16R8 — Autonomy Controller**
  - Camera
  - Sensor integration
  - Navigation and autonomy
  - Currently controlled through a web interface

## Hardware

- ESP32-S3 flight controller
- ESP32-S3 N16R8 with camera
- MPU6500
- BMP280
- Motors and ESCs


## Documentation

- [Setup guide](docs/setup.md)
- [Wiring](docs/wiring.md)
- [Wireless Communication](docs/wireless.md)
- [Tools](docs/tools.md)

## Current Development

The drone is currently operated manually through a web interface while the onboard autonomy system is being developed.

The current work focuses on:

- Flight-controller communication
- Sensor integration
- Navigation
- Camera-based perception
- Autonomous flight
## Status

Horizon1 is currently in the transition from **manual flight and control** toward **autonomous navigation**.

The immediate focus is establishing reliable communication between the autonomy controller and the Betaflight flight controller while integrating the onboard sensors and camera system.

## Team

- **[Tchakal Mohamed Karim](https://github.com/Karim-tchakal)** — Embedded Systems, Flight Control & Autonomy
- **[Chakib Ait Hadi](...)** — ...
