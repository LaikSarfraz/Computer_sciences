#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
  srand(time(NULL));
  float v =  (float)rand ()    ;

  printf("%f et %d\n",v,RAND_MAX);
  
  return 0;
}
