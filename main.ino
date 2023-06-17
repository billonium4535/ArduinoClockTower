#include <FastLED.h>

#define NUM_LEDS 39
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

int seconds = 0;
int tens_seconds = 0;
int minutes = 0;
int tens_minutes = 0;
int hours = 0;
int tens_hours = 0;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
  Serial.begin(9600);
}

void loop() {
  seconds++;
  
  if (seconds == 10) {
    seconds = 0;
    tens_seconds++;
  }
  
  if (tens_seconds == 6) {
    tens_seconds = 0;
    minutes++;
  }
  
  if (minutes == 10) {
    minutes = 0;
    tens_minutes++;
  }
  
  if (tens_minutes == 6) {
    tens_minutes = 0;
    hours++;
  }
  
  if (hours == 10) {
    hours = 0;
    tens_hours++;
  }
  
  if (tens_hours == 2 && hours == 4) {
    tens_hours = 0;
    hours = 0;
  }
  
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

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
  }

  for (int i = 0; i < NUM_LEDS; i++) {
    if (i < seconds) {
      leds[i] = CRGB(255, 0, 0);
    }
    if (i + 9 < tens_seconds + 9) {
      leds[i + 9] = CRGB(0, 255, 0);
    }
    if (i + 14 < minutes + 14) {
      leds[i + 14] = CRGB(0, 0, 255);
    }
    if (i + 23 < tens_minutes + 23) {
      leds[i + 23] = CRGB(255, 255, 0);
    }
    if (i + 28 < hours + 28) {
      leds[i + 28] = CRGB(255, 0, 255);
    }
    if (i + 37 < tens_hours + 37) {
      leds[i + 37] = CRGB(0, 255, 255);
    }
  }

  FastLED.show();
  
  delay(1000);
}
