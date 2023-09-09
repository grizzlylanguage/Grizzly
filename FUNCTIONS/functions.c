#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./functions.h"
#include "../CLI/cli.h"

extern char *fileName;

void printErr(const char *errType, const char *errStr) {
    const char *relativePath = fileName;
    char fullPath[PATH_MAX];

    if (getcwd(fullPath, sizeof(fullPath)) != NULL) {
        strcat(fullPath, "\\");
        strcat(fullPath, relativePath);
        fprintf(stderr, "\033[1;31mError (%s):\033[0m\n    Message: \033[1;33m%s\033[0m\n    \033[1;36mIn file:\033[0m \033[90m%s\033[0m\n", errType, errStr, fullPath);
        exit(1);
    } else {
        perror("getcwd");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

bool hasParen(const char *str) {
    int openCount = 0;
    int closeCount = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            openCount++;
        } else if (str[i] == ')') {
            closeCount++;
        }
        if (closeCount > openCount) {
            return false;
        }
    }

    return openCount == closeCount;
}