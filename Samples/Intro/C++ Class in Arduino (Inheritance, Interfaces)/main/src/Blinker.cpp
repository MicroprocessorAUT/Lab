#include "Blinker.h"

Blinker::Blinker() { }
Blinker::Blinker(int ledPin) {
  this->ledPin = ledPin;
}

void Blinker::blinkBy(int ms) {
  digitalWrite(ledPin, HIGH);
  delay(ms);
  digitalWrite(ledPin, LOW);
  delay(ms);
}

void Blinker::off(){
  digitalWrite(ledPin , LOW);
}

void Blinker::alertBlink() { blinkBy(500); }