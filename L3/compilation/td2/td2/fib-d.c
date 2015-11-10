/* fib-d.c

   Driver pour la fonction de Fibonacci
*/
# include <stdio.h>
# include <stdlib.h>

extern int fib(int n); // dans fib.s

int
main(int argc, char * argv[]){
  int i;
  int t;

  for(i = 1; i < argc; i++){
    t = strtol(argv[i], NULL, 0);
    printf("fib(%d) = %d\n", t, fib(t));
  }
  return 0;
}
