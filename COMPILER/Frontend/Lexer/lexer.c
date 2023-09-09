#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../../CLI/cli.h"
#include "./lexer.h"
#include "../../../FUNCTIONS/functions.h"

extern char *fileValue;

TokenTypes *lexedValue;

int lmain() {
    TokenTypes tokens;

    char *input = strdup(fileValue);
    char *token = strtok(input, ";");
    char *fileValueSplitted;

    while (token != NULL) {
        fileValueSplitted = token;
        token = strtok(NULL, ";");
    }

    char *line = strtok(fileValueSplitted, "\n");

    while (line != NULL) {
        char *openParen = strchr(line, '(');

        if (openParen != NULL) {
            size_t openParenIndex = openParen - line;

            char beforeParen[openParenIndex + 1];
            strncpy(beforeParen, line, openParenIndex);
            beforeParen[openParenIndex] = '\0';

            char *afterParen = openParen;

            strcpy(tokens.type, "Function");
            strcpy(tokens.name, beforeParen);
            strcpy(tokens.value, afterParen);
        } else {
            printErr("TypeError", "Missing some parenthesis.");
        }

        line = strtok(NULL, "\n");
    }

    lexedValue = malloc(sizeof(TokenTypes));
    if (lexedValue != NULL) {
        strcpy(lexedValue->type, tokens.type);
        strcpy(lexedValue->name, tokens.name);
        strcpy(lexedValue->value, tokens.value);
    } else {
        printf("Failed to allocate memory for lexedValue.\n");
        return 1;
    }
    free(input);

    // Next step.
    pmain();
    
    return 0;
}
