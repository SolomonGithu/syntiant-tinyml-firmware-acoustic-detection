#define Syntiant_TinyML A6 // connect Syntiant to A6 of Atmega328P
// or use interrupt pins 
int Syntiant_val = 0; // variable to store the Logic Levels of D5
#define Stat_Led 8

bool interrupt_process = false; // state that determines if microcontroller
// will proceed with running other instructions,resets with hardware only
void setup() {
  Serial.begin(9600);

  pinMode(Syntiant_TinyML, INPUT_PULLUP); // set A6 as input and use internal pullup
  pinMode(Stat_Led, OUTPUT);
}

void loop() {
  // read status of A6
  Syntiant_val = analogRead(Syntiant_TinyML);
  //Serial.println(Syntiant_val);
  
  if (Syntiant_val == 1023) {
    Serial.println("__ Accident Detected! __");
    digitalWrite(Stat_Led, HIGH);
    interrupt_process = true;
  }
  else {
    digitalWrite(Stat_Led, LOW);

    if (!interrupt_process) {
      doSomething();
    }
  }
}
void doSomething() {
  // put code here that runs the main tasks
}
