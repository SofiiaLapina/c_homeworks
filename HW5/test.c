#include <stdio.h>  
#include <assert.h>
#include <math.h>
#include "bisection.h"


double coeff_a;
double coeff_b;

double test_function(double x) {
    return coeff_a * sin(x) - coeff_b * cos(x);
}

void test_bisection() {
    double root;
    int iterations;

    coeff_a = 1.0;
    coeff_b = 1.0;

    root = bisection(0, 2, test_function, 0.0001, &iterations);
    assert(fabs(test_function(root)) < 0.0001);  

    assert(iterations > 0);

    printf("Test passed for a = %.2f, b = %.2f\n", coeff_a, coeff_b);
}

int main() {
    test_bisection();
    return 0;
}
