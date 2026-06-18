#include <TickTwo.h>
#define RELAY1 5
#define RELAY2 6
#define RELAY3 7

void turnOnRelay1();
void turnOnRelay2();
void turnOnRelay3();

TickTwo timer1(turnOnRelay2, 600000, 1, MILLIS);
TickTwo timer2(turnOnRelay3, 10000, 1, MILLIS);
TickTwo timer3(turnOnRelay1, 10000, 1, MILLIS);

void setup() {
  // put your setup code here, to run once:
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);


  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);

  turnOnRelay1();
}

void loop() {
  // put your main code here, to run repeatedly:
  timer1.update();
  timer2.update();
  timer3.update();
}

void turnOnRelay1() {
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY1, LOW);
  timer1.start();
}

void turnOnRelay2() {
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, LOW);
  timer2.start();
}

void turnOnRelay3() {
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, LOW);
  timer3.start();
}
