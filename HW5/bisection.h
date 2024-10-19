#ifndef BISECTION_H
#define BISECTION_H

double bisection(double a, double b, double (*f)(double), double tolerance, int *iterations);

#endif
