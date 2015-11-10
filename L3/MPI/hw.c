#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>



int main(int ac, char** av){
  int rang,processus;
  
  MPI_Init(&ac, &av);
  MPI_Comm_rank(MPI_COMM_WORLD,&rang);
  MPI_Comm_size(MPI_COMM_WORLD,&processus);
  printf(" Hello world rang vaut %d processus vaut %d \n",rang,processus);
  MPI_Finalize();



  return 0;
}
