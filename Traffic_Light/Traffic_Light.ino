void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // Green
  digitalWrite(11, HIGH);
  delay(1500);
  digitalWrite(11, LOW);

  // Yellow
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);

  // Red
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
}
