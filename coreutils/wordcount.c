/**
 * wordcount - a mockup of the GNU coreutil command `wc`
 * 
 * `mktemp` is a less used coreutil used to byte, character
 * 
 * USAGE - ./copy <from> <to>
 * 
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE (16 * 1024)
#define LINE_SIZE 500

int main(int argc, char *argv[]) {
    int file_size(FILE *);
    int count_chars(char *);
    int count_words(char *);
    int count_lines(char *);

    FILE *file_ptr; 
    file_ptr = fopen(argv[argc - 1], "r");

    if (file_ptr == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(8);
    }

    char output[MAX_SIZE]; char line[500];

    while (fgets(line, LINE_SIZE, file_ptr)) strcat(output, line);

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "--bytes") == 0) 
            printf("Byte count: %d\n", file_size(file_ptr));

        if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--chars") == 0) 
            printf("Character count: %d\n", count_chars(output));

        if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--words") == 0) 
            printf("Word count: %d\n", count_words(output));

        if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--lines") == 0) 
            printf("Line count: %d\n", count_lines(output));
    }

    return 0;
}

int file_size(FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    int res = ftell(fp); //counting the size of the file
    fclose(fp); //closing the file
    return res;
}

int count_chars(char *str) {
    int count = 0;

    for(; *str != '\0'; ++str) ++count;

    return count;
}

int count_words(char *str) {
    int count = 0;

    // Fixes wierd bug
    if ((*str == '\0') || (*str == ' ' && *(str + 1) == ' ')) 
        return count;

    while (*str != '\0') {
        if ((*str == ' ' && *(str + 1) != ' ') || (*str == '\n' && *(str + 1) != ' ')) 
            ++count;
        ++str;
    }

    return count + 1;
}

int count_lines(char *str) {
    int count = 0;

    for(; *str != '\0'; ++str) 
        if (*str == '\n') ++count;

    return count;
}