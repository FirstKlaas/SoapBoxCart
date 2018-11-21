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

void setup() {

  /**
   * Initialize FastLED for the NeoPixel ring
   */
  FastLED.show();
}

void loop() {
  wheel.fadeOut(224,idx++);  
  FastLED.show();
  delay(60);  
  idx %= 12;
}
