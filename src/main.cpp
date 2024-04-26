#include <Arduino.h>
#include <Servo.h>
#include "ESP32Wiimote.h"

#define servoPin  GPIO_NUM_4

Servo myServo;
ESP32Wiimote wiimote;

int wheel = 0;

void setup()
{
    Serial.begin(115200);
    myServo.attach(servoPin);
    wiimote.init();
}

void loop()
{
  wiimote.task();
  wheel = 0;
  if (wiimote.available() > 0) 
  {
    AccelState   accel   = wiimote.getAccelState();
    wheel = map(accel.yAxis, 101, 152, 0, 180);
    myServo.write(wheel);
    Serial.print(wheel);
    Serial.print(" ");
  }
}