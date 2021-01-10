/**
 * copy - a mockup of the GNU coreutil command `cp`
 * 
 * USAGE - ./copy <from> <to>
 * 
**/

// Since UNIX treats ASCII files as binary, we can just treat every file as such

#include <stdio.h>
#include <stdlib.h>

// UNIX filesystem
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE (16 * 1024) // 16K buffer

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    int input_file;
    int output_file;
    int read_size;

    if (argc != 3) {
        fprintf(stderr, "Error: Wrong number of arguments.");
        exit(8);
    }

    input_file = open(argv[1], O_RDONLY | 0); // Input file we only want to read
    if (input_file < 0) {
        fprintf(stderr, "Error: Unable to read file.");
        exit(8);
    }
    
    output_file = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT | 0, 0666); // Output file we need to write
    if (output_file < 0) {
        fprintf(stderr, "Error: Unable to write to file.");
        exit(8);
    }
    
    while (1) {
        read_size = read(input_file, buffer, sizeof(buffer)); // Use buffer

        if (read_size == 0) break;

        if (read_size < 0) {
            fprintf(stderr, "Error: Error reading file.");
            exit(8);
        }

        write(output_file, buffer, (unsigned int) read_size);
    }
    close(input_file); close(output_file);
    
    return 0;
}