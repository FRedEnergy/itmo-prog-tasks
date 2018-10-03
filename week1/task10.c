#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getDigits(int **digits, int *count, int n){
    *count = (int) (log10(n) + 1);
    *digits = malloc(sizeof(int) * *count);
    int m = n;
    for(int i = *count - 1; i >= 0; i--){
        *((*digits) + i) = m % 10;
        m /= 10;
    }
}

int recurseSum(int sum, int i, int *digits, int count){
    if(i >= count)
        return sum;
    return recurseSum(sum + digits[i], i + 1, digits, count);
}

int main(int c, char **args){
    int n = 0;
    scanf("%d", &n);
    int *digits = 0;
    int digitsCount = 0;
    getDigits(&digits, &digitsCount, n);

    for(int i = 0; i < digitsCount; i++){
        printf("%d = %d\n", i, digits[i]);
    }

    int sum = recurseSum(0, 0, digits, digitsCount);
    printf("Sum = %d\n", sum);

    return 0;
}