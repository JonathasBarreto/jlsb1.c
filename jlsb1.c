#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 250

int main() {

    int *num ;

    char string[MAX], str[MAX] ;
    int n, i, j, k ;

    printf("String inicial: \n") ;
    scanf("%s", string) ;

    n = strlen(string) ;
    j = 0;
    str[0] = 0 ;
    for ( i = 0; i < n; i++ ) {
        if (strchr(str, string[i]) == NULL){
                str[j] = string[i] ;
                j++ ;
                str[j] = 0 ;
        }
    }
    strcpy(string, str) ;
    n = strlen(string) ;

    num = (int *) calloc((n+1), sizeof(int)) ;
    if ( num == NULL ) {
        return -1;
    }

    while ( num[n] == 0) {
        for (i = 0; i < n; i++ ) {
            for (j = 0, k = n-1; j < n; j++) {
                str[k] = string[num[j]] ;
                k-- ;
            }
            str[j] = 0 ;
            printf("%s\n", str) ;

            num[0]++ ;
        }

        for ( i = 0; i < n; i++ ) {
            if ( num[i] == n ) {
                num[i] = 0 ;
                num[i+1]++ ;
            }
        }
    }
    return 0;
}
