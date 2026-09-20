# Ultrasonic Distance Measurement with LCD and Buzzer

An Arduino-based distance measurement system using an **HC-SR04 ultrasonic sensor**, **16x2 I2C LCD**, and **buzzer**. The system measures the distance of nearby objects, displays the reading on the LCD, and activates the buzzer when an object is detected within 10 cm.

## Features

* Real-time distance measurement
* Distance displayed on a 16x2 I2C LCD
* Serial Monitor output
* Buzzer alert for objects within 10 cm
* HC-SR04 ultrasonic sensor

## Components Required

* Arduino
* HC-SR04 Ultrasonic Sensor
* 16x2 I2C LCD
* Buzzer
* Jumper wires
* Breadboard

## Software Used

* Arduino IDE
* LiquidCrystal_I2C Library

## Pin Configuration

| Arduino Pin | Component    |
| ----------- | ------------ |
| D2          | HC-SR04 Trig |
| D3          | HC-SR04 Echo |
| D5          | Buzzer       |

The LCD communicates with the Arduino through the I2C interface.

## How It Works

The HC-SR04 sensor sends an ultrasonic pulse through its trigger pin. When the pulse reflects from an object, the echo pin receives the returning signal.

The Arduino measures the duration of the echo pulse and calculates the distance using the speed of sound.

The calculated distance is displayed on the LCD and Serial Monitor.

If the measured distance is **10 cm or less**, the buzzer is activated as a proximity alert.

## Project Structure


Ultrasonic-Distance-LCD-Buzzer/
│
├── ultrasonic_lcd_buzzer.ino
├── README.md
│
└── images/
    ├── project.jpg



## Setup

### 1. Install Arduino IDE

Install the Arduino IDE and select the appropriate Arduino board.

### 2. Install the LCD Library

Install the `LiquidCrystal_I2C` library through the Arduino IDE Library Manager.

### 3. Connect the Components

Connect the HC-SR04, buzzer, and I2C LCD according to the pin configuration.

### 4. Upload the Code

Open `ultrasonic_lcd_buzzer.ino` in Arduino IDE and upload it to the Arduino.

### 5. View the Output

The measured distance will be displayed on the LCD and Serial Monitor.

The buzzer will activate when an object comes within 10 cm.

## Project Images

Recommended images to add:

* Complete circuit
* HC-SR04 and Arduino wiring
* LCD displaying distance
* Buzzer alert condition

## Future Improvements

* Add adjustable distance threshold
* Add multiple alert levels
* Add LED indicators
* Improve LCD display formatting
* Add data logging
* Add an enclosure for the circuit

## What I Learned

This project helped me understand:

* Ultrasonic distance measurement
* HC-SR04 sensor interfacing
* I2C communication
* LCD interfacing
* Buzzer control
* `pulseIn()` function
* Serial communication
* Basic sensor-based automation

## Author

**Dhruv Kumar**

ECE Student
Dayanand Sagar College of Engineering, Bangalore

