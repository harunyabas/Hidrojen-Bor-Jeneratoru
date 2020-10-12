#include <SoftwareSerial.h>
#include "RoboClaw.h"

SoftwareSerial serial(10,11);  
RoboClaw roboclaw(&serial,10000);

#define address 0x80

int islem = 1;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  roboclaw.begin(38400);

  roboclaw.ForwardM1(address, 0);
  roboclaw.BackwardM1(address, 0);
  
  digitalWrite(LED_BUILTIN, HIGH);
}
void loop(){
  if(digitalRead(LED_BUILTIN) == HIGH){
    dongu(0);
    islem1P();
    }else{
    dongu(1);
    islem1N();  
    }
    delay(500);
}

void dongu(int x){
  digitalWrite(LED_BUILTIN, x);
  Serial.println(x);
}

void islem1P(){
 if(islem==1){
  roboclaw.ForwardM1(0x80, 127);
 }
 Serial.println("ISLEM : 1");  
}
void islem1B(){
 if(islem==1){
  roboclaw.ForwardM1(0x80, 0);
  roboclaw.BackwardM1(0x80, 0);
 }
 Serial.println("ISLEM : 0");
}
void islem1N(){
 if(islem==1){
  roboclaw.BackwardM1(0x80, 127);
 }
 Serial.println("ISLEM : 2");
}
void durdurma(){
 for(int durdur=12;durdur>12;durdur--){
  digitalWrite(durdur, LOW);
 }  
}
