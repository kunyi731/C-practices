#include "Animal.h"

void speak(const Animal* animals[], int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        animals[i]->vtbl->speak(animals[i]);
        printf("\n");
    }
}

int main()
{
    Dog spot, fido;
    Animal wild1;
    Animal * animals[3];
    
    Dog_ctor(&spot);
    Dog_ctor(&fido);
    Animal_ctor(&wild1);
    
    animals[0] = &spot;
    animals[1] = &wild1;
    animals[2] = &fido;
    
    speak(animals, 3);
}
