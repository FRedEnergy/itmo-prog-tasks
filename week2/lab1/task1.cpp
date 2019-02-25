#include <iostream>
#include <cmath>
#include "task1.h"

void changeLargestRef(int &a, int &b) {
    if(a > b)
        a = a % b;
    else
        b = b % a;
}

void changeLargestPtr(int *a, int *b) {
    if(*a > *b)
        *a = *a % *b;
    else
        *b = *b % *a;
}

void roundRef(double &a) {
    a = floor(a + 0.5);
}

void roundPtr(double *a) {
    *a = floor(*a + 0.5);
}

void reduceRadiusRef(CircleStruct &circle, float &reduction) {
    circle.r -= reduction;
}

void reduceRadiusPtr(CircleStruct *circle, float *reduction) {
    circle->r -= *reduction;
}

void transposeRef(Matrix3 &matrix) {
    float copy[9];
    std::copy(std::begin(matrix.data), std::end(matrix.data), std::begin(copy));

    for(int n = 0; n < 3; n++)
        for(int m = 0; m < 3; m++)
            matrix.data[n * 3 + m] = copy[m * 3 + n];

}

void transposePtr(Matrix3 *matrix) {
    float copy[9];
    std::copy(std::begin(matrix->data), std::end(matrix->data), std::begin(copy));

    for(int n = 0; n < 3; n++)
        for(int m = 0; m < 3; m++)
            matrix->data[n * 3 + m] = copy[m * 3 + n];
}

int main(){
    //#3

    int a = 23;
    int b = 32;

    changeLargestRef(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    //#6
    double d = -3.14;
    roundPtr(&d);
    std::cout << "d = " << d << std::endl;

    //#11
    CircleStruct circle{1, 1, 3};

    float reduction = 2.0F;
    reduceRadiusRef(circle, reduction);
    std::cout << "circle.r = " << circle.r << std::endl;

    //#14
    Matrix3 mat{{
        1.0F, 2.0F, 3.0F,
        4.0F, 5.0F, 6.0F,
        7.0F, 8.0F, 9.0F
    }};

    transposePtr(&mat);
    for(int i = 0; i < 9; i++)
        std::cout << "mat[" << i << "] = " << mat.data[i] << std::endl;

    return 0;
}