# include <stdarg.h>

void
foo(int a, ...){
  va_list toto;
  int t;

  debut();
  va_start(toto, a);
  avant_boucle();
  while((t = va_arg(toto, int)) != 0)
    bar(t);
  apres_boucle();
  va_end(toto);
}
