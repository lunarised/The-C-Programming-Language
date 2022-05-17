#include <stdio.h>
#include <stdlib.h>
#define IN 1
#define OUT 0

int main() {

  int i, j, c, state, cc, max;
  int lengths[11];
  state = OUT;
  cc = 0;
  for (i = 0; i < 11; ++i) {
    lengths[i] = 0;
  }
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t') {
      if (state == IN) {
        if (cc > 10) {
          lengths[10] += 1;
        } else {
          lengths[cc - 1] += 1;
        }

        cc = 0;
      }
      state = OUT;
    } else if (state == OUT) {
      state = IN;
    }
    if (state == IN) {
      cc++;
    }
  }

  /* Get Max Value */
  max = 0;
  for (i = 0; i < 11; ++i) {
    if (lengths[i] > max) {
      max = lengths[i];
    }
  }
  for (i = max; i > 0; --i) {
    printf("%6d |", i);
    for (j = 0; j < 11; j++) {
      if (lengths[j] >= i) {
        printf("  *  ");
      } else {
        printf("     ");
      }
    }
    printf("\n");
  }
  printf("       +__________________________________________________\n");
  printf("      ");
  for (i = 0; i < 10; ++i) {
    printf("  %3d", i + 1);
  }
  printf("   >10\n");
  return EXIT_SUCCESS;
}