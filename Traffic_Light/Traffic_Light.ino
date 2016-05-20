void setup() {
  pinMode(11, OUTPUT); // Output for Green Light
  pinMode(12, OUTPUT); // Output for Yellow Light
  pinMode(13, OUTPUT); // Output for Red Light
}

void loop() {
  // Green
  digitalWrite(11, HIGH); // Turns light on
  delay(1500); // Delay for amount of milliseconds light should stay on
  digitalWrite(11, LOW); // Turns light off

  // Yellow
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);

  // Red
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
}
