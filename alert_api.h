#ifndef AlertAPI_h
#define AlertAPI_h

#include <HTTPClient.h>
#include <ArduinoJson.h>

class AlertAPI {
public:
	AlertAPI(char* url, char *key);

	int IsAlert();
 
private:
	char* apiUrl;
	char* apiKey;

};

#endif