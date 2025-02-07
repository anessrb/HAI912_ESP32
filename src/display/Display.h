#pragma once
#include <TFT_eSPI.h>

class Display {
private:
    TFT_eSPI& tft;
    
public:
    Display(TFT_eSPI& tft);
    void init();
    void clear();
    void showSensorData(float temp, int light, bool ledState, const String& mode);
    void showMessage(const String& message);
    void showIP(const String& ip);
};
