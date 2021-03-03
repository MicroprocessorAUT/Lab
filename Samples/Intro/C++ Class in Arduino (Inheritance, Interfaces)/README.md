# Arduino Object Oriented Programming (OOP)

In this part we make an alert using inheritance there are two classes "normalBlinker" and "secutirtyBlinker" which extend from Blinker class

Like first intro part we create class for our components and use them in the main file

You can see the code below :

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
