#include <stdio.h>
#include <stdlib.h>

struct datetime {
    int year;
    int month;
    int day;
    int hour; // Military time
    int minute;
};

int main(void) {
    char date_line1[50];
    char date_line2[50];
    struct datetime date1;
    struct datetime date2;
    long int difference(struct datetime, struct datetime);

    printf("Enter first date: ");
    fgets(date_line1, sizeof(date_line1), stdin);
    sscanf(date_line1, "%d %d %d %d %d", &date1.year, &date1.month, &date1.day, &date1.hour, &date1.minute);

    printf("Enter last date: ");
    fgets(date_line2, sizeof(date_line2), stdin);
    sscanf(date_line2, "%d %d %d %d %d", &date2.year, &date2.month, &date2.day, &date2.hour, &date2.minute);

    long int the_diff = difference(date1, date2);
    printf("Difference of the two dates in minutes: %ld\n", the_diff);
    return 0;
}

long int difference(struct datetime date1, struct datetime date2) {
    // Approx month to minute conversion (since different months have different days)
    long int date1_min = date1.year * 525600 + date1.month * 43800 + date1.day * 1440 + date1.hour * 60 + date1.minute;
    long int date2_min = date2.year * 525600 + date2.month * 43800 + date2.day * 1440 + date2.hour * 60 + date2.minute;

    long int d = abs(date2_min - date1_min);
    return d;
}