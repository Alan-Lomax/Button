#include "ButtonClass.h"

ButtonClass::ButtonClass(byte pin, unsigned long debounceDelay) {
  // Save the passed pins and debounce delay into the equivelent local variables (with underscore)
  _pin = pin;
  _debounceDelay = debounceDelay;
  init();
}

ButtonClass::ButtonClass(byte pin) {
  // If debounce delay was not passed we will use the default value of 50ms (as specified in the button.h code)
  _pin = pin;
  init();
}

void ButtonClass::init() {
  if (_pin == A6 || _pin == A7) {
    pinMode(_pin, INPUT);  // A6/A7 are analog input only - special case
  } else {
    pinMode(_pin, INPUT_PULLUP);  // using internal pullup. Reads high until button is pushed.
  }
  _lastDebounceTime = millis();  // Current time in millis for measuring debounce intervals
}

void ButtonClass::update() {
  bool _newReading;  // _newReading only exists for the duration of each update call
  // Step 1 read the pin
  if (_pin == A6 || _pin == A7) {
    int _analogVal = analogRead(_pin);  // only delcare the analog value if it is needed
    _newReading = (_analogVal <= 300);  // A6/A7 are analog input only - special case logical comparison
  } else {
    _newReading = !digitalRead(_pin);  // Inverted else a 1 would indicate not pressed.
  }

  // step 2 compare this reading to our last reading - is it different?
  if (_newReading != _lastReading) {
    _lastDebounceTime = millis();  // if things have changed keep refreshing the start timer value
  }

  // step 3 Only if the debounce time has expired
  if (millis() - _lastDebounceTime >= _debounceDelay) {  // update our state only if debounce time has passed
    _state = _newReading;                                // update the state of the object
  }

  if ((_newReading == HIGH) && (_lastReading == LOW)) {  // We will count only button presses (this line is looking for a change)
    _PressCount++;                                       // Increment the Press Counter once when the button is released
  }

  _lastReading = _newReading;  // make these two the same so we can detect a future change
}

bool ButtonClass::isPressed() {
  return _state;
}

bool ButtonClass::isNotPressed() {
  return (!isPressed());  // This will always be the opposite of isPressed()
}

unsigned long ButtonClass::PressCount() {
  return _PressCount;
}
