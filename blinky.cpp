#include <Arduino.h>

// Use only core 1 for demo purposes
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

// Pins
#define LED_BUILTIN 2
static const int led_pin = LED_BUILTIN;

// Our task: blink an LED
void toggleLED(void* parameter);
void setup();
void loop();
void toggleLED(void* parameter) {
  const unsigned int delay = (unsigned int) parameter;
  while(1) {
    digitalWrite(led_pin, HIGH);
    vTaskDelay(delay / portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(delay / portTICK_PERIOD_MS);
  }
}



void setup() {
  // Configure pin
  pinMode(led_pin, OUTPUT);

  // Task to run forever
  xTaskCreatePinnedToCore( // Use xTaskCreate() in vanilla FreeRTOS
      toggleLED,           // Pointer to task function
      "Toggle LED",        // Name of task
      1024,                // Stack size (words in vanilla FreeRTOS, but here in ESP32, it's bytes)
      (void*) 200,         // Parameter to pass to function
      1,                   // Task priority (0 to configMAX_PRIORITIES - 1)
      NULL,                // Task handle (I guess it would be the address to some task-handling struct
      app_cpu);            // CPU to run in
}

void loop() {
  // put your main code here, to run repeatedly:

}

