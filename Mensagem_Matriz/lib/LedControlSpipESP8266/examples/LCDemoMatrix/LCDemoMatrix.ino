//We always have to include the library
#include <SPI.h>
#include "LedControlSPIESP8266.h"

/* needs at least a 8X8 dot matrix! Up to 8 can be cascaded*/

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 Pinout sur NodeMCU 
 D5 = GPIO14 = Clk   is connected to CLK  [pin 13 on max7219]
 D7 = GPIO13 = MOSI  is connected to DATA in [pin 1 on max7219]
 D8 = GPIO15 = SS    is connected to LOAD [pin 12 on max7219]
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(15,1); // Load pin, number of LED displays

/* we always wait a bit between updates of the display */
unsigned long delaytime=100;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  /* here is the data for the characters 
  byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
  byte r[5]={B00111110,B00010000,B00100000,B00100000,B00010000};
  byte d[5]={B00011100,B00100010,B00100010,B00010010,B11111110};
  byte u[5]={B00111100,B00000010,B00000010,B00000100,B00111110};
  byte i[5]={B00000000,B00100010,B10111110,B00000010,B00000000};
  byte n[5]={B00111110,B00010000,B00100000,B00100000,B00011110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};*/

  /* here is the data for the characters */  
  byte a[8]={0x04, 0x0A, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x00}; // A
  byte r[8]={0x00, 0x00, 0x0D, 0x13, 0x01, 0x01, 0x01, 0x00}; // r
  byte d[8]={0x10, 0x10, 0x16, 0x19, 0x11, 0x19, 0x16, 0x00}; // d
  byte u[8]={0x00, 0x00, 0x11, 0x11, 0x11, 0x19, 0x16, 0x00}; // u
  byte i[8]={0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x00}; // i
  byte n[8]={0x00, 0x00, 0x0D, 0x13, 0x11, 0x11, 0x11, 0x00}; // n
  byte o[8]={0x00, 0x00, 0x06, 0x09, 0x09, 0x09, 0x06, 0x00}; // o
  
  /* now display them one by one with a small delay */
  lc.setRow(0,7,a[0]);
  lc.setRow(0,6,a[1]);
  lc.setRow(0,5,a[2]);
  lc.setRow(0,4,a[3]);
  lc.setRow(0,3,a[4]);
  lc.setRow(0,2,a[5]);
  lc.setRow(0,1,a[6]);
  lc.setRow(0,0,a[7]);
  delay(delaytime*4);
  lc.setRow(0,7,r[0]);
  lc.setRow(0,6,r[1]);
  lc.setRow(0,5,r[2]);
  lc.setRow(0,4,r[3]);
  lc.setRow(0,3,r[4]);
  lc.setRow(0,2,r[5]);
  lc.setRow(0,1,r[6]);
  lc.setRow(0,0,r[7]);
  delay(delaytime*4);
  lc.setRow(0,7,d[0]);
  lc.setRow(0,6,d[1]);
  lc.setRow(0,5,d[2]);
  lc.setRow(0,4,d[3]);
  lc.setRow(0,3,d[4]);
  lc.setRow(0,2,d[5]);
  lc.setRow(0,1,d[6]);
  lc.setRow(0,0,d[7]);
  delay(delaytime*4);
  lc.setRow(0,7,u[0]);
  lc.setRow(0,6,u[1]);
  lc.setRow(0,5,u[2]);
  lc.setRow(0,4,u[3]);
  lc.setRow(0,3,u[4]);
  lc.setRow(0,2,u[5]);
  lc.setRow(0,1,u[6]);
  lc.setRow(0,0,u[7]);
  delay(delaytime*4);
  lc.setRow(0,7,i[0]);
  lc.setRow(0,6,i[1]);
  lc.setRow(0,5,i[2]);
  lc.setRow(0,4,i[3]);
  lc.setRow(0,3,i[4]);
  lc.setRow(0,2,i[5]);
  lc.setRow(0,1,i[6]);
  lc.setRow(0,0,i[7]);
  delay(delaytime*4);
  lc.setRow(0,7,n[0]);
  lc.setRow(0,6,n[1]);
  lc.setRow(0,5,n[2]);
  lc.setRow(0,4,n[3]);
  lc.setRow(0,3,n[4]);
  lc.setRow(0,2,n[5]);
  lc.setRow(0,1,n[6]);
  lc.setRow(0,0,n[7]);
  delay(delaytime*4);
  lc.setRow(0,7,o[0]);
  lc.setRow(0,6,o[1]);
  lc.setRow(0,5,o[2]);
  lc.setRow(0,4,o[3]);
  lc.setRow(0,3,o[4]);
  lc.setRow(0,2,o[5]);
  lc.setRow(0,1,o[6]);
  lc.setRow(0,0,o[7]);
  delay(delaytime*4);
  lc.setRow(0,7,0);
  lc.setRow(0,6,0);
  lc.setRow(0,5,0);
  lc.setRow(0,4,0);
  lc.setRow(0,3,0);
  lc.setRow(0,2,0);
  lc.setRow(0,1,0);
  lc.setRow(0,0,0);
  delay(delaytime*4);
}

/*
  This function lights up a some Leds in a row.
 The pattern will be repeated on every row.
 The pattern will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void rows() {
  for(int row=0;row<8;row++) {
    delay(delaytime);
    lc.setRow(0,row,B10100000);
    delay(delaytime);
    lc.setRow(0,row,(byte)0);
    for(int i=0;i<row;i++) {
      delay(delaytime);
      lc.setRow(0,row,B10100000);
      delay(delaytime);
      lc.setRow(0,row,(byte)0);
    }
  }
}

/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */
void columns() {
  for(int col=0;col<8;col++) {
    delay(delaytime);
    lc.setColumn(0,col,B10100000);
    delay(delaytime);
    lc.setColumn(0,col,(byte)0);
    for(int i=0;i<col;i++) {
      delay(delaytime);
      lc.setColumn(0,col,B10100000);
      delay(delaytime);
      lc.setColumn(0,col,(byte)0);
    }
  }
}

/* 
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void single() {
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(delaytime);
      lc.setLed(0,row,col,true);
      delay(delaytime);
      for(int i=0;i<col;i++) {
        lc.setLed(0,row,col,false);
        delay(delaytime);
        lc.setLed(0,row,col,true);
        delay(delaytime);
      }
    }
  }
}

void loop() { 
  writeArduinoOnMatrix();
  rows();
  columns();
  single();
}