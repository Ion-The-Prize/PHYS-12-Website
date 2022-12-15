#include <FastLED.h>

#define LED_PIN     8
#define NUM_LEDS    3

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);  
  leds[1] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  leds[2] = CRGB(0, 0, 0);
  FastLED.show();
  delay(500);
}
