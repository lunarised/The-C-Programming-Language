#include <stdio.h>
#include <stdlib.h>
int main() {
  int blanks, c;

  blanks = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (blanks == 0) {
        ++blanks;
        putchar(' ');
      }
    } else {
      blanks = 0;
      putchar(c);
    }
  }
  return EXIT_SUCCESS;
}
