void vypisVzduchu() {
  Serial.print(vzduch);
  Serial.print(", ");
  Serial.println(voda);
  File soubor = SD.open("teploty.txt", FILE_WRITE);
  soubor.print(vzduch);
  soubor.print(", ");
  soubor.println(voda); 
  soubor.close();
  delay(1000);
}
void vypisVody() {
  Serial.print("     ");
  Serial.print(", ");
  Serial.println(voda);
}
