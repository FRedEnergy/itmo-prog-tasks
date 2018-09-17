#include <stdio.h>

int isPrime(int n){
    int c;
    for (c = 2 ; c <= n - 1; c++) {
        if(n % c == 0)
            break;
    }
    return c == n;
}

int main(int c, char **arg){

    //sub 3
    printf("Enter number to convert to string:\n");
    int input = 0;
    scanf("%d", &input);
    char str[12];
    sprintf(str, "%d", input);

    printf("String of %d = '%s'\n", input, str);

    //sub 4
    printf("Enter last number to loop to:\n");

    int n = 0;
    scanf("%d", &n);

    for(int i = 0; i <= n; i++){
        if(isPrime(i))
            printf("%d ", i);
    }

}