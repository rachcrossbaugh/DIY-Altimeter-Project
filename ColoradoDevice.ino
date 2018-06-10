
#include <Wire.h>
#include <SPI.h>
#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10


Adafruit_BMP280 bme; // I2C
//Adafruit_BMP280 bme(BMP_CS); // hardware SPI
//Adafruit_BMP280 bme(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);


LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
    Serial.begin(9600);
    Serial.println(F("BMP280 test"));
  
    if (!bme.begin()) {  
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);}
}

void loop()
{
    lcd.begin(16, 2);
    lcd.clear();

    lcd.setCursor(0,0);
    //lcd.print("Temp = ");
    //lcd.print(bme.readTemperature());

    //lcd.print("Pressure = ");
    //lcd.print(bme.readPressure());

    
    double Alt = bme.readAltitude(1020.8);
    int AltFt = Alt * 3.28084;
    lcd.print("Altitude:");
    lcd.print(AltFt);
    lcd.print("'");


    double tempC = bme.readTemperature();
    int tempF = tempC *1.8 + 32;
    lcd.setCursor(0,1);
    lcd.print("Temperature:");
    lcd.print(tempF);
    lcd.print("F");
 

    delay(10000);
    
}

