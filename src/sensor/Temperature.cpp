#include "Temperature.h"

Temperature::Temperature(int pin, int numSamples) 
    : pin(pin), numSamples(numSamples), lastReading(0) {
    pinMode(pin, INPUT);
}

float Temperature::read() {
    long total = 0;
    for(int i = 0; i < numSamples; i++) {
        total += analogRead(pin);
        delay(5);
    }
    
    float average = total / numSamples;
    lastReading = convertToTemperature(average);
    return lastReading;
}

float Temperature::convertToTemperature(float rawValue) const {
    float resistance = (1023.0 / rawValue - 1.0) * 1000;
    return 1.0 / (log(resistance / 1000) / 3950 + 1.0 / 298.15) - 273.15;
}

bool Temperature::isValid(float reading) const {
    return reading >= MIN_VALID_TEMP && reading <= MAX_VALID_TEMP;
}

String Temperature::toJson() const {
    return "{\"temperature\":" + String(lastReading, 1) + "}";
}
