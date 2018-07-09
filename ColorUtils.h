#ifndef COLORUTILS_H
#define COLORUTILS_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class ColorUtils {

  public:
  static uint32_t wheel(byte wheelPosition, Adafruit_NeoPixel* pixels);
};

#endif