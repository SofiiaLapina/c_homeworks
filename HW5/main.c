#include <stdio.h>
#include <math.h>
#include "bisection.h"

double function(double x) {
    extern double coeff_a;
    extern double coeff_b;
    return coeff_a * sin(x) - coeff_b * cos(x);
}

double coeff_a;
double coeff_b;

int main() {
    double a, b, tolerance, root;
    int iterations;

    printf("Enter the value of coefficient a: ");
    scanf("%lf", &coeff_a);
    printf("Enter the value of coefficient b: ");
    scanf("%lf", &coeff_b);
    printf("Enter the left boundary (a): ");
    scanf("%lf", &a);
    printf("Enter the right boundary (b): ");
    scanf("%lf", &b);
    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);

    root = bisection(a, b, function, tolerance, &iterations);

    printf("Root found at x = %.6f\n", root);
    printf("Number of iterations: %d\n", iterations);

    return 0;
}
