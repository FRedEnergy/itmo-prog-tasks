#include <stdio.h>
#include <stdlib.h>

int main(int c, char ** args) {
    float p = 1;
    float *x = &p;
    x[0] = -8.8F;
    x[1] = 11.2;
    x[2] = 64.67;
    x[3] = 55.32;

    printf("Array 1\n");
    for(int i = 0; i < 4; i++){
        printf("%d = %f\n", i, *(x + i));
    }

    float *a = malloc(4 * sizeof(float));
    a[0] = -8.8F;
    a[1] = 11.2;
    a[2] = 64.67;
    a[3] = 55.32;

    printf("Array 2\n");
    for(int i = 0; i < 4; i++){
        printf("%d = %f\n", i, a[i]);
    }

    free(a);

    return 0;
}