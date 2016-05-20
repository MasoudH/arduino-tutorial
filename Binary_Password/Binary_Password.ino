int B0State = 0; // State of Button 1
int B1State = 0; // State of Button 2

const String CorrectPassword = "01000100"; // Correct Password
String AttemptedPassword = ""; // String for users input

bool IsButtonRegistered = false;

void setup() {
  pinMode(2, INPUT); // Input from button 1
  pinMode(4, INPUT); // Input from button 2

  pinMode(12, OUTPUT);  // Correct
  pinMode(13, OUTPUT);  // Wrong

  Serial.begin(9600);
}

void loop() {
  while (AttemptedPassword.length() < 8) {
    B0State = digitalRead(2); // Read data from button 1
    B1State = digitalRead(4); // Read data from button 2
    
    if (B0State == 0 && B1State == 0) {
      IsButtonRegistered = false;
    }
  
    if (B0State == 1 && !IsButtonRegistered){
      // 0 input from button 1
      
      AttemptedPassword += "0";
      IsButtonRegistered = true;
    }
    else if (B1State == 1 && !IsButtonRegistered) {
      // 1 input from button 2
      
      AttemptedPassword += "1";
      IsButtonRegistered = true;
    }
  }

  if (AttemptedPassword == CorrectPassword) {
    // Correct Password - Green Light
    
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  else {
    // Wrong Password - Red Light
    
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }

  delay(5000);

  AttemptedPassword = ""; // Reset Users attempts
}
