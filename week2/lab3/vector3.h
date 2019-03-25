#ifndef ITMO_PROG_TASKS_VECTOR3_H
#define ITMO_PROG_TASKS_VECTOR3_H

class vector3 {

private :
    double m_x, m_y, m_z;

public:

    vector3(double x, double y, double z){
        this->m_x = x;
        this->m_y = y;
        this->m_z = z;
    }

    vector3 operator+(vector3 other);

    double len();

    double angle(vector3 other);

    void print();

    double getX();
    double getY();
    double getZ();
};

#endif
