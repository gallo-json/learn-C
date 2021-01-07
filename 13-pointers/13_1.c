#include <stdio.h>

#define SIZE 8

int arr[8];

int main(void) {
    void init_arr();
    
    init_arr(arr);

    return 0;
}

void init_arr(int *array_ptr) {
    for (int i = 0; i < SIZE; ++i) 
        *(array_ptr + i) = 0;
}