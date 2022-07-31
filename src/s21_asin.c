#include "s21_math.h"
long double s21_fuckt(double x) {
    long double n = 1;
    for (int i = 1; i < x + 1; i++) {
        n *= i;
    }
    return n;
}
long double s21_asin(double x) {
    long double preResult, result = 0; int i = 0;
    do {
        preResult = ((s21_fuckt(2 * i)*s21_pow(x, 2*i+1)))\
                                        /(s21_pow(4, i)* s21_pow(s21_fuckt(i), 2)*(2*i + 1));
        result = result + preResult;
        i++;} while (s21_fabs(preResult) > 1e-17);
    if (x < -1 || x > 1) {
        result = S21_NAN;
    }
    if (x > 0.9) {
        result = S21_Pi/2 - s21_sqrt(2*(1-x));
    }
    return x == 1 || x == -1 ? S21_Pi/2 * x : result;
}
