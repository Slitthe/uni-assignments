#include <stdio.h>



// Insertion sort
int main() {
    int input[] = {5, 2, 4, 6, 1, 3};
    int size = sizeof(input) / sizeof(input[0]);

    printf("\nBEFORE: \n");
    for(int i = 0; i < size; i++) {
        printf("input[%d]=%d\n", i, input[i]);
    }

    for(int i = 1; i < size; i++) {
        for(int j = i; j > 0; j--) {
            if(input[j - 1] > input[j]) {
                int tmp = input[j - 1];
                input[j - 1] = input[j];
                input[j] = tmp;
            }
        }

    }

    printf("\nAFTER:\n");
    for(int i = 0; i < size; i++) {
        printf("input[%d]=%d\n", i, input[i]);
    }

    return 0;
}