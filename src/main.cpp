#include <Arduino.h>

constexpr uint8_t SOIL_SENSOR_PIN = A0;
constexpr uint8_t ALERT_LED_PIN = 7;
constexpr int DRY_THRESHOLD_PERCENT = 35;
constexpr unsigned long READING_INTERVAL_MS = 1000;

unsigned long lastReadingAt = 0;

void setup() {
  pinMode(ALERT_LED_PIN, OUTPUT);
  digitalWrite(ALERT_LED_PIN, LOW);

  Serial.begin(9600);
  Serial.println(F("Day 12 - Smart Plant Care Monitor"));
  Serial.println(F("Turn the potentiometer to simulate soil moisture."));
}

void loop() {
  const unsigned long now = millis();

  if (now - lastReadingAt < READING_INTERVAL_MS) {
    return;
  }

  lastReadingAt = now;

  const int rawValue = analogRead(SOIL_SENSOR_PIN);
  const int moisturePercent = map(rawValue, 0, 1023, 0, 100);
  const bool soilIsDry = moisturePercent < DRY_THRESHOLD_PERCENT;

  digitalWrite(ALERT_LED_PIN, soilIsDry ? HIGH : LOW);

  Serial.print(F("Raw sensor: "));
  Serial.print(rawValue);
  Serial.print(F(" | Moisture: "));
  Serial.print(moisturePercent);
  Serial.print(F("% | Status: "));
  Serial.println(soilIsDry ? F("DRY - water needed") : F("OK"));
}