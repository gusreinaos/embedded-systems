// (C) Juan Garcia, Oscar Reina, Jan Manel, group: 19 (2023)
// Work package 6
// Exercise 1
// Submission code: ZZZ19ZZZ  (provided by your TA-s)

// WP 6 Exercise 1 Template DIT 632

// declare pins for encoder
#define ENCA 2
#define ENCB 3
// declare pins for motor driver
#define PWM1 5
#define PWM2 6
 
volatile int pos = 0; // Position in ticks
int deg = 0; // Position in degrees

int degtarget = 0; // Target position in degrees

int speed = 0; // Desired motor speed

int kp = 5; // Proportional constant for controller (tuning parameter)
int u_out = 0; // output of controller

volatile int e = 0; // error
int a = 25; // a-encoder signal
int b = 0; // b-encoder signal

void setup() {
 
  // set up input pins for encoder and motor driver
  Serial.begin(9600);
  pinMode(ENCA,INPUT_PULLUP);
  pinMode(ENCB,INPUT_PULLUP);
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);  
  
  /*
  ==> TO DO TO DO TO DO
  ATTACH INTERRUPT HERE.
  */
  // attach interrupt to encoder A when rising
  attachInterrupt(digitalPinToInterrupt(2), ISR_readEncoder, RISING);

  // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
  analogWrite(PWM2, 10); 
  delay(1000); // TinkerCad bug
  analogWrite(PWM1, 10);
}

void loop() {
  // Stop the motor, but not to zero because then TinkerCad dies....
  analogWrite(PWM1, 10);
  delay(1000); // TinkerCad...bug
  analogWrite(PWM2, 10);
  
  // Check if motor rotated all the way around, and reset counter
    if (pos > 2299){
      deg = deg - 359;
      pos = pos - 2299;
    }
    if (pos < 0){
      deg = 359 + deg;
  	  pos = 2299 + pos;
    }
  
  // Print current position
  Serial.print("The current position is: ");
  Serial.print(deg);
  Serial.print("\n");
  Serial.println(pos);
   
  // Get input 
  degtarget = getInput();
  
  // Calculate initial error
  e = degtarget - deg;
    
  // Loop until error is zero
  while(e){
    //Serial.println(e);
    // Map current position into degrees
    deg = map(pos,0,2299,0,359);
    Serial.print("target is ");
    Serial.print(degtarget);
    Serial.print(" deg is ");
    Serial.print(deg);
    Serial.println();
  	// Get necessary speed signal
  	speed = getAction(e);
    
  	// Send speed signal to motor
    // Rotating clockwise
    if(speed >= 0){
    	if (speed < 100) // motor does not react with too low inputs
      	speed = 100;
      analogWrite(PWM2, 0);
      analogWrite(PWM1, speed);
  	}
  
    // Rotating counter-clockwise
  	else{
    	if (-speed < 100) // motor does not react with too low inputs
      	speed = -100; 
      analogWrite(PWM1, 0);
      analogWrite(PWM2, -speed); 
    }
	
    // Calculate new error
  	e = degtarget - deg;
  }
}

int getInput(){
  
  int ready = 0;
  char buf[3];
  int input = -1;
  
  Serial.print("Please enter the desired position: \n");
  
  while(!ready){
    ready = Serial.readBytes(buf,3);
    input = atoi(&buf[0]);
  }
  Serial.print("input is ");
  Serial.println(input);
  return input;
}  

int getAction(int error){
  /*
  ==> TO DO TO DO TO DO
  Calculate u_out as function of the error and the kp (tuning parameter).
  // ask user for speed
  */
  
  // here we used the formula recommended in the exercise description
  u_out = kp * error;
  
  if (u_out > 254){ //u_out cannot be more than 255...
  	return 255;
  }
  else if (u_out < -254){ //...or less than -254
    return -255;
  }  
  else
     return u_out;
}
// this function is called when encoder A is set to high
void ISR_readEncoder(){

  // read encoder B
  int b = digitalRead(ENCB);
  // if b is set to low, then its going counterclockwise
  if (b == 0){
    // increase the tick counter
    a++;
  // if b is also set to high, then its going clockwise
  } else {
    // decrease tick counter
  	a--;
  }
  // set tick counter to positive equivalent (6500 is the NR of ticks per revolution)
  // this is done so we can map the position to the a value
  if (a < 0){
  	a= 6149 + a;
  } 
  // map position to a value
  pos = map(a, 0, 6149, 0, 2299); 
}