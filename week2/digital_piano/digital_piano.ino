// Pin Definitions
const int buzzerPin = 8;
const int btn1 = 2; // Do
const int btn2 = 3; // Re
const int btn3 = 4; // Mi
const int btn4 = 5; // Fa

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
}

void loop() {
  // Check which button is pressed (LOW means pressed)
  if (digitalRead(btn1) == LOW) tone(buzzerPin, 262);      // Do
  else if (digitalRead(btn2) == LOW) tone(buzzerPin, 294); // Re
  else if (digitalRead(btn3) == LOW) tone(buzzerPin, 330); // Mi
  else if (digitalRead(btn4) == LOW) tone(buzzerPin, 349); // Fa
  else noTone(buzzerPin);                                  // Silence if none pressed
}