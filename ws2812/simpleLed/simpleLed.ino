
#include <Adafruit_NeoPixel.h>

#define outPin 6
#define motPin 4
#define gpsPin 3
#define armPin 2

unsigned long duration;

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, outPin, NEO_RGB + NEO_KHZ800); //pamietac zmienic na GRB/RGB

int delayval = 500;
int brightness = 5;
void setup() {
    pinMode(4, INPUT);
    pinMode(3, INPUT);
    pinMode(2, INPUT);
    pixels.begin(); // This initializes the NeoPixel library.
    Serial.begin(9600);
}

void loop() {

    //stdNav(3);
    if (armPin == HIGH){
        colorChange(0,255,0,2);
        Serial.print("armPin");
    }
    else {
        colorChange(0,0,0,2);
    }
//blinkAll(100,100,100,100);
/*
    duration = pulseIn(motPin, LOW,2000000);
    if (duration < 200000){
        stdNav(3);
        Serial.println(duration); //debug
    }

    else{
        

    if (motPin == HIGH){
        colorChange(255,0,0,0);
        
    }
    else {
        colorChange(0,0,0,0);
    }
    if (gpsPin == HIGH){
        colorChange(0,0,255,1);
    }
    else {
        colorChange(0,0,0,1);
    }
    if (armPin == HIGH){
        colorChange(0,255,0,2);
        Serial.print("armPin");
    }
    else {
        colorChange(0,0,0,2);
    }
    }
    */
    
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

void stdNav(int x){
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