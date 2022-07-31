#include "s21_math.h"
long double s21_fmod(double x, double y) {
    int c = x / y;
    long double result = x - c * y;
    if (y == 0) {
        result = s21_asin(2);
    } else if (x < 0 && result == 0) {
        result = -result;
    } return result;
}
