#include <Arduino.h>

const int led1 = 2; // Pin of the LED

void toggleLED(void * parameter) {
  while(1) {
    digitalWrite(led1, HIGH);
    Serial.println("Turning on LED");
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led1, LOW);
    Serial.println("Turning off LED");
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void setup() {
  pinMode(led1, OUTPUT);
  xTaskCreate(
    toggleLED,    // Function that should be called
    "Toggle LED",   // Name of the task (for debugging)
    1000,            // Stack size (bytes)
    NULL,            // Parameter to pass
    1,               // Task priority
    NULL             // Task handle
  );
}

void loop() {
}
