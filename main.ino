#include <time.h>
#include "alert_logic.h"

#define DEBUG

AlertLogic alertLogic;

void setup() {
	Serial.begin(115200);

	alertLogic = AlertLogic();
	alertLogic.Init();
}

void loop() {
	alertLogic.Tick(); 
}