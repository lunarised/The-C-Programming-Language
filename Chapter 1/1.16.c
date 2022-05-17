#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 30
int getLine(char line[], int maxLine);
void copy(char to[], char from[]);

int getLine(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}

int main() {
  int len, max, getMore, prevMax;
  char line[MAXLINE];
  char longest[MAXLINE];
  char temp[MAXLINE];
  max = 0;
  getMore = 0;
  prevMax = 0;
  while ((len = getLine(line, MAXLINE)) > 0) {

    if (line[len - 1] != '\n') {
      if (getMore == 0) {
        copy(temp, line);
      }
      prevMax += len;
      getMore = 1;

    } else {
      if (getMore == 1) {
        if (max < prevMax + len) {
          max = prevMax + len;
          copy(longest, temp);
          longest[MAXLINE - 2] = '\n';
        }
        getMore = 0;
      } else if (max < len) {
        max = len;
        copy(longest, line);
      }
      prevMax = 0;
    }
  }

  if (max > 0) {
    printf("The longest string is %d characters: %s", max, longest);
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}