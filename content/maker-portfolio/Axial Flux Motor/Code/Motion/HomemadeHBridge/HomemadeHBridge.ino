// BTS7960 arduino h-bridge motor driver sketch 

// pins
// r and l are directions
const int R_pwr = 7; // motor rightside control pin for letting + through (not PWM)
const int R_gnd = 6; // motor rightside control pin for letting - through (PWM)
const int L_pwr = 4; // motor leftside control pin for + (not PWM)
const int L_gnd = 3; // motor leftside control pin for - (PWM)

// variables
int max_power = 255;

void setup() {
  // put your setup code here, to run once:
  pinMode(R_pwr, OUTPUT);
  pinMode(R_gnd, OUTPUT);
  pinMode(L_pwr, OUTPUT);
  pinMode(L_gnd, OUTPUT);
  
  // digitalWrite(R_IS, LOW);
  // digitalWrite(L_IS, LOW);
  // digitalWrite(R_EN, HIGH);
  // digitalWrite(L_EN, HIGH);
  Serial.begin(9600);
  Serial.println("Serial Begin");
}

void rightPower(int power){
  analogWrite(R_gnd, 0);
  digitalWrite(L_pwr, LOW);
  digitalWrite(R_pwr, HIGH);
  analogWrite(L_gnd, power);
}

void leftPower(int power){
  analogWrite(L_gnd, 0);
  digitalWrite(R_pwr, LOW);
  analogWrite(R_gnd, power);
  digitalWrite(L_pwr, HIGH);
}

void noPower(){
  digitalWrite(R_pwr, LOW);
  analogWrite(R_gnd, 0);
  digitalWrite(L_pwr, LOW);
  analogWrite(L_gnd, 0);
}

void loop() {
  float power_frac = 1;
  int delay_time = 5000;
  // put your main code here, to run repeatedly:
  Serial.println("RIGHT");
  rightPower(255);
  delay(delay_time);
  noPower();
  delay(100);
  
  Serial.println("LEFT");
  leftPower(255);
  delay(delay_time);
  noPower();
  delay(100);
}
