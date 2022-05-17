#include <stdio.h>
#include <stdlib.h>

/* print Fahrenheit-Celcius table
   for fahr = 0, 20, ..., 300 */

int main() {
  float celc, fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celc = lower;
  printf("Celcius \t Fahr\n");
  while (celc <= upper) {
    fahr = ((9.0 / 5.0) * celc) + 32.0;
    printf("%3.0f\t%6.1f\n", celc, fahr);
    celc = celc + step;
  }
  return EXIT_SUCCESS;
}
