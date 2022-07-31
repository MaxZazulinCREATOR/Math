#include "s21_math.h"
long double s21_exp(double x) {
    long int i = 1;
    long double result = 1;
    long double x1 = x;
    long double fac = 1;
    if (x > 709.7827) {
        result = S21_INF;
    } else if (x < -37.534508668464679) {
        result = 0.0;
    } else {
        while (s21_fabs(x1/fac) > S21_EPS / 10) {
            result += x1 / fac;
            x1 *= x;
            fac *= (i + 1);
            ++i;
        }
    }
    return result;
}
