#include <stdio.h>
#include "Student.h"

int main()
{
  Student* student = newStudent(65432);
  Student_setName(student, "Bradley");
  printf("%s's student id is %d.\n", Student_getName(student),
                                     Student_getId(student));

  deleteStudent(student);
}
