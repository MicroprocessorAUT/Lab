#include "NormalBlinker.h"

NormalBlinker::NormalBlinker(int ledPin) : Blinker(ledPin) { }

void NormalBlinker::alertBlink(){
  Blinker::blinkBy(1000);
}