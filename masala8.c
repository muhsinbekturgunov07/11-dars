#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

void findLongWords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \t\n.,?!;");
        while (token != NULL) {
            if (strlen(token) >= 4) {
                printf("%s ", token);
            }
            token = strtok(NULL, " \t\n.,?!;");
        }
    }

    fclose(file);
}

int main() {
    const char *filename = "input.txt";

    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "Hello world. How are you?\nBootcamp Foundation new PLAN 59\n");
        fclose(file);
    }

    findLongWords(filename);

    return 0;
}
