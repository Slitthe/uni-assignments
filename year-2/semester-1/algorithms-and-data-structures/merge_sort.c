#include <stdio.h>


// Merge sort
int main() {
    // merging two sorted arrays
    int arr1[] = {2,4,6, 8, 44};
    int arr2[] = {9, 10, 22, 33};
    int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]);

    int combinedSize = arr1Size + arr2Size;
    int combined[combinedSize];

    int left = 0;
    int right = 0;

    for(int i = 0; i < combinedSize; i++) {
        int isLeftInBounds = left < arr1Size ? 1 : 0;
        int isRightInBounds = right < arr2Size ? 1 : 0;

        if(isLeftInBounds == 1 && arr1[left] < arr2[right]) {
            combined[i] = arr1[left];
            left++;
            continue;
        }
        if(isRightInBounds == 1 && arr2[right] < arr1[left]) {
            combined[i] = arr2[right];
            right++;
            continue;
        }

        if(isLeftInBounds == 1 && isRightInBounds == 0) {
            combined[i] = arr1[left];
            left++;
            continue;
        }

        if(isRightInBounds == 1 && isLeftInBounds == 0) {
            combined[i] = arr2[right];
            right++;
            continue;
        }



    }

    printf("Arr1 size: %d\n", arr1Size);
    printf("Arr2 size: %d\n", arr2Size);


    printf("\nAFTER:\n");
    for(int i = 0; i < combinedSize; i++) {
        printf("input[%d]=%d\n", i, combined[i]);
    }

    return 0;
}