#include <SD.h>
#include <Wire.h>
#include "MMA7660.h"
#include <SoftwareSerial.h>
#define COUNT_OF_LATITUDE 3
#define COUNT_OF_LONGITUDE 5
#define COUNT_OF_TIME  1
MMA7660 acc;  //Объявление объектов и массива строк
const int chipSelect = 10;
SoftwareSerial ss(3,2);
String StringMass[12];

void setup()
{
    acc.init();  //инициализируем акселерометр
    pinMode(13, OUTPUT);   
    Serial.begin(38400); //инициализируем сериал
    ss.begin(38400);
    pinMode(10, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
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

    
    acc.getAcceleration(&ax,&ay,&az); //получаем данные с акселерометра
    File dataFile = SD.open("data.csv", FILE_WRITE); //открываем файл с данными
    if(dataFile)
    {
        while(ss.available()) //в этой части кода мы читаем то, что отправляет нам GPS модуль
        {    
            temp = ss.read();
            if(temp==','){                          //разделяем данные на отдельные элементы
                StringMass[count]=dataString;
                temp=0;
                dataString="";
                count++;   
            }
            if(StringMass[2]=="V"){         //Проверяем приходят ли координаты
                digitalWrite(4, HIGH);
                delay(400);
                digitalWrite(4,LOW);
                break;
            }
            if(count==1&&StringMass[0]!="$GPRMC"){  //проверяем та ли строка нам приходит
                for(int i=0; i<2;i++){
                    StringMass[i]="";
                }
                while(dataString!="$GPRMC"){ //ждем нужной строки
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
            dataString += String(temp); // заполняем часть строки
            index++;
            if(index>600){
                break;
            }
        }
        if(StringMass[COUNT_OF_TIME]&&StringMass[COUNT_OF_LONGITUDE]&&StringMass[COUNT_OF_LATITUDE]){ //индикатор получения данных
                digitalWrite(5, HIGH);
                delay(400);
                digitalWrite(5,LOW);
        }
        
        dataFile.print(StringMass[COUNT_OF_TIME]); //вывод данных в файл на SD карте
        dataFile.print(",");
        dataFile.print(StringMass[COUNT_OF_LONGITUDE]); 
        dataFile.print(",");
        dataFile.print(S21tringMass[COUNT_OF_LATITUDE]);
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


