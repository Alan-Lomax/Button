# Button
Button Class

This class implements a button input complete with a variable debounce delay.
It has no delay() calls in its implementation so your mainline loop code can keep running doing other things.
  
It is defined in one of two ways as follows:
  
     Button(byte pin);
     Button(byte pin, unsigned long debounceDelay);
      
The first way shown just needs to know what pin you want to use. It will define that pin using input_pullup and use the default
debounce delay of 50 ms. The physical button you connect only has to short the pin to ground to work.
Note that on some Arduinos pins A6 and A7 do not have pullup resistors available.
These are handled in the class as special cases and defined as input only (no pullup). You could add external pullups if desired.

The second invocation method also passes a debounce delay (in ms) in addition to the pin. The passed debounce will override the default 50 ms. 
If you use this class to detect a passing train for example (using an infrared senor instead of a button) a longer delay
is useful so that the gap between wagons does not cause minor blips (depending on speed of travel of course).  

This class can be used on many types of inputs not just pushbuttons. 
Toggle switches, infrared detectors, magnetic reed switches are all suitable for use with this class.
With longer debounce values (much longer than 50 ms) this class effectively becomes a simple fixed 'time delay'.
This is useful when used with sensors but long delays could be annoying when used with hand operated switches though.
  
### Files: Button.h, Button.CPP

### Example:
Notice in this example that the loop calls the update() method and then also acts on whether the debounce time has been Activated by checking the state().
At no point does the loop hang around waiting for something to happen. 


    /*
        Example of using the Button class for debouncing a switch or sensor.
        In this case an IR sensor is connected to A0 and pulls A0 to ground when something is detected. (you could use a switch or pushbutton from A0 to ground also.)
    */
    #include "Button.h";

    // Define constants here
    const bool  Activated  = true;      // Because the input is declared with input pullup, it normally reads 'true' (a high voltage) and when the button is pushed it reads 'false' or a low voltage. 
    //                                     Some sensors invert this so using a constant like this makes the intent clear and swapping true to false is easy.
    const byte   SensPin1  = A0;        // Use this input for sensor input.

    Button SENSOR1    (SensPin1, 5);    // Defining Sensor1 outside of setup makes it 'global' and accessable from any part of the program. Here we use a very small 5 millisecond debounce
                                        // Note you can define as many of the Button class as you need .. and they will not interfere with each other.

    void setup() {
      Serial.begin(9600);               // for serial monitor / debug console
      Serial.println(__FILE__);         // by habit I always output the file name - so I know what program is running at startup.
    }

    void loop() {
      SENSOR1.update();                    // See if anything has changed

      if (SENSOR1.state() == Activated) {  // Has the button been pushed and the debounce time expired?
        // Do something here
          Serial.println("SENSOR1.state() is Activated");    // message is same as logic test - so we know this logic test is working.
      }
    }


### Methods
    void update();                        // check current timing to see if anything needs doing

### Properties:
    bool state();                         // What is the current state of the button (true or false)
    bool isPressed();                     // Alternate way of checking state - improves code readability. (Note this does not imply a pushbutton only - it could be one state of a toggle switch)
    bool isNotPressed();                  // Alternate way of checking state - improves code readability. 
