# IoT Summer School 2026

**Name:** Palle Sushanth Reddy
**Roll Number:**

## Project Description

This repository contains the coursework, sensor integration exercises, and programming assignments completed during the 2026 IoT Summer School. It tracks my progress week-by-week, starting from basic microcontroller setup in C++ to advanced IoT deployments. The repository culminates in a comprehensive final project demonstrating end-to-end hardware and software integration
## Interactive LED Blink with Potentiometer Control

**Author:** Palle Sushanth Reddy  
**Event:** IoT Summer School 2026, IIIT Bhagalpur  

## Project Overview

This project demonstrates fundamental digital output and analog input control using a microcontroller. It features an LED that blinks at a variable rate determined by the physical position of a potentiometer. Additionally, the system tracks and logs the total number of blink cycles to the Serial Monitor.

---

## Hardware Required

To build this circuit, you will need the following components:

* 1x Arduino Uno (or compatible microcontroller)
* 1x 5mm LED (Any color)
* 1x 220Ω Resistor
* 1x 10kΩ Potentiometer (Rotary)
* 1x Breadboard
* Jumper Wires

---

## Circuit Diagram Description

**1. The LED Circuit:**

* Connect the **Anode** (longer leg) of the LED to one end of the 220Ω resistor.
* Connect the other end of the 220Ω resistor to **Digital Pin 13** on the Arduino.
* Connect the **Cathode** (shorter leg) of the LED directly to a **GND** (Ground) pin on the Arduino.

**2. The Potentiometer Circuit:**

* Connect the **Left Pin** of the potentiometer to the **5V** pin on the Arduino.
* Connect the **Middle Pin** (Wiper) of the potentiometer to **Analog Pin A0** on the Arduino.
* Connect the **Right Pin** of the potentiometer to a **GND** pin on the Arduino.

---

## How to Upload Code

Follow these steps to compile and flash the code to your hardware:

1. **Connect the Hardware:** Use a USB cable to connect your Arduino to your computer.
2. **Open the IDE:** Launch the Arduino IDE and open the `led_blink.ino` file.
3. **Select the Board:** Go to `Tools` > `Board` and select **Arduino Uno** (or your specific board model).
4. **Select the Port:** Go to `Tools` > `Port` and select the COM port that your Arduino is connected to (e.g., `COM3` on Windows or `/dev/cu.usbmodem` on Mac).
5. **Upload:** Click the right-pointing arrow button (**Upload**) in the top left corner of the IDE. Wait for the "Done uploading" message at the bottom of the screen.

---

## Expected Output

Once the code is uploaded:

* The LED will immediately begin blinking.
* Turning the potentiometer knob will dynamically change the blink speed (delay ranges from 0ms to 1023ms).
* If you open the **Serial Monitor** (magnifying glass icon in the top right of the IDE) and set the baud rate to **9600**, you will see a continuous printout stating `Blink count: X`, where X increases by 1 after every full blink cycle.

---

## Troubleshooting Tips

* **LED is not lighting up:** Check the polarity of your LED. LEDs only allow current to flow in one direction. Try reversing the legs so the longer leg (anode) routes to Pin 13.
* **Upload fails with an "avrdude" error:** This usually means the IDE cannot talk to the board. Double-check that your USB cable is fully plugged in and that you have selected the correct Port under the `Tools` menu.
* **Serial Monitor displays unreadable/garbage characters:** Ensure the baud rate dropdown at the bottom right of the Serial Monitor window is set to **9600 baud** to match the `Serial.begin(9600);` command in the `setup()` function.
* **Blink speed does not change when turning the knob:** Verify the potentiometer wiring. Ensure the middle wiper pin is securely connected to `A0` and the outer pins are connected to `5V` and `GND`.
