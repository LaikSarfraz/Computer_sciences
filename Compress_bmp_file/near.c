/*********** TROUVE LA COULEUR LA PLUS PLUS PROCHE PARMI LA PALETTE DE COULEURS */

#include "bmp.h"


short palette[COLORS][3] = {
  {0,0,0},  // noir
  {255,255,255}, //blanc
  {255,0,0}, // rouge 
  {0,255,0}, // vert clair 
  {0,0,255}, // bleu
};

int carre(int a){
  return a*a;
}



void near( short *r , short *g,short *b)
{


 
  int i =0;
  int tab_distance[COLORS]; /* tableau des distances avec les 16 couleurs */
  int shortest_distance;
  int indice=0;
  
  /* parcourt la palette et repertorie les distances*/
  for ( i = 0 ; i <COLORS ; i ++ )
    {
      tab_distance[i] =  carre(*r - palette[i][0])  + carre( *g - palette[i][1] ) +  carre(*b - palette[i][2] ) ;
    }

  
  /* Trouver la plus petite distance */
  shortest_distance = tab_distance[0];
  for ( i = 1 ; i <COLORS ; i ++ )
    {
      if ( tab_distance[i] < shortest_distance)
	{
	  shortest_distance = tab_distance[i];
	  indice = i;
	}
    }

  *r = palette [indice] [0];
  *g = palette [indice] [1];
  *b = palette [indice] [2];
  

 

}
  



