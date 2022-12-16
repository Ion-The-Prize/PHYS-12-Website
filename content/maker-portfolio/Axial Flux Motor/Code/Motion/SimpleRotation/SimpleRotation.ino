// BTS7960 arduino h-bridge motor driver sketch 

// pins
// r and l are directions
// const int R_IS = 2;  // IS = tell you you're exceeding current (if device is overtaxxed)
// const int R_EN = 6;  // en = enable
const int phase_a_R_PWM = 2;  // pwm = give less power
const int phase_a_L_PWM = 3;
const int phase_b_R_PWM = 4;
const int phase_b_L_PWM = 5;
const int phase_c_R_PWM = 6;
const int phase_c_L_PWM = 7;
const int hall_a = A0;
const int hall_b = A1;
const int hall_c = A2;
const int potentiometer = A3;
const int phase_a[6] = {1,1,0,-1,-1,0};
const int phase_b[6] = {-1,0,1,1,0,-1};
const int phase_c[6] = {0,-1,-1,0,1,1};
int cycle = 0;


void setup() {
  // put your setup code here, to run once:
 // pinMode(R_IS, INPUT);
 // pinMode(R_EN, OUTPUT);
 pinMode(phase_a_R_PWM, OUTPUT);
 pinMode(phase_a_L_PWM, OUTPUT);
 pinMode(phase_b_R_PWM, OUTPUT);
 pinMode(phase_b_L_PWM, OUTPUT);
 pinMode(phase_c_R_PWM, OUTPUT);
 pinMode(phase_c_L_PWM, OUTPUT);
 pinMode(potentiometer, OUTPUT);
 // pinMode(L_IS, INPUT);
 // pinMode(L_EN, OUTPUT);
 // digitalWrite(R_IS, LOW);
 // digitalWrite(L_IS, LOW);
 // digitalWrite(R_EN, HIGH);
 // digitalWrite(L_EN, HIGH);
}
  Serial.begin(9600);

void loop() {
  // put your main code here, to run repeatedly:
  int control_motor = 1024 - analogRead(potentiometer);

  // determine cycle
  /*
  int hall_a_val = analogRead(hall_a);
  int hall_b_val = analogRead(hall_a);
  int hall_c_val = analogRead(hall_a);
  */
  
  cycle++;
  if(cycle == 6) {
    Serial.println(control_motor);
    cycle = 0;
  }
  
  // set phase powers
  analogWrite(phase_a_R_PWM, phase_a[cycle]*255);
  analogWrite(phase_a_L_PWM, phase_a[cycle]*255);
  analogWrite(phase_b_R_PWM, phase_b[cycle]*255);
  analogWrite(phase_b_L_PWM, phase_b[cycle]*255);
  analogWrite(phase_c_R_PWM, phase_c[cycle]*255);
  analogWrite(phase_c_L_PWM, phase_c[cycle]*255);


  
  delay(control_motor);
}
