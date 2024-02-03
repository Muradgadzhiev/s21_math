#ifndef S21_MATH
#define S21_MATH
#include <limits.h>
#include <stdio.h>
#define s21_PI 3.14159265358979323846
#define s21_NAN 0.0 / 0.0
#define s21_EPS 1e-6
#define s21_INF 1.0 / 0.0
#define s21_RAD 57.29577951308

int s21_abs(int x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_sqrt(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_fmod(double x, double y);
long double s21_sqrt(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_factorial(double x);
#endif
