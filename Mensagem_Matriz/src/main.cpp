#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FC16.h>

#include "paginaWeb.h"

#define pinoCS D4
#define qtDisplays 4
#define scrollDelay 250
#define buzzer D2

#define SSID "seu_Wifi"
#define SENHA "sua_Senha"

ESP8266WebServer servidor;

FC16 matriz = FC16(pinoCS, qtDisplays);

void imprimeMensagem (void){
  if (servidor.hasArg("m")){
      matriz.clearDisplay();
      const char * mensagem = servidor.arg("m").c_str();//servidor.arg() retorna uma string e c_str transforma em array de char
      matriz.setText(mensagem);
  }
  tone(buzzer,1300);
  delay(1500);
  noTone(buzzer);
}

void setup() {
  pinMode(buzzer,OUTPUT);

  WiFi.begin(SSID,SENHA);
  Serial.begin(115200);

  while(WiFi.status()!=WL_CONNECTED){//Enquanto a conexão não é realizada
    Serial.print(".");
    delay(500);
  }

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());//Ip onde tenho que me conectar

  matriz.begin();
  matriz.setIntensity(8);
  matriz.clearDisplay();

  servidor.on("/mensagem", HTTP_GET, imprimeMensagem);
  servidor.begin();
}

void loop() {
  servidor.send(200,"text/html", codigoWeb);
  servidor.handleClient();  
  matriz.update();
  delay(scrollDelay);

}