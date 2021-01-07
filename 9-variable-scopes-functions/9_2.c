#include <stdio.h>
#include <string.h>

char line[100];
char first_string[100];
char second_string[100];

int main(void) {
    printf("Enter two words: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%s %s", &first_string, &second_string);

    printf("Does %s begin %s: %d\n", first_string, second_string, begins(first_string, second_string));
}

// Excercise 9-2

int begins(char string1[], char string2[]) {
    for (int i = 0; i < strlen(string1); i++) {
        if (string1[i] != string2[i])
            return (0);
    }
    return (1);
}