#include <iostream>
#include <cmath>

double f(double x) {
  // Пример функции: x^3 - 3x + 2
  return (pow(2, x) - (2 * pow(x, 2)) + 1);
}

double goldenRatioMethod(double a, double b, double eps) {
  double phi = (1 + sqrt(5)) / 2; // Число золотого сечения

  while (b - a > eps) {
    double x1 = b - (b - a) / phi;
    double x2 = a + (b - a) / phi;

    double fx1 = f(x1);
    double fx2 = f(x2);

    if (fx1 * fx2 < 0) {
      b = x2;
    } else {
      a = x1;
    }
  }

  return (a + b) / 2;
}

int main() {
  double a = 0; // Левая граница
  double b = 2; // Правая граница
  double eps = 1e-6; // Точность

  double root = goldenRatioMethod(a, b, eps);
  std::cout << "Корень уравнения методом золотого сечения: " << root << std::endl;

  return 0;
}
