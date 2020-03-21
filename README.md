# EKVITOR
Ekvitermní termoregulátor pro domácí systém vytápění
## Programy, na kterých lze testovat funkčnost projektu
### spuštění ekvitermní termoregulace (bez dálkového ovládání):
- sketch "tepelneCidloDvakrat9.ino"
  - se soubory ve stejnojmenné složce otevřít v Arduino IDE a nahrát na desku Arduino Mega
### bezdrátová komunikace (bez termoregulace, jen s přepínáním módů):
- sketch "radioVysilac3.ino" ve složce "radio"
  - otevřít v Arduino IDE a nahrát na desku Arduino Uno - dálkové ovládání
- sketch "radioPrijimac4.ino" ve složce "radio"
  - otevřít v Arduino IDE a nahrát na desku Aduino Mega - přijímač signálu
  
