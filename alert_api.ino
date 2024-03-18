#include "alert_api.h"

AlertAPI::AlertAPI(char* url, char *key){
	this->apiUrl = url;
	this->apiKey = key;
}

int AlertAPI::IsAlert(){
	HTTPClient http;

	http.begin(this->apiUrl);
	http.addHeader("X-API-Key", this->apiKey);

	int httpResponseCode = http.GET();

	if (httpResponseCode > 0) {
		#ifdef DEBUG
		Serial.print("HTTP Response code: ");
		Serial.println(httpResponseCode);
		#endif

		String payload = http.getString();
		#ifdef DEBUG
		Serial.println(payload);
		#endif

		http.end();

		StaticJsonDocument<128> jsonResponse;
		deserializeJson(jsonResponse, payload);

		bool is_alert = jsonResponse["alert"];

		if(is_alert){
			#ifdef DEBUG
			Serial.println("alert");
			#endif
			return 1;
		}

		#ifdef DEBUG
		Serial.println("no alert");
		#endif
		return 0;
	}

	http.end();
	#ifdef DEBUG
	Serial.println("No response from the server");
	#endif
	return 2;
}