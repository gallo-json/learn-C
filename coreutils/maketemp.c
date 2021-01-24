/**
 * maketemp - a mockup of the GNU coreutil command `mktemp`
 * 
 * `mktemp` is a less used coreutil used to create a temporary file or directory.
 * 
 * USAGE - ./maketemp
 * 
**/

#include <stdio.h>
#include <string.h>

int main() {
    char *tmp_name(void);

    printf("Name: %s\n", tmp_name());
    printf("Name: %s\n", tmp_name());
    
    return 0;
}

char *tmp_name(void) {
    static char name[30];
    static int sequence = 0;

    ++sequence;

    strcpy(name, "tmp");

    name[3] = sequence + '0'; name[4] = '\0';

    return name;
}