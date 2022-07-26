+++
fragment = "content"
weight = 100
disabled = false
+++

# Week 10 - Machine Building and End Effectors
## Building a Useless Machine
A "useless machine" is a project you often see at Maker Faires which generally look like a box with a switch. When a person flips this switch, a little robot arm will pop out of the box to flip it back and then return to the box.

I want to build one of these with a stepper motor, a limit switch, and a normal switch. When the normal switch is flipped, the motor will turn until it is flipped back. The motor will then have its zero position updated and rotate in the opposite direction until it hits the limit switch, at which point its zero is re-updated (and it will rotate a couple steps until the limit switch is un-pressed).

To start, I had to solder headers onto my [STSPIN220 microstepping bipolar stepper motor driver](https://www.pololu.com/product/2876). I also soldered female dupont connections to my [stepper motor](https://www.adafruit.com/product/324)'s wires so I can connect it to a breadboard.

<p align="center">
<img src="" alt="" width=/>
</p>

<p align="center">
<img src="" alt="" width=/>
</p>

<p align="center">
<img src="" alt="" width=/>
</p>

I wired the driver according to the [minimal wiring diagram](https://a.pololu-files.com/picture/0J9750.1200.jpg?018aeb688feed9c63fc87c5f22f17805) on pololu's website and then set the current limit to be 1 A by adjusting the VREF voltage screw to 0.2 V. I then wired the motor according to the minimal wiring diagram. The stepper motor's pins are the phases; pins 1 (orange wire) and 3 (blue) make up phase B and pins 4 (red) and 6 (yellow) make up phase A. The motor power supply is a benchtop power supply. `MODE1` and `MODE2` pins are hard-wired to LOW for now.

<p align="center">
<img src="" alt="" width=/>
</p>

<p align="center">
<img src="" alt="" width=/>
</p>

I wrote some test code just to rotate the stepper. The I tested a few various delays and a delay of 2 milliseconds seemed to work best. When the dirPin is LOW, the motor rotates anticlockwise, and clockwise when it is HIGH.

```c
// set pin connections
const int stepPin = 3;
const int dirPin = 4;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(dirPin, HIGH);
  digitalWrite(stepPin, HIGH);
  delay(2);
  digitalWrite(stepPin, LOW);
  delay(2);
}
```

{put a video here}

I wanted to experiment with microsteps, so I wired up the standby pin and changed `MODE1` to HIGH and added a bit of code in `setup` to tell the stepper to use half steps:

<p align="center">
<img src="" alt="" width=/>
</p>

```c
  // latch half step setting
  digitalWrite(stbyPin, LOW);  // enter standby mode
  digitalWrite(stepPin, HIGH);
  digitalWrite(dirPin, LOW);
  digitalWrite(stbyPin, HIGH);  // exit standby mode
```

The motion is jerky and current draw is up eightfold (from 25 mA to 200mA). I tested a couple different values and lowering the delay from 2 milliseconds to 0.25 milliseconds works better; current draw is now at the same 25-ish mA, motion is slower than with full steps but also smoother, torque is higher, and the motor only draws ~10 mA more when forcefully halted (as opposed to 75 mA more when using full steps).

I cleaned up a two-state, three-pronged switch I had and soldered some headers to it after some short, breadboard-compatible wires proved a bit too flimsy for my liking.

<p align="center">
<img src="" alt="The switch as I had it." width=/>
</p>

<p align="center">
<img src="" alt="The switch with breadboard-compatible wires." width=/>
</p>

<p align="center">
<img src="" alt="The switch with headers." width=/>
</p>

I'll be using the switch as a pullup input instead of a "normal" input even though it has three prongs because I'm not sure if I want to use this specific switch in a finished product, and more switches have two prongs than not (though this choice does mean that the third prong basically becomes a decoration).

I added a button to work as a limit switch, set it to also be a pullup input, and wrote some homing code utilizing it in `setup` after adding a mutable `steps` variable:

<p align="center">
<img src="" alt="The button and switch wired up." width=/>
</p>

```c
  // home motor
  limitState = digitalRead(limitPin);  // read limit switch state
  digitalWrite(dirPin, LOW);
  while (limitState == HIGH) {
    limitState = digitalRead(limitPin);  // read limit switch state
    // step motor
    digitalWrite(stepPin, HIGH);
    delay(1.5);
    digitalWrite(stepPin, LOW);
    delay(1.5);
  }
```

I changed the way the motor steps as well. Because the motor should always be able to move away from the limit switch if the toggle has been flipped, even if it is at home, this has a special if statement. For the motor to be able to turn towards the home position, first the limit switch can't be pressed and then the toggle has to be in the correct state. With this, the loop function looks as follows:

```c
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
```

Lastly, after playing around with different microstep fractions and wait times, using 1/8 steps with 1.5 ms delays for initial homing and half steps with 0.075 ms delays for everything else seems to strike a promising balance between torque, speed, and current draw (and this combination also enables `MODE1` and `MODE2` to be hard-wired).

With this, the code should be done!

```c
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
```