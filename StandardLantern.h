#ifndef STANDARDLANTERN_H
#define STANDARDLANTERN_H
/* bring in the Neopixel library */
#include <Adafruit_NeoPixel.h>

class StandardLantern {
  Adafruit_NeoPixel *pixels;
  
  /* light levels */
  uint8_t valueLow = 75;
  uint8_t valueMed = 150;
  uint8_t valueHigh = 255;

  public:
  void begin(Adafruit_NeoPixel &_pixels);
  void low(); // low white light
  void medium(); // medium white light
  void high(); // high white light
  void classic(); // yellow light

  private:
  void setAllPixels(uint32_t color);
};

#endif