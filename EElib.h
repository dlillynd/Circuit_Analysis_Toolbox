#include <stdlib.h>


typedef struct complex 
{
    double x;
    double y;
} complex;

typedef struct polar
{
    double r;
    double angle;
} polar;

typedef struct waveform
{
    double magnitude;
    double omega;
    double theta;
} waveform;

typedef struct element
{
    double value;
    char* units;
} element;

typedef struct circuit
{
    int num_nodes;
    char** branches;
    element* elements;
    char* element_locations;

} circuit;


//initializes a complex number with a value of 0 + j0
complex* c_base_init();

//initializes a complex number with a given value
complex* c_init(float x, float y);

//initializes a polar number with a value of 0<0
polar* p_base_init();

//initializes a polar number with a value of r<angle
polar* p_init(double r, double angle);

//returns the sum of two complex numbers
complex* c_sum(complex* a, complex* b);

//returns the difference of two complex numbers
complex* c_sub(complex* a, complex* b);

complex* c_mult(complex*a, complex* b);

//returns the modulus of a complex number
double c_mod(complex* a);

complex* p_to_c(polar* p);

polar* c_to_p(complex* a);

//prints a complex number to the screen
void print_c(complex* a);

//prints a polar number to the screen
void print_p(polar* p);

//prints a waveform to the screen
void print_w(waveform* w);
