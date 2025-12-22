#pragma once
#include <Arduino.h>
#include <vector>
#include <memory>
#include "Button.h"

class ButtonManager {
  std::vector<std::unique_ptr<Button>> m_activeButtons;
  uint8_t numButtons;
public:
  ButtonManager();
  uint8_t getNumButtons() const;
  Button* addButton(uint8_t pin, bool hasPullup = false, uint16_t setDebounce = 50, unsigned long holdTime = 300);
  Button* addButton(bool *input, bool hasPullup = false, unsigned long holdTime = 300);
  void updateAll();
};