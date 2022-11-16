const int SENSOR_PIN = A0;
const float BASELINE_TEMP = 20.0;

void setup() {
  Serial.begin(9600);

  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);  
  }
}

void loop() {
  int sensorVal = analogRead(SENSOR_PIN);
  float voltage = (sensorVal / 1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100;

  if (temperature < BASELINE_TEMP) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= BASELINE_TEMP + 2 && temperature < BASELINE_TEMP + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= BASELINE_TEMP + 4 && temperature < BASELINE_TEMP + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);  
  } else if (temperature > BASELINE_TEMP + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("\n");
  delay(500);
}
