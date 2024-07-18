#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    char grade;
} Student;

void deleteStudent(const char* filename, int index) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    Student students[100];
    int count = 0;
    while (fread(&students[count], sizeof(Student), 1, file)) {
        count++;
    }
    fclose(file);

    for (int i = index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }
    count--;

    file = fopen(filename, "wb");
    fwrite(students, sizeof(Student), count, file);
    fclose(file);
}

int main() {
    const char *filename = "students.bin";
    Student students[] = {{"Eve", 20, 'B'}, {"Dan", 22, 'C'}, {"Anna", 19, 'A'}};

    FILE *file = fopen(filename, "wb");
    fwrite(students, sizeof(Student), 3, file);
    fclose(file);

    deleteStudent(filename, 1);

    return 0;
}
