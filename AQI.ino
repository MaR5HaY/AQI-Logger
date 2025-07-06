#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>

// Pin Definitions
#define DHTPIN 2          // DHT11 sensor pin
#define DHTTYPE DHT11     // DHT11, not DHT22
#define MQ135PIN A0       // MQ135 analog output pin

// Initialize LCD and DHT
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address might be 0x27 or 0x3F
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin();
  lcd.backlight();
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  // Read sensors
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int mq135Value = analogRead(MQ135PIN);  // Raw CO₂/air quality value (0–1023)

  // Display on Serial Monitor
  Serial.print("Temp: "); Serial.print(temperature); Serial.print(" °C | ");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.print(" % | ");
  Serial.print("Air Quality: "); Serial.println(mq135Value);

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C H:");
  lcd.print(humidity, 0);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("AQI: ");
  lcd.print(mq135Value);

  delay(2000);  // Update every 2 seconds
}
