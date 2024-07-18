#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

int containsDigit(const char *word) {
    while (*word) {
        if (isdigit(*word)) {
            return 1;
        }
        word++;
    }
    return 0;
}

void findWordsWithDigits(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            if (containsDigit(token)) {
                printf("%s ", token);
            }
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(file);
}

int main() {
    const char *filename = "input.txt";

    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "Salom Foundation33 guruhi 1-o'rinda\n");
        fclose(file);
    }

    findWordsWithDigits(filename);

    return 0;
}
