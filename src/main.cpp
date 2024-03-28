#include <Arduino.h>

#include <ESP8266WiFi.h>

WiFiServer server(8080);

void setup() {
    Serial.begin(9600);
    WiFi.begin("SSID", "password");
    while(!WiFi.isConnected()) {delay(10);};
    Serial.println(WiFi.localIP());
    server.begin();
}

void loop() {
    WiFiClient client = server.accept();
    if(client) {
        while(client.connected()) {
            if(client.available()) {
                String str = client.readString();
                Serial.println(str);
                delay(100);
            }
        }
    }
}