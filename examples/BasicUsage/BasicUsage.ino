#include "Button.h"
#include "ButtonManager.h"

ButtonManager buttonManager; // Create manager object to controll the buttons
Button* buttonBuiltIn; // Create Button pointer
Button* logicalButton;

constexpr uint8_t ledPin = 8;
bool stateLED = false;
bool logicalPin = false;

void setup() {
  Serial.begin(9600);
  delay(1500);

  buttonBuiltIn = buttonManager.addButton(9, true); // Create Button object (uint8_t buttonPin, unsigned long setDebounce = 50, unsigned long holdTime = 300, bool hasPullup = false)
  logicalButton = buttonManager.addButton(&logicalPin, false, 300); // Create logical Button object (bool *input, bool hasPullup, unsigned long holdTime)

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  Serial.println("BOOT! ");
  Serial.print(buttonManager.getNumButtons()); // Getter returns number of created Button objects
  Serial.println(" buttons found.");
}

void loop() {
  ////Logic pin test:
  // in = false;
  // delay(50);
  // buttonManager.updateAll();
  // in = true;
  // delay(50);
  // buttonManager.updateAll();
  // in = false;
  // delay(300);
  // buttonManager.updateAll();


  // if (virtualButton->pressed()) Serial.println("PRESSED");
  // if (virtualButton->held())    Serial.println("HELD");

  // delay(1000);
  // Pressed logic:
  if (buttonBuiltIn->pressed()) {
    digitalWrite(8, stateLED);
    stateLED = !stateLED;
    Serial.println("Button was pressed.");
  }

  // Held logic:
  if (buttonBuiltIn->held()) {
    Serial.println("Button was held.");
  }
}
