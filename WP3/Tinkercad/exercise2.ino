// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 3
// Exercise 3.2 This is the combined one (multimeter, temperature sensor, photosensor and 3 LEDs)
// Submission code: Tyu-78F (provided by your TA-s) 

// declare light and temperature sensor states
int lightSensorValue = 0;
int tempSensorValue = 0;

//declare LED Pins
int LED1 = 9;
int LED2 = 10;
int LED3 = 11;

// declare periodicity
int periodicity = 100;


void setup() {
  
  // declare component pins and modes
  
  // declare photoresistor
  pinMode (A0, INPUT);
  
  // declare temperature sensor
  pinMode (A1, INPUT);
  
  // declare LEDs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  // allow serial to print
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  
  // read photoresistor value
  lightSensorValue = analogRead(A0);
  // writes photoresistor value which goes from 0 to 1023
  // to a percentage value 0 - 100
  int lightIntensity = map(lightSensorValue, 0, 1023, 0, 100);
  
  
  // read temperature value
  // read temperature value
  int temperatureSensor = analogRead(A1);
  
  // calculate voltage 
  float voltage = temperatureSensor * 5.01 / 1024.0;
  voltage = voltage * 1000;
  
  //calculate temperature
  float temperature = (voltage - 500) / 10;
  
  // print temperature, light intensity value and volts
  Serial.print(temperature);
  Serial.println(" degrees C");
  Serial.print(lightIntensity);
  Serial.println(" light %");
  Serial.print(voltage);
  Serial.println(" mv");  
  
  
  
  // calculate relationship between temperature and light
  
  // i define ranges to values 1,2,3 or 4 depending on the table 
  // of the exercise description
  
  // temperature ranges
  // t <= 12 degrees celsius  -> range = 1
  // 12 degrees celsius < t <= 0 degrees celsius  -> range = 2
  // 0 degrees celsius < t <= 20 degrees celsius  -> range = 3
  // t > 20 degrees celsius  -> range = 4
  
  int tempRange = 0;
  if (temperature <= - 12){
    tempRange = 1;
  } else if (temperature > -12 && temperature <= 0){
    tempRange = 2;
  } else if (temperature > 0 && temperature <= 20){
    tempRange = 3;
  } else if (temperature > 20){
    tempRange = 4;
  }
  
  // light intensity % ranges
  // % = 0  -> range = 1
  //  1 < % < 20  -> range = 2
  //  20 < % < 60  -> range = 3
  //  60 < %   -> range = 4
  
  int lightRange = 0;
  if (lightIntensity < 1){
    lightRange = 1;
  } else if (lightIntensity > 0 && lightIntensity <= 20){
    lightRange = 2;
  } else if (lightIntensity > 20 && lightIntensity <= 60){
    lightRange = 3;
  } else if (lightIntensity > 60){
    lightRange = 4;
  }
    
  //  turn correct LED on and turn others off based on exercise specification 
  if (lightRange == tempRange){
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
  } else if (lightRange > tempRange){
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
  } else if (lightRange < tempRange){
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
  }

  // short delay 
  delay(periodicity);  
  
}