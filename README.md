# Arduino Tutorial - MasseyHacks II

This tutorial will occur in 3 steps

## Blinking Lights
#### Breadboard Layout
![Blinking Light Breadboard Layout](http://github.com/MasoudH/arduino-tutorial/tree/master/Blinking_Light/img/breadboard.JPG)
#### Code
File is availble for download /Blinking_Light/Blinking_Light.ino

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

## Functioning Traffic Light
#### Breadboard Layout

#### Code
