<div align="center">

# GawiButtons

GawiButtons is a lightweight Arduino library with debounced button handling. It provides a central manager for multiple buttons.

</div>

## Features
* Debounce handling with configurable timing.
* Press and hold detection.
* ButtonManager for centralized updates.
* Optional pull-up support.
* Logical pin. Takes pointer to bool as input.

## Installation
1. Search for GawiButtons in the Arduino IDE library manager.
2. Choose latest release.
3. Click "install".
* Coming soon.
### Manual installation
1. Download the .zip from GitHub.
2. In the Arduino IDE -> Sketch -> Include Library -> Add .zip library or add GawiButtons to `Documents/Arduino/libraries`
3. Include in project: `#include <GawiButtons.h>`

## Setup

1. Create manager object to control the buttons:
```cpp
ButtonManager buttonManager;
```

2. Create Button object. `addButton()` dynamically creates a button within the ButtonManager object. The function returns a pointer to the new Button object.
```cpp
Button* buttonBuiltIn;
buttonBuiltIn = buttonManager.addButton(9);
```

## Usage

1. Manager updates all registered buttons:
```cpp
buttonManager.updateAll();
```

2. Button states logic:
```cpp
if (buttonBuiltIn->wasPressed()) {
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