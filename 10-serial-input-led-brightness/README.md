# Lesson 10 — Serial Input LED Brightness

This exercise was demonstrated by the tutor in the video lesson, controlling LED brightness from a number typed into the Serial Monitor.

## What the program does

**serial_input_led_brightness.ino** — Asks the user for a brightness level from 0 to 10, reads it from the Serial Monitor, converts it to a PWM value from 0 to 255, and sets the LED brightness with `analogWrite()`.

- Prompt: a `String` variable (`prompt`) holds the message "Please Input Desired Brightness (0-10)", printed with `Serial.println()` every loop.
- Waiting for input: `while (Serial.available() == 0) {}` pauses the program until the user types something.
- Reading input: `Serial.parseInt()` converts the typed text into an integer (`ui`), which `constrain()` limits to 0–10.
- Brightness mapping: `writeVal = pow(2, (8./10.) * ui) - 1` turns the 0–10 input into a PWM value from 0 to 255. Each step roughly doubles the value, so brightness looks evenly spaced to the eye.
- Output: the PWM value is printed to the Serial Monitor and written to the LED pin.

## Setup

- LED connected to GPIO 4 (`redPin`), with a current-limiting resistor to GND
- Board: ESP32 (Arduino IDE, ESP32 core 3.x so that `analogWrite()` works)
- Serial Monitor baud rate: 115200
- Serial Monitor line ending: Newline

## What I understood from this lesson

- `Serial.available()` tells you how many characters are waiting in the buffer. A `while` loop on `Serial.available() == 0` makes the program wait for the user instead of running ahead.
- `Serial.parseInt()` turns typed text into a number, so the user can control the program while it runs, with no need to re-upload code.
- The eye does not see brightness in a linear way. A linear 0–255 scale looks like it changes too fast at the low end and barely changes at the high end. The exponential formula `2^(0.8 * ui) - 1` fixes this, so input 0 gives 0 (off) and input 10 gives 255 (full brightness).
- `pow()` returns a floating-point number, and storing it in an `int` drops the decimal part.
- `constrain()` keeps the input in a safe range, so values outside 0–10 cannot push the PWM value above 255.
- Printing `writeVal` to the Serial Monitor lets me check the calculation without relying only on how the LED looks.
- Clearing leftover characters (such as the newline) from the Serial buffer stops them from being read as extra input on the next loop.

## Reference

Tutorial lesson on Controlling LED Based on User Input From Serial Monitor (Arduino R4 WiFi series, adapted to ESP32).
