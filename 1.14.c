#include <stdio.h>
#include <stdlib.h>

#define CHOP 5
int main() {

  int i, j, c, max;
  int freq[26];

  for (i = 0; i < 26; ++i) {
    freq[i] = 0;
  }
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t' || c == '\r') {
      continue;
    } else {
      if (c > 'Z') {
        c = c - 32;
      }
      if (c > 'Z' || c < 'A') {
        continue;
      }
      c = c - 65;
      freq[c] += 1;
    }
  }

  /* Get Max Value */
  max = 0;
  for (i = 0; i < 26; ++i) {
    if (freq[i] > max) {
      max = freq[i];
    }
  }
  max = max / CHOP;

  /* Chop */
  for (i = 0; i < 26; ++i) {
    freq[i] = freq[i] / CHOP;
  }

  for (i = max; i > 0; --i) {
    printf("%6d |", i * CHOP);
    for (j = 0; j < 26; j++) {
      if (freq[j] >= i) {
        printf(" * ");
      } else {
        printf("   ");
      }
    }
    printf("\n");
  }
  printf("      "
         "0+-------------------------------------------------------------------"
         "-----------\n");
  printf("        ");
  for (i = 0; i < 26; ++i) {
    printf(" %c ", i + 97);
  }
  printf("\n");
  return EXIT_SUCCESS;
}