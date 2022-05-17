#include <stdio.h>
#include <stdlib.h>

int fToC(int f) {
  int c;
  c = (5 / 9) * (f - 32);
  return c;
}
int cToF(int c) {
  int f;
  f = ((9.0 / 5.0) * c) + 32.0;
  return f;
}

int main() {
  printf("%d\n", fToC(212));
  printf("%d\n", cToF(32));
  return EXIT_SUCCESS;
}