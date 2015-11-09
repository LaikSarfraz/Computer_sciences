/* il s agit de prendre une image et de la modifier */

#include "bmp.h"


short palettee[COLORS][3] = {
  {0,0,0},  // noir
  {255,255,255}, //blanc
  {255,0,0}, // rouge 
  {0,255,0}, // vert clair 
  {0,0,255}, // bleu
};



void decompresser(Image * i,char* s) {
  int j, size,ind;
  GLubyte * im; 

  size = 3 * i->sizeY * i->sizeX;
  im = i->data;




  
  FILE *File;
  champ_bit a [i->sizeY * i->sizeX / 5];

  File = fopen( "file.txt" , "r" );
  fread(a , 1 , sizeof(a) , File );


  for( j =0,ind=0; j<size; j+=15,ind++)
    {
      {
	im[j] = (GLubyte)palettee [a[ind].a] [0];
	im[j+1] = (GLubyte)palettee [a[ind].a] [1];
	im[j+2] = (GLubyte)palettee [a[ind].a] [2];

	im[j+3] = (GLubyte)palettee [a[ind].b] [0];
	im[j+4] = (GLubyte)palettee [a[ind].b] [1];
	im[j+5] = (GLubyte)palettee [a[ind].b] [2];

	im[j+6] =(GLubyte) palettee [a[ind].c] [0];
	im[j+7] = (GLubyte)palettee [a[ind].c] [1];
	im[j+8] =(GLubyte) palettee [a[ind].c] [2];
	  
	im[j+9] =(GLubyte) palettee [a[ind].d] [0];
	im[j+10] = (GLubyte)palettee [a[ind].d] [1];
	im[j+11] = (GLubyte)palettee [a[ind].d] [2];
	  
	im[j+12] = (GLubyte)palettee [a[ind].e] [0];
	im[j+13] = (GLubyte)palettee [a[ind].e] [1];
	im[j+14] = (GLubyte)palettee [a[ind].e] [2];
      }

    }
  
}

