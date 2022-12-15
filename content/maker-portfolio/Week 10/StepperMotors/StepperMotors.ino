// set pin connections
const int stepPin = 3;
const int dirPin = 4;  // direction
const int stbyPin = 5;  // standby
const int limitPin = 6;  // limit switch (button) pin
const int toggleSwitchPin = 7;  // toggle switch pin

// variables
int limitState = 0;  // pushbutton value variable
float steps = 0;  // current stepper motor position
int switchState = 0;  // switch value variable

void setup() {
  // initialize stepper pins
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stbyPin, OUTPUT);
  // initialize input pins
  pinMode(limitPin, INPUT_PULLUP);
  pinMode(toggleSwitchPin, INPUT_PULLUP);
  
  // latch 1/8 step setting
  digitalWrite(stbyPin, LOW);  // enter standby mode
  digitalWrite(stepPin, HIGH);
  digitalWrite(dirPin, HIGH);
  digitalWrite(stbyPin, HIGH);  // exit standby mode

  // home motor
  limitState = digitalRead(limitPin);  // read limit switch state
  digitalWrite(dirPin, LOW);  // rotate anticlockwise
  while (limitState == HIGH) {
    limitState = digitalRead(limitPin);  // read limit switch state
    // step motor
    digitalWrite(stepPin, HIGH);
    delay(1.5);
    digitalWrite(stepPin, LOW);
    delay(1.5);
  }
  steps = 0;

  // latch half step setting
  digitalWrite(stbyPin, LOW);  // enter standby mode
  digitalWrite(stepPin, HIGH);
  digitalWrite(dirPin, LOW);
  digitalWrite(stbyPin, HIGH);  // exit standby mode
  
  Serial.begin(9600);
}

void loop() {
  limitState = digitalRead(limitPin);  // read limit switch state
  switchState = digitalRead(toggleSwitchPin);  // read toggle switch state
  if (switchState == HIGH) {
    digitalWrite(dirPin, HIGH);  // clockwise and away from limit switch (towards toggle switch)
    
    // step motor
    digitalWrite(stepPin, HIGH);
    delay(0.075);
    digitalWrite(stepPin, LOW);
    delay(0.075);
    steps += 0.5;  // using half step microsteps
  }
  if (limitState == LOW) {
    steps = 0;
  } else if (switchState == LOW) {
    digitalWrite(dirPin, LOW);  // anticlockwise and towards limit switch
    
    // step motor
    digitalWrite(stepPin, HIGH);
    delay(0.075);
    digitalWrite(stepPin, LOW);
    delay(0.075);
    steps -= 0.5;  // using half step microsteps
  }
  Serial.println(steps);
}
