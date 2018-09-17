
#include <printf.h>
#include <math.h>

enum OrgType {
    ZAO,
    OOO,
    IP
};

typedef struct {
    float x, y;
} Vec;

typedef struct {
    Vec a, b, c;
} Trig;

float distance(Vec a, Vec b){
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

float calcPerimeter(Trig trig){
    float ab = distance(trig.a, trig.b);
    float bc = distance(trig.b, trig.c);
    float ca = distance(trig.b, trig.a);
    return ab + bc + ca;
}

int main(int c, char **arg){
    //sub 1
    printf("OOO = %d\n", OOO);

    //sub 2
    Trig trig = {
        {-2, -1},
        {0, 4},
        {4, -2}
    };
    float p = calcPerimeter(trig);
    printf("Perimeter of triangle = %f\n", p);

    //sub 3
    unsigned int input = 0;
    scanf("%x", &input);
    unsigned int state = 0xFFFFFF;
    state &= input & 0b11111;

    printf("Card Reader State:\n");
    printf("Enabled: %s\n", ((state & 1) > 0) ? "YES" : "NO");
    printf("SD Card: %s\n", ((state & 0b10) > 0) ? "YES" : "NO");
    printf("Compact Flash Card: %s\n", ((state & 0b100) > 0) ? "YES" : "NO");
    printf("Memory Stick: %s\n", ((state & 0b1000) > 0) ? "YES" : "NO");
}