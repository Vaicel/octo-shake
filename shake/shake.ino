#include <Wire.h>
#include "MMA7660.h"
MMA7660 acc;

bool shakingNow = false;

void setup()
{
    attachInterrupt(digitalPinToInterrupt(3), shake, RISING);
    acc.init();
    pinMode(13, OUTPUT);
    pinMode(8, INPUT_PULLUP);
    Serial.begin(115200);
    Wire.begin();
    Wire.beginTransmission(MMA7660_ADDR);
    Wire.write(MMA7660_INTSU);
    Wire.write(11100011);
    Wire.endTransmission();
}

void loop(){
    if(shakingNow) {
        shakingNow = false;
        Serial.print(1);
    }
}

void shake(){
    shakingNow = true;
}