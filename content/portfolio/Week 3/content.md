+++
fragment = "content"
weight = 100
+++

# Kinetic Sculpture
## Outline
Because the lab makerspace does not currently have a UV curing station for the Formlabs SLA 3D printer, therefore rendering it unable to be used, I wanted to help out by making one.

The basic requirements for a curing setup are actually pretty simple:
* Must have relatively even, total coverage of UV light

...and that's really it. To accomplish the requirements of "relatively even" UV light with "total coverage" of the parts as cheaply and effectively as possible, the basic idea is this: a cardboard box with UV LED strips, a turntable, and a lot of mylar. Here is a precise sketch:

The motor does not need to be powerful at all, in fact, it's probably better for energy and part stability for it to be slow. The yellow motors will suffice for this project. Soldering up wires and adding a dab of hot glue gives us:

The motor having an output shaft that comes out both sides is problematic for us, as we want it to lie flat. So, we will cut off the part on the wire's side with a hacksaw.

I don't like the idea of gluing the motor to something (especially since that would likely involve sanding to roughen up the smooth, injection-molded plastic surface just to get glue to stick), so we will use bolts in the two holes to affix the motor to the laser-cut housing.

This gives us information of what details we should include in our CAD of the motor (and gearbox); these details being the general shape (we don't need to be specific with the geometry because it won't be press-fit into the housing), sizes, the output shaft location, and information about the mounting holes we'll use.


## Motor CAD
###### Cool Caliper & CAD Hacks
For all these *measured* dimensions and not ones that are for custom user values, we can just name our `model parameters` appropriately instead of making a bunch of `user parameters`.

If the part you're measuring was made by a person, it probably has standard, whole number, or common fractional measurements. If you can check it against something (like an M3 bolt), feel free to round if your calipers measure something close but not quite. Make a comment of it along with the actual, measured value in the parameter, though.

After taking a measurement, you may be able to figure out if your calipers drifted a bit by closing them and seeing if they still say zero.

The motor is smaller than the gearbox on all sides, so measuring its length conventionally would be difficult. So, we can measure the gearbox length, zero the calipers, and then extend them to measure the entire motor + gearbox assembly length, only with the gearbox length already subtracted.

Positioning the mounting holes is annoying—you would have to measure the edge-of-circle-to-wall distance because of the nature of calipers, and then constrain the center of the circle to the wall and add the radius and it's just a mess. Instead, you can create a `construction` `centerline` constrained to the midpoint of the body:

Then, place the circle somewhere where it does not snap to anything:

And now, constrain the circle's horizontal distance to the centerline using the center-to-center measurement of the circles (the dimensional constraint will look different, that's because it's controlling the center-to-center distance to where a reflection about of the centerline would be):

This is also very handy because we can now `pattern reflect` this hole about the centerline.

However, measuring the center-to-center distance of holes is often challenging. To get the measurement easily, simply measure the diameter of a hole, zero the calipers, and then measure the outer edge-to-edge distance—it'll already effectively have the radii subtracted twice, giving you the center-to-center distance. Note that this trick only works if the holes are the same size.

###### Cool Caliper & CAD Hacks Over and Out ######


We can just get the center-to-edge distances for other constraints the boring way by measuring the edge-to-edge and then adding half the diameter.

Extrude by the measured height and we have a fancy box with holes in it (even if we weren't planning on putting a spinnable peg there in the assembly, it wouldn't really matter that the output shaft is a hole and not a peg; what's really important is the size and position):

Also, the actual gearbox has some fillets, so we can use our calipers to approximate the fillet radius.

Again, the precise shape of the motor itself is not very important; just that it has pretty accurate dimensions. Because of this, we can approximate it as an ellipse and use the snip tool to cut off the top and bottom:

Extruding:

And now we have our motor all CAD-ed up!


## Tabbed Box CAD

Personally, I don't like designing laser-cut parts in 3D CAD software, especially the tabs. So, I will be using an online tool I've used before to make tabbed boxes; [boxes.py](https://www.festi.info/boxes.py/?language=en).

I like the [electronics box](https://www.festi.info/boxes.py/ElectronicsBox?language=en) design. It has mounting holes which will be useful so the motor spins the turntable instead of itself, and the removable lid is a nice touch.

The option to save settings into a url makes sharing easy, so I'll include urls for every iteration.

The first thing I did was uncheck the `outside` setting and then export a .svg into Adobe Illsutrator with all the other settings as their defaults. I then measured the distance from the base of the walls to the holes for the triangles' tabs, which revealed that the `height` parameter is not for the height of the overall box, but instead the height for the contents (which is good because it's what we would want to control anyway, so it just means less work).

Instead of filling in the parameters on boxes.py with the parameters from Inventor verbatim, I added a bit of wiggle room on the height and length, and a generous amount of space on either side of the motor. This accomplishes three main things:
1. Provides the turntable with a bit more
2. Makes the motor is easier to put in the box
3. Provides space for cable ties if they become necessary.

I'd like to be note that I'm keeping the format as a .svg so I can preview it in my browser and make changes easier; to actually get it laser cut of course needs a .dxf, so I'll just change it to that once it looks good.

This leaves us with [this](https://www.festi.info/boxes.py/ElectronicsBox?FingerJoint_angle=90.0&FingerJoint_style=rectangular&FingerJoint_surroundingspaces=2.0&FingerJoint_edge_width=1.0&FingerJoint_extra_length=0.0&FingerJoint_finger=2.0&FingerJoint_play=0.0&FingerJoint_space=2.0&FingerJoint_width=1.0&x=53.00&y=70.00&h=20.0&outside=0&triangle=18.0&d1=3.0&d2=3.0&d3=3.0&outsidemounts=0&outsidemounts=1&holedist=7.0&thickness=4.6&format=svg&tabs=0.0&debug=0&labels=0&labels=1&reference=100&inner_corners=loop&burn=0.1&render=0):

This looks good, except for the fact that there are no tabs on the triangles. Reading through the settings reveals the culprit(s): `surroundingspaces` and `finger`. Basically, the tabs were too large and demanded too much space around the edges. Lowering these gives us [something good](https://www.festi.info/boxes.py/ElectronicsBox?FingerJoint_angle=90.0&FingerJoint_style=rectangular&FingerJoint_surroundingspaces=1.0&FingerJoint_edge_width=1.0&FingerJoint_extra_length=0.0&FingerJoint_finger=1.5&FingerJoint_play=0.0&FingerJoint_space=2.0&FingerJoint_width=1.0&x=58.00&y=75.00&h=15.5&outside=0&triangle=18.0&d1=3.0&d2=3.0&d3=3.0&outsidemounts=0&outsidemounts=1&holedist=7.0&thickness=4.6&format=svg&tabs=0.0&debug=0&labels=0&labels=1&reference=100&inner_corners=loop&burn=0.3&render=0):

Let's get it laser-cut:

Aaannnd it didn't cut all the way through.

And the lab was closing so this is what we have. After mauling it with an x-acto knife, the only casualty was Wall 3, which lost half its skin due to impatience. Other than that, it seems pretty good. 

While I was at it, I also punched some holes in the bottom and top for bolts and the shaft. The wires can also fit pretty perfectly in between the tabs. Wall 3 losing its skin did enable an easier punching through with the tab on the gearbox, which adds another point of stability. That said, punching all these by hand is not ideal—they should be included in the design. The main issue is that the shaft might not poke through enough, but this can't really be fixed with the design of the box given how perfect the height is, so hopefully a bolt in the shaft will be able to fix it. Lastly, the length is a too long.

For the next iteration, I remade [some alterations to the box with boxes.py](https://www.festi.info/boxes.py/ElectronicsBox?FingerJoint_angle=90.0&FingerJoint_style=rectangular&FingerJoint_surroundingspaces=1.0&FingerJoint_edge_width=1.0&FingerJoint_extra_length=0.0&FingerJoint_finger=1.5&FingerJoint_play=0.0&FingerJoint_space=2.0&FingerJoint_width=1.0&x=58.00&y=66.00&h=15.5&outside=0&triangle=18.0&d1=3.0&d2=3.0&d3=3.0&outsidemounts=0&outsidemounts=1&holedist=7.0&thickness=4.5&format=svg&tabs=0.0&debug=0&labels=0&labels=1&reference=100&inner_corners=loop&burn=0.3&render=0) and then used Illustrator to add the mounting holes I punched through in the first:


