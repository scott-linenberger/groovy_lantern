#include "StandardLantern.h"

void StandardLantern::begin(Adafruit_NeoPixel &_pixels) {
  /* assign the neopixel pointer */
  pixels = &_pixels;
}

void StandardLantern::setAllPixels(uint32_t color) {
  for (uint8_t i = 0; i < pixels->numPixels(); i++) {
    pixels->setPixelColor(i, color);
  }

  pixels->show();
}

void StandardLantern::low() {
  setAllPixels(pixels->Color(0, 0, 0, valueLow));
}

void StandardLantern::medium() {
  setAllPixels(pixels->Color(0, 0, 0, valueMed));
}

void StandardLantern::high() {
  setAllPixels(pixels->Color(0, 0, 0, valueHigh));
}

void StandardLantern::classic() {
  setAllPixels(pixels->Color(255, 75, 0, 0));
}