#include "circle.h"
#include <cmath>

double circle::sector_area(double sector_angle) {
    return M_PI * getRadius() * getRadius() / (2.0 * M_PI) * sector_angle;
}

double circle::sector_perimeter(double sector_angle) {
    return 2.0 * M_PI * getRadius() / (2.0 * M_PI) * sector_angle + getRadius() * 2.0;
}

void circle::set_cut_line(double line_a, double line_b, double line_c) {
    m_line_a = line_a;
    m_line_b = line_b;
    m_line_c = line_c;
    has_cut_line = true;
}

void circle::clear_cut_line() {
    has_cut_line = false;
}

double circle::piece_perimeter(int piece) {
    if(!has_cut_line)
        return -1.0;

    double A = getLineA();
    double B = getLineB();
    double C = getLineC();
    double R = getRadius();
    double A2 = A * A;
    double B2 = B * B;
    double C2 = C * C;
    double d = pow(2.0 * A * C / B2, 2.0) - 4.0 * (A2 / B2 + 1.0) * (C2 / B2 - R * R);
    if(d < 0.0){
        return 0.0;
    } else if(d == 0.0){
        if(piece != 2){
            return 0.0;
        } else {
            return 2.0 * M_PI;
        }
    } else {
        double x1 = (2 * (-A/B) * (C/B) + sqrt(d)) / 2.0 * (1.0 - A / B);
        double x2 = (2 * (-A/B) * (C/B) - sqrt(d)) / 2.0 * (1.0 - A / B);
        double y1 = -A * x1 / B - C / B;
        double y2 = -A * x2 / B - C / B;
        double a1 = atan2(y1, x1);
        double a2 = atan2(y2, x2);
        double a;
        if(piece == 1){
            a = abs(a1 - a2);
        } else if(piece == 2){
            a = 2.0 * M_PI - abs(a1 - a2);
        } else return 0.0;
        return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0)) + sector_perimeter(a);
    }
}

double circle::piece_area(int piece) {
    if(!has_cut_line)
        return -1.0;

    double A = getLineA();
    double B = getLineB();
    double C = getLineC();
    double R = getRadius();
    double A2 = A * A;
    double B2 = B * B;
    double C2 = C * C;
    double d = pow(2.0 * A * C / B2, 2.0) - 4.0 * (A2 / B2 + 1.0) * (C2 / B2 - R * R);
    if(d < 0.0){
        return 0.0;
    } else if(d == 0.0){
        if(piece != 2){
            return 0.0;
        } else {
            return M_PI * getRadius() * getRadius();
        }
    } else {
        double x1 = (2 * (-A/B) * (C/B) + sqrt(d)) / 2.0 * (1.0 - A / B);
        double x2 = (2 * (-A/B) * (C/B) - sqrt(d)) / 2.0 * (1.0 - A / B);
        double y1 = -getLineA() * x1 / getLineB() - getLineC() / getLineB();
        double y2 = -getLineA() * x2 / getLineB() - getLineC() / getLineB();
        double a1 = atan2(y1, x1);
        double a2 = atan2(y2, x2);
        double a;
        if(piece == 1){
            a = abs(a1 - a2);
        } else if(piece == 2){
            a = 2.0 * M_PI - abs(a1 - a2);
        } else return 0.0;

        // S = sector_area - triangle_area

        double sa = sector_area(a);
        double b = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
        double ta = 0.5 * b * sqrt(getRadius() * getRadius() - b * b / 4.0);

        return sa - ta;
    }
}

bool circle::operator==(circle &b) {
    return getRadius() == b.getRadius();
}

bool circle::hasCutLine() {
    return has_cut_line;
}

double circle::getRadius() {
    return getA();
}

double circle::getLineA() {
    return m_line_a;
}

double circle::getLineB() {
    return m_line_b;
}

double circle::getLineC() {
    return m_line_c;
}
