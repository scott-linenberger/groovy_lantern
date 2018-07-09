
#ifndef RAINBOWLANTERN_H
#define RAINBOWLANTERN_H
/* bring in the Neopixel library */
#include <Adafruit_NeoPixel.h>
#include "Ticker.h"

class RainbowLantern {
  /* neopixels */
  Adafruit_NeoPixel *pixels;

  /* position */
  int currentPosition = 0;

  /* Ticker for animation updates */
  Ticker ticker = Ticker(50);

  public:
  void begin(Adafruit_NeoPixel &_pixels);
  void run();

  private:
  void updatePosition();
};

#endif