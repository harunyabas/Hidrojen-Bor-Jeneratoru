#include <SoftwareSerial.h>
#include "RoboClaw.h"

SoftwareSerial serial(10,11);  
RoboClaw roboclaw(&serial,10000);

#define address 0x80

int sysSt = 1;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  roboclaw.begin(38400);

  roboclaw.ForwardM1(address, 0);
  roboclaw.BackwardM1(address, 0);
  
  digitalWrite(LED_BUILTIN, HIGH);
}
void loop(){
  if(digitalRead(LED_BUILTIN) == HIGH){
    sysBack(0);
    attack1P();
    }else{
    sysBack(1);
    attack1N();  
    }
    delay(500);
}

void sysBack(int x){
  digitalWrite(LED_BUILTIN, x);
  Serial.println(x);
}
void elektroliz1(){
 if(sysSt==1){
  attack1P(); 
 }
}
void elektroliz2(){
 if(sysSt==1){
  attack1N(); 
 }
}
void attackTurn(){
  attack1B(); 
}

void attack1P(){
 if(sysSt==1){
  float Emax1 = 2.7399;
  Serial.println(Emax1);
  float Emax2 = 2.7399;
  float Emax3 = 2.7399;
  Serial.println(Emax3);
  float Emax4 = 2.7399;
  float Emax5 = 2.7399;
  Serial.println(Emax5); 
  float Emax = Emax1+Emax2+Emax3+Emax4+Emax5;
  Serial.println(Emax);

  byte p = 1;
  Serial.println(p);
  byte Npp = 0;
  byte Npe = 0;
  Serial.println(Npe);
  float Enpp = Emax*(1/p-1/(p*pow(Npp+1,2)));  
  Serial.println(Enpp);
  
  float R1 = 4/3*4/3;
  Serial.println(R1);
  float R2 = 8/3*R1;
  float R3 = 8/5*R1;
  Serial.println(R3);
  float R4 = 8/3*R1;
  float R5 = 8/5*R1;
  Serial.println(R5);
  float R6 = 8/3*R1;
  float R7 = 8/5*R1;
  Serial.println(R7);
  float R8 = 8/3*R1;
  float R9 = 8/5*R1;
  Serial.println(R9);
  float R10 = 8/3*R1;
  float R11 = 8/5*R1;
  Serial.println(R11);
  float R12 = 8/3*R1;
  float R13 = 8/5*R1;
  Serial.println(R13);
  float R14 = 8/3*R1;
  float R15 = 8/5*R1;
  Serial.println(R15);
  float R16 = 8/3*R1;
  float R17 = 8/5*R1;
  Serial.println(R17);

  float Enpp1 = 1/4*Emax;
  Serial.println(Enpp1);
  float Enpp2 = 5/8*Emax;
  float Enpp3 = 3/8*Emax;
  Serial.println(Enpp3);
  float Enpp4 = 5/8*Emax;
  float Enpp5 = 3/8*Emax;
  Serial.println(Enpp5);

  float EnB = (1/4+5/8+3/8+5/8+3/8)*Emax+9/4*Emax;
  Serial.println(EnB);
  
  double pulse1 = int((+sin(1.00794*PI/9650)+cos(1.00794*PI/9650))/1600)/10;
  Serial.println(pulse1);
  
  roboclaw.ForwardM1(0x80, 127);
 }
 Serial.println("ISLEM : 1");  
}
void attack1B(){
 if(sysSt==1){
  float Emax1 = 2.7399;
  float Emax2 = 2.7399;
  float Emax3 = 2.7399;
  float Emax4 = 2.7399;
  float Emax5 = 2.7399; 
  float Emax = Emax1+Emax2+Emax3+Emax4+Emax5;

  byte p = 1;
  byte Npp = 0;
  byte Npe = 0;
  float Enpp = Emax*(1/p-1/(p*pow(Npp+1,2)));  
  
  float R1 = 4/3*4/3;
  float R2 = 8/3*R1;
  float R3 = 8/5*R1;
  float R4 = 8/3*R1;
  float R5 = 8/5*R1;
  float R6 = 8/3*R1;
  float R7 = 8/5*R1;
  float R8 = 8/3*R1;
  float R9 = 8/5*R1;
  float R10 = 8/3*R1;
  float R11 = 8/5*R1;
  float R12 = 8/3*R1;
  float R13 = 8/5*R1;
  float R14 = 8/3*R1;
  float R15 = 8/5*R1;
  float R16 = 8/3*R1;
  float R17 = 8/5*R1;

  float Enpp1 = 1/4*Emax;
  float Enpp2 = 5/8*Emax;
  float Enpp3 = 3/8*Emax;
  float Enpp4 = 5/8*Emax;
  float Enpp5 = 3/8*Emax;

  float EnB = (1/4+5/8+3/8+5/8+3/8)*Emax+9/4*Emax;
  
  double pulse1 = int((+sin(1.00794*PI/9650)+cos(1.00794*PI/9650))/1600)/10;
  
  roboclaw.ForwardM1(0x80, 0);
  roboclaw.BackwardM1(0x80, 0);
 }
 Serial.println("ISLEM : 0");
}
void attack1N(){
 if(sysSt==1){
  float Emax1 = 2.7399;
  float Emax2 = 2.7399;
  Serial.println(Emax2);
  float Emax3 = 2.7399;
  float Emax4 = 2.7399;
  Serial.println(Emax4);
  float Emax5 = 2.7399; 
  float Emax = Emax1+Emax2+Emax3+Emax4+Emax5;
  Serial.println(Emax);

  byte p = 1;
  byte Npp = 0;
  Serial.println(Npp);
  byte Npe = 0;
  float Enpp = Emax*(1/p-1/(p*pow(Npp+1,2)));  
  Serial.println(Enpp);
  
  float R1 = 4/3*4/3;
  float R2 = 8/3*R1;
  Serial.println(R2);
  float R3 = 8/5*R1;
  float R4 = 8/3*R1;
  Serial.println(R4);
  float R5 = 8/5*R1;
  float R6 = 8/3*R1;
  Serial.println(R6);
  float R7 = 8/5*R1;
  float R8 = 8/3*R1;
  Serial.println(R8);
  float R9 = 8/5*R1;
  float R10 = 8/3*R1;
  Serial.println(R10);
  float R11 = 8/5*R1;
  float R12 = 8/3*R1;
  Serial.println(R12);
  float R13 = 8/5*R1;
  float R14 = 8/3*R1;
  Serial.println(R14);
  float R15 = 8/5*R1;
  float R16 = 8/3*R1;
  Serial.println(R16);
  float R17 = 8/5*R1;

  float Enpp1 = 1/4*Emax;
  float Enpp2 = 5/8*Emax;
  Serial.println(Enpp2);
  float Enpp3 = 3/8*Emax;
  float Enpp4 = 5/8*Emax;
  Serial.println(Enpp4);
  float Enpp5 = 3/8*Emax;
  
  float EnB = (1/4+5/8+3/8+5/8+3/8)*Emax+9/4*Emax;
  Serial.println(EnB);
  
  double pulse1 = int((+sin(1.00794*PI/9650)+cos(1.00794*PI/9650))/1600)/10;
  Serial.println(pulse1);
  
  roboclaw.BackwardM1(0x80, 127);
 }
 Serial.println("ISLEM : 2");
}
void attackBreak(){
 for(int nasgul=12;nasgul>12;nasgul--){
  digitalWrite(nasgul, LOW);
 }  
}
