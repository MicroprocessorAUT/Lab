#include "Alert.h"

Alert::Alert(int inputPin, Blinker* blinker) {
	this->inputPin = inputPin;
	this->blinker = blinker;
}

void Alert::watch() {
	if (digitalRead(inputPin) == HIGH){
		blinker->alertBlink();
	}
	else {
		blinker->off();
	}
}
