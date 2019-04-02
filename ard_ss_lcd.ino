#include<LiquidCrystal.h>
#include<Wire.h>
#include<SoftwareSerial.h>
#include<Ultrasonic.h>
Ultrasonic ultrasonic(8,9);
SoftwareSerial s5(6,7);
SoftwareSerial s4(10,13);
const int rs = 12, en = 11, d4 = 5, d5 =4 , d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int val1,v1,v2,v3,v4;
/*int ultra_trig = 8;
int ultra_echoo = 9;*/
int dist;

void setup()
{
  Serial.begin(9600);
  s4.begin(4800);
  s5.begin(4800);
  pinMode(6,INPUT);
  pinMode(7,OUTPUT);
  pinMode(10,INPUT);
  pinMode(13,OUTPUT);
  lcd.begin(20, 4);
  lcd.print("Advanced  Irrigation  System using IoT ");
  delay(2000);
  lcd.clear();
  lcd.print("Group members:");
  lcd.setCursor(0, 1);
  lcd.print("1707235-Sudipta");
  lcd.setCursor(0, 2);
  lcd.print("1707232-Subhasis");
  lcd.setCursor(0, 3);
  lcd.print("1707234-Raghuvanshi");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1707238-Suman");
  lcd.setCursor(0, 1);
  lcd.print("1707246-Utkarsh");
  lcd.setCursor(0, 2);
  lcd.print("1707248-Yashwant");
  delay(3000);
  lcd.clear();
  lcd.print("Please  Enjoy  Our  Project");
  delay(2000);
  lcd.clear();
}
/*void water()
{
  digitalWrite(ultra_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(ultra_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultra_trig, LOW);
  int duration = pulseIn(ultra_echoo, HIGH);
  dist= duration*0.034/2;
  delay(100);
  Serial.println(dist);
   lcd.setCursor(0,0);
        lcd.print("tank level:");
        lcd.print(dist);
}*/
void loop()
{
  //Serial.print("hi");
  //water();
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.println(" cm" );
  delay(100);
  lcd.setCursor(0,0);
  lcd.print("Water level: ");
  lcd.print(ultrasonic.Ranging(CM));
  while(s5.available()>0)
  {
    //Serial.print("s5 communication available\n");
    /*val1=s5.parseFloat();
    {
     
      if(s5.read() == '\n')
      {
        Serial.print("tank level: ");
        Serial.println(val1);
        lcd.setCursor(0,0);
        lcd.print("tank level:");
        lcd.print(val1);
        
      }delay(30);*/
      v2=s5.parseFloat();
      if(s5.read() == '\n')
      {
        Serial.print("moisture1 : ");
        Serial.println(v2);
        lcd.setCursor(0,1);
        lcd.print("moisture1: ");
        lcd.print(v2);
      }
      delay(30);
      v3=s5.parseFloat();
      if(s5.read() == '\n')
      {
        Serial.print("moisture2 : ");
        Serial.println(v3);
        lcd.setCursor(0,2);
        lcd.print("moisture2: ");
        lcd.print(v3);
      }
      delay(30);
      v4=s5.parseFloat();
      if(s5.read() == '\n')
      {
      
        Serial.print("moisture3 : ");
        Serial.println(v4);
        lcd.setCursor(0,3);
        lcd.print("moisture3: ");
        lcd.print(v4);
       
      }delay(30);
      //lcd.clear();
    
    }
    /*while (s4.available()>0)
    {
      Serial.print("s4 communication available\n");
      int val=s4.parseFloat();
      if(s4.read()=='\n')
      {
        Serial.print(val);
      }delay(30);
        if (val==1)
        {
          lcd.setCursor(0,1);
          lcd.print("Mode: Manual");
        }
        if(val==0)
        {
          lcd.setCursor(0,1);
          lcd.print("Mode: Automatic");
        }}
      delay(30);*/
      lcd.clear();

}    
