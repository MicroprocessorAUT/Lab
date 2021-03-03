#pragma once

#include <Arduino.h>

#include "Blinker.h"

class Alert {
  private:
    int inputPin = -1;
    Blinker* blinker;
    
  public:
    Alert(int inputPin, Blinker* blinker);

    void watch();
};