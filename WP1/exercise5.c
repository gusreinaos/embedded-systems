#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
 
#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers 

// ------ Function declarations   ----------  
 
// This function generates a set of random numbers 
// and fills the table *tab with these numbers 
void create_random(int *tab );
 
// This function takes the *tab of random numbers 
// and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq );     
 
// This function takes the frequency count table 
// and draws a histogram of the values in that frequency table 
void draw_histogram(int *freq );  
 
// ------ Function definitions   ---------- 

void create_random(int *tab) {
    for(int i = 0; i < MAX; i++) {
        tab = rand() % (MAXNUMBER + 1);
        tab++;
    }
}

void count_frequency(int *tab, int *freq){
    //the pointer temp will act as a copy of the adress pointed by tab
    int *temp = tab;
    //for each number between 0 to 20
    for (int i = 0; i <= MAXNUMBER; ++i)
    {
        //initialize frequency to 0
        *freq = 0;
        //for every random number in tab
        for (int j = 0; j < MAX; ++j)
        {
            //if the number is equal to i ([0,20])
            if (*temp==i)
            {
                //sum 1 to the frequency
                *freq+=1;
            }
            //jump to next adress in tab array
            temp++;
        }
        //reset temp 
        temp = tab;
        //jump to next freq adress
        freq++;
    }


}   

void draw_histogram(int *freq){
    //for each value of freq
    for (int i = 0; i <= MAXNUMBER; ++i)
    {
        //if it's different to zero
        if (*freq!=0)
        {
            //print a number of x equal to the value of the frequency
            printf("%d   %.*s\n", i,*freq, "xxxxxxxxxxxxxxxxxxxx");
        }        
        *freq++;
    }
}

 
// ------ Main   -------------------------- 
 
// The main entry point for the program 
//  
// If you choose to go for the optional part 
// Please modify it accordingly 
int main (void){ 
    srand(time(NULL));
    int table[MAX]; 
    int frequency[MAXNUMBER];

    int *tab = table;
    int *freq = frequency;
    create_random(tab);
    count_frequency(tab,freq);
    draw_histogram(freq);        
} 