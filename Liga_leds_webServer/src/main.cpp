#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "webPage.h"


#define LEDVERDE D0
#define LEDAZUL D2

ESP8266WebServer server;

const char* ssid     = "Seu_Wifi";
const char* password = "Sua_Senha";

//Funções dos requests
void verdeOn()
{
  digitalWrite(LEDVERDE,HIGH);
}

void verdeOff()
{
  digitalWrite(LEDVERDE,LOW);
}

void azulOn()
{
  digitalWrite(LEDAZUL,HIGH);
}

void azulOff()
{
  digitalWrite(LEDAZUL,LOW);
}

void setup()
{
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAZUL, OUTPUT);

  WiFi.begin(ssid,password);
  Serial.begin(115200);

  while(WiFi.status()!=WL_CONNECTED)//Enquanto a conexão não é realizada
  {
    Serial.print(".");
    delay(500);
  }

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  //Definições das ações a serem tomadas quando as requisiões forem feitas.
  server.on("/liga1",azulOn);
  server.on("/desliga1",azulOff);
  server.on("/liga2",verdeOn);
  server.on("/desliga2",verdeOff);
  server.begin();
}


void loop()
{
  server.send(200,"text/html", pageCode);//Imprime a página web no servidor
  server.handleClient();
}

