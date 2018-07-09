#include "StandardLantern.h"

void StandardLantern::begin(Adafruit_NeoPixel &_pixels) {
  /* assign the neopixel pointer */
  pixels = &_pixels;

  /* build colors */
  colorWhiteLow = pixels->Color(0, 0, 0, 75);
  colorWhiteMed = pixels->Color(0, 0, 0, 125);
  colorWhiteHigh = pixels->Color(0, 0, 0, 255);
  colorFlame = pixels->Color(255, 100, 0, 0);
}

void StandardLantern::setAllPixels(uint32_t color) {
  for (uint8_t i = 0; i < pixels->numPixels(); i++) {
    pixels->setPixelColor(i, color);
  }

  pixels->show();
}

void StandardLantern::low() {
  setAllPixels(colorWhiteLow);
}

void StandardLantern::medium() {
  setAllPixels(colorWhiteMed);
}

void StandardLantern::high() {
  setAllPixels(colorWhiteHigh);
}

void StandardLantern::classic() {
  setAllPixels(colorFlame);
}