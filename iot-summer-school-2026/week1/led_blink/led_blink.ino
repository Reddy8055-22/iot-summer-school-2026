//use this program in Arduino IDE compiler for blinking the LED using arduino board
void setup() {
  // Initialize digital pin 13 as an output.
  pinMode(13, OUTPUT ) ;

}

void loop() {
  digitalWrite( 13 ,HIGH ) ;   // Turn the LED on
  delay(1000) ;              // Wait for a second (1000 milliseconds)
  digitalWrite(13, LOW) ;   // Turn the LED off
  delay(1000) ;              // Wait for a second
}