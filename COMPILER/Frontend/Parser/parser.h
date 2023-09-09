#ifndef PARSER_H
#define PARSER_H

typedef struct {
    char type[100];
    char value[100];
    char name[100];
} ParserTypes;

extern ParserTypes *parsedValue;

#endif