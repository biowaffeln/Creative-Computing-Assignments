# week three documentation

## lab 2 - hooking up a servo

The first task was to wire up a servo and control it with the Arduino. Here is a video of the working circuit:

[
![servo circuit](https://i3.ytimg.com/vi/hFzfkMQsJAM/maxresdefault.jpg)
](https://youtu.be/hFzfkMQsJAM)

## lab 3 - hooking up a motor

The second lab was hooking up a motor to the Arduino and controlling it with a button. This was somewhat more elaborate as the motor had to be powered by a 9V battery, which would be activated from the Arduino through a transistor.
We did have some problems with this lab, but in the end it just came down to finding a faulty wire (thanks again for helping us with that one, Phoenix!).
[
![motor circuit](https://i3.ytimg.com/vi/cl_hvjHIYIQ/maxresdefault.jpg)
](https://www.youtube.com/watch?v=cl_hvjHIYIQ)

## lab 4 - hooking up an MPR121

Hooking up the MPR121 was again rather straightforward. The interesting thing we noticed was that you could connect the MPR121 both to the SCL/SDA pins as well as pin 2 and 3.

[
![MPR121 circuit](https://i3.ytimg.com/vi/YjwdJJ06TAE/maxresdefault.jpg)
](https://youtu.be/YjwdJJ06TAE)

## lab 5 - CapSense library

The last part of this week's lab was the Capacitive Sensing Library. As it turns out, the library has problems with detection when the laptop isn't plugged in to power, which took me a while to figure out... But in the end I got a basic example working, which you can see here:

![CapSense Library Working circuit](images/capsense.jpg)

When playing around with the above circuit, I noticed a weird quirk in the measurement &mdash; Every time I would touch my laptop with one hand, while holding the copper foil with the other hand, the measured value would become negative. (I am still not entirely sure why exactly that happens, to be honest.)

Anyway, this discovery gave me the opportunity to make something creative with that!
So I decided to send the serial data to a Processing sketch which would draw different faces depending on whether my laptop was touched or not.

Here you can see the final result of my touch sensitive laptop:

[
![CapSense Library Working circuit](https://i3.ytimg.com/vi/nMj0s4Ar5yk/maxresdefault.jpg)
](https://www.youtube.com/watch?v=nMj0s4Ar5yk)
(There's a copper foil that's is held in my right hand)
