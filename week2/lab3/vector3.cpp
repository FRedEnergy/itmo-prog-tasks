#include "vector3.h"
#include <cmath>
#include <iostream>
#include "polynom.h"

using namespace std;

double vector3::getX() {
    return m_x;
}

double vector3::getY() {
    return m_y;
}

double vector3::getZ() {
    return m_z;
}

vector3 vector3::operator+(vector3 other) {
    return vector3(getX() + other.getX(), getY() + other.getY(), getZ() + other.getZ());
}

double vector3::len() {
    return sqrt(getX() * getX() + getY() * getY() + getZ() * getZ());
}

double vector3::angle(vector3 other) {
    double dot = getX() * other.getX() + getY() * other.getY() + getZ() * other.getZ();
    double len1 = len();
    double len2 = other.len();
    return acos(abs(dot / (len1 * len2)));
}

void vector3::print() {
    cout << "(" << getX() << ", " << getY() << ", " << getZ() << ")" << endl;
}

int main(){
    //vector
    vector3 a(2, 2, 2);
    vector3 b(2, 1, 1);

    cout << "a + b = ";
    (a + b).print();

    cout << "len of a = " << a.len() << endl;
    cout << "a^b = " << a.angle(b) << endl;

    cout << endl;

    //polynom
    polynom f(3, 8, -2);

    cout << "f = ";
    f.print();

    cout << "f(10) = " << f.eval(10.0) << endl;
    cout << "f has " << f.count_root() << " roots" << endl;

    double t0 = 0, t1 = 0;
    f.get_roots(&t0, &t1);
    cout << "roots of f: " << t0 << ", " << t1 << endl;

    double min = 0, max = 0;
    f.get_min_max(&min, &max);
    cout << "min of f = " << min << ", max of f = " << max << endl;



    return 0;
}
