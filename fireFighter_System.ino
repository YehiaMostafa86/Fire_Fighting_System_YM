
#include <ESP32Servo.h>
Servo flameServo;
#define flameServoPin 16
Servo waterServo;
#define waterServoPin 17
#define relay 18
#define flameSensorePin 32

void setup() {
  flameServo.attach(flameServoPin);
  waterServo.attach(waterServoPin);
  flameServo.write(90);
  waterServo.write(90);
  pinMode(flameSensorePin, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay,LOW);
  // put your setup code here, to run once:
}

void loop() {
  int flameSensorReading = digitalRead(flameSensorePin);
  for (int i = 90; i > 0; i -= 2) {
    flameSensorReading = digitalRead(flameSensorePin);
    flameServo.write(i);
    delay(30);
    if (flameSensorReading == LOW) {
      waterServo.write(i);
      digitalWrite(relay, HIGH);
      delay(4000);
      digitalWrite(relay, LOW);
    }
  }
  delay(100);
  for (int i = 0; i < 180; i += 2) {
    flameSensorReading = digitalRead(flameSensorePin);
    flameServo.write(i);
    delay(30);
    if (flameSensorReading == LOW) {
      waterServo.write(i);
      digitalWrite(relay, HIGH);
      delay(4000);
      digitalWrite(relay, LOW);
    }
  }
  delay(100);
  for (int i = 180; i > 90; i -= 2) {
    flameSensorReading = digitalRead(flameSensorePin);
    flameServo.write(i);
    delay(30);
    if (flameSensorReading == LOW) {
      waterServo.write(i);
      digitalWrite(relay, HIGH);
      delay(4000);
      digitalWrite(relay, LOW);
    }
  }
  // put your main code here, to run repeatedly:
}
