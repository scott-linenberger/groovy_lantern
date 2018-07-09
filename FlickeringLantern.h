#ifndef FLICKERINGLANTERN_H
#define FLICKERINGLANTERN_H
/* bring in the Neopixel library */
#include <Adafruit_NeoPixel.h>
#include "Ticker.h"

class FlickeringLantern {
  /* neopixels */
  Adafruit_NeoPixel *pixels;

  /* Ticker for animation updates */
  Ticker ticker = Ticker(250);

  /* determines if color is fading or growing */
  boolean isFading = false;

  float valueGreen = 1;
  float valueRed = 0;
  float ratioRed = 2.5;

  public:
  void begin(Adafruit_NeoPixel &_pixels);
  void run();

  private: 
  void updateColor();
};

#endif