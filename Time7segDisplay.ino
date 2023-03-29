//     _
//     a
//  f| _ |b
//     g
//  e| _ |c
//     d      
//
byte connection[] = { 2, 3, 4, 5, 6, 7, 8 };
byte pos[] = { 9, 10, 11, 12 };
byte numL[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  //0
  { 0, 1, 1, 0, 0, 0, 0 },  //1
  { 1, 1, 0, 1, 1, 0, 1 },  //2
  { 1, 1, 1, 1, 0, 0, 1 },  //3
  { 0, 1, 1, 0, 0, 1, 1 },
  { 1, 0, 1, 1, 0, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1 }
};

int a;      // cislice na tisicich
int b;      // cislice na stovkách
int c;      // cislice na desítkách
int d;      // cislice na jednotkách
int j;      // konkretni zobrazená cislice
int num;  // zobrazované číslo
unsigned long casTed;

int showTime = 1000;  // jak dlouho má číslo svítit
int timeNow;

void setup() {
  for (int i = 2; i < 13; i = i + 1) {
    pinMode(i, OUTPUT);
    //randomSeed(analogRead(A0));
    
  }
}

void zobraz(int num) {
  timeNow = millis();
  do {
    for (int k = 12; k > 8; k--) {
      if (k == 12 && a != 0) {
        j = a;
        digitalWrite(k, HIGH);
      } else if (k == 11 && ((a != 0) || (b != 0 && a == 0))) {
        j = b;
        digitalWrite(k, HIGH);
      } else if (k == 10 && ((a != 0 || b != 0) || (c != 0 && a == 0 && b == 0))) {
        j = c;
        digitalWrite(k, HIGH);
      } else if (k == 9) {
        j = d;
        digitalWrite(k, HIGH);
      }
      for (int i = 0; i < 7; i = i + 1) {
        digitalWrite(connection[i], numL[j][i]);
      }
      delay(4);
      digitalWrite(k, LOW);
    }
  } while (millis() - timeNow < showTime);
}

void loop() {
  /*for(int i = 0; i<9999; i = i+10){
    cislo = i;
  }*/
  if (num >= 9999){
    timeNow = millis();
    num = millis() - timeNow;
  }
  num = millis();
  a = num / 1000;
  b = (num - a * 1000) / 100;
  c = (num - a * 1000 - b * 100) / 10;
  d = num - a * 1000 - b * 100 - c * 10;
  
  zobraz(num);
  //delay(500);
}
