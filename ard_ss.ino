#include <LiquidCrystal_I2C.h>
#include<Wire.h>
#include<SoftwareSerial.h>
#include<Ultrasonic.h>
#include<Servo.h>
SoftwareSerial s1(3, 2);
SoftwareSerial s2(5, 4);
SoftwareSerial s3(7, 6);
SoftwareSerial S4(10, 9);//serial communictaion between 2 ardiuno
int m1 = A0;
int m2 = A1;
int m3 = A2;
int pump = A3;
int ultra_trig = 12;
int ultra_echoo = 13;
Servo servo;
Ultrasonic ultra(ultra_trig, ultra_echoo);
LiquidCrystal_I2C lcd(0x27, 20, 4);                                  //change address

void setup()
{
  /*pinMode(D2,INPUT);
    pinMode(D3,OUTPUT);*/
  Serial.begin(9600);
  s1.begin(4800);
  s2.begin(4800);
  s3.begin(4800);
  S4.begin(4800);

  pinMode(m1, INPUT);
  pinMode(m2, INPUT);
  pinMode(m3, INPUT);
  //servo.attach(A4);
  lcd.begin(20,4);
  lcd.backlight();
}

void check_level()
  {
  //int dist = ultra.read(CM);
  digitalWrite(ultra_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(ultra_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultra_trig, LOW);
  int duration = pulseIn(ultra_echoo, HIGH);
  int dist= duration*0.034/2;
  
  /*s3.print(dist);
  s3.println('\n');
  delay(1000);
  Serial.print("dist:");
  Serial.println(dist);
  */
  }

void loop()
{
  
  //check_level();
  int m11 = analogRead(m1);
  if(m11>600)
  {
    digitalWrite(pump,HIGH);
    delay(1000);
    digitalWrite(pump,LOW);
  }
  s1.print(m11);
  s1.println('\n');
  delay(30);
  Serial.println(m11);
  s3.print(m11);
  s3.println('\n');
  
  delay(1000);
  int m12 = analogRead(m2);
  
  if(m12>600)
  {
    digitalWrite(pump,HIGH);
    delay(1000);
    digitalWrite(pump,LOW);
  }
  s1.print(m12);
  s1.println('\n');
  delay(30);
  Serial.println(m12);
  s3.print(m12);
  s3.println('\n');
  /*lcd.setCursor(0, 1);
  lcd.print("moisture2: ");
  lcd.print(m12);*/
  delay(1000);
  int m13 = analogRead(m3);
  
  if(m13>600)
  {
    digitalWrite(pump,HIGH);
    delay(1000);
    digitalWrite(pump,LOW);
  }
  s1.print(m13);
  s1.println('\n');
  delay(30);
  Serial.println(m13);
  s3.print(m13);
  s3.println('\n');
  delay(1000);
}
