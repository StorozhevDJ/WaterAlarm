#ifndef WATER_BOT_
#define WATER_BOT_

class Waterbot {
public:
  void begin();
  void connect();
  void sendAlarm();
  void sendBatteryLevel(unsigned int level);
private:

};

#endif