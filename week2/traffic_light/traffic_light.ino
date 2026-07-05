// Pin Definitions
const int buttonPin = 7;
const int redPin = 10;
const int yellowPin = 9;
const int greenPin = 8;

// Time Tracking Variables
unsigned long previousMillis = 0;
int currentState = 0; // 0 = Red, 1 = Yellow, 2 = Green, 3 = Pedestrian Red

void setup() {
  // Configure LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  // Configure button pin with internal pull-up resistor (Reads LOW when pressed)
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Initialize Serial Monitor
  Serial.begin(9600);
  
  // Start the sequence with the Red light
  setLight(0); 
}

void loop() {
  unsigned long currentMillis = millis();

  // 1. Check for Pedestrian Button Press
  // If button is pressed (LOW) and we aren't already in Pedestrian Mode
  if (digitalRead(buttonPin) == LOW && currentState != 3) {
     currentState = 3;             // Switch to Pedestrian State
     setLight(3);                  // Update LEDs and Serial
     previousMillis = currentMillis; // Reset the timer
  }

  // 2. State Machine for Standard Light Sequence
  // RED Light (Hold for 5 seconds)
  if (currentState == 0 && currentMillis - previousMillis >= 5000) {
     currentState = 1;
     setLight(1);
     previousMillis = currentMillis;
  } 
  // YELLOW Light (Hold for 2 seconds)
  else if (currentState == 1 && currentMillis - previousMillis >= 2000) {
     currentState = 2;
     setLight(2);
     previousMillis = currentMillis;
  } 
  // GREEN Light (Hold for 4 seconds)
  else if (currentState == 2 && currentMillis - previousMillis >= 4000) {
     currentState = 0;
     setLight(0);
     previousMillis = currentMillis;
  } 
  // PEDESTRIAN RED Light (Hold for 8 seconds, then restart sequence)
  else if (currentState == 3 && currentMillis - previousMillis >= 8000) {
     currentState = 0; // Returning to standard red to restart the cycle safely
     setLight(0);
     previousMillis = currentMillis;
  }
}

// Function to handle LED switching and Serial Logging
void setLight(int state) {
  // Turn all lights off first
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);

  // Print Timestamp
  Serial.print("Time: ");
  Serial.print(millis());
  Serial.print(" ms | State: ");

  // Turn on the appropriate light and log the state
  if (state == 0) {
    digitalWrite(redPin, HIGH);
    Serial.println("RED ON (Normal Sequence)");
  } else if (state == 1) {
    digitalWrite(yellowPin, HIGH);
    Serial.println("YELLOW ON");
  } else if (state == 2) {
    digitalWrite(greenPin, HIGH);
    Serial.println("GREEN ON");
  } else if (state == 3) {
    digitalWrite(redPin, HIGH);
    Serial.println("RED ON (Pedestrian Override!)");
  }
}