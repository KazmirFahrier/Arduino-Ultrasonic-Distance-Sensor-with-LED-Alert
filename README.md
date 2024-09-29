# Arduino Ultrasonic Distance Sensor with LED Alert

## Suggested Description:

This project utilizes an ultrasonic distance sensor (HC-SR04) connected to an Arduino to measure the distance of nearby objects and trigger an LED alert when the distance falls below a specified threshold. The system reads the distance and prints the measured values via the serial monitor for debugging or further use.

### Features:

Measures distance using an ultrasonic sensor.
Displays distance readings via the Arduino Serial Monitor.
Activates an LED when an object is closer than 12 inches.
Trigger input is controlled by a button connected to digital pin 13.

### Components Used:

Arduino Uno
HC-SR04 Ultrasonic Sensor
LED
Button/Switch
Breadboard and Jumper Wires

### How it Works:

The Arduino sends out a pulse from the ultrasonic sensor and listens for the echo.
The time taken for the echo to return is converted into a distance reading.
If the distance is less than 12 inches, the system turns on an LED connected to pin 9.
The program prints the distance readings to the serial monitor for easy debugging.

### Setup Instructions:

Wire the HC-SR04 ultrasonic sensor, LED, and button as shown in the circuit diagram.
Upload the provided code to the Arduino using the Arduino IDE.
Open the serial monitor to view distance readings.
Press the button to initiate the distance measurement, and observe the LED turning on if an object is within 12 inches.
