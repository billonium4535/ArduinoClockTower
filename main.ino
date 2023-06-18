#include <FastLED.h>

#define NUM_LEDS 39
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

// Variables to store the time
int seconds = 0;
int tens_seconds = 0;
int minutes = 0;
int tens_minutes = 0;
int hours = 0;
int tens_hours = 0;

void setup() {
  // Initialize the LED strip
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

  // Set the brightness of the LEDs
  FastLED.setBrightness(100);

  // Initialize the serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Increment seconds
  seconds++;
  
  // If 10 seconds have passed
  if (seconds == 10) {
    // Reset seconds
    seconds = 0;
    // Increment tens of seconds
    tens_seconds++;
  }
  
  // If 60 seconds have passed
  if (tens_seconds == 6) {
    // Reset tens of seconds
    tens_seconds = 0;
    // Increment minutes
    minutes++;
  }
  
  // If 10 minutes have passed
  if (minutes == 10) {
    // Reset minutes
    minutes = 0;
    // Increment tens of minutes
    tens_minutes++;
  }
  
  // If 60 minutes have passed
  if (tens_minutes == 6) {
    // Reset tens of minutes
    tens_minutes = 0;
    // Increment hours
    hours++;
  }
  
  // If 10 hours have passed
  if (hours == 10) {
    // Reset hours
    hours = 0;
    // Increment tens of hours
    tens_hours++;
  }
  
  // If 24 hours have passed
  if (tens_hours == 2 && hours == 4) {
    // Reset tens of hours
    tens_hours = 0;
    // Reset hours
    hours = 0;
  }
  
  // Print the current time
  Serial.print("s=");
  Serial.print(seconds);
  Serial.print(", 10s=");
  Serial.print(tens_seconds);
  Serial.print(", 1m=");
  Serial.print(minutes);
  Serial.print(", 10m=");
  Serial.print(tens_minutes);
  Serial.print(", 1h=");
  Serial.print(hours);
  Serial.print(", 10h=");
  Serial.println(tens_hours);

  // Turn off all LEDs
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
  }

  // Set LEDs based on the current time
  for (int i = 0; i < NUM_LEDS; i++) {
    if (i < seconds) {
      // Red LED for seconds
      leds[i] = CRGB(255, 0, 0);
    }
    if (i + 9 < tens_seconds + 9) {
      // Green LED for tens of seconds
      leds[i + 9] = CRGB(0, 255, 0);
    }
    if (i + 14 < minutes + 14) {
      // Blue LED for minutes
      leds[i + 14] = CRGB(0, 0, 255);
    }
    if (i + 23 < tens_minutes + 23) {
      // Yellow LED for tens of minutes
      leds[i + 23] = CRGB(255, 255, 0);
    }
    if (i + 28 < hours + 28) {
      // Purple LED for hours
      leds[i + 28] = CRGB(255, 0, 255);
    }
    if (i + 37 < tens_hours + 37) {
      // White LED for tens of hours
      leds[i + 37] = CRGB(255, 255, 255);
    }
  }

  // Update the LED strip
  FastLED.show();
  
  // Delay for 1 second
  delay(1000);
}
