#ifndef WH_NTP_h
#define WH_NTP_h

#include <NTPClient.h>
#include <WiFiUdp.h>

#define OPERATIONAL_HOURS_START 0
#define OPERATIONAL_HOURS_END 24
#define OPERATIONAL_DAYS_START 1
#define OPERATIONAL_DAYS_END 5

#define NTP_UPDATE_TIME	600000
#define MAX_NTP_RETRIES 5

#define TIME_ZONE_OFFSET 7200

class WhNTP {
public:
	WhNTP();
	
	bool Update();
	bool IsOperational();
	
private:
	unsigned long lastUpdate = 0;
	bool isOperational = false;
	bool success = false;

	WiFiUDP ntpUDP;
	NTPClient timeClient;
};

#endif