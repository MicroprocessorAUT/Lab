#pragma once

#include "Blinker.h"

class SecurityBlinker : public Blinker {
  public:
    SecurityBlinker(int ledPin);
    
	void alertBlink();
};
