#include <stdio.h>
#include <string.h>

char str[] = "   HHello";

int main(void) {
    char *first_nonwhite_char(char[]);

    printf("First nonwhite char: %s\n", first_nonwhite_char(str));
    return 0;
}

char *first_nonwhite_char(char string[]) {
    static char first;

    for (int i = strlen(string); i >= 0; --i) {
        if (string[i] != ' ') first = string[i];
    }

    return &first;
}