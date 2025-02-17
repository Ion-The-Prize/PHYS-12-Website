+++
fragment = "content"
weight = 100
#disabled = true
#hide = true

#headless = true

#background = ""
categories = ["Axial Flux Motor", "Speed Controller"]
display_date = true
date = "2022-10-31" # yyyy-mm-dd
publishdate = "2022-10-31"

title_align = "left"
title = """A DIY 3-Phase PM BLDC Axial Flux Electric Motor and Custom, Sensor-Based ESC"""
subtitle = """
<h2 id="lightTitle"><font size="5" color="grey" font-weight="100"><i>
	What goes into making a speed controller for a BLDC electric motor?
</i></font></h2>
"""

summary = """ """

[sidebar]
    title = "Contents"
    sticky = true
    align = "right"
    #content = ""

#[asset]
	image = "Omitted because Syna devs don't want this to work (GH issue 629)"
+++

{{< fontawesome "calendar-days-regular" >}} {{< readableDate >}} </br>
{{< fontawesome "clock-regular" >}} {{< estReadingTime >}}

-------

## Introduction


### Background


#### Motivation: Why did I choose this project?

To properly provide reason and motivation for choosing this project, some backstory is necessary. In early 2020, I made an electric scooter from scratch. There were two main reasons:

The first is that I commuted between different schools a lot on my bike and thought this was inconvenient. Seeing as I could not (and still can not) drive, an electric scooter or bike made sense. The second reason is that I had no idea how I would go about building such a thing, so I would learn a lot from doing it. (This is also part of why I made an electric scooter instead of an electric bike, as I had more of an understanding of how the latter worked.) The scooter itself was quite shoddy and not at all suitable for my commute, and I really only use it for very short rides when I’m feeling lazy or want fresh air. But that doesn’t really matter to me because I did indeed learn a lot from this project and had my eyes set on many exciting new ones.

As I was making the scooter, I was using some parts I didn’t make and didn’t completely understand (many of them electronics-based). I asked myself if I could really say that I had made the scooter from scratch if this were the case. I decided not and so, earlier this year, I made a DC electric, radial flux motor from scratch using mostly 3D-printed parts based on designs by Christoph Laimer. Why brushless? Because I heard it was harder than a brushed motor.

Anyway, the motor hit almost 2000 RPM without breaking a sweat; it didn’t even get warm! And this was without an iron core! So I was happy, right? Wrong. To make it spin, I used a pre-made "electronic speed controller." Because I simply can’t have that, I wanted to make a speed controller. But, because of the design of the motor I made, doing so with that motor would have been a lot more complicated than I was comfortable with (too big of a step up from my current skill level).

Of course, I do have to draw the line of "from scratch" somewhere and move on. Making my own speed controller? Seems productive. Making my own transistors? Seems debatably productive. Enameling my own wire? Perhaps not very productive.

So that brings us to today, where I designed a new motor just so that I can make a speed controller for it so that I can be one step closer to making an electric scooter completely from scratch.

*If you’re wondering why I decided to make a different style of motor (axial flux) instead of modifying the radial flux design, there are two main reasons: (1) axial flux is better for vehicles, and (2) it would be more challenging and therefore I would learn more.*

#### Project Outline & Goal-Setting

##### What are all those buzzwords in the title?

***A DIY 3-Phase PM BLDC Axial Flux Electric Motor and Custom, Sensor-Based ESC***

DIY
: Do-it-yourself (homemade)

3-Phase
: A phase is a set of electromagnets being activated at the same time with the same polarity
: This motor will have three such sets of electromagnets.

PM
: Permanent-Magnet based; i.e., the electromagnets will pull Permanent Magnets around in a circle instead of creating temporary magnets

BLDC
: Brushless, Direct-Current (motor)
: A brushless motor uses electronic controls to energize the correct electromagnet so that it can pull other magnets around in a circle for part of a rotation.  <sup>[</sup>[^MPS]<sup>]</sup>

Axial flux
: the style of motor (as opposed to radial flux)
: Axial flux means the magnetic fields of the magnetic fields of the permanent magnets are *parallel* to the axis of rotation and radial flux means the magnetic fields of the permanent magnets are *perpendicular* to the axis of rotation ("radiating" outwards).

Motor
: Thing that spins

ESC
: Electronic speed controller
: Tells each phase of electromagnets when to turn on and off

Sensor-based ESC
: the ESC uses sensors (in this case Hall effect sensors) instead of induction from the permanent magnets to know where the permanent magnets are <sup>[</sup>[^Atmel-AVR443]<sup>]</sup>

##### Research Question

The research question I seek to answer through this project is: "What goes into making a speed controller for a BLDC electric motor?" 

##### Initial Project Goals & Overall Philosophy

This section is perhaps too important to be relegated to a 5th level heading which is haphazardly buried in the middle of a subsection, but I digress.

My overall philosophy going into this project is reflected in my research question: my focus is on learning above all else, including traditional measures of success. This has some notable ramifications beyond the face-value, and perhaps even naïve, hedonistic lusting for knowledge. In particular, wanting to keep things as low-level and understood as possible means avoiding specialized components; I would rather dive deeper into a smaller number of subjects than gain a shallow understanding of a large number of areas. Beyond personal preference, I also know that a deeper understanding is more transferable and reusable for me: I can more easily re-tool and adapt that which I understand more completely. Additionally, specialized components are, well, specialized, and more restrictive in how much they can be adapted or re-tooled to begin with, regardless of depth of understanding.

That said, I do need to establish goals and criteria for success. These goals are as follows:
- Design & create an electronic speed controller for an electric motor
- Design & build an electric motor from scratch for the DIY ESC
- Program the DIY ESC to control the motor
- To learn, which should be evidenced through a blog post meeting the following:
	- Documents the project and its process with text, code, designs, explanations of code and of designs, pictures, videos, other graphics (e.g., animations), captions, and textual explanations
	- Is a minimum of a 4-8 minute read
	- Is neatly structured (or, at least, organized)
	- Contains a reflection section
	- (Optionally contains) a short preview/summary video up to around 1 minute in length
- Create a presentation display for the motor

#### How do electric motors work?

The goal of an electric motor is to translate electrical potential energy into rotational kinetic energy. They accomplish this by forcing some magnets into a sort of Sisyphean light chase with electromagnets.

Electromagnets use electricity to create a North or South magnetic field which will repel or attract Permanent magnets with either matching or opposing fields. So, by turning on an electromagnet directly "in front" of a permanent magnet, the permanent magnet will move towards the electromagnet to try to line up their fields. By arranging several electromagnets in a circle and implementing careful timing, the electromagnets can be turned on and off in sequence to constantly change magnetic fields to always pull on the permanent magnets and create  motion:

It turns out that we can link the electromagnets into three "phases" with unique signals; we don’t need to individually control each electromagnet. Because the magnets are trying to align their fields, there will be no motion should they accomplish this. It turns out that three phases is the minimum amount of electromagnets needed to guarantee that there will always be one which is misaligned with the permanent magnets. 

The electromagnets and permanent magnets are each on one of the motor’s two main parts: the stator and the rotor. The difference is simple: the stator is stationary and the rotor rotates. 

There are two main flavors of DC motors—brushed and brushless—which differ in which types of magnets are in the motors' stators and rotors. You would think that the electromagnets would always have to be stationary to avoid twisting their wires, but brushed motors actually do spin the electromagnets: Brushed motors have incomplete circuits to the electromagnets which are completed when physical electrical contacts ("brushes") on the stator come into contact with other physical electrical contacts on the rotor, allowing current to flow through.  Brushless motors do keep the electromagnets stationary and control them externally with a speed controller composed of logic circuits and/or code.

#### WITNtMMOWfSJtMaSP

A.K.A., Why I Totally Need to Make My Own Motor from Scratch Just to Make a Speed Controller

Basically, I want to make a speed controller (duh). To make a speed controller, I need a brushless motor. To turn the electromagnets on at the right time, I need to know where the magnets are. To know where the magnets are, I can either use magnetic field sensing magnetic field sensors or induction wizardry. The latter is wizardry so the former it is! All the former requires is my knowing precise information about the electromagnets and the permanent magnets’ relative positions. To know precise information about the motor, I pretty much just have to make it (especially given some other restrictions I have).
### Research

#### Annotated Bibliography

J. F. Gieras, R.-J. Wang, and M. J. Kamper, *Axial Flux Permanent Magnet Brushless Machines*, 2nd ed. New York City, NY: Springer, 2008.
> I selected this source because of its outstanding depth despite its also amazing breadth. Its incredibly thorough information is, at minimum, kind of useful for pretty much every aspect of this project as well as possible future, related ones and, at maximum, just what I need for many circumstances. This amazing wealth of information it provides is also rock solid with plenty of citations. The authors are also highly credible.

[^Gieras]: J. F. Gieras, R.-J. Wang, and M. J. Kamper, *Axial Flux Permanent Magnet Brushless Machines*, 2nd ed. New York City, NY: Springer, 2008.

Atmel, "Atmel AVR443: Sensor-based Control of Three Phase Brushless DC Motor," 2596C−AVR−07/2013, Circa 2005 [Rev. July 2013]
> I chose this application note as a source because of its almost perfect relevance to my project—controlling a BLDC motor with Hall-effect sensors. Additionally, it is extremely reliable as a source, being a continually revised application note.

[^Atmel-AVR443]: Atmel, "Atmel AVR443: Sensor-based Control of Three Phase Brushless DC Motor," 2596C−AVR−07/2013, Circa 2005 [Rev. July 2013]

Monolithic Power Systems Inc., "Brushless DC Motor Fundamentals," AN047, Jian Zhao and Yangwei Yu, MPS: The Future of Analog IC Technology, July 2011 [Rev. May 2014]
> This is another application note and therefore very credible. This source is particularly useful for programming the phases and providing some intuition into that, but also contains generally good and relevant information for my project.

[^MPS]: Monolithic Power Systems Inc., "Brushless DC Motor Fundamentals," AN047, Jian Zhao and Yangwei Yu, MPS: The Future of Analog IC Technology, July 2011 [Rev. May 2014]

-------

I cite only 3 resources in my bibliography because a very good portion of the reference materials for this project was unofficial and I learned in hobbyist spaces and from their resources, which, of course, are not scholarly.

----------

With that all out of the way, let’s take a look at the actual project:

-------

## The Design

|	![Gif revealing real motor overlaid on CAD drawing](<./Documentation Graphics/Designs/CAD-Drawing-and-Real-Life-Comparison.gif>)	|
|	:--:	|
|	A short animation I made showing how the <abbr title="Computer Aided Design">CAD</abbr> model was translated into real life.	|

### Philosophy

My general philosophy when designing the motor itself was to make it as modular as possible without sacrificing effectiveness. What this means practically is that I divided the motor into a handful of subsystems that I could build when I had the necessary materials or which I could improve when I discovered some new information, and would want to minimize time spent redesigning everything. For example, the coils are designed to have replaceable cores so, with one design, I can turn my air cores into iron cores by stacking waterjetted sheet steel or once I get access to the material and equipment for (lost-PLA metal casting)[https://www.youtube.com/watch?v=YKeImuJpxow], or some other tooling method like a 5-axis CNC capable of milling cast-iron.

### The Motor

The motor is made up of two main systems: the rotor which rotates and the stator which is stationary. These, of course, have their own components in turn (see what I did there?). All of this is described below.

#### Approach

<aside style="width: 34%; padding-left: 1rem; margin-left: 2rem; float: right !important; box-shadow: inset .4rem 0 0.34rem -0.34rem #f5007e; color: #f5007e;">

This project involved two CAD tools: Autodesk Inventor for Mechanical CAD (mCAD) for the motor's physical design, and KiCAD for Electrical CAD (eCAD) to design the necessary circuit boards and control systems.

</aside>

After facing the blank slate and a bit of "designers' block," I went about the mechanical CAD in a bit of an inside-out fashion. For example, I knew what magnets I had and what diameter shaft I was going to use, so I started with a very rough sketch of them, the structure to hold them, and then, finally, sized and arranged the electromagnets based on that structure. In this way, positions and angles were roughed out from these requirements and restrictions:

<center>

| ![A VERY rough sketch indeed](<./Documentation Graphics/Motor Sketch.svg>) |
|:--------------------------------------------:|

</center>

From there, I started putting parameters in a spreadsheet so I could link all my models because of how helpful that is and in case something changed later. I started with the rotor, then went onto the stator, assembled both, and finally designed the coils which could be 3d-printed and wrapped.

Here are all of the parameters that the motor used, listed more or less in the order I added them:

<details><summary>Motor Global Parameters</summary>

<iframe src="./Documentation Graphics/Designs/Motor Global Parameters.html" width="100%" height="720px" style="border: none; max-width: 1080px;"></iframe>

</details>

#### [Vitamins](https://reprap.org/wiki/Category:Vitamin)

Despite my efforts to "build from scratch," some parts of my motor cannot be 3D printed or otherwise made by me—the permanent magnets, shaft, bearings, fasteners, wires, shaft collars, magnets, sensors, etc. are not presently 3D printable. I've always liked how these imported parts are called Vitamins in the world of self-replicating machines. Of course, while I won't be making these parts, they are still planned for and included in the design. It is important to do this for many reasons, including the following: aiding with assembly, ensuring that the correct size vitamins are available and affordable, maximizing vitamins already owned, and effectively planning the layout. The last of these—effectively planning the layout—is especially important for this motor as spacings are critical and the size is constrained by the available magnets. For the motor to be as efficient as possible, the coils need to sit as close to the permanent magnets as possible. So, the bottom of the stator needs to be completely flush to accommodate this. This requirement necessitates a lot of countersinking (among other things) and was always something to consider while I was designing the motor.

That said, I only very recently modeled some of the vitamins. Specifically, I had, of course, modeled the magnets, bearings, shaft, and shaft collar, but fasteners like nuts and bolts were not a priority because I could accommodate and plan for them without a model just as easily as I could with (and I was tight on time).

##### THE EVERYBOLT (patent pending)\*

\*patent not actually pending

In the spreadsheet of parameters, you may notice how every bolt has several parameters attached to it; things like the height and diameter of the head, the length of the shaft, the height of that size of bolt’s nut and its width across flats, and more. Well, this simultaneous variety and similarity of the bolts I needed annoyed me enough that I was sent down such a deep rabbithole to create a parameterized "EVERYBOLT" that I could use, well, *everywhere* and for all my bolting needs. I was repeatedly surprised as I was making my ~~magnum opus~~ bolt how many times a feature I wanted to add (of which there were several) required learning a lot about a large part of <abbr title="Autodesk Inventor is the mCAD software I use">Inventor</abbr> Inventor I had never heard about before. This complexity of and depth of learning I gained while designing are even more incredible given how simple a part it seems to be—it’s just a bolt for crying out loud! And I have even more ideas to improve ***THE EVERYBOLT*** which I truly cannot wait to implement.

Because of how useful ***THE EVERYBOLT*** turned out to be and how extensive the scope ended up being, I actually have given it its own section here, even though I had to finish the Motor's design before ***THE EVERYBOLT*** was ready.

But, I digress. Here is ***THE EVERYBOLT*** and its features.

-------

 - It is the everybolt
> Just drop the bolt into an assembly and say what size you need and everything else is filled in for you—no more need to have dozens of separate models and files for every different bolt type. This is realized as an Inventor iPart (a.k.a., a factory part), into which I configured the specifications for the various sizes involved in a bolt (head diameter, height of head, etc.) for many (*many*) metric bolt sizes (M3, M4, M2.5, M40, etc.). 

 - Custom shaft and transition lengths
> Both the length of the threaded shaft and the length of the unthreaded part of the shaft are individually adjustable upon placing the bolt an assembly

 - Handy defaults
> For each bolt size, the most common threaded shaft length and the most common unthreaded shaft lengths are filled in by default.

 - Adjustable detail levels
> Sometimes you want to make a pretty presentation. Other times, you have 281 bolts and you don’t want to be able to cook s’mores with the heat radiating from your computer. With the click of some buttons, this one bolt model can accommodate both of these desires by turning on/off modeled threads, knurling, and other details.

 - Places itself where it’s needed in assemblies all in one move with iMates 
> When you’re designing a part in Inventor, you can’t put other parts in it; that’s what assemblies are for. This is sometimes inconvenient because you know what fasteners a part requires while you're designing it, and it is easy to forget where they go when using that part in an assembly.  Ideally, you just want to add the bolt and put it where it’s meant to go in one motion as you drop it in instead of adding each bolt to the assembly and then telling each one, individually, where it’s meant to go. Obviously, this is *very* convenient if you have several bolts. This is where Inventor's iMates come in: The bolt has one half of the constraints that would be necessary to place it where it’s meant to go on a different part—its centerline and its bearing face—and the part that’s meant to have a bolt has the other half of the constraints: "this surface will touch an M5 bolt’s bearing surface" and/or "this line will be an M5 bolt’s centerline." If this is done, when a bolt is dropped into the assembly, it’ll go in the correct place(s). Alternatively, these half constraints can be used to add and place a bolt into an assembly in one motion, just add bolt to assembly, click where it’s meant to go, move onto next bolt, as easy as 1-2-3.

 - (Coming Soon) Imperial sizes
> It is just a metric bolt right now, but SAE/imperial sizes are super easy to implement. I am still undecided on whether I want SAE and metric in one bolt. On the one hand, having changes made to one be applied to the other is really appealing. But, on the other hand, it’s likely that projects will be either entirely imperial or entirely metric and not a mix, so it would be kind of pointless to have just one bolt for both purposes. In all likelihood, I’ll put both sizes in one bolt file until I can find some way to keep my changes synced between two separate files, at which point I’ll go with that. 

> I am adding this here after learning more about Derived features, and it seems like that is definitely the way to go for having parts/assemblies with some common features but some different ones. I am not sure if it works with iPart factories yet, but I don’t see why not.

 - (Coming Soon) Bolt Hole iFeature
> EZ Bolt Holes! While a configurable bolt is great (I’d even say outstanding), it’s kind of useless unless the hole it goes into doesn’t also change to accommodate different sizes. The shaft hole is easy—it’s what the metric bolts are named after—an M5 has a 5mm diameter shaft, an M3 a 3mm diameter shaft, an M2.5 a 2.5mm shaft, an M20 has a, you guessed it, 20mm diameter shaft. The same is true even for some SAE (imperial) bolts—a 5/32 bolt has a shaft diameter of 5/32 in. While the hole sizes are easy to manage, countersinking does not follow such a pattern (otherwise an everybolt would be less amazing). Being able to tell a hole that it is an adjustable hole based on a bolt that will go in it would be wonderful (almost as wonderful as an adjustable bolt, perhaps), and it seems like [iFeatures](https://knowledge.autodesk.com/support/inventor/learn-explore/caas/CloudHelp/cloudhelp/2019/ENU/Inventor-Help/files/GUID-C2D08AAD-D86D-4720-96E4-8E0DA7374BE9-htm.html) make such a thing possible.

 - (Coming ???) Different head styles
> Imagine a world where there is just one bolt to drop in for every head type—from socket cap, to button, to flat, to hex, to hex washer, to slotted hex washer, to oval, to truss, to round, to pan, and everything in between—on top of every size so that separate files aren’t even needed for these different head types. Such a world would truly be utopic, at least from a CAD point of view.
>
> However, the method of storing different bolts’ sizes in one file I used is… somewhat lacking. I’ll need a better solution going forward.
>
> In preparation for when it becomes possible, all necessary features of the bolt are already properly independent of one another to make this happen (if they weren’t and the shaft were dependent on the head for example, then if, say, the socket cap head was suppressed and the hex head enabled, then, if it did not just cause an error, the entire shaft would be suppressed along with the socket cap head, leaving just a floating hex head). That said, it may be impossible with the current implementation of iParts and it’ll likely also need for there to be different (derived) parts for the different head shapes.

 - (Coming ???) Different [drive types](https://en.wikipedia.org/wiki/List_of_screw_drives)
> Just like how I would like for there to soon be just one bolt model file to drop into assemblies for every head type as well as every size, soon there will also be just one bolt model file for every type of driver (phillips, flathead, hex, star, triangle, oval, etc.). Also just like the different head styles, all necessary features are already independent of one another (there will be a hole for the driver whether or not there’s a head to cut into, much less a specific head type).

 - (Coming ???) Measurement tolerances
> Not all bolts are made equal. Some are smaller than they’re meant to be and some are larger than they’re meant to be. The people that designed bolts were smart and accounted for these differences in machining quality. Every measurement has a minimum and a maximum built into the standard. Inventor also has tolerances built into it for such cases. Disappointingly, it doesn’t seem like Inventor supports tolerances with iParts. So, until this is added, I just use the largest of the measurements as outlined in the standard for the everybolt so that it is never under-toleranced for. And if a bolt is ever needed for an ultra-high precision use case and tolerances are not supported for iParts yet, I will simply use an inferior, boring, normal, "onlybolt." 

 - (Coming ???) Scaling bolt specification label
> Like how Inventor doesn’t seem to support measurement tolerances with iParts, the text feature is quite limited for modeling for my purposes: Labeling the bolts (by diameter, pitch, and length) is trivial, but sizing the labels is problematic. It seems like the modeling text tool was ported directly over from Inventor’s CAD drawing capabilities. For CAD drawings, standards are enforced depending on the style being used and so Inventor enforces these standards. This includes fixed options for text size (and among all the standards, the largest size is still quite small). This is fine for drawings, but not for modeling and makes labeling the heads of the different sizes of bolts with nicely sized labels impossible. That said, I’ve looked around online but still don’t know if bolts’ labels are scaled; however, for readability purposes, a percentage-based scaling label would be nice.

##### The Everynut

Like THE EVERYBOLT, the idea behind the Everynut is to have one component which I can drop into assemblies and select the type and size of nut I want (M4 locknut, M3 jam nut, M24 wing nut, etc.). Also like THE EVERYBOLT, accomplishing this how I want to is likely impossible in the current iteration of Inventor.

As of right now, the Everynut is all sizes of standard metric nuts.

#### Rotor

{{< newTabSVG src="./Documentation Graphics/Designs/Rotor/Motor Exploded Drawing - Highlighted - Rotor.svg" >}}

##### The Rotor’s Jobs & Purposes

As mentioned earlier, the rotor rotates and interfaces with the outside world (e.g., a wheel) so that this rotation can be useful. To be able to rotate, it must spin freely and hold permanent magnets which can be pulled around in a circle by the carefully timed electromagnets of the stator.

##### Magnets

I’m going to talk about the magnets before I talk about the body because the body’s design was largely informed by the restrictions set by the magnets.

As has been stated before, I categorize the magnets into three types of magnets: drive, halbach, and sensor. They all have different sizes and jobs.

In the CAD drawing, it looks like every magnet is doubled up. This is because I colored each one with a north and south pole and, to get the sides to have multiple colors, I needed a groove at the split (otherwise Inventor would merge the face). That said, the Halbach and Drive magnets are each in stacks of two for added strength.

###### Drive Magnets

{{< newTabSVG src="./Documentation Graphics/Designs/Rotor/Motor Exploded Drawing - Highlighted - Drive Magnets.svg" >}}

The "Drive magnets" are large and strong magnets whose magnetic fields will be used to spin the rotor. This rotational force will be stronger with larger magnets, and, therefore, I would rather the drive magnets be wedge shaped to fill in the gaps between them, but I did not have any available.

To make up for the strength I might be losing because of the drive magnets’ rectangular shape, I added in "Halbach magnets" which will be described next.

###### Halbach Magnets

{{< newTabSVG src="./Documentation Graphics/Designs/Rotor/Motor Exploded Drawing - Highlighted - Halbach Magnets.svg" >}}

These are slightly smaller magnets whose magnetic fields are used to concentrate the drive magnets’ magnetic fields where they can best interact with the stator's electromagnets. Such [Halbach arrays](https://en.wikipedia.org/wiki/Halbach_array) are basically black magic, but it works.

In a classic example of "equal and opposite" forces, the Halbach array's focusing of the drive magnets' fields also makes the Halbach magnets really want to shoot out and away from the drive magnets. After initial designs failed to hold the Halbach magnets in position, I had to redesign the rotor with dedicated cubbies for them and a constraining band around the circumference to keep them in place. 

###### Sensor Magnets

{{< newTabSVG src="./Documentation Graphics/Designs/Rotor/Motor Exploded Drawing - Highlighted - Sensor Magnets.svg" >}}

The last type of magnets are "Sensor magnets" which are read by the Hall Effect sensors. As you may recall, for the right electromagnets to be energized at the right times, the position of the permanent magnets with respect to the electromagnets must be known, Hall Effect sensors inform the controller of this.

These sensor magnets are very small and are "paired" with the drive magnets—each one matches the angle and polarity as a drive magnet but is closer to the shaft. This separation between drive-and-sensor magnets is necessary because the electromagnets on the stator need to be above the drive magnets, leaving no room for a Hall effect sensor. Additionally, even if there was room, the sensors would probably just read the electromagnets' fields, which tells me nothing about the rotor's position. So, set in the empty space closer to the shaft, these sensor magnets will let me know where the drive magnets are without my actually having to read the drive magnets.

##### Rotor Body

{{< newTabSVG src="./Documentation Graphics/Designs/Rotor/Motor Exploded Drawing - Highlighted - Rotor Body.svg" >}}

Most of the features of the body of the rotor are designed within a single, wedge-shaped  sketch:

<center>

| ![The parent and child relationships of the rotor’s Sketch1](<./Documentation Graphics/Designs/Rotor/Rotor Body Sketch1 Relationships.png>) | ![404 Alt Text not Found](<./Documentation Graphics/Designs/Rotor/Rotor Body Sketch1.png>) |
| :---: | :---: |
| Sketch1’s relationships | Sketch1 itself |

</center>

This wedge has spots for each of the types of magnets, and a slot for trapped nuts to hold the rotor band in place. The drive magnets sit in slots on top of the rotor in order to be as close to the electromagnets in the stator as possible. The same is true for the sensor magnets and the stator's hall effects sensors. However, as they don't interact with the stator, the Halbach magnets are secured within enclosed cubbies. After some difficulty with assembly and disassembly, I added slots and holes in the design so a thin nail or similar can be used to push them out of their locations.

I thought the rotor looked kind of plain with just the drive and sensor magnets visible on top so I put indents in the top surface where the halbach magnets are. Here is what the rotor looks like with all these features implemented:

<center>

| ![Rotor body](<./Documentation Graphics/Designs/Rotor/Rotor Body.png>) |
| :----: |
| ![Sketch1 shown on the final part](<./Documentation Graphics/Designs/Rotor/Rotor Body Sketch1 With Features.png>) |
| :---: |
| {{< video type="video/mp4" src="./Documentation Graphics/Designs/Rotor/Rotor Body Spinning.mp4" width="75%" >}} |

</center>

To make sure that my tolerance and the magnets’ fits were good, I printed a single wedge section of the rotor:

<center>

| ![Magnet fit test](<./Documentation Graphics/Designs/Rotor/Magnet Fit Test Top.jpeg>) | ![Magnet fit test](<./Documentation Graphics/Designs/Rotor/Magnet Fit Test Angle.jpeg>) |
| :----: | :----: |

</center>

One of the rotor prints failed halfway through, but I thought it looked cool and serves as a nice cutaway view:

<center>

| ![An ASA print of the rotor which failed due to warping](<./Documentation Graphics/Designs/Rotor/Failed Rotor Print.jpeg>) |
| :----: |

</center>

##### Rotor Band

{{< newTabSVG src="./Documentation Graphics/Designs/Rotor/Motor Exploded Drawing - Highlighted - Rotor Band.svg" >}}

The rotor's design includes a band around its circumference. This band is designed to serve two main purposes: 

The first, as described earlier, is to hold the Halbach magnets in place: On top of the interaction with the drive magnets forcing the Halbach magnets outwards, the rotor spinning is going to add centrifugal "force" and cause them to be flung outwards. The rotor band overcomes both of these forces and holds them in.

All motors need a mechanism to turn their rotational energy into something useful. Many turn a shaft that can then be connected to a wheel or pulley or another external device. My motor’s shaft is an axle and is kept stationary, and instead uses the spinning rotor body for interfacing with the world. This is the second job of the rotor band—to be a wheel, hub, gear or sprocket which can connect to something that needs to turn. Separating this role from the main body of the rotor into a separate, smaller part has many advantages, the biggest of which is that it is more iterable because it can be tweaked and iterated upon independently from the rest of the rotor. It is also more modular as it is easier to swap out the rotor band than it is the entire rotor, after all. For example, I could hypothetically have a rotor band which interfaces with a bicycle wheel and one which interfaces with a scooter wheel, and just move the rest of the motor between them.

------

The rotor band attaches to the main body with bolts and trapped nuts:

{{< newTabSVG src="./Documentation Graphics/Designs/Rotor/Motor Exploded Drawing - Highlighted - Rotor Band Fasteners.svg" >}}

I had to split the rotor band into 3 segments to get it to fit on the printer, but it can theoretically be printed in one piece at the moment. I have been considering some bumpouts to push the Halbach magnets in their cubbies and these would make it impossible to put the band on the rotor in one piece.

This is what the rotor looks like with the magnets and everything on it:

<center>

| {{< video type="video/mp4" src="./Documentation Graphics/Designs/Rotor/Rotor Body with Magnets Spinning.mp4" width="75%" >}}
| :---: |
| What I was talking about with the sensor magnets earlier might make more sense with the polarity of the magnets colored now, too. |

| ![Testing the rotor band with a new magnet fit test](<./Documentation Graphics/Designs/Rotor/Magnet Fit Test with Rotor Band.JPG>) | ![Bearing inserted in rotor bottom](<./Documentation Graphics/Designs/Rotor/Bearing in Bottom.JPG>) |
| :----: | :----: |
| Testing the rotor band with a new magnet fit test | Maintain your bearing… |

</center>

Here it is with all the magnets. (This was before I added indents where the halbach magnets are… See what I mean about it looking kinda plain??)

<center>

| ![The rotor with all the magnets in it](<./Documentation Graphics/Designs/Rotor/Magnet Platter No Shaft.JPG>) | ![The rotor with all the magnets in it and the rotor band attached](<./Documentation Graphics/Designs/Rotor/Magnet Platter Shaft Angle.JPG>) | ![Another angle of the rotor with the rotor with all the magnets in it and the rotor band attached](<./Documentation Graphics/Designs/Rotor/Magnet Platter Shaft Top.JPG>) |
| :---: | :---: | :---: |
| A platter of magnets! It weighs a surprising amount. | The drive magnets are held down by the halbach magnets, but a couple sensor magnets were somewhat loose so I held them in with tape. | I’ll probably be gluing them in the final motor. |

</center>

#### Stator

{{< newTabSVG src="./Documentation Graphics/Designs/Stator/Motor Exploded Drawing - Highlighted - Stator.svg" >}}

##### The Stator’s Jobs & Purposes

Basically, the stator’s job is to pull the rotor in circles. With equal and opposite reactions and all that, the stator must be anchored in place so it does not rotate in the opposite direction that it’s forcing the rotor to spin in with electromagnetic forces. Because I want the motor to eventually be in a wheel, the shaft will be stationary and the stator will attach to it. Lastly and somewhat obviously, the stator must hold the electromagnets & electronics.

##### Motivation: Why coils aren’t just "bare"?

I’m going to talk about the coils’ motivation/backstory before I talk about the stator body’s because, while I modeled the coils last, their requirements and conceptual design informed a great deal of the design of the stator as a whole.

-------

Wire spools take up space and increase distances, and many axial flux motors I see don’t have a spool still attached to the coils.<sup>[</sup>[^Gieras]<sup>]</sup> Instead, the wire is glued or otherwise fused together to maintain its shape and these bare coils themselves are affixed to a frame within  (the stator). This—the having of coils independent of and without individual spools—is for good reason, too, as magnetic strength falls off not with the inverse square of distance but with the inverse cube of the distance which means that even a small separation can have a pretty major effect on efficiency; therefore, the permanent magnets can be made to sit much closer to the coils by not having spools but instead bare coils; however, as my motor was designed to be a good, easily modifiable prototype with an emphasis on modularity, gluing coils to the stator seemed counter to that to me.

This consideration culminated in the question of "how can I make the spools swappable while sacrificing as little efficiency as possible?" as I was designing the motor. I settled on 2mm thick spools attached to the stator with bolts. And the stator would have "arms" in each of the coils’ acceptor spots that the bolts could sit in, and the coils’ spools would have negatives of those arms "cut" into them so they can be as flush with the "bottom" of the stator and therefore as close to the permanent magnets as possible.

##### Stator Body

{{< newTabSVG src="./Documentation Graphics/Designs/Stator/Motor Exploded Drawing - Highlighted - Stator Body.svg" >}}

As mentioned in the [Vitamins](####Vitamins) section, countersinking is quite important for the broader goal of getting the rotor and stator to be as flush as possible with each other. Many of the design decisions were informed with this and countersinking *everything* in mind.

Like with the rotor body, most of the features of the stator body were designed within a single, wedge-shaped sketch. This is brought to a whole other level with the stator however, as not only is the stator more complicated than the rotor, but the coils are also derived from the stator body, and this single sketch in particular, so most of the features of *the entire stator as a whole* were designed within a single, wedge-shaped sketch.

<center>

| ![The parent and child relationships of the stator’s Sketch5](<./Documentation Graphics/Designs/Stator/StatorBody Sketch5 Relationships.png>) | ![404 Alt Text not Found](<./Documentation Graphics/Designs/Stator/StatorBody Sketch5.png>) |
| :---: | :---: |
| Sketch5’s relationships | Sketch5 itself. The purple lines mean it is underconstrained. I’ll get back to that later in the reflection… |

| {{<  video type="video/mp4" src="./Documentation Graphics/Designs/Stator/StatorBody Spinning.mp4" width="75%"  >}} |
| :----: |

</center>

This sketch primarily contains the main feature of the stator: the coil holders. This is in the form of the "stator spider" and is discussed in its and the coils sections. The other main feature of the stator—the circuit board holder—is actually in a different sketch which is discussed in its section below.

###### Flange Coupling

{{< newTabSVG src="./Documentation Graphics/Designs/Stator/Motor Exploded Drawing - Highlighted - Flange Coupling.svg" >}}

The flange coupling is what anchors the stator to the shaft, and it does so with four giant M4 bolts (with similarly massive nuts). I needed to countersink not just the flange coupling, but also the bolts’ heads (the nuts are the same height as the bolts heads, so it doesn’t matter which way they face). Because I am worried about the nub breaking off, I gave it some fillets for strength.

###### Stator Spider

Because this part of the stator’s design was informed by the coils even more so than the rest, I’m going to give sparknotes here and talk about the process a lot more in the coils section.

------

{{< newTabSVG src="./Documentation Graphics/Designs/Stator/StatorBody Graphics.svg" >}}

The stator spider gets its name from it making the stator look like a spider web. *View B* in the stator body’s drawing shows the underside of the stator, where I think this is most apparent.

| ![A 3D printer printing a stator body](<./Documentation Graphics/Designs/Stator/Stator V1 Printing.JPG>) | ![A 3D printer printing a newer stator body](<./Documentation Graphics/Designs/Stator/Stator V2 Printing.JPG>) | 
| :----: | :----: |
| One of the first iterations of the stator being printed. | A much newer iteration. |

The "island" in the center (shown in *Detail C* in the drawing) and its bumpout is necessary so a bolt can hold the coils in and be countersink. The arms support it as minimally as possible so the spools can have more material to make winding easier.

###### Circuit Board Acceptor

The circuit board acceptor began humbly, as but simple indents of the sensor magnets, reminiscent of the Halbach magnets’ indents which were meant as a visual aid and nothing functional. 

Upon these indents proving insufficient for the oh-so important purpose of precise alignment, they were replaced with over-engineered recesses custom-fit to the hall effect sensor I was using with measurements taken straight from the [Hall effect sensors’ datasheet]. It now also is made to accept a custom circuit board/PCB and be used in conjunction with eCAD to make that custom circuit board. *Detail A* and *Detail B* in the stator body’s drawing show what this now looks like.

[Hall effect sensors’ datasheet]: https://www.allegromicro.com/en/products/sense/linear-and-angular-position/linear-position-sensor-ics/a1308-9

-----

After testing Hall sensors’ sensing capabilities when mounted on the stator body in the new design, they do indeed sense. However, their signal is rather weak. Instead of intentionally increasing the thickness of the stator so the Hall sensors’ indents don’t create too thin a wall, they really should intentionally poke through the stator.

I did run into some trouble with this when designing it, as I was unsure of how the PCB would be mounted (for the Hall sensors to poke through the stator, there would not be anywhere near enough material for bolts or trapped nuts or really anything to attach the PCB with because of how low a profile the sensors have without putting them some weird standoff things).

That said, upon thinking about it with a fresh mind, I could probably make some arms hold the PCB from the “top” instead of trying to mount it to the base. Oh yeah… I could just put standoffs on the back of the circuit board and mount it to the other stator half like a chandelier.

##### Coils

{{< newTabSVG src="./Documentation Graphics/Designs/Stator/Motor Exploded Drawing - Highlighted - Coils.svg" >}}

###### Cores: Iron vs Air

If you wrap wire around something and apply current, you get a magnet. If you wrap wire around a nail and apply current, you (probably) get a better magnet. To understand why this is, one should first have somewhat of an understanding of how magnets work.

Just like how copper is more electrically conductive than air, iron is more "magnetically conductive" than air or many other substances ("conductivity" for magnets is called magnetic permeability).

A magnet’s magnetic field is the space around the magnet that experiences a magnetic force. This field could be thought of as a cloud of lines that loop from one "pole" of the magnet to the other, passing through the magnet’s center by necessity. However, while many of these loops remain relatively close to the magnet, some go very, *very* far away. Because the "field lines" that go farther away are more spread out than the ones that are close to the magnet, the strength of the magnet is reduced over distance—closer is stronger because the magnetic field is denser and farther is weaker because the magnet field is less dense. These same rules apply equally for permanent and electromagnets; after all, electromagnets are basically just generators of magnetic fields you can turn on or off.

Just like how conductivity is useful because it can be used to control where electricity goes, magnetic permeability is useful because it can be used to control where magnetic field lines go—just like how electricity follows the path of least resistance and would therefore "rather" flow through copper than the air, so too do magnetic fields which would "rather" flow through iron than the air, should each of electricity and magnetic fields’ respective options be available.

These ideas—denser magnetic fields are stronger, iron concentrates where magnetic fields tend to, and the magnetic field of a magnet necessarily traveling through the magnet’s center—can be combined to create more powerful electromagnets. By placing iron at the core of an electromagnet, the magnetic field will tend to be there much more and it will also remain close to the electromagnet more so that the distance it has to travel to return to the center is as small as possible because traveling a short distance takes less energy than traveling a large distance. This has the effect of making the magnetic field denser closer to the electromagnet and less dense farther from the electromagnet, exactly what we need to maximize the stator's ability to force the rotor to turn.

----------

Nitpicking unimportant to the explanation:

It should be noted that the magnetic permeability of the iron does not, on its own, alter the "number of magnetic field lines" and therefore the total strength of of the electromagnet; all the magnetic permeability of the iron does is alter where the magnetic field tends to be and therefore make the magnet stronger closer to the electromagnet but also weaker farther away from the electromagnet; however, because we only care about the strength close to the electromagnet, we simplify this by saying that an iron core makes the electromagnets stronger.

Nitpicking even less important to the explanation:

Also technically, an electromagnet with an iron core is stronger than an electromagnet without an iron core but which is otherwise equal. This is because the electromagnet induces a magnetic field in the iron (or, more accurately, aligns the magnetic fields of the iron to give it a nonzero net magnetic field in line with the magnetic field of the electromagnet) which "adds to the total number of magnetic field lines" and this effect alone is akin to adding a permanent magnet core; however, while the strength of the combination of the magnetic fields of the electromagnet and effective permanent magnet is greater, the strength of the magnetic field of *just the electromagnet* is unaffected by the addition of the effective permanent magnet. But to call the main statement of the explanation incorrect for this reason would be extremely nitpicky (perhaps as evidenced by the fact that I needed to carefully word the first sentence of this paragraph for this point to be technically true).

###### The Actual Coil Design

{{< newTabSVG src="./Documentation Graphics/Designs/Stator/Coils/Motor Exploded Drawing - Highlighted - Coil Bolts.svg" >}}

There are nine coils in total, each attached to the stator body with a single bolt that goes all the way through it and into a nut.

<center style="position: relative;">

| {{<  video type="video/mp4" src="./Documentation Graphics/Designs/Stator/Coils/Placing a Coil on the Stator.mp4" width="84%" >}} |
| :----: |
| It feels like an infinity stone… |

</center>

{{< newTabSVG src="./Documentation Graphics/Designs/Stator/Coils/Motor Exploded Drawing - Highlighted - Coil Exploded.svg" >}}

The coils have four main parts: the spools’ main body, the core, the spools’ lid, and the actual copper windings.

{{< newTabSVG src="./Documentation Graphics/Designs/Stator/Coils/Motor Exploded Drawing - Highlighted - Coil Windings.svg" >}}

The two things which affect an electromagnet’s strength are the number of wrappings of wire and the current supplied. A thicker wire can take more current but is also, well, thicker and so takes up more space.

Copper wire is wound directly onto the spools and then superglued into place, effectively making the coils the only part of the motor which, once made, is permanent. However, even if the coils were not glued, they would still be the most permanent pieces due to the difficulty in unwinding and any kinks introduced in the wire.

I did not plan for a certain number of turns when designing, just the wire’s gauge. After wrapping the first, I did count its number of turns to keep it consistent between all coils. And that is 119 turns of 20 gauge magnet wire.

I was not sure, but assumed the direction of wrapping would probably affect the polarity of the electromagnet, so I made sure to keep that consistent as well by establishing that I would wrap clockwise when facing the bottom of the spool:

<center>

| ![The wrapping direction](<./Documentation Graphics/Designs/Stator/Coils/The Wrapping Direction.JPG>) | 
| :----: |
| The wrapping direction marked in pencil on the bottom of a coil. |

</center>

| {{< newTabSVG src="./Documentation Graphics/Designs/Stator/Coils/Motor Exploded Drawing - Highlighted - Coil Main Body.svg" >}} | {{< newTabSVG src="./Documentation Graphics/Designs/Stator/Coils/Motor Exploded Drawing - Highlighted - Coil Lid.svg" >}} |
| :----: | :----: |

The spool part of the coil is designed to be printed in two pieces to avoid headaches with support: the main body and the lid. I printed the main body in ASA because the coils are the part of the motor which actually generates heat, and so it is especially important that they be heat resistant. Unfortunately, two of the nine warped:

| ![Warped coil spools](<./Documentation Graphics/Designs/Stator/Coils/Warped Spools.JPG>) | 
| :----: |
| Two warped spools on either side of a non-warped spool. |

Since this reduced their volume, and I was unable to reprint them, I wrapped these first to establish the number of turns the other coils would have.

I was also unable to print the lids, but, since they are flat, I laser cut them out of acrylic, which is even more heat resistant than ASA. I had not originally intended to do this because I had not originally intended for them to be flat and perfect to laser cut, but it worked out.

{{< newTabSVG src="./Documentation Graphics/Designs/Stator/Coils/Motor Exploded Drawing - Highlighted - Coil Core.svg" >}}

##### Reflecting on the Stator’s Design

Why do I have a reflection section outside of my reflection section? Well, and I’ll keep saying this ad nauseam, it’s because I don’t think the design of the stator and coils is very good. Sure, they are parameterized, but not really all that editable, adaptable, iterable, and upgradeable. And sure, they do also look nice, but they probably need redesigns from the ground up.

Remember how I said that Sketch5, the main sketch that the majority of the entire stator is based on, is "underconstrained"? Well, that means that it does not have enough definition to always look like I want it to with any combination of parameters. This is not good. It also means my previous statement about it being parameterized is, at minimum, somewhat untrue. This begs the question though: if it’s so bad, why don’t I just make it fully constrained? Because I don’t know how to (in a good way which maintains parameterization); I tried for a little while but couldn’t get it all fully constrained.

Admittedly, I didn’t try very hard because I’m planning on redoing it anyway and so didn’t use the Sketch Doctor or attempt to auto-generate constraints, but I’d rather avoid those anyway if I can; I prefer to fully understand my designs so I can fix them in case they break. If it’s just one or two constraints or if I properly dissect things, that’s fine, but if it’s 22 dimensions (of which 13 I did get, to my credit), that’s a different story.

<aside style="width: 34%; padding-left: 1rem; margin-left: 2rem; float: right !important; box-shadow: inset .4rem 0 0.34rem -0.34rem #f5007e; color: #f5007e;">

I’m coming back to this having made some graphics which I wanted the lines to be white for, and I did figure it out with some real motivation. The point still stands though—it’s telling for me, the designer of it, to have had difficulty understanding how it was made.

</aside>

I also did not know about some features and went about some things in really not ideal ways. For example, I did not know about projecting geometry and remade geometry from one sketch in another from scratch. I also did not know that you could reference model geometry within definitions of other model geometry, so not only did I recreate the geometry separately, but the recreated stuff also wouldn’t change if I updated the original. Granted, I figured that one out pretty quickly, but you get the idea.

Knowing what I know now about CAD, I’d like to make both the coils and their acceptor locations in the stator adaptive and based on common sketches. 

The coils should also be an assembly full of adaptive parts (core, spool, wire, spool’s "lid" ) instead of a part with multiple components (because components are a surprisingly limiting feature and I still don’t quite understand them).

I tried to do both of these things when designing them initially, but didn’t know how and gave up pretty quickly. Redesigning/refactoring this does sound fun, which is a surprise to me given how much I normally dislike doing the same thing twice; maybe I just like standardization more.

###### New Plan!

So, I’m coming back to this section a couple weeks after writing it and have learned more about derived parts and assemblies. Having done that, they really seem like the way to go, with one master part containing just sketches used by both the stator shell and the coils (each with other things derived from there). The stator shell can actually even be a subassembly itself containing two child parts derived from a master stator shell (the master stator shell itself being derived from the master stator sketches part). This is because the stator is (meant to be) made up of two halves which share many features but not all, which fits the bill for derived parts pretty much to the letter. (Like, one stator shelf half would have the mounting place for the hall effect circuit board and the other would have spots for threaded inserts or trapped nuts for bolts to hold the stator shell together to interface with.)

I threw this chart of these dependencies together in Lucidchart:

<center>

| ![404 Alt Text Not Found. What, you try making an informative alt text for a flowchart, it’s not easy](<./Documentation Graphics/Designs/Stator/New Stator Design Idea Dependency Diagram.png>) |
|:--------------------------------------------:|
|               	Pink = parent derived part ; Light blue = part ; Blue = subassembly ; Orange = assembly             	|

</center>

And grey is other, various parts like nuts, electronics and, yes, of course, the ***EVERYBOLT***.

-------

## Electronics


### Motion (The ESC)


#### General Layout

I made this (very) rough layout of what all of the electronics will eventually look like, including the regeneration circuit, in Lucidchart:

<center>

| ![Informative, descriptive alt text for diagram](<./Documentation Graphics/Electronics/Overall Electronics Layout-Refined.png/>) |
|:--------------------------------------------:|
|               	Okay, so maybe I should just learn some ECAD program               	|

</center>

For now, I’m focused on just controlling the motor and not the regeneration mode.
#### H-Bridges, a Lesson in Expectation & Reality, and Trouble (oh, so much trouble indeed)

It is somewhat misleading for H-bridges to be a subsection of the greater ESC section because all my ESC really boils down to (not counting regenerative braking) is H-bridge circuits and H-bridge code.

So, what is an H-bridge?

##### What an H-bridge is

An H-bridge is a circuit that allows a voltage to be applied across a load *in either direction*. In other words, it can turn DC to AC, which makes them perfect for controlling motors because the electromagnets need to be turned from North to South to off rapidly and in a controlled manner. 

To control the direction of a motor, an H-bridge uses four switches (in this case, MOSFETs) arranged in a "bridge" configuration so current can flow through the load in either direction depending on how the switches are activated.

<center>

|	![Cyril B’s graphic for the structure of an H-bridge](https://upload.wikimedia.org/wikipedia/commons/d/d4/H_bridge.svg)	|
|	:----:	|
|	It is called an H-bridge because it is shaped like the letter "H," </br> with the load at the center of the H and the voltage source at each end.	|

</center></br>

The speed of the motor can be controlled by adjusting the duty cycle of the switching signals applied to the H-bridge. Assuming the signals being switched at a high enough frequency to keep "pace" with the rotor, speed is dependent on how long the switches are activated for—if the switches are more activated than deactivated, the motor will rotate faster and if the switches are more deactivated than activated, the motor will rotate slower. Think of repeatedly flipping a light switch on and off; the more it is in the On position, the brighter the room will be.


##### Off-the-Shelf arduino BTS7960 H-bridges
###### † Initial Experimentation

Arduino’s H-bridges seemed like a great tool and perfect for the job I had in mind, at least to get things working initially before making them from scratch if I had time.

H-Bridges
L_EN and R_EN are both just wired straight to 5V because, as long as PWM is done correctly (only one at a time), this is fine.
L_IS and R_IS are current alarms and won't be used.
This is partly to save pins as three H-Bridges are needed.

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

<center>

<table>
<tr>
<th style="position: relative;">

{{<  video type="video/mp4" src="./Documentation Graphics/Electronics/H-bridges/A Wild Magnet.mp4" >}}

</th>
<th style="position: relative;">

![The magnet flipper setup](<./Documentation Graphics/Electronics/H-bridges/Magnet Flipper Setup.JPG>)

</th>
</tr>
<tr>
<td colspan="2">

*Our most experienced professional mechano-wildlife videographers were able to capture the ever-skittish magnet in its natural habitat where it performs a jumping dance to spread its field in the hopes of attracting a mate of opposite polarity. Once its cover is blown, it attempts to flee.*

</td>
</tr>
</table>

</center>

Initial results were clearly promising! But, this did not last very long at all.

###### Further Testing and Uncovering Issues

So basically, if the magnet was flipped at even a *fraction* of the rate you’d expect from even a leisurely motor, the BTS7960 H-bridges got hot quite quickly (even with their massive heatsinks). This is apparently a known issue, and, despite their large size, the heatsinks are actually kind of useless because they are "connected" to the things on the circuit board that get hot (the MOSFETs) through *a thermal insulator* for some unknown reason.

Some have tried to get around this by going so far as to [sand down the circuit board so they can put solder in the vias](https://www.letscontrolit.com/forum/viewtopic.php?t=7928) (aka holes) to allow heat to get to the heatsinks more easily.

I tried thermal paste. I tried heat sinks on the plastic of the MOSFETs. No fue lo suficientemente bueno.

Also for some reason, the backs of the MOSFETs are connected to one of their pins meaning that, should the backs touch anything metal they’re not meant to (pretty much anything), including the *metal* heatsinks mind you (if you, say, sanded too deep or didn’t use a ["yes to heat, no to electricity" thermal pad](https://www.amazon.com/Outus-Silicone-Reusable-Conductive-Conduction/dp/B094PWW9TM)), it could short circuit and destroy everything. *But I’ll get to the MOSFETs later.*

------

Okaaay, rant over. The point is, apparently [the BTS7960s are not rated for as big of motor as mine is without modification](https://www.letscontrolit.com/forum/viewtopic.php?t=7928). It may have been an issue related to a common ground, though I can’t say for sure.

##### Introduction to My DIY H-Bridges

"Heat’s a problem with these specialized circuits because they are not designed for this application and are unconfigurable so I’m going to do as this project’s overarching philosophy preaches and break them down into their base parts so I can understand and make them myself. They’ll be even more custom and also won’t have the issue of getting too hot and will be easy and quick and fun to make." … is approximately what past me thought to herself, so full of optimistic naïveté. She was right about one out of three things though: they were kinda fun to make (though the jury’s still out on that). I was also going to make one myself eventually anyway, I just didn't expect to be doing it now.

On the bright side, I did indeed follow this project’s overarching philosophy in this way but also another—I dove deeper into a single something rather than shallowly into several somethings. I’ll talk about that more in the reflection, but the important thing now is that single something I learned a lot about: MOSFETs.


### DIY H-Bridges

Ah, the reality half of "Expectation vs. Reality," what a marvelous, messy, and marvelously messy side of things. So much excitement—or disappointment—depending on ~~what part I remember most~~ how you look at it. The suspense of not knowing how the potential will be realized. More flowery introductory sentences that raise expectations to those for a light, poetic reading experience as a sort of meta-commentary on expectations contrasted with reality through the rhetorical irony of that divide being perpetuated by a thought making commentary on it and the absurdism of—okay I’ll stop, I’ve had my fun. Where was I? Oh, right, MOSFETs <sup>~~hey, it’s a hypophora~~</sup>

First though, my making of my own H-bridge circuits ended up being much more involved than originally thought (which really shouldn’t be all that surprising to me at this point) so I promoted its heading to get more subheading options and include more details!

#### Creating an H-bridge

As sometimes painful as it was to make the H-bridges, It did feel good to make my own circuit without following any online tutorial. It reminds me of when MCAD was just starting to "click" for me after I had a handle on the basic features. It’s nice to have even just a small amount of the understanding I now do with MCAD with electronics.

--------

That said, I definitely did ride this high and overestimate my understanding of things initially. My first attempt at the circuit had all MOSFETs in a row on the breadboard to give myself some more room:

| ![arduino uno connected to H-bridge on breadboard and electromagnet](<./Documentation Graphics/Electronics/H-bridges/V0 Linear Progress 1.jpeg>) | ![arduino uno connected to breadboard with MOSFETs](<./Documentation Graphics/Electronics/H-bridges/V0 Linear Progress 2.jpeg>) | ![arduino uno connected to breadboard with MOSFETs](<./Documentation Graphics/Electronics/H-bridges/V0 Linear Progress 3.jpeg>) |
|:-----------------------------------:|:-----------------------------------:|:-----------------------------------:|

…but I didn’t know the circuit had diodes in it because I didn’t fully understand it at this point (there was another major issue with it, too). But, even though what I had made was not an H-bridge circuit, it was a circuit I had made without a tutorial or assistance, and so it gave me some more undeserved confidence and I was excited and ready to try again.

So great was my overestimation in my ability and understanding that in my next attempt at the circuit, I made it compact. So compact, in fact, that I see now in hindsight that it actually had a function I was unaware of at the time and which it performs surprisingly well; that is, it acts as a display of my then-gross overconfidence.

<center>

|	![The second draft of my H-bridge circuit](<./Documentation Graphics/Electronics/H-bridges/V1 Dense Breadboard Angle Top.jpeg>)	| ![Another angle of the 2nd attempt at an H-bridge](<./Documentation Graphics/Electronics/H-bridges/V1 Dense Breadboard Angle Top2.jpeg>) |
|	:--:	| :----: |

A monument to my hubris: the second draft of my H-bridge circuit using IRLZ34N MOSFETs on a breadboard which I wired up *moderately densely*.

</center>

So yeah, big mistake. I was thinking about 3 things when deciding to go down this route:
1. Doubt—because I'm going to be making it into a protoboard anyway, it's also going to become small and compact anyway no matter what I do therefore there’s no reason to not make it big now
2. Flashback—when a tutoring student says "okay, I understand it now, give me a hard one!" you never give them a really hard one without confirming that they’re ready somehow. Never.
3. Deja Vu—when I was starting with MCAD (and even now still) and thought I finally had a handle on something and could imagine how to make a design and the steps involved, the steps I imagined could indeed be done, but the method turned out to be bad or inefficient, and that the feeling of understanding I first had with MCAD was the same as my feelings in the moment.

But, "it’s such a simple circuit," I thought. "It's fineeeeee." So oh well, I learned my lesson: breadboards are, among other things, drafting tools and so making drafts easily editable is the point, so don’t fight that.

I thought I could fight that because I had seen many examples of breadboards which were completely packed full of stuff and still worked perfectly, and I thought that was quite cool. However, the key difference between those and mine is that mine is the first draft, not the final one. They also have experience. And custom-cut wires (not exclusively "prototyping" jumper wires). And ECAD.

That last one is really important for compact circuits on breadboards because dense circuits are, for most all intents and purposes (and especially for someone like me who is inexperienced with electronics), read-only and pretty much undiagnosable because it’s hard to trace connections. I did catch *some* errors in mine (flipped diodes, wrong rail jumped to, possible short) thanks to a multimeter and sketching out the circuit:

| ![Dense H-bridge circuit on breadboard next to sketch of the H-bridge circuit](<./Documentation Graphics/Electronics/H-bridges/V1 Dense Breadboard Next to Layout Sketch.jpeg>) |
|:---------------------------------------------------------------------:|
|                            Having a plan helps. Also, hey, that looks like an "H" now.                      	|

Interestingly, the dense circuit did actually cycle the voltage like it was meant to, just nowhere near as much as it should have:

<center>

| {{< video src="./Documentation Graphics/Electronics/H-bridges/V1 Dense Breadboard Voltage Fluctuation Too Small.mp4" type="video/mp4" width="80%" >}} |
|:---------------------------------------------------------------------:|
|                            Using a multimeter on the compact H-bridge circuit revealing its voltage switching performance.                         	|

| {{< video type="video/mp4" src="./Documentation Graphics/Electronics/H-bridges/V1 Manually Switching MOSFET.mp4" width="75%" >}} |
|:---------------------------------------------------------------------:|
|                            The voltage across a MOSFET when I manually connect its control pin to power and ground.                         	|

</center>


If I had to guess, I’d say the MOSFETs were being switched outside of the optimal pattern. Of course, I didn’t confirm this because it was not worth it to me to try to decipher my mess.

Regardless of the errors that I did catch, I did fundamentally misunderstand MOSFETs that made me not actually understand the H-bridge circuit. I am actually glad I had this misconception because, had the dense circuit worked, a bad habit would have been reinforced or possibly born.

##### **G**ate, **D**rain, and **S**ource
*A ~~Tragedy~~ Story of Electricity and Learning in Three Parts*

A MOSFET, a metal–oxide–semiconductor field-effect **transistor**, is, being a type of transistor, a digital switch. I had thought they were like a doorway—people can go through both ways if the door is open and cannot go through if it is closed. Indeed, some do work this way, but those are special cases. The more broad case has a Source, a Drain, and a Gate. If the gate receives voltage, the FET allows current through. However, that current can *only flow in a specific direction*: the electrons enter through the Source and exit through the Drain. In other words, if the drain side must be the grounded side (or otherwise more negative) than the source side and if it’s not, current will not flow despite the "gate" being open. In hindsight, this does make a lot more sense from a chemistry perspective than what I had originally thought.

Also, remember how I said that the backs of the MOSFETs are connected to "one of their pins" for "some reason" and that "I’ll get back to MOSFETs later." Well, later is now, the pin the metal backs are connected to is the drain pin (i.e., ground), and so it is based in some logic (establishing common ground is often important). Personally, I am not advanced enough in electronics to appreciate this decision so it will still bug me.

###### Chemistry of MOSFETs

Y’know what doesn’t (sometimes) bug me? Chemistry! I think the "why" behind MOSFETs and their GDS stuff is actually pretty interesting, so…

There are two main types of MOSFETs: n-channel and p-channel. In an n-channel MOSFET, the channel is made of n-type semiconductor material, which means it is doped with impurities that give it an excess of electrons. In a p-channel MOSFET, the channel is made of p-type semiconductor material, which means it is doped with impurities that give it a deficiency of electrons, or "holes." The electrical standard cares about these "holes" and current flowing from positive to negative because old dead guys said so (even though it’s technically the other way around with the electrons and all that, but I digress).

The source and drain of a MOSFET are the two terminals that allow current to flow through the transistor. The gate terminal is insulated from the channel by a thin layer of oxide, which is why it is called a "metal-*oxide*-semiconductor" transistor.

When a voltage is applied to the gate terminal, it creates an electric field that modifies the conductivity of the channel. If the voltage is positive (for an n-channel MOSFET) or negative (for a p-channel MOSFET), it attracts electrons to the gate and creates a conductive channel between the source and drain. This allows current to flow through the transistor from the source to the drain. If the voltage is removed from the gate, the channel becomes non-conductive and the transistor is turned off.

##### Remaking the H-Bridge Circuit Properly to Make it Useful


On top of spreading things out, I thought it would be clearer if I doubled up the breadboards so only the outer rails are used on both sides and let me just say, there’s a reason entropy wins in the end. Although, in this case, I’d say it actually has less disorder *because* it was spread out:

| ![Organized DIY H-bridge circuit on breadboard with just signal connections and components](<./Documentation Graphics/Electronics/H-bridges/V2 Spread Out Breadboard Progress 1.jpeg>) | ![Organized DIY H-bridge circuit on breadboard with all connections](<./Documentation Graphics/Electronics/H-bridges/V2 Spread Out Breadboard Progress 2.jpeg>) |
|:-----------------------------------:|:-----------------------------------:|
|           	The H-bridge prototyped properly. Here, just the components and arduino connections are placed.           	|            	And here is the completed H-bridge circuit! The blue wires are connected to a multimeter not in frame.               	|

The outer rails are the H-bridge’s input current (DC) and the middle rails are the H-bridge’s outputs (AC). 

I say it’s complete, but the multimeter will be the judge of that…

| {{< video type="video/mp4" src="./Documentation Graphics/Electronics/H-bridges/V2 Spread Out Breadboard Progress 3 - Multimeter.mp4" >}} |
|:---------------------------------------------------------------------:|
|                            	Survey says…                           	|

That’s what you like to see! I didn’t even have to debug anything because I didn’t make any errors to begin with. Part of this I’m sure can be attributed to my better understanding, but everything being spread out and easy to see where everything is is probably the main reason. And it’s also much more readable, so will be a far better reference when making protoboards. No wonder people stick to procedure….

On the subject of readability, I thought it would be cool, especially for the display for the presentation, to put LED indicator lights directly connected to the gate on each MOSFET. This way, you could see the "X" of where the final AC signal comes from. 

<center>

| <img src="./Documentation Graphics/Electronics/H-bridges/V2 Spread Out Breadboard Progress 4 - LEDs.jpeg" alt="H-bridge breadboard circuit with LED indicator lights" width="75%"/> | {{< video type="video/mp4" src="./Documentation Graphics/Electronics/H-bridges/V2 Spread Out Breadboard Progress 5 - LEDs Blinking.mp4" width="100%" >}} |
|----:|:---|
|  Adding the lights…  |  X marks the spot!  |

</center>

The indicator LEDs really do help to show how the current is flowing through the output load.

I did make an H-bridge in KiCad later, and with the components spread out, it’s pretty easy to see what’s what:

|	![H-Bridge circuit diagram](<./Documentation Graphics/Electronics/H-bridges/H-bridge circuit schematic KiCad.svg>)	|
|	:--:	|
|	Circuit schematic for my DIY H-bridges made in KiCad.	|

Given that mine actually works for the job it’s designed for and the arduino BTS7960 doesn’t, it would appear that looks are not everything when it comes to expectation and reality. Another dub for the DIY community.
##### Hot FETs

Nonononoooo
When I tried the breadboard circuit hooked up to an electromagnet as a load, it got concerningly hot.

The heat is what catalyzed my switching away from BTS7960’s in the first place! This is the worstttt

Just kidding! While I was concerned for a moment, I soon realized that I should still expect the MOSFETs to get hot—the [IRLZ34N MOSFET’s datasheet](https://www.mouser.com/datasheet/2/196/Infineon_IRLZ34N_DataSheet_v01_01_EN-1732809.pdf) saying that they’re rated for the current my motor is rated for is doing so under the assumption that they’re cool. (One of) the advantages of MOSFETs over the BTS7960 is that I could cool them *much* better because I wouldn't be foolish enough to try to cool through an insulator, but instead directly connect them to heat sinks.

I can also use some giant, hopefully-overkill heat sinks so I can focus on electrical *function* before efficiency. However, I do want to test the possibly overheated MOSFETs to make sure they're functional.

###### MOSFET Auto-tester With Oscilloscope

There isn’t much to this circuit other than just hooking a MOSFET up to an oscilloscope. I used the Digilent Analog Discovery 2 oscilloscope. I also did throw an LED into the test circuit just as an extra visual indicator.

| ![Bird's eye view of the oscilloscope and test circuit](<./Documentation Graphics/Electronics/H-bridges/MOSFET Tester Setup Wire Birds Eye.jpeg>) | ![Closeup of the oscilloscope and test circuit](<./Documentation Graphics/Electronics/H-bridges/MOSFET Tester Setup Wire Closeup.jpeg>) |
|:-----------------------------------:|:-----------------------------------:|
|           	Bird's eye view of the oscilloscope and test circuit           	|            	Closeup of the oscilloscope and test circuit                 	|

| {{< video type="video/mp4" src="./Documentation Graphics/Electronics/H-bridges/MOSFET Tester Setup Controlled with Oscilloscope.mp4" width="80%" >}} |
|:---------------------------------------------------------------------:|
|                            	Controlling the MOSFET with the computer running the Analog Discovery 2 software. (I don’t know morse code.)                            	|

While results seem to indicate that the MOSFETs are still functional, I’d much rather be cautious than reckless (especially after my compact breadboard fiasco).

##### Protoboard H-Bridges

Protoboards are the middle ground between a printed circuit board (PCB) and a breadboard. Let’s see how much we can shrink and streamline the H-bridge.

| ![Rough protoboard sketch layout](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 0 - Very Rough Layout Wiring Diagram.jpeg>) | ![Protoboard with components arranged in initial layout](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 1 - Initial Layout.jpeg>) |
|:-----------------------------------:|:-----------------------------------:|
|           	I started with a very rough sketch to get an idea of what layout would work...           	|            	...and then arranged the components on a protoboard without soldering based on that.                 	|

The screw terminals interface the H-bridge with power and their phase of the motor and the female JST connector interfaces them with the microcontroller.

The MOSFETs were a bit of a pain to solder perpendicular to the protoboard because their pins are flanged and so they don’t sit flush with the protoboard, but it wasn’t too bad. Remember how I mentioned disagreeing with the decision to connect the drain to the large metal back of the MOSFETs? Yeah, I still do. This was my fault, but the wiggling of the MOSFETs was enough to worry me that they might short, especially with higher amounts of current:

| ![MOSFET Drains sit concerningly close to one another](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 2 - FET Drains Touch.jpeg>) |
|:---------------------------------------------------------------------:|
|                            	MOSFET Drains sit concerningly close to one another when arranged on a protoboard.                            	|

| ![Protoboard in a metalworking vice](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 2 - FET Drains Touch.jpeg>) | ![Increasing the space between drains](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 3 - Dremel FETs.jpeg>) |
|-----------------------------------:|:-----------------------------------|
|           	It's a good thing           	|            	I have a dremel                 	|

With some gentle convincing, there is more space between the FETs’ drains. I was careful to go slowly so as to not heat up the MOSFETs.

With the next boards, I changed the components’ arrangement slightly to avoid this tight-spacing issue to begin with. I’ll also just relegate the odd one out to be a part of the magnet flipping demonstration on the display.

| ![New protoboard component layout](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 4 - New Board Arrangement.jpeg>) |
|:---------------------------------------------------------------------:|

Jumping wires and making connections and I have two almost complete H-bridges:

| ![One protoboard H-bridge near completion](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 5 - Almost Complete Board 1.jpeg>) | ![A different protoboard H-bridge similarly near completion but in a different manner	](<./Documentation Graphics/Electronics/H-bridges/V3 Protoboard Progress 5 - Almost Complete Board 2.jpeg>) |
|:-----------------------------------:|:-----------------------------------:|

Now, what to do about the heat? Well, I have two large heat sinks with these guys’ names on ‘em. I drilled and tapped them so I can screw the H-bridges to them using nylon (non-conductive) screws and then later put silicone thermal pads between them and the heat sinks once they’re all soldered up. Heat be gone!

| ![Various](<./Documentation Graphics/Electronics/H-bridges/V4 Mounted on Heatsink - Angle 1.jpeg>) | ![angles of](<./Documentation Graphics/Electronics/H-bridges/V4 Mounted on Heatsink - Angle 2.jpeg>) |
|:-----------------------------------:|:-----------------------------------:|
| ![protoboard](<./Documentation Graphics/Electronics/H-bridges/V4 Mounted on Heatsink - Angle 3.jpeg>) | ![H-bridges](<./Documentation Graphics/Electronics/H-bridges/V4 Mounted on Heatsink - Angle 4.jpeg>) |

##### Major Iterations of H-Bridges

<center>

| {{< video type="video/mp4" src="./Documentation Graphics/Electronics/H-bridges/V4 Mounted on Heatsink - All Versions Compared.mp4" width="100%" >}} | ![Evolution of H-bridge iterations](<./Documentation Graphics/Electronics/H-bridges/V4 Mounted on Heatsink - All Versions Compared.jpeg>) |
|:---------------------------------------------------------------------:|:-----:|
|                            	                           	|                            	                           	|

Evolution of H-bridge iterations</center>

##### H-Bridge Code

<details><summary>BTS7960 Component Sketch</summary>

```arduino
// BTS7960 arduino H-bridge motor driver sketch 

// pins
const int R_PWM = 3; // Pin for control of one side of the H-bridge
const int L_PWM = 5; // Pin for control of the other side of the H-bridge
const int L_IS = 7; // overcurrent pin
const int R_IS = 5; // overcurrent pin

// enable pins not set because they are wired to HIGH

void setup() {
  // Set the control pins as outputs
  pinMode(R_PWM, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(R_IS, INPUT);
  pinMode(L_IS, INPUT);

  // start serial
  Serial.begin(9600);
  Serial.println("Serial Begin");
}

void loop() {

  // Drive the motor forward at 100%
  analogWrite(L_PWM, 0);
  analogWrite(R_PWM, 255);
  delay(500);

  // Stop the motor
  analogWrite(R_PWM, 0);
  analogWrite(L_PWM, 0);
  delay(100); // Pause for 0.1 seconds
  
  // check for overcurrent
   if(digitalRead(R_IS)){
     Serial.print("R OVERCURRENT @ ");
     Serial.println(millis());
   }
   if(digitalRead(L_IS)){
     Serial.print("L OVERCURRENT @ ");
     Serial.println(millis());
   }
  
  // drive other way
  analogWrite(R_PWM, 0);
  analogWrite(L_PWM, 255);
  delay(500);
```
</details>

<details><summary>

Homemade H-Bridges Sketch <sup>[</sup>[^MPS]<sup>]</sup>

</summary>

Because of the heat issues, I was worried about PWM-ing the power MOSFETs. Also, I can’t PWM both the power and ground at the same time because there’s no guarantee that the signals would line up (in fact, it would be quite unlikely). I also always made sure to actively close the MOSFETs when they weren’t in use, just in case.

```arduino
// pins
// r and l are directions
// these are all MOSFET gate pins
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
  float power_frac = 1;  // used as an easy multiplier for power but was temporarily removed (e.g. 0.5 for 50% power) 
  int delay_time = 5000;

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
```

</details>

<details><summary>HallEffectTest</summary>

```arduino
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
```

</details>

<details><summary>Simple rotation</summary>

VERY work in progress; I just wanted something to work so I could code the phases… it didn’t turn out that way of course because I couldn’t get the BTS7960s working once again.

```arduino
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
```

</details>

#### A Brief Aside on the Importance of Resistors

The resistors that connect to the MOSFETs’ gate input seemed kind of weird and unnecessary to me.

To my surprise, they’re actually vital. This is because the MOSFETs act as capacitors of sorts and, upon activation into their Gate pin, have effectively 0 resistance. Once they get some current, then the resistance increases.

Now, 0 resistance sounds great and it seems silly to add some; however, because of Ohm’s Law of `V = IR` and `I = V/R`. This means you'll effectively get ≈infinite current at the instant of trying to activate the gate pin, which would be *bad* and destroy basically everything.

Obviously resistance is not actually *equal* to 0 but instead just *approximately* equal to 0. This is still what those in the industry call "bad," so we add some resistance so there's not this enormous current spike.

This was news to me and I found it interesting, so I wanted to share.

#### The Cold(–Running FET) Promised Land

Bill, a retired electrical engineer at my local makerspace caught wind of my endeavors with MOSFETs. According to him, it is possible to run the MOSFETs cold without any cooling systems; just better control should be enough alone. Basically, because there is effectively no resistance when the FETs are open, this should (and does) not create hardly any heat. All of the heat is during the opening and closing of the gate because resistance spikes and peaks at the halfway point between open and closed (the same is true for all transistors; even the computer chip most densely packed with transistors will cool off as soon as the bits stop flipping).

My analogy, verified for correctness by him, is that you could think about the FETs like a knife switch. Resistance through the knife switch when it's completely closed is effectively zero, but resistance through the air is *really* high, and during the initial connection resistance can be in between. The electricity will attempt to jump the gap through the high-resistance air when the knife switch is partially open, causing a spike in heat (as air is ionized and such). To minimize this heat, you minimize the amount of time you leave the switch partially open or partially closed—you operate it faster.

The same is true for FETs. But, how do you open and close a FET faster? Push harder—give more current to the gate pin. The microcontroller can only supply so much current before cooking itself, so you charge a capacitor with the microcontroller and then discharge it into the gate to open and close it as fast as possible.

To me, this sounds like black magic, but so does most of what Bill does anyway. I would like to try this out though. Sure, capacitors are extra parts, but anything will make the motor more practical than the enormous cooling system I have right now. The (chilly) promised land awaits…

## Reflection

### What I Learned

Before I discuss the other aspects of my reflection, I would first like to talk about all that I learned by doing this project as that was my primary focus. There is (I think) good news in that I learned too much to list, so I’ll mostly be focusing on the things I thought were particularly of note and those which I haven’t mentioned already throughout this post.


##### Electronic Components

- Hall effect sensors
- MOSFETs
- Diodes
- Capacitors
- H-bridges
- Bridge rectifiers
- Electromagnets
- Electrical Voltage and Current

#### Tools

- Oscilloscopes
- Thread tapping tools
- More arduino skills

#### Skills

- Soldering surface mount
- Markdown
- HTML relearning, refinement, and new learning
- blog writing/styling/formatting (one area of improvement would be that I’m overexplaining some things that could just be left as a citation because I find it fun, but I recognize that this habit can potentially *really* clutter things and obscure my actual project & work)

##### CAD

- Much more Inventor/MCAD overall refinement
	- mCAD presentations
	- mCAD drawings
	- mCAD iParts
	- mCAD derived parts
	- mCAD linking parameters
- Introductory eCAD

#### Some personal growth, too
A bit of a hard lesson in piecewise progress and more rigid structures to enforce greater documentation as I go… making daily commits and posting regular progress updates seems like the right way forward

### Answering the Research Question

***What goes into making a speed controller for a BLDC electric motor?***

Quite a bit, it turns out! On paper, it seems rather simple: just turn DC to AC at the right times so you can turn some magnets on or off. But what goes into this is actually really in depth. And it does make sense for it to be so in depth, too—with how common motors are you’d want the process of controlling them to be as robust as possible.

As for the mechanics of this, boy does it get complicated. For starters, I had to build an electric motor so that I could build the speed controller and couldn’t really just use an off-the-shelf one because, at least to my understanding, the sensor-based speed controllers rely on knowing the precise position of/angle between two electromagnets and two permanent magnets. The difficulty of obtaining this data would depend on what motors I have access to and which fit my other requirements (e.g., axial flux, doesn’t have a speed controller built in, decently powerful, somewhat large, openable, information available online etc.) and, less importantly, tastes.

While I wouldn’t’ve had to make my own motor had I made a sensorless ESC, I didn’t know enough electronics to feel comfortable undertaking such a project when given my time/business constraints and, now with hindsight, I do think I made the right call because the project I ended up doing was just the right amount beyond my ability level at the start for me to learn a ton through the challenges it presented and not so far beyond my ability level that I was hopelessly lost.

In any case, what goes into making a speed controller for a BLDC electric motor is apparently everything that goes into making a BLDC electric motor since you have to* make one, on top of the electronics and code necessary to make the speed controller itself.

*I think

### Meeting of Goals?

No way! Well, sort of. It doesn’t entirely feel like it to me. While I did make accomplishments relevant to, in support of, and as a part of this project that were not set as goals, my product does not function and this project is very much still incomplete to me. That said, because the goals were, somewhat intentionally, not defined to demand a functional product, they were met. I think this is a good thing though, because my definition of meeting goals or a successful project is warped to require the content of the project being successful itself, when that’s not always the case; I have learned that I should take extra care with goal setting, as this project really highlighted that I run into difficulty publishing work I feel is unfinished or a failure. This is especially foolish in this case, as not publishing would rather unnecessarily limit my learning and therefore go against this project and many others’ motivation and overall philosophy.

However, regardless of the technicality of whether the goals were met on paper, I would be remiss if all I used this reflection and analysis for was a simple "yes" or "no" for whether the goals were met because, while this project was not successful in creating a motor, it was very much successful in being a learning experience.

With this in mind, what I think are important to reflect on are the research question, the Kaplan objectives, and what I learned. But, first, let’s look at how the *original* goals were met on paper:

- [ ] Design & create an electronic speed controller for an electric motor
- [x] Design & build an electric motor from scratch for the DIY ESC
- [ ] Program the DIY ESC to control the motor
- [x] To learn, which should be evidenced through a blog post meeting the following:
	- [x] Documents the project and its process with text, code, designs, explanations of code and of designs, pictures, videos, other graphics (e.g., animations), captions, and textual explanations
	- [x] Is a minimum of a 4-8 minute read
	- [x] Is neatly structured (or, at least, organized)
	- [x] Contains a reflection section
	- (Optionally contains) a short preview/summary video up to around 1 minute in length
- [x] Create a presentation display for the motor

So, it’s clear that I learned a tremendous amount and the blog post is quite complete, but the first couple goals are iffy. A goal that the motor or other products had to be *working* was never set; however, this is splitting hairs and silly nitpicking which misses the much more important fact that my goals changed as I was going about the project.

I did initially intend to have a working motor and ESC, however, I did not plan for it in goal form because my overarching philosophy was that:

- [x] ***It is better to dive deeply into a single something than shallowly into several somethings***

Not having functionality be baked into my goals gave me much-needed room for flexibility.

This is perhaps most notable when I ran into complications with the H-bridges. Given that the off-the-shelf ones simply did not work at the power levels they advertised, I had to change plans. It happens that making my own was more in line with this overarching goal of learning anyway with my discovering just how complicated just the H-bridges were. Unfortunately, while I learned a lot, prototyped two, but could not finish building the three my design required (or even a fourth/just one to use in a display).

### Next Steps

#### Part 1: Finishing the Project

I say "Finishing the Project," but really that is finishing *this* project, which is still just a prototype. That said, here’s what I believe is involved given the current state of things:

- Finish current electronics
	- Get H-bridges soldered on protoboard
	- Mount Hall effects on motor
	- Connect Hall effects to stator "hub" protoboard
- Program phases based on Hall effect input
- Wrap 1 or 4 more coils to have either 2 or the desired 3 per phase

- Finalize presentation board
	- Mount electronics
		- Connect things (power rails, etc.)
	- Magnet flipper demo
	- Peripherals
		- LEDs next to each H-bridge for which phase they’re in
		- LCD display with information (RPM, current draw, voltage)
			- (optional) (pin-eating) 7 segment RPM meter
		- LED ring showing magnet positions
		- (optional) use a TFT to show 3 scrolling sine waves for the phases
		- (optional) connect with website (Spin CAD model, display information other peripherals have (RPM, current draw, phase sine waves, graphic magnet position view, graphic of the electromagnets on the stator colored by their current phase, regen enabled, etc.))

#### Part 2: Extensions & Future Projects

While this seems like the smallest or simplest of the three parts, it very well could be the hardest. I can’t really say because it is mostly electronics, which I still don’t know much about, and certainly not enough to make accurate predictions of time or scope because I can’t imagine what the product may look like.

- Regenerative braking
- Optimize ESC to minimize switch time (eliminate need for heat sinks)
- Optimize coil design

Optimizing the coil design is going to be notably difficult. This is simply because it is the hardest thing for me to iterate upon, as coils pretty much need to be rewrapped and made permanent. This is not damning in its own right—I need to reprint an entire new rotor every time I modify the design, for example—but copper is expensive and wrapping takes a lot of time.

#### Part 3: Making it Professional

This project was in support of a greater project of making an electric scooter from scratch. So, eventually, its product needs to be a motor and ESC which are usable in that case. That will pretty much involve remaking the entire motor (the "Final Draft," if you will), so whatever the current one is at the point of starting to make this final draft can be kept for the presentation board.

- "Package" motor
	- Reprint everything in ASA
	- Redesign stator
		- Design & make other stator half
		- Give coils cores
			- Make new coils
	- Make PCB for the internals of the stator and Hall Effect sensors
	- Cable management solution (e.g., hollow axle)
	- Make 2<sup>nd</sup> rotor (even if it doesn’t have magnets)
	- Design and make "fat" rotor band to enclose motor and connect two rotor halves (basically make proper motor housing)
- "Package" ESC
	- Make PCB for ESC
	- Make housing/package
- Test motor & its limits
### Kaplan Objectives

#### Change Over Time
*What was it like in the past, the present & what might it be like in the future?*

Saying just "yes," while apt, is perhaps too succinct.

Especially in this reflection, and in particular the previous Next Steps section, I thoroughly examined what the project might look like in the future based on its current state, which I summarized throughout the rest of the blog.

Throughout the rest of this blog, I showed literal change over time by documenting my process and creation steps.

#### Details
*Who..? What..? When..? Where..? Why..? How..?*

Again, I think that saying just "yes" here would be apt but perhaps too succinct. This one is also a bit more nuanced than just that.

I initially planned for this Kaplan Objective to be demonstrated in the tests that I was expecting to perform on the motor (such as rated voltage/current, RPM, torque, etc.), but, given that my motor was nonfunctional and incomplete, I could not perform such tests.

Despite this, I believe that this Kaplan Objective was still demonstrated through the copious examination of various aspects of this project. In the research, I answered many questions through explanations (for example, the "Why" of the MOSFETs’ drain being connected to their metal backing was proposed). In my motor itself, I discussed a great deal of the "whats, wheres, whys, and hows" of my motors design.

## Bibliography

To go back up to the research section in the introduction, click [here](###Research).

### Reference List
