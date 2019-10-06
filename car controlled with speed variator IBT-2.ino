

#include <SoftwareSerial.h>
#define TX 10
#define RX 11

SoftwareSerial BluetoothSerial(TX, RX);
#define R_EN1 A0
#define L_EN1 A1
#define RPWM1 2
#define LPWM1 3
#define R_EN2 A2
#define L_EN2 A3
#define RPWM2 4
#define LPWM2 5
int VG = 0, VD = 0;
int VG2 = 0, VD2 = 0;
float CD, CG, C;
float CD2, CG2, C2;
char choix;
boolean sens;

void setup() {
  pinMode(R_EN1, OUTPUT);
  pinMode(L_EN1, OUTPUT);
  pinMode(RPWM1, OUTPUT);
  pinMode(LPWM1, OUTPUT);

  pinMode(R_EN2, OUTPUT);
  pinMode(L_EN2, OUTPUT);
  pinMode(RPWM2, OUTPUT);
  pinMode(LPWM2, OUTPUT);

  Serial.begin(9600);
  BluetoothSerial.begin(9600);

}
void loop() {

  while (BluetoothSerial.available())
  {


    choix = BluetoothSerial.read();

    switch (choix)
    {
      case 'a': CD = 1; CG = 1; break;
      case 'b': CD = 0.75; CG = 1; break;
      case 'c': CD = 0.5; CG = 1; break;
      case 'd': CD = 0.25; CG = 1; break;
      case 'e': CD = 0; CG = 1; break;
      case 'f': CD = 1; CG = 0.75; break;
      case 'g': CD = 1; CG = 0.5; break;
      case 'h': CD = 1; CG = 0.25; break;
      case 'i': CD = 1; CG = 0; break;
      case 'j': C = 0; break;
      case 'k': C = 0.25; sens = true; break;
      case 'l': C = 0.5; sens = true; break;
      case 'm': C = 0.75; sens = true; break;
      case 'n': C = 1; sens = true; break;
      case 'o': C = 0.25; sens = false; break;
      case 'p': C = 0.5; sens = false; break;
      case 'q': C = 0.75; sens = false; break;
      case 'r': C = 1; sens = false; break;
    }
    VG = 255 * CG * C;
    VD = 255 * CD * C;
    if (sens)
      avance (VG, VD);

    else
      arriere(VG, VD);

    if (C == 0) {
      switch (choix)
      {
        case 'a': CD2 = 0; CG2 = 0; break;
        case 'b': CD2 = 0; CG2 = 0.25; break;
        case 'c': CD2 = 0; CG2 = 0.5; break;
        case 'd': CD2 = 0; CG2 = 0.75; break;
        case 'e': CD2 = 0; CG2 = 1; break;
        case 'f': CD2 = 0.25; CG2 = 0; break;
        case 'g': CD2 = 0.5; CG2 = 0; break;
        case 'h': CD2 = 0.75; CG2 = 0; break;
        case 'i': CD2 = 1; CG2 = 0; break;
      }
      VG2 = 255 * CG2;
      VD2 = 255 * CD2;
      avance (VG2, VD2);
    }

  }
  delay(10);
}
void avance (int VG, int VD) {
  analogWrite(RPWM1, VD);
  analogWrite(LPWM1, 0);
  digitalWrite(R_EN1, HIGH);
  digitalWrite(L_EN1, HIGH);
  analogWrite(RPWM2, VG);
  analogWrite(LPWM2, 0);
  digitalWrite(R_EN2, HIGH);
  digitalWrite(L_EN2, HIGH);
}
void arriere (int VG, int VD) {
  analogWrite(RPWM1, 0);
  analogWrite(LPWM1, VD);
  digitalWrite(R_EN1, HIGH);
  digitalWrite(L_EN1, HIGH);
  analogWrite(RPWM2, 0);
  analogWrite(LPWM2, VG);
  digitalWrite(R_EN2, HIGH);
  digitalWrite(L_EN2, HIGH);
}
