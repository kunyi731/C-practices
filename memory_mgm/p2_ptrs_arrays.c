#include <stdio.h>

void printRange(int *begin, int *end) {
  while (begin != end) {
    printf("%d ", *begin);
    begin++;
  }
  printf("\n");
}


int main(void) {
  int arr[10];
  int *ptr;

  ptr = arr;

  int i;
  for (i = 0; i < 10; ++i) {
    *ptr = i + i;
    ptr++;
  }


  //ptr value at one past the end of the arr
  int *end = arr + 10;
  int *it = arr;

  while (it != end) {
    printf("%d ", *it);
    it ++;
  }
  printf("\n");

  printRange(&arr[0], end);
}
