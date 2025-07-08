/*
  LiquidCrystalRus_I2C_Esp - Displaying full LCD charset (0x00 - 0xFF)

  This example shows the contents of the CGROM of a 16x2 I2C LCD with Russian mapping.

  Connections (ESP32):
   * SDA -> GPIO21
   * SCL -> GPIO22
   * VCC -> 5V
   * GND -> GND
*/

#include <LiquidCrystalRus_I2C_Esp.h>

LiquidCrystalRus_I2C_Esp lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
}

void loop() {
  char c[17];
  c[16] = '\0';
  for (int i = 0; i < 16; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("0x");
    lcd.print(i * 16, HEX);
    lcd.print(" - 0x");
    lcd.print(i * 16 + 15, HEX);
    for (int k = 0; k < 16; k++) {
      c[k] = i * 16 + k;
    }
    lcd.setCursor(0, 1);
    lcd.print(c);
    delay(3000);
  }
}
