#include <VirtualWire.h>

int sig[1];           // počet integerů, které chci přijmout (nenastavovat jako konstantu!)
const int prij = 2;   // na tomhle pinu mám DATA přijímače
const int ledka = 31; // když blikne, je přijat signál z vysílače
const int ledA = 23;
const int ledB = 25;
const int ledC = 27;
const int ledD = 29;

void setup() {
  pinMode(ledka, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  Serial.begin(4800);
  
  vw_set_ptt_inverted(true);    // je potřeba nastavit pro levné moduly
  vw_setup(900);                // bity za sekundu
  vw_set_rx_pin(prij);          // na tomhle pinu mám DATA přijímače
  vw_rx_start();                // zapni přijímač
}

void loop() {
  delay(50);
  digitalWrite(ledka,LOW);
  uint8_t buf[VW_MAX_MESSAGE_LEN];      // tohle budem přijímat (buffer)
  uint8_t buflen = VW_MAX_MESSAGE_LEN;  // délka bufferu
  if(vw_get_message(buf, &buflen)) {    // podívej se, jestli dostal přijímač nějaký signál
    digitalWrite(ledka,HIGH);
    Serial.print("příjem: ");
    sig[0] = word(buf[1], buf[0]);      // dej dohromady přijatý signál
    Serial.println(sig[0],DEC);         // (ve zdroji pro víc integerů, mně stačí jedno číslo, proto [0])
  }
  if(sig[0] == 1) {
    digitalWrite(ledB,LOW);
    digitalWrite(ledC,LOW);
    digitalWrite(ledD,LOW);
    digitalWrite(ledA,HIGH);
  }
  else if(sig[0] == 2) {
    digitalWrite(ledA,LOW);
    digitalWrite(ledC,LOW);
    digitalWrite(ledD,LOW);
    digitalWrite(ledB,HIGH);
  }
  else if(sig[0] == 3) {
    digitalWrite(ledA,LOW);
    digitalWrite(ledB,LOW);
    digitalWrite(ledD,LOW);
    digitalWrite(ledC,HIGH);
  }
  else if(sig[0] == 4) {
    digitalWrite(ledA,LOW);
    digitalWrite(ledB,LOW);
    digitalWrite(ledC,LOW);
    digitalWrite(ledD,HIGH);
  }
}
