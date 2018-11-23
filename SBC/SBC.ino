/**********************************************************
 * This is the sketch that controlles the sensors and leds
 * of our SoapBoxCart.
 * 
 * Author : Klaas Nebuhr
 * Started: 21.11.2018
 **********************************************************/
#include "FastLED.h"
#include "steering.h"

/***
 * Neo Pixel Ring for the steering wheel
 */
SteeringWheel wheel = SteeringWheel();
uint8_t idx = 0;
ColorFunctionData colorFunctionData;

void setup() {

  /**
   * Initialize FastLED for the NeoPixel ring
   */
  set_max_power_in_volts_and_milliamps(5, 500);
  FastLED.show();
  colorFunctionData.frame = 0;
  setRawColor(colorFunctionData, 30, 255,155);
}

void updateRainbow(ColorFunctionData &data) {
  wheel.fill(asHSV(data));
  data.raw_color[0]++;
}

void updateFadeOut(ColorFunctionData &data) {
  wheel.fill(asHSV(data));
  data.raw_color[0]++;
}

void fillRandomHue(ColorFunctionData &data) {
  for (uint8_t i=0; i<12; i++) {
    wheel.setColorAt(i, CHSV(random(256),255,255));
  }  
}

void circlePixel(ColorFunctionData &data) {
  wheel.clear();
  wheel.setColorAt(data.vb1, asHSV(data));
  data.vb1 += 1;
  data.vb1 %= 12;
}

void loop() {
  colorFunctionData.frame++;
  //updateRainbow(colorFunctionData);
  //wheel.fadeOutCW(40,idx++);  
  //idx %= 12;
  //fillRandomHue(colorFunctionData);
  circlePixel(colorFunctionData);
  FastLED.show();
  
  delay(400);  
}
