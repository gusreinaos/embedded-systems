#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
  srand ( time(NULL) );
  int randomNumber =  rand() %100 + 1;
  
  
  return 0;
}