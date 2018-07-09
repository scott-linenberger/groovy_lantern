#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "Debouncer.h"
#include "StandardLantern.h"
#include "FlickeringLantern.h"
#include "RGBLantern.h"
#include "RainbowLantern.h"

/* pins */
#define PIN_PIXELS 9
#define PIN_BUTTON 10
#define NUM_PIXELS 24

/* mode vars */
uint8_t modeCurrent = 0;
uint8_t modePrevious = 99;
uint8_t modeMax = 12;

/* NeoPixels */
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN_PIXELS, NEO_GRBW + NEO_KHZ800);

/* time in ms that must pass between presses */
const int TIMEOUT_DEBOUNCE = 250;
/* time in ms the button must be depressed */
const int TIMEOUT_PRESS = 50;

/* Debouncer */
Debouncer button = Debouncer(PIN_BUTTON, TIMEOUT_DEBOUNCE, TIMEOUT_PRESS);

/* Lantern controls */
StandardLantern lantern = StandardLantern();
FlickeringLantern lanternFlickering = FlickeringLantern();
RGBLantern lanternRgb = RGBLantern();
RainbowLantern lanternRainbow = RainbowLantern();

/* campfire mode vars */
#define TIMEOUT_LAST_CAMPFIRE 2500

void setup() {
  /* start serial */
  Serial.begin(9600);

  Serial.println("Groovy Lantern Started!");

  /* configure the button */
  pinMode(PIN_BUTTON, INPUT);

  /* start the pixels */
  pixels.begin();
  pixels.clear();
  pixels.show();

  /* start the Lantern */
  lantern.begin(pixels);
  lanternFlickering.begin(pixels);
  lanternRgb.begin(pixels);
  lanternRainbow.begin(pixels);
}

void changeMode() {
  /* increment the mode */
  modeCurrent++;

  /* roll the mode back to beginning if necessary */
  if (modeCurrent > modeMax) {
    modeCurrent = 0;
  }
}

void loop() {
  /* listen for button presses */
  if (button.isPressed()) {
    changeMode();
  }

  /* execute animation mode */
    switch(modeCurrent) {
    case 0:
      lantern.low();
      break;

    case 1:
      lantern.medium();
      break;

    case 2:
      lantern.high();
      break;

    case 3:
      lantern.classic();
      break;

    case 4:
      lanternFlickering.run();
      break;

    case 5:
      lanternRainbow.run();
      break;

    case 6:
      lanternRgb.red();
      break;

    case 7:
      lanternRgb.orange();
      break;

    case 8:
      lanternRgb.yellow();
      break;

    case 9:
      lanternRgb.green();
      break;

    case 10:
      lanternRgb.blue();
      break;

    case 11: 
      lanternRgb.indigo();
      break;

    case 12:
      lanternRgb.violet();
      break;

    default:
      /* uknown mode, set to 0 */
      modeCurrent = 0;
      break;
  }

  /* set the current mode and last mode equal */
  modePrevious = modeCurrent;
}
