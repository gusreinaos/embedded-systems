// (C) Juan García, Oscar Reina, Jan Manel, group: 19 (2023) 
// Work package 2 
// Exercise 2.2
// Submission code: 5556 (provided by your TA-s) 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
//#### Constants ##### 
#define MAX 5   
 
// ##### typedefs          #### 
typedef struct q{ 
        int number; 
        struct q *next; 
        struct q *prev; 
} REGTYPE; 
 
// ##### Function declarations   ##### 
 
REGTYPE* random_list(void); 
REGTYPE* add_first(REGTYPE* temp, int data); 
 
 
//###### Main program ####### 
int main(int argc, char *argv[]) 
{ 
    int nr=0; 
 
    REGTYPE *act_post , *head=NULL; 
 
    srand(time(0));  //   Random seed  
    head=random_list(); 
    act_post=head;

    while( act_post!=NULL){ 
           printf("\n Post nr %d : %d" , nr++, act_post->number); 
           act_post=act_post->next; 
    }



    printf("\n");
    //add a new node at the first position and do the same testing
    head=add_first(head, rand() % (101));
    act_post = head;
    nr = 0;
    while( act_post!=NULL){ 
           printf("\n Post nr %d : %d" , nr++, act_post->number); 
           act_post=act_post->next; 
    }

    printf("\n");


 
       
 
 // --- Free the allocated memory  --- 
 
  while((act_post=head)!=NULL){ 
    // store next pointer for next loop iteration
     head=act_post->next;
     // delete current node
     free(act_post); 
  } 
   
                    
 
  return 0; 
} 
 
// ====     End of main   ====================================== 
 
REGTYPE* random_list(void){ 
    int nr; 
    //we declare three REGTYPE structs one for the top node, and two temporal nodes
    REGTYPE *top, *old, *item;

    top = malloc(sizeof(REGTYPE));
    //previous node of top is NULL
    top->prev=NULL;
    //we assign a random number 
    top->number= rand() % (101);
    //old points at top
    old = top;
    for (int i = 1; i < MAX; ++i){
        //we declare a new node
        item = malloc(sizeof(REGTYPE));
        //previous node is old
        item->prev = old;
        //next node of old is the new node
        old->next = item;
        //we assign a random number to the new node
        nr= rand() % (101);
        item->number = nr;
        //old points to the new node
        old = item;
    }
    //return top node
    return(top); 
} 
 
//==========================================================                 
 
REGTYPE* add_first(REGTYPE* temp, int data){ 
    REGTYPE *item;
    //we create a new node
    item = malloc(sizeof(REGTYPE));
    //we assign the the top node that previous is the new node
    temp->prev = item;
    //previous of the new node is NULL
    item->prev = NULL;
    //the pointer to the next node is the old top
    item->next = temp;
    //we assing the data to number
    item ->number = data;
    //return the new top node
    return(item);

}