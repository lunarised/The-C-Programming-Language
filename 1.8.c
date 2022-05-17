#include <stdio.h>
#include <stdlib.h>

int main() {
  int blanks, tabs, newlines, c;

  blanks = 0;
  tabs = 0;
  newlines = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++blanks;
    } else if (c == '\t') {
      ++tabs;
    } else if (c == '\n') {
      ++newlines;
    }
  }
  printf("blanks %d, tabs %d newlines %d\n", blanks, tabs, newlines);
  return EXIT_SUCCESS;
}
