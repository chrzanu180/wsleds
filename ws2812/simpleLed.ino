
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
    colorChange(pixels.Color(255,0,0),0);
    colorChange(pixels.Color(0,255,0),1);
    colorChange(pixels.Color(0,0,255),2);
    delay(1000);
    colorChange(pixels.Color(255,0,0),2);
    colorChange(pixels.Color(0,255,0),0);
    colorChange(pixels.Color(0,0,255),1);
    delay(1000);
    colorChange(pixels.Color(255,255,255),0);
    colorChange(pixels.Color(255,255,255),1);
    colorChange(pixels.Color(255,255,255),2);
    delay(1000);

}

void colorChange(uint32_t c, int pix) {
    pixels.setPixelColor(pix, c);
    pixels.show();
}
