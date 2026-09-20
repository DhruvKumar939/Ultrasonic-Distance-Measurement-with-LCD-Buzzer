/*
 * ---------------------------------------------------------
 * Project: Ultrasonic Distance Measurement with LCD & Buzzer
 * Microcontroller: Arduino
 * Sensor: HC-SR04 Ultrasonic Sensor
 * Display: 16x2 I2C LCD
 * ---------------------------------------------------------
 *
 * Description:
 * This project measures the distance of an object using
 * an HC-SR04 ultrasonic sensor and displays the distance
 * on a 16x2 I2C LCD.
 *
 * A buzzer is activated when an object comes within
 * 10 cm of the sensor.
 * ---------------------------------------------------------
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// -------------------------
// Pin Definitions
// -------------------------

const int buzzer = 5;
const int trig = 2;
const int echo = 3;

// Create LCD object with I2C address 0x27
// and dimensions of 16 columns × 2 rows.
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup()
{
  // Start serial communication
  Serial.begin(9600);

  // Configure ultrasonic sensor pins
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // Configure buzzer pin
  pinMode(buzzer, OUTPUT);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Display distance label
  lcd.setCursor(0, 0);
  lcd.print("Distance :");

  // Display unit
  lcd.setCursor(8, 1);
  lcd.print("cm");
}


void loop()
{
  float time;
  float distance;

  // Send a short trigger pulse to the ultrasonic sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  // Measure the duration of the echo pulse
  time = pulseIn(echo, HIGH);

  // Calculate distance in centimeters.
  // Speed of sound ≈ 0.0343 cm/µs.
  // Division by 2 accounts for the outgoing
  // and returning ultrasonic wave.
  distance = time * 0.0343 / 2;


  // -------------------------
  // Buzzer Control
  // -------------------------

  // Activate buzzer when an object is
  // detected within 10 cm.
  if (distance <= 10)
  {
    tone(buzzer, 1000);
    delay(10);
  }
  else
  {
    noTone(buzzer);
  }


  // -------------------------
  // Serial Monitor Output
  // -------------------------

  Serial.print("Distance : ");
  Serial.println(distance);


  // -------------------------
  // LCD Output
  // -------------------------

  // Clear the previous distance value
  // before displaying the new value.
  lcd.setCursor(0, 1);
  lcd.print("        ");

  lcd.setCursor(0, 1);
  lcd.print(distance);


  // Update the reading every 500 ms
  delay(500);
}