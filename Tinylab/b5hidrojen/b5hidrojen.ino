#include "LedControl.h"
#include <Wire.h>
#include <LiquidTWI2.h>

LedControl lc=LedControl(10,12,11,1);

LiquidTWI2 lcd(0x20);

#define MQ_PIN (A0)
#define RL_VALUE (10) // Yük direnci kilo ohm cinsinden tanımlar
#define RO_CLEAN_AIR_FACTOR (9.21) // Temiz hava sensor direnci
#define CALIBARAION_SAMPLE_TIMES (50) // Kalibrasyon aşamasında alınacak örnek miktarı
#define CALIBRATION_SAMPLE_INTERVAL (500) // Örnekler arası milisaniye cinsinden değer
#define READ_SAMPLE_INTERVAL (50) // Sayım esnasında alınacak örnek atom miktarı
#define READ_SAMPLE_TIMES (5) // Sayım esnasında verilerin karşılarştırılmas süresi. Milisaniye cinden.
#define GAS_H2 (0)

float H2Curve[3]  =  {2.3, 0.93,-1.44};
float Ro = 10; // Ro 10 kilo ohm olarak başlatıldı

int sysSt = 1;
int pwm1 = 3;
int poz1 = 4;
int neg1 = 5;

 int pwm2 = 6;
 int poz2 = 7;
 int neg2 = 8;
 
const int hizliUretim = 9;
const int hizliUretim2 = 8;

  int num1=0;
  int num2=0;
  int num3=0;
  int num4=0;
  
unsigned long delay_time=10;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(230400);
    lc.shutdown(0,false);
    lc.setIntensity(0,8);
    lc.clearDisplay(0);
      lcd.setMCPType(LTI_TYPE_MCP23008);
      lcd.begin(16, 9);
      lcd.setBacklight(HIGH);
      lcd.print("B5 ENERJI SAVUNMA");
      lcd.setCursor(0, 1);
      lcd.print("UZAY TEKNO. A.S.\n");
      lcd.setCursor(0, 2);
        Ro = MQCalibration(MQ_PIN);
      lcd.setCursor(0, 3);
      lcd.clear();
      lcd.print("Kalibrasyon Başarıyla");
      lcd.setCursor(0,4);
      lcd.print("tamamlanmıştır. Yönlendiriliyorsunuz.\n");
      lcd.setCursor(0, 5);
      lcd.print("Ro=");
      lcd.setCursor(0, 6);
      lcd.print(Ro);
      lcd.setCursor(0, 7);
      lcd.print("kohm");
      lcd.setCursor(0, 8);
      lcd.print("\n");
      lcd.setCursor(0, 9);
        lcd.clear();
          pinMode(pwm1, OUTPUT);
          pinMode(pwm2, OUTPUT);
            pinMode(poz1, OUTPUT);
            pinMode(poz2, OUTPUT);
              pinMode(neg1, OUTPUT);
              pinMode(neg2, OUTPUT);
                pinMode(hizliUretim, INPUT);
                pinMode(hizliUretim2, INPUT);
                  digitalWrite(LED_BUILTIN, OUTPUT);
  }

void dongu(){
    int j;
    int num;
    j=MQGetGasPercentage(MQRead(MQ_PIN)/Ro,GAS_H2);
    num = j;
    num4 = num / 1000;
    num = num -(-num4*1000);
    num3 = num /100;
    num = num - (num3 * 100);
    num2 = num /10;
    num1 = num - (num2 * 10);
    for (int i = 1; i<= 50; i++){
      
      }
    if (j >= 1000){
      DisplayNumber(num4);
        delay(4);
      DisplayNumber(num3);
        delay(4);
      DisplayNumber(num2);
        delay(4);
      DisplayNumber(num1);
        delay(4);
    }else if  (j >= 100){   
      DisplayNumber(num4);
        delay(4);
      DisplayNumber(num3);
        delay(4);
      DisplayNumber(num2);
        delay(4);
    }else if(j >= 10){   
      DisplayNumber(num4);
        delay(4);
      DisplayNumber(num3);
        delay(4);
    }
    else if  (j >= 0){   
      DisplayNumber(num4);
        delay(4);
    }
    lc.setDigit(0, 0, num4, false);
    lc.setDigit(0, 1, num3, false);
    lc.setDigit(0, 2, num2, false);
    lc.setDigit(0, 3, num1, false);
      delay(delay_time);
  }
  void DisplayNumber(int x) {
    switch (x) {    
      case 0: sifir();break;
      case 1: bir();break;
      case 2: iki();break;
      case 3: uc();break;
      case 4: dort();break;
      case 5: bes();break;
      case 6: alti();break;
      case 7: yedi();break;
      case 8: sekiz();break;
      case 9: dokuz();break;
    }
}
void sifir(){
  if(sifir >= 0){
    sifir==0;
  }
}
void bir(){
  if(bir >= 1){
    bir==1;
  }
}
void iki(){
  if(iki >= 2){
    iki==2;
  }
}
void uc(){
  if(uc >= 3){
    uc==3;
  }
}
void dort(){
  if(dort >= 4){
    dort==4;
  }
}
void bes(){
  if(bes >= 5){
    bes==5;
  }
}
void alti(){
  if(alti >= 6){
    alti==6;
  }
}
void yedi(){
  if(yedi >= 7){
    yedi==7;
  }
}
void sekiz(){
  if(sekiz >= 8){
    sekiz==8;
  }
}
void dokuz(){
  if(dokuz >= 9){
    dokuz==9;
  }
}

void loop(){
  dongu();
  if(digitalRead(hizliUretim) == LOW){
    lcd.setBacklight(HIGH);
      lcd.print("B5 HİDROJEN JEN");
        lcd.setCursor(0, 1);
      lcd.print("HIZLI URETiM 1A");
        lcd.setCursor(0,2);
          aihydgen1();
  }else if(digitalRead(hizliUretim) == HIGH){
    lcd.setBacklight(HIGH);
      lcd.print("B5 HİDROJEN JEN");
        lcd.setCursor(0,1);
      lcd.print("NORMAL URETiM 1");
        lcd.setCursor(0, 2);
          aihydgen();
    }
  if(digitalRead(hizliUretim2) == LOW){
    lcd.setBacklight(HIGH);
      lcd.print("B5 HİDROJEN JEN");
        lcd.setCursor(0,1);
      lcd.print("HIZLI URETiM 2A");
        lcd.setCursor(0, 2);
          aihydgen2();
      }
}
void aihydgen(){
  if(digitalRead(LED_BUILTIN) == HIGH){
      sysBack(0);
        attack1n();
         attack2p();
      }else{
        sysBack(1);
          attack1p();
           attack2n();
        }
        delay(10*10);
  }
void aihydgen1(){
  if(digitalRead(LED_BUILTIN) == HIGH){
      sysBack(0);
        attack1n();
         attack2p();
      }else{
        sysBack(1);
          attack1p();
           attack2n();
        }
        delay(10*10*10);
  }
void aihydgen2(){
  if(digitalRead(LED_BUILTIN) == HIGH){
      sysBack(0);
        attack1n();
         attack2p();
      }else{
        sysBack(1);
          attack1p();
           attack2n();
        }
        delay(10*10*10*10);
  }
void sysBack(int x) {
  digitalWrite(LED_BUILTIN, x);
    Serial.println("ATAK : ");
      Serial.println(x);
  }
void coptSt() {
  if (sysSt==1) {
    attack1p();
     attack2n();
    }
  }
void coptStd() {
  if (sysSt==1){
    attack1n();
    attack2p();
    }
  }
void attackTurn() {
  attack1h();
   attack2h();
  }
  
void attack1p() {
  if (sysSt == 1) {
    
    analogWrite(pwm1, atselk1PWs1Pesi);
      digitalWrite(poz1, LOW);
      digitalWrite(neg2, HIGH);
    }
    Serial.println("ELEKTROLİZ İŞLEMİ BAŞLADI");
          Serial.println("");
  }
void attack1h() {
  if (sysSt == 1) {
    analogWrite(pwm1, atselk1PWs1Pesi2);
      digitalWrite(poz1, LOW);
      digitalWrite(neg1, HIGH);
    }
    Serial.println("ELEKTROLİZ İŞLEMİ BAŞLADI");
      Serial.println("");
  }
void attack1n() {
  if (sysSt == 1) {
    analogWrite(pwm1, atselk1PWs1P3);
      digitalWrite(poz1, HIGH);
      digitalWrite(neg1, LOW);
    }
    Serial.println("ELEKTROLİZ İŞLEMİ BAŞLADI");
      Serial.println("");
  }
 void attack2p() {
    if (sysSt==1) {
      analogWrite(pwm2, atselk2PWs2Pess);
        digitalWrite(poz2, LOW);
        digitalWrite(neg2, HIGH);
      }
      Serial.println("ELEKTROLİZ İŞLEMİ BAŞLADI");
        Serial.println("");
    }
  void attack2h() {
    if (sysSt==1) {
      analogWrite(pwm2, atsel2PWs2Pe22);
        digitalWrite(poz2, LOW);
        digitalWrite(neg2, HIGH);
      }
      Serial.println("ELEKTROLİZ İŞLEMİ BAŞLADI");
        Serial.println(""); 
    }
  void attack2n() {
    if (sysSt==1) {
      analogWrite(pwm2, atsel2PWs2Pe33);
        digitalWrite(poz2, HIGH);
        digitalWrite(neg2, LOW);
      }
      Serial.println("ELEKTROLİZ İŞLEMİ BAŞLADI");
        Serial.println(""); 
    }
void attackTurn1() {
  for (int nasgl = 2; nasgl < 11; nasgl++){
    digitalWrite(nasgl, LOW);
    
    } 
  }

float MQResistanceCalculation(int raw_adc) {
  return ( ((float)RL_VALUE*(1023-raw_adc)/raw_adc));
}

float MQCalibration(int mq_pin) {
  int i;
  float val=0;
   for (i=0;i<CALIBARAION_SAMPLE_TIMES;i++) {
      val += MQResistanceCalculation(analogRead(mq_pin));
    delay(CALIBRATION_SAMPLE_INTERVAL);
  }
      val = val/CALIBARAION_SAMPLE_TIMES; 
      val = val/RO_CLEAN_AIR_FACTOR; 
      return val;
  }
  
float MQRead(int mq_pin) {
  int i;
  float rs=0;
  for (i=0;i<READ_SAMPLE_TIMES;i++) {
    rs += MQResistanceCalculation(analogRead(mq_pin));
    delay(READ_SAMPLE_INTERVAL);
  }
  rs = rs/READ_SAMPLE_TIMES;
  return rs;  
}

int MQGetGasPercentage(float rs_ro_ratio, int gas_id) {
  if ( gas_id == GAS_H2) {
     return MQGetPercentage(rs_ro_ratio,H2Curve);
  }  
  return 0;
}

int  MQGetPercentage(float rs_ro_ratio, float *pcurve) {
  return (pow(10,( ((log(rs_ro_ratio)-pcurve[1])/pcurve[2]) + pcurve[0])));
}
