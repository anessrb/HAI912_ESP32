// src/main.cpp
#include <Arduino.h>
#include "config.h"
#include "sensor/Temperature.h"
#include "sensor/Light.h"
#include "actuator/Led.h"
#include "display/Display.h"
#include "api/ApiServer.h"

Temperature tempSensor(TEMP_PIN);
Light lightSensor(LIGHT_PIN);
Led led(LED_PIN);
TFT_eSPI tft;
Display display(tft);
ApiServer api(SERVER_PORT, tempSensor, lightSensor, led);

void setup() {
    Serial.begin(115200);
    display.init();
    
    display.showMessage("Connexion WiFi...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        display.showMessage(".");
    }
    
    api.begin();
    display.clear();
    display.showMessage("Connecte!");
    display.showIP(WiFi.localIP().toString());
}

void loop() {
    api.handle();
    
    float temp = tempSensor.read();
    int light = lightSensor.read();
    
    if (api.getMode() == "temp") {
        if (temp >= 25 && !led.getState()) {
            led.setState(true);
        } else if (temp < 25 && led.getState()) {
            led.setState(false);
        }
    } else {
        if (light >= 1000 && !led.getState()) {
            led.setState(true);
        } else if (light < 1000 && led.getState()) {
            led.setState(false);
        }
    }
    
    display.showSensorData(temp, light, led.getState(), api.getMode());
    delay(1000);
}