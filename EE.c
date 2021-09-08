#include <stdio.h>

#include "EElib.c"

int main()
{
    complex* c1 = c_init(1, 2); //1 + j2
    complex* c2 = c_init(5, 7); //5 + j7

    complex* sum = c_sum(c1,c2);
    complex* diff = c_sub(c1, c2);

    double mod1 = c_mod(c1); 
    double mod2 = c_mod(c2);
    int x = 0;

    printf("%s\n", "c1 is equal to:");
    print_c(c1);
    printf("%s\n", "c2 is equal to:");
    print_c(c2);

    printf("%s\n", "The sum of c1 and c2 is:");
    print_c(sum);
    printf("%s\n", "The diff of c1 and c2 is:");
    print_c(diff);

    printf("The modulus of c1 is: %f\n", mod1);
    printf("The modulus of c2 is: %f\n", mod2);

    polar* p1 = c_to_p(c1);
    printf("c1 in Polar is\n");
    print_p(p1);

    polar* p3 = p_init(1, 165);
    complex* c3 = p_to_c(p3);
    printf("c3 in Polar is\n");
    print_c(c3);

    polar* p4 = p_init(1, -15);
    complex* c4 = p_to_c(p4);
    printf("c4 in Polar is\n");
    print_c(c4);

    return 0;






}