<div align="center">

# GawiButtons

GawiButtons is a lightweight Arduino library with debounced button handling. It provides a central manager for multiple buttons.

</div>

## Features
* Debounce handling with configurable timing.
* Press and hold detection.
* ButtonManager for centralized updates.
* Optional pull-up support.
* Support for logical pin, driven by a logical bool instead of GPIO.

## Installation
1. Search for GawiButtons in the Arduino IDE library manager.
2. Choose latest release.
3. Click "install".

### Manual installation
1. Download the .zip from GitHub.
2. In the Arduino IDE -> Sketch -> Include Library -> Add .zip library or add GawiButtons to `Documents/Arduino/libraries`
3. Include in project: `#include <GawiButtons.h>`

## Setup

1. Create manager object to control the buttons:
```cpp
ButtonManager buttonManager;
```

2. Create Button object. `addButton()` returns a pointer to a new Button object managed by the ButtonManager.
```cpp
Button* buttonBuiltIn;
buttonBuiltIn = buttonManager.addButton(9);
```

or

2. Create Button object with a purely logical input.
```cpp
bool logicalPin;
Button* buttonLogical;
buttonLogical = buttonManager.addButton(&logicalPin);
```

## Usage

1. Manager updates all registered buttons:
```cpp
buttonManager.updateAll();
```

2. Button states logic:
```cpp
if (buttonBuiltIn->wasPushed()) {
    Serial.println("Button was pressed.");
}

if (buttonBuiltIn->wasHeld()) {
    Serial.println("Button was held.");
}
```

## Additional functions

* Get number of added buttons:
```cpp
buttonManager.getNumButtons(); // Returns a uint8_t
```