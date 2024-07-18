#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

int isCapitalized(const char *word) {
    return isupper(word[0]);
}

void findCapitalizedWords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            if (isCapitalized(token)) {
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
        fprintf(file, "Salom bolalar. Anvarni qani?\n");
        fclose(file);
    }

    findCapitalizedWords(filename);

    return 0;
}
