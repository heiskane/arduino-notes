const int LED = 2;
const long sleep_interval = 10000;
unsigned long previous_millis = 0;

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
}

void loop() {
  Serial.println("Loop started");

  unsigned long current_millis = millis();

  if (current_millis - previous_millis >= sleep_interval) {
    Serial.println("Going to sleep...");

    // ESP Can be woken up by pullin RST pin low
    ESP.deepSleep(0);
  }

  digitalWrite(LED, LOW);
  delay(1000);
  digitalWrite(LED, HIGH);
  delay(1000);
}
