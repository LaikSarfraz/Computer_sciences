#include <stdio.h>

extern int fact ( int n ) ; // dans fact . s

int
main ( int argc , char** argv ) {
  int i ;
  int t ;

  for ( i = 1 ; i < argc ; i++){
    printf("%d\n",argc);

    t = atoi ( argv [ i ]);
    printf (" fact (%d ) = %d \n " , t , fact ( t ) ) ;

  }
}
