# include <stdio.h>
# include <string.h>

extern char * indexa(char *); // dans indexa.s 

void
tester(char * string){
  char * trouve = indexa(string);
  char * correct = strchr(string, 'a');
  
  printf("Dans la chaine %s: ", string);
  if (correct != trouve)
    printf("ERREUR: indexa renvoie %p au lieu de %p\n", trouve, correct);
   else if (correct != NULL)
     printf("on trouve 'a' en %d\n", trouve - string);
   else
     printf("on n'a pas trouve 'a'\n");
}

int
main(int argc, char * argv[]){
  int i;

  for(i = 1; i < argc; i++)
    tester(argv[i]);
  return 0;
}
