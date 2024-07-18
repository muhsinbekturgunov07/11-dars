#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    char grade;
} Student;

void copyFile(const char* source, const char* destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        perror("Failed to open destination file");
        fclose(src);
        return;
    }

    Student student;
    while (fread(&student, sizeof(Student), 1, src)) {
        fwrite(&student, sizeof(Student), 1, dest);
    }

    fclose(src);
    fclose(dest);
}

int main() {
    const char *source = "source.bin";
    const char *destination = "destination.bin";
    Student students[] = {{"asadbek", 24, 'A'}, {"Rita", 22, 'B'}};

    FILE *file = fopen(source, "wb");
    fwrite(students, sizeof(Student), 2, file);
    fclose(file);

    copyFile(source, destination);

    return 0;
}
