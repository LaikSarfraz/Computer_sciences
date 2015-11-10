/* fact-d.c

   Driver pour la fonction factorielle
*/
# include <stdio.h>
# include <stdlib.h>

extern int fact(int n); // dans fact.s

int
main(int argc, char * argv[]){
  int i;
  int t;

  for(i = 1; i < argc; i++){
    t = strtol(argv[i], NULL, 0);
    printf("fact(%d) = %d\n", t, fact(t));
  }
  return 0;
}
