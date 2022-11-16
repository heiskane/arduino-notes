int notes[] = {262, 294, 330, 349};

void setup() {
  Serial.begin(9600);

}

void loop() {
  int analog_data = analogRead(A0);
  Serial.println(analog_data);

  if (analog_data == 1023) {
    tone(8, notes[0]);  
  } else if (analog_data > 990 && analog_data < 1010) {
    tone(8, notes[1]);  
  } else if (analog_data > 500 && analog_data < 515) {
    tone(8, notes[2]);  
  } else if (analog_data > 5 && analog_data < 10) {
    tone(8, notes[3]);
  } else {
    noTone(8);  
  }
}
