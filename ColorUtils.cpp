#include "ColorUtils.h"

  static uint32_t ColorUtils::wheel(byte wheelPosition, Adafruit_NeoPixel* pixels) {
    wheelPosition = 255 - wheelPosition;

    if(wheelPosition < 85) {
      return pixels->Color(255 - wheelPosition * 3, 0, wheelPosition * 3);
    }

    if(wheelPosition < 170) {
      wheelPosition -= 85;
      return pixels->Color(0, wheelPosition * 3, 255 - wheelPosition * 3);
    }

    wheelPosition -= 170;
    return pixels->Color(wheelPosition * 3, 255 - wheelPosition * 3, 0);
  }