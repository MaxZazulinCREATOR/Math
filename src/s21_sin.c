#include "s21_math.h"
long double s21_sin(double x) {
    x = s21_fmod(x, 2 * S21_Pi);
    double result = x, sum = 0.0;
    int i = 1;
    while (s21_fabs(result) > S21_EPS) {
        sum += result;
        result *= -x * x / (2 * i * (2 * i + 1));
        i++;
    }
    return sum;
}
