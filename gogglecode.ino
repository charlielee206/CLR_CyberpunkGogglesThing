#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16matrix matrix1 = Adafruit_8x16matrix();
Adafruit_8x16matrix matrix2 = Adafruit_8x16matrix();
Adafruit_8x16matrix matrix3 = Adafruit_8x16matrix();
Adafruit_8x16matrix matrix4 = Adafruit_8x16matrix();
void setup() {
  Serial.begin(9600);
  Serial.println("16x8 LED Matrix Test");
  
  matrix3.begin(0x74);
  matrix4.begin(0x72);
  matrix1.begin(0x70);
  matrix2.begin(0x71);
  // pass in the address

  matrix1.clear();
  matrix2.clear();

}

static const uint8_t PROGMEM

    smile1_bmp[] =
  { B00000000,
    B00000000,
    B00000000,
    B00000001,
    B00000011,
    B00000011,
    B00000110,
    B00000110,
    B00001110,
    B00001100,
    B00001100,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000 },

    smile2_bmp[] =
  { B00000000,
  B00000000,
  B00000000,
  B00000000,
  B10000000,
  B10000000,
  B11000000,
  B11000000,
  B01100000,
  B01100000,
  B01100000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,},
    
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 };



void loop() {

   
  matrix1.clear();
  matrix2.clear();
  matrix3.clear();
  matrix4.clear();

  matrix1.drawBitmap(0, 0, smile1_bmp, 8, 16, LED_ON);  
  matrix1.writeDisplay();
  
  matrix2.drawBitmap(0, 0, smile2_bmp, 8, 16, LED_ON);  
  matrix2.writeDisplay();

  matrix3.drawBitmap(0, 0, smile1_bmp, 8, 16, LED_ON);  
  matrix3.writeDisplay();

  matrix4.drawBitmap(0, 0, smile2_bmp, 8, 16, LED_ON);  
  matrix4.writeDisplay();
  delay(5000);
  
  matrix1.clear();
  matrix2.clear();
  matrix3.clear();
  matrix4.clear();

matrix1.setTextSize(1);
  matrix1.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix1.setTextColor(LED_ON); 

  matrix2.setTextSize(1);
  matrix2.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix2.setTextColor(LED_ON);
  matrix2.clear();
    matrix1.setCursor(2,5);
    matrix1.print("T");
    matrix1.writeDisplay();
  
    matrix2.clear();
    matrix2.setCursor(1,5);
    matrix2.print("T");
    matrix2.writeDisplay();
  
    matrix4.setTextSize(1);
  matrix4.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix4.setTextColor(LED_ON); 

  matrix3.setTextSize(1);
  matrix3.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix3.setTextColor(LED_ON);
  matrix3.clear();
    matrix3.setCursor(2,5);
    matrix3.print("T");
    matrix3.writeDisplay();
  
    matrix4.clear();
    matrix4.setCursor(1,5);
    matrix4.print("T");
    matrix4.writeDisplay();
    delay(5000);


   matrix1.clear();
  matrix2.clear();
  matrix3.clear();
  matrix4.clear();

matrix1.setTextSize(1);
  matrix1.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix1.setTextColor(LED_ON); 

  matrix2.setTextSize(1);
  matrix2.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix2.setTextColor(LED_ON);
  matrix2.clear();
    matrix1.setCursor(2,5);
    matrix1.print("?");
    matrix1.writeDisplay();
  
    matrix2.clear();
    matrix2.setCursor(1,5);
    matrix2.print("?");
    matrix2.writeDisplay();
  
    matrix4.setTextSize(1);
  matrix4.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix4.setTextColor(LED_ON); 

  matrix3.setTextSize(1);
  matrix3.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix3.setTextColor(LED_ON);
  matrix3.clear();
    matrix3.setCursor(2,5);
    matrix3.print("?");
    matrix3.writeDisplay();
  
    matrix4.clear();
    matrix4.setCursor(1,5);
    matrix4.print("?");
    matrix4.writeDisplay();
    delay(5000);



    
}
