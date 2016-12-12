#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
double startTime;
//double lastTime;
double currentTime = 0;
double lastTime = 0;

void setup(){
    pinMode(4,OUTPUT);
    pinMode(2,INPUT);
    pinMode(6,OUTPUT);
    pinMode(8,OUTPUT);
}

void loop(){
    digitalWrite(4,1);
    lastTime = millis()/1000.0;
    startTime = lastTime;
    while(!(((lastTime) > ((startTime) + (5))) | (((1)==(digitalRead(2))))))
    {
        _loop();
        lastTime = millis()/1000.0;
    }
    digitalWrite(4,0);
    digitalWrite(6,1);
    _delay(2);
    digitalWrite(6,0);
    digitalWrite(8,1);
    _delay(8);
    digitalWrite(8,0);
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
}

