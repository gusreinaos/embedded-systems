// (C) Juan Garcia, Oscar Reina, Jan Manel, group: 19 (2023)
// Work package 4
// Exercise 4 
// Submission code: eRw&9 (provided by your TA-s) 

//Declaration of libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// -----Functions Declarations -------
int search_number(int number, int tab[], int size); 
void sort(int number, int tab[]);


// -----Functions Utils -------
int search_number(int number, int tab[], int size) {

    //Checking for the number in the array 
    for(int i = 0; i < size; i ++) {
        if(tab[i] == number){
            //In case we find it we return its first occurrence and break the program (so we make sure it is only the first one)
            return i;
        }
    }
    //Return -1 breaking the program in case of no value found
    return -1;
}

void sort(int number, int tab[]) {
    int start = 0;
    //Looping through the array according to the new start value 
    while (start < number) {
        //Saving the first value of the array
        int minValue = tab[start];
        //Saving the index of that first value
        int minIndex = start;
        //Looping over the list to find the minimum element
        for (int i = start; i < number; i++) {
            //Comparing each element of the array with the minimum to get the new smaller value with its index
            if (tab[i] < minValue) {
                minIndex = i;
                minValue = tab[i];
            }
        }

        //Swapping the minimum with the first in the list (start)
        int temp = tab[minIndex];
        tab[minIndex] = tab[start];
        tab[start] = temp;
        //Increasing the start of the array +1 since that part of the array is sorted
        start++;
    }
}

// Main function in the program, no program arguments supported
int main () {

    //Creating a dummy array to test
    int tab[] = {7, 1, 6, 3, 99, 3745, 87};
    //Getting the size of the array
    int size = sizeof(tab) / sizeof(tab[0]);

    //Searching for a specific number of the array
    int number = search_number(6, tab, size);
    //Sorting the test array
    sort(size, tab);
    
    //Printing the index of the number we were looking for
    printf("The number we are looking for is located at index %d\n", number);

    //Printing the already sorted array
    printf("Sorted array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
} 