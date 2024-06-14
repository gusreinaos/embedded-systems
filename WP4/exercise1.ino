// (C) Juan Garcia, Oscar Reina, Jan Manel, group: 19 (2023)
// Work package 4
// Exercise 1
// Submission code: eRw&9 (provided by your TA-s)

// the following definitions are values to setup timer 1
// these have been taken from the code example provided
// by professor Miroslav Staron
// used in calculation: compare match register = [ clock speed/ (prescaler * interrupt frequency) ] - 1
#define PRESCALER 1024      // used for dictating speed of timer according to (timer speed (Hz)) = (Arduino clock speed (16MHz)) / prescaler
#define INTERRUPT_FREQ 1    // define interrupt frequency
#define CLOCK_SPEED 16000000// Clock speed of the Arduino Uno
#define TIMER1_MAX 65535    // Max counter value for timer1
#define TIMER1_LOW 257      // Lowest counter value for timer1

// declare timer counter
int timer1 = 0;

// declare initial state for temperature sensor
int tempSensorValue = 0;

// declare LED pins
int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int LED5 = 9;

// declare LED threshold values
int LED1_Threshold = 10;
int LED2_Threshold = 25;
int LED3_Threshold = 40;
int LED4_Threshold = 60;
int LED5_Threshold = 128;



void setup() {
  
  // declare component pins and modes
  
  // declare temperature sensor
  pinMode (A0, INPUT);
  
  // declare LEDs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  
  setup_timer_1();        // Setup timer
  Serial.begin(DATA_RATE);// Begin serial
}

// the loop function runs over and over again forever
void loop(){}

// function activated when timer 1 interruption is called
ISR(TIMER1_COMPA_vect){
  
  cli();
  // read temperature value
  int temperatureSensor = analogRead(A0);
  
  // calculate voltage 
  float voltage = temperatureSensor * 5.01 / 1024.0;
  voltage = voltage * 1000;
  
  //calculate temperature
  float temperature = (voltage - 500) / 10;
  
  // turn on correct LED and turn others off depending on 
  // temperature thresholds

  // if temperature is lower than that of threshold for led 1, light LED 1 and turns others off
  if (temperature <  LED1_Threshold){
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
  // if temperature is lower than that of threshold for led 2, light LED 1 and 2 and turns others off
  } else if (temperature <  LED2_Threshold){
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
  // if temperature is lower than that of threshold for led 3, light LED 1 , 2 and 3 and turns others off
  } else if (temperature <  LED3_Threshold){
  	digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
  // if temperature is lower than that of threshold for led 4, light LED 1 , 2 , 3 and 4 and turn 5 off
  } else if (temperature <  LED4_Threshold){
  	digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
  // if temperature is lower than that of threshold for led 5, turn all leds one
  } else if (temperature <  LED5_Threshold){
  	digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
  }
  sei();  
  
}

// timer function
// this code has been taken from the code example provided
// by professor Miroslav Staron
void setup_timer_1() {

   cli();//stop interrupts

   TCCR1A = 0;    // set entire TCCR1A register to 0
   TCCR1B = 0;    // same for TCCR1B
   TCNT1 = 0;     //initialize counter value to 0

   // calculate at which point to stop the counter and set to int:
   timer1 = (CLOCK_SPEED / (PRESCALER * INTERRUPT_FREQ)) - 1;
   //timer1 = (CLOCK_SPEED / (INTERRUPT_FREQ)) - 1;
   // timer1 = 16 000 000 / 65535

   if (timer1 >= TIMER1_MAX) {                                                         // if value went above max value
      timer1 = TIMER1_MAX;                                                             // set timer to max allowed value
      Serial.println((String) "timer1 was set too high and was changed to: " + timer1);// notify user
   } else if (timer1 <= TIMER1_LOW) {                                                  // if value went below lowest value
      timer1 = TIMER1_LOW;                                                             // set timer to max allowed value
      Serial.println((String) "timer1 was set too low and was changed to: " + timer1); // notify user
   }
   
   OCR1A = timer1;                     // set compare match register for 1hz increments
   TCCR1B |= (1 << WGM12);             // turn on CTC mode
   TCCR1B |= (1 << CS12) | (1 << CS10);// set CS10 and CS12 bits for 1024 prescaler
   TIMSK1 |= (1 << OCIE1A);            // enable timer compare interrupt
   sei();//allow interrupts
}