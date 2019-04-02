#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <SPI.h>
#include<Ethernet.h>
#include<SoftwareSerial.h>
#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#include<Servo.h>
Servo servo;
SoftwareSerial S1(D2, D3);
SoftwareSerial S2(D4, D5);//D4 pin=A0;
SoftwareSerial S3(D6, D7);
SoftwareSerial S5(D0, D1);
int pump=D8;


int pinValue, pinValue2, pinValue3, pinValue4;
float val1, val2, val3;

char auth[] = "enter your authentication code from blynk";
char ssid[] = "yyy";
char pass[] = "pahar123";
BlynkTimer timer;


void myTimerEvent()
{
 
  Blynk.virtualWrite(V8, val1);
  Blynk.virtualWrite(V6, val2);
  Blynk.virtualWrite(V7, val3);
}

void setup()
{
  Serial.begin(9600);
  S1.begin(4800);
  S2.begin(4800);
  S3.begin(4800);
  S5.begin(4800);
  //S4.begin(4800);
  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, INPUT);//D4 connection to be changed
  pinMode(D5, OUTPUT);
  pinMode(D6, INPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, INPUT);
  pinMode(D9, OUTPUT);
  pinMode(D0, INPUT);
  pinMode(D1, OUTPUT);
  pinMode(pump,OUTPUT);
  servo.attach(D0);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);

}

void sensor()
{
  while (S1.available() > 0)
  {
    val1 = S1.parseFloat();
    if (S1.read() == '\n')
    {
      Serial.print("moisture1:");
      Serial.println(val1);
    }
  
  delay(30);
  val2 = S1.parseFloat();
    if (S1.read() == '\n')
    {
      Serial.print("moisture2:");
      Serial.println(val2);
    }
  
   val3 = S1.parseFloat();
    if (S1.read() == '\n')
    {
      Serial.print("moisture3:");
      Serial.println(val3);
    }
 
  delay(30);
}}

BLYNK_WRITE(V1)
{
  pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable

  // process received value
}
BLYNK_WRITE(V2)
{
  pinValue2 = param.asInt(); // assigning incoming value from pin V1 to a variable

  // process received value
}
BLYNK_WRITE(V3)
{
  pinValue3 = param.asInt(); // assigning incoming value from pin V1 to a variable

  // process received value
}
BLYNK_WRITE(V0)
{
  pinValue4 = param.asInt(); // assigning incoming value from pin V1 to a variable

  // process received value
}
/*BLYNK_READ(V5)
{
  Blynk.virtualWrite(V8,val1);
}
BLYNK_READ(V6)
{
  Blynk.virtualWrite(V6,val2);
}
BLYNK_READ(V7)
{
  Blynk.virtualWrite(V7,val3);
}*/

void loop()
{

  //delay(30);
  sensor();
  timer.run();
    /*while (S4.available() > 0)
    {
    float val4 = S4.parseFloat();
    if (S4.read() == '\n')
    {
      Serial.print("water_level:");
      Serial.println(val4);
    }*/

  /*delay(30);
    //delay(500);
    if (pinValue > 0)
    {
    int i = 45;
    S4.print(i);
    S4.println('\n');
    Serial.println("pin1on");
    delay(30);
    }
    if (pinValue2 > 0)
    {
    int i = 90;
    S4.print(i);
    S4.println('\n');
    Serial.println("pin2on");
    delay(30);
    }
    if (pinValue3 > 0)
    {
    int i = 135;
    S4.print(i);
    S4.println('\n');
    Serial.println("pin3on");
    delay(30);
    }*/
  
  if (pinValue4 > 0)
  {
    
    if (pinValue > 0)
    {
      servo.write(135);
      Serial.println("man1");
      digitalWrite(pump,HIGH);
      delay(2000);
      digitalWrite(pump,LOW);
    }
    if (pinValue2 > 0)
    {
      servo.write(90);
      Serial.println("man2");
      digitalWrite(pump,HIGH);
      delay(2000);
      digitalWrite(pump,LOW);
    }
    if (pinValue3 > 0)
    {
      servo.write(45);
      Serial.println("man3");
      digitalWrite(pump,HIGH);
      delay(2000);
      digitalWrite(pump,LOW);
    }

    Serial.println("hhh");
    int modee=1;
    S5.println(modee);
    S5.println('\n');
    delay(30);
  }
  else
  {
    int modee=0;
    S5.println(modee);
    S5.println('\n');
    delay(30);
    servo.write(90);
    if (val1 > 500)
  {
    servo.write(135);
    Serial.println("water1");
    digitalWrite(pump,HIGH);
    delay(2000);
    servo.write(90);
    digitalWrite(pump,LOW);
  }
  if (val2 > 500)
  {
    servo.write(0);
    Serial.println("water2");
    digitalWrite(pump,HIGH);
    delay(2000);
    servo.write(90);
    digitalWrite(pump,LOW);
  }
  if (val3 > 500)
  {
    servo.write(45);
    Serial.println("water3");
    digitalWrite(pump,LOW);
    delay(2000);
    servo.write(90);
    digitalWrite(pump,LOW);
  }
  }

  Blynk.run();
}
