#include <Adafruit_NeoPixel.h>

#define navPin  6
#define statPin 5
#define motPin  4
#define gpsPin  3
#define armPin  2
#define NAVPIXELS      3
#define STATPIXELS     12

unsigned long duration;
const long interval = 800;
unsigned long prevMillis = 0;

int ledState = LOW;

Adafruit_NeoPixel navLeds = Adafruit_NeoPixel(NAVPIXELS, navPin, NEO_RGB + NEO_KHZ800); //pamietac zmienic na GRB/RGB
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
    delay(1000);
    Serial.begin(57600);
}

void loop() {
int timerOn = 0;
/*unsigned long currMillis = millis();
if (currMillis - prevMillis >= 800){
    prevMillis = currMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(13,ledState);
}
*/
if (millis()%1000==0){Serial.println(millis());}
//digitalWrite(13,ledState);

//stdNav(3);

    for (int i = 0; i<STATPIXELS;i++){
        //statColor(255,255,255,i-1);
        for (int j = 0;j<4;j++){
            int x=0;
            if (i+j>12){x = -13;}
            statColor(255,0,0,i+j+x);
        }
        for (int j = 0;j<4;j++){
            int x=0;
            if (i+j+4>12){x = -12;}
            statColor(0,255,0,i+j+3+x);
        }
        for (int j = 0;j<4;j++){
            int x=0;
            if (i+j+8>12){x = -12;}
            statColor(0,0,255,i+j+7+x);
        }
        
        
        delay(70);
        
    }

    /*;
    if (armPin == HIGH){
        navColor(0,255,0,2);
        Serial.print("armPin");
    }
    else {
        navColor(0,0,0,2);
    }
//blinkAll(100,100,100,100);

    duration = pulseIn(motPin, LOW,2000000);
    if (duration < 200000){
        stdNav(3);
        Serial.println(duration); //debug
    }

    else{
        

    if (motPin == HIGH){
        navColor(255,0,0,0);
        
    }
    else {
        navColor(0,0,0,0);
    }
    if (gpsPin == HIGH){
        navColor(0,0,255,1);
    }
    else {
        navColor(0,0,0,1);
    }
    if (armPin == HIGH){
        navColor(0,255,0,2);
        Serial.print("armPin");
    }
    else {
        navColor(0,0,0,2);
    }
    }
    */

    
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
    
    for (int i=0;i<x;i++){
    navColor(255,255,255, 2);
    delay(50);
    navColor(0,0,0,2);
    delay(50);
    }
    delay(900);

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