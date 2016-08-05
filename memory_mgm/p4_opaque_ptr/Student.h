typedef struct hidden_tag Student;

Student* newStudent(int id);
void deleteStudent(Student* s);

int Student_getId(const Student* s);

char* Student_getName(const Student* s);

void Student_setName(Student* s, const char* name);
