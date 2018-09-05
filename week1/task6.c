#include <stdio.h>
#include <stdlib.h>

int main(int c, char ** args) {
    float *a = malloc(sizeof(float) * 4);
    a[0] = -8.8F;
    a[1] = 11.2;
    a[2] = 64.67;
    a[3] = 55.32;

    for(int i = 0; i < 4; i++){
        printf("%d = %f\n", i, (*a + sizeof(float) * i));
    }

    return 0;
}