# SCARAB Robot Source Code

![SCARAB Hexapod Robot](https://i.postimg.cc/1XtkvYSs/Scarab-Skin.png)

## Introduction

Welcome to the SCARAB Hexapod Robot Control Software repository. This repository contains the Arduino sketch for controlling SCARAB, a hexapod robot designed for various remote-controlled movements and actions. SCARAB features a hexapod locomotion system and a servo-driven mandible.

## About SCARAB

SCARAB is a remote-controlled hexapod robot equipped with the following components:

- **Legs**:
  - Left Coxa, Left Femur, and Left Tibia (LC, LF, LT)
  - Right Coxa, Right Femur, and Right Tibia (RC, RF, RT)

- **Mandible**:
  - A servo motor controls the mandible for gripping and interaction.

![App Screenshot](https://i.postimg.cc/5yRZTq9v/Connection-Layout.png)

Connection layout of SCARAB

## Features

- **Bluetooth Control**: SCARAB can be controlled remotely via a Bluetooth connection, enabling easy and intuitive operation.

- **Multiple Modes**: The robot supports various modes of operation, including:
  - Forward Movement
  - Backward Movement
  - Left and Right Movement
  - Rotational Movement
  - Customizable Delay Control

## Getting Started

To use this control software with your SCARAB hexapod robot, follow these steps:

1. **Hardware Setup**: Ensure that you have connected the servo motors and Bluetooth module to your Arduino board as per the provided pin mappings.

2. **Arduino IDE**: Use the Arduino IDE to upload this sketch to your Arduino board.

3. **Bluetooth Pairing**: Pair your Bluetooth-enabled device (e.g., smartphone, tablet) with SCARAB's Bluetooth module.

4. **Control SCARAB**: Send commands from your Bluetooth device to SCARAB to initiate various movements and actions.

## Usage

- Modify the code as needed to customize SCARAB's behavior, servo angles, and control logic.

- Experiment with different delay values to adjust the speed of SCARAB's movements.

## Contributions

Contributions to this project are welcome. If you have any improvements, bug fixes, or new features to suggest, please feel free to submit a pull request.



---

**Note:** This code was written with the Arduino Mega 2560 and Giga microcontrollers in mind, with the IO pins numbering 54.

For more information, please contact the engineer, Michael Chukwukere, on [LinkedIn](https://www.linkedin.com/in/chxxvo) or [Behance](https://www.behance.net/chxxvo)



## Screenshots


![App Screenshot](https://i.postimg.cc/FFC5YmbR/Circuit-Layout.png)

Complete Circuit Layout of SCARAB

