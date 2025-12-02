#pragma once
#include "Arduino.h"
#include <vector>
#include <memory>
#include "Button.h"

class ButtonManager {
  std::vector<std::unique_ptr<Button>> m_activeButtons;
  uint8_t numButtons;
public:
  ButtonManager();
  uint8_t getNumButtons() const;
  Button* addButton(uint8_t pin);
  Button* addButton(uint8_t pin, bool hasPullup);
  Button* addButton(uint8_t pin, bool hasPullup, uint16_t setDebounce);
  Button* addButton(uint8_t pin, bool hasPullup, uint16_t setDebounce, unsigned long holdTime);
  void updateAll();
};