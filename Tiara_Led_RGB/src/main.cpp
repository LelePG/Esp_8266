#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Tiara.h"

#define RED D0
#define GREEN D1
#define BLUE D2

#define SSID "Seu_SSID"
#define SENHA "SUA_SENHA"

void coloreLED(int redQ, int greenQ, int blueQ) {
  analogWrite(RED, redQ);
  analogWrite(GREEN, greenQ);
  analogWrite(BLUE, blueQ);
}

void azul(){coloreLED(0,0,255);}
void aqua(){coloreLED(0,255,255);}
void vprimavera(){coloreLED(0,255,127);}
void verde(){coloreLED(0,255,0);}
void lilas(){coloreLED(123,104,238);}
void azulVioleta(){coloreLED(138,43,226);}
void magenta(){coloreLED(255,0,255);}
void rosa(){coloreLED(255,20,147);}
void vermelho(){coloreLED(255,0,0);}
void branco(){coloreLED(255,255,255);}


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

server.on("/azul",azul);
server.on("/aqua",aqua);
server.on("/VP",vprimavera);
server.on("/Verde",verde);
server.on("/lilas",lilas);
server.on("/blue-violet",azulVioleta);
server.on("/magenta",magenta);
server.on("/rosa",rosa);
server.on("/vermelho",vermelho);
server.on("/branco",branco);
server.begin();

void loop() {
  server.send(200,"text/html", tiaraCodigo);//Imprime a página web no servidor
  server.handleClient();  

}