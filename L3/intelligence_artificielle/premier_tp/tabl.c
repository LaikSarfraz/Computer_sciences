#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void shuffle(int tab[100], char boo[100])
{
  srand(time(NULL));
  int i = 0;
  int alea = rand()%100;

  for ( i = 0; i<100; i++)
    boo[i] = 0;
  for ( i = 0; i<100; i++)
    {
      while (boo[alea])
	alea=rand()%100;
      tab[i]=alea;
      boo[alea]=1;
    }
}

  
  
main(){
  srand(time(NULL));
  int tab[100];
  char boo[100];
  shuffle(tab,boo);

  int i = 0;
  for ( i = 0; i<100; i++)
    printf("%d \n",tab[i]);


}
