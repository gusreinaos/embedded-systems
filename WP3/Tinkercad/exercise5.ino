// This exercise was done in collaboration between group 19 and group 7
// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 3
// Exercise 3.4
// Submission code: Tyu-78F (provided by your TA-s) 


//Define the number of rows of the keypad
const int numberOfRows = 4; 
//Define the number of columns of the keypad
const int numberOfColumns = 4; 

//Define the matrix of the keypad that has all of the options
const int keys[numberOfRows][numberOfColumns] = { 
  {'1', '2', '3', 'A'}, 
  {'4', '5', '6', 'B'}, 
  {'7', '8', '9', 'C'}, 
  {'*', '0', '#', 'D'} 
}; 

//Store all of the row pins
int rowPins[numberOfRows] = {13, 12, 11, 10}; 
//Store all of the column pins
int colPins[numberOfColumns] = {9, 8, 7, 6}; 

void setup() {
  //Declare the input points from the aray of row pins
  for (int i = 0; i < numberOfRows; i++) { 
    pinMode(rowPins[i], INPUT_PULLUP); 
  }
  //Declare the input points from the aray of column pins
  for (int i = 0; i < numberOfColumns; i++) { 
    pinMode(colPins[i], OUTPUT); 
  } 
  Serial.begin(9600);
} 

void loop() {

  //Iterating through every column and turning it low
  for (int i = 0; i < numberOfColumns; i++) { 

    //Set the state of the pins of the columns to low in every iteration
    //so that as soon as the user presses in one of the buttons of the row
    //(set as high in the beginning)the voltage will be 0 and therefore
    //the function will detect a press

    digitalWrite(colPins[i], LOW);

    //Iterating through every row in the column and checking if it is low meaning it is pressed
    for (int j = 0; j < numberOfRows; j++) { 

      //If one row happens to be pressed (row is low) and the column is low as well
      if (digitalRead(rowPins[j]) == LOW) {

        //Print the exact position of the intersection of column and row
        Serial.println((char)keys[j][i]);

       //Do nothing until the row becomes high again
        while(digitalRead(rowPins[j]) == LOW);
      } 
    }
    //Getting the column back as high again
    digitalWrite(colPins[i], HIGH); 
  }
}