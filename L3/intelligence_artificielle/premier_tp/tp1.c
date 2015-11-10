/************************************************
Sarfraz Laïk 12312565
Fonction strtok prise sur tutorialspoint.com
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX 150


typedef struct Vecteur{

  double *v;
  char* nom;
  double norm;
}Vecteur;



void affiche(Vecteur* _Vecteur){
  int i = 0 ;
  int j = 0 ;
  for ( i = 0 ; i<MAX; i++)
    {
      for( j = 0; j<4; j++)
	{
	printf("%f ",_Vecteur[i].v[j]);
	}
      printf("la norme vaut %lf ",_Vecteur[i].norm);
      printf("%s ",_Vecteur[i].nom);


    }
}


/* Fonction qui mélange d'un seul passage le tableau de structures */

void shuffle(Vecteur* _Vecteur)
{
  int r = rand () %149;
  int i =0;
  int j=0;
  float tmp[4];
  for (i = 0; i<150; i++){
    for ( j=0; j<4; j++)
      {
	tmp[j]= _Vecteur[i].v[j];
	_Vecteur[i].v[j]=_Vecteur[r].v[j];
	_Vecteur[r].v[j]=tmp[j];
      }
    r = rand()%150;
  }
}




int main(){
  srand(time(NULL));
  FILE* fichier= NULL;
  fichier = fopen("iris.txt", "r+");

  const char s[2] = ",";
  int i = 0;
  int j = 0;

  char* token;
  char* recuperateur;
  Vecteur* _Vecteur ;

  token = malloc(sizeof(char)*14); // car iris-virginica est de 14 lettres max
  recuperateur=malloc(sizeof(char)*30);
  _Vecteur = malloc(sizeof(*_Vecteur)*MAX);

  /* allouer les 150 x 5 vecteurs */
  for (i =0; i<MAX; i++){
    _Vecteur[i].v = malloc(sizeof(double)*4);
    _Vecteur[i].nom=malloc(sizeof(char)*14);
  }

   i = 0;

  /* on lit toutes les lignes terminant par \n */
   while( fgets(recuperateur,100,fichier) != NULL )
    {
      token = strtok(recuperateur,s);     
      for (j=0 ;j < 4; j++ )
	{
	  _Vecteur[i].v[j] = atof(token);
	  token = strtok(NULL,s);
	}
      _Vecteur[i].nom = token;
      for ( j = 0; j < 4; j++) 
     	_Vecteur[i].norm  += pow ( _Vecteur[i].v[j] , 2  );
      
      i++;
    }
  
  affiche(_Vecteur);
  shuffle(_Vecteur);
  printf(" \n\n **************** DEUXIEME AFFICHAGE **************\n\n");
  affiche(_Vecteur);
  printf("\n");


  

  // free(token);  //en commentaire car segfault
  free(recuperateur);
  free(_Vecteur);

  return 0;
  
}

