
#include <Wire.h> //Required for I2C
#include <SPI.h> //For BMP dual sensor reading
#include <LiquidCrystal.h> //LCD Library for 16x2
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

//Constants for BMP Sensor
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10


Adafruit_BMP280 bme; // I2C
//Adafruit_BMP280 bme(BMP_CS); // hardware SPI
//Adafruit_BMP280 bme(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

//LCD Setup
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
    
    //lcd.print("Pressure = ");
    //lcd.print(bme.readPressure()); //Optional pressure reading

    
    double Alt = bme.readAltitude(1020.8);//Stores altitude reading in Alt
    int AltFt = Alt * 3.28084;//Converts altitude in meters to feet
    lcd.print("Altitude:");
    lcd.print(AltFt);
    lcd.print("'");


    double tempC = bme.readTemperature(); //Stores sensor temperature reading in tempC
    int tempF = tempC *1.8 + 32; //Convert Celsius reading to Farenheit
    lcd.setCursor(0,1);
    lcd.print("Temperature:");
    lcd.print(tempF);
    lcd.print("F");
 

    delay(10000);
    
}

