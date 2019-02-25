#include "polynom.h"
#include <cmath>
#include <iostream>

using namespace std;

double polynom::getA() {
    return m_a;
}

double polynom::getB() {
    return m_b;
}

double polynom::getC() {
    return m_c;
}

double polynom::eval(double x) {
    return getA() * x * x + getB() * x + getC();
}

int polynom::count_root() {
    double d = getB() * getB() - 4.0 * getA() * getC();
    if(d > 0)
        return 2;
    if(d == 0)
        return 1;
    return 0;
}

void polynom::get_roots(double *t0, double* t1) {
    if(count_root() == 0)
        return;
    double d = getB() * getB() - 4.0 * getA() * getC();
    *t0 = (-getB() + sqrt(d)) / (2.0 * getA());
    *t1 = (-getB() - sqrt(d)) / (2.0 * getA());
}

void polynom::get_min_max(double *min, double *max) {
    double x0 = -getB() / (2.0 * getA());
    double y0 = eval(x0);
    if(getA() > 0) {
        *min = y0;
        *max = INFINITY;
    } else {
        *max = y0;
        *min = -INFINITY;
    }

}

void polynom::print() {
    cout << "(" << getA() << ") * x^2 + (" << getB() << ") * x + (" << getC() << ")" << endl;
}
