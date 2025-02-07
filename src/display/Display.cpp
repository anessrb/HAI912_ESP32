#include "Display.h"

Display::Display(TFT_eSPI& tft) : tft(tft) {}

void Display::init() {
    tft.init();
    tft.setRotation(1);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(2);
    clear();
}

void Display::clear() {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
}

void Display::showSensorData(float temp, int light, bool ledState, const String& mode) {
    clear();
    tft.println("Temperature: " + String(temp, 1) + " C");
    tft.println("Lumiere: " + String(light));
    tft.println("LED: " + String(ledState ? "ON" : "OFF"));
    tft.println("Mode: " + mode);
}

void Display::showMessage(const String& message) {
    tft.println(message);
}

void Display::showIP(const String& ip) {
    tft.println("IP: " + ip);
}
