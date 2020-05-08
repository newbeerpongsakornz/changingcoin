#include <Keypad_I2C.h>
#include <Keypad.h>
#include <Wire.h>
#define I2CADDR 0x20

#include "counter.h"
#include "numpad.h"

int must_input_number = 1;

int red = D3;
int green = D4;

// -------------------------------------------------
//                      Setup
// -------------------------------------------------
void setup() {
  Serial.begin(115200);
  setupCounter();
  setupKeypad();
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.println("Input your number");
}


// -------------------------------------------------
//                      Loop
// -------------------------------------------------
void loop() {
  if (must_input_number)
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    keyInput();
    if (complete_input)
    {
      must_input_number = 0;
      Serial.print("Money is ");
      Serial.println(can_pay);
    }
  }
  else if (complete_input)
  {
    keyReset();
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    must_input_number = 0;
    checkCoin(can_pay);
    if (complete_insert)
    {
      complete_input = 0;
    }
  }
  else if (complete_insert)
  {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    Serial.println("Complete");
    complete_insert = 0;
    delay(5000);
    ESP.restart();
  }
  
}
