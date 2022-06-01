#include <Arduino.h>

#define LED 16
unsigned long Mytime;
#define interruptpin 0
void  pin_interrupt();
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LED,OUTPUT);
 attachInterrupt(digitalPinToInterrupt(interruptpin), pin_interrupt, FALLING);
}



void loop() {
  // put your main code here, to run repeatedly:
  Mytime=millis();
  while(millis()<Mytime+1000){}
  digitalWrite(LED,HIGH);
  Serial.println("PUT ON"); 
  Mytime=millis();
  while(millis()<Mytime+1000){}
  Serial.println("PUT OFF");
  digitalWrite(LED,LOW);
  
  
}

void pin_interrupt (){

Serial.println("PULSADO");

}