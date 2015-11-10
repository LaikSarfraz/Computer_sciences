#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>
#include <math.h>
#include <mpi.h>


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

00000000000000
.v210oid san(int n, int p, int Rank, int Size){
  int k,i,puissance;
  
  for(i=0; i<INT_MAX; i++){
    if((i%Size)==Rank){
      if(pow(i,p) < INT_MAX){
	puissance = pow(i,p);
	k = nb_digit(puissance);
	if(k==n)
	  printf("A(%d,%d) ==> %d | ^%d = %d\n",n,p,i,p,puissance);
      }
    }
  }
}

int main(int c, char**arg){
  MPI_Init(&c,&arg);
  int Rank, Size, n,p;

  MPI_Comm_rank(MPI_COMM_WORLD,&Rank);
  MPI_Comm_size(MPI_COMM_WORLD,&Size);
  
  n = atoi(arg[1]);
  p = atoi(arg[2]);

  san(n,p, Rank,Size);
  MPI_Finalize();
  return 0;
}
