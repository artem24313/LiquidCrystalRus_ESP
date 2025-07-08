// ======================= LiquidCrystalRus_I2C_Esp.h =======================
#ifndef LiquidCrystalRus_I2C_Esp_h
#define LiquidCrystalRus_I2C_Esp_h

#include <Arduino.h>
#include <Wire.h>
#include <Print.h>
#include <LiquidCrystal_I2C.h>

class LiquidCrystalRus_I2C_Esp : public Print {
  public:
    LiquidCrystalRus_I2C_Esp(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows);
    void begin();
    void clear();
    void home();
    void setCursor(uint8_t col, uint8_t row);
    void backlight();
    void noBacklight();
    void display();
    void noDisplay();
    void printRus(const char* str);
    void printRus(const String& str);
    void printRusFlash(const __FlashStringHelper* str);
    void createChar(uint8_t location, uint8_t charmap[]);
    void scrollText(const char* str, uint8_t row, uint16_t delayMs = 300);

    virtual size_t write(uint8_t);
    using Print::write;

  private:
    LiquidCrystal_I2C lcd;
    void processUTF8(uint8_t c);
    int8_t utf_hi_char = -1;
};

#endif
