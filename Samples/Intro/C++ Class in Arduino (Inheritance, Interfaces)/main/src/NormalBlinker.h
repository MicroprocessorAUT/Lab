#pragma once

#include "Blinker.h"

class NormalBlinker : public Blinker {
  public:
    NormalBlinker(int ledPin);
    
    void alertBlink();
};