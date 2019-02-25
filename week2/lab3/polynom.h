
#ifndef ITMO_PROG_TASKS_POLYNOM_H
#define ITMO_PROG_TASKS_POLYNOM_H


class polynom {
private:
    double m_a, m_b, m_c;

public:
    polynom(double a, double b, double c){
        this->m_a = a;
        this->m_b = b;
        this->m_c = c;
    }

    double getA();
    double getB();
    double getC();

    double eval(double x);

    int count_root();

    void get_roots(double* t0, double* t2);

    void get_min_max(double* min, double* max);

    void print();

};


#endif //ITMO_PROG_TASKS_POLYNOM_H
