
#ifndef ITMO_PROG_TASKS_ELLIPSE_H
#define ITMO_PROG_TASKS_ELLIPSE_H

typedef struct {
    double x, y;
} point;
class ellipse {
protected:
    double m_a, m_b;
    double angle = 0.0;

public:

    ellipse(double a, double b){
        this->m_a = a;
        this->m_b = b;
    }


    ellipse(ellipse& copy){
        this->m_a = copy.m_a;
        this->m_b = copy.m_a;
        this->angle = copy.angle;
    }

    double perimeter();
    double area();
    bool contains(double x, double y);

    virtual void rotate(double angleRadians);

    point* get_n_points(int points);

    double getA();
    double getB();
    double getAngle();

    bool operator==(ellipse& b);

};


#endif //ITMO_PROG_TASKS_ELLIPSE_H
