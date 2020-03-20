#include <OneWire.h>
#include <DallasTemperature.h>
#include <SD.h>

OneWire jedenDrat(40);
DallasTemperature teplomer(&jedenDrat);
const int sdkarta = 53;       // SS pin pro modul micro SD karty (na modulu jako CS)
const int kotel = 41;         // relé na ovládání kotle (relé svítí = kotel NETOPÍ)
const int kotled = 39;        // indikační ledka kotle (ledka svítí = kotel TOPÍ)
int i;                        // index (pořadí) čidla na drátě
float vzduch;                 // teplota vzduchu (venkovní čidlo)
float voda;                   // teplota vody (čidlo v kotli)
int dolni;                    // dolní hranice teploty vody
int horni;                    // horní hranice teploty vody
int prodleva = 15000;         // prodleva mezi regulacemi kotle (nebo měřeními teploty vody)
DeviceAddress adresaCidla;    // sem si budu ukládat adresy čidel

void setup() {
  Serial.begin(4800);         // spustí sériový port
  Serial.println("vzduch,voda[°C]");
  teplomer.begin();           // spustí knihovnu
  pinMode(kotel, OUTPUT);
  pinMode(kotled, OUTPUT);
  SD.begin(sdkarta);
}
void loop() {
  vzduch = mereniVzduchu();
  delay(2000);
  vypisVzduchu();           // na Serial vypíše teplotu vzduchu i vody, uloží je na SD kartu
  nastaveniHranicA();
  for(int j=0; j<300; j++) {
    voda = mereniVody();
    delay(prodleva);
    vypisVody();            // na Serial vypíše jen teplotu vody, na sd kartu nic
    regulaceKotle();
  }
}
