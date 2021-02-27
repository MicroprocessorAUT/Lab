#include "src/Led/Led.h"
#include "src/Button/Button.h"

#define LED_1_PIN 6
#define LED_2_PIN 5
#define LED_3_PIN 4
#define LED_4_PIN 3

#define BUTTON_PIN 10

Led led1(LED_1_PIN);
Led led2(LED_2_PIN);
Led led3(LED_3_PIN);
Led led4(LED_4_PIN);
Button button1(BUTTON_PIN);


void setup() {
  
}

void loop() {

  if (button1.isPressed()) {
    led1.on();
    led2.off();
    led3.on();
    led4.off();
  }
  else {
    led1.off();
    led2.on();
    led3.off();
    led4.on();
  }
}
