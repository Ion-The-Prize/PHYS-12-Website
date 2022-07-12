int potentiometer = A0;
#define motor_output 6

void setup()
{
  Serial.begin(9600);
  pinMode(potentiometer, OUTPUT);
}

void loop()
{
  int control_motor = analogRead(potentiometer);
  analogWrite(motor_output, control_motor / 4);
  Serial.println(control_motor); // For debugging
}
