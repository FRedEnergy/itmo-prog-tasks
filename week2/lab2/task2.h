#ifndef ITMO_PROG_TASKS_TASK2_H
#define ITMO_PROG_TASKS_TASK2_H

#include <iostream>

typedef struct {
    double real, imagin;

    operator double();

} Complex;

Complex operator*(Complex lhs, double value);
Complex operator+(Complex lhs, Complex rhs);
Complex operator*(Complex lhs, Complex rhs);

typedef struct {
    int data[100];

    int head = -1;

    void print();
} StackStruct;

void operator<<(StackStruct& stack, int value);
void operator>>(StackStruct& stack, int* out);
void operator>>(StackStruct& stack, std::ostream& out);


#endif //ITMO_PROG_TASKS_TASK2_H
