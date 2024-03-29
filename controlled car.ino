#define HC05 Serial

#define M1 A2
#define IN1_M1 2
#define IN2_M1 3

#define M2 A3
#define IN1_M2 4
#define IN2_M2 6

#define M3 A0
#define IN1_M3 8
#define IN2_M3 10

#define M4 A1
#define IN1_M4 12
#define IN2_M4 13
char command;
void setup() {

  pinMode(M1, OUTPUT);
  pinMode(IN1_M1, OUTPUT);
  pinMode(IN2_M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(IN1_M2, OUTPUT);
  pinMode(IN2_M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(IN1_M3, OUTPUT);
  pinMode(IN2_M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(IN1_M4, OUTPUT);
  pinMode(IN2_M4, OUTPUT);

  HC05.begin(9600);
}

void forward() {
  digitalWrite(M1, 1);
  digitalWrite(IN1_M1, HIGH);
  digitalWrite(IN2_M1, LOW);
  digitalWrite(M2, 1);
  digitalWrite(IN1_M2, HIGH);
  digitalWrite(IN2_M2, LOW);

  digitalWrite(M3, 1);
  digitalWrite(IN1_M3, HIGH);
  digitalWrite(IN2_M3, LOW);
  digitalWrite(M4, 1);
  digitalWrite(IN1_M4, HIGH);
  digitalWrite(IN2_M4, LOW);
}

void stoper() {
  digitalWrite(M1, 0);
  digitalWrite(M2, 0);
  digitalWrite(M3, 0);
  digitalWrite(M4, 0);
}

void back() {
  digitalWrite(M1, 1);
  digitalWrite(IN1_M1, LOW);
  digitalWrite(IN2_M1, HIGH);
  digitalWrite(M2, 1);
  digitalWrite(IN1_M2, LOW);
  digitalWrite(IN2_M2, HIGH);

  digitalWrite(M3, 1);
  digitalWrite(IN1_M3, LOW);
  digitalWrite(IN2_M3, HIGH);
  digitalWrite(M4, 1);
  digitalWrite(IN1_M4, LOW);
  digitalWrite(IN2_M4, HIGH);
}

void left() {
  digitalWrite(M1, 1);
  digitalWrite(IN1_M1, LOW);
  digitalWrite(IN2_M1, HIGH);
  digitalWrite(M2, 1);
  digitalWrite(IN1_M2, LOW);
  digitalWrite(IN2_M2, HIGH);

  digitalWrite(M3, 1);
  digitalWrite(IN1_M3, HIGH);
  digitalWrite(IN2_M3, LOW);
  digitalWrite(M4, 1);
  digitalWrite(IN1_M4, HIGH);
  digitalWrite(IN2_M4, LOW);
}

void right() {
  digitalWrite(M1, 1);
  digitalWrite(IN1_M1, HIGH);
  digitalWrite(IN2_M1, LOW);
  digitalWrite(M2, 1);
  digitalWrite(IN1_M2, HIGH);
  digitalWrite(IN2_M2, LOW);

  digitalWrite(M3, 1);
  digitalWrite(IN1_M3, LOW);
  digitalWrite(IN2_M3, HIGH);
  digitalWrite(M4, 1);
  digitalWrite(IN1_M4, LOW);
  digitalWrite(IN2_M4, HIGH);
}

void loop() {
  while (HC05.available())
  {

    command = HC05.read();
    Serial.print(command);
    switch (command)
    {
      case 'F':
        forward(); break;
      case 'B':
        back(); break;
      case 'L':
        left(); break;
      case 'G':
        left(); break;
      case 'R':
        right(); break;
      case 'I':
        right(); break;
      default:
        stoper();
    }
  }
}
