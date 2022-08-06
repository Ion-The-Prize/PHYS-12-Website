// BTS7960 arduino h-bridge motor driver sketch 

// pins
// r and l are directions
// const int R_IS = 2;  // IS = tell you you're exceeding current (if device is overtaxxed)
// const int R_EN = 6;  // en = enable
const int R_PWM = 1;  // pwm = give less power
// const int L_IS = 4;
// const int L_EN = 5;
const int L_PWM = 3;

void setup() {
  // put your setup code here, to run once:
 // pinMode(R_IS, INPUT);
 // pinMode(R_EN, OUTPUT);
 pinMode(R_PWM, OUTPUT);
 // pinMode(L_IS, INPUT);
 // pinMode(L_EN, OUTPUT);
 pinMode(L_PWM, OUTPUT);
 // digitalWrite(R_IS, LOW);
 // digitalWrite(L_IS, LOW);
 // digitalWrite(R_EN, HIGH);
 // digitalWrite(L_EN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for(i = 0; i <= 255; i= i+10) { // clockwise rotation
   analogWrite(R_PWM, i);
   analogWrite(L_PWM, 0);
   delay(100);
  }
  delay(500);
  for(i = 0; i <= 255; i= i+10) { //counter clockwise rotation
   analogWrite(R_PWM, 0);
   analogWrite(L_PWM, i);
   delay(100);
  }
  delay(500);
}
