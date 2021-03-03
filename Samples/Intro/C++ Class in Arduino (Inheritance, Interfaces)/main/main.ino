const int led1 = 6;
const int led2 = 7;
const int button1 = 12; // security alert blinking 
const int button2 = 11; // normal alert blinkin


class Blinker{    
  protected:
    int ledPin = -1;
    
    void blinkBy(int ms) {
      digitalWrite(ledPin, HIGH);
      delay(ms);
      digitalWrite(ledPin, LOW);
      delay(ms);
    }
    
  public:
    Blinker() { }
    Blinker(int ledPin) {
      this->ledPin = ledPin;
    }
   
    void off(){
      digitalWrite(ledPin , LOW);
    }

    virtual void alertBlink() { blinkBy(500); }
};

// two below classes extend from alert class

class NormalBlinker : public Blinker{
  public:
    NormalBlinker(int ledPin) : Blinker(ledPin) { }
    
    void alertBlink(){
      Blinker::blinkBy(1000);
    }
};

class SecurityBlinker : public Blinker{
  public:
    SecurityBlinker(int ledPin) : Blinker(ledPin) { }
    
    void alertBlink(){
      Blinker::blinkBy(150);
    }
};

class Alert {
  private:
    int inputPin = -1;
    Blinker blinker;
    
  public:
    Alert(int inputPin, Blinker blinker) {
      this->inputPin = inputPin;
      this->blinker = blinker;
    }

    void watch() {
      if (digitalRead(inputPin) == HIGH){
        blinker.alertBlink();
      }
      else {
        blinker.off();
      }
    }
};
  
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

  Alert sA(button1, sB);
  Alert nA(button2, nB);

  sA.watch();
  nA.watch();
}
