// src/api/ApiServer.h
#pragma once
#include <WebServer.h>
#include "../sensor/Temperature.h"
#include "../sensor/Light.h"
#include "../actuator/Led.h"

class ApiServer {
private:
    WebServer server;
    Temperature& temp;
    Light& light;
    Led& led;
    String mode;
    
    void setupRoutes();
    void handleRoot();
    void handleData();
    void handleToggleLed();
    void handleSetMode();
    
public:
    ApiServer(int port, Temperature& temp, Light& light, Led& led);
    void begin();
    void handle();
    String getMode() const;
};
