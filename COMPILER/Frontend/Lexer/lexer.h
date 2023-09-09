#ifndef LEXER_H
#define LEXER_H

typedef struct {
    char type[100];
    char value[100];
    char name[100];
} TokenTypes;

extern TokenTypes *lexedValue;

#endif