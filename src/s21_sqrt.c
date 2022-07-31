#include "s21_math.h"
long double s21_sqrt(double x) {
    long double result = 0;
    if (x < 0) {
        result = -S21_NAN;
    } else if (S21_NAN == x) {
        result = S21_NAN;
    } else if (S21_INF == x || x <= S21_EPS) {
        result = x;
    } else {
        result = s21_exp(s21_log(x) / 2.);
    }
    return result;
}
