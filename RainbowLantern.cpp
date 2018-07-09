#include "RainbowLantern.h"
#include "ColorUtils.h"

void RainbowLantern::begin(Adafruit_NeoPixel &_pixels) {
  /* assign the neopixel pointer */
  pixels = &_pixels;
}

void RainbowLantern::updatePosition() {
  currentPosition+= 10;

  /* reset the current position if needed */
  if (currentPosition > 255) {
    currentPosition = 0;
    return;
  }
}

void RainbowLantern::run() {
  /* check if a tick has passed */
  if (!ticker.isReady()) {
    return; // tick hasn't passed
  }

  for (uint8_t i = 0; i < pixels->numPixels(); i++) {
    /* increment the color wheel position */
    updatePosition();
    /* get the color */
    uint32_t currentColor = ColorUtils::wheel(currentPosition, pixels);
    /* set it on the pixel */
    pixels->setPixelColor(i, currentColor);
  }
  pixels->show();

  ticker.tick();
}