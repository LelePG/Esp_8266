#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "webPage.h"


ESP8266WebServer server;
uint8_t pin_led = D0;
uint8_t pin_led2 = D2;
const char* ssid     = "Seu_Wifi";
const char* password = "Sua_Senha";


void liga1()
{
  digitalWrite(pin_led,HIGH);
}

void desliga1()
{
  digitalWrite(pin_led,LOW);
}

void liga2()
{
  digitalWrite(pin_led2,HIGH);
}

void desliga2()
{
  digitalWrite(pin_led2,LOW);
}

char webpage[] PROGMEM = R"=====(
<html>
<head>
</head>
<body>
<p> LED Status: <span id="led-state">__</span> </p>
<button onclick="myFunction()"> TOGGLE </button>
</body>
<script>
function myFunction()
{
  console.log("button was clicked!");
  var xhr = new XMLHttpRequest();
  var url = "/liga";
  
  xhr.open("POST", url, true);
  xhr.send();
};
document.addEventListener('DOMContentLoaded', myFunction, false);
</script>
</html>
)=====";

void setup()
{
  pinMode(pin_led, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  
  server.on("/liga1",liga1);
  server.on("/desliga1",desliga1);
  server.on("/liga2",liga2);
  server.on("/desliga2",desliga2);
  server.begin();
}


void loop()
{
  server.send(200,"text/html", pageCode);//Imprime a página web no servidor
  server.handleClient();
}

