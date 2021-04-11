#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>
#include "paginaWeb.h"

#define SSID "seu_Wifi"
#define SENHA "sua_Senha"

ESP8266WebServer servidor;
Servo horizontal;
Servo vertical;

void moveServos(void);

void setup() {
horizontal.attach(D1);
vertical.attach(D2);
horizontal.write(0);
vertical.write(0);
WiFi.begin(SSID,SENHA);
Serial.begin(115200);

while(WiFi.status()!=WL_CONNECTED)//Enquanto a conexão não é realizada
{
  Serial.print(".");
  delay(500);
}

Serial.print("IP Address: ");
Serial.println(WiFi.localIP());//Ip onde tenho que me conectar

servidor.on("/movimento", HTTP_GET, moveServos);
servidor.begin();
}

void loop() {
  servidor.send(200,"text/html", paginaWeb);
  servidor.handleClient();  
}

void moveServos(void){
  if(servidor.hasArg("v") && servidor.hasArg("h")){
    horizontal.write(servidor.arg("h").toInt());
    vertical.write(servidor.arg("v").toInt());
  }

}