#include <stdio.h>
#include "Array.h"
 
void print(int * begin, int * end)
{
    while (begin != end) {
        printf("%d ", *begin);
        ++begin;
    }
    printf("\n");
}
 
int main()
{
    Array* arr = ArrayAlloc(10);
    int *it = NULL;
    int i = 0;
    int size = 0;
    
    it = Array_begin(arr);
    size = Array_size(arr);
 
    for (i = 0; i < size; ++i) {
        it[i] = i + i;
    }
    
    print(Array_begin(arr), Array_end(arr));
    
    // This will grow the array because we are setting an
    // index that is larger than the last index
    Array_set(arr, size, 42);
    
    print(Array_begin(arr), Array_end(arr));
 
    // Need to make sure and free the memory allocated
    ArrayFree(arr);
}
