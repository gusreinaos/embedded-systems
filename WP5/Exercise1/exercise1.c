// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 5
// Exercise 1
// Submission code: DrT56_u (provided by your TA-s) 
// declare initial button state
int buttonState = 0;

// Set up function to declare pins
void setup() {
  // declare led as an output
  pinMode(2, INPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
}

// loop function that determines board behaviour
void loop() {
   // call function that blinks led
   blinkingLed();

   // gather button value
   buttonState = digitalRead(2);
   // turn light on or off depending on button value
  if (buttonState == HIGH) {
  	digitalWrite(8,HIGH);
  } else {
  	digitalWrite(8,LOW);
  }
  // short delay
  delay(10); 
}

void blinkingLed(){
  // code for blinking led
  digitalWrite(13, HIGH); // turn the LED on 
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);  // turn the LED off 
  delay(1000);              // wait for a second
}