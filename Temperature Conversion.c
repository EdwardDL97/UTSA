#include <stdio.h>

double CalculateCelsius(double Fahrenheit){
  double c;
c = (Fahrenheit - 32) * 5 / 9;
return c;
}

double CalculateKelvin(double Celsius){
  double k;
  k = Celsius + 273.15;
  return k;
}


int main( int argc, char *argv[] ){
double  x;
double cel;
double kel;

scanf("%lf", &x);
printf("%lf\n", x);

cel = CalculateCelsius(x);
printf("%lf\n", cel);

kel = CalculateKelvin(cel);
printf("%lf", kel);
return 0;
}
