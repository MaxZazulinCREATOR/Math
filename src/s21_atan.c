#include "s21_math.h"
long double atan_range(double x) {
    long double result = x, temp = x, i = 1;
    while (s21_fabs(result) > S21_EPS) {
        result *= -1 * s21_pow(x, 2) * (2 * i - 1) / (2 * i + 1);
        i += 1;
        temp += result;
    }
    return temp;
}

long double s21_atan(double x) {
    long double temp = 0;
    if ((x >= (double)LLONG_MAX || x <= (double)LLONG_MIN) || x != x) temp = x;
    else if (x == 0)
        temp = 0;
    else if (x < 1 && x > -1)
        temp = atan_range(x);
    else if (x == 1)
        temp = S21_Pi / 4;
    else if (x == -1)
        temp = -S21_Pi / 4;
    else if (x > 1)
        temp = S21_Pi / 2 - atan_range(1 / x);
    else if (x < -1)
        temp = -S21_Pi / 2 - atan_range(1 / x);
    return temp;
}
