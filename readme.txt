# LiquidCrystalRus_ESP

Библиотека для отображения текста на русском языке на LCD-дисплеях 16x2/20x4 с интерфейсом I2C. Поддерживает микроконтроллеры **ESP32** и **ESP8266**. Основана на `LiquidCrystal_I2C` с добавлением поддержки кодировки UTF-8 и псевдографики для кириллицы.

---

## 🔧 Подключение

| LCD Pin | Подключение к ESP |
|--------:|------------------:|
| SDA     | GPIO21 (ESP32) / GPIO4 (ESP8266) |
| SCL     | GPIO22 (ESP32) / GPIO5 (ESP8266) |
| VCC     | 3.3V или 5V       |
| GND     | GND               |

---

## 🚀 Установка

1. Скачай ZIP с [GitHub](https://github.com/artem24313/LiquidCrystalRus_ESP)
2. В Arduino IDE: **Скетч > Подключить библиотеку > Установить ZIP библиотеку**.
3. Выбери путь к скачанному архиву.

---

## ✅ Поддерживаемые платформы

- ✅ ESP32
- ✅ ESP8266

---

## 🔍 Пример

```cpp
#include <LiquidCrystalRus_ESP.h>

LiquidCrystalRus_ESP lcd(0x27, 16, 2); // адрес I2C может быть 0x27 или 0x3F

void setup() {
  lcd.begin();
  lcd.printRus("Привет, мир!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
}
