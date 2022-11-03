#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

#include "config/WaterbotConfig.h"

#include "Waterbot.h"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);


void Waterbot::begin() {
  // Attempt to connect to Wifi network:
  Serial.print("Connecting to Wifi: ");
  Serial.println(SSID);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);

  for (char i = 0; i++; i < 20) {
    if (WiFi.status() == WL_CONNECTED) break;
    delay(500);
    Serial.print(".");
  }
  if (WiFi.status() != WL_CONNECTED) throw("Not connected error: " + (WiFi.status() | 0x30));

  Serial.println("");
  Serial.print("WiFi connected ");
  // Print the IP address
  Serial.println(WiFi.localIP());
}

void Waterbot::connect() {
  bot =  UniversalTelegramBot(BOTtoken, client);
  client.setInsecure();
}

void Waterbot::sendAlarm() {
  bot.sendMessage(CHAT_ID, "Обнаружена протечка!!!", "");
}

void Waterbot::sendBatteryLevel(unsigned int level) {
bot.sendMessage(CHAT_ID, "Battery: " + String(level, DEC), "");
}