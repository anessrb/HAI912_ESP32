// src/sensor/Temperature.h
#pragma once
#include <Arduino.h>

class Temperature {
private:
    const int pin;
    const int numSamples;
    float lastReading;
    
    float convertToTemperature(float rawValue) const;
    
public:
    Temperature(int pin, int numSamples = SAMPLE_COUNT);
    float read();
    float getLastReading() const;
    bool isValid(float reading) const;
    String toJson() const;
};