#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../../FUNCTIONS/functions.h"
#include "../Lexer/lexer.h"
#include "./parser.h"

extern TokenTypes *lexedValue;

ParserTypes *parsedValue;

int pmain() {
    parsedValue = malloc(sizeof(ParserTypes));
    if (strcmp(lexedValue->type, "Function") == 0) {
        if (strcmp(lexedValue->name, "print") == 0) {
            strcpy(parsedValue->name, lexedValue->name);
            strcpy(parsedValue->value, lexedValue->value);
        } else if (strcmp(lexedValue->name, "print") == 1) {
            printErr("TypeError", "This functions doesn't exist.");
        }
    }
    
    // Next step
    smain();

    return 0;
}