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

void SteeringWheel::setColorAt(const uint8_t index, const struct CRGB &color) {
  // Testing index. If testing is invalid (> 11) nothing happens.
  if (index > 11) return;
  this->leds[index] = color;
}

void SteeringWheel::setNColorAt(const uint8_t index, const uint8_t num, const struct CRGB &color)  {
  for (uint8_t i=0; i<num; i++) {
    this->setColorAt((index+i)%12,color);  
  }
}

/**
 * Fades the color clockwise out. Starting with full hsv value at the
 * given index with the given hue. Then fading out from led to led by
 * decreasing the hsv value.
 */
void SteeringWheel::fadeOutCW(uint8_t hue, uint8_t startIndex) {
  uint8_t value = 255;
  for (uint8_t i=0; i<12; i++) {
    this->leds[(startIndex + i) % 12] = CHSV(hue,255,value);
    value -= 21;
  }
}

/**
 * Fades the color counterclockwise out. Starting with full hsv value 
 * at the given index with the given hue. Then fading out from led to 
 * led by decreasing the hsv value.
 */
void SteeringWheel::fadeOutCCW(uint8_t hue, uint8_t startIndex) {
  uint8_t value = 255;
  for (uint8_t i=0; i<12; i++) {
    this->leds[(startIndex + 12 - i) % 12] = CHSV(hue,255,value);
    value -= 21;
  }
}

void SteeringWheel::showDirection(enum Direction d, const CRGB &color) {
  switch (d) {
    case NORTH : 
      this->setNColorAt(10,4,color);
      break;
    case NORTHEAST : 
      this->setNColorAt(0,4,color);
      break;
    case EAST : 
      this->setNColorAt(2,4,color);
      break;
    case SOUTHEAST : 
      this->setNColorAt(4,4,color);
      break;
    case SOUTH : 
      this->setNColorAt(6,4,color);
      break;
    case SOUTHWEST : 
      this->setNColorAt(8,4,color);
      break;
    case WEST : 
      this->setNColorAt(10,4,color);
      break;
    case NORTHWEST : 
      this->setNColorAt(10,4,color);
      break;
  }
}


CRGB asRGB(const ColorFunctionData &cfd) {
  return CRGB(cfd.raw_color[0],cfd.raw_color[1],cfd.raw_color[2]);   
}

CHSV asHSV(const ColorFunctionData &cfd) {
  return CHSV(cfd.raw_color[0],cfd.raw_color[1],cfd.raw_color[2]);   
}

void setRawColor(ColorFunctionData &cfd, uint8_t c1, uint8_t c2, uint8_t c3) {
  cfd.raw_color[0] = c1;
  cfd.raw_color[1] = c2;
  cfd.raw_color[2] = c3;
}
