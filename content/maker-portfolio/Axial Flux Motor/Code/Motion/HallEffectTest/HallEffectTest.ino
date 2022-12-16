// pins
const int S1Pin = A0;  // S1 analog input pin

int S1Value = 0;  // value read from the hall effect S1

void setup() {
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  S1Value = analogRead(S1Pin);

  // print the results to the Serial Monitor:
  //Serial.print("S1 = ");
  Serial.println(S1Value);
 
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
