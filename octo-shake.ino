#include <SD.h>
#include <Wire.h>
#include "MMA7660.h"
#include <SoftwareSerial.h>
MMA7660 acc;

SoftwareSerial ss(3,2);

void setup()
{
    acc.init();
    pinMode(13, OUTPUT);
    Serial.begin(38400);
    ss.begin(38400);
    pinMode(10, OUTPUT);
}

void loop()
{

    float ax,ay,az;
    char index = 0;
    char temp = 0;
    String dataString = "";
    
    acc.getAcceleration(&ax,&ay,&az);
    while(ss.available())
    {    
        temp = ss.read();
     dataString += String(temp);
     index++;
      if(index>600){
        break;
      }
    }
    if(dataString!="") Serial.println(dataString);
   /* Serial.print("accleration: ");
    Serial.print(ax);
    Serial.print(ay);
    Serial.print(az);
    Serial.println();
    delay(50);*/

}


