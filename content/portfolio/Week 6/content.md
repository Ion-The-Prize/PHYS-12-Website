+++
fragment = "content"
weight = 100
disabled = false
+++

# Electronic Input Devices

The input device that I wanted to use was a potentiometer. Specifically, I wanted to be able to control a DC motor based on the potentiometer input; to create something of a throttle.

I found [an old blog post](https://www.makersgeneration.net/single-post/2017/12/30/How-to-control-a-DC-motor-speed-with-a-Arduino-Uno-board-and-a-potentiometer) about doing just this. It includes this wiring diagram:

<p align="center">
<img src="Potentiometer-WiringDiagram.jpg" alt="Wiring diagram for controlling a DC motor with a potentiometer and arduino uno"/>
</p>

In this wiring, the transistor acts as a digital switch and the diode is needed for PWM. When the motor is turned off in a PWM cycle, it coasts instead of stopping, which makes it act as a generator and it generates *a lot* of energy (for a small amount of time), which is enough to damage the electronics. However, this "backflow" of energy flips the polarity of the diode, which then re-routes it, almost turning the motor into a resistor for itself. Once the motor has stopped acting as a generator, the diode routes everything back to normal and the cycle can repeat.

Foolishly, for my first attempt, I decided to solder everything up instead of using a breadboard.

<p align="center">
<img src="Potentiometer-SolderedWiring.jpeg" alt="Always test twice and solder once..." width=400/>
</p>

Now, I'm pretty sure that the transistor was backwards (an easy fix on a breadboard), but, even if this circuit worked, it would have set a bad precedant, so perhaps it's good that it failed.

So, I redid the wiring, this time on a breadboard.

<p align="center">
<img src="Potentiometer-BreadboardProperlyWiredOverview.jpg" alt="Overview" width=750/>
</p>

<p align="center">
<img src="" alt="Multimeter" width=750/>
</p>
I needed a secondary power source, so I alligator clipped-up a 5V wall adapter.

<p align="center">
<img src="Potentiometer-BreadboardProperlyWiredCloseup.jpg" alt="Closeup" width=750/>
</p>

I added a print statement to plot the potentiometer. Here is a plot of the potentiometer's inputs:

<p align="center">
<img src="Potentiometer-Plot1.png" alt="" width=/>
</p>

<p align="center">
<img src="Potentiometer-Plot2.png" alt="" width=/>
</p>

And the code:

<p align="center">
<img src="Potentiometer-Code.png" alt="" width=/>
</p>

The input appears a little jagged, but, once the graph rescales properly, it looks very smooth. And... it works! Here's a video: