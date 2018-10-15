#include "circle.h"
#include <stdio.h>

void main(int count, char** args){
    printf("Enter circle radius:\n");
    float radius = 0.0F;
    scanf("%f", &radius);
    Circle circle = {radius};

    printf("Perimeter of circle with radius %f is: %f\n", circle.radius, getCirclePerimeter(circle));
    printf("Area of circle with radius %f is: %f\n", circle.radius, getCircleArea(circle));
}
