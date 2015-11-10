/* return-adr.c

 Comment renvyer une adresse
*/
extern char globale;

char *
foo(void){
  return &globale;
}
