#include "Button.h"

Button::Button(uint8_t buttonPin, bool hasPullup, unsigned long setDebounce, unsigned long holdTime)
  : _pin(buttonPin), _inputPtr(nullptr), _hasPullup(hasPullup), _debounceTiming(setDebounce), _holdThreashold(holdTime) {

  // BUTTON INITIALIZATION
  if (_hasPullup) pinMode(_pin, INPUT_PULLUP);
  else pinMode(_pin, INPUT);
  _buttonState = digitalRead(_pin);
  this->init();
}

Button::Button(bool *input, bool hasPullup, unsigned long holdTime)
  : _pin(0), _inputPtr(input), _hasPullup(hasPullup), _holdThreashold(holdTime), _debounceTiming(0) {
    _buttonState = *_inputPtr;
    this->init();
  }

void Button::init() {
  // LOGIC
  _activeState = (_hasPullup) ? LOW : HIGH;
  _inactiveState = !_activeState;
  _prevButtonState = _buttonState;
  _now = millis();
  _nextDebounce = 0;
  _buttonHeldTimer = 0;
  _pushedFlag = false;
  _heldFlag = false;
  _releasedFlag = false;
}

bool Button::getButtonState() {
  if (_inputPtr == nullptr) _buttonState = digitalRead(_pin);
  else _buttonState = *_inputPtr;
  return _buttonState;
}

bool Button::isDebounced() {
  if (_buttonState != _prevButtonState) {
    if (_now >= _nextDebounce) {
      _nextDebounce = _now + _debounceTiming;
      return true;
    }
  }
  return false;
}

void Button::update() {
  _pushedFlag = false;
  _heldFlag = false;
  _releasedFlag = false;
  _now = millis();
  _buttonState = getButtonState();
  if (isDebounced()) {
    if (_buttonState == _activeState && _prevButtonState == _inactiveState) _buttonHeldTimer = _now;
    if (_buttonState == _inactiveState && _prevButtonState == _activeState) {
      _releasedFlag = true;
      if (_now - _buttonHeldTimer >= _holdThreashold) _heldFlag = true;
      else _pushedFlag = true;
    }
  }
  _prevButtonState = _buttonState;
}

bool Button::pressed() {
  return _pushedFlag;
}

bool Button::held() {
  return _heldFlag;
}

bool Button::released() {
  return _releasedFlag;
}
