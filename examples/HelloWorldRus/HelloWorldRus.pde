/*
  LiquidCrystalRus_I2C_Esp - Hello world with timer

  This example prints a Russian message and updates a second counter.

  Author: Artyom + ChatGPT (2025)
*/

#include <LiquidCrystalRus_I2C_Esp.h>

LiquidCrystalRus_I2C_Esp lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.printRus("Привет, мир!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
  delay(500);
}
