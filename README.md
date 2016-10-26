# Arduino Tutorial - MasseyHacks II
I want a shirt
This tutorial will occur in 3 major steps

## Blinking Lights
#### Breadboard Layout
![Blinking Light Breadboard Layout](http://github.com/MasoudH/arduino-tutorial/tree/master/Blinking_Light/img/breadboard.JPG)
#### Code
Code is availble for download /Blinking_Light/Blinking_Light.ino
```
void setup() {
  pinMode(11, OUTPUT); // Output pin for Green Light
  pinMode(12, OUTPUT); // Output pin for Yellow Light
  pinMode(13, OUTPUT); // Output pin for Red Light
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
```

## Binary Password
#### Breadboard Layout
![Binary Password Breadboard Layout](http://github.com/MasoudH/arduino-tutorial/tree/master/Binary_Password/img/breadboard.JPG)
#### Code
Code is availble for download /Binary_Password/Binary_Password.ino
```
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
```

## Functioning Traffic Light
#### Breadboard Layout
![Functioning Traffic Light Breadboard Layout](http://github.com/MasoudH/arduino-tutorial/tree/master/Traffic_Light/img/breadboard.JPG)
#### Code
Code is availble for download /Traffic_Light/Traffic_Light.ino
```
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
```
