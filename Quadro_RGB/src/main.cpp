#include <Arduino.h>
#include <ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include "paginaWeb.h"

#define RED D5
#define GREEN D6
#define BLUE D7

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

void handleCor()
{
  if (servidor.hasArg("cor"))
  {
    String corHexa = servidor.arg("cor");
    String r = corHexa.substring(1,corHexa.indexOf(','));
    corHexa = corHexa.substring(corHexa.indexOf(',')+1);
    String g = corHexa.substring(0,corHexa.indexOf(','));
    corHexa = corHexa.substring(corHexa.indexOf(',')+1);
    String b = corHexa.substring(0,corHexa.length()-1);
    coloreLED(r.toInt(),g.toInt(),b.toInt());
    //Serial.println(r + ' ' + g + ' ' + b);
  }
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
servidor.on("/desliga", apagaLED);
servidor.on("/cor", HTTP_GET, handleCor);

servidor.begin();
}

void loop() {
  servidor.send(200,"text/html", codigoRGB);
  servidor.handleClient();  

}