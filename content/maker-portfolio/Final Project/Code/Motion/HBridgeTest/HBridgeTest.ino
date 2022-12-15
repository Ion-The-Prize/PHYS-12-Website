// BTS7960 arduino h-bridge motor driver sketch 

// pins
// r and l are directions
const int R_IS = 4;  // IS = tell you you're exceeding current (if device is overtaxxed)
// const int R_EN = 6;  // en = enable
const int R_PWM = 3;  // pwm = give less power
const int L_IS = 7;
// const int L_EN = 5;
const int L_PWM = 5;

void setup() {
  // put your setup code here, to run once:
 pinMode(R_IS, INPUT);
 // pinMode(R_EN, OUTPUT);
 pinMode(R_PWM, OUTPUT);
 pinMode(L_IS, INPUT);
 // pinMode(L_EN, OUTPUT);
 pinMode(L_PWM, OUTPUT);
 // digitalWrite(R_IS, LOW);
 // digitalWrite(L_IS, LOW);
 // digitalWrite(R_EN, HIGH);
 // digitalWrite(L_EN, HIGH);
 Serial.begin(9600);
 Serial.println("Serial Begin");
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM, 255);
  delay(500);
  if(digitalRead(R_IS)){
    Serial.print("R OVERCURRENT @ ");
    Serial.println(millis());
  }
  if(digitalRead(L_IS)){
    Serial.print("L OVERCURRENT @ ");
    Serial.println(millis());
  }
  
  analogWrite(R_PWM, 0);
  analogWrite(L_PWM, 255);
  delay(500);
}
