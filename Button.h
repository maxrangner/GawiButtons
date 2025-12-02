#pragma once
#include <Arduino.h>

class Button {
  // BUTTON
  uint8_t pin;
  bool* inputPtr;
  bool buttonState;
  bool prevButtonState;
  // DEBOUNCE
  unsigned long now;
  unsigned long debounceTiming;
  unsigned long nextDebounce;
  // LOGIC
  bool activeState;
  bool inactiveState;
  unsigned long holdThreashold;
  unsigned long buttonHeldTimer;
  bool pushedFlag;
  bool heldFlag;
public:
  // CONSTRUCTORS
  Button(uint8_t buttonPin, bool hasPullup = false, unsigned long setDebounce = 50, unsigned long holdTime = 300);
  Button(bool *input, bool hasPullup = false, unsigned long setDebounce = 50, unsigned long holdTime = 300);
  // DEFAULTS
  static constexpr unsigned long DefaultDebounce = 50;
  static constexpr unsigned long DefaultHold = 300;
  static constexpr bool DefaultPullup = false;
  // CORE
  bool getButtonState();
  bool isDebounced();
  void update();
  bool wasPressed();
  bool wasHeld();
};

