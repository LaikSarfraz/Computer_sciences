/* main.c
 */
# include <stdio.h>

int
main(int ac, char * av[]){
        if (ac < 3){
                fprintf(stderr, "usage: %s N M\n", av[0]);
                return 1;
         }
        printf("%d\n", pgcd(atoi(av[1]), atoi(av[2])));
        return 0;
}
