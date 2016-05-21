int B0State = 0;
int B1State = 0;

int LightFrame = 0;

const String CorrectPassword = "01000100";
String AttemptedPassword = "";

bool IsButtonRegistered = false;
bool Cycling = false;

void setup() {
  pinMode(2, INPUT); // Button 1
  pinMode(4, INPUT); // Button 2

  pinMode(11, OUTPUT);  // Green
  pinMode(12, OUTPUT);  // Yellow
  pinMode(13, OUTPUT);  // Red

  Serial.begin(9600);
}

void loop() {
  while (AttemptedPassword.length() < 8) {
    B0State = digitalRead(2); // State Button 1
    B1State = digitalRead(4); // State Button 2
    
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

    if (Cycling) {
      CycleLights();
    }

    Serial.println(AttemptedPassword);
  }

  if (AttemptedPassword == CorrectPassword) {
    Cycling = !Cycling;
  }
  else {
    for (int i = 0; i < 3; i++) {
      digitalWrite(13, HIGH);
      delay(1000);
    }
  }

  if (!Cycling) {
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }

  AttemptedPassword = "";
}

void CycleLights() {
  if (LightFrame < 1000) {
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  else if (LightFrame > 1000 && LightFrame < 2000) {
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  else if (LightFrame > 2000) {
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }

  LightFrame++;

  if (LightFrame > 3300) {
    LightFrame = 0;
  }
}

