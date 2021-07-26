# Button
Button Class

This class implements a button input complete with a variable debounce delay.
It has no delay() calls in its implementation and requires calls to the update() method
to check if if time has expired.
  
It is defined in one of two ways as follows:
  
	 Button(byte pin);
     Button(byte pin, unsigned long debounceDelay);
	  
The first way shown just needs to know what pin you want to use. It will define that pin using input_pullup and use the default
debounce delay of 50 ms. The physical button you connect only has to short the pin to ground to work.
Note that on some Arduinos pins A6 and A7 do not have pullup resistors available.
These are handled in the class as special cases and defined as input only (no pullup). You could add external pullups if desired.

The second method also passes a debounce delay (in ms) and this will override the default 50 ms. 
If you use this class to detect a passing train for example (using an infrared senor instead of a button) a longer delay
is useful so that the gap between wagons does not cause minor blips (depending on speed of travel of course).  
  
### Files: Button.h, Button.CPP

### Usage:
Include the header file near the top of your code. (After this is done the compiler will know how to handle you using it.)

    #include "Button.h";

### Instantiation:

An example of its use is shown below.

     const byte   SensPin1   = A0;        // Use this input for sensor input to detect TT is in position 1
     ...
	 Button SENSOR1    (SensPin1, 5);     // Sensor for Position 1 with a very small 5 millisecond debounce

### Methods
    void Update();                        // check current timing to see if anything needs doing

### Properties:
    bool State();                         // What is the current state of the button (true or false)
    bool IsPressed();                     // Alternate way of checking state - improves code readability.
	bool IsNotPressed();                  // Alternate way of checking state - improves code readability.



