// Pin Definitions
const int buzzerPin = 8;
const int btn1 = 2;
const int btn2 = 3;
const int btn3 = 4;
const int btn4 = 5;
const int modeBtn = 6; // 5th button for toggle

// State Tracking
bool isMinor = false;
int lastModeState = HIGH;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
  pinMode(modeBtn, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // 1. Handle Mode Toggle Button (with debouncing)
  int currentModeState = digitalRead(modeBtn);
  if (lastModeState == HIGH && currentModeState == LOW) {
    isMinor = !isMinor; // Flip the scale mode
    Serial.println(isMinor ? "Scale: MINOR" : "Scale: MAJOR");
    delay(50); // Basic debounce delay
  }
  lastModeState = currentModeState;

  // 2. Read Piano Keys
  bool p1 = (digitalRead(btn1) == LOW);
  bool p2 = (digitalRead(btn2) == LOW);
  bool p3 = (digitalRead(btn3) == LOW);
  bool p4 = (digitalRead(btn4) == LOW);

  int pressCount = p1 + p2 + p3 + p4;

  // 3. Play Tones
  if (pressCount >= 2) {
    tone(buzzerPin, 392); // Sol 
  } 
  else if (pressCount == 1) {
    if (p1) tone(buzzerPin, 262); // Do
    else if (p2) tone(buzzerPin, 294); // Re
    // Switch Mi frequency based on scale mode
    else if (p3) tone(buzzerPin, isMinor ? 311 : 330); // Minor(Eb) vs Major(E)
    else if (p4) tone(buzzerPin, 349); // Fa
  } 
  else {
    noTone(buzzerPin);
  }
}