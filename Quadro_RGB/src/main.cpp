#include <Arduino.h>
#include <ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include "paginaWeb.h"

#define RED D0
#define GREEN D1
#define BLUE D2

#define SSID "seu_Wifi"
#define SENHA "sua_Senha"

ESP8266WebServer servidor;

void coloreLED(int redQ, int greenQ, int blueQ) {
  analogWrite(RED, redQ);
  analogWrite(GREEN, greenQ);
  analogWrite(BLUE, blueQ);
}


void acendeLED(void){
  coloreLED(255,255,255);  
}

void apagaLED(void){
  coloreLED(0,0,0);
}

void setup() {
 pinMode(RED,OUTPUT);
 pinMode(GREEN,OUTPUT);
 pinMode(BLUE,OUTPUT);

WiFi.begin(SSID,SENHA);
Serial.begin(115200);

while(WiFi.status()!=WL_CONNECTED)//Enquanto a conexão não é realizada
{
  Serial.print(".");
  delay(500);
}

Serial.print("IP Address: ");
Serial.println(WiFi.localIP());//Ip onde tenho que me conectar

servidor.on("/liga",acendeLED);
servidor.on('/desliga', apagaLED);

servidor.begin();
}

void loop() {
  coloreLED(16,176,200);
  servidor.send(200,"text/html", codigoRGB);//Imprime a página web no servidor
  servidor.handleClient();  

}