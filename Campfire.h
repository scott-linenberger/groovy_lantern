#ifndef CAMPFIRE_H
#define CAMPFIRE_H

/* bring in the Neopixel library */
#include <Adafruit_NeoPixel.h>

class Campfire {
    Adafruit_NeoPixel *pixels;

    public:
    void begin(Adafruit_NeoPixel &_pixels);

    private:
    
};

#endif