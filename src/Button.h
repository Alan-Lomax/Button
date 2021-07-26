#ifndef MY_BUTTON_H
#define MY_BUTTON_H
#include <Arduino.h>

class Button {

  private:
    byte _pin;
    bool _state;
    bool _lastReading;
    unsigned long _lastDebounceTime = 0;
    unsigned long _debounceDelay = 50;
    
  public:
    Button(byte pin, unsigned long debounceDelay);
	Button(byte pin);
    void init();
    void Update();
    bool State();
    bool IsPressed();
	bool IsNotPressed();
};
#endif