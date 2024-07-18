#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void findThreeLetterWords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \t\n.,?!;");
        while (token != NULL) {
            if (strlen(token) == 3) {
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
        fprintf(file, "Hello world. How are you?\n");
        fclose(file);
    }

    findThreeLetterWords(filename);

    return 0;
}
