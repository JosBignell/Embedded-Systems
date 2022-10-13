#include "mbed.h"
#include "Complex_C.hpp"
#include <cmath>

ComplexNumber_C complexAdd(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;
    y.real += b.real;
    y.imag += b.imag;
    return y;
}

void complexDisplay(const char *strName, const ComplexNumber_C u) {
    printf("%s = %f + j%f\n", strName, u.real, u.imag);
}

ComplexNumber_C complexConjugate(const ComplexNumber_C a) {
    ComplexNumber_C y = a;
    y.imag = -a.imag;
    return y;
}

ComplexNumber_C complexNegate(const ComplexNumber_C a) {
    ComplexNumber_C y = a;
    y.real = -a.real;
    y.imag = -a.imag;
    return y;
}

ComplexNumber_C complexSubtract(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;
    y.real -= b.real;
    y.imag -= b.imag;
    return y;
}

//double complexMagnitude(const ComplexNumber_C a) {
//    ComplexNumber_C y;
//    double p;
//    y.real = a.real * a.real;
//    y.imag = a.imag * a.imag;

//    p = sqrt(y.real + y.imag);

//    return p;
//}

ComplexNumber_C complexMultiply(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;
    y.real = (a.real * b.real) + ((a.imag * b.imag) * -1);
    y.imag = (a.imag * b.real) + (a.real * b.imag);
    return y;
}

ComplexNumber_C complexDivide(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;
    y.real = ((a.real * b.real) + (a.imag * b.imag))/((b.real * b.real) + (b.imag * b.imag));
    y.imag = ((a.imag * b.real) - (a.real * b.imag))/((b.real * b.real) + (b.imag * b.imag));
    return y;
}
