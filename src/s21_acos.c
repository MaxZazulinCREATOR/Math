#include "s21_math.h"
long double s21_fucktor(double x) {
    long double n = 1;
    for (int i = 1; i < x + 1; i++) {
        n *= i;
    }
    return n;
}

long double s21_acos(double x) {
    long double preResult, result = 0; int i = 0;
    do {
        preResult = (s21_fucktor(2 * i) * s21_pow(x, 2 * i + 1))\
                                    / (s21_pow(4, i)* s21_pow(s21_fucktor(i), 2) * (2 * i + 1));
        result = result + preResult;
        i++;} while (s21_fabs(preResult) > S21_EPS);
    if (x < -1 || x > 1) {
        result = S21_NAN;
    }
    if (x > 0.9) {
        result = s21_sqrt(2*(1-x));
    } else {
        result = S21_Pi/2 - result;
    }
    return x == 1 || x == -1 ? S21_Pi/2 - S21_Pi / 2 * x : result;
}
