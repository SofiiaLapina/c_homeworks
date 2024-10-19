#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main() {
    float num;
    uint32_t bits;
    int sign, exponent;
    float mantissa, reconstructed;

    printf("Floating point number: ");
    scanf("%f", &num);

    bits = *(uint32_t*)&num;

    sign = (bits >> 31) ? -1 : 1;
    exponent = ((bits >> 23) & 0xFF) - 127;
    mantissa = 1.0 + (bits & 0x7FFFFF) / (float)(1 << 23);

    reconstructed = sign * mantissa * pow(2, exponent);

    printf("Sign: %c\n", sign == 1 ? '+' : '-');
    printf("Mantissa: %.5f\n", mantissa - 1.0);
    printf("Exponent: %d\n", exponent);
    printf("Reconstructed value: (%1.1f + %.5f) * 2^%d = %f\n", 1.0, mantissa - 1.0, exponent, reconstructed);

    return 0;
}