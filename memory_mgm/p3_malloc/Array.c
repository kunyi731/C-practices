#include <stdlib.h>
#include <stdio.h>
 
typedef struct
{
    int m_size;
    int * m_data;
} Array;
 
Array* ArrayAlloc(int size)
{
    // allocate memory for the Array stucture (use malloc)
    Array* ret = malloc(sizeof(Array));
    if (ret == NULL)
    {
      printf("Not enough memory for Array struct");
    }
    ret->m_size = size;
    // allocate memory for the growable array (use malloc)
    ret->m_data = malloc(size * sizeof(int));
    if (ret->m_data == NULL)
    {
      printf("Not enough memory for data");
    }
    return ret;
}
 
void ArrayFree(Array* array)
{
    // free up both the memory for the array
    // and the memory for the Array structure
    free(array->m_data);
    free(array);
}
 
void Array_set(Array* array, int index, int value)
{
    if (index >= array->m_size) {
        int newSize = array->m_size * 1.5;
        if (newSize <= index) { newSize = index + 1; }
        // allocate more memory (use realloc)
        array->m_data = (int *) realloc(array->m_data, newSize * sizeof(int));
        array->m_size = newSize;
    }
    array->m_data[index] = value;
}
 
int Array_size(const Array* array)
{
    return array->m_size;
}
 
int * Array_begin(Array* array)
{
    return array->m_data;
}
 
int * Array_end(Array* array)
{
    return array->m_data + array->m_size;
}
