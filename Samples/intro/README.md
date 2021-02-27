# Arduino Object Oriented Programming (OOP)

Basically, the Arduino language is a subset of C/C++. You can create classes, use inheritance, composition, and many other nice OOP functionalities but how ?

in this introduction we want to learn how to use oop in arduino for more reusability, modularity, readability, etc.
lets start with a simple example
consider the below circuit:
<p align="center">
  <img src="https://roboticsbackend.com/wp-content/uploads/2019/05/schema_button.jpg" width="500" hight="100" alt="circuit">
</p>

We want to turn on LED 1 , 3 and turn off LED 2 , 4 when the button is pressed and opposite will happen after releasing the button.
Now let's see how to program this arduino in the clearest way using classes 

As you see we have two components (LED and Button) so we need a class for each of this component to handle their functionalities so we’ll separate the code into 3 parts: the LED class, the Button class, and the “main”. **Each class will be on its own independent file.**
For each class we'll have two files : cpp file (.cpp) and a header file (.h) in this way our code will become much more readable. 

**Note that** creating other files for an Arduino program is quite tricky. You must create all your files inside your Arduino program folder. Example: if your program is named Test.ino, then it will be automatically saved on a Test/ folder (the Arduino IDE does that). You’ll have to put all your files in the Test/folder as well, so the Arduino IDE can find them.

Go into the folder of your current Arduino program. Create 4 files:

  * Led.h
  * Led.cpp
  * Button.h
  * Button.cpp

**All the source codes are available in intro section**

# LED classes
LED is a very basic component. We setup a digital pin to INPUT mode, and then We just need to set its state to HIGH (on) or LOW (off)

## Led.h 

```cpp
#ifndef MY_LED_H
#define MY_LED_H

#include <Arduino.h> // This include is necessary 

class Led {
  
  private:
    byte pin;
    
  public:
    Led(byte pin);
    void init();
    void on();
    void off();
};

#endif
```
In this file we just write the class declaration. This makes the class much easier to understand and use.

The header guards (first 2 lines, and last line) will make sure that the Led class will not be included more than once, if for example you have multiple <code>#include "Led.h"</code>
in other parts of your program.

Also note that We’ve added <code>#include <Arduino.h></code>
at the beginning. Why? This include is necessary to use the specific Arduino functions and types (think of pinMode(), digitalWrite(), byte). In the “main” file we don’t need to write it because it’s automatically added when you compile your code. But in any other file, you need to add it by yourself.
  
## Led.cpp

```cpp
#include "Led.h"

Led::Led(byte pin) {
  this->pin = pin;  //using 'this-> we make difference between the 'pin' attribute of the class and the local variable 'pin' '
  init();
}

void Led::init() {    // the initial state of LED is off
  pinMode(pin, OUTPUT);
  
  // Instead of writing digitalWrite(pin, LOW) here,
  // we call the function off() which already does that inorder to avoid duplicate code
  
  off();
}

void Led::on() {
  digitalWrite(pin, HIGH); //As we mentioned this make the LED turn on
}

void Led::off() {
  digitalWrite(pin, LOW); //This code make the LED turn off
}

```
**don't forget the <code>#include "Led.h"</code> to access the LED class**
 
# Button classes

The button is a little bit more complex, because we need to add a debounce functionality if we want it to remove the mechanical noise.
you can read about debouncing [here] : https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce


  
