#ifndef ITMO_PROG_TASKS_CIRCLE_H
#define ITMO_PROG_TASKS_CIRCLE_H


#include "ellipse.h"

class circle: public ellipse {

private:

    double m_line_a = 0.0, m_line_b = 0.0, m_line_c = 0.0;
    bool has_cut_line = false;

public:

    circle(double radius): ellipse(radius, radius) { }

    circle(circle& copy): ellipse(copy){ }

    double sector_area(double sector_angle);
    double sector_perimeter(double sector_angle);

    void set_cut_line(double line_a, double line_b, double line_c);
    void clear_cut_line();

    double piece_area(int piece);
    double piece_perimeter(int piece);

    double getRadius();
    double getLineA();
    double getLineB();
    double getLineC();

    bool hasCutLine();

    bool operator==(circle& c);
};


#endif //ITMO_PROG_TASKS_CIRCLE_H
