# ArduinoClockTower
A replica of the Düsseldorf Rheinturm tv tower

This code is written for controlling a strip of WS2812B addressable LEDs using the FastLED library. It creates a digital clock display on the LED strip, showing the current time in hours, minutes, and seconds.
## Hardware Requirements

- WS2812B addressable LED strip
- Arduino board (compatible with the FastLED library)
- Data pin connection between Arduino and LED strip (defined as `DATA_PIN` in the code)

## Software Requirements

- FastLED library: This code relies on the FastLED library for controlling the LED strip. Make sure to install the library before uploading the code to your Arduino board.

## Installation

1. Connect the WS2812B LED strip to your Arduino board. Ensure the data pin connection is properly made and update the `DATA_PIN` constant in the code if necessary.

2. Install the FastLED library if you haven't already. You can find the library on the Arduino Library Manager or download it from the FastLED GitHub repository.

3. Open the Arduino IDE and create a new sketch.

4. Copy and paste the code into the sketch.

5. Verify the code for any errors and upload it to your Arduino board.

6. Open the Serial Monitor to view the clock display in the format: `s=0, 10s=0, 1m=0, 10m=0, 1h=0, 10h=0`. The values for seconds, tens of seconds, minutes, tens of minutes, hours, and tens of hours will be continuously updated.

7. Connect the power supply to your Arduino board and the LED strip to observe the clock display on the LEDs.

## Usage

The code operates in an infinite loop, continuously updating the time and refreshing the LED strip accordingly. The clock display starts from 00:00:00 and increments every second.

The LED strip is divided into sections to represent different units of time:

- The first `seconds` LEDs (red) indicate the current seconds value.
- The next `tens_seconds` LEDs (green) indicate the tens of seconds value.
- The next `minutes` LEDs (blue) indicate the current minutes value.
- The next `tens_minutes` LEDs (yellow) indicate the tens of minutes value.
- The next `hours` LEDs (magenta) indicate the current hours value.
- The last `tens_hours` LEDs (cyan) indicate the tens of hours value.

Ensure that the `NUM_LEDS` constant matches the number of LEDs in your strip for proper display.

## Troubleshooting

- If the LED strip does not light up, double-check the wiring connections and the `DATA_PIN` constant in the code.
- If the clock display is not working as expected, ensure that the `NUM_LEDS` constant matches the actual number of LEDs in your strip. Additionally, check for any syntax errors or logical issues in the code.
