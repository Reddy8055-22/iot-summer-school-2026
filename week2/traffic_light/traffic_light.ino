// Pin Definitions
const int buttonPin = 7;
const int redPin = 10;
const int yellowPin = 9;
const int greenPin = 8;

// Time Tracking Variables
unsigned long previousMillis = 0;
int currentState = 0; // 0 = Red, 1 = Yellow, 2 = Green, 3 = Pedestrian Red
// Timing constants (milliseconds)
const unsigned long RED_TIME = 5000;
const unsigned long YELLOW_TIME = 2000;
const unsigned long GREEN_TIME = 4000;
const unsigned long PED_TIME = 8000;

// Button debouncing and state
const unsigned long debounceDelay = 50; // ms
int lastButtonState = HIGH; // pull-up: HIGH when not pressed
int buttonState = HIGH;
unsigned long lastDebounceTime = 0;
bool buttonPressed = false;
bool waitingForRelease = false;

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
  // Initialize timer so the first delay counts from now
  previousMillis = millis();
}

void loop() {
  unsigned long currentMillis = millis();

  // 1. Check for Pedestrian Button Press
  // Debounce the button input
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = currentMillis;
  }

  if (currentMillis - lastDebounceTime > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      // Button pressed (active LOW)
      if (buttonState == LOW) {
        buttonPressed = true;
      }
    }
  }
  lastButtonState = reading;

  // If button was pressed, only honor it when we're in GREEN state.
  // Also avoid retriggering until the user releases the button.
  if (buttonPressed && !waitingForRelease && currentState == 2) {
    currentState = 3;             // Switch to Pedestrian State
    setLight(3);                  // Update LEDs and Serial
    previousMillis = currentMillis; // Reset the timer
    waitingForRelease = true;
    buttonPressed = false;
  }
  // Clear waiting flag when button is released
  if (waitingForRelease && buttonState == HIGH) {
    waitingForRelease = false;
  }

  // 2. State Machine for Standard Light Sequence
    // RED Light
    if (currentState == 0 && currentMillis - previousMillis >= RED_TIME) {
      currentState = 1;
      setLight(1);
      previousMillis = currentMillis;
    } 
    // YELLOW Light
    else if (currentState == 1 && currentMillis - previousMillis >= YELLOW_TIME) {
      currentState = 2;
      setLight(2);
      previousMillis = currentMillis;
    } 
    // GREEN Light
    else if (currentState == 2 && currentMillis - previousMillis >= GREEN_TIME) {
      currentState = 0;
      setLight(0);
      previousMillis = currentMillis;
    } 
    // PEDESTRIAN RED Light (then restart sequence)
    else if (currentState == 3 && currentMillis - previousMillis >= PED_TIME) {
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