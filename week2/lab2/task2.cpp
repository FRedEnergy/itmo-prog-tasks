#include "task2.h"
#include <iostream>

using namespace std;

Complex operator*(Complex lhs, double value) {
    return Complex{lhs.real * value, lhs.imagin * value};
}

Complex operator+(Complex lhs, Complex rhs) {
    return Complex{lhs.real + rhs.real, lhs.imagin + lhs.real};
}

Complex operator*(Complex lhs, Complex rhs) {
    return Complex{lhs.real * rhs.real - lhs.imagin * rhs.imagin, lhs.real * rhs.imagin + rhs.real * lhs.imagin};
}

Complex::operator double() {
    return sqrt(real * real + imagin * imagin);
}

void operator<<(StackStruct &stack, int value) {
    if(stack.head == 99)
        return;

    stack.data[++stack.head] = value;
}

void operator>>(StackStruct &stack, int *out) {
    if(stack.head == 0)
        return;

    *out = stack.data[stack.head--];
}

void operator>>(StackStruct &stack, std::ostream& out) {
    int value = 0;
    stack >> &value;
    out << value;
}

void StackStruct::print() {
    for(int i = 0; i <= head; i++)
        cout << data[i] << ", ";
    cout << endl;
}

int main(){
    //#1
    //multiplication by number
    Complex number{1, 1};

    number = number * 2.0;
    cout << "number * 2.0 = " << number.real << " + " << number.imagin << "i" << endl;
    number = operator*(number, 2);
    cout << "number * 2.0 = " << number.real << " + " << number.imagin << "i" << endl;

    //sum
    Complex a{2, 2}, b{4, 4};
    Complex sum = a + b;
    cout << "a + b = " << sum.real << " + " << sum.imagin << "i" << endl;
    sum = operator+(a, b);
    cout << "a + b = " << sum.real << " + " << sum.imagin << "i" << endl;

    //multiplication
    Complex product = a * b;
    cout << "a * b = " << product.real << " + " << product.imagin << "i" << endl;
    product = operator*(a, b);
    cout << "a * b = " << product.real << " + " << product.imagin << "i" << endl;

    //double conversion
    cout << "(double)a = " << (double)a << endl;
    cout << "double(a) = " << double(a) << endl;

    //#5
    StackStruct stack;
    stack << 2;
    operator<<(stack, 10);
    stack << 1;
    cout << "After inserting 2, 10, 1 stack is: ";
    stack.print();

    cout << "Extracting top value from stack: ";
    stack >> cout;
    cout << endl;

    cout << "Extracting one more value from stack: ";
    operator>>(stack, cout);
    cout << endl;

    cout << "Stack after extraction: ";
    stack.print();

    return 0;
}
