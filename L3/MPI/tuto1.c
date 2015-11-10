#include <mpi.h>
int main(int argc, char * argv[]) {
  int rang, p;
  /* Initialisation de MPI.
     Aucune fonction MPI ne peut etre appelee avant l’appel a cette fonction */
  MPI_Init(&argc,&argv);
  /* Affecte a p le nombre de processus qui executent ce programme */
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  /* Affecte a rang mon numero de processus */
  MPI_Comm_rank(MPI_COMM_WORLD, &rang);
  /* Instructions du programme */
  /* Apres l’appel a cette fonction, plus aucun appel
     a la biliotheque MPI n’est possible */
  MPI_Finalize();
  return 0;
}
