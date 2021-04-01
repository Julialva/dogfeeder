#include <Servo.h>

Servo servo1;
long int counter;
int PosGo=0;
int PosRest=90;
int MealTime=5000;
int Sleep = 15000;
int OpenCloseTime = 1500;
//int MealTime=1000*60*6;
//int Sleep = 1000*60*6;
int LEDPin=8;
int ButtonPin=12;
int ButtonRead;
unsigned long int PreviousTime;
void setup() {
  Serial.begin(9600);
  pinMode(LEDPin,OUTPUT);
  pinMode(ButtonPin,INPUT);
  servo1.attach(9);
}

void loop() {    
 ButtonRead=digitalRead(ButtonPin);
 
 if (ButtonRead==1){
  servo1.write(PosGo);
  digitalWrite(LEDPin,HIGH);
  delay(OpenCloseTime);
  PreviousTime = millis();
  counter = counter + 1;
 }
 

 if(millis() - PreviousTime >=MealTime){
      servo1.write(PosGo);
      digitalWrite(LEDPin,HIGH);
      delay(OpenCloseTime);
      PreviousTime = millis();
      counter = counter + 1;

 }

 else{
  digitalWrite(LEDPin,LOW);
  servo1.write(PosRest);
 }
 if (counter >= 3){
      delay(Sleep);
      counter=0;
    }
 }

 
