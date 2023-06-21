#include <Servo.h>
Servo s = Servo();
#include <Ultrasonic.h>
Ultrasonic u = Ultrasonic(3, 4);



void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  analogWrite(11, 200);  //A speed
  analogWrite(5, 200);   //B speed
  s.attach(8);
  Serial.begin(9600);
}

void loop() {
  int x = Serial.read();

  if (x == '1') {  //F

    s.write(90);
    int d = u.distanceRead();
    if (d > 15) {

      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);

      digitalWrite(7, HIGH);
      digitalWrite(6, LOW);

      delay(700);
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);

      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
    }
  }
  if (x == '2') {  //R

    s.write(30);
    int d = u.distanceRead();
    if (d > 15) {

      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);

      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);

      delay(350);
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);

      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
    }
    s.write(90);
  }
  if (x == '3') {  //L

    s.write(160);
    int d = u.distanceRead();
    if (d > 15) {

      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);

      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);

      delay(350);
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);

      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
    }
    s.write(90);
  }
  if (x == '4') {  //B
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);

    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);

    delay(700);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);

    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
  }
}
