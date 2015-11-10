#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>
#include <math.h>
#include <math.h>



int nb_digit(int nb){
    
  int tab[10];
  int i,res=0;
  bzero(tab, 10*sizeof(tab[0]));

  while(nb>0){
    tab[nb%10]++;
    nb/=10;
  }
  for(i=0; i<10; i++)
    if(tab[i])
      res++;
  
  return res;
}

void san(int n, int p){
  int k,i,puissance;
  for(i=0; i<INT_MAX-1; i++){
    if(pow(i,p) < INT_MAX){
      puissance = pow(i,p);
      k = nb_digit(puissance);
      if(k==n)
	printf("A(%d,%d) ==> %d | ^%d = %d\n",n,p,i,p,puissance);
    }
  }
}

int main(int c, char**arg){
  int n,p;
  printf("t0\n");
  n = atoi(arg[1]);
  p = atoi(arg[2]);
  printf("t1\n");
  san(n,p);
  return 0;
}
