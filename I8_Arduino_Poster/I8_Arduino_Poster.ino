#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 81

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
// #define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  Serial.begin(57600);
  Serial.println("resetting");
  LEDS.addLeds<WS2812B,DATA_PIN,RGB>(leds,NUM_LEDS);
  LEDS.setBrightness(84);
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(100); } }

void colorful_loop() { 
  static uint8_t hue = 0;
  // Serial.print("x");
  // First slide the led in one direction
  for(int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    //Serial.println(i);
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(20);
  }
}
void yellowloop() { 
  static uint16_t hue = 0;
  // Serial.print("x");
  // First slide the led in one direction
  for(int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    //Serial.println(i);
    leds[i] = CRGB::Yellow;
    // Show the leds
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(20);
  }
}
void loop() { 
  static uint8_t hue = 0;
  // Serial.print("x");
  // First slide the led in one direction
  for(int i = 0; i < NUM_LEDS; i+=5) {
    // Set the i'th led to red 
    //Serial.println(i);
    //First number is color, and second number is the brightness
    leds[i++] = CHSV(64, 255, 255);
    leds[i++] = CHSV(64, 255, 255);
    leds[i++] = CHSV(64, 255, 255);
    i += 5;
    leds[i++] = CHSV(64, 255, 255);
    leds[i++] = CHSV(64, 255, 255);
    leds[i++] = CHSV(64, 255, 255);
    // Show the leds
    i += 5;
    leds[i++] = CHSV(64, 255, 255);
    leds[i++] = CHSV(64, 255, 255);
    leds[i++] = CHSV(64, 255, 255);
    i += 5;
    leds[i++] = CHSV(64, 255, 255);
    leds[i++] = CHSV(64, 255, 255);
    leds[i++] = CHSV(64, 255, 255);
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(500);
  }
}


/*
  Local Variables:
  mode: c++
  c-basic-offset: 4
  indent-tabs-mode: nil
  End:
*/