#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#define  MCW MPI_COMM_WORLD


int algo(int n){
  //printf(" %d" , n);
  int age=0;
  while(1){
    age++;
    if(n==1)
      return age;
    if(n & 0x01)
      n= 3*n+1;
    else
      n/=2;
  }
}


int age(int a, int b){
  int max=0,act=0;
  
  while(a<=b)
    {
      act= algo(a);
      if(act>max)
	max=act;
      a++;
    }
  return max;
}

int main(int _C, char** _V){

  int i = 0;
  MPI_Init(&_C,&_V);
  int D[3*1024];
  int nD=0;
  int R,S,a,b,tmp[1024];
  MPI_Status status;
  FILE * fp = fopen(_V[1],"w+");
  MPI_Comm_rank(MCW, &R);
  int Z[1024];
  int L=0;
  MPI_Comm_size(MCW,&S);
  L=0;
  if(R==0){
    while(fp!=0){
      //Lire les deux valeurs a , b
      if(L<1024)
	D[L*3]=L;
      D[L*3+1]=a;
      D[L*3+2]=b;
      L++;
    }
  }
  
  if(R==0){

    for(i=1; i < S; i++){
      MPI_Send(&L,1, MPI_INT, i, 0 , MCW);
      MPI_Send(D,3*L, MPI_INT, i, 0 , MCW);
      
    }
  }
  else{
    MPI_Recv(&L, 1, MPI_INT, 0 , 0 , MCW, &status);
    MPI_Recv(D, 3*1, MPI_INT, 0 , 0 , MCW, &status);
  }
  for(i=R; i< L ; i+=S)
    Z[i]= age (D[i*3+1], D[i*3+2]);
  if(R==0){
    for(i= 0; i < S ; i++) while(1){
	int tmp[3];
	MPI_Recv(tmp,3,MPI_INT , i , 0 , MCW, &status);
	if(tmp[0]== -1 && tmp[1] == -1) break;
	Z[tmp[0]]= tmp[1];
      }
  }
  else{
    for(i=R; i < L; i+=S){
      int tmp [2];
      tmp[0]=i;
      tmp[1]= Z[i];
      MPI_Send(tmp, 2 , MPI_INT, 0 , 0 , MCW);

    }
    tmp[0]= -1;
    tmp[1]= -1;
    MPI_Send(tmp,2,MPI_INT,0,0,MCW);
  }
  if(R == 0){
    for(i = 0; i < L ; i++){
      printf("%d %d %d\n", D[i * 3 + 1], D[i*3+2], Z[i]);
    }
  }
  fclose(fp);
  MPI_Finalize();
  return 0;
}
