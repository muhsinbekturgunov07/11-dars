#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    char grade;
} Student;

int countStudents(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    int count = 0;
    Student student;
    while (fread(&student, sizeof(Student), 1, file)) {
        count++;
    }
    fclose(file);

    return count;
}

int main() {
    const char *filename = "students.bin";
    Student students[] = {{"Kim", 20, 'B'}, {"Leo", 21, 'C'}, {"Nina", 22, 'A'}};

    FILE *file = fopen(filename, "wb");
    fwrite(students, sizeof(Student), 3, file);
    fclose(file);

    int count = countStudents(filename);
    printf("Yozuvlar soni: %d\n", count);

    return 0;
}
