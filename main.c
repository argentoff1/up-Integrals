#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


double InFunction(double x) {
  return tan(sin(x));
}

double Integral(double a, double b, int n) {
  double result = 0, h = (b - a) / n;
  for(double i = a; i <= b; i+=h) {
    result += InFunction(i - h / 2);
  }

  result *= h;
  return result;
}

double Sompson(double a, double b, int n)
{
    double h = (b - a) / n;
    double result = InFunction(a);
    result = result + InFunction(a + n * h);
    for(int i = 1; i < n; i = i + 2)
    {
        result = result + InFunction(a + h * i) * 4;
    }
    for(int i = 2; i < n; i = i + 2)
    {
        result = result + InFunction(a + h * i) * 2;
    }
    return result * h / 3;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double b = Integral(1.0, 2.2, 16);
    double q = Sompson(1.0, 2.2, 16);
    printf("Метод прямоугольников: %.3f\nМетод симпсона %.3f", b, q);
}
