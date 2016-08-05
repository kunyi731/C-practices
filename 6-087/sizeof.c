#include <stdio.h>

/* Test of the sizeof() macro */

int main(void) {
  int a = 7;
  char b = '7';
  char c[] = "7";

  printf("size of int 7 is %d bytes\n", sizeof(a));
  printf("size of \"7\" is %d bytes\n", sizeof(c));
  printf("size of '7' is %d bytes\n", sizeof(b));
  return 0;
}
