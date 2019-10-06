#include <NewPing.h>

#define distLim 20

#define trig 8
#define echo 9
#define MaxDistance 25

#define trig2 10
#define echo2 11


NewPing sonar(trig, echo, MaxDistance);
NewPing sonar2(trig2, echo2, MaxDistance);
unsigned int d1 = 0, d11 = 0;
unsigned int d2 = 0, d22 = 0;

int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;
int ENA = 6;
int ENB = 7;
#define capteur_g  30
#define capteur_mg 32
#define capteur_md 34
#define capteur_d 36

int tt = 0;
int tt2 = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(30, INPUT);
  pinMode(32, INPUT);
  pinMode(34, INPUT);
  pinMode(36, INPUT);


}
void loop()
{
  tt++;
  tt2++;
  if (tt >= 10)
  {
    tt = 0;
    look();
    while (d1 <= distLim && d1 != 0 && d11 <= distLim && d11 != 0)
    {
      stoper();
      delay(25);
      look();
    }
  }

  digitalRead(capteur_g);
  digitalRead(capteur_mg);
  digitalRead(capteur_md);
  digitalRead(capteur_d);
  Serial.print( digitalRead(capteur_g));
  Serial.print( digitalRead(capteur_mg));
  Serial.print( digitalRead(capteur_md));
  Serial.print( digitalRead(capteur_d));
  Serial.println();


  if (digitalRead(capteur_mg) == HIGH && digitalRead(capteur_md) == HIGH)
  { avance();
  }
  //calibrage:
  if (digitalRead(capteur_mg) == LOW && digitalRead(capteur_md) == HIGH && digitalRead(capteur_g) == LOW && digitalRead(capteur_d) == LOW)
  { deroite_ca();
  }
  if (digitalRead(capteur_mg) == HIGH && digitalRead(capteur_md) == LOW && digitalRead(capteur_g) == LOW && digitalRead(capteur_d) == LOW)
  { gauche_ca();
  }

  if (digitalRead(capteur_mg) == LOW && digitalRead(capteur_md) == LOW && digitalRead(capteur_g) == LOW && digitalRead(capteur_d) == LOW)
  { avance();
  }

  if (digitalRead(capteur_g) == LOW && digitalRead(capteur_mg) == LOW && digitalRead(capteur_md) == LOW && digitalRead(capteur_d) == HIGH)
  { droite();
  }
if (digitalRead(capteur_g) == HIGH && digitalRead(capteur_mg) == LOW && digitalRead(capteur_md) == LOW && digitalRead(capteur_d) == HIGH)
  { droite();
  }
  
  if (digitalRead(capteur_g) == HIGH && digitalRead(capteur_mg) == LOW && digitalRead(capteur_md) == LOW && digitalRead(capteur_d) == LOW)
  { gauche();
  }
//parking

 if (tt2 >= 5)
  {
    tt2 = 0;
look2();
    if(d2 < 20 && d2!=0 && d22!= 0 && d22 < 20)
    {
      
      delay(550);
      look2();
      if(d2 < 20 && d2!=0 && d22!= 0 && d22 < 20)
      {
        // calibrage
         if (digitalRead(capteur_mg) == LOW && digitalRead(capteur_md) == HIGH && digitalRead(capteur_g) == LOW && digitalRead(capteur_d) == LOW)
        { deroite_ca();
         }
         if (digitalRead(capteur_mg) == HIGH && digitalRead(capteur_md) == LOW && digitalRead(capteur_g) == LOW && digitalRead(capteur_d) == LOW)
         { gauche_ca();
         }
           delay(875);
        look2();
        if(d2 < 20 && d2!=0 && d22!= 0 && d22 < 20)
        {
          // calibrage
         if (digitalRead(capteur_mg) == LOW && digitalRead(capteur_md) == HIGH && digitalRead(capteur_g) == LOW && digitalRead(capteur_d) == LOW)
        { deroite_ca();
         }
         if (digitalRead(capteur_mg) == HIGH && digitalRead(capteur_md) == LOW && digitalRead(capteur_g) == LOW && digitalRead(capteur_d) == LOW)
         { gauche_ca();
         }
          delay(830);
          parking();
         delay(550);
         avance();
         delay(550);
         while (1)
        {stoper();}        
        }
      }
      else if (d2 > 20 && d2!=0 && d22!= 0 && d22 > 20)
      {
        parking();
      delay(550);
      avance();
      delay(550);
      while (1)
      {stoper();}
      }
      
      parking();
      delay(550);
      avance();
      delay(550);
      while (1)
      {stoper();}
    }
  }
}


void avance()
{
  analogWrite(ENA, 75);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, 95);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void stoper()
{
  analogWrite(ENA, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, 0);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void droite()
{
  analogWrite(ENA, 75);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, 95);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
void gauche()
{
  analogWrite(ENA, 75);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, 95);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

//calibrage:
void deroite_ca()
{
  analogWrite(ENA, 75);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, 0);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void gauche_ca()
{
  analogWrite(ENA, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, 95);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void look()
{
  d1 = sonar.ping_cm();
  delay(20);
  d11 = sonar.ping_cm();
  if (abs(d1 - d2) >= 2)
  {
    d1 = sonar.ping_cm();
    delay(20);
    d11 = sonar.ping_cm();
  }
}
void look2()
{
  d2 = sonar2.ping_cm();
  delay(15);
  d22 = sonar2.ping_cm();
  if (abs(d2 - d22) >= 2)
  {
    d2 = sonar2.ping_cm();
    delay(20);
    d22 = sonar2.ping_cm();
  }
}

void parking()
{
  analogWrite(ENA, 55);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, 85);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

