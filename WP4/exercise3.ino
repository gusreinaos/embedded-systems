// (C) Juan Garcia, Oscar Reina, Jan Manel, group: 19 (2023)
// Work package 4
// Exercise 3 
// Submission code: eRw&9 (provided by your TA-s) 

#include <Adafruit_NeoPixel.h>

//Declare temperature variable in celsius
int celsius = 0;

//Declare led ring object with library
Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, 2, NEO_GRB + NEO_KHZ800);

//Setting up all of the pins used
void setup()
{
  // set up analog pin 0 as input
  pinMode(A0, INPUT);

  // set up digital pins 13 and 6 as output
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);

  // begin the led ring
  strip.begin();
  
  // start serial 
  Serial.begin(9600);
}


void loop()
{
  //Reading the temperature value
  int temperatureValue = analogRead(A0);
  
  
  //Convert the raw voltage reading obtained from the temperature sensor 
  //into a temperature value in degrees Celsius

  // this two lines of code obtain voltage in mV
  float voltage = temperatureValue * 4.68;
  voltage /= 1024.0;
  // this line converts voltage to temperature
  float temperatureC = (voltage - 0.5) * 100;
  
  //Calculating the numLeds that should be lit up according to the temperature measurement 
  float numLeds = (temperatureC * strip.numPixels()) / 85;
  
  // variable used to iterate in upcoming for loop
  int i = 0;
  
  //Setting the color to red (RGB) according to the number of LEDS obtained
  for(i=0; i < numLeds;i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
    //Update the LEDs to show the colors set by previous function call 
    strip.show();
    delay(20);
    
    
   	//In case the number of leds happens to be the maximum we light up the single red LED
    //and activate the speaker
    if(numLeds >= 24) {
    	digitalWrite(6, HIGH);
      	tone(13, 500, 1000);
  	}
    //Once the number of leds is no longer the max, we stop lighting the single LED
    //and deactivate the speaker
    else {
    	digitalWrite(6, LOW);
      	tone(13, 0, 1000);
    }
  } 
  
  //We use this loop in order to set no color to the LEDs that do not need to light up
  for(int j=i; j<strip.numPixels(); j++) {
    	strip.setPixelColor(j, strip.Color(0, 0, 0)); 
  }
  
  //Update the LEDs to show the colors set by previous function call 
  strip.show();
}