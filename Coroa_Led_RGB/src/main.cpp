#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Coroa.h"

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

servidor.on("/azul",azul);
servidor.on("/aqua",aqua);
servidor.on("/verde-primavera",vprimavera);
servidor.on("/verde",verde);
servidor.on("/lilas",lilas);
servidor.on("/azul-violeta",azulVioleta);
servidor.on("/magenta",magenta);
servidor.on("/rosa",rosa);
servidor.on("/vermelho",vermelho);
servidor.on("/branco",branco);
servidor.begin();
}

void loop() {
  coloreLED(16,176,200);
  servidor.send(200,"text/html", tiaraCodigo);//Imprime a página web no servidor
  servidor.handleClient();  

}