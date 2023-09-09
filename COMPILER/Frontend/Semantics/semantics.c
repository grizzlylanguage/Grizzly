#include <stdio.h>
#include "../Parser/parser.h"
#include "../../../FUNCTIONS/functions.h"

extern ParserTypes *parsedValue;

int smain() {
    if (hasParen(parsedValue->value)) {
        printf("%s", parsedValue->value);
    }
    return 0;
}