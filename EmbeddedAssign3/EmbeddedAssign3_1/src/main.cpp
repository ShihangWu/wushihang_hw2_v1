#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH      128   // OLED display width, in pixels
#define SCREEN_HEIGHT     64    // OLED display height, in pixels
#define OLED_RESET        -1    // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS    0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

// 构造对象 连接到I2C(SDA、SCL引脚)的SSD1306声明
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // OLED初始化
  OLED.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  // OLED清除显示
  OLED.clearDisplay();
  // OLED设置光标位置
  OLED.setCursor(1, 1);
  // 设置字体颜色
  OLED.setTextColor(SSD1306_WHITE);
  // 显示字符串内容
  OLED.println("Hello, world!");

  OLED.display();
}

void loop() {
  // put your main code here, to run repeatedly:
}
