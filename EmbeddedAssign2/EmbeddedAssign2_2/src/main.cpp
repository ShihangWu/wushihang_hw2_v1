#include <Arduino.h>

const char* expected[] = {"AA", "BB", "CC", "DD"}; // 预期的密码序列
int currentStep = 0; // 当前验证步骤

void setup() {
  Serial.begin(9600); // 初始化串口，波特率9600
}

void loop() {
  if (Serial.available() > 0) {
    // 读取一行输入并去除首尾空白字符
    String input = Serial.readStringUntil('\n');
    input.trim();

    // 验证输入是否正确
    if (input == expected[currentStep]) {
      currentStep++; // 进入下一步
      if (currentStep >= 4) { // 所有步骤均正确
        Serial.println("The code is right");
        currentStep = 0; // 重置步骤
      }
    } else {
      Serial.println("The code is wrong");
      currentStep = 0; // 重置步骤
    }
  }
}

