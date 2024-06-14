// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 3
// Exercise 3.2.2 
// Submission code: Tyu-78F (provided by your TA-s) 
// declare initial state for temperature sensor value
int tempSensorValue = 0;

// declare periodicity for program delay
int periodicity = 500;


void setup() {
  
  // declare component pins and modes
  
  // declare temperature sensor
  pinMode (A0, INPUT);
  
  // allow serial to print
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  
  
  // read temperature value
  int temperatureSensor = analogRead(A0);
  
  // calculate voltage, 5.01 is a constant to pass it to Volts and 1024 is the value range 
  float voltage = temperatureSensor * 5.01 / 1024.0;
  // then we multiply by 1000 to get it in Mv
  voltage = voltage * 1000;
  
  //calculate temperature based on exercise requested formula
  float tempFormula = (voltage - 500) / 10;
  
  // print temperature and voltage
  Serial.print(voltage);
  Serial.println(" mv");  
  Serial.print(tempFormula);
  Serial.println(" formulated degrees C");  
  
  
  // delay program based on periodicity variable
  delay(periodicity);  
  
}