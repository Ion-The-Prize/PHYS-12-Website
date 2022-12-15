+++
fragment = "content"
weight = 100
#disabled = true
#hide = true

#headless = true

#background = ""
categories = ["Long"]
display_date = true
date = "2022-10-31" # yyyy-mm-dd

title-align = "left"
title = """<h1 id="leftTitle" style="text-align:left !important;">A DIY 3-Phase PM BLDC Axial Flux Electric Motor and Custom, Sensor-Based ESC</h1>"""
subtitle = """<h2 id="lightTitle"><font size="5" color="grey" font-weight="100"><i>What goes into making a speed controller for a BLDC electric motor?</i></font></h2>"""

summary = """ """

[sidebar]
	title = "Contents"
	sticky = true
	align = "right"
	#content = ""

#[asset]
	image = ""
+++

*n minute read*


-------


## Introduction

### Background

#### Motivation: Why did I choose this project?

To properly provide reason and motivation for choosing this project, some backstory is necessary. In early 2020, I made an electric scooter from scratch. There were two main reasons:

The first is that I commuted between schools a lot on my bike and thought this was inconvenient. Seeing as I could not (and still can not) drive, an electric scooter or bike made sense. This begs the question of why would I not just buy an electric scooter or bike (it’s not the cost; making it myself is way more expensive and especially for the quality of the product). Well, the second reason is that I had no idea how I would go about building such a thing, so I would learn a lot from doing it. (This is also part of why I made an electric scooter instead of an electric bike, as I had more of an understanding of how the latter worked.) The scooter itself was quite shoddy and not at all suitable for my commute, and I really only use it for very short rides when I’m feeling lazy or want fresh air. But that doesn’t really matter to me because I did indeed learn a lot from this project and had my eyes set on many exciting new ones.

As I was making the scooter, I was using some parts I didn’t make and didn’t completely understand (many of them electronics-based). I asked myself if I could really say that I had made the scooter from scratch if this were the case. I decided not and so, earlier this year, I made a DC electric radial flux motor from scratch using mostly 3D-printed parts. Why radial flux and brushless? Because I heard it was harder than a brushed motor.

Anyway, the motor hit almost 2000 RPM without breaking a sweat; it didn’t even get warm! And this was without an iron core! So I was happy, right? Wrong. To make it spin, I used a pre-made so-called “speed controller.” Because I simply can’t have that, I wanted to make a speed controller. But, because of the design of the motor I made, doing so with that motor would have been a lot more complicated than I was comfortable with (too big of a step up from my current skill level).

Of course, I do have to draw the line of “from scratch” somewhere and move on. Making my own speed controller? Seems productive. Making my own transistors? Seems debatably productive. Enameling my own wire? Perhaps not very productive.

So that brings us to today, where I designed a new motor just so that I can make a speed controller for it so that I can be one step closer to making an electric scooter completely from scratch.

*If you’re wondering why I decided to make a different style of motor (axial flux) instead of modifying the radial flux design, there are two main reasons: (1) axial flux is better for vehicles, and (2) it would be more challenging and therefore I would learn more.*

#### How do electric motors work?

Include a .gif of the drone motor guy’s video for the three phases
Goal of motor is to translate electrical energy into (rotational) kinetic energy
Moving electromagnetic field like a kind of Sisyphean light chase 
If the field is aligned with the permanent magnets, then the motor will not move, so we need:
3 phases so one will always be misaligned
to be able to turn the electromagnets on and off precisely
And we know where the permanent magnets are in relation to the electromagnets


#### Project Outline & Goalsetting

##### What are all those buzzwords in the title?

A DIY 3-Phase PM BLDC Axial Flux Electric Motor and Custom, Sensor-Based ESC
DIY = do-it-yourself (homemade)
3-Phase = a phase is a set of electromagnets being activated at the same time with the same polarity
PM = permanent magnet based
Axial flux - the style of motor (as opposed to radial flux). Axial flux means the magnetic fields of the electromagnets are perpendicular to the magnetic fields of the permanent magnets. Radial flux means they are parallel.  Axial Flux in wikipedia: "magnetic flux...is aligned parallel with the axis of rotation"
Motor - spinny thing
ESC - electronic speed controller - tells electromagnets when to turn on
Sensor-based ESC - the ESC uses sensors (in this case Hall effect sensors) instead of induction from the permanent magnets to know where they are


##### Research Question

The research question I seek to answer through this project is: “What goes into making a speed controller for a BLDC electric motor?”

##### Initial Project Goals & Overall Philosophy

This section is perhaps too important to be relegated to a 5th level heading which is haphazardly buried in the middle of a subsection, but I digress.

My overall philosophy going into this project is reflected in my research question, that is, with my primary focus being on learning above all else—including traditional measures of success. This has some notable ramifications beyond the face-value and perhaps even naïve hedonistic lusting for knowledge. In particular is wanting to keep things as bottom-level as possible and avoiding specialized components (hey, that’s very similar to this project’s motivation as well); I would rather dive deeper into a smaller number of subjects than gain a shallow understanding of a large number of subjects. Beyond personal preference, I also know that a deeper understanding is more transferable and configurable for me, and I can more easily re-tool and adapt that which I understand more completely. Additionally, specialized components are, well, specialized, and more restrictive in how much they can be adapted or re-tooled to begin with, regardless of depth of understanding.

That said, I do need to establish goals and criteria for success. These goals are as follows:
- Design & create an electronic speed controller for an electric motor
- Design & build an electric motor from scratch for the DIY ESC
- Program the DIY ESC to control the motor
- To learn, which should be evidenced through a blog post meeting the following:
	- Documents the project and its process with text, code, designs, explanations of code and of designs, pictures, videos, other graphics (e.g., animations), captions, and textual explanations
	- Is a minimum of a 4-8 minute read
	- Is neatly structured (or, at least, organized)
	- Contains a reflection section
	- (Optionally contains) a short summary video up to around 1 minute in length
- Create a presentation display for the motor

##### Kaplan Objectives


###### Change Over Time



###### Details



### Research

#### Annotated Bibliography
Each project must include a correctly formatted bibliography (without required annotations) with 3+ resources (Scholarly and/or peer-reviewed). Each must have a brief explanation of why I chose it. In addition, I must provide a brief remark on why I have the number of sources that I do (e.g. “I have 3 resources because there were very few resources on this specific area of my project”, or “I have 9 resources because this area of my project is controversial”). The style of citation I use should reflect my topic (science topics use APA, literature use MLA etc.)

J. F. Gieras, R.-J. Wang, and M. J. Kamper, *Axial Flux Permanent Magnet Brushless Machines*, 2nd ed. New York City, NY: Springer, 2008.
> I selected this source because of its outstanding depth despite its also amazing breadth. Its incredibly thorough information is, at minimum, kind of useful for pretty much every aspect of this project as well as possible future, related ones and, at maximum, just what I need for many circumstances. This amazing wealth of information it provides is also rock solid with plenty of citations. The authors are also highly credible.

[^Gieras]: J. F. Gieras, R.-J. Wang, and M. J. Kamper, *Axial Flux Permanent Magnet Brushless Machines*, 2nd ed. New York City, NY: Springer, 2008.

Atmel, “Atmel AVR443: Sensor-based Control of Three Phase Brushless DC Motor,” 2596C−AVR−07/2013, Circa 2005 [Rev. July 2013]
> I chose this application note as a source because of its almost perfect relevance to my project—controlling a BLDC motor with Hall-effect sensors. Additionally, it is extremely reliable as a source, being a continually revised application note.

[^Atmel-AVR443]: Atmel, “Atmel AVR443: Sensor-based Control of Three Phase Brushless DC Motor,” 2596C−AVR−07/2013, Circa 2005 [Rev. July 2013]

Monolithic Power Systems Inc., “Brushless DC Motor Fundamentals,” AN047, Jian Zhao and Yangwei Yu, MPS: The Future of Analog IC Technology, July 2011 [Rev. May 2014]
> This is another application note and therefore very credible. This source is particularly useful for programming the phases and providing some intuition into that, but also contains generally good and relevant information for my project.

[^MPS]: Monolithic Power Systems Inc., “Brushless DC Motor Fundamentals,” AN047, Jian Zhao and Yangwei Yu, MPS: The Future of Analog IC Technology, July 2011 [Rev. May 2014]

-------
[] DigiKey, “How to Power and Control Brushless DC Motors,” 2016-12-07
https://web.mit.edu/kirtley/binlustuff/literature/electric%20machine/designOfAxialFluxPMM.pdf
http://www.stefanv.com/electronics/escprimer.html
https://vedder.se/2014/01/a-custom-bldc-motor-controller/

I have _ resources because a very good portion of this project I learned by doing and through hobbyist spaces and resources, which are not scholarly.

----------

With that all out of the way, let’s take a look at the actual project:


## The Design

|	![Gif revealing real motor overlaid on CAD drawing](<./Documentation Graphics/Designs/CAD-Drawing-and-Real-Life-Comparison.gif>)	|
|	:--:	|
|	A short animation I made showing how the CAD model was translated into real life.	|

### Philosophy

My general philosophy when designing the motor itself was to make it as modular as possible without sacrificing effectiveness. What this means is that I knew that I did not have all the materials I needed or would need in case I discovered some new improvement, and would want to minimize time spent redesigning everything. For example, the coils are designed to have replaceable cores so, with one design, I can turn my air cores into iron cores once I get access to either lost PLA iron casting or some other tooling method like a 5-axis CNC capable of milling cast-iron or just plain old iron casting.

### The Motor

The motor is made up of two main systems: the rotor which rotates and the stator which is stationary. These, of course, have their own niches, purposes, and subsystems in turn (see what I did there) and there are other parts, but the rotor and stator are the main ones and their high-level job is to simply rotate or not rotate.

#### [Vitamins](https://reprap.org/wiki/Category:Vitamin)

Some parts of a motor cannot be 3D printed (the shaft, bearings, fasteners, wires, shaft collars, magnets, sensors, etc.) but are still planned for and included in the design. It is important to do this for many reasons, including but not limited to: aiding with assembly, ensuring that the correct size vitamins can be purchased, planning for vitamins already owned, and effectively planning the layout. The last of these—effectively planning the layout—is especially important for this motor as size is constrained. For the motor to be as efficient as possible, the coils need to sit as close to the permanent magnets as possible. So, the bottom of the stator needs to be completely flush to accommodate this. This requirement necessitates a lot of countersinking (among other things) and was always something to consider while I was designing the motor.

That said, I only very recently modeled in a lot of the vitamins. I had modeled in some previously—the magnets, bearing, shaft, and shaft collar—but, because I could accommodate and plan for them without a model just as easily as I could with (and I was tight on time), things like nuts and bolts were not a priority.

##### THE EVERYBOLT (patent pending)\*

\*patent not actually pending

This bolt sent me down such a deep rabbithole. As I was making it, I had these small ideas for things that I wanted to do and ended up learning about these large parts of the software I use and then I would have more ideas and I learned so much because of the decision to design a bolt,  which is kind of even more incredible given how simple of a part it seems to be. And there’s even still many more ideas I have to improve ***THE EVERYBOLT*** which I truly cannot wait to implement.

Because of how useful a part ***THE EVERYBOLT*** turned out to be and how deep the scope ended up being, I actually moved it out of this project and have turned it into a project of its own. (It should be said that I ended up not actually using ***THE EVERYBOLT*** in this motor project as of right now because of this increase in the scope of ***THE EVERYBOLT***—I had my eyes locked on a new toy and gave it more attention, and used the fact that it is technically an incomplete part and its alternatives (that I could find) utterly inferior as justification for not using it.)

But, I digress. Here is ***THE EVERYBOLT*** and its features.

Image of the bolt (or, even better, a .gif of it rotating with detail and without detail or maybe a half and half of with detail and without detail and it changes size while maintaining the same length)

*It is the everybolt
> The bolt is an iPart, a factory part, which contains specifications for the various sizes involved in a bolt (head diameter, height of head, etc.) for many (*many*) metric bolt sizes (M3, M4, M2.5, M40, etc.). Just drop the bolt into an assembly and say what size you need and everything else is filled in for you—no more need to have dozens of separate models and files for every different bolt type.
Custom shaft and transition lengths
> Both the length of the threaded shaft and the length of the unthreaded part of the shaft are individually adjustable upon placing the bolt an assembly
Handy defaults
> For each bolt size, the most common threaded shaft length and the most common unthreaded shaft lengths are filled in by default.
Adjustable detail levels
> Sometimes you want to make a pretty presentation. Sometimes you have 254 bolts and you don’t want to make s’mores with your computer. With the click of a button (multiple buttons), this one bolt model can accommodate both of these desires by turning on/off modeled threads (extra geometry as opposed to an image of threads), any knurling, and modeled .
Places itself where it’s needed in assemblies all in one move with iMates 
> When you’re designing a part, you can’t put other parts in it, that’s what assemblies are for. This is sometimes inconvenient because you may forget that a bolt goes somewhere and you’d like to be able to indicate that in your part in a way that the program understands. Or if you just want to add the bolt and put it where it’s meant to go in one move as you drop it in instead of adding each bolt to the assembly and then telling each one, individually, where it’s meant to go, which is *very* convenient if you have several bolts. This is where iMates come in. The bolt has one half of the constraints that would be necessary to place it where it’s meant to go on a different part (its centerline and its bearing face). When you’re designing another part that’s meant to have a bolt, you can put the other half of the constraints in (basically, “this surface will touch an M5 bolt’s bearing surface” and/or “this line will be an M5 bolt’s centerline”). If this is done, when a bolt is dropped into the assembly, it’ll go in the correct place(s). Alternatively, these half constraints can be used to add and place a bolt into an assembly in one motion, just add bolt to assembly, click where it’s meant to go, move onto next bolt, as easy as 123..
(Coming Soon) Imperial sizes
> It is just a metric bolt right now, but SAE/imperial sizes are super easy to implement. I am still undecided on whether I want SAE and metric in one bolt. On the one hand, having changes made to one be applied to the other is really appealing. But, on the other hand, it’s likely that projects will be either entirely imperial or entirely metric and not a mix, so it would be kind of pointless to have just one bolt for both purposes. In all likelihood, I’ll put both sizes in one bolt file until I can find some way to keep my changes synced between two separate files, at which point I’ll go with that. 
> I am adding this here after learning more about Derived features, and it seems like that is definitely the way to go for having parts/assemblies with some common features but some different ones. I am not sure if it works with iPart factories yet, but I don’t see why not.
(Coming Soon) Bolt Hole iFeature
> EZ Bolt Holes! While a configurable bolt is great (I’d even say outstanding), it’s kind of useless unless the hole it goes into doesn’t also change to accommodate different sizes. The shaft hole is easy—it’s what the bolts are named after—an M5 has a 5mm diameter shaft, an M3 a 3mm diameter shaft, an M2.5 a 2.5mm shaft, an M20 has a, you guessed it, 20mm diameter shaft. The same is true even for SAE (imperial) bolts—a 5/32 bolt has a shaft diameter of 5/32 in. Any countersinking does not follow such a pattern (otherwise an everybolt would be less amazing). Being able to tell a hole that it is an adjustable hole based on a bolt that will go in it would be wonderful (almost as wonderful as an adjustable bolt, perhaps), and it seems like [iFeatures](https://knowledge.autodesk.com/support/inventor/learn-explore/caas/CloudHelp/cloudhelp/2019/ENU/Inventor-Help/files/GUID-C2D08AAD-D86D-4720-96E4-8E0DA7374BE9-htm.html) make such a thing possible.
(Coming ???) Different head styles
> Imagine a world where there is just one bolt to drop in for every head type—from socket cap, to button, to flat, to hex, to hex washer, to slotted hex washer, to oval, to truss, to round, to pan, and everything in between—on top of every size so that separate files aren’t even needed for these different head types. Such a world would truly be utopic.
> However, the method of storing different bolts’ sizes in one file I used is 
> In preparation for when it becomes possible, all necessary features of the bolt are already properly independent of one another to make this happen (if they weren’t and the shaft were dependent on the head for example, then if, say, the socket cap head was suppressed and the hex head enabled, then, if it did not just cause an error, the entire shaft would be suppressed along with the socket cap head, leaving just a floating hex head). That said, it may be impossible with the current implementation of iParts and it’ll likely also need for there to be different (derived) parts for the different head shapes.
(Coming ???) Different [drive types](https://en.wikipedia.org/wiki/List_of_screw_drives)
> Just like how I would like for there to soon be just one bolt model file to drop into assemblies for every head type as well as every size, soon there will also be just one bolt model file for every type of driver (phillips, flathead, hex, star, triangle, oval, etc.). Also just like the different head styles, all necessary features are already independent of one another (there will be a hole for the driver whether or not there’s a head to cut into, much less a specific head type).
> 
(Coming ???) Measurement tolerances
> Not all bolts are made equal. Some are smaller than they’re meant to be and some are larger than they’re meant to be. The people that designed bolts were smart and accounted for these differences in machining quality. Every measurement has a minimum and a maximum built into the standard. Inventor also has tolerances built into it for such cases. But it doesn’t seem like Inventor supports tolerances with iParts, which sucks. So, until this is added, I just use the largest of the measurements as outlined in the standard for the everybolt so that it is never under-toleranced for. And if a bolt is ever needed for an ultra-high precision use case and tolerances are not supported for iParts yet, I will simply use an inferior onlybolt (just a normal bolt).
(Coming ???) Scaling bolt specification label
> Like how Inventor doesn’t seem to support measurement tolerances with iParts, the text feature is quite limited for modeling for my purposes. It seems like the modeling text tool was ported directly over from Inventor’s CAD drawing capabilities. For CAD drawings, standards are enforced depending on the style being used and so Inventor enforces these standards. This includes fixed options for text size (and among all the standards, the largest size is still quite small). This is fine for drawings, but not for modeling and makes labeling the heads of the different sizes of bolts with nicely sized labels impossible, not even to consider a label based on  p. And labeling the bolts (by diameter, pitch, and length) is trivial, but sizing the labels is problematic. That said, I’ve looked and but still don’t know if bolts’ labels are scaled, but, for readability, a percentage scale would be nice.

##### The Everynut

Like THE EVERYBOLT, the idea behind the Everynut is to have one component which I can drop into assemblies and select the type and size of nut I want (M4 locknut, M3 jam nut, M24 wing nut, etc.). Also like THE EVERYBOLT, accomplishing this how I want to is likely impossible in the current iteration of Inventor.

As of right now, the Everynut is all sizes of standard metric nuts.

##### Other Vitamins

For what the motor needs (not the ESC), there are a couple vitamins of particular note:
Shaft collar
Bearings
Permanent magnets
“Drive magnets” - magnets whose magnetic fields will be used to spin the rotor
“Halbach magnets” - magnets whose magnetic fields will be used to concentrate the magnetic fields of the drive magnets in a [Halbach array](https://en.wikipedia.org/wiki/Halbach_array) (basically black magic)
“Sensor magnets” - small magnets offset from the drive magnets and which have the same polarity so as to be read by the Hall effect sensors
Bolts
Hex Nuts
(optional) Square nuts
Shaft
Copper wire
Other than this, it’s all 3D printed. Well, part of the coils is laser cut acrylic, but it’s designed to be 3D printed. There is not really anything all that exceptional regarding the modeling or design of these parts themselves (other than the Everybolt & Everynut)... they just sort of are modeled to match the real thing without creativity.
#### Rotor

##### The Rotor’s Jobs & Purposes

Rotate!
Hold permanent magnets
Have an interface that wheel/spokes can attach to

#### Stator

##### The Stator’s Jobs & Purposes

Stay still while rotor rotates
Attach motor to shaft
Hold electromagnets & electronics

##### Coils

###### Cores: Iron vs Air

If you wrap copper wire around something and apply current, you get a magnet. If you wrap copper wire around a nail and apply current, you get a better magnet. To understand why this is, one should first have somewhat of an understanding of how magnets work.

Just like how copper is more electrically conductive than air, iron is more “magnetically conductive” than air (“conductivity” for magnets is called magnetic permeability).

A magnet’s magnetic field is the space around the magnet that experiences a magnetic force. This field could be thought of as a cloud of a bunch of lines that loop from one pole of the magnet to the other and passing through the magnet’s center by necessity. However, while many of these loops remain relatively close to the magnet, some go very, *very* far away. Because the “field lines” that go so far away are less numerous than the ones that are close to the magnet, the strength of the magnet is dependent on distance—closer is stronger because the magnetic field is denser and farther is weaker because the magnet field is less dense. These same rules apply for electromagnets; after all, electromagnets are basically just generators of magnetic fields you can turn on or off. (“Generators of magnetic fields” is just a long-winded way of saying permanent magnets.)

Just like how conductivity is useful because it can be used to control where electricity goes, magnetic permeability is useful because it can be used to control where magnetic field lines go—just like how electricity follows the path of least resistance and would therefore “rather” flow through copper than the air, so too do magnetic fields who would “rather” flow through iron than the air, should each of electricity and magnetic fields’ respective options be available.

These ideas—of a dense magnetic field being strong, iron controlling where magnetic fields tend to, and the magnetic field of a magnet necessarily traveling through the magnet’s center—can be combined to create more powerful electromagnets. By placing iron at the core of an electromagnet, the magnetic field will want to be there more and it will also want to generally stay close to the electromagnet more so that the distance it has to travel to return to the center is as small as possible because traveling a short distance takes less energy than traveling a large distance. This has the effect of making the magnetic field denser closer to the electromagnet and less dense farther from the electromagnet.

----------

Nitpicking unimportant to the explanation:

It should be noted that the magnetic permeability of the iron does not, on its own, alter the “number of magnetic field lines” and therefore the total strength of of the electromagnet; all the magnetic permeability of the iron does is alter where the magnetic field tends to be and therefore make the magnet stronger closer to the electromagnet but also weaker farther away from the electromagnet; however, because we only care about the strength close to the electromagnet, we simplify this by saying that an iron core makes the electromagnets stronger.

Nitpicking even less important to the explanation:

Also technically, an electromagnet with an iron core is stronger than an electromagnet without an iron core but which is otherwise equal. This is because the electromagnet induces a magnetic field in the iron (or, more accurately, aligns the magnetic fields of the iron to give it a nonzero net magnetic field in line with the magnetic field of the electromagnet) which “adds to the total number of magnetic field lines” and this effect alone is akin to adding a permanent magnet core; however, while the strength of the combination of the magnetic fields of the electromagnet and effective permanent magnet is greater, the strength of the magnetic field of *just the electromagnet* is unaffected by the addition of the effective permanent magnet. But to call the main statement of the explanation incorrect for this reason would be extremely nitpicky (perhaps as evidenced by the fact that I needed to carefully word the first sentence of this paragraph for this point to be technically true).

###### Motivation: Why coils aren’t just “bare”?

Many axial flux motors I see don’t have a spool still attached to the coils.[^Gieras] Instead, the wire is glued or otherwise fused together to maintain its shape and these bare coils themselves are affixed to a frame (the stator). This—the having of coils independent of and without individual spools—is for good reason, too, as magnetic strength falls off not with the inverse square of distance but with the inverse cube of the distance which means that even a small separation can have a pretty major effect on efficiency; therefore, the permanent magnets can be made to sit much closer to the coils by not having spools but instead bare coils; however, as my motor was designed to be a good, easily modifiable prototype with an emphasis on modularity, gluing coils to the stator seemed counter to that to me.

This consideration culminated in the question of “how can I make the spools swappable while sacrificing as little efficiency as possible?” as I was designing the motor. I settled on 2mm thick spools attached to the stator with bolts. And the stator would have “arms” in each of the coils’ acceptor spots that the bolts could sit in, and the coils’ spools would have negatives of those arms “cut” into them so they can be as flush with the “bottom” of the stator and therefore as close to the permanent magnets as possible.

###### The Actual Coil Design

119 turns of 20 gauge wire


Is based off the stator’s sketch and done in a way that kinda sucks from a design perspective even more than how the stator sucks tbh
Combining 3D printed parts with laser cut parts
ASA especially useful here because they get the hottest out of any part of the motor
Warping of ASA


As I did not have access to either casting or iron filament my initial plan was to just use air cores. but was unable to tighten the bolts holding the spools in because the stator spider’s plastic was too weak. I did what I could in CAD with fillets and such without sacrificing coil volume, but that meant only horizontal fillets which didn’t do much against the vertical force of the bolt. I’m new to stress analyses and so did not optimize the design procedurally based off of one, but I did make a [stress analysis report](./Documentation Graphics/StatorBody.ipt Stress Analysis Report 10_31_2022.html) to document it.

As a perhaps next-best option, I made some plastic cores to act as standoffs. These were not only good for protecting the stator spider and holding the coils down, but were also great prototyping for the design of iron cores that I’ll later use as these had to go through a couple revisions before working nicely:
image of real life revisions first to add an indent for the stator spider and then to chamfer the top face because the glue holding the coil 
Problems with fillet radius & offsetting for the coils (fillet radius of outside corners was the same as the offset distance between the outer and inner, which meant no fillet on corners which was bad because it might damage the wire’s enamel, so the inside was filleted after the offset which left wasted space some images would be good to include here; that show what the offset of outside to inside looks like (with sharp points) and what offset of filleted inside to outside looks like (with excessive rounding) and possibly the original and the very rounded overlayed on top of each other with the extra space highlighted)
Kinda hard to wrap evenly
Would like to model grooves into spools to get a good start
Would like to make the height based on wire gauge as well so that the bolts holding coils in can be flush with top rotor
Would like to use heat-set inserts on coil lids instead of nuts so that it can be flush with  top rotor
Is this the best number of turns and wire gauge? What about n-stranded wire of a thinner gauge? Who knows! That’s why I want to do some simple research about this

##### Reflecting on the Stator’s Design

Both the stator and the coils kinda suck from a design perspective in that they’re difficult to modify and adapt. Knowing what I now know about CAD, I’d like to make both the coils and the spots the coils go in the stator adaptive based on common sketches. The coils should also be an assembly full of adaptive parts (core, spool, wire, spool’s “lid”) instead of a part with multiple components (because it is surprisingly limiting and I don’t quite understand how to use components). These all necessitate redesigning the stator and coils both from the ground up, but this is honestly kind of a welcome thing and more standardization would be good.
Actually, having learned more about derived parts and assemblies, that seems like the way to go; one part for the stator and coils. And the stator can even be two derived parts itself; since the stator is made up of two halves which share many features but not all, there could be a “master” part with all these features and then two derived parts with unique features (like, one would have the mount for the hall effect circuit board and the other would have spots for trapped nuts).

## Electronics


### Motion (The ESC)


#### General Layout

I made this (very) rough layout of what all of the electronics will eventually look like, including the regeneration circuit, in Lucidchart:



#### H-Bridges, a Lesson in Expectation & Reality, and Trouble (oh, so much trouble indeed)

| ![Off the shelf arduino H-bridge BTS7960](<./Documentation Graphics/>) | 	| ![My janky DIY H-bridge circuit](<./Documentation Graphics/>) |
|:----------------------------------------------------------------------------------:| --- |:-------------------------------------------------------------------------------------------:|
| Expectation: being able to create something like this neat, clean, tidy, and further synonyms highlighting the organization of the off-the-shelf arduino BTS7960 H-bridge components                                                                              	| vs  |                                       	Reality: a bird’s nest of wires stuck into a breadboard with indicator lights which do indeed indicate, among other things, a lack of confidence in one’s work                                    	|

It is somewhat misleading for H-bridges to be a subsection of the greater ESC section because all the ESC really boils down to (not counting regenerative breaking) are H-bridge circuits and H-bridge code. At least, at my current understanding this is the case.

So, what is an H-bridge?

##### What an H-bridge is

Description of H-bridge (goal: turn DC to AC, does this with MOSFET screwery)

|	![Cyril B’s graphic for the structure of an H-bridge](https://upload.wikimedia.org/wikipedia/commons/d/d4/H_bridge.svg)	|
|	:--:	|
|	Structure of an H-bridge (highlighted in red; kinda looks like the capital letter “H”) from Wikipedia’s H-bridge article. The M represents a motor (or a single phase of a motor’s) with its two inputs.	|

##### Off-the-Shelf arduino BTS7960 H-bridges
###### † Initial Experimentation

Arduino’s H-bridges seemed like a great tool and perfect for the job I had in mind, at least to get things working initially before making them from scratch as well if I had time.

L_EN and R_EN are both just wired straight to 5V because, as long as PWM is done correctly (only one at a time), this is fine.
L_IS and R_IS are current alarms and won't be used.
This is partly to save pins, as three H-Bridges are needed.

```arduino
// BTS7960 arduino h-bridge motor driver sketch

// pins
// r and l are directions
// const int R_IS = 1;  // IS = tell you you're exceeding current (if device is overtaxxed)
// const int R_EN = 2;  // en = enable
const int R_PWM = 3;  // pwm = give less power
// const int L_IS = 4;
// const int L_EN = 5;
const int L_PWM = 6;

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
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for(i = 0; i <= 255; i= i+10) { // clockwise rotation
   analogWrite(R_PWM, i);
   analogWrite(L_PWM, 0);
   delay(500);
  }
  delay(500);
  for(i = 0; i <= 255; i= i+10) { //counter clockwise rotation
   analogWrite(R_PWM, 0);
   analogWrite(L_PWM, i);
   delay(500);
  }
  delay(500);
}
```

Video of magnet flipper captioned with something like “our trained mechano-wildlife videographers were able to capture the ever-skittish magnet in its natural habitat where it performs a jumping dance to spread its field in the hopes of attracting a mate of opposite polarity. Once it spots us, it attempted to flee.”

Initial results were clearly promising! But, this did not last very long at all.

###### Further Testing and Uncovering Issues

If the magnet was flipped at even a fraction of the rate you’d expect from a motor, the BTS7960 H-bridges got hot quite quickly (even with their massive heatsinks). This is apparently a known issue, and, despite their large size, the heatsinks are actually kind of useless because they are connected to the things on the circuit board that get hot (the MOSFETs) through *an insulator* for some unknown reason. Some have tried to get around this by going so far as to sand down the circuitboard coating so they can put solder in the vias to allow heat to get to the heatsinks more easily hyperlink this[HERE]. I tried thermal paste. No fue lo suficientemente bueno. Also for some reason, the backs of the MOSFETs are connected to one of their pins meaning that, should the backs touch anything metal they’re not meant to (pretty much anything), including the *metal* heatsinks mind you (if you, say, sanded too deep or didn’t use a [yes to heat, no to electricity thermal pad](hyperlink this)), it could shortcircuit and destroy everything. But I’ll get to the MOSFETs later.
Okay, rant over. The point is, apparently [the BTS7960s are not rated for as big of motor as mine is without modification](hyperlink this [same link as above]). It may (may) have been an issue related to a common ground, though I can’t say for sure.

##### Introduction to My DIY H-Bridges

“Heat’s a problem with these specialized circuits because they are not designed for this application and are unconfigurable so I’m going to do as this project’s overarching philosophy preaches and break them down into their base parts so I can understand and make them myself. They’ll be even more custom and also won’t have the issue of getting too hot and will be easy and quick and fun to make.” … is approximately what past me thought to herself, so full of optimistic naïveté. She was right about one out of three things though: they were kinda fun to make (though the jury’s still out on that). I was also going to make one myself eventually anyway, I just didn't expect to be doing it now.

On the bright side, I did indeed follow this project’s overarching philosophy in this way but also another—I dove deeper into a single something rather than shallowly into several somethings. I’ll talk about that more in the reflection, but the important thing now is that single something I learned a lot about: MOSFETs.


### DIY H-Bridges

Ah, the reality half of “Expectation vs. Reality,” what a marvelous, messy, and marvelously messy side of things. So much excitement—or disappointment, depending on how you look at it—over here. The suspense of not knowing how the potential will be realized. More flowery introductory sentences that raise expectations to those for a light, poetic reading experience as a sort of meta-commentary on expectations contrasted with reality through the rhetorical irony of that divide being perpetuated by a thought making commentary on it and the absurdism of—okay I’ll stop, I’ve had my fun. Where was I? Oh, right, MOSFETs <sup>~~hey, it’s a hypophora~~</sup>

First though, my making of my own H-bridge circuits ended up being much more involved than originally thought (which really shouldn’t be all that surprising to me at this point) so I promoted its heading to get more subheading options and include more details!

#### *How* an H-bridge is

I explained earlier what an H-bridge is and does in a sort of hand-wavey fashion. Let’s do the (more) nitty-gritty now.

|	![H-Bridge circuit diagram](<./Documentation Graphics/Electronics/H-bridges/H-bridge circuit schematic KiCad.svg>)	|
|	:--:	|
|	Circuit schematic for my DIY H-bridges made in KiCad.	|

Download the KiCAD files here




#### Creating an H-bridge

As sometimes painful as it was to make the H-bridges, It did feel good to make my own circuit without following any online tutorial. It reminds me of when MCAD was just starting to “click” for me after I had a handle on the basic features. It’s nice to have even just a small amount of the understanding I now do with MCAD with electronics.

--------

That said, I definitely did ride this high and overestimate my understanding of things initially. My first attempt at the circuit had all MOSFETs in a row on the breadboard to give myself some more room:

| ![arduino uno connected to H-bridge on breadboard and electromagnet](<./Documentation Graphics/Electronics/H-bridges/V0 Linear Progress 1.jpeg>) | ![arduino uno connected to breadboard with MOSFETs](<./Documentation Graphics/Electronics/H-bridges/V0 Linear Progress 2.jpeg>) | ![arduino uno connected to breadboard with MOSFETs](<./Documentation Graphics/Electronics/H-bridges/V0 Linear Progress 3.jpeg>) |
|:-----------------------------------:|:-----------------------------------:|:-----------------------------------:|

…but I didn’t know the circuit had diodes in it because I didn’t fully understand it at this point (there was another major issue with it, too). But, even though what I had made was not an H-bridge circuit, it was a circuit I had made without a tutorial or assistance, and so it gave me some more undeserved confidence and I was excited and ready to try again.

So great was my overestimation in my ability and understanding that in my next attempt at the circuit, I made it compact. So compact, in fact, that I see now in hindsight that it actually had a function I was unaware of at the time and which it performs surprisingly well; that is, it acts as a display of my then-gross overconfidence.

|	![The second draft of my H-bridge circuit](<./Documentation Graphics/Electronics/H-bridges/V1 Dense Breadboard Angle Top.jpeg>)	|
|	:--:	|
|	A monument to my hubris: the second draft of my H-bridge circuit using IRLZ34N MOSFETs on a breadboard which I wired up *moderately densely*.	|

| ![Another angle of the 2nd attempt at an H-bridge](<./Documentation Graphics/Electronics/H-bridges/V1 Dense Breadboard Angle Top2.jpeg>) |
|:-----------------------------------:|




So yeah, big mistake. I was thinking about 3 things when deciding to go down this route:
1. Doubt—because I'm going to be making it into a protoboard anyway, it's also going to become small and compact anyway no matter what I do therefore there’s no reason to not make it big now
2. Flashback—when a tutoring student says "okay, I understand it now, give me a hard one!" you never give them a really hard one without confirming that they’re ready somehow. Never.
3. Deja Vu—when I was starting with MCAD (and even now still) and thought I finally had a handle on something and could imagine how to make a design and the steps involved, the steps I imagined could indeed be done, but the method turned out to be bad or inefficient, and that the feeling of understanding I first had with MCAD was the same as my feelings in the moment.

But, “it’s such a simple circuit,” I thought. "It's fineeeeee." So oh well, I learned my lesson: breadboards are, among other things, drafting tools and so making drafts easily editable is the point, so don’t fight that.

I thought I could fight that because I had seen many examples of breadboards which were completely packed full of stuff and still worked perfectly, and I thought that was quite cool. However, the key difference between those and mine is that mine is the first draft, not the final one. They also have experience. And custom-cut wires (not exclusively “prototyping” jumper wires). And ECAD.

That last one is really important for compact circuits on breadboards because dense circuits are, for most all intents and purposes (and especially for someone like me who is inexperienced with electronics), read-only and pretty much undiagnosable because it’s hard to trace connections. I did catch *some* errors in mine (flipped diodes, wrong rail jumped to, possible short) thanks to a multimeter and sketching out the circuit:

| ![Dense H-bridge circuit on breadboard next to sketch of the H-bridge circuit](<./Documentation Graphics/Electronics/H-bridges/V1 Dense Breadboard Next to Layout Sketch.jpeg>) |
|:---------------------------------------------------------------------:|
|                            Having a plan helps. Also, hey, that looks like an “H” now.                      	|

Interestingly, the dense circuit did actually cycle the voltage like it was meant to, just no where near as much as it should have:

| ![Using a multimeter on the compact H-bridge circuit](<./Documentation Graphics/Electronics/H-bridges/V1 Dense Breadboard Voltage Fluctuation Too Small.mp4>) |
|:---------------------------------------------------------------------:|
|                            The dense H-bridge’s voltage switching performance.                         	|

| ![Manually giving and removing power from MOSFET control pin to test it](<./Documentation Graphics/Electronics/H-bridges/V1 Manually Switching MOSFET.mp4>) |
|:---------------------------------------------------------------------:|
|                            The voltage across a MOSFET when I manually connect its control pin to power and ground.                         	|

If I had to guess, I’d say the MOSFETs were being switched outside of the optimal pattern. Of course, I didn’t confirm this because it was not worth it to me to try to decipher my mess.

Regardless of the errors that I did catch, I did fundamentally misunderstand MOSFETs that made me not actually understand the H-bridge circuit. I am actually glad I had this misconception because, had the dense circuit worked, a bad habit would have been reinforced or possibly born.

##### **G**ate, **D**rain, and **S**ource
*A ~~Tragedy~~ Story of Electricity and Learning in Three Parts*

A MOSFET, a metal–oxide–semiconductor field-effect **transistor**, is a type of transistor, a digital switch. I had thought they were like a doorway—people can go through both ways if the door is open and cannot go through if it is closed. Indeed, some do work this way, but those are special cases. The more broad case has a Source, a Drain, and a Gate. If the gate receives voltage, the FET allows current through. However, that current can only flow in a specific direction: the electrons enter through the Source and exit through the Drain. In other words, if the drain side must be the grounded side and more negative than the source side and if it’s not, current will not flow.

Also, remember how I said that the backs of the MOSFETs are connected to “one of their pins” for “some reason” and that “I’ll get back to MOSFETs later.” Well, later is now, the pin the metal backs are connected to is the drain pin (i.e., ground), and so it is based in some logic (establishing common ground is often important). Personally, I am not advanced enough in electronics to appreciate this decision so it will still bug me.

##### Remaking the H-Bridge Circuit Properly to Make it Useful

On top of spreading things out, I thought it would be clearer if I doubled up the breadboards so only the outer rails are used on both sides and let me just say, there’s a reason entropy wins in the end. Although, in this case, I’d say it actually has less disorder spread out:

| ![Organized DIY H-bridge circuit on breadboard with just signal connections and components](<./Documentation Graphics/Electronics/H-bridges/V2 Spread Out Breadboard Progress 1.jpeg>) | ![Organized DIY H-bridge circuit on breadboard with all connections](<./Documentation Graphics/Electronics/H-bridges/V2 Spread Out Breadboard Progress 2.jpeg>) |
|:-----------------------------------:|:-----------------------------------:|
|           	The H-bridge prototyped properly. Here, just the components and arduino connections are placed.           	|            	And here is the completed H-bridge circuit! The blue wires are connected to a multimeter not in frame.               	|

The outer rails are the H-bridge’s input current (DC) and the middle rails are the H-bridge’s outputs (AC). 

I say it’s complete, but the multimeter will be the judge of that…

| ![Testing new H-bridge circuit with multimeter](<./Documentation Graphics/Electronics/H-bridges/V2 Spread Out Breadboard Progress 3 - Multimeter.mp4>) |
|:---------------------------------------------------------------------:|
|                            	Survey says…                           	|

That’s what you like to see! I didn’t even have to debug anything because I didn’t make any errors to begin with. Part of this I’m sure can be attributed to my better understanding, but everything being spread out and easy to see where everything is is probably the main reason. And it’s also much more readable, so will be a far better reference when making protoboards. No wonder people stick to procedure…

On the subject of readability, I thought it would be cool, especially for the display for the presentation, to put LED indicator lights directly connected to the gate on each MOSFET. This way, you could see the “X” of where the final AC signal comes from. 

| ![H-bridge breadboard circuit with LED indicator lights](<./Documentation Graphics/Electronics/H-bridges/V2 Spread Out Breadboard Progress 4 - LEDs.jpeg>) |
|:---------------------------------------------------------------------:|
|                            	Adding the lights…                           	|

| ![Video of the H-bridge breadboard circuit with LED indicators running](<./Documentation Graphics/Electronics/H-bridges/V2 Spread Out Breadboard Progress 5 - LEDs Blinking.mp4>) |
|:---------------------------------------------------------------------:|
|                            	X marks the spot!                           	|

I was indeed right that the LEDs help show where the output is getting its current.

##### Hot FETs

Nonononoooo
When I tried the breadboard circuit hooked up to an electromagnet as a load, it got concerningly hot.

The heat is what catalyzed my switching away from BTS7960’s in the first place, so I’m a bit sour that it wasn’t magically resolved by running away.
Oh well. The MOSFETs should still be more adaptable (or, at least have the failsafe that, should push come to shove, have practically drop-in equivalents which are rated for higher current). I was also going to switch to MOSFETs eventually anyway so would have to face this issue no matter what. I’m sure I have a bandaid solution if I can’t diagnose why.

The [IRLZ34N MOSFET’s datasheet](hyperlink this datasheet) says that they should be rated for the current my motor is rated for and yet they’re running hot, even when I used heatsinks. For now, I can just use a giant heat sink, but I do want to know if they’ve been damaged by the heat or if I’m just being paranoid.

###### MOSFET Auto-tester With Oscilloscope

There isn’t much to this circuit other than just hooking a MOSFET up to an oscilloscope. I used the Digilent Analog Discovery 2 oscilloscope. I also did throw an LED into the test circuit just as an extra visual indicator.

| ![Bird's eye view of the oscilloscope and test circuit](<./Documentation Graphics/Electronics/H-bridges/MOSFET Tester Setup Wire Birds Eye.jpeg>) | ![Closeup of the oscilloscope and test circuit](<./Documentation Graphics/Electronics/H-bridges/MOSFET Tester Setup Wire Closeup.jpeg>) |
|:-----------------------------------:|:-----------------------------------:|
|           	Bird's eye view of the oscilloscope and test circuit           	|            	Closeup of the oscilloscope and test circuit                 	|

| ![I don't know morse code](<./Documentation Graphics/Electronics/H-bridges/MOSFET Tester Setup Controlled with Oscilloscope.mp4>) |
|:---------------------------------------------------------------------:|
|                            	Controlling the MOSFET with the computer running the Analog Discovery 2 software.                            	|

Results seem to indicate that the MOSFETs are still functional. Because I am still paranoid (especially without enough time to get replacement MOSFETs), I’d rather be better cautious than reckless.

##### Protoboard H-Bridges

The middle ground between a PCB and a breadboard. Let’s see how much we can shrink and streamline the H-bridge.

| ![Rough protoboard sketch layout](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 0 - Very Rough Layout Wiring Diagram.jpeg>) | ![Protoboard with components arranged in initial layout](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 1 - Initial Layout.jpeg>) |
|:-----------------------------------:|:-----------------------------------:|
|           	I started with a very rough sketch to get an idea of what layout would work...           	|            	...and then arranged the components on a protoboard without soldering based on that.                 	|

The screw terminals interface the H-bridge with power and their phase of the motor and the female JST connector interfaces them with the microcontroller.

The MOSFETs were a bit of a pain to solder perpendicular to the protoboard because their pins are flanged and so they don’t sit flush with the protoboard, but it wasn’t too bad. Remember how I mentioned disagreeing with the decision to connect the drain to the large metal back of the MOSFETs? Yeah, I still do. This was my fault, but the wiggling of the MOSFETs was enough to worry me that they might short, especially with higher amounts of current:

| ![MOSFET Drains sit concerningly close to one another](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 2 - FET Drains Touch.jpeg>) |
|:---------------------------------------------------------------------:|
|                            	MOSFET Drains sit concerningly close to one another when arranged on a protoboard.                            	|

| ![Protoboard in a metalworking vice](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 2 - FET Drains Touch.jpeg>) | ![Increasing the space between drains](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 3 - Dremel FETs.jpeg>) |
|:-----------------------------------:|:-----------------------------------:|
|           	It's a good thing           	|            	I have a dremel                 	|

With some gentle convincing, there is more space between the FETs’ drains. I was careful to go slowly so as to not heat up the MOSFETs.

With the next boards, I changed the components’ arrangement slightly to avoid this issue to begin with. I’ll also just relegate the odd one out to be a part of the magnet flipping demonstration on the display.

| ![New protoboard component layout](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 4 - New Board Arrangement.jpeg>) |
|:---------------------------------------------------------------------:|

Jumping wires and making connections and I have two almost complete H-bridges:

| ![One protoboard H-bridge near completion](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 5 - Almost Complete Board 1.jpeg>) | ![A different protoboard H-bridge similarly near completion but in a different manner	](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 5 - Almost Complete Board 2.jpeg>) |
|:-----------------------------------:|:-----------------------------------:|

Now, what to do about the heat? Well, I have two large heat sinks with these guys’ names on ‘em. I drilled and tapped them so I can screw the H-bridges to them using nylon (non-conductive) screws and then later put silicone thermal pads between them and the heat sinks once they’re all soldered up.

| ![Various](<./Documentation Graphics/Electronics/H-bridges/V4 Mounted on Heatsink - Angle 1.jpeg>) | ![angles of](<./Documentation Graphics/Electronics/H-bridges/V4 Mounted on Heatsink - Angle 2.jpeg>) |
|:-----------------------------------:|:-----------------------------------:|
| ![protoboard](<./Documentation Graphics/Electronics/H-bridges/V4 Mounted on Heatsink - Angle 3.jpeg>) | ![H-bridges](<./Documentation Graphics/Electronics/H-bridges/V4 Mounted on Heatsink - Angle 4.jpeg>) |

##### Major Iterations of H-Bridges

| ![Evolution of H-bridge iterations](<./Documentation Graphics/Electronics/H-bridges/V4 Mounted on Heatsink - All Versions Compared.mp4>) |
|:---------------------------------------------------------------------:|
| ![Evolution of H-bridge iterations](<./Documentation Graphics/Electronics/H-bridges/V4 Mounted on Heatsink - All Versions Compared.jpeg>) |
|                            	Evolution of H-bridge iterations                            	|

#### A Brief Aside on the Importance of Resistors

The resistors that connect to the MOSFETs’ gate input seemed kind of weird and unnecessary to me.

To my surprise, they’re actually vital. This is because the MOSFETs act as capacitors of sorts and, upon activation into their Gate pin, have effectively 0 resistance. Once they get some current, then the resistance increases.

Now, 0 resistance sounds great and it seems silly to add some; however, because of Ohm’s Law of `V = IR` and `I = V/R`. This means you'll effectively get ≈infinite current at the instant of trying to activate the gate pin, which would be *bad* and destroy basically everything.

Obviously resistance is not actually *equal* to 0 but instead just *approximately* equal to 0. This is still what those in the industry call “bad,” so we add some resistance so there's not this enormous current spike.

This was news to me and I found it interesting, so I wanted to share.

#### The Cold(–Running FET) Promised Land

A retired electrical engineer at my local makerspace caught wind of my endeavors with MOSFETs. According to him, it is possible to run the MOSFETs cold without any cooling systems, just better control. Basically, because there is effectively no resistance when the FETs are open, this should (and does) not create hardly any heat. All of the heat is during the opening and closing of the gate because resistance spikes and peaks at the halfway point between open and closed (the same is true for all transistors; even the computer chip most densely packed with transistors will cool off as soon as the bits stop flipping).

My analogy, verified for correctness by him, is that you could think about the FETs like a knife switch. Resistance through the knife switch is effectively zero, but resistance through the air is high. The electricity will attempt to jump the gap through the high-resistance air when the knife switch is partially open, causing a spike in heat (as air is ionized and such). To minimize this heat, you minimize the amount of time you leave the switch partially open or partially closed—you operate it faster.

The same is true for FETs. But, how do you open and close a FET faster? Push harder—give more current to the gate pin. The microcontroller can only supply so much current before cooking itself, so you charge a capacitor with the microcontroller and then discharge it into the gate to open and close it as fast as possible.

To me, this sounds like black magic, but so does most of what he does anyway. I would like to try this out though. Sure, capacitors are large but not as large as a cooling system. The promised land awaits…

### Presentation Display Board



### Regeneration

While regeneration may not be within the scope of this project, I did do some preparatory work for it—namely, a rough circuitry layout and a voltage regulator side project.

#### Rough Circuitry Layout

For the regen circuit, I’ll need voltage regulators and therefore an understanding of how they work. The goal of this side project is to gain somewhat of an understanding of how voltage regulators work by converting the 50 V DC from a battery I made into 5 V DC I can use to charge my phone.


#### Voltage Regulator Side Project

When you hear “electric scooter,” what do you think? If your answer is anything except for “a phone charger,” I think that's a problem in need of addressing and part of what this side project seeks to fix.

##### Background

So I have this battery I made for my electric scooter that's 13S 2P of 18650's and, at 3.7 V per battery, is 48.1 V when fully charged. This would explode my phone if I plugged it in but it would be nice to have it work as an emergency battery just in case (or if I want a super battery for playing Pokémon Go). Rough calculations estimate that it should be able to charge my phone from dead to full around 360 times (assuming that is the only thing it is doing—no motor), which is quite the improvement. My phone wouldn't need to see an outlet for a year if I could only harness this power. 

Sadly, the laws of nature dictate that the fruit be forbidden and such a thing is impossible indeed. It would seem this side project was never meant to be; ended before it could begin…


Nah, I’m just kidding. Someone gave me this handy voltage regulator link datasheet that will work a treat and do just what I need.

image

Before we get to that, though, you may be wondering how this in any way is connected to my motor. Good question.
The answer is that it's not. Or, at least, not directly. To make the regeneration circuit, I’ll need to use voltage regulators and also the knowledge and skill to be able to do this and implement them. I do not have this so this side project lets me kill two birds with one stone by letting me gain experience and practice with voltage regulators (a useful thing in its own right) and also helping me to be able to capture more pocket monsters.

##### The Process

cut at some female USB-As to use as outputs, and the input will be a female XT60. I "modified" a little electronics project box with a dremel to accomodate these ports. I drilled holes into a prototyping board to route wires through.

~~images of like USB-A pinouts and a wiring diagram for the whole thing~~

 - Measured voltage but didn't charge phone
 - Dad's resistor discovery
 - Soldered resistors properly
 - Everything works!
 - unplug and it shorts
 - short appears to have originated from XT60 connection
 - Male XT60 on board is heavily charred; female XT60 on battery seems unharmed
 - Battery still measures voltage and appears undamaged (thank goodness)
 - {results from testing voltage regulator with benchtop power supply}
 - Used multimeter to test continuity in male XT60 and it measured none... the search continues
## Reflection

### What I Learned

Before I discuss the other aspects of my reflection, I would first like to talk about all that I learned by doing this project as that was my primary focus ^(and I need to hype myself up first)^. There is (I think) good news in that I learned too much to list, so I’ll mostly be focusing on the things I thought were particularly of note and those which I haven’t mentioned already throughout this post.

#### Knowledge:
that I still have a lot more to learn about even just MOSFETs (Bill’s promised land)
More in depth physics of electromagnets

##### Electronic Components
Hall effect sensors
MOSFETs
Diodes
Capacitors



#### Skills:
Markdown
blog writing/styling/formatting (one area of improvement would be that I’m overexplaining some things that could just be left as a citation because I find it fun, but I recognize that this habit can potentially *really* clutter things and obscure my actual project & work)
Soldering surface mount

##### CAD:
Much more Inventor/mCAD overall refinement
mCAD presentations
mCAD drawings
mCAD iParts
mCAD derived parts
mCAD linking parameters
Introductory eCAD

#### Some personal growth, too:
A hard lesson in piecewise progress and more rigid structures to enforce greater documentation as I go… making and posting progress updates seems like the right way forward



### Answering the Research Question

***What goes into making a speed controller for a BLDC electric motor?***

Quite a bit, it turns out! On paper, it seems rather simple: just turn DC to AC at the right times so you can turn some magnets on or off. But what goes into this is actually really in depth. And it does make sense for it to be so in depth, too—with how common motors are you’d want the process of controlling them to be as robust as possible.

As for the mechanics of this, boy does it get complicated. For starters, I had to build an electric motor so that I could build the speed controller and couldn’t really just use an off-the-shelf one because, at least to my understanding, the sensor-based speed controllers rely on knowing the precise position of/angle between two electromagnets as well as two permanent magnets. The difficulty of obtaining this data would depend on what motors I have access to and which fit my other requirements (e.g., axial flux, doesn’t have a speed controller built in, decently powerful, somewhat large, openable, information available online etc.) and, less importantly, tastes.

While I wouldn’t’ve had to make my own motor had I made a sensorless ESC, I didn’t know enough electronics to feel comfortable undertaking such a project when given my time/business constraints and, now with hindsight, I do think I made the right call because the project I ended up doing was just the right amount beyond my ability level at the start for me to learn a ton through the challenges it presented and not so far beyond my ability level that I was hopelessly lost.

In any case, what goes into making a speed controller for a BLDC electric motor is apparently everything that goes into making a BLDC electric motor since you have to* make one, on top of the electronics and code necessary to make the speed controller itself.

*I think

### Meeting of Goals?

No way! Well, sort of. It doesn’t entirely feel like it to me. While I did make accomplishments relevant to, in support of, and as a part of this project that were not set as goals, my product does not function and this project is very much still incomplete to me. That said, because the goals were not defined in adequately specific terms to demand a functional product, they were met. I think this is a good thing though, because my definition of meeting goals or a successful project is warped to require the content of the project being successful itself, when that’s not always the case; I have learned that I should take extra care with goal setting, as this project really highlighted that I run into difficulty publishing work I feel is unfinished or a failure. This is especially foolish in this case, as not publishing would rather unnecessarily limit my learning and therefore go against this project and many others’ motivation and overall philosophy.

However, regardless of the technicality of whether the goals were met on paper, I would be remiss if all I used this reflection and analysis for was a simple “yes” or “no” for whether the goals were met on paper because, while this project was not successful in creating a motor, it was very much successful in being a learning experience.

### Kaplan Objectives

#### Change Over Time
*What was it like in the past, the present & what might it be like in the future?*

#### Details
*Who..? What..? When..? Where..? Why..? How..?*

### Next Steps

Finish current electronics
Get H-bridges soldered on protoboard
Wrap 1 or 4 more coils to have either 2 or 3 per phase
Do regeneration
“Package” motor (possibly redesign stator, make other half of stator, make proper housing with a second rotor (even if it doesn’t have magnets), hollow axle, get PCBs made for all electronics (especially Hall effect), reprint everything in ASA, etc.)
Finalize presentation board with peripherals (RPM meter, amps, etc.)
Run tests with motor

## Bibliography

To go back up to the research section in the introduction, click [here](###Research).

### Reference List
