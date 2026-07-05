// Pin Definitions
const int buzzerPin = 8;
const int btn1 = 2; 
const int btn2 = 3; 
const int btn3 = 4; 
const int btn4 = 5; 

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
}

void loop() {
  // Read all button states
  bool p1 = (digitalRead(btn1) == LOW);
  bool p2 = (digitalRead(btn2) == LOW);
  bool p3 = (digitalRead(btn3) == LOW);
  bool p4 = (digitalRead(btn4) == LOW);

  // Count how many buttons are actively pressed
  int pressCount = p1 + p2 + p3 + p4;

  if (pressCount >= 2) {
    tone(buzzerPin, 392); // Play Sol for chord substitute
  } 
  else if (pressCount == 1) {
    if (p1) tone(buzzerPin, 262);      // Do
    else if (p2) tone(buzzerPin, 294); // Re
    else if (p3) tone(buzzerPin, 330); // Mi
    else if (p4) tone(buzzerPin, 349); // Fa
  } 
  else {
    noTone(buzzerPin);
  }
}