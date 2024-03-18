#include "wh_ntp.h"

WhNTP::WhNTP():ntpUDP(),timeClient(ntpUDP){
	this->timeClient.begin();
	this->timeClient.setTimeOffset(TIME_ZONE_OFFSET);
}

bool WhNTP::IsOperational(){
	return this->isOperational;
}

bool WhNTP::Update(){
	if((millis() - this->lastUpdate) > NTP_UPDATE_TIME || !this->success){
		#ifdef DEBUG
		Serial.println("WhNTP::Update");
		#endif
		int max_retries = MAX_NTP_RETRIES;

		while(!this->timeClient.update() && max_retries > 0){ 
			this->timeClient.forceUpdate();
			max_retries--;
		}
		
		if(max_retries > 0)
		{
			#ifdef DEBUG
			Serial.println("WhNTP::Update success");
			#endif
			this->success = true;
			int currentHour = this->timeClient.getHours();
			int currentDay = this->timeClient.getDay();

			#ifdef DEBUG
			char buffer[128];
			sprintf(buffer, "current time: hour %d: min %d, day %d", currentHour, this->timeClient.getMinutes(), currentDay );
			Serial.println(buffer);
			#endif

			bool tmpIsOperational = false;
			if(currentDay >= OPERATIONAL_DAYS_START && currentDay <= OPERATIONAL_DAYS_END && currentHour >= OPERATIONAL_HOURS_START && currentHour <= OPERATIONAL_HOURS_END)
				tmpIsOperational = true;	

			this->lastUpdate = millis();

			bool has_change = this->isOperational == tmpIsOperational ? true: false;
			this->isOperational = tmpIsOperational;
			#ifdef DEBUG
			sprintf(buffer, "is operational: %d: has change %d", this->isOperational, has_change );
			Serial.println(buffer);
			#endif
			return has_change;
		}
	}

	return false;
}
