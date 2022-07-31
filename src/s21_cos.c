#include "s21_math.h"
long double s21_cos(double x) {
    long double rcos;
    long double rcos2;
        rcos = s21_sqrt(1 - s21_pow(s21_sin(x), 2));
        rcos2 = (rcos * s21_pow(10, 16)) / s21_pow(10, 16);
    while (x > (S21_Pi * 2)) {
        x = s21_fmod(x,  (S21_Pi * 2));
    }
    while (x < (-S21_Pi * 2)) {
        x = s21_fmod(x,  (S21_Pi * 2));
    }
    if ( s21_fabs(x) > S21_Pi/2 && s21_fabs(x) <= 3*S21_Pi/2 ) {
        rcos2 *= -1;}
    return rcos2;
}
