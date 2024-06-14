// (C) Juan Garcia, Oscar Reina, Jan Manel, group: 19 (2023)
// Work package 5
// Exercise 2
// Submission code: DrT56_u (provided by your TA-s)

#define DATA_RATE 9600// Define data rate for Serial

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

// declare LED threshod values
int LED1_Threshold = 13;
int LED2_Threshold = 14;
int LED3_Threshold = 15;
int LED4_Threshold = 16;
int LED5_Threshold = 17;



void setup() {
  
  // declare component pins and modes
  
  // declare temperature sensor
  pinMode (A0, INPUT);
  
  // declare LEDs as output
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  
  Serial.begin(DATA_RATE);// Begin serial
}

// the loop function runs over and over again forever
void loop(){
  delay(1000);

 // read temperature sensor 
  int temperatureSensor = analogRead(A0);
  // transform voltage reading into temperature using
  // online specification formula for sensor LM35
  float temperature = (temperatureSensor*4.88);
  temperature = temperature/20;
  
  // turn on correct LED and turn others off depending on 
  // temperature thresholds

  // If below threshold 1, only light up led 1
  if (temperature <  LED1_Threshold){
    
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
  // If below threshold 2, only light up led 1 and 2
  } else if (temperature <  LED2_Threshold){
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
  // If below threshold 3, only light up led 1, 2 and 3
  } else if (temperature <  LED3_Threshold){
  	digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    // If below threshold 4, only light up led 1, 2, 3 and 4
  } else if (temperature <  LED4_Threshold){
  	digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
  // If below threshold 5, light up all LEDS
  } else if (temperature <  LED5_Threshold){
  	digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
  }
}