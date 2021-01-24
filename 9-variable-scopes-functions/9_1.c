#include <stdio.h>
#include <string.h>

int main(void) {
    int count_words(char*);

    char string[] = "       ";
    printf("Number of words: %d\n", count_words(string));
    return (0);
}

int count_words(char *str) {
    int count = 0;

    // Fixes wierd bug
    if ((*str == '\0') || (*str == ' ' && *(str + 1) == ' ')) 
        return count;

    while (*str != '\0') {
        if (*str == ' ' && *(str + 1) != ' ') 
            ++count;
        ++str;
    }

    return count + 1;
}