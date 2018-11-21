#include "steering.h"

const uint8_t LED_STEERING__DATA_PIN =  6;
const uint8_t NUM_LEDS               = 12;
 
SteeringWheel::SteeringWheel( void ) {
  this->hue        = 0;
  this->saturation = 255;
  this->value      = 55;
  
  this->leds = malloc(NUM_LEDS * sizeof(CRGB));
  
  FastLED.addLeds<NEOPIXEL, LED_STEERING__DATA_PIN >(this->leds, NUM_LEDS);
  this->clear();
}

void SteeringWheel::update() {
  
}

void SteeringWheel::fill(const struct CRGB &color) {
  fill_solid(this->leds, NUM_LEDS,color);  
}

void SteeringWheel::clear() {
  fill_solid(this->leds, NUM_LEDS, CRGB::Black);  
}

void SteeringWheel::setPixelAt(const uint8_t index, const struct CRGB &color) {
  if (index > 11) return;
  this->leds[index] = color;
}

void SteeringWheel::fadeOut(uint8_t hue, uint8_t startIndex) {
  uint8_t value = 255;
  for (uint8_t i=0; i<12; i++) {
    this->leds[(startIndex + i) % 12] = CHSV(hue,255,value);
    value -= 21;
  }
}
