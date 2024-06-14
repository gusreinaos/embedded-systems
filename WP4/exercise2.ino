// (C) Juan Garcia, Oscar Reina, Jan Manel, group: 19 (2023)
// Work package 4
// Exercise 2
// Submission code: eRw&9 (provided by your TA-s)


//include servo Library
#include <Servo.h>

// declare variable to keep track of seconds, interrups and degrees
int timer = 0;			
int interruptCounter = 0;	
int degreeCounter = 0;		

//Declare a servo object
Servo servo;				


void setup() {
   // method to setup the timer
   setup_timer_2(); 	
   // attach servo object
   servo.attach(7, 0, 360);	
   //begin console
   Serial.begin(9600);	
}

// loop will do nothing since servo will move via interrupts
void loop() {}

// inspired on tutorial:
// https://electronoobs.com/eng_arduino_tut140.php
void setup_timer_2() {
  // stop all interrupts
   cli();			
  
   // set timer 2 value to 0
   TCNT2 = 0;		
  
   // Timer2 (interrupt each 8 ms)
   // interrupt time = 1/(16Mhz/1024) * 125 =  8 ms;
   // Reset TCCR2A and TCCR2B to 0
   TCCR2A = 0;                 
   TCCR2B = 0;    
  
   //Set CS20, CS21 and CS22 to 1 so we get prescalar 1024
   TCCR2B |= B00000111;
  
   //Set OCIE1B to 1 so we enable compare match B
   TIMSK2 |= B00000100;   
   // Set compare register B to this value 
   OCR2B = 125;   
   //Allow interrupts	
   sei();			
}


// The check for 125 interrupts was inspired by the implementation
// of team 1


//This IRS triggers every 8ms
ISR(TIMER2_COMPB_vect){
  
  	// we increase by 1 the counter that keeps track of how 
    // many times this function is called
  	interruptCounter++;		
    //set the timer to 0
	TCNT2 = 0;  	
  
  	// we check if the number of interrupts is a multiple of 125, since
    // 8ms times 125 would equal 1 second
 	if((interruptCounter % 125) == 0){			
      
      // if clock reaches end position, reset it
      if(timer % 180 == 0){				   
        degreeCounter = 0;				
      }
      // print time 
      Serial.print("Time: ");
      Serial.println(timer++);	 
      
      // move servo by 1/60th of 180
      degreeCounter +=6;
      servo.write(degreeCounter);   
	}
}