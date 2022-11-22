/*
 The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * 10K resistor:
   * ends to +5V and ground
   * wiper to LCD VO pin (pin 3)
*/

#include <LiquidCrystal.h>

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define led 13
#define sensor 2

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
  {
  lcd.clear();
  int val = digitalRead(sensor);
  if (val == LOW)
  {
    digitalWrite(led, LOW);
    delay(100);
  }
    if (val == HIGH)
    {
      Serial.println("Motion Detected");
      digitalWrite(led, HIGH);
       lcd.print("Motion Detected");
    }
  }
 
  
  
