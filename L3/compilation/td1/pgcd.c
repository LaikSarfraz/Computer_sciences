/* pgcd.c
 */
int
pgcd(int a, int b){
        int t;

        while(a != 0){
                if (a < b){
                        t = b;
                        b = a;
                        a = t;
                }
                a -= b;
        }
        return b;
}
