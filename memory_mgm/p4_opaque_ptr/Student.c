#include <stdlib.h>

typedef struct
{
  int id;
  char name[16];
} Student;

Student* newStudent(int id)
{
  Student* new;
  new = (Student *) malloc(sizeof(Student *));
  if (new != NULL)
  {
    new->id = id;
  }
  return new;
}

void deleteStudent(Student* s)
{ 
  free(s);
}

int Student_getId(const Student* s)
{
  return s->id;
}

char* Student_getName(const Student* s)
{
  return s->name;
}

void Student_setName(Student* s, const char* name)
{
  int i;
  for (i = 0; i < 16; i++)
  {
    s->name[i] = name[i];
  }
}
