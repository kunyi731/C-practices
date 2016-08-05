#include <stdio.h>

typedef struct Animal Animal;
 
typedef struct
{
    void (*speak)(Animal* self);
} Animal_vtbl;
 
struct Animal
 
{
    Animal_vtbl * vtbl;
 
};
 
 
void Animal_speak(Animal* self)
{
    printf("growl");
}
 
static Animal_vtbl the_Animal_vtbl = { Animal_speak };
 
 
void Animal_ctor(Animal* self)
{
    self->vtbl = &the_Animal_vtbl;
}

typedef struct
{
    Animal * base;
} Dog;

void Dog_speak(Dog* self)
{
    printf("woof");
}

static Animal_vtbl the_Dog_vtbl = { Dog_speak };

void Dog_ctor(Dog* self)
{
    ((Animal*)self)->vtbl = &the_Dog_vtbl;
}
