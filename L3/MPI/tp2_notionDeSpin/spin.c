#include <stdio.h>
#include <stdlib.h>



void convertir( int* tab, int x )
{
  int i = 0;
  while ( x > 1 )
    {
      if (x%2 == 1)
	tab[i] = 1;
      x /= 2;
      i++;
    }
}      

int spin(int a, int b,int n)
{
  int i = 0;
  int j = 0;
  int vec1[n];
  int vec2[n];
  int somme = 0 ;
  for(j = 0; j < n; j++)
    for(i =0 ; i < n ; i++)
      somme += vec1[i] * vec2[j];
  return somme;
}


int main(int argc, char** argv)
{
  int N=5;
  int i=0;
  int tab[N] = -1;
  convertir ( tab, 10);

  for(i=0; i<N; i++)
    printf("%d ",tab[i]);
  return 0;
}
