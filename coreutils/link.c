/**
 * link - a mockup of the GNU coreutil command `ln`
 * 
 * Can be used to create both hard links and symlinks.
 * 
 * USAGE
 * 
 * hard link - ./link -h <file> <linked-file>
 * symlink - ./link -s <file> <linked-file>
 * 
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// This is more of an excercise to parse command line arguments

int main(int argc, char *argv[]) {
    char *original_file; char *linked_file;

    // program_name = argv[0]

    if (argc == 4 && argv[1][0] == '-') {
        original_file = &argv[2]; linked_file = &argv[3];
        char hard_or_soft = argv[1][1];

        if (hard_or_soft == 'h') {
            int hardlink = link(original_file, linked_file);

            if (hardlink == -1) {
                fprintf(stderr, "Error: Could not create a hard link.\n");
                exit(8);
            }
        } else if (hard_or_soft == 's') {
            int softlink = symlink(original_file, linked_file);

            if (softlink == -1) {
                fprintf(stderr, "Error: Could not create symlink.\n");
                exit(8);
            }
        }

    } else {
        fprintf(stderr, "Error: Bad arguments.\n");
        exit(8);
    }

    return 0;
}