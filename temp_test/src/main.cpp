#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
//high led red with delay//****

int ledr = 4;

void setup()
{
  pinMode(ledr, OUTPUT);
  //para prender el led se necesita la funcion digitalWrite(pin, value);
  while (true)
  {
    digitalWrite(ledr, HIGH);
    delay(2000);
    digitalWrite(ledr, LOW);
    delay(2000);
  }
}

void loop(){}
