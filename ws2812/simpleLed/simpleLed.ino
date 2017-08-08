
#include <Adafruit_NeoPixel.h>

#define PIN            0

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //pamietac zmienic

int delayval = 500; // delay for half a second
int brightness = 5;
void setup() {
    pinMode(2, INPUT);
    pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
    /*Serial.begin(57600);
    if (Serial.read()=='k'){
        
        Serial.println("k: started");
        blinkAll(255,255,255,1000);
        Serial.println("k: done");
    }
    else if (Serial.read()=='b'){

    }
    else{
        
    }*/

    if (digitalRead(2)==HIGH){
      stdBlink(3);
    }
    else{
    for (int i =0;i<5;i++){
      blinkAll(50,0,0,100);
    }

    for (int i =0;i<5;i++){
      blinkAll(0,50,0,100);
    }

    for (int i =0;i<5;i++){
      blinkAll(0,0,50,100);
    }  
    }
    

    

}

void colorChange(int r,int g, int b, int pix) {
    pixels.setPixelColor(pix, pixels.Color(r/brightness,g/brightness,b/brightness));
    pixels.show();
}

void  allOff(){
    for (int i=0;i<NUMPIXELS;i++){
        colorChange(0,0,0,i);
    }
}

void stdBlink(int x){
    colorChange(0,255,0, 0);
    colorChange(255,0,0, 1);
    
    for (int i=0;i<x;i++){
    colorChange(255,255,255, 2);
    delay(50);
    colorChange(0,0,0,2);
    delay(50);
    }
    delay(900);

}


void blinkAll(int r,int g, int b, int time) {
    for (int i=0;i<NUMPIXELS;i++){
        colorChange(r,g,b,i);
    }
    delay(time);
    allOff();
    delay(time);
}