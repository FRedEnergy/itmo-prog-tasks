#include <math.h>
#include <stdio.h>


int main(int c, char ** args){

    double a = 0.0;
    scanf("%lf", &a);

    double m = sin(2.0 * a) + sin(5.0 * a) - sin(3.0 * a);
    double n = cos(a) + 1.0 - 2.0 * sin(2.0 * a) * sin(2.0 * a);
    double z1 = m / n;
    double z2 = 2.0 * sin(a);

    printf("z1 = %f\nz2 = %f", z1, z2);
    return 0;
}
