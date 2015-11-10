# include <stdarg.h>

char marque;

void
foo(char * a, ...){
  va_list toto;
  char * t;

  debut();
  va_start(toto, a);
  avant_boucle();
  while((t = va_arg(toto, char *)) != &marque)
    bar(t);
  apres_boucle();
  va_end(toto);
}
