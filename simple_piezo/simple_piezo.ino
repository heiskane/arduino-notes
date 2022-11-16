int sensor_value;
int sensor_low = 1023;
int sensor_high;

const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  while (millis() < 5000) {
    sensor_value = analogRead(A0);

    if (sensor_value > sensor_high) {
      sensor_high = sensor_value;  
    }

    if (sensor_value < sensor_high) {
      sensor_low = sensor_value;  
    }
  }

  digitalWrite(LED_PIN, LOW);
}

void loop() {
  sensor_value = analogRead(A0);

  int pitch = map(sensor_value, sensor_low, sensor_high, 50, 4000);
  tone(8, pitch, 20);
  delay(10);
}
