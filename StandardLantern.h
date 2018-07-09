#ifndef STANDARDLANTERN_H
#define STANDARDLANTERN_H
/* bring in the Neopixel library */
#include <Adafruit_NeoPixel.h>

class StandardLantern {
  /* neopixels */
  Adafruit_NeoPixel *pixels;
  
  /* light levels */
  uint32_t colorWhiteLow;
  uint32_t colorWhiteMed;
  uint32_t colorWhiteHigh;
  uint32_t colorFlame;

  public:
  void begin(Adafruit_NeoPixel &_pixels);
  void low(); // low white light
  void medium(); // medium white light
  void high(); // high white light
  void classic(); // yellow-ish light

  private:
  void setAllPixels(uint32_t color);
};

#endif