void nastaveniHranicA() {
  if(vzduch < -5) {
    horni = 27;
    dolni = 28;
  }
  else if(-5 <= vzduch < 5) {
    dolni = 26;
    horni = 27;
  }
  else if(5 <= vzduch < 15) {
    dolni = 25;
    horni = 26;
  }
  else if(15 <= vzduch < 25) {
    dolni = 24;
    horni = 25;
  }
  else if(25 <= vzduch < 30){
    dolni = 23;
    horni = 24;
  }
}
//------------------------------------------

void nastaveniHranicB() {
  if(vzduch < 10) {
    dolni = 27;
    horni = 28;
  }
  else if(10 <= vzduch < 20) {
    dolni = 26;
    horni = 27;
  }
  else if(20 <= vzduch < 25) {
    dolni = 25;
    horni = 26;
  }
  else if(25 <= vzduch < 30) {
    dolni = 24;
    horni = 25;
  }
  else {
    dolni = 23;
    horni = 24;
  }
}
void nastaveniHranicC() {
  if(vzduch < 10) {
    dolni = 27;
    horni = 28;
  }
  else if(10 <= vzduch < 20) {
    dolni = 26;
    horni = 27;
  }
  else if(20 <= vzduch < 25) {
    dolni = 25;
    horni = 26;
  }
  else if(25 <= vzduch < 30) {
    dolni = 24;
    horni = 25;
  }
  else {
    dolni = 23;
    horni = 24;
  }
}
void nastaveniHranicD() {
  if(vzduch < 10) {
    dolni = 27;
    horni = 28;
  }
  else if(10 <= vzduch < 20) {
    dolni = 26;
    horni = 27;
  }
  else if(20 <= vzduch < 25) {
    dolni = 25;
    horni = 26;
  }
  else if(25 <= vzduch < 30) {
    dolni = 24;
    horni = 25;
  }
  else {
    dolni = 23;
    horni = 24;
  }
}
