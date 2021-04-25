#include <Arduino.h>

/*#include "MD_MAX72xx.h"
#include "MD_Parola.h"
#include <SPI.h>


#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 2

#define DATA_PIN 3
#define CLK_PIN 4
//MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  // Intialize the object:
  myDisplay.begin();
  // Set the intensity (brightness) of the display (0-15):
  myDisplay.setIntensity(0);
  // Clear the display:
  myDisplay.displayClear();
}
void loop() {
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.print("Center");
  delay(2000);
  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("Left");
  delay(2000);
  myDisplay.setTextAlignment(PA_RIGHT);
  myDisplay.print("Right");
  delay(2000);
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.setInvert(true);
  myDisplay.print("Invert");
  delay(2000);
  myDisplay.setInvert(false);
  myDisplay.print(1234);
  delay(2000);
}*/

#include <FC16.h>
//Conexao do pino CS
const int csPin = D4;
//Numero de displays que estamos usando
const int numDisp = 4;
//Tempo do scroll em milisegundos
const int scrollDelay = 250;
FC16 display = FC16(csPin, numDisp);
void setup() 
{
  //Inicializa o display
 display.begin();
  //Intensidade / Brilho
 display.setIntensity(8);
  //Apaga o display
 display.clearDisplay();
 //Texto a ser exibido no display
 display.setText("x10 Hello!! x11");
}
void loop() 
{
 //Chama a rotina de scroll
 display.update();
 //Aguarda o tempo definido
 delay(scrollDelay);
}