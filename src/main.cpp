#include <Arduino.h>
#include "camera_config.h"
#include "web_handlers.h"

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32-CAM starting...");

  if (!initCamera()) {
    Serial.println("Camera init failed!");
    return;
  }

  initSD();
  initWiFi();
  initServer();
}

void loop() {
  server.handleClient();
}
