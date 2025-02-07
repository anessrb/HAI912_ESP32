
#include "Led.h"

Led::Led(int pin) : pin(pin), state(false) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void Led::toggle() {
    state = !state;
    digitalWrite(pin, state ? HIGH : LOW);
}

void Led::setState(bool newState) {
    state = newState;
    digitalWrite(pin, state ? HIGH : LOW);
}

bool Led::getState() const {
    return state;
}

String Led::toJson() const {
    return "{\"state\":\"" + String(state ? "ON" : "OFF") + "\"}";
}
