/************************************************
Sarfraz Laïk 12312565
Fonction strtok prise sur tutorialspoint.com
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int syracuse(int n){
  int acc = 1;
  while ( n != 1)
    {
      if( n % 2 )
	n = 3 *n +1;
      else 
	n /=2 ;
      acc++;
    }
  return acc;
}


int max_age(int a,int b)
{
  int i = 0;
  int j = 0;
  int tab[b-a];
  int max = 0;

  for( i = a ; i <= b ; i ++,j++)
    {
      tab[j] = syracuse (i);
    }

  for(j=0, i = a ; i <= b ; i ++, j++)
    {
      if ( max < tab[j] )
	max = tab[j];
    }
  return max;
}

int main(int argc , char** argv){

  FILE* fichier= NULL;
  fichier = fopen("text.txt", "r+");

  const char s[2] = " ";
  int i = 0;
  int j = 0;
  int max = 0;
  char* token;
  char* recuperateur;
  token = malloc(sizeof(char)*30); 
  recuperateur=malloc(sizeof(char)*50);
  
  while( fgets(recuperateur, 100,fichier) != NULL )
    {
      token = strtok(recuperateur,s);     
      while ( token != NULL ) 
	{
	  i = atoi(token);
	  token = strtok(NULL,s);
	  j = atoi(token);
	  token = strtok(NULL,s);
	  max =  max_age(i,j);

	}

      printf("%d %d %d \n",i,j,max );
    }
  

}

