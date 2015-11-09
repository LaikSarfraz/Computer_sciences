#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#define __OSX__
#ifndef __OSX__
#include <GL/gl.h>	
#else
#include <GL/glut.h>
#endif
#define COLORS 5



struct Image {
  unsigned long sizeX;
  unsigned long sizeY;
  GLubyte* data;
};


typedef struct
{
  unsigned short
  a: 3,
    b: 3,
    c: 3,
    d: 3,
    e: 3;

}champ_bit; 


typedef struct Image Image;
typedef unsigned short utab [3][3][3];

int ImageLoad(char *filename, Image *image);
int ImageSave(char *filename, Image *image);
int ImageSaveJPG(char *filename, Image *image);
void gris (Image * ), lumineux (Image *);
void near(short*, short*, short*);
void decompresser(Image*  i,char* ) ;
