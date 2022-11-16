
const int vPIN = A0;
const int BUTTON = 2;
const int MOTOR = 9;

float vOUT = 0.0;
float vIN = 0.0;

float R1 = 10000.0;       // Resistor 1 value in ohms (10000 ohms = 10Kohms) 
float R2 = 1000.0;        // Resistor 2 value in ohms (1000 ohms  =  1Kohms)

bool can_spin = true;

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON, INPUT);
  pinMode(MOTOR, OUTPUT);
}

void loop() {
  int button = digitalRead(BUTTON);

  // Wait 100ms to ignore initial spike in voltage
  if (button) {
    delay(100);  
  }
  
  int analog_data = analogRead(vPIN);

  // Calculate voltage
  vOUT = (analog_data * 5.0) / 1024.0;
  vIN = vOUT / ( R2 / (R1 + R2) );
  Serial.print("Voltage: ");
  Serial.println(vIN);

  // Stop spinning if motor is drawing too much voltage
  if (vIN < 8.5) {
    can_spin = false;  
  }

  if (button && can_spin) {
    digitalWrite(MOTOR, HIGH);
  } else {
    digitalWrite(MOTOR, LOW);  
  }

}
