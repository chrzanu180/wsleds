#include <Adafruit_NeoPixel.h>

#define navPin  0
#define statPin 1
#define motPin  4
#define gpsPin  3
#define armPin  2
#define NAVPIXELS      3
#define STATPIXELS     12
int counter =0;
unsigned long tmr0;

int ledState = LOW;

Adafruit_NeoPixel  navLeds = Adafruit_NeoPixel(NAVPIXELS, navPin, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel statLeds = Adafruit_NeoPixel(STATPIXELS, statPin, NEO_GRB + NEO_KHZ800);

//int delayval = 500;
int brightness = 1; 
void setup() {
    pinMode(4, INPUT);
    pinMode(3, INPUT);
    pinMode(2, INPUT);
    navLeds.begin();
    statLeds.begin();
    statColor(255,255,255,0);
    delay(100);
    Serial.begin(57600);
}

void loop() {
stdNav(3);
//statRing();

}
void statRing(){
for (int i = 0; i<STATPIXELS;i++){
    if (counter%100==0){
        for (int j = 0;j<4;j++){
            int x=0;
            if (i+j>12){x = -13;}
            statColor(180,0,100,i+j+x);
        }
        for (int j = 0;j<4;j++){
            int x=0;
            if (i+j+4>12){x = -12;}
            statColor(100,180,0,i+j+3+x);
        }
        for (int j = 0;j<4;j++){
            int x=0;
            if (i+j+8>12){x = -12;}
            statColor(0,100,180,i+j+7+x);
        }
    }
    Serial.println(counter);     
    }
}

void navColor(int r,int g, int b, int pix) {
   navLeds.setPixelColor(pix,navLeds.Color(r/brightness,g/brightness,b/brightness));
   navLeds.show();
}
void statColor(int r,int g, int b, int pix) {
   statLeds.setPixelColor(pix,statLeds.Color(r/brightness,g/brightness,b/brightness));
   statLeds.show();
}

void  allOff(){
    for (int i=0;i<NAVPIXELS;i++){
        navColor(0,0,0,i);
    }
    for (int i=0;i<STATPIXELS;i++){
        statColor(0,0,0,i);
    }
}

void stdNav(int x){
navColor(0,255,0, 0);
navColor(255,0,0, 1);

//if(counter%200==0){
    
    for (int i=0;i<x;i++){
        navColor(255,255,255, 2);
        delay(50);
        navColor(0,0,0,2);
        delay(50);
        }
        delay(900);
    //}
}


void blinkAll(int r,int g, int b, int time) {
    for (int i=0;i<NAVPIXELS;i++){
        navColor(r,g,b,i);
    }
    for (int i=0;i<STATPIXELS;i++){
        statColor(r,g,b,i);
    }
    delay(time);
    allOff();
    delay(time);
}
