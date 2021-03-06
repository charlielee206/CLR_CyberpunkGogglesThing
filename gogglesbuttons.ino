#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16matrix matrix1 = Adafruit_8x16matrix();
Adafruit_8x16matrix matrix2 = Adafruit_8x16matrix();
Adafruit_8x16matrix matrix3 = Adafruit_8x16matrix();
Adafruit_8x16matrix matrix4 = Adafruit_8x16matrix();

const int button = 6;

int state = 0;
int mode = 0;


void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);

  matrix3.begin(0x74);
  matrix4.begin(0x72);
  matrix1.begin(0x70);
  matrix2.begin(0x71);


  matrix1.clear();
  matrix2.clear();
  matrix3.clear();
  matrix4.clear();

}

static const uint8_t PROGMEM
oh1_bmp[] =
{ B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00010000,
  B00010010,
  B01111101,
  B00010000,
  B00111100,
  B01010010,
  B01010010,
  B00100110,
  B00000000,
  B00000000,
  B00000000,
  B00000000
},

oh3_bmp[] =
{ B00000000,
  B00000000,
  B00000000,
  B00000000,
  B01000010,
  B01000010,
  B01001111,
  B01000010,
  B01000010,
  B01001110,
  B01010011,
  B01001110,
  B00000000,
  B00000000,
  B00000000,
  B00000000
},


oh5_bmp[] =
{ B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00001000,
  B00001000,
  B00001110,
  B00001000,
  B00001000,
  B00111100,
  B01001010,
  B00110000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
},

oh7_bmp[] =
{ B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00111000,
  B00000000,
  B00111000,
  B01000100,
  B00000100,
  B00000100,
  B00011000,
  B00100000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
},


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
  B00000000
},

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
  B00000000,
};



void loop() {

  state = digitalRead(button);

  if (state == LOW)
  {
    delay (500);
    mode++;
    if (mode >= 3)
    {
      mode = 0;
    }
  }


  Serial.println(mode);


  if (mode == 0)
  {
    matrix1.clear();
    matrix2.clear();
    matrix3.clear();
    matrix4.clear();

    matrix1.drawBitmap(0, 0, oh1_bmp, 8, 16, LED_ON);
    matrix1.writeDisplay();

    matrix2.drawBitmap(0, 0, oh3_bmp, 8, 16, LED_ON);
    matrix2.writeDisplay();

    matrix3.drawBitmap(0, 0, oh5_bmp, 8, 16, LED_ON);
    matrix3.writeDisplay();

    matrix4.drawBitmap(0, 0, oh7_bmp, 8, 16, LED_ON);
    matrix4.writeDisplay();
  }

  if (mode == 1)
  {
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
  }

  if (mode == 2)
  {

    matrix1.clear();
    matrix2.clear();
    matrix3.clear();
    matrix4.clear();

    matrix1.setTextSize(1);
    matrix1.setTextWrap(false);
    matrix1.setTextColor(LED_ON);

    matrix2.setTextSize(1);
    matrix2.setTextWrap(false);
    matrix2.setTextColor(LED_ON);
    matrix2.clear();
    matrix1.setCursor(2, 5);
    matrix1.print("T");
    matrix1.writeDisplay();

    matrix2.clear();
    matrix2.setCursor(1, 5);
    matrix2.print("T");
    matrix2.writeDisplay();

    matrix4.setTextSize(1);
    matrix4.setTextWrap(false);
    matrix4.setTextColor(LED_ON);

    matrix3.setTextSize(1);
    matrix3.setTextWrap(false);
    matrix3.setTextColor(LED_ON);
    matrix3.clear();
    matrix3.setCursor(2, 5);
    matrix3.print("T");
    matrix3.writeDisplay();

    matrix4.clear();
    matrix4.setCursor(1, 5);
    matrix4.print("T");
    matrix4.writeDisplay();
  }

}
