#ifndef ITMO_PROG_TASKS_HEXAGON_H
#define ITMO_PROG_TASKS_HEXAGON_H

#include "BaseCObject.h"
#include "CVector2D.h"
#include "IDialogInitable.h"
#include "IGeoFig.h"
#include "IPhysObject.h"
#include "IPrintable.h"
#include <stdio.h>
#include <iostream>
#include <cmath>

class Hexagon: public BaseCObject,
               public IDialogInitiable,
               public IGeoFig,
               public IPhysObject,
               public IPrintable {

private:

    double side;
    CVector2D pos;

public:

    Hexagon(): side(0.0), pos(CVector2D(0.0, 0.0)) {}

    Hexagon(double side, const CVector2D &pos) : side(side), pos(pos) {}

    virtual const char *classname() {
        return "hexagon";
    }

    virtual unsigned int size() {
        return sizeof(Hexagon);
    }

    virtual void initFromDialog() {
        std::cout << "Enter hexagon side: " << std::endl;
        std::cin >> side;
        std::cout << "Enter hexagon center: " << std::endl;
        std::cin >> pos.x >> pos.y;
    }

    virtual double square() {
        return 3.0 * sqrt(3.0) * side * side / 2.0;
    }

    virtual double perimeter() {
        return side * 6.0;
    }

    virtual double mass() {
        return 0.5 * square();
    }

    virtual CVector2D position() {
        return pos;
    }

    virtual bool operator==(IPhysObject &ob) {
        return false;
    }

    virtual bool operator<(IPhysObject &ob) {
        return false;
    }

    virtual void draw() {
        std::cout << "Hexagon with side " << side << " at {" << pos.x << ", " << pos.y << "}" << std::endl;
    }

};


#endif //ITMO_PROG_TASKS_HEXAGON_H
