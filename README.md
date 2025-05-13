# Voice_Controlled_Car


**Project Overview**:
This project demonstrates a **Voice Controlled Car** using **Arduino** and a **Bluetooth module (HC-05)**. The car is controlled remotely through **voice commands** sent from a mobile app developed by me using **MIT App Inventor**. The Bluetooth module (HC-05) receives these voice commands and communicates with the Arduino, which controls the movement of the car via the **L293D motor shield**.

## Components Required:
### <h4>Components required in this module:</h4>
<ol>
  <li><p>Arduino (Arduino Uno)</p></li>
  <li><p>Motor Shield L293D</p></li>
  <li><p>Chassis Set</p></li>
  <li><p>Bluetooth Module (HC-05)</p></li>
  <li><p>Jumper Wires</p></li>
  <li><p>Double-Sided Tape</p></li>
  <li><p>3 x 9V Batteries or a Voltage Source</p></li>
  <li><p>PC</p></li>
  <li><p>Arduino Cable</p></li>
</ol>



**Figure 1**: The system setup with the Arduino, motor shield, Bluetooth module, and chassis.

## Working Principle:
The car is controlled by **voice commands** sent from a **mobile app** developed using **MIT App Inventor**. The app captures voice commands (e.g., "forward", "backward", "left", "right") and sends them to the **HC-05 Bluetooth module**. The Bluetooth module transmits these commands to the Arduino, which processes them and drives the motors accordingly using the **L293D motor shield**.

### Features:
- **Voice Control**: Control the car’s movement using voice commands.
- **Bluetooth Communication**: The mobile app communicates with the car via Bluetooth.
- **Arduino-based Motor Control**: The **L293D motor shield** is used to control the motors, enabling the car to move forward, backward, and turn left or right.

## MIT App Inventor:
The mobile app used to control the car was developed by me using **MIT App Inventor**. The app incorporates **voice recognition** to capture voice commands and sends the corresponding Bluetooth signals to the Arduino. It includes buttons for voice commands like **"Forward"**, **"Backward"**, **"Left"**, and **"Right"**.

### How I Built the Mobile App:
1. **MIT App Inventor**: Go to [MIT App Inventor](https://appinventor.mit.edu/) and create a new project.
2. **App Design**: The app was designed with a **speech-to-text** component to process the voice commands and control the car.
3. **Bluetooth Setup**: I configured Bluetooth communication in the app to connect to the **HC-05 Bluetooth module**.
4. **Block Editor**: The block editor was used to send the correct Bluetooth signals corresponding to the voice commands ("f" for forward, "b" for backward, etc.).

## Code Explanation:
The Arduino code listens for Bluetooth commands and drives the motors based on the received signals. The mobile app processes the voice input and sends the corresponding commands through Bluetooth.

```cpp
// Arduino code for controlling the voice-controlled car
// Code for controlling the car with Bluetooth commands (forward, backward, left, right, stop)

