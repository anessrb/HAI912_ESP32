#pragma once
#include <Arduino.h>

class Light {
private:
    const int pin;
    const int numSamples;
    int lastReading;
    
public:
    Light(int pin, int numSamples = SAMPLE_COUNT);
    int read();
    int getLastReading() const;
    bool isValid(int reading) const;
    String toJson() const;
};
