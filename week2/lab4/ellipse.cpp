#include "ellipse.h"
#include "circle.h"
#include <cmath>
#include <cstdlib>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

double ellipse::perimeter() {
    return M_PI * (3.0 * (getA() + getB()) - sqrt((3.0 * getA() + getB()) * (getA() + 3.0 * getB())));
}

double ellipse::area() {
    return M_PI * getA() * getB();
}

bool ellipse::contains(double x, double y) {
    double d = pow((x * cos(getAngle()) - y * sin(getAngle())), 2.0) / pow(getA(), 2.0) +
            pow(x * sin(getAngle()) - y * cos(getAngle()), 2.0)/pow(getB(), 2.0);
    return d <= 1.0;
}

void ellipse::rotate(double angleRadians) {
    angle += angleRadians;
}

point* ellipse::get_n_points(int points) {
    double full_circle = M_PI * 2.0;
    double step = full_circle / points;
    auto buffer = (point*)malloc(points * sizeof(point));
    for(int i = 0; i < points; i++){
        double t = step * i;
        auto p = (point*) malloc(sizeof(point));
        p->x = getA() * cos(t) * cos(-getAngle()) - getB() * sin(t) * sin(-getAngle());
        p->y = getA() * cos(t) * sin(-getAngle()) - getB() * sin(t) * cos(-getAngle());
        buffer[i] = *p;
    }
    return buffer;
}

double ellipse::getA() {
    return m_a;
}

double ellipse::getB() {
    return m_b;
}

double ellipse::getAngle() {
    return angle;
}

void handle_ellipse_action(ellipse& l, string action){
    if(action == "perimeter"){
        cout << "Perimeter = " << l.perimeter() << endl;
    } else if(action == "area"){
        cout << "Area = " << l.area() << endl;
    } else if(action == "rotate"){
        double d;
        cin >> d;
        l.rotate(d * M_PI / 180.0);
        cout << "Rotate by " << d << " degrees" << endl;
    } else if(action == "contains"){
        double x,y;
        cin >> x >> y;
        cout << (l.contains(x, y) ? "yes" : "no") << endl;
    } else if(action == "get_points"){
        int n;
        cin >> n;
        point* p = l.get_n_points(n);
        for(int i = 0; i < n; i++)
            cout << (i + 1) << ") " << p[i].x << ", " << p[i].y << endl;
    }
}

bool ellipse::operator==(ellipse &b) {
    return getA() == b.getA() && getB() == b.getB() && getAngle() == b.getAngle();
}


void eval_ellipse(){
    double a, b;
    cin >> a >> b;

    ellipse l(a, b);

    cout << "Ellipse(" << a << ", " << b << ") initialized" << endl;

    cout << "Enter action (perimeter, area, rotate d, get_points n, contains x y)" << endl;
    while(true){
        string action;
        cin >> action;

        if(action == "exit")
            break;
        else
            handle_ellipse_action(l, action);

    }
}



void eval_circle(){
    double r;
    cin >> r;

    circle l(r);

    cout << "Circle(" << r << ") initialized" << endl;

    cout << "Enter action (sec_area a, sec_perimeter a, add_cut a b c, delete_cut, piece_area 1/2, piece_perimeter 1/2," << endl
         << "perimeter, area, rotate d, get_points n, contains x y)" << endl;
    while(true){
        string action;
        cin >> action;


        if(action == "exit")
            break;
        else if(action == "sec_area"){
            double a;
            cin >> a;
            cout << "Area of sector with angle " << a << " = " << l.sector_area(a * M_PI / 180.0) << endl;
        } else if(action == "sec_perimeter"){
            double a;
            cin >> a;
            cout << "Perimeter of sector with angle " << a << " = " << l.sector_perimeter(a * M_PI / 180.0) << endl;
        } else if(action == "add_cut"){
            double a, b, c;
            cin >> a >> b >> c;
            cout << "Added cut line " << a << "x" << " + " << b << "y" << " + " << c << " = 0" << endl;
            l.set_cut_line(a, b, c);
        } else if(action == "delete_cut"){
            cout << "Removed cut line" << endl;
            l.clear_cut_line();
        } else if(action == "piece_area"){
            int n;
            cin >> n;
            if(l.hasCutLine())
                cout << "Area of piece " << n << " = " << l.piece_area(n) << endl;
            else
                cout << "No cut line set" << endl;
        } else if(action == "piece_perimeter"){
            int n;
            cin >> n;
            if(l.hasCutLine())
                cout << "Perimeter of piece " << n << " = " << l.piece_perimeter(n) << endl;
            else
                cout << "No cut line set" << endl;
        }
        else
            handle_ellipse_action(l, action);
    }
}

int main(){

    string type;

    cin >> type;

    if(type == "ellipse"){
        eval_ellipse();
    } else if(type == "circle"){
        eval_circle();
    }

    return 0;
}
