#include <stdio.h>
#include <math.h>  // Include for using fabs()

int main() {
    double number, guess, tolerance, previous_guess;
    int iterations = 0;

    // Input the number and tolerance for convergence
    printf("Enter the number to find the square root of: ");
    scanf("%lf", &number);

    if (number <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tolerance);

    // Initialize the first approximation
    guess = number / 2.0;
    previous_guess = 0.0;

    // Babylonian method
    while (fabs(guess - previous_guess) > tolerance) {  // Use fabs() for absolute difference
        previous_guess = guess;
        guess = (guess + number / guess) / 2.0;
        iterations++;
    }

    // Output the results
    printf("Number of iterations: %d\n", iterations);
    printf("Approximate square root: %.6f\n", guess);

    return 0;
}
