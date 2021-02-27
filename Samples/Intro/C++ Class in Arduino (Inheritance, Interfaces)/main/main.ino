const int led1 = 6;
const int button1 = 12; // security alert blinking 
const int button2 = 11; // normal alert blinkin


class alert{    
  public:
  virtual void alertBlink();
  virtual void off();
};

// two below classes extend from alert class

class normalAlert : public alert{
   public:
    void alertBlink(){
      digitalWrite(led1, HIGH);
      delay(1000);
      digitalWrite(led1, LOW);
    }

    public:
      void off(){
        digitalWrite(led1 , LOW);
      }
  
};

class securityAlert : public alert{
  public:
    void alertBlink(){
      digitalWrite(led1, HIGH);
      delay(150);
      digitalWrite(led1, LOW);
    }

  public:
    void off(){
      digitalWrite(led1 , LOW);
     }
  
};


  
void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

}

void loop() {
  normalAlert nA;
  securityAlert sA;
  if (digitalRead(button1) == HIGH){
    sA.alertBlink();
  }

  else if(digitalRead(button2) == HIGH){
    nA.alertBlink();
  }
  else {
    nA.off();
    sA.off();
  }

}
