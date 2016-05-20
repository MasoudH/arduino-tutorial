int B0State = 0;
int B1State = 0;

const String CorrectPassword = "01000100";
String AttemptedPassword = "";

bool IsButtonRegistered = false;

void setup() {
  pinMode(2, INPUT);
  pinMode(4, INPUT);

  pinMode(12, OUTPUT);  // Correct
  pinMode(13, OUTPUT);  // Wrong

  Serial.begin(9600);
}

void loop() {
  while (AttemptedPassword.length() < 8) {
    B0State = digitalRead(2);
    B1State = digitalRead(4);
    
    if (B0State == 0 && B1State == 0) {
      IsButtonRegistered = false;
    }
  
    if (B0State == 1 && !IsButtonRegistered){
      AttemptedPassword += "0";
      IsButtonRegistered = true;
    }
    else if (B1State == 1 && !IsButtonRegistered) {
      AttemptedPassword += "1";
      IsButtonRegistered = true;
    }
  }

  if (AttemptedPassword == CorrectPassword) {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  else {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }

  delay(5000);

  AttemptedPassword = "";
}
