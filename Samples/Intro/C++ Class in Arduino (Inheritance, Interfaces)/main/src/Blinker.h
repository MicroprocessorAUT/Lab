#pragma once

#include <Arduino.h>

class Blinker{    
  protected:
    int ledPin = -1;
    
    void blinkBy(int ms);
    
  public:
    Blinker();
    Blinker(int ledPin);
   
    void off();
    virtual void alertBlink();
};
