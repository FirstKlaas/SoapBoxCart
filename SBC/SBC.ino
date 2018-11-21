/**********************************************************
 * This is the sketch that controlles the sensors and leds
 * of our SoapBoxCart.
 * 
 * Author : Klaas Nebuhr
 * Started: 21.11.2018
 **********************************************************/
#include "FastLED.h"

/***
 * Neo Pixel Ring
 */
const int  LED_DATA_PIN     = 6;
const int  NUM_LEDS         = 12;
CRGB leds[NUM_LEDS];

uint8_t hue_start = 0;

void setup() {

  /**
   * Initialize FastLED for the NeoPixel ring
   */
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  fill_solid(leds,NUM_LEDS,CRGB::Black);
  FastLED.show();

  
}

void loop() {
  for (uint8_t i = 0; i<NUM_LEDS; i++) {
    leds[i] = CHSV(hue_start + (i*20),255,155);
  }
  hue_start += 5;
  FastLED.show();
  delay(10);  
}
