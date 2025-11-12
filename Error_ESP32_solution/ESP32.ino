void setup() {
  pinMode(2, OUTPUT); // LED integrado en pin 2 (en la mayoría de ESP32)
}

void loop() {
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
}
