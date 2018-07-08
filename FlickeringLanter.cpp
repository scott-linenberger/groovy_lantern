#include "FlickeringLantern.h"

void FlickeringLantern::begin(Adafruit_NeoPixel &_pixels) {
  /* assign the neopixel pointer */
  pixels = &_pixels;
}