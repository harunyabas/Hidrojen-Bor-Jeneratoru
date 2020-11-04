#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "RoboClaw.h"

RoboClaw roboclaw(&Serial, 10000);

const char pw[] = "b5enerji";
const char ap_name[] = "B5 AI-HYD";

ESP8266WebServer server(80);

const char home_page[] = R"=====(
<!DOCTYPE html>
<html>
<head>
<script>
  function sendCommand(chan,state) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
 
      }
    };
    xhttp.open("GET", "handleMotor?motorChannel="+chan+"&motorState="+state, true);
    xhttp.send();
  }

  setInterval(function(){
   getEnc_1();
  }, 1000);
  
   setInterval(function(){
   getTemp();
  }, 1000);

   setInterval(function(){
   getTemp2(); 
  }, 1000);

   setInterval(function(){
   getVoltage();
  }, 5000);
  
   setInterval(function(){
   getCurrents();
  }, 2000);
  
   setInterval(function(){
   getPWMs();
  }, 2000);

  function getEnc_1() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if(this.readyState == 4 && this.status == 200){
        document.getElementById("encoder_1_value").innerHTML = this.responseText;
      }
    };
    xhttp.open("GET","readEncoder_1",true);
    xhttp.send();
  }

  function getTemp() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if(this.readyState == 4 && this.status == 200){
        document.getElementById("temp").innerHTML = this.responseText;
      }
    };
    xhttp.open("GET","readTemp",true);
    xhttp.send();
  }
  
  function getTemp2() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if(this.readyState == 4 && this.status == 200){
        document.getElementById("temp2").innerHTML = this.responseText;
      }
    };
    xhttp.open("GET","readTemp2",true);
    xhttp.send();
  }
  
  function getVoltage() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if(this.readyState == 4 && this.status == 200){
        document.getElementById("voltage").innerHTML = this.responseText;
      }
    };
    xhttp.open("GET","readVoltage",true);
    xhttp.send();
  }

  function getCurrents(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function(){
      if(this.readyState == 4 && this.status == 200){
        document.getElementById("currents").innerHTML = this.responseText;
      }
    };
    xhttp.open("GET","readCurrents",true);
    xhttp.send();
  }

  function getPWMs(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function(){
      if(this.readyState == 4 && this.status == 200){
        document.getElementById("pwms").innerHTML = this.responseText;
      }
    };
    xhttp.open("GET","readPWMs",true);
    xhttp.send();
  }
</script>

<style>
.bbes-content{
 padding:10px 0 10px 0;
 margin-top:5px;
 overflow:hidden;
}
.card {
 display: inline-block;
 position: relative;
 width: 100%;
 border-radius: 5px;
 color: rgba(0,0,0, 0.87);
 background: transparent;
}
.gogle{
 transition: background-color 1s;
 box-shadow:0 16px 38px -12px rgba(0, 0, 0, 0.56), 
  0 4px 25px 0px rgba(0, 0, 0, 0.12), 
  0 8px 10px -5px rgba(0, 0, 0, 0.2);
}
h2{
 color: #707078;
}

.btn{
 background-color:#f3f3f3;  
}
.btn-action{
 color:#FFFFFF;
 background:#1eb858;
 border-color:#1eb858;  
}
.btn-action:hover{
 color: #1eb858;
 background: transparent;
 border-color: #1eb858;
}
.btn-danger{
 color:#FFFFFF;
 background:red;
 border-color:red;  
}
.btn-danger:hover{
 color: red;
 background: transparent;
 border-color: red;
}
span{
 color: #707078;
}
p{
 color: #707078;
 font-size: 25px;
}
td:hover{
  box-shadow:0 0 10px 0 rgba(0,0,0, 0.4);
 -webkit-transition:0.4s;
 -moz-transition:0.4s;
 -o-transition:0.4s;
 transition:0.4s;
  }
td{
  margin:10px 10px 10px 10px;
  padding:10px 32px 10px 32px;
  }
</style>
</head
<body>
 <table class="bbes-content card">
  <thead class="gogle">
   <tr>
    <td colspan="30" style="text-align:center;">
     <h1>B5 ENERJI SAVUNMA VE UZAY TEKNOLOJILERI</h1>
    </td>
   </tr>
  </thead>
  <tr class="gogle">
   <td colspan="5">
    <div class="">
     <h2>Sensor Degerleri</h2>
    </div>
   </td>
   <td colspan="5" style="text-align:center;">
    <p>Voltaj : <span id="voltage">0</span>V</p>
   </td>
   <td colspan="5" style="text-align:center;">
    <p>Akim : <span id="currents">0</span>A</p>
   </td>
   <td colspan="5" style="text-align:center;">
    <p>Islem : <span id="pwms">0</span></p>
   </td>
  </tr>
  <tr class="gogle">
   <td colspan="5">
    <div class="">
     <h2>Uretim 1</h2>
    </div>
   </td>
   <td colspan="5" style="text-align:center;">
    <button type="button" class="btn btn-action" onclick="sendCommand('1','1')">Baslat</button>
   </td>
   <td colspan="5" style="text-align:center;">
    <button type="button" class="btn btn-danger" onclick="sendCommand('1','0')">Durdur</button>
   </td>
   <td colspan="5" style="text-align:center;">
    <p>Sicaklik : <span id="temp">0</span>C</p>
   </td>
   <td colspan="5" style="text-align:center;">
    <p>Enkoder : <span id="encoder_1_value">0</span></p>
   </td>
  </tr>
  <tr class="gogle">
   <td colspan="5">
    <div class="">
     <h2>Uretim 2</h2>
    </div>
   </td>
   <td colspan="5" style="text-align:center;">
    <button type="button" class="btn btn-action" onclick="sendCommand('2','1')">Baslat</button>
   </td>
   <td colspan="5" style="text-align:center;">
    <button type="button" class="btn btn-danger" onclick="sendCommand('2','0')">Durdur</button>
   </td>
   <td colspan="5" style="text-align:center;">
    <p>Sicaklik : <span id="temp2">0</span>C</p>
   </td>
   <td colspan="5" style="text-align:center;">
   <p>Enkoder : <span id="encoder_1_value">0</span></p>
   </td>
  </tr>
  
 </table>

    
    
</body>
</html>

)=====";

void handleHome(){
  String page = home_page;
  server.send(200, "text/html",page);
}

void handleEncoder_1(){
  int enc_value = roboclaw.ReadEncM1(0x80);
  String value = String(enc_value);
  server.send(200, "text/plain", value);
    
}

void handleMotor(){
  String motor_channel = server.arg("motorChannel");
  String motor_state = server.arg("motorState");
  if(motor_channel == "1") {
    if(motor_state == "1") {
      roboclaw.ForwardBackwardM1(0x80, 96);
    }
    else if(motor_state == "0") {
      roboclaw.ForwardBackwardM1(0x80, 64);
    }
  }

  else if(motor_channel == "2") {
     if(motor_state == "1") {
      roboclaw.ForwardBackwardM1(0x80, 96);
    }
    else if(motor_state == "0") {
      roboclaw.ForwardBackwardM1(0x80, 64);
    }
  }
  
}

void handleTemp() {
  uint16_t temp = 0;
  roboclaw.ReadTemp(0x80, temp);
  float temp_f = (float)temp/10;
  String temp_str = String(temp_f);
  server.send(200, "text/plain", temp_str);
}
void handleTemp2() {
  uint16_t temp2 = 0;
  roboclaw.ReadTemp(0x80, temp2);
  float temp2_f = (float)temp2/10;
  String temp2_str = String(temp2_f);
  server.send(200, "text/plain", temp2_str);
}

void handleVoltage() {
  int voltage = 0;
  voltage = roboclaw.ReadMainBatteryVoltage(0x80);
  float voltage_f = (float)voltage/10;
  String voltage_str = String(voltage_f);
  server.send(200, "text/plain", voltage_str);
}

void handleCurrents(){
  int16_t current1 = 0;
  int16_t current2 = 0;
  roboclaw.ReadCurrents(0x80, current1, current2);
  
  float current1_f = (float)current1/100;
  String current1_str = String(current1_f);
  float current2_f = (float)current2/100;
  String current2_str = String(current2_f);
  server.send(200, "text/plain", current1_str);
}

void handlePWMs(){
 int16_t pwm1 = 0;
 int16_t pwm2 = 0;
 
 roboclaw.ReadPWMs(0x80, pwm1, pwm2);

 float pwm1_f = (float)pwm1/1000;
 String pwm1_str = String(pwm1_f);
 float pwm2_f = (float)pwm2/1000;
 String pwm2_str = String(pwm2_f);
 server.send(200, "text/plain", pwm1_str);  
}

void setup() {
  roboclaw.begin(38400);
  Serial.swap();
  WiFi.softAP(ap_name, pw);

  server.on("/", handleHome);
  server.on("/readEncoder_1", handleEncoder_1);
  server.on("/handleMotor", handleMotor);
  server.on("/readTemp", handleTemp);
  server.on("/readTemp2", handleTemp2);
  server.on("/readVoltage", handleVoltage);
  server.on("/readCurrents", handleCurrents);
  server.on("/readPWMs", handlePWMs);

  server.begin();

}

void loop() {
  server.handleClient();
}
