// *** These libraries are for Waziup LoRaWAN
#include <WaziDev.h>
#include <xlpp.h>
#include <Base64.h>
/*********************** Gateway Credentials *********************/
// NwkSKey (Network Session Key) and Appkey (AppKey) are used for securing LoRaWAN transmissions.
// You need to copy them from/to your LoRaWAN server or gateway.
// You need to configure also the devAddr. DevAddr need to be different for each devices!!
// Copy'n'paste the DevAddr (Device Address): 23011D00
unsigned char devAddr[4] = {0x22, 0x01, 0x1D, 0x00};

// Copy'n'paste the key to your Wazigate: 23158D3BBC31E6AF670D195B5AED5525
unsigned char appSkey[16] = {0x22, 0x15, 0x8D, 0x3B, 0xBC, 0x31, 0xE6, 0xAF, 0x67, 0x0D, 0x19, 0x5B, 0x5A, 0xED, 0x55, 0x25};

// Copy'n'paste the key to your Wazigate: 23158D3BBC31E6AF670D195B5AED5525
unsigned char nwkSkey[16] = {0x22, 0x15, 0x8D, 0x3B, 0xBC, 0x31, 0xE6, 0xAF, 0x67, 0x0D, 0x19, 0x5B, 0x5A, 0xED, 0x55, 0x25};

WaziDev wazidev;
/*****************************************************************/
// *** End of Waziup libraries

#define Syntiant_TinyML A6 // connect Syntiant to A6 of Atmega328P
// or use interrupt pins 
int Syntiant_val = 0; // variable to store the Logic Levels of D5
#define Stat_Led 8

bool interrupt_process = false; // state that determines if microcontroller
// will proceed with running other instructions,resets with hardware only
void setup() {
  Serial.begin(38400);

  wazidev.setupLoRaWAN(devAddr, appSkey, nwkSkey); // initialize Waziup LoraWAN

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
  delay(1000);
}
void doSomething() {
  // put code here that runs the main tasks
}
