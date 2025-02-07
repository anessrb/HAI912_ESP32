#pragma once
#include <Arduino.h>

class Led {
private:
    const int pin;
    bool state;
    
public:
    Led(int pin);
    void toggle();
    void setState(bool newState);
    bool getState() const;
    String toJson() const;
};
