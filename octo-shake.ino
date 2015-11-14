#include <SD.h>
#include <Wire.h>
//#include "MMA7660.h"
#include <SoftwareSerial.h>
#define COUNT_OF_LATITUDE 3
#define COUNT_OF_LONGITUDE 5
#define COUNT_OF_TIME  1
//MMA7660 acc;

SoftwareSerial ss(3,2);

void setup()
{
//    acc.init();
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
    String StringMass[12];
    int count=0;

    
//    acc.getAcceleration(&ax,&ay,&az);
    while(ss.available())
    {    
        temp = ss.read();
        if(temp==','){
            StringMass[count]=dataString;
            temp=0;
            dataString="";
            count++;   
        }
        if(StringMass[2]=="V"){
            for(int i=0; i<13;i++){
                StringMass[i]="-";
            }
            break;
        }
        dataString += String(temp);
        index++;
        if(index>600){
        break;
      }
    }
    Serial.println("Longitude: ");
    Serial.println(StringMass[COUNT_OF_LONGITUDE]);
    Serial.println("Latitude: ");
    Serial.println(StringMass[COUNT_OF_LATITUDE]);
    Serial.println("Time: ");
    Serial.println(StringMass[COUNT_OF_TIME]);
    
   /* Serial.print("accleration: ");
    Serial.print(ax);
    Serial.print(ay);
    Serial.print(az);
    Serial.println();
    delay(50);*/

}


