#include <Servo.h>

Servo myServo;

int const POT_PIN = A0;
int pot_value;
int angle;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  pot_value = analogRead(POT_PIN);
  Serial.print("Pot value: ");
  Serial.print(pot_value);
  Serial.print(", ");

  angle = map(pot_value, 0, 1023, 0, 179);
  Serial.print("Angle: ");
  Serial.print(angle);
  Serial.print("\n");

  myServo.write(angle);
  delay(15);
}
