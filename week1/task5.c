
#include <stdio.h>

int dot(int a, int b, int c, int d){
    return a * c + b * d;
}
int main(int c, char ** args) {
    int a[] = {88, 112, 6467, 325, 878, 3, 77, 8, 99};
    printf("Array content:\n");
    for(int i = 0; i < (sizeof(a)/ sizeof(int)); i++)
        printf("%d = %d\n", i, a[i]);

    int m1[] = {1, 2,
                3, 1};
    int m2[] = {1, 1,
                0, 2};

    int result[] = {
        dot(m1[0], m1[1], m2[0], m2[2]), dot(m1[0], m1[1], m2[1], m2[3]),
        dot(m1[2], m1[3], m2[0], m2[2]), dot(m1[2], m1[3], m2[1], m2[3])
    };

    printf("Result of matrix multiplication:\n%d, %d\n%d, %d", result[0], result[1], result[2], result[3]);
    return 0;
}