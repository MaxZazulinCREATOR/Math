#include "s21_math.h"
long double s21_tan(double x) {
    long double result;
    if (x == S21_INF || x == -S21_INF) {
        result = S21_NAN;
    } else {
        result = s21_sin(x) / s21_cos(x);
    }
    return result;
}
