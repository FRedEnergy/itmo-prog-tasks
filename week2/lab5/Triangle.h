#ifndef ITMO_PROG_TASKS_TRIANGLE_H
#define ITMO_PROG_TASKS_TRIANGLE_H


#include "BaseCObject.h"
#include "CVector2D.h"
#include "IDialogInitable.h"
#include "IGeoFig.h"
#include "IPhysObject.h"
#include "IPrintable.h"
#include <stdio.h>
#include <iostream>
#include <cmath>

class Triangle: public BaseCObject,
                public IDialogInitiable,
                public IGeoFig,
                public IPhysObject,
                public IPrintable {
private:
    double side;
    CVector2D pos;

public:

    Triangle(): side(0), pos(CVector2D(0, 0)){}

    Triangle(double side, const CVector2D &pos) : side(side), pos(pos) {}

    virtual const char *classname() {
        return "triangle";
    }

    virtual unsigned int size() {
        return sizeof(Triangle);
    }

    virtual void initFromDialog() {
        std::cout << "Enter triangle side length: " << std::endl;
        std::cin >> side;
        std::cout << "Enter triangle center (x, y): " << std::endl;
        std::cin >> pos.x >> pos.y;
    }

    virtual double square() {
        return side * side * sqrt(3.0) / 4.0;
    }

    virtual double perimeter() {
        return 3.0 * side;
    }

    virtual double mass() {
        return 0.5 * square();
    }

    virtual CVector2D position() {
        return pos;
    }

    virtual bool operator==(IPhysObject &ob) {
        if(ob.mass() != this->mass())
            return false;
        CVector2D obPos = ob.position();
        CVector2D pos = position();
        return obPos.x != pos.x && obPos.y != obPos.y;
    }

    virtual bool operator<(IPhysObject &ob) {
        return mass() < ob.mass();
    }

    virtual void draw() {
        CVector2D pos = position();
        std::cout << "Triangle with side " << side << " at {" << pos.x << ", " << pos.y << "}" << std::endl;
    }

};


#endif //ITMO_PROG_TASKS_TRIANGLE_H
