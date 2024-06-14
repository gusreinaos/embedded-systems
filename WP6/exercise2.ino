// (C) Juan Garcia, Oscar Reina, Jan Manel, group: 19 (2023)
// Work package 6
// Exercise 2
// Submission code: ZZZ19ZZZ  (provided by your TA-s)

//declare constants with the pins

//Declaration of pins used by the ultrasonic sensor
const int echo = 13;
const int trig = 12;

//Declaration of pins used by the 4 red LEDs
const int LED1=7;
const int LED2=6;
const int LED3=5;
const int LED4=4;

//Declaration of pin used by the piezo (speaker)
const int buzzer=10;

//Declaration of duration and distance variables which will be updated afterwards with the accurate measurements
int duration = 0;
int distance = 0;

//Factor by which we divide the raw output from the ultrasonic sensor in order to get the measurement in cm
//The conversion factor of 58.2 is used to convert the speed of sound in air from meters per second to centimeters per microsecond, which allows us to directly convert the time in microseconds to distance in centimeters
float conversion_factor = 58.2;

void setup() {
  //Set the ultrasonic output port (emitting the wave)
  pinMode(trig, OUTPUT);
  //Set the ultrasonic input port (receiving the wave)
  pinMode(echo, INPUT);

  //Set leds with pins as output
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  Serial.begin(9600);
}

void ultrasonicDistance() {
  digitalWrite(trig, HIGH);
  //Small delay of 1000 microseconds (1 millisecond) to allow time for the trigger signal to reach the sensor and for it to emit the sound wave.
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);

  //Used to measure the duration of a pulse on the ping
  duration = pulseIn(echo, HIGH);
  distance = (duration / conversion_factor);
}

void turnOffAll() {
  //Turning off both buzzer and LEDs
  noTone(buzzer);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
}

void setBuzzerAndLED(int buzzerFrequency, int ledNumber) {
  digitalWrite(ledNumber, HIGH);
  tone(buzzer, buzzerFrequency);
}

void loop(){
  //Set buzzer and LEDS LOW in order to avoid them from activating constantly.
  turnOffAll();
  ultrasonicDistance();
  
  //if distance is > 200 buzzer and LEDs are set to off as nothing is detected
  if(distance >200){
      turnOffAll();
  }
  //If the distance is < 200 we set the buzzer to a frequency of 10 and LED1 to HIGH
  if(distance < 200){
    setBuzzerAndLED(10, LED1);
  }

  //If the distance is < 130 we set the buzzer to a frequency of 40 and LED2 to HIGH (being LED1 already to HIGH)
  if(distance < 130){
    setBuzzerAndLED(40, LED2);
  }

  //If the distance is < 70 we set the buzzer to a frequency of 70 and LED3 to HIGH (being LED1 and LED2 already to HIGH)
  if (distance<70){
    setBuzzerAndLED(70, LED3);
  }
  
  //If the distance is < 30 we set the buzzer to a frequency of 150 and LED 4 to HIGH (being LED1, LED2 and LED3 already to HIGH)
  if (distance<30){
    setBuzzerAndLED(150, LED4);
  }

  //If the distance is < 25 we enable the blinking of LEDs
  if(distance < 25){
    // Turn LEDs to HIGH and buzzer to a higher tone in order to enable the blinking
    setBuzzerAndLED(0, LED1);
    setBuzzerAndLED(0, LED2);
    setBuzzerAndLED(0, LED3);
    setBuzzerAndLED(0, LED4);
    // Delay for blink
    delay(500);
    // Turn LEDs to LOW and buzzer to have no tone
    turnOffAll();
  }