#ifndef __STEERING_H
#define __STEERING_H

#include "Arduino.h"
#include "FastLED.h"

class SteeringWheel;

typedef void (*UpdateHandler) (SteeringWheel &t);
 
class SteeringWheel {
  private:
    uint8_t hue;
    uint8_t saturation;
    uint8_t value;
    
    CRGB* leds;
    
  public:
    SteeringWheel( void );
    void update( void );
    void clear( void ); 
    void fill(const struct CRGB &color);
    void setPixelAt(const uint8_t index, const struct CRGB &color);
    void fadeOut(uint8_t hue, uint8_t startIndex);
};


#endif
