#include <stdio.h>
#include <stdlib.h>


int* insertionSort(const int unsorted[], int size);

int main() {
    int input[] = {15,3,0,14,16,9,6,19,5,19,9,8,1,8,9,12,9,11,15,9};
    int size = sizeof(input) / sizeof(input[0]);

    printf("Unsorted: [");
    for(int i = 0; i < size; i++) {
        printf("%d, ", input[i]);
    }
    printf("]\n\n");

    int* sorted = insertionSort(input, size);

    printf("Sorted: [");
    for(int i = 0; i < size; i++) {
        printf("%d, ", sorted[i]);
    }
    printf("]\n\n");

    return 0;
}

int* insertionSort(const int unsorted[], int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        arr[i] = unsorted[i];
    }

    for(int i = 1; i < size; i++) {
        for(int j = i; j > 0; j--) {
            if(arr[j - 1] > arr[j]) {
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    return arr;
}