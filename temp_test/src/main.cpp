#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <EEPROM.h>

// LED RGB
int ledr = 4;
define ledr, OUTPUT;

// LCD DISPLAY
LiquidCrystal_I2C lcd(0x27, 16, 2);

// SENSOR
const int oneWireBus = 12;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

// Constants definition EEPROM
#define EEPROM_SIZE 4096

int timeAddress = 100;
float lastTemperature = 0;

void readData();

void setup() {
  Wire.begin(8, 9);
  pinMode(ledr, OUTPUT);
  lcd.init();
  lcd.backlight();
  sensors.begin();
  EEPROM.begin(EEPROM_SIZE);
  lastTemperature = EEPROM.readFloat(timeAddress);
  readData();
}

void loop() {
  readData();
  delay(1000); // Delay for 10 seconds before reading data again
}

void readData() {
  sensors.requestTemperatures();
  float currentTemperature = sensors.getTempCByIndex(0);
  EEPROM.writeFloat(timeAddress, currentTemperature);
  EEPROM.commit();

  float difference = currentTemperature - lastTemperature;

  lcd.setCursor(0, 2);
  lcd.print("Difference: ");
  lcd.print(difference);

  if (difference >= 2 || difference <= -2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ALERTA");
    digitalWrite(ledr, HIGH);
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("all good");
    digitalWrite(ledr, LOW);
  }

  lastTemperature = currentTemperature;
}
 