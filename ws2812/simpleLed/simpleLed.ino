
#include <Adafruit_NeoPixel.h>

#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
    blinkAll(10,35,200,1000);

}

void colorChange(uint32_t c, int pix) {
    pixels.setPixelColor(pix, c);
    pixels.show();
}

void blinkAll(int r,int g, int b, int time) {
    for (int i=0;i<NUMPIXELS;i++){
        colorChange(pixels.Color(r,g,b),i);
    }
    delay(time);
    for (int i=0;i<NUMPIXELS;i++){
        colorChange(pixels.Color(0,0,0),i);
    }
    delay(time);
}