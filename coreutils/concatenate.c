/**
 * concatenate - a mockup of the GNU coreutil command `cat`
 * 
 * USAGE 
 * 
 * ./cat <file1> - display contents of a file to the standard output.
 * ./cat <file1> <file2> ... - concatenate the inputed files and display the contents.
 * ./cat <file1> <file2> ... > <newfile> - concatenate the inputed files and write them to a new file.
 * ./cat <file1> <file2> ... >> <newfile> - append the contents from file1 to file2.
 * 
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE (1024 * 16) // 16 KB
#define LINE_SIZE 500

#define length(array) (sizeof(array)/sizeof(*(array)))

int main(int argc, char *argv[]) {
    char *cat(char*[], unsigned int, unsigned int);
    void write_to(char*, char*, unsigned int);

    unsigned int number_lines;
    unsigned int append;
    //unsigned int num_files = argc - 1;

    char *output_file;

    number_lines = 0;
    append = 2;

    char *files[argc - 1];

    for (int i = 1; i < argc; ++i) {
        files[i - 1] = argv[i];
    }

    char output[MAX_SIZE]; strcpy(output, cat(files, length(files), number_lines));

    if (append == 2) puts(output);
    else write_to(output_file, output, append);

    return 0;
}



char *cat(char *files[], unsigned int num_files, unsigned int number_lines) {
    static char output[MAX_SIZE]; output[0] = '\0';
    unsigned int line_number = 1;
    
    for (int i = 0; i < num_files; ++i) {
        FILE *file_ptr; 
        file_ptr = fopen(files[i], "r");

        char line[LINE_SIZE];

        if (file_ptr == NULL) {
            fprintf(stderr, "Error: Could not open file.\n");
            exit(8);
        }

        if (number_lines) {
            char line_buffer[LINE_SIZE];

            while (fgets(line, LINE_SIZE, file_ptr)) {
                sprintf(line_buffer, "%d", line_number); strcat(line_buffer, line);

                strcat(output, line_buffer);
                ++line_number;
            }
        } else 
            while (fgets(line, LINE_SIZE, file_ptr)) strcat(output, line);
        
        strcat(output, "\n");

        fclose(file_ptr);
    }

    return output;
}

void write_to(char *file_name, char *str_to_write, unsigned int append) {
    FILE *file_ptr;

    if (append) file_ptr = fopen(file_name, "a");
    else file_ptr = fopen(file_name, "w");

    if (file_ptr == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(8);
    }

    fprintf(file_ptr, "%s", str_to_write);
    fclose(file_ptr);
}