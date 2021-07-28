#include "Button.h"

Button::Button(byte pin, unsigned long debounceDelay) {
  // Save the passed pin and debounce delay into the equivelent local variables (with underscore)
  _pin = pin;
  _debounceDelay=debounceDelay;
  init();
}

Button::Button(byte pin) {
  // If debounce delay was not passed we will use the default value of 50ms (as specified in the button.h code)
  _pin = pin;
  init();
}
void Button::init() {
  if (_pin == A6 || _pin == A7){
     pinMode(_pin, INPUT);             // A6/A7 are analog input only - special case
  }
  else {
     pinMode(_pin, INPUT_PULLUP);    // using internal pullup. Reads high until button is pushed.
  }
  _lastReading = digitalRead(_pin);  // first update during initialization
  _state=false;                      // state is assumed false until debounce time expires
}

void Button::update() {
    // I will handle the debounce of the button directly in the class
    bool _newReading;
    int _analogVal;
    if (_pin == A6 || _pin == A7){
     _analogVal = analogRead(_pin);
     _newReading = (_analogVal >= 300); // A6/A7 are analog input only - special case logical comparison
    }
    else {
    _newReading = digitalRead(_pin);   // _newReading only exists for the duration of each update call 
    }
    if (_newReading != _lastReading) {
      _lastDebounceTime = millis();
    }
    if (millis() - _lastDebounceTime >= _debounceDelay) {
      // update the 'state' attribute only if debounce time has passed
      _state = _newReading;
    }
    _lastReading = _newReading;
}
bool Button::state() {
  return _state;
}

bool Button::isPressed() {
  return !_state;                         // Due to pull up isPressed is Inverse
}

bool Button::isNotPressed() {
  return (!isPressed());                  // This will always be the opposite of isPressed()
}
