#include "RGBLantern.h"

void RGBLantern::setAllPixels(uint32_t color) {
  for (uint8_t i = 0; i < pixels->numPixels(); i++) {
    pixels->setPixelColor(i, color);
  }

  pixels->show();
}

void RGBLantern::begin(Adafruit_NeoPixel &_pixels) {
  /* assign the neopixel pointer */
  pixels = &_pixels;

  /* build colors */
  colorRed = pixels->Color(255, 0, 0, 0);
  colorOrange = pixels->Color(255, 50, 0, 0);
  colorYellow = pixels->Color(255, 150, 0, 0);
  colorGreen = pixels->Color(0, 255, 0, 0);
  colorBlue = pixels->Color(0, 0, 255, 0);
  colorIndigo = pixels->Color(75, 0, 255, 0);
  colorViolet = pixels->Color(255, 0, 255, 0);
}
 
void RGBLantern::red() {
  setAllPixels(colorRed);
}

void RGBLantern::orange() {
  setAllPixels(colorOrange);
}

void RGBLantern::yellow() {
  setAllPixels(colorYellow);
}

void RGBLantern::green() {
  setAllPixels(colorGreen);
}

void RGBLantern::blue() {
  setAllPixels(colorBlue);
}

void RGBLantern::indigo() {
  setAllPixels(colorIndigo);
}

void RGBLantern::violet() {
  setAllPixels(colorViolet);
}