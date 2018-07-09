#include "FlickeringLantern.h"

void FlickeringLantern::begin(Adafruit_NeoPixel &_pixels) {
  /* assign the neopixel pointer */
  pixels = &_pixels;
}

void FlickeringLantern::updateColor() {
  /* update the value based on fading or growing */
  if (isFading) {
    valueGreen--;
  } else {
    valueGreen++;
  }

  /* calculate the red value */
  valueRed = valueGreen * ratioRed;

  /* check that the red value is in bounds */
  if (valueRed > 255) {
    /* value is maxed out, set fading true */
    isFading = true;
    /* recurse this method */
    updateColor();
  }

  if (valueGreen < 1) {
    /* value has bottomed out, set fading false */
    isFading = false;
    /* recurse this method */
    updateColor();
  }

  /* randomly change fade */
  int fadeChange = random(0, 2);

  if (fadeChange == 1) {
    isFading = !isFading;
  }
}

void FlickeringLantern::run() {
  /* check if a tick has passed */
  if (!ticker.isReady()) {
    return; // tick hasn't passed
  }

  /* update the colors */
  updateColor();

  /* randomize if we are randomly turning pixels off */
  int randomOff = random(0, 2);

  /* update the pixels */
  for (uint8_t i = 0; i < pixels->numPixels(); i++) {
    /* set odd pixels solid, even pixels flickering */ 
    if (i % 2 != 0) {
      pixels->setPixelColor(i, pixels->Color(255, 100, 0));
    } else {
      uint32_t currentColor = pixels->Color(valueRed, valueGreen, 0, 0);
      pixels->setPixelColor(i, currentColor);
    }
  }

  /* flicker 4 random pixels */
  for (uint8_t i = 0; i < 4; i++) {
      int flickerValue = random(0, 2);
      int randomPixel = random(0, pixels->numPixels() + 1);

      if (flickerValue == 1 && randomOff == 1) {
        pixels->setPixelColor(randomPixel, pixels->Color(0, 0, 0, 0));
      }
  }

  pixels->show();

  /* tick our ticker */
  ticker.tick();
}