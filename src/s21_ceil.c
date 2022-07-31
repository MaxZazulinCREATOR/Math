#include "s21_math.h"
long double s21_ceil(double x) {
    int result = x;
    x -= result;
    return x > 0 ? result + 1 : result;
}

