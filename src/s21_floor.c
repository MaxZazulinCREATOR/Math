#include "s21_math.h"
long double s21_floor(double x) {
    int result = x;
    x -= result;
    return x < 0 ? result - 1 : result;
}

