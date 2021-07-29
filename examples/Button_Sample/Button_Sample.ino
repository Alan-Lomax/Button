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
//                                     Note you can define as many of the Button class as you need .. and they will not interfere with each other.

void setup() {
  Serial.begin(9600);       // for debug console
  Serial.println(__FILE__); // by default I always output the file name
}

void loop() {
  SENSOR1.update();                    // See if anything has changed

  if (SENSOR1.state() == Activated) {  // Has the button been pushed and the debounce time expired?
    // Do something here
    Serial.println("SENSOR1.state() is Activated");    // message is same as logic test - so we know this logic test is working.
  }
}
