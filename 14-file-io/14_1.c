#include <stdio.h>
#include <stdlib.h>

const char file_name[] = "14_2.c";

int main(void) {
    int count = 0;
    int ch;
    FILE *input_file;

    input_file = fopen(file_name, "r");
    if (input_file == NULL) printf("Cannot open %s\n", file_name);

    while (1) {
        ch = fgetc(input_file);

        if (ch == EOF) break;

        if (ch == '\n') ++count;
    }

    printf("Number of lines in %s is %d\n", file_name, count);

    fclose(input_file);

    return 0;
}