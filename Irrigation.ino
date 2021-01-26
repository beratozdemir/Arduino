#include <Servo.h>
Servo servoM;
int motor = 4 ;
int buzzerPin = 8;
int sensorPin1 = A1;
int sensorPin2 = A2;
int sensorPin3 = A3;
int sensorPin4 = A4;
int veri1;
int veri2;
int veri3;
int veri4;
int pos = 0;

void setup() {
  servoM.attach(9);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(sensorPin3, INPUT);
  pinMode(sensorPin4, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  veri1 = analogRead(sensorPin1);
  if (veri1 > 550) {
    servoM.write(0);
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(300);
    digitalWrite(motor, HIGH);
    delay(3000);
    digitalWrite(motor, LOW);
    delay(3000);

    if (veri1 > 550) {
      digitalWrite(buzzerPin, HIGH);
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(200);
      digitalWrite(motor, HIGH);
      delay(2000);
      digitalWrite(motor, LOW);
      delay(5000);
    } else {
      digitalWrite(motor, LOW);
    }
  } else {
    digitalWrite(motor, LOW);
  }

  veri2 = analogRead(sensorPin2);
  if (veri2 > 550) {
    servoM.write(60);
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(300);
    digitalWrite(motor, HIGH);
    delay(3000);
    digitalWrite(motor, LOW);
    delay(3000);
    if (veri2 > 550) {
      digitalWrite(buzzerPin, HIGH);
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(200);
      digitalWrite(motor, HIGH);
      delay(2000);
      digitalWrite(motor, LOW);
      delay(5000);
    } else {
      digitalWrite(motor, LOW);
    }
  } else {
    digitalWrite(motor, LOW);
  }

  veri3 = analogRead(sensorPin3);
  if (veri3 > 550) {
    servoM.write(120);
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(300);
    digitalWrite(motor, HIGH);
    delay(3000);
    digitalWrite(motor, LOW);
    delay(3000);
    if (veri3 > 550) {
      digitalWrite(buzzerPin, HIGH);
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(200);
      digitalWrite(motor, HIGH);
      delay(2000);
      digitalWrite(motor, LOW);
      delay(5000);
    } else {
      digitalWrite(motor, LOW);
    }
  } else {
    digitalWrite(motor, LOW);
  }

  veri4 = analogRead(sensorPin4);
  if (veri4 > 550) {
    servoM.write(180);
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(300);
    digitalWrite(motor, HIGH);
    delay(3000);
    digitalWrite(motor, LOW);
    delay(3000);
    if (veri4 > 550) {
      digitalWrite(buzzerPin, HIGH);
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(200);
      digitalWrite(motor, HIGH);
      delay(2000);
      digitalWrite(motor, LOW);
      delay(5000);
    } else {
      digitalWrite(motor, LOW);
    }
  } else {
    digitalWrite(motor, LOW);
  }
}

