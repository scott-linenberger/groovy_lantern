#ifndef FLICKERINGLANTERN_H
#define FLICKERINGLANTERN_H
/* bring in the Neopixel library */
#include <Adafruit_NeoPixel.h>

class FlickeringLantern {
  void begin(Adafruit_NeoPixel &_pixels);
};

#endif