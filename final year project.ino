#include <LiquidCrystal.h>
#include<SoftwareSerial.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(13,12,11,10,9,8);
int sw1 =A0;
int sw2 =7;
int sw3 =A2;
int sw4 =A3;
int out1=6;
int buzzer=3;

 
void setup()
{
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(sw3,INPUT); 
  pinMode(sw4,INPUT);
  pinMode(out1,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
//  pinMode(out2,OUTPUT);

  Serial.begin(9600);
  lcd.begin(16,2);
    lcd.setCursor(0, 0);
      lcd.print("NO _CONNECTIVITY");
      Serial.print("NO_CONNECTIVITY");
      lcd.setCursor(0, 1);
      lcd.print("ZONE");delay(2000);
  
}  
void loop()
{
    
    
    

    if((digitalRead(sw1)==LOW) && (digitalRead(sw2)==HIGH) && (digitalRead(sw3)==HIGH) && (digitalRead(sw4)==HIGH))
  {
  
    lcd.setCursor(0, 0);
    lcd.print("PERSON");
    Serial.print("PERSON_WAS");
    lcd.setCursor(0, 1);
    lcd.print("SAFE");
    Serial.println("SAFE");
    delay(1000);
     lcd.clear();
    delay(2000);
  }
  if((digitalRead(sw1)==HIGH) && (digitalRead(sw2)==LOW) && (digitalRead(sw3)==HIGH) && (digitalRead(sw4)==HIGH))
  {
   // count = 6;
   // sped=150;
    lcd.setCursor(0, 0);
    lcd.print("PERSON_IS_IN_danger_lat:17.4613 long:78.6942");
    Serial.println("PERSON_IS_IN_danger_lat:17.4613 long:78.694");
    lcd.setCursor(0, 1);
     digitalWrite(buzzer,HIGH);delay(1000);digitalWrite(buzzer,LOW);
    delay(1000);
     lcd.clear();
    delay(2000);
  }
  if((digitalRead(sw1)==HIGH) && (digitalRead(sw2)==HIGH) && (digitalRead(sw3)==LOW) && (digitalRead(sw4)==HIGH))
  {
   // count = 4;
   // sped=100;
    lcd.setCursor(0, 0);
    lcd.print("PERSON IS");
    Serial.println("PERSON_IS");
    lcd.setCursor(0, 1);
    lcd.print("IN STREET");
    Serial.println("IN_STREET");
    delay(1000);
     lcd.clear();
    delay(2000);
  }
  if((digitalRead(sw1)==HIGH) && (digitalRead(sw2)==HIGH) && (digitalRead(sw3)==HIGH) && (digitalRead(sw4)==LOW))
  {
   
    lcd.setCursor(0, 0);
    lcd.print("PERSON");Serial.println("PERSON");
    lcd.setCursor(0, 1);
    lcd.print("AT_LOCATION");
    Serial.println("AT_LOCATION");
    delay(1000);
     lcd.clear();
    delay(2000);
  }
  else
  {
    lcd.print("nothing");
    
    delay(2000);
    lcd.clear();
  }
  
 
  }
