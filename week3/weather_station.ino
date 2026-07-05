#include <DHT.h>

// Pin Definitions
const int DHT_PIN = 2;       // DHT11 data pin connected to Digital Pin 2
const int RED_LED = 4;       // Red LED for warning
const int GREEN_LED = 5;     // Green LED for normal conditions

// Initialize DHT sensor (Type: DHT11)
#define DHTTYPE DHT11
DHT dht(DHT_PIN, DHTTYPE);

// Timer variable
unsigned long previousMillis = 0;
const long interval = 2000; // 2 seconds

void setup() {
  Serial.begin(9600);
  
  // Initialize pins
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  // Start the sensor
  dht.begin();
  
  // Print the CSV header to the Serial Monitor
  Serial.println("timestamp,temp_C,temp_F,humidity");
}

void loop() {
  unsigned long currentMillis = millis();

  // Read sensor every 2 seconds
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Read temperature as Celsius (default) and Fahrenheit (isFahrenheit = true)
    float tempC = dht.readTemperature();
    float tempF = dht.readTemperature(true);
    float humidity = dht.readHumidity();

    // Check if any reads failed and exit early (to try again)
    if (isnan(tempC) || isnan(tempF) || isnan(humidity)) {
      Serial.println("Error: Failed to read from DHT sensor!");
      return;
    }

    // Print data in CSV format
    Serial.print(currentMillis);
    Serial.print(",");
    Serial.print(tempC);
    Serial.print(",");
    Serial.print(tempF);
    Serial.print(",");
    Serial.println(humidity);

    // Alert Logic
    if (tempC > 35.0 || humidity > 80.0) {
      // Warning condition
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
    } else {
      // Normal condition
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
    }
  }
}