#ifndef __STEERING_H
#define __STEERING_H

#include "Arduino.h"
#include "FastLED.h"

enum Direction { NORTH, NORTHEAST, EAST, SOUTHEAST, SOUTH, SOUTHWEST, WEST, NORTHWEST };

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
    void setColorAt(const uint8_t index, const struct CRGB &color);
    void setNColorAt(const uint8_t index, const uint8_t num, const struct CRGB &color);
    void fadeOutCW(uint8_t hue, uint8_t startIndex);
    void fadeOutCCW(uint8_t hue, uint8_t startIndex);
    void showDirection(enum Direction d, const CRGB &color);
};

typedef struct {
   uint32_t frame;
   uint8_t raw_color[3];
   union {
     struct {
      uint8_t vb1;
      uint8_t vb2;
      uint8_t vb3;
      uint8_t vb4;
      uint8_t vb5;
      uint8_t vb6;
      float vf1;
      float vf2;
      float vf3;
      float vf4;
     };
     uint8_t data[12];
   };
} ColorFunctionData;

void setRawColor(ColorFunctionData &cfd, uint8_t c1, uint8_t c2, uint8_t c3);
CRGB asRGB(const ColorFunctionData &cfd);
CHSV asHSV(const ColorFunctionData &cfd);

#endif
