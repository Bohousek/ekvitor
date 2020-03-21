#include <VirtualWire.h>

const int vys = 2;
int sig[1];           //počet integerů, který posílám (mně stačí jeden)
const int tlacitkoA = 4;
const int tlacitkoB = 5;
const int tlacitkoC = 6;
const int tlacitkoD = 7;
int A = 0;
int B = 0;
int C = 0;
int D = 0;
const int ledA = 8;
const int ledB = 9;
const int ledC = 11;  // (desítka blbne)
const int ledD = 12;

void setup() {
  vw_set_ptt_inverted(true);
  vw_setup(900);
  vw_set_tx_pin(vys);
  
  pinMode(tlacitkoA, INPUT);
  pinMode(tlacitkoB, INPUT);
  pinMode(tlacitkoC, INPUT);
  pinMode(tlacitkoD, INPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  
  digitalWrite(ledA,HIGH);
  digitalWrite(ledB,HIGH);
  digitalWrite(ledC,HIGH);
  digitalWrite(ledD,HIGH);
  sig[0] = 0;
}

void loop() {
  A = digitalRead(tlacitkoA);
  B = digitalRead(tlacitkoB);
  C = digitalRead(tlacitkoC);
  D = digitalRead(tlacitkoD);
  
  if(A == HIGH) {
    digitalWrite(ledB,LOW);
    digitalWrite(ledC,LOW);
    digitalWrite(ledD,LOW);
    sig[0] = 1;
    for(int i=0; i<20; i++) {
      digitalWrite(ledA,LOW);
      vw_send( (uint8_t *)sig, sizeof(sig));
      vw_wait_tx();             // počkej na konec zprávy
      digitalWrite(ledA,HIGH);
      delay(1000);
    }
  }
  else if(B == HIGH) {
    digitalWrite(ledA,LOW);
    digitalWrite(ledC,LOW);
    digitalWrite(ledD,LOW);
    sig[0] = 2;
    for(int i=0; i<20; i++) {
      digitalWrite(ledB,LOW);
      vw_send( (uint8_t *)sig, sizeof(sig));
      vw_wait_tx();             // počkej na konec zprávy
      digitalWrite(ledB,HIGH);
      delay(1000);
    }
  }
  else if(C == HIGH) {
    digitalWrite(ledA,LOW);
    digitalWrite(ledB,LOW);
    digitalWrite(ledD,LOW);
    sig[0] = 3;
    for(int i=0; i<20; i++) {
      digitalWrite(ledC,LOW);
      vw_send( (uint8_t *)sig, sizeof(sig));
      vw_wait_tx();             // počkej na konec zprávy
      digitalWrite(ledC,HIGH);
      delay(1000);
    }
  }
  else if(D == HIGH) {
    digitalWrite(ledA,LOW);
    digitalWrite(ledB,LOW);
    digitalWrite(ledC,LOW);
    sig[0] = 4;
    for(int i=0; i<20; i++) {
      digitalWrite(ledD,LOW);
      vw_send( (uint8_t *)sig, sizeof(sig));
      vw_wait_tx();             // počkej na konec zprávy
      digitalWrite(ledD,HIGH);
      delay(1000);
    }
  }
}
