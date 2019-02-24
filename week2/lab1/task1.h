#ifndef ITMO_PROG_TASKS_TASK1_H
#define ITMO_PROG_TASKS_TASK1_H

typedef struct {
    float x, y, r;
} CircleStruct;

typedef struct {
    float data[9];
} Matrix3;

void changeLargestRef(int& a, int& b);

void changeLargestPtr(int* a, int* b);

void roundRef(double& a);

void roundPtr(double* a);

void reduceRadiusRef(CircleStruct& circle, float& reduction);

void reduceRadiusPtr(CircleStruct* circle, float* reduction);

void transposeRef(Matrix3& matrix);

void transposePtr(Matrix3* matrix);

#endif //ITMO_PROG_TASKS_TASK1_H
