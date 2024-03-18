#ifndef AlertLogic_h
#define AlertLogic_h

#include <WiFi.h>
#include "wh_ntp.h"
#include "alert_api.h"
#include "music.h"

#define PIN_BUZZER 18
#define PIN_LED_RED 13
#define PIN_LED_GREEN 12

#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

#define API_URL "YOUR_SERVICE_URL"
#define API_KEY "YOUR_API_KEY"

#define LED_RED_DELAY_ON 300
#define LED_RED_DELAY_OFF 300
#define LED_GREEN_DELAY_ON 50
#define LED_GREEN_DELAY_OFF 3000

#define LOGIC_DELAY 30000

typedef struct {
	unsigned long blinkTimeDealyOn;
	unsigned long blinkTimeDealyOff;
	bool status;
	int pin;
} Led;

class AlertLogic {
public:
	AlertLogic();
	
	void Init();
	void Tick();
private:
	void SetAlert(bool alert, bool firstTime = false);
	void processAlert();
	
	WhNTP *whNTP = NULL;
	Music music = Music(PIN_BUZZER);
	AlertAPI alertAPI;
	
	Led leds[2] = {{LED_GREEN_DELAY_ON, LED_GREEN_DELAY_OFF, false, PIN_LED_GREEN}, {LED_RED_DELAY_ON, LED_RED_DELAY_OFF, false, PIN_LED_RED}};
	unsigned long lastTime = 0;
	unsigned long lastLedTime = 0;
	bool alertStatus = false;
	bool prevAlertStatus = false;
};

#endif