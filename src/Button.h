#pragma once
#include <Arduino.h>

class Button {
  // BUTTON
  uint8_t _pin;
  bool* _inputPtr;
  bool _hasPullup;
  bool _buttonState;
  bool _prevButtonState;
  // DEBOUNCE
  unsigned long _now;
  unsigned long _debounceTiming;
  unsigned long _nextDebounce;
  // LOGIC
  bool _activeState;
  bool _inactiveState;
  unsigned long _holdThreashold;
  unsigned long _buttonHeldTimer;
  bool _pushedFlag;
  bool _heldFlag;
public:
  // CONSTRUCTORS
  Button(uint8_t buttonPin, bool hasPullup, unsigned long setDebounce, unsigned long holdTime);
  Button(bool *input, bool hasPullup, unsigned long holdTime);
  // CORE
  void init();
  bool getButtonState();
  bool isDebounced();
  void update();
  bool pressed();
  bool held();
};

