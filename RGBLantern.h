#ifndef RGBLANTERN_H
#define RGBLANTERN_H
/* bring in the Neopixel library */
#include <Adafruit_NeoPixel.h>

class RGBLantern {
    /* neopixels */
  Adafruit_NeoPixel *pixels;

  uint32_t colorRed;
  uint32_t colorOrange;
  uint32_t colorYellow;
  uint32_t colorGreen;
  uint32_t colorBlue;
  uint32_t colorIndigo;
  uint32_t colorViolet;

  public:
  void begin(Adafruit_NeoPixel &_pixels);
  void red();
  void orange();
  void yellow();
  void green();
  void blue();
  void indigo();
  void violet();

  private:
  void setAllPixels(uint32_t color);
};

#endif