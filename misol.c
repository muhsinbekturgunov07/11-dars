#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    char grade;
} Student;

void updateStudent(const char* filename) {
    FILE *file = fopen(filename, "rb+");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    Student student;
    fseek(file, 0 * sizeof(Student), SEEK_SET); 
    fread(&student, sizeof(Student), 1, file);

    
    student.grade = 'A';

    fseek(file, 0 * sizeof(Student), SEEK_SET); 
    fwrite(&student, sizeof(Student), 1, file);

    fclose(file);
}

int main() {
    const char *filename = "students.bin";
    Student students[] = {{"Sam", 23, 'B'}, {"Mia", 21, 'A'}};

    FILE *file = fopen(filename, "wb");
    fwrite(students, sizeof(Student), 2, file);
    fclose(file);

    updateStudent(filename);

    return 0;
}
