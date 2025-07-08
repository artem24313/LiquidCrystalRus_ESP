/*
  LiquidCrystalRus_I2C_Esp - WH1601 welcome

  Example for Russian I2C LCD with WH1601-compatible logic

  WARNING: setDRAMModel() is for parallel displays and not used here.
*/

#include <LiquidCrystalRus_I2C_Esp.h>

LiquidCrystalRus_I2C_Esp lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.printRus("Привет, мужики!");
}

void loop() {}
