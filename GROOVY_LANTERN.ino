#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "Debouncer.h"
#include "StandardLantern.h"
#include "Campfire.h"

/* pins */
#define PIN_PIXELS 9
#define PIN_BUTTON 10
#define NUM_PIXELS 24

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

/* campfire mode vars */
#define TIMEOUT_LAST_CAMPFIRE 2500

/* pixel mode vars */
uint8_t modeCurrent = 0;
uint8_t modePrevious = 99;
uint8_t modeMax = 3;

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
}

void modeCampfire() {
  /* check if the timeout has passed */
  if ((millis() - TIMEOUT_LAST_CAMPFIRE) < TIMEOUT_LAST_CAMPFIRE) {
    return; // timeout hasn't passed
  }

  for(uint8_t i = 0; i < NUM_PIXELS; i++) {
    uint8_t randomOnOff = random(0, 2);
    if (randomOnOff == 1) {
      pixels.setPixelColor(i, pixels.Color(255, 75, 0, 0));
    } else {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0, 0));
    }
  }

  pixels.show();
}

void changeMode() {
  Serial.println("MODE CHANGE!");
  
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

    default:
      Serial.println("Mode unknown!");
      break;
  }

  /* set the current mode and last mode equal */
  modePrevious = modeCurrent;
}
