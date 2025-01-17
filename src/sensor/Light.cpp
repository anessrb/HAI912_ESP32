// src/sensor/Light.cpp
#include "Light.h"

Light::Light(int pin, int numSamples) 
    : pin(pin), numSamples(numSamples), lastReading(0) {
    pinMode(pin, INPUT);
}

int Light::read() {
    long total = 0;
    for(int i = 0; i < numSamples; i++) {
        total += analogRead(pin);
        delay(5);
    }
    
    lastReading = total / numSamples;
    return lastReading;
}

bool Light::isValid(int reading) const {
    return reading >= MIN_VALID_LIGHT && reading <= MAX_VALID_LIGHT;
}

String Light::toJson() const {
    return "{\"luminosity\":" + String(lastReading) + "}";
}