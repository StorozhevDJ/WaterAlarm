#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>


#include "config/HWConfig.h"

#include "Waterbot.h"
#include "WaterDetector.h"


WaterDetector waterDetector;
Waterbot waterbot;


void setup() {
  Serial.begin(115200);

  try {
    waterbot.begin();
    waterbot.connect();
  } catch (const char *e) {
    Serial.print(e);
  }
waterbot.sendAlarm();
waterbot.sendBatteryLevel(batteryStatusCheck());
}

void loop() {
  // Sleep
  ESP.deepSleep(10 * 10);
  waterbot.sendAlarm();
  
}


/**
 * Checking the Battery charge level and sending message if level is low
 */
int batteryStatusCheck() {
  int sensorValue = analogRead(batteryCheckPin);
  return sensorValue;
}