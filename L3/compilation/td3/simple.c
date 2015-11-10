/* simple.c

 Une fonction simple.
 L'affectation au milieu sert à séparer le prologue de l'épilogue
*/
void
foo(){
  extern int globale;

  globale = 1234;
}
