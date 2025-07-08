// ======================= LiquidCrystalRus_I2C_Esp32.cpp =======================
#include "LiquidCrystalRus_I2C_Esp.h"

LiquidCrystalRus_I2C_Esp32::LiquidCrystalRus_I2C_Esp32(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows)
  : lcd(lcd_Addr, lcd_cols, lcd_rows) {}

void LiquidCrystalRus_I2C_Esp32::begin() {
  #if defined(ESP32)
  Wire.begin(21, 22);
#elif defined(ESP8266)
  Wire.begin(4, 5); // D2=SDA, D1=SCL на большинстве ESP8266
#else
  Wire.begin(); // универсальный случай
#endif

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void LiquidCrystalRus_I2C_Esp32::clear() {
  lcd.clear();
}

void LiquidCrystalRus_I2C_Esp32::home() {
  lcd.home();
}

void LiquidCrystalRus_I2C_Esp32::setCursor(uint8_t col, uint8_t row) {
  lcd.setCursor(col, row);
}

void LiquidCrystalRus_I2C_Esp32::backlight() {
  lcd.backlight();
}

void LiquidCrystalRus_I2C_Esp32::noBacklight() {
  lcd.noBacklight();
}

void LiquidCrystalRus_I2C_Esp32::display() {
  lcd.display();
}

void LiquidCrystalRus_I2C_Esp32::noDisplay() {
  lcd.noDisplay();
}

void LiquidCrystalRus_I2C_Esp32::printRus(const char* str) {
  while (*str) {
    write(*str++);
  }
}

void LiquidCrystalRus_I2C_Esp32::printRus(const String& str) {
  for (uint16_t i = 0; i < str.length(); i++) {
    write(str[i]);
  }
}

void LiquidCrystalRus_I2C_Esp32::printRusFlash(const __FlashStringHelper* str) {
  PGM_P p = reinterpret_cast<PGM_P>(str);
  while (true) {
    char c = pgm_read_byte(p++);
    if (c == 0) break;
    write(c);
  }
}

void LiquidCrystalRus_I2C_Esp32::createChar(uint8_t location, uint8_t charmap[]) {
  lcd.createChar(location, charmap);
}

void LiquidCrystalRus_I2C_Esp32::scrollText(const char* str, uint8_t row, uint16_t delayMs) {
  uint8_t len = strlen(str);
  if (len <= 16) {
    setCursor(0, row);
    printRus(str);
    return;
  }
  for (uint8_t i = 0; i <= len - 16; i++) {
    setCursor(0, row);
    for (uint8_t j = 0; j < 16; j++) {
      write(str[i + j]);
    }
    delay(delayMs);
  }
}

size_t LiquidCrystalRus_I2C_Esp32::write(uint8_t value) {
  static const uint8_t table[] = {
    0x41, 0xA0, 0x42, 0xA1, 0xE0, 0x45, 0xA3, 0xA4,
    0xA5, 0xA6, 0x4B, 0xA7, 0x4D, 0x48, 0x4F, 0xA8,
    0x50, 0x43, 0x54, 0xA9, 0xAA, 0x58, 0xE1, 0xAB,
    0xAC, 0xE2, 0xAD, 0xAE, 0x62, 0xAF, 0xB0, 0xB1,
    0x61, 0xB2, 0xB3, 0xB4, 0xE3, 0x65, 0xB6, 0xB7,
    0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0x6F, 0xBE
  };

  if (utf_hi_char >= 0) {
    if (value >= 0xC0 || value < 0x80) {
      lcd.write(0xD0 + utf_hi_char);
      lcd.write(value);
    } else {
      value &= 0x3F;
      if (!utf_hi_char && (value == 1)) {
        lcd.write(0xA2); // Ё
      } else if ((utf_hi_char == 1) && (value == 0x11)) {
        lcd.write(0xB5); // ё
      } else {
        lcd.write(table[value]);
      }
    }
    utf_hi_char = -1;
  } else if (value >= 0xD0 && value < 0xD2) {
    utf_hi_char = value - 0xD0;
  } else {
    lcd.write(value);
  }

  return 1;
}
