#include <SD.h>
#include <Wire.h>
#include "MMA7660.h"
#include <SoftwareSerial.h>
#define COUNT_OF_LATITUDE 3
#define COUNT_OF_LONGITUDE 5
#define COUNT_OF_TIME  1
MMA7660 acc;
const int chipSelect = 10;
SoftwareSerial ss(3,2);
String StringMass[12];

void setup()
{
    acc.init();
    pinMode(13, OUTPUT);
    Serial.begin(38400);
    ss.begin(38400);
    pinMode(10, OUTPUT);
    if (!SD.begin(chipSelect)) {
      return;
  }
}

void loop()
{

    float ax,ay,az;
    char index = 0;
    char temp = 0;
    String dataString = "";
    int count=0;

    
    acc.getAcceleration(&ax,&ay,&az);
    File dataFile = SD.open("data.csv", FILE_WRITE);
    if(dataFile)
    {
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
                break;
            }
            if(count==1&&StringMass[0]!="$GPRMC"){
                for(int i=0; i<2;i++){
                    StringMass[i]="";
                }
                while(dataString!="$GPRMC"){
                    temp = ss.read();
                    if(temp==','){
                        StringMass[count]=dataString;
                        temp=0;
                        dataString="";
                        count++;
                    }   
                    dataString += String(temp);
                }
            }
            dataString += String(temp);
            index++;
            if(index>600){
                break;
            }
        }
    dataFile.print(StringMass[COUNT_OF_TIME]);
    dataFile.print(",");
    dataFile.print(StringMass[COUNT_OF_LONGITUDE]);
    dataFile.print(",");
    dataFile.print(StringMass[COUNT_OF_LATITUDE]);
    dataFile.print(",");
    dataFile.print(ax);
    dataFile.print(",");
    dataFile.print(ay);
    dataFile.print(",");
    dataFile.println(az);
    dataFile.close();
    delay(100);
    }

}


