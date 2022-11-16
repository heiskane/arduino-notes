const int GREEN_LED = 9;
const int BLUE_LED = 10;
const int RED_LED = 11;

const int R_SENSOR = A0;
const int G_SENSOR = A1;
const int B_SENSOR = A2;

int r_value = 0;
int g_value = 0;
int b_value = 0;

int r_sensor_value = 0;
int g_sensor_value = 0;
int b_sensor_value = 0;

void setup() {
  Serial.begin(9600);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void loop() {
  r_sensor_value = analogRead(R_SENSOR);
  delay(5);
  g_sensor_value = analogRead(G_SENSOR);
  delay(5);
  b_sensor_value = analogRead(B_SENSOR);

  r_value = r_sensor_value / 4;
  g_value = g_sensor_value / 4;
  b_value = b_sensor_value / 4;

  analogWrite(RED_LED, r_value);
  analogWrite(GREEN_LED, g_value);
  analogWrite(BLUE_LED, b_value);

  Serial.print("Sensor values:");
  Serial.print("\n");
  Serial.print(r_sensor_value);
  Serial.print("\n");
  Serial.print(g_sensor_value);
  Serial.print("\n");
  Serial.print(b_sensor_value);
  Serial.print("\n");
  delay(1000);
}
