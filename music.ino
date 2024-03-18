#include "music.h"

Music::Music(int pinBuzzer){
	this->pinBuzzer = byte(pinBuzzer);
}

void Music::Play(int melody[], int delays[], int length, float delay_multi){
	for (int thisNote = 0; thisNote < length; thisNote++) {
		int noteDuration = (delays[thisNote] * delay_multi);
		if(melody[thisNote] != 0)
			tone(this->pinBuzzer, melody[thisNote], noteDuration);

		int pauseBetweenNotes = noteDuration * 1.30;
		delay(pauseBetweenNotes);
		noTone(this->pinBuzzer);
	}
}

void Music::PlayAlertOn(){
	this->Play(melody_alert_on, delay_alert_on, MELODY_LENGTH_ALERT_ON, 0.8);
}

void Music::PlayAlertOff(){
	this->Play(melody_alert_off, delay_alert_off, MELODY_LENGTH_ALERT_OFF, 1.5);
}