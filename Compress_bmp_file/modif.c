/* il s agit de prendre une image et de la modifier */

#include "bmp.h"



int trouve_couleur(int r, int g, int b)
{
  if ( r == 0 && g == 0 && b == 0)
    return 0;
  else  if ( r == 255 && g == 255 )
    return 1;
  else  if ( r == 255 && g == 0)
    return 2;
  else  if ( r == 0 && g == 255)
    return 3;
  else  if ( r == 0 && b==255 )
    return 4;

}

void gris(Image * i) {
  int j, size;
  GLubyte * im; 
  short * ancien_p=malloc(sizeof(short)*i->sizeY*i->sizeX*3);
  short * erreur=malloc(sizeof(short)*i->sizeY*i->sizeX*3);
  short *imbis=malloc(sizeof(short)*i->sizeY*i->sizeX*3);
  int* tab=malloc(sizeof(int)*i->sizeY*i->sizeX);

  size = 3 * i->sizeY * i->sizeX;
  im = i->data;

  for ( j= 0; j < size ; j++)
      imbis[j] = (GLubyte)im[j];



  for (j = 0; j < size; j +=3) {

    /* stocker l'ancien pixel */
    ancien_p[j]=imbis[j]; 
    ancien_p[j+1]=imbis[j+1]; 
    ancien_p[j+2]=imbis[j+2]; 

    near(&imbis[j] ,&imbis[j+1] ,&imbis[j+2]);


    /* La différence */
    erreur[j] = ancien_p[j] - imbis[j] ;
    erreur[j+1] =  ancien_p[j+1] - imbis[j+1];
    erreur[j+2] = ancien_p[j+2] - imbis[j+2] ;
  
    if ( j< 11)
      printf("erreur %d %d %d\n\n",erreur[j],erreur[j+1],erreur[j+2]);
    
    /* Erreur répartie sur le pixel à droite */
    imbis[j+3] += (float)7/16*erreur[j];
    imbis[j+4] += (float)7/16*erreur[j+1];
    imbis[j+5] += (float)7/16*erreur[j+2];
    

    /* Erreur répartie sur le pixel en bas à gauche*/
    imbis[j+(i->sizeX*3)-3] += (float)3/16*erreur[j];
    imbis[j+(i->sizeX*3)-2] += (float)3/16*erreur[j+1];
    imbis[j+(i->sizeX*3)-1] += (float)3/16*erreur[j+2];

    /* Erreur répartie sur le pixel en bas  */
    imbis[j+(i->sizeX*3)+0] += (float)5/16*erreur[j];
    imbis[j+(i->sizeX*3)+1] += (float)5/16*erreur[j+1];
    imbis[j+(i->sizeX*3)+2] += (float)5/16*erreur[j+2];
   
    /* Erreur répartie sur le pixel en bas à droite  */
    imbis[j+(i->sizeX*3)+3] += (float)1/16*erreur[j];
    imbis[j+(i->sizeX*3)+4] += (float)1/16*erreur[j+1];
    imbis[j+(i->sizeX*3)+5] += (float)1/16*erreur[j+2];
    
  }


  
  




for ( j= 0; j < size ; j++)
    {
      im[j] = (GLubyte)imbis[j];
    }

  
}



  /****************** PARTIE COMPRESSION *********************/
void compresser(Image* i)
{
  int j,k,size;
  GLubyte *imbis;
 
  
  size = 3 * i->sizeY * i->sizeX;
  imbis = i->data;

 
  FILE* compression;
  compression = fopen( "file.txt" , "w" );  

  champ_bit compress[ (i->sizeY * i->sizeX) / 5];
  for ( j=0,k=0; j< size; j+=15,k++)
    {
      compress[k].a = trouve_couleur( (int)imbis[j] , (int)imbis[j+1], (int)imbis[j+2]);
      compress[k].b = trouve_couleur( (int)imbis[j+3] , (int)imbis[j+4], (int)imbis[j+5]);
      compress[k].c = trouve_couleur( (int)imbis[j+6] , (int)imbis[j+7], (int)imbis[j+8]);
      compress[k].d = trouve_couleur( (int)imbis[j+9] , (int)imbis[j+10], (int)imbis[j+11]);
      compress[k].e = trouve_couleur( (int)imbis[j+12] , (int)imbis[j+13], (int)imbis[j+14]);  
    }


  
 fwrite(compress , 1 , sizeof(compress) ,compression  );
 printf("Vous passez de %d octets a %d octets, vous économisez %lu octets\n",size,sizeof(compress), size-sizeof(compress));
}
