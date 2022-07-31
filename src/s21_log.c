#include "s21_math.h"
long double s21_log(double x) {
    int ex_pow = 0;
    double result = 0;
    double compare = 0;
    if (x == 1) {
        result = 0;
    } else if (x == 0) {
        result = -1/S21_INF;
    } else if (x < 0) {
        result = 0;
    } else {
        for (; x >= S21_EXP; x /= S21_EXP, ex_pow++) continue;
        int i;
        for (i = 0; i < 100; i++) {
            compare = result;
            result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
        }
    }
    return (result + ex_pow);
}
