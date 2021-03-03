#include "SecurityBlinker.h"

SecurityBlinker::SecurityBlinker(int ledPin) : Blinker(ledPin) { }

void SecurityBlinker::alertBlink() {
  Blinker::blinkBy(150);
}