#include "Button.h"

Button::Button(uint8_t buttonPin, bool hasPullup, unsigned long setDebounce, unsigned long holdTime)
  : pin(buttonPin), inputPtr(nullptr), debounceTiming(setDebounce), holdThreashold(holdTime) {

  // BUTTON INITIALIZATION
  if (hasPullup) pinMode(pin, INPUT_PULLUP);
  else pinMode(pin, INPUT);

  // LOGIC
  activeState = (hasPullup) ? LOW : HIGH;
  inactiveState = !activeState;

  // SET STATES
  buttonState = digitalRead(pin);
  prevButtonState = buttonState;

  // DEBOUNCE
  now = millis();
  nextDebounce = 0;

  // FLAGS
  buttonHeldTimer = 0;
  pushedFlag = false;
  heldFlag = false;
}

Button::Button(bool *input, bool hasPullup, unsigned long setDebounce, unsigned long holdTime)
  : pin(0), inputPtr(input), debounceTiming(setDebounce), holdThreashold(holdTime) {

  // LOGIC
  activeState = (hasPullup) ? LOW : HIGH;
  inactiveState = !activeState;

  // SET STATES
  buttonState = *inputPtr;
  prevButtonState = buttonState;

  // DEBOUNCE
  now = millis();
  nextDebounce = 0;

  // FLAGS
  buttonHeldTimer = 0;
  pushedFlag = false;
  heldFlag = false;
}

bool Button::getButtonState() {
  if (inputPtr == nullptr) buttonState = digitalRead(pin);
  else buttonState = *inputPtr;
  return buttonState;
}

bool Button::isDebounced() {
  if (buttonState != prevButtonState) {
    if (now >= nextDebounce) {
      nextDebounce = now + debounceTiming;
      return true;
    }
  }
  return false;
}

void Button::update() {
  pushedFlag = false;
  heldFlag = false;
  now = millis();
  buttonState = getButtonState();
  if (isDebounced()) {
    if (buttonState == activeState && prevButtonState == inactiveState) buttonHeldTimer = now;
    if (buttonState == inactiveState && prevButtonState == activeState) {
      if (now - buttonHeldTimer >= holdThreashold) heldFlag = true;
      else pushedFlag = true;
    }
  }
  prevButtonState = buttonState;
}

bool Button::wasPressed() {
  return pushedFlag;
}

bool Button::wasHeld() {
  return heldFlag;
}
