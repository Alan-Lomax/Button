#ifndef MY_BUTTON_H
#define MY_BUTTON_H
#include <Arduino.h>

class ButtonClass {

private:
  byte _pin;
  bool _state= false;                   // The debounced state of the button True = Pressed
  bool _lastReading = false;            // previous button reading so we can compare if a change has occured
  unsigned long _PressCount = 0;        // Running count of the number of presses
  unsigned long _lastDebounceTime = 0;  // For measuring Debounce intervals
  unsigned long _debounceDelay = 50;    // default debounce delay
  void init();

public:
  ButtonClass(byte pin, unsigned long debounceDelay);  // Instantiated passed pin and with a custom debounce time
  ButtonClass(byte pin);                               // Instantiated passed pin and the default debounce
  void update();                                                   //
  bool isPressed();                                                //
  bool isNotPressed();                                             //
  unsigned long PressCount();                                      // how many pushes so far
};
#endif