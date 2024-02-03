#include "s21_math.h"

int s21_abs(int x) {
  if (x < 0)
    x = -x;
  else
    x = x;
  return x;
}
long double s21_atan(double x) {
  long double result = x;
  long double x_res = x;
  int i = 1;
  if (x == 1)
    return 0.785398163;
  if (x == -1)
    return -0.785398163;
  if (x > -1 && x < 1) {
    for (int j = 1; j < 1000; j++) {
      i = -i;
      x_res = x_res * x * x;
      result = result + i * x_res / (2 * j + 1);
    }
  } else if (x > 1)
    result = s21_PI / 2 - s21_atan(1 / x);
  else if (x < -1)
    result = -s21_PI / 2 - s21_atan(1 / x);
  return result;
}
long double s21_exp(double x) {
  long double result = 1.0;
  long double u = 1.0;
  if (x < -5.0)
    result = 0.0;
  else
    for (int i = 1; i < 1000; i++) {
      u = u * x / i;
      result = result + u;
    }
  return result;
}

long double s21_log(double x) {
  long double ln_p = 0.0;
  long double ln = 0.0;
  if (x == 0)
    ln = -s21_INF;
  else if (x == s21_INF)
    ln = s21_INF;
  else if (x < 0)
    ln = s21_NAN;
  else
    for (int i = 1; i < 32; i++) {
      ln = ln_p + 2 * (x - s21_exp(ln_p)) / (x + s21_exp(ln_p));
      ln_p = ln;
    }
  return ln;
}

long double s21_pow(double base, double exp) {
  long double pw = 1.0;
  if (base == 0) {
    if (exp == -s21_INF)
      return s21_INF;
    else if (exp == s21_INF)
      return 0.0;
  }
  if (exp == 0)
    return 1.0;
  else if ((base == s21_INF && exp == exp && exp != -s21_INF) ||
           (exp == s21_INF && base == base))
    return s21_INF;
  else if ((base == -s21_INF && exp == exp) ||
           (exp == -s21_INF && base == base))
    return 0.0;

  else if ((base != base || exp != exp) && exp != s21_INF)
    return s21_NAN;
  else if (exp == exp - s21_fmod(exp, 1) && exp > 0)
    for (int i = 0; i < exp; i++) {
      pw = pw * base;
    }
  else if (exp == exp - s21_fmod(exp, 1) && exp < 0) {
    for (int i = 0; i > exp; i--) {
      pw = pw * base;
    }
    pw = 1 / pw;
  } else if (exp == 0)
    pw = 1.0;
  else if (base == 0)
    pw = 0.0;
  else
    pw = s21_exp(exp * s21_log(base));
  return pw;
}

long double s21_sin(double x) {
  int n = x / (2 * s21_PI);
  x = x - n * 2 * s21_PI;
  long double result = x;
  double uv = x;
  for (int i = 2; i < 64; i += 2) {
    uv = (-1) * uv * x * x / (i * (i + 1));
    result = result + uv;
  }
  return result;
}

long double s21_cos(double x) {
  int n = x / (2 * s21_PI);
  x = x - n * 2 * s21_PI;
  long double result = 1;
  double uv = 1;
  for (int i = 1; i < 64; i += 2) {
    uv = (-1) * uv * x * x / (i * (i + 1));
    result = result + uv;
  }
  return result;
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double s21_fmod(double x, double y) {
  long double res = 0;
  int n = s21_abs(x / y);
  if (x == s21_INF || x == -s21_INF)
    res = s21_NAN;
  else if (y == s21_INF || y == -s21_INF)
    res = x;
  else if (y == 0 && y != s21_INF)
    res = s21_NAN;

  else if (x * y < 0 && y != s21_INF)
    res = x + n * y;
  else if (y != s21_INF)
    res = x - n * y;
  return res;
}

long double s21_sqrt(double x) { return s21_pow(x, 0.5); }

long double s21_fabs(double x) {
  if (x < 0)
    x = -x;
  else
    x = x;
  return x;
}

long double s21_floor(double x) {
  if (x != x)
    return s21_NAN;
  if (x == s21_INF || x == -s21_INF)
    return x;
  long int a = x;

  if ((a < 0.0 || (a == 0 && x < 0)) && a != x) {
    a = a - 1;
  }
  return a;
}

long double s21_ceil(double x) {
  long double a = x;
  unsigned long int b = x;
  signed long int c = x;
  if (x == s21_INF || x == -s21_INF) {
    a = x;
  } else if (a != b && a > 0) {
    a = b;
    a = a + 1;
  } else if (a < 0 && a != b) {
    a = c;
  }
  return a;
}

long double s21_asin(double x) {
  double res = s21_NAN;
  if (x > 1 || x < -1)
    res = s21_NAN;
  if (x == 1 || x == -1)
    res = s21_PI / (2 * x);
  if (x > -1 && x < 1)
    res = s21_atan((x) / s21_sqrt(1 - x * x));
  return res;
}

long double s21_acos(double x) {
  long double res = s21_NAN;
  if (x < 1 && x >= 0)
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  if (x > -1 && x < 0)
    res = s21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  if (x < -1 || x > 1)
    res = s21_NAN;
  if (x == 1)
    res = 0;
  if (x == -1)
    res = s21_PI;
  return res;
}
long double s21_factorial(double x) {
  long double res = 0;
  if (x == 1 || x == 0)
    res = 1;
  else if (x < 0)
    res = s21_INF;
  else
    res = x * s21_factorial(x - 1);
  return res;
}
