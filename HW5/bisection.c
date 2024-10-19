#include <math.h>
#include "bisection.h"

double bisection(double a, double b, double (*f)(double), double tolerance, int *iterations) {
    double midpoint;
    *iterations = 0;

    while (fabs(b - a) > tolerance) {
        midpoint = (a + b) / 2.0;

        if (f(midpoint) == 0.0) {
            return midpoint;
        } else if (f(a) * f(midpoint) < 0) {
            b = midpoint;
        } else {
            a = midpoint;
        }

        (*iterations)++;
    }

    return (a + b) / 2.0;
}
