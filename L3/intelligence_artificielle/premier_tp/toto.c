#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
  srand(time(NULL));
  int r = rand ()%20 ; 
  int i;
  for ( i = 0; i<20; i++)
    {
    printf("%d\n",r);
    r =rand()%20;
    }
  return 0;
}
