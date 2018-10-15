
#include "circle.h"
#include <math.h>

float getCirclePerimeter(Circle circle){
    return 2.0F * M_PI * circle.radius;
}

float getCircleArea(Circle circle){
    return M_PI * circle.radius * circle.radius;
}
