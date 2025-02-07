// src/api/ApiServer.cpp
#include "ApiServer.h"

ApiServer::ApiServer(int port, Temperature& temp, Light& light, Led& led)
    : server(port), temp(temp), light(light), led(led), mode("temp") {
    setupRoutes();
}

void ApiServer::setupRoutes() {
    server.on("/", HTTP_GET, [this]() { handleRoot(); });
    server.on("/data", HTTP_GET, [this]() { handleData(); });
    server.on("/led/toggle", HTTP_GET, [this]() { handleToggleLed(); });
    server.on("/mode", HTTP_GET, [this]() { handleSetMode(); });
}

void ApiServer::handleRoot() {
    String html = "<html><body style='font-family: Arial'>";
    html += "<h1>Controle des Capteurs</h1>";
    html += "<p>Temperature: " + String(temp.getLastReading(), 1) + " C</p>";
    html += "<p>Luminosite: " + String(light.getLastReading()) + "</p>";
    html += "<p>LED: " + String(led.getState() ? "ON" : "OFF") + "</p>";
    html += "<p>Mode: " + mode + "</p>";
    html += "<a href='/led/toggle'>Toggle LED</a><br>";
    html += "<a href='/mode?mode=temp'>Mode Temperature</a> | ";
    html += "<a href='/mode?mode=light'>Mode Lumiere</a>";
    html += "</body></html>";
    server.send(200, "text/html", html);
}

void ApiServer::handleData() {
    String json = "{";
    json += "\"temperature\":" + String(temp.getLastReading(), 1) + ",";
    json += "\"luminosity\":" + String(light.getLastReading()) + ",";
    json += "\"led\":" + String(led.getState() ? "true" : "false") + ",";
    json += "\"mode\":\"" + mode + "\"";
    json += "}";
    
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "application/json", json);
}

void ApiServer::handleToggleLed() {
    led.toggle();
    server.send(200, "application/json", led.toJson());
}

void ApiServer::handleSetMode() {
    if (server.hasArg("mode")) {
        String newMode = server.arg("mode");
        if (newMode == "temp" || newMode == "light") {
            mode = newMode;
            server.send(200, "text/plain", "Mode set to: " + mode);
        } else {
            server.send(400, "text/plain", "Invalid mode");
        }
    } else {
        server.send(400, "text/plain", "Mode parameter missing");
    }
}

void ApiServer::begin() {
    server.begin();
}

void ApiServer::handle() {
    server.handleClient();
}

String ApiServer::getMode() const {
    return mode;
}
