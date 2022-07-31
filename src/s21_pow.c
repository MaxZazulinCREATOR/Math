#include "s21_math.h"
long double s21_pow(double base, double exp) {
    long double result;
    if (base < 0) {
        if ((long int)exp == exp) {
            if (exp > 0) {
                result = base;
                for (long int i = 0; i < (long int)exp - 1; i++)
                    result *= base;
            } else if (exp == 0) {
                result = 1;
            } else {
                result = 1 / base;
                for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
                    result /= base;
                }
            }
        } else {
            if (exp == -S21_INF) {
                if (base * (-1) < 1) {
                    result = S21_INF;
                } else if (base * (-1) == 1) {
                    result = 1;
                } else {
                    result = 0;
                }
            } else if (exp == S21_INF) {
                if (base * (-1) < 1) {
                    result = 0;
                } else if (base * (-1) == 1) {
                    result = 1;
                } else {
                    result = S21_INF;
                }
            } else {
                result = S21_NAN;
            }
        }
    } else if (base == 0) {
        if (exp == 0)
            result = 1;
        else
            result = 0;
    } else {
        if ((long int)exp == exp) {
            if (exp > 0) {
                result = base;
                for (long int i = 0; i < (long int)exp - 1; i++) {
                    result *= base;
                }
            } else if (exp == 0) {
                result = 1;
            } else {
                result = 1 / base;
                for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
                    result /= base;
                }
            }
        } else {
            result = s21_exp(exp * s21_log(base));
        }
    }
    return result;
}
