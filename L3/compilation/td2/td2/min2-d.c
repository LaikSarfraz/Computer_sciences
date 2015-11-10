/* min2-d.c
  Driver pour tester la fonction min2
 */
# include <stdio.h>
# include <stdlib.h> // pour strtol

extern int min2(int, int); // defini dans min2.s

int
main(int argc, char * argv[]){
  int a, b;

  if (argc != 3){
    fprintf(stderr, "usage: %s N M\n", argv[0]);
    return 1;
  }
  a = strtol(argv[1], NULL, 0);
  b = strtol(argv[2], NULL, 0);
  printf("min2(%d, %d) = %d\n", a, b, min2(a, b));
  return 0;
}
