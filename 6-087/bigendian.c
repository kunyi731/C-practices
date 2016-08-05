#include <stdio.h>

int main(void) {
  /* Test whether the machine is big endian or little endian */
  int *a = (int *) malloc(4); //allocate 4 bytes
  unsigned char *b;
  int i; //loop index

  printf("%d\n", sizeof(a));
  *a = 0xDEADBEEF;

  /* Use char pointer array to store addresses */
  //unsigned int arr_len = sizeof(int)/sizeof(char);
  b = (unsigned char *)a;
  
  for (i = 0; i < 4; i++) {
    printf("%x\n", *(b + i));
  }

  if (*b == 0xef) {
    printf("Machine is little endian!! \n");
  }
  else {
    printf("Machine big endian!! \n");
  }

}
