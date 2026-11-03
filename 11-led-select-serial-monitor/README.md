# Lesson 11 — Selecting an LED Colour from the Serial Monitor (Homework)

This was the homework exercise after the lesson on user input from the Serial Monitor. I wrote the solution myself, using String input and if statements to choose which LED turns on.

## What the code does

Asks the user to type a colour (red, green or yellow) in the Serial Monitor, reads the text into a String variable with Serial.readString(), and converts it to lowercase with toLowerCase(). It then turns on the LED that matches the colour and turns the other two LEDs off, and prints a message such as "Your selected led is Red".

## Setup

- Red LED on GPIO 2, green LED on GPIO 4, yellow LED on GPIO 5, each with a current-limiting resistor to GND
- Board: ESP32 (Arduino IDE)
- Serial Monitor baud rate: 115200
- Serial Monitor line ending: No line ending (otherwise the extra newline character can stop the colour from matching)

## What I understood from this exercise

- Serial.readString() reads typed text into a String variable, unlike Serial.parseInt(), which reads numbers.
- toLowerCase() makes the input case-insensitive, so "Red", "RED" and "red" all work.
- Comparing a String with == inside an if statement lets the program decide what to do based on what the user types.
- Each if block turns on one LED and turns the other two off, so only one LED is on at a time.
- The while(Serial.available()==0) loop makes the program wait until the user types something before continuing.

## Reference

Homework from the tutorial lesson on Controlling LED Based on User Input From Serial Monitor (Arduino R4 WiFi series, adapted to ESP32).
