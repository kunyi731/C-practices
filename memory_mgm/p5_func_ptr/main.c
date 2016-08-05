#include <stdio.h>

typedef void (*Handle1) (int);
typedef int  (*Handle2) (int);

void foreach(int *begin, int *end, Handle1 fn )
{
  while (begin != end)
  {
    fn(*begin);
    ++begin;
  }
}

void print(int i)
{
  printf("%d ", i);
}

void transform(int *begin, int *end, Handle2 fn)
{
  while (begin != end)
  {
    *begin = fn(*begin);
    ++begin;
  }
}

int timesTwo(int i)
{
  return 2 * i;
}

int main()
{
    int a[5];
    int i;
    
    for (i = 0; i < 5; ++i) {
        a[i] = i + i;
    }
    
    //use foreach and print here
    

    foreach(a, a + 5, print);
    
    transform(a, a + 5, timesTwo);

    foreach(a, a+5, print);


    printf("\n");
}
