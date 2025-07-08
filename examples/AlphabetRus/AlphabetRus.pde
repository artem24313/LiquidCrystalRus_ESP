/*
  LiquidCrystalRus_I2C_Esp - Пример вывода русского алфавита

  Подключение (для I2C LCD):
  * SDA -> GPIO21
  * SCL -> GPIO22
  * Питание дисплея: VCC -> 5V, GND -> GND
  * Контраст — резистор между VO и GND или фиксированным делителем

  Автор оригинала: Ilya V. Danilov http://mk90.ru/
  Адаптация для ESP32 и I2C: ChatGPT, 2025
*/

#include <LiquidCrystalRus_I2C_Esp.h>

// Адрес по умолчанию — 0x27, 16 колонок, 2 строки
LiquidCrystalRus_I2C_Esp lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
}

void loop() {
  lcd.printRus("АБВГДЕЁЖЗИЙКЛМНО");
  delay(3000);
  lcd.clear();

  lcd.printRus("ПРСТУФХЦЧШЩЪЫЬЭЮ");
  delay(3000);
  lcd.clear();

  lcd.printRus("Я");
  delay(3000);
  lcd.clear();

  lcd.printRus("абвгдеёжзийклмно");
  delay(3000);
  lcd.clear();

  lcd.printRus("прстуфхцчшщъыьэю");
  delay(3000);
  lcd.clear();

  lcd.printRus("я");
  delay(3000);
  lcd.clear();
}
