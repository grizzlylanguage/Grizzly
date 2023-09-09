#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./cli.h"

char *fileValue = NULL;
char *fileName = NULL;

int climain(int argc, char *argv[]) {
    fileName = argv[1];
    if (argc == 2) {
        FILE* file;
        char *filename = argv[1];
        char *extension = ".spk";
        int filename_len = strlen(filename);
        int extension_len = strlen(extension);

        file = fopen(argv[1], "r");
        if (file == NULL) {
            printf("Error: Can't find the file.");
            return 1;
        }
        if (filename_len >= extension_len && strcmp(filename + filename_len - extension_len, extension) == 0) {
            
            fileValue = (char*)malloc(1);
            fileValue[0] = '\0';
            
            char buffer[100];
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                char *temp = (char*)malloc(strlen(fileValue) + strlen(buffer) + 1);
                
                if (temp == NULL) {
                    printf("Error: Memory allocation failed.\n");
                    return 1;
                }
                
                strcpy(temp, fileValue);
                strcat(temp, buffer);
                
                free(fileValue);
                fileValue = temp;
            }
            
            fclose(file);
            lmain();
        } else {
            printf("Error: The file doesn't have the extension \".spk\".");
            return 1;
        }
    } else {
        printf("Usage: %s <File location>\n", argv[0]);
        exit(1);
    }
}