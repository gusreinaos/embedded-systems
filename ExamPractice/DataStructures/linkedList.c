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
 
       
 
 // --- Free the allocated memory  --- 
 
  while((act_post=head)!=NULL){ 
     head=act_post->next; 
     free(act_post); 
  } 
  return 0; 
} 
 
// ====     End of main   ====================================== 
 
REGTYPE* random_list(void ){ 
    int nr, i=0; 
    REGTYPE *top = NULL, *new_node, *prev_node = NULL; 

    for(int i = 0; i < MAX; i++) {
        REGTYPE *new_node = malloc(sizeof(REGTYPE));
        new_node->number = rand() % 101;
        new_node->prev = prev_node;
        new_node->next = NULL;

        if(prev_node != NULL) {
            prev_node->next = new_node;
        }
        if(top == NULL) {
            top = new_node;
        }
        prev_node = new_node;
    }
     
    return(top); 
} 
 
//==========================================================                 
 
REGTYPE* add_first(REGTYPE* temp, int data){ 
 
 
} 