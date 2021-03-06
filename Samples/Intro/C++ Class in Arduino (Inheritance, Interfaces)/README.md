# Arduino Object Oriented Programming (OOP)

In this part we make an alert using inheritance there are two classes "normalBlinker" and "secutirtyBlinker" which extend from Blinker class

Like first intro part we create class for our components and use them in the main file

Lets take a brief look:

The <code>Blinker.cpp</code> has a function which turns LED on and off with some delay that is given in the input.Look at the cpp file below:

## Blinker.cpp
```cpp
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
```

For alert we'll explain both <code>.cpp</code> and <code>.h</code> but don't forget to see other <code>.h</code> files.

The <code>Alert.cpp</code> calls the alertBlink whenever we push the button:
## Alert.cpp
```cpp
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
```
In <code>Alert.h</code>, note that for using an instance of <code>Blinker</code> class in <code>Alert</code>, instead of <code>Blinker</code>,use a member variable of type <code>Blinker*</code>.<br/>If we use variable type of <code>Blinker</code> then call to <code>alertBlink()</code> member function will result in execution of base class's (aka parent, in this case Blinker) <code>alertBlink()</code> function.<br/>
This is unwanted because we have defined <code>alertBlink()</code> in Blinker as virtual function to force derived classes (aka children, Normal and Security Blinkers)
to override the function, so that child class's implementation of <code>alertBlink()</code>to be called.<br/>
In case of not using pointer, we are actually creating new variable within <code>Alert</code> which is indeed of type base class itself, and NOT derived class types anymore. So calling methods like this,will execute base class functions, and not child's implementation of the function.
 
## Alert.h
```cpp
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
```

Then we have <code>NormalBlinker</code> and <code>SecurityBlinker</code> which both extend from Blinker as we mentioned.

lets see the code for each of them:
## NormalBlinker.cpp
```cpp
#include "NormalBlinker.h"

NormalBlinker::NormalBlinker(int ledPin) : Blinker(ledPin) { }

void NormalBlinker::alertBlink(){
  Blinker::blinkBy(1000);
}
```

## SecurityBlinker
```cpp
#include "SecurityBlinker.h"

SecurityBlinker::SecurityBlinker(int ledPin) : Blinker(ledPin) { }

void SecurityBlinker::alertBlink() {
  Blinker::blinkBy(150);
}
```

And finally the <code>main</code> class that we created object of each blinker in it and call alert:

## main

```cpp
#include "src/NormalBlinker.h"
#include "src/SecurityBlinker.h"
#include "src/Alert.h"

const int led1 = 6;
const int led2 = 7;
const int button1 = 12; // security alert blinking 
const int button2 = 11; // normal alert blinkin
  
void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

}

void loop() {
  NormalBlinker nB(led1);
  SecurityBlinker sB(led2);

  Alert sA(button1, &sB);
  Alert nA(button2, &nB);

  sA.watch();
  nA.watch();
}
```
