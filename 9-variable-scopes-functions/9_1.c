#include <stdio.h>
#include <string.h>

int main(void) {
    char string[] = "Hello world im s this";
    printf("Number of words: %d\n", count_words(string));
    return (0);
}

int count_words(char string[]) {
    int char_count = 0;

    for (int i = 0; i < strlen(string); i++) {
        if (string[i] != ' ') 
            ++char_count;
    }

    int num_of_spaces = strlen(string) - char_count;

    return (num_of_spaces + 1);
}