#include <stdlib.h>
#include <math.h>

#include "EElib.h"



complex* c_base_init() {
    complex* c = malloc(sizeof(complex));
    c->x = 0;
    c->y = 0;

    return c;
}

complex* c_init(float x, float y) {
    complex* c = malloc(sizeof(complex));
    c->x = x;
    c->y = y;

    return c;
}

polar* p_base_init() {
    polar* p = malloc(sizeof(polar));
    p->r = 0;
    p->angle = 0;

    return p;
}

polar* p_init(double r, double angle) {
    polar* p = malloc(sizeof(polar));
    p->r = r;
    p->angle = angle;
    return p;
}


complex* c_sum(complex* a, complex* b){
    complex* c = malloc(sizeof(complex));
    c->x = a->x + b->x;
    c->y = a->y + b->y;

    return c;
}

complex* c_sub(complex* a, complex* b){
    complex* c = malloc(sizeof(complex));
    c->x = a->x - b->x;
    c->y = a->y - b->y;

    return c;
}

complex* c_mult(complex*a, complex* b){
    complex* c = malloc(sizeof(complex));
    c->x = (a->x * b->x) + (a->y * b->y)*-1;
    c->y = (a->x * b->y) + (a->y * b->x);

    return c;
}

double c_mod(complex* a){
    double x = pow(a->x, 2);
    double y = pow(a->y, 2);

    return sqrt(x+y);

}


complex* p_to_c(polar* p)
{
    complex* c = malloc(sizeof(complex));
    c->x = p->r*cos(p->angle);
    c->y = p->r*sin(p->angle);

    return c;

}

polar* c_to_p(complex* a){
    polar *p = malloc(sizeof(polar));
    p->r = c_mod(a);
    if (a->x >= 0)
    {
        p->angle = atan(a->y/a->x)*(180/3.1415);
        return p;
    }
    p->angle = atan(a->y/a->x)*(180/3.1415) + 180;
    return p;
}



void print_c(complex* a){
    if (a->y > 0)
    {
        printf("%f%s%f\n", a->x, " + j", a->y);
        return;
    }
    printf("%f%s%f\n", a->x, " - j", fabs(a->y));
    return;
}

void print_p(polar* a){
    printf("%f%s%f\n", a->r, "<", a->angle);
} 

void print_w(waveform* w){
    printf("%f%s%f%s%f", w->magnitude, "cos(", w->omega/3.1415, "pi*t + ", w->theta);
}