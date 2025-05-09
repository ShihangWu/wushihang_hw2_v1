#include <Arduino.h>

// 定义使用的 GPIO 引脚
const int ledPins[] = {2, 4, 5, 12, 13, 14};
const int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  // 设置所有引脚为输出，并初始设为 LOW
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  // 遍历所有引脚，每次只亮一个
  for (int i = 0; i < ledCount; i++) {
    // 先熄灭所有灯
    for (int j = 0; j < ledCount; j++) {
      digitalWrite(ledPins[j], LOW);
    }
    // 点亮当前灯
    digitalWrite(ledPins[i], HIGH);
    delay(500);
  }
}

