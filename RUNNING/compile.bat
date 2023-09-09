@echo off
gcc -o ./RUNNING/run ./RUNNING/index.c ./CLI/cli.c ./COMPILER/Frontend/Parser/parser.c ./COMPILER/Frontend/Lexer/lexer.c ./FUNCTIONS/functions.c ./COMPILER/Frontend/Semantics/semantics.c

echo Done compiling the Grizzly.