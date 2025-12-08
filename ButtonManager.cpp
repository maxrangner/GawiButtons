#include "ButtonManager.h"

ButtonManager::ButtonManager() : numButtons(0) {}

uint8_t ButtonManager::getNumButtons() const {
  return numButtons;
}

Button* ButtonManager::addButton(uint8_t pin, bool hasPullup, uint16_t setDebounce, unsigned long holdTime) {
  m_activeButtons.emplace_back(std::make_unique<Button>(pin, hasPullup, setDebounce, holdTime));
  Serial.println("Button added.");
  this->numButtons++;
  return m_activeButtons.back().get();
}

Button* ButtonManager::addButton(bool *input, bool hasPullup, unsigned long holdTime) {
  m_activeButtons.emplace_back(std::make_unique<Button>(input, hasPullup, holdTime));
  Serial.println("Button added.");
  this->numButtons++;
  return m_activeButtons.back().get();
}

void ButtonManager::updateAll() {
  for (auto& b : m_activeButtons) {
    b->update();
  }
}

